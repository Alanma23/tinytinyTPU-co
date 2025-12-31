# TinyTinyTPU

A minimal 2x2 systolic-array TPU-style matrix-multiply unit, implemented in SystemVerilog.

The design models the full post-MAC pipeline:
MMU -> Accumulator (alignment + double buffering) -> Activation + Normalization + Loss -> Quantization -> Unified Buffer

--------------------------------------------------------------------------------

## Project Structure

```
tinytinyTPU/
|
|-- rtl/                          # SystemVerilog RTL source files
|   |-- pe.sv                     # Processing Element
|   |-- mmu.sv                    # 2x2 Matrix Multiply Unit
|   |-- weight_fifo.sv            # Single-column weight FIFO
|   |-- dual_weight_fifo.sv       # Dual-column weight FIFO with skew
|   |-- accumulator.sv            # Top-level accumulator
|   |-- accumulator_align.sv      # Column alignment logic
|   |-- accumulator_mem.sv        # Double-buffered accumulator memory
|   |-- activation_func.sv        # ReLU/ReLU6 activation
|   |-- normalizer.sv             # Gain/bias/shift normalization
|   |-- loss_block.sv             # L1 loss computation
|   |-- activation_pipeline.sv    # Full post-accumulator pipeline
|   |-- unified_buffer.sv         # Ready/valid output FIFO
|   `-- mlp_top.sv                # Top-level MLP integration wrapper
|
|-- sim/                          # Simulation environment
|   |-- Makefile                  # Build and test automation
|   |-- tests/                    # cocotb Python testbenches
|   |   |-- test_pe.py
|   |   |-- test_mmu.py
|   |   |-- test_weight_fifo.py
|   |   |-- test_dual_weight_fifo.py
|   |   |-- test_accumulator.py
|   |   |-- test_activation_func.py
|   |   |-- test_normalizer.py
|   |   |-- test_activation_pipeline.py
|   |   `-- test_mlp_integration.py
|   `-- waves/                    # Generated VCD waveforms
|
|-- archive/                      # Original Vivado project (preserved)
|   |-- tinytinyTPU.xpr           # Vivado project file
|   |-- tinytinyTPU.srcs/         # Original Verilog sources and testbenches
|   |-- tinytinyTPU.sim/          # Vivado simulation outputs
|   |-- tinytinyTPU.cache/        # Vivado cache files
|   |-- tinytinyTPU.hw/           # Hardware files
|   |-- tinytinyTPU.ip_user_files/
|   `-- vivado.log, vivado.jou    # Vivado session logs
|
`-- README.md
```

Note: The archive/ folder contains the original Vivado project with Verilog
sources. The rtl/ folder contains the migrated SystemVerilog versions.

--------------------------------------------------------------------------------

## Quick Start

### Prerequisites

- Verilator 5.022 or later
- Python 3.8+
- Surfer or GTKWave for waveform viewing

### Environment Setup

```bash
# Navigate to simulation directory
cd sim

# Create virtual environment (recommended)
python3 -m venv venv
source venv/bin/activate

# Install dependencies
python3 -m pip install -r requirements.txt
```

### Running Tests

All simulation commands must be run from the `sim/` directory:

```bash
cd sim

# Run all tests (virtual environment is activated automatically)
make test

# Run all tests with waveform generation
make test WAVES=1

# Run specific module test
make test_pe
make test_mmu
make test_mlp
make test_uart

# Run with waveforms
make test_pe WAVES=1
```

### Viewing Waveforms

```bash
# List available waveforms
make waves

# Open specific waveform
make waves MODULE=pe
make waves MODULE=mmu
make waves MODULE=mlp_top
```

### Linting

```bash
make lint
```

--------------------------------------------------------------------------------

## SystemVerilog Migration

This project was migrated from Verilog to SystemVerilog for improved synthesis compatibility and modern language features.

### Key Changes

1. File extension: `.v` -> `.sv`

2. Type declarations:
   - `input wire` / `output reg` -> `input logic` / `output logic`
   - `reg` / `wire` -> `logic`

3. Always blocks:
   - `always @(posedge clk)` -> `always_ff @(posedge clk)`
   - `always @(*)` -> `always_comb`

4. Array syntax:
   - `[0:DEPTH-1]` -> `[DEPTH]`

5. Case statements:
   - `case` -> `unique case` where appropriate

6. Width handling:
   - Explicit bit-width casts to avoid Verilator warnings
   - Example: `count == DEPTH` -> `count == (ADDR_W+1)'(DEPTH)`

### Testbench Migration

The Verilog testbenches were replaced with cocotb Python testbenches:

- More maintainable and readable test code
- Easier debugging with Python tools
- VCD waveform generation via Verilator
- Pytest integration for test discovery and reporting

--------------------------------------------------------------------------------

## Core RTL Modules

### pe.sv - Processing Element

The PE is the fundamental compute block.

- Multiply-Accumulate (MAC): `psum_out = psum_in + (in_act * weight)`
- Data forwarding: activation flows right, partial sum flows down
- Weight loading: separate `en_weight_pass` and `en_weight_capture` signals

Design Notes:
- Single-cycle registered outputs
- `en_weight_pass` controls psum passthrough during load phase
- `en_weight_capture` triggers weight register latch
- Systolic-friendly timing for TPU-style arrays

### mmu.sv - 2x2 Systolic Array

```
PE00 -> PE01    Activations flow horizontally (right)
  |       |     
PE10 -> PE11    Partial sums flow vertically (down)
  |       |
acc0    acc1    Outputs to accumulator
```

Responsibilities:
- Feeds activations into rows (row0 direct, row1 with skew register)
- Loads weights via vertical psum path with per-column capture timing
- Emits two partial-sum columns to the accumulator

Control Signals:
- `en_weight_pass` - broadcast to all PEs during weight load phase
- `en_capture_col0` - capture enable for column 0 PEs
- `en_capture_col1` - capture enable for column 1 PEs (staggered)

### dual_weight_fifo.sv - Staggered Column Weight FIFO

Two independent 4-entry queues share one data bus to fill both MMU columns.

- Column 0: Combinational read output (no latency)
- Column 1: Registered output with 1-cycle skew for diagonal wavefront
- Single `pop` signal advances both read pointers

### accumulator.sv

Captures MMU outputs, aligns staggered columns, and supports accumulate/overwrite with double buffering.

Components:
- `accumulator_align.sv` - Deskews column outputs
- `accumulator_mem.sv` - Double-buffered 32-bit storage

### activation_pipeline.sv

Top-level post-accumulator stage:

1. Activation (ReLU/ReLU6/passthrough)
2. Normalization (gain/bias/shift)
3. Parallel loss computation
4. Affine int8 quantization with saturation

### unified_buffer.sv

Byte-wide synchronous FIFO with ready/valid backpressure.

--------------------------------------------------------------------------------

## Diagonal Wavefront Weight Loading

The 3-cycle staggered weight loading scheme ensures weights propagate through the systolic array in a proper diagonal wavefront pattern.

For weight matrix W = [[1, 2], [3, 4]]:

| Cycle | col0_out | col1_out | Column 0 Captures | Column 1 Captures |
|-------|----------|----------|-------------------|-------------------|
| 0     | 3        | 0 (skew) | No                | No                |
| 1     | 1        | 4        | Yes               | No                |
| 2     | (hold)   | 2        | No                | Yes               |

Final Weight Distribution:
```
PE00: W[0,0]=1    PE01: W[0,1]=2
PE10: W[1,0]=3    PE11: W[1,1]=4
```

--------------------------------------------------------------------------------

## Multi-Layer MLP Inference

The `test_mlp_integration.py` demonstrates multi-layer neural network inference:

```
Weight FIFO -> MMU (systolic) -> Accumulator -> Activation Pipeline -> UB
                 ^                                                      |
                 +------------------ feedback (next layer) ------------+
```

### 2-Layer MLP Example

```
Input:  A  = [[5, 6], [7, 8]]

Layer 1: H = ReLU(A * W1)    where W1 = [[1, 2], [3, 4]]
         H = [[23, 34], [31, 46]]

Layer 2: Y = ReLU(H * W2)    where W2 = [[1, 1], [1, 1]]
         Y = [[57, 57], [77, 77]]
```

--------------------------------------------------------------------------------

## Makefile Reference

```
make help                  Show all available commands

Test Commands:
  make test                Run all tests
  make test WAVES=1        Run all tests with waveform generation
  make test_pe             Run PE tests only
  make test_mmu            Run MMU tests only
  make test_mlp            Run MLP integration tests

Waveform Commands:
  make waves               List available waveforms
  make waves MODULE=pe     Open specific waveform in viewer

Other:
  make lint                Run Verilator lint check
  make clean               Remove build artifacts
  make clean_waves         Remove generated waveforms

Environment Variables:
  WAVES=1                  Enable waveform generation
  WAVE_VIEWER=gtkwave      Use GTKWave instead of Surfer
  MODULE=<name>            Specify module for waveform viewing
```

--------------------------------------------------------------------------------

## Pipeline Timing Summary

| Phase        | Duration | Description                                    |
|--------------|----------|------------------------------------------------|
| Weight Load  | 3 cycles | Staggered column capture with diagonal wavefront |
| Compute      | 3 cycles | Activation streaming with row skew             |
| First Result | 5 cycles | From compute start to first accumulator output |
|Result Spacing| 1 cycle  | Between consecutive valid accumulator outputs  |

--------------------------------------------------------------------------------

## Test Coverage

| Test File                  | Module              | Tests                           |
|---------------------------|---------------------|--------------------------------|
| test_pe.py                | pe                  | Reset, MAC, weight capture      |
| test_mmu.py               | mmu                 | Weight loading, matrix multiply |
| test_weight_fifo.py       | weight_fifo         | Push/pop, wraparound           |
| test_dual_weight_fifo.py  | dual_weight_fifo    | Column independence, skew      |
| test_accumulator.py       | accumulator         | Alignment, buffering, modes    |
| test_activation_func.py   | activation_func     | ReLU positive/negative/zero    |
| test_normalizer.py        | normalizer          | Gain, bias, scaling            |
|test_activation_pipeline.py| activation_pipeline| Full pipeline, saturation     |
| test_mlp_integration.py   | mlp_top             | Multi-layer MLP inference      |

All 9 test suites pass with Verilator 5.042.
