# TinyTinyTPU v1 - FPGA Synthesis for Basys3

This directory contains FPGA implementation files for deploying TinyTinyTPU v1 on the **Digilent Basys3** board (Artix-7 XC7A35T).

## Files

- **`basys3_top.sv`** - Top-level wrapper module for Basys3 board
- **`basys3.xdc`** - Pin constraints and timing constraints
- **`build_vivado.tcl`** - Automated Vivado build script
- **`README.md`** - This file

## Hardware Requirements

- **Board**: Digilent Basys3 (Rev B or later)
- **FPGA**: Xilinx Artix-7 XC7A35T-1CPG236C
- **USB Cable**: Micro-USB for programming and UART communication
- **Software**: Xilinx Vivado 2019.2 or later

## Quick Start

### 1. Build Bitstream (Automated)

Run the TCL script in batch mode:

```bash
cd fpga
vivado -mode batch -source build_vivado.tcl
```

This will:
- Create a Vivado project
- Add all RTL sources
- Run synthesis, implementation, and bitstream generation
- Generate reports
- Output: `basys3_top.bit`

### 2. Program the FPGA

#### Option A: Vivado Hardware Manager (GUI)

1. Open Vivado
2. Click "Open Hardware Manager"
3. Click "Open Target" → "Auto Connect"
4. Click "Program Device"
5. Select `basys3_top.bit`
6. Click "Program"

#### Option B: Command Line

```bash
vivado -mode tcl
```

Then in Vivado TCL console:

```tcl
open_hw_manager
connect_hw_server
open_hw_target
set_property PROGRAM.FILE {basys3_top.bit} [get_hw_devices xc7a35t_0]
program_hw_devices [get_hw_devices xc7a35t_0]
close_hw_manager
exit
```

### 3. Connect and Test

1. **Keep the USB cable connected** (provides power and UART)
2. Find the UART port:
   - **Linux**: `/dev/ttyUSB0` or `/dev/ttyUSB1`
   - **macOS**: `/dev/tty.usbserial-*`
   - **Windows**: `COM3`, `COM4`, etc.

3. Run the Python demo:

```bash
cd ../host
python3 inference_demo.py /dev/ttyUSB1
```

## Board Interface

### Clock and Reset

- **Clock**: 100 MHz oscillator (W5) - used directly, no clock wizard needed
- **Reset**: Center button (BTNC, U18) - press to reset the TPU

### UART Communication

- **RX** (B18): Receives commands from PC
- **TX** (A18): Sends responses to PC
- **Baud Rate**: 115200
- **Format**: 8N1 (8 data bits, no parity, 1 stop bit)

### LED Status Display

LEDs display different information based on switch settings SW[15:14]:

#### Mode 00 (Default): MLP State and Status
- `LED[3:0]` - MLP FSM state
  - 0: IDLE
  - 1: LOAD_WEIGHT
  - 2: LOAD_ACT
  - 3: COMPUTE
  - 4: DRAIN
  - 5: TRANSFER
  - 6: NEXT_LAYER
  - 7: WAIT_WEIGHTS
  - 8: DONE (shows as 0)
- `LED[6:4]` - Current layer (0-1)
- `LED[7]` - Layer complete flag
- `LED[8]` - Accumulator valid
- `LED[9]` - UART RX line state
- `LED[10]` - UART TX line state
- `LED[11]` - Reset indicator
- `LED[15:12]` - UART controller state

#### Mode 01: Accumulator Result
- `LED[15:0]` - Lower 16 bits of acc0 (computation result)

#### Mode 10: UART Controller Detail
- `LED[3:0]` - UART controller state
- `LED[7:4]` - Current command being processed
- `LED[10:8]` - Byte count
- `LED[12:11]` - Response byte index
- `LED[13]` - TX valid
- `LED[14]` - RX valid
- `LED[15]` - Weights ready flag

#### Mode 11: Cycle Counter and Layer Info
- `LED[4:0]` - Cycle count
- `LED[7:5]` - Current layer
- `LED[11:8]` - MLP state
- `LED[12]` - Layer complete
- `LED[13]` - Accumulator valid
- `LED[15:14]` - Mode indicator (11)

### Switches

- `SW[15:14]` - LED display mode select (see above)
- `SW[13:0]` - Available for future debug features

## Resource Utilization

Expected resource usage on XC7A35T (approximate):

- **LUTs**: ~3,000-5,000 (15-25% of available)
- **FFs**: ~2,000-3,000 (5-10% of available)
- **BRAMs**: ~10-15 (20-30% of available)
- **DSPs**: 0 (using LUT-based multipliers)

Actual utilization will be shown in the post-implementation reports.

## Timing

- **Target Clock**: 100 MHz (10 ns period)
- **UART Baud**: 115200 (meets timing with large margin)
- **Critical Path**: Typically in MLP datapath or accumulator

Check `timing_summary_post_impl.rpt` for detailed timing analysis.

## Troubleshooting

### Synthesis/Implementation Fails

1. Check Vivado version (requires 2019.2+)
2. Verify all RTL files exist in `../rtl/`
3. Check build log for specific errors
4. Try cleaning and rebuilding:
   ```bash
   rm -rf vivado_project/
   vivado -mode batch -source build_vivado.tcl
   ```

### UART Communication Issues

1. **Find correct port**:
   ```bash
   ls /dev/ttyUSB*  # Linux
   ls /dev/tty.*    # macOS
   ```

2. **Check permissions** (Linux):
   ```bash
   sudo chmod 666 /dev/ttyUSB1
   # or add user to dialout group
   sudo usermod -a -G dialout $USER
   ```

3. **Verify baud rate**: Must be 115200

4. **Check LED[9:10]**: Should toggle during communication

### No Response from TPU

1. Press center button (BTNC) to reset
2. Check LED[11] - should go high during reset
3. Verify LEDs show activity in Mode 00
4. Try a simple status command:
   ```python
   from tpu_driver import TPUDriver
   with TPUDriver('/dev/ttyUSB1') as tpu:
       state, cycle = tpu.read_status()
       print(f"State: {state}, Cycle: {cycle}")
   ```

## Advanced Usage

### Interactive Vivado Build

For debugging or customization:

```bash
vivado -mode tcl -source build_vivado.tcl
```

This opens Vivado in TCL mode. After the script completes, you can:
- Examine the design
- Run additional reports
- Modify constraints
- Re-run implementation with different strategies

### Custom Implementation Strategy

Edit `build_vivado.tcl` and change:

```tcl
set_property strategy "Performance_Explore" [get_runs impl_1]
```

Available strategies:
- `Performance_Explore` - Optimize for speed
- `Performance_ExplorePostRoutePhysOpt` - Aggressive timing optimization
- `Area_Explore` - Minimize resource usage
- `Power_DefaultOpt` - Reduce power consumption

### Viewing Waveforms

The design includes internal signal probes. To debug:

1. Add ILA (Integrated Logic Analyzer) cores
2. Re-synthesize and implement
3. Use Vivado Hardware Manager to capture waveforms

## Next Steps

1. **Build and program** the FPGA
2. **Test basic communication** with `tpu_driver.py`
3. **Run inference demo** with `inference_demo.py`
4. **Monitor LEDs** during operation
5. **Experiment** with different matrices

## References

- [Basys3 Reference Manual](https://digilent.com/reference/programmable-logic/basys-3/reference-manual)
- [Basys3 Schematic](https://digilent.com/reference/_media/basys3:basys3_sch.pdf)
- [Vivado Design Suite User Guide](https://www.xilinx.com/support/documentation-navigation/design-hubs/dh0010-vivado-design-hub.html)
