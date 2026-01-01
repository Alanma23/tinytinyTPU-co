# TinyTinyTPU Implementation Documentation

## Overview

TinyTinyTPU is a minimal 2x2 systolic-array TPU-style matrix-multiply unit implemented in SystemVerilog for FPGA deployment. The design implements a complete inference pipeline from matrix multiplication through activation, normalization, and quantization.

## Architecture

### System Overview

```
UART Controller → TPU Bridge → MLP Top
                                      ↓
                    Weight FIFO → MMU (2x2 Systolic Array)
                                      ↓
                    Unified Buffer → Accumulator (Alignment + Double Buffer)
                                      ↓
                    Activation Pipeline (ReLU → Normalization → Quantization)
                                      ↓
                    Unified Buffer (for next layer feedback)
```

### Key Components

#### 1. Processing Element (PE) - `rtl/pe.sv`
- **Function**: Fundamental MAC unit
- **Operation**: `psum_out = psum_in + (activation × weight)`
- **Data Flow**: 
  - Activations flow horizontally (right)
  - Partial sums flow vertically (down)
- **Weight Loading**: Separate `en_weight_pass` and `en_weight_capture` signals for systolic timing

#### 2. Matrix Multiply Unit (MMU) - `rtl/mmu.sv`
- **Size**: 2×2 systolic array
- **Layout**:
  ```
  PE00 → PE01    (activations flow right)
    ↓      ↓
  PE10 → PE11    (partial sums flow down)
    ↓      ↓
  acc0   acc1    (outputs to accumulator)
  ```
- **Features**:
  - Diagonal wavefront weight loading
  - Staggered column capture timing
  - Row1 skew register for systolic timing

#### 3. Accumulator - `rtl/accumulator.sv`
- **Sub-components**:
  - `accumulator_align.sv`: Aligns staggered column outputs (col1 arrives 1 cycle after col0)
  - `accumulator_mem.sv`: Double-buffered 32-bit storage
- **Modes**:
  - Overwrite mode: Replace accumulator value
  - Accumulate mode: Add to existing value
- **Double Buffering**: Supports ping-pong buffers for multi-layer inference

#### 4. Activation Pipeline - `rtl/activation_pipeline.sv`
- **Stages**:
  1. Activation function (ReLU/ReLU6/passthrough)
  2. Normalization (gain/bias/shift)
  3. Loss computation (L1 loss, optional)
  4. Quantization (affine int8 with saturation)
- **Output**: Quantized int8 values ready for next layer

#### 5. Unified Buffer - `rtl/unified_buffer.sv`
- **Function**: Ready/valid FIFO for activation data
- **Features**: 
  - Double buffering for layer-to-layer data transfer
  - Backpressure support via ready/valid handshake

#### 6. MLP Top - `rtl/mlp_top.sv`
- **Function**: Top-level state machine orchestrating the entire inference pipeline
- **States**:
  - `IDLE` (0): Waiting for start signal
  - `LOAD_WEIGHT` (1): Loading weights into MMU via weight FIFO
  - `LOAD_ACT` (2): Loading initial activations into unified buffer
  - `COMPUTE` (3): Running matrix multiplication
  - `DRAIN` (4): Draining remaining results from MMU
  - `TRANSFER` (5): Transferring results to unified buffer for next layer
  - `NEXT_LAYER` (6): Preparing for next layer
  - `WAIT_WEIGHTS` (7): Waiting for next layer weights
  - `DONE` (8): Inference complete

#### 7. UART Controller - `rtl/uart_controller.sv`
- **Function**: Serial communication interface for host control
- **Commands**:
  - `0x01`: WRITE_WEIGHT - Load 2×2 weight matrix
  - `0x02`: WRITE_ACT - Load 2×2 activation matrix
  - `0x03`: EXECUTE - Start computation
  - `0x04`: READ_RESULT - Read 32-bit accumulator result
  - `0x05`: STATUS - Read MLP state and cycle count

#### 8. TPU Top - `rtl/tpu_top.sv`
- **Function**: System integration module
- **Connects**: UART Controller ↔ TPU Bridge ↔ MLP Top
- **Debug Outputs**: Exposes internal signals for debugging

### Data Flow

#### Weight Loading (Diagonal Wavefront)
For a 2×2 weight matrix W = [[1, 2], [3, 4]]:

| Cycle | col0_out | col1_out | Column 0 Captures | Column 1 Captures |
|-------|----------|----------|-------------------|-------------------|
| 0     | 3        | 0 (skew) | No                | No                |
| 1     | 1        | 4        | Yes               | No                |
| 2     | (hold)   | 2        | No                | Yes               |

Final weight distribution:
```
PE00: W[0,0]=1    PE01: W[0,1]=2
PE10: W[1,0]=3    PE11: W[1,1]=4
```

#### Matrix Multiplication
For activations A = [[a00, a01], [a10, a11]] and weights W = [[w00, w01], [w10, w11]]:

Result C = A × W:
- C[0,0] = a00×w00 + a01×w10
- C[0,1] = a00×w01 + a01×w11
- C[1,0] = a10×w00 + a11×w10
- C[1,1] = a10×w01 + a11×w11

The accumulator reads `acc0 = C[0,0] + C[1,0]` (sum of column 0).

## Implementation Details

### Timing
- **Clock Frequency**: 100 MHz (configurable)
- **UART Baud Rate**: 115200 (configurable)
- **Weight Load**: 3 cycles (staggered column capture)
- **Compute Phase**: 3 cycles (activation streaming)
- **DRAIN Phase**: 7 cycles (result draining)
- **Total Inference**: ~20 cycles per layer

### Precision
- **Weights**: 8-bit signed integers
- **Activations**: 8-bit signed integers
- **Partial Sums**: 16-bit signed integers (MMU output)
- **Accumulator**: 32-bit signed integers
- **Quantized Output**: 8-bit signed integers

### Multi-Layer Support
The design supports multi-layer MLP inference through:
- Double-buffered unified buffers (ping-pong)
- Weight FIFO for layer-by-layer weight loading
- State machine that cycles through layers

## Errors Encountered and Fixes

### Error 1: Accumulator Off-by-One Error

**Problem**: The "all ones" test case (W=[[1,1],[1,1]], A=[[1,1],[1,1]]) was returning 5 instead of the expected 4.

**Root Cause**: 
The `mmu_valid` signal was asserted for the entire DRAIN phase (7 cycles), but the MMU only produces 2 valid outputs for a 2×2 matrix. The accumulator_align module was processing all 7 cycles as valid, causing it to accumulate zeros or stale values from the MMU after the valid outputs were exhausted.

**Original Code** (`rtl/mlp_top.sv` line 206):
```systemverilog
assign mmu_valid = (compute_phase && cycle_cnt_reg >= 5'd2) || drain_phase;
```

This made `mmu_valid` high for:
- COMPUTE phase when `cycle_cnt >= 2` (1 cycle)
- Entire DRAIN phase (7 cycles: cycles 0-6)

**Fix**:
Gate `mmu_valid` to only be high when the MMU actually has valid outputs:

```systemverilog
// Only assert mmu_valid when MMU actually has valid outputs
// During COMPUTE: valid when unified buffer has data (act_ub_rd_valid)
// During DRAIN: valid only for first 2 cycles (when MMU has valid outputs for 2x2 matrix)
assign mmu_valid = (compute_phase && cycle_cnt_reg >= 5'd2 && act_ub_rd_valid) || 
                   (drain_phase && cycle_cnt_reg < 5'd2);
```

**Result**: 
- During COMPUTE: `mmu_valid` is only high when `act_ub_rd_valid` is high (MMU has valid inputs)
- During DRAIN: `mmu_valid` is only high for the first 2 cycles (when MMU has valid outputs for a 2×2 matrix)
- The accumulator now correctly accumulates only valid MMU outputs, preventing accumulation of zeros or stale values

**Verification**: The "all ones" test now correctly returns 4 instead of 5.

### Error 2: Accumulator Mode Timing

**Problem**: Initially, the accumulator was in overwrite mode during COMPUTE and accumulate mode only during DRAIN, which could cause incorrect accumulation for multi-row results.

**Fix**: Set `accum_en = 1` from the start of COMPUTE phase to ensure all row results are accumulated correctly.

**Code Change** (`rtl/mlp_top.sv` line 366):
```systemverilog
COMPUTE: begin
    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
    accum_en <= 1'b1;  // Enable accumulation from start of COMPUTE to accumulate all row results
    // ...
end
```

## Testing

### Unit Tests
All RTL modules have comprehensive cocotb testbenches in `sim/tests/`:
- `test_pe.py`: Processing element MAC operations
- `test_mmu.py`: Matrix multiply unit weight loading and computation
- `test_accumulator.py`: Accumulator alignment and buffering
- `test_activation_pipeline.py`: Full activation pipeline
- `test_mlp_integration.py`: Multi-layer MLP inference

### Hardware Tests
The `host/` directory contains Python scripts for FPGA testing:
- `debug_tpu.py`: Comprehensive diagnostics
- `inference_demo.py`: Basic inference demonstrations
- `test_tpu_driver.py`: Driver functionality tests

### Test Results
All tests pass with the following verified cases:
- ✓ Identity matrix: W=[[1,0],[0,1]], A=[[10,20],[10,20]] → acc0 = 20
- ✓ 2x scale: W=[[2,0],[0,2]], A=[[5,10],[5,10]] → acc0 = 20
- ✓ Zero weights: W=[[0,0],[0,0]], A=[[5,10],[5,10]] → acc0 = 0
- ✓ All ones: W=[[1,1],[1,1]], A=[[1,1],[1,1]] → acc0 = 4

## FPGA Deployment

### Target Platform
- **Board**: Basys3 (Xilinx Artix-7)
- **Clock**: 100 MHz system clock
- **UART**: 115200 baud rate

### Build Process
1. Synthesize RTL with Vivado
2. Generate bitstream
3. Program FPGA via JTAG
4. Connect via UART (USB serial)

### Host Interface
The TPU communicates via UART using a simple command protocol:
- Commands are single bytes
- Data follows commands (4 bytes for weights/activations, 4 bytes for results)
- Status is returned as a single byte (state[3:0], cycle[3:0])

## Performance

### Throughput
- **Matrix Size**: 2×2
- **Inference Time**: ~20 cycles = 200 ns @ 100 MHz
- **Throughput**: ~5 million inferences/second (theoretical)

### Resource Usage (Basys3 Artix-7)
- **LUTs**: ~2000 (estimated)
- **FFs**: ~1500 (estimated)
- **BRAM**: 2-4 blocks (for unified buffers)

## Future Improvements

1. **Larger Matrix Support**: Extend to 4×4 or 8×8 systolic arrays
2. **Variable Precision**: Support for INT4, INT16, FP16
3. **Multi-Layer Optimization**: Pipeline layer transitions
4. **DMA Support**: Direct memory access for weights/activations
5. **On-Chip Memory**: Larger unified buffers for bigger models

## References

- Original TPU architecture: [chewingonchips.substack.com](https://chewingonchips.substack.com)
- Systolic array design patterns
- SystemVerilog best practices

## License

[Add your license here]

