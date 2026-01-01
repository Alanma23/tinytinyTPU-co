# Synthesis Checklist for VPU and 20-Instruction ISA

## Files Updated for Synthesis

### New RTL Files Added to build_vivado.tcl:
- ✅ `rtl/vpu.sv` - Vector Processing Unit with ReLU, ReLU6, Sigmoid, Tanh
- ✅ `rtl/config_regs.sv` - Configuration register file
- ✅ `rtl/instruction_decoder.sv` - 20-instruction ISA decoder
- ✅ `rtl/execution_unit.sv` - Instruction execution unit

### Modified RTL Files:
- ✅ `rtl/pe.sv` - Updated to use signed types
- ✅ `rtl/mmu.sv` - Updated to use signed types
- ✅ `rtl/accumulator_align.sv` - Updated to use signed types
- ✅ `rtl/accumulator.sv` - Updated to use signed types
- ✅ `rtl/mlp_top.sv` - Added VPU configuration input
- ✅ `rtl/activation_pipeline.sv` - Integrated VPU module
- ✅ `rtl/tpu_bridge.sv` - Added VPU configuration
- ✅ `rtl/tpu_top.sv` - Added VPU configuration routing
- ✅ `rtl/uart_controller.sv` - Added instruction decoder and execution unit

## Potential Synthesis Issues to Watch For

### 1. VPU Module (`vpu.sv`)
- **Complex Functions**: Sigmoid and Tanh use piecewise linear approximations with nested conditionals
- **Large Combinational Logic**: May need pipelining if timing fails
- **Recommendation**: Monitor timing reports, may need to add pipeline stages

### 2. Execution Unit (`execution_unit.sv`)
- **Combinational Logic**: Large `always_comb` block with many conditionals
- **State Machine**: Uses registered state, should be fine
- **Recommendation**: Check for timing violations in combinational paths

### 3. Instruction Decoder (`instruction_decoder.sv`)
- **Pure Combinational**: All outputs are combinational
- **Should be fine**: Simple decode logic

### 4. Config Regs (`config_regs.sv`)
- **Simple Register File**: Standard register implementation
- **Should be fine**: No complex logic

### 5. Signed Arithmetic
- **PE/MMU/Accumulator**: All updated to use `signed` types
- **Multiplication**: Uses `$signed()` casts
- **Recommendation**: Verify DSP48 usage in synthesis reports

## Known Synthesis Attributes

### Preserved Signals:
- `activation_pipeline.sv`: `(* keep = "true" *)` on `mult_reg`
- `normalizer.sv`: `(* keep = "true" *)` on `mult_res`

### DSP Usage:
- `activation_pipeline.sv`: `(* use_dsp = "yes" *)` on `mult_raw`
- `normalizer.sv`: `(* use_dsp = "yes" *)` on `mult_raw`

### FSM Encoding:
- `mlp_top.sv`: `(* fsm_encoding = "USER" *)` on `state_reg`

## Timing Considerations

1. **VPU Pipeline**: 2-cycle latency (input register + output register)
2. **Execution Unit**: Combinational paths from instruction_valid to control signals
3. **UART Controller**: Already has proper pipelining

## Testing After Synthesis

### Python Scripts to Run:

1. **Basic Functionality Test**:
   ```bash
   cd host
   python3 debug_tpu.py /dev/ttyUSB0
   ```

2. **20-Instruction ISA Test**:
   ```bash
   cd host
   python3 test_isa_comprehensive.py /dev/ttyUSB0
   ```

3. **Forward Pass Demo**:
   ```bash
   cd host
   python3 demo_forward_pass.py /dev/ttyUSB0
   ```

### Expected Behavior:
- All 20 instructions should execute
- VPU activation functions should work (ReLU, ReLU6, Sigmoid, Tanh)
- Signed arithmetic should work correctly (negative values)
- Backward compatibility with legacy commands (0x01-0x05)

## If Synthesis Fails

1. **Check Timing Violations**: Look for combinational paths > 10ns
2. **Check Resource Usage**: VPU may use significant LUTs
3. **Check DSP48 Usage**: Should use DSPs for multiplications
4. **Check for Unconnected Signals**: Verify all execution_unit outputs are used

## Post-Synthesis Verification

1. Check utilization reports for resource usage
2. Check timing reports for violations
3. Verify all modules are synthesized (not optimized away)
4. Test on hardware with comprehensive test script

