# FPGA Synthesis Notes

## Fixed Issues

### Unbuffered IO Errors (RESOLVED)

**Problem**: Vivado reported unbuffered IO errors during place_design phase.

**Root Cause**:
- Clock signal not using global buffer (BUFG)
- LED outputs driven by combinatorial logic
- Switch inputs not synchronized

**Solution Applied**:

1. **Clock Buffering**:
   ```systemverilog
   BUFG bufg_inst (
       .I(clk),
       .O(clk_100mhz)
   );
   ```

2. **Registered Outputs**:
   - All LED signals now registered through flip-flops
   - Eliminates combinatorial paths to output pins

3. **Input Synchronization**:
   - Double-synchronizer for switches (prevents metastability)
   - Double-synchronizer for reset button

## Build Instructions

```bash
cd fpga
vivado -mode batch -source build_vivado.tcl
```

Expected build time: 5-10 minutes

## Design Statistics (Expected)

- **LUTs**: ~3,500-5,000
- **FFs**: ~2,500-3,500
- **BRAMs**: 10-15
- **Max Frequency**: >100 MHz (target: 100 MHz)

## Common Vivado Errors and Fixes

### 1. "UnBuffered IOs"
**Cause**: Direct connections between logic and IO pads
**Fix**: Register all outputs, synchronize all inputs, use BUFG for clocks

### 2. "Timing not met"
**Cause**: Critical path exceeds clock period
**Fix**: Add pipeline stages, reduce logic depth, or lower clock frequency

### 3. "Unplaced instances"
**Cause**: Design too large for FPGA
**Fix**: Check utilization reports, optimize design, or use larger FPGA

## Verification Checklist

After successful synthesis and implementation:

- [ ] Check timing reports: `timing_summary_post_impl.rpt`
- [ ] Verify utilization: `utilization_post_impl.rpt`
- [ ] Review DRC: `drc_post_impl.rpt`
- [ ] Check power: `power_post_impl.rpt`
- [ ] Test bitstream on hardware

## Programming the FPGA

### Via Hardware Manager GUI:

1. Connect Basys3 board
2. Open Vivado
3. Open Hardware Manager
4. Auto-connect to target
5. Program with `basys3_top.bit`

### Via TCL:

```tcl
open_hw_manager
connect_hw_server
open_hw_target
set_property PROGRAM.FILE {basys3_top.bit} [get_hw_devices xc7a35t_0]
program_hw_devices [get_hw_devices xc7a35t_0]
```

## Debug Tips

### If LEDs don't light up:
1. Check power (USB connected)
2. Verify bitstream programmed correctly
3. Try different LED modes (SW[15:14])
4. Press center button to reset

### If UART doesn't work:
1. Check COM port (`ls /dev/ttyUSB*`)
2. Verify baud rate (115200)
3. Check LED[9:10] for UART activity
4. Try loopback test (TX to RX)

### Using ChipScope/ILA for Debug:
Add to build_vivado.tcl before synthesis:
```tcl
create_ip -name ila -vendor xilinx.com -library ip -module_name ila_0
set_property -dict [list CONFIG.C_NUM_OF_PROBES {8}] [get_ips ila_0]
```

## Resource Optimization

If design doesn't fit:

1. **Reduce BRAM usage**: Use distributed RAM for small memories
2. **Share resources**: Multiplex logic where possible
3. **Pipeline breaking**: Reduce combinatorial depth
4. **Remove debug logic**: Disable $display statements

## Next Steps

1. ✅ Fix unbuffered IO errors
2. ⏳ Run full synthesis and implementation
3. ⏳ Program FPGA
4. ⏳ Test with Python driver
5. ⏳ Verify inference works on hardware
