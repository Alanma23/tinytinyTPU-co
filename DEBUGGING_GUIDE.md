# TPU Debugging Guide

## Current Issue
TPU stuck in IDLE state (state=0), constant result 0x28, not responding to execute commands.

## Step 1: Verify Basic Hardware Functionality

### Option A: Quick LED Test (Recommended First)
1. **Temporarily change the top-level module in Vivado:**
   - In Vivado project settings, change top module from `basys3_top` to `basys3_top_debug`
   - Resynthesize and program the board

2. **Expected LED behavior:**
   - **LED[7:0]**: Should count down from FF to 00 rapidly, then stay at 00
   - **LED[8]**: Should blink every ~0.1 seconds (heartbeat)
   - **LED[10]**: Should be ON briefly after power-up or button press, then go OFF
   - **LED[9]**: Should turn ON when you press center button

3. **If LEDs don't behave as expected:**
   - Clock is not working properly
   - Reset circuit is stuck
   - Synthesis failed

### Option B: Full TPU with LED Monitoring

1. **Build with `basys3_top` (main design)**

2. **Set switches SW[15:14] = 11 (both UP)** for detailed UART debug mode

3. **Run the Python test and watch LEDs:**
   ```
   python3 debug_tpu.py /dev/tty.usbserial-210183A27BE01
   ```

4. **LED meanings in mode 11 (SW[15:14]=11):**
   - **LED[3:0]**: UART controller state (should change during test)
   - **LED[7:4]**: Upper 4 bits of last command byte
   - **LED[10:8]**: UART byte counter (should change during test)
   - **LED[11]**: UART RX valid (should flicker briefly during test)
   - **LED[12]**: UART TX ready
   - **LED[13]**: Weights ready flag
   - **LED[14]**: **START_MLP signal** (should turn ON when execute command sent)
   - **LED[15]**: Reset indicator

5. **What to check:**
   - **LED[14] (START_MLP)**: Does it turn ON after you send execute command?
     - If NO: UART controller not setting start_mlp
     - If YES: MLP is receiving start signal but not transitioning

   - **LED[3:0] (UART state)**: Does it change during the test?
     - If NO: UART RX not working
     - If YES: UART is functioning

## Step 2: Check Vivado Reports

### Synthesis Report
```
Reports → Synth Design → Report Utilization
```

**Look for:**
- **Block RAM (BRAM/RAMB)**: Should show 2-4 BRAMs used
  - If 0: unified_buffer not inferred as BRAM
- **DSP48**: Should show 8-16 DSP blocks used
  - If 0: Multipliers not inferred correctly
- **Flip-Flops**: Should show ~2000-4000 FFs
  - If way less: Design was over-optimized

### Timing Report
```
Reports → Impl Design → Report Timing Summary
```

**Look for:**
- **WNS (Worst Negative Slack)**: Should be > -1.0ns (ideally positive)
  - If < -3ns: Design won't work reliably
- **TNS (Total Negative Slack)**: Ideally 0
  - If large negative value: Many timing violations

### Critical Warnings
```
Reports → Synth Design → Report Messages
```

**Look for:**
- Any "inferred latch" warnings
- "Signal X has no driver" warnings
- "Unconnected pins" warnings

## Step 3: Verify Rebuild

### Did you FULLY rebuild?
In Vivado TCL console:
```tcl
# Reset everything
reset_run synth_1
reset_run impl_1

# Rebuild from scratch
launch_runs impl_1 -to_step write_bitstream
wait_on_run impl_1

# Program device
open_hw_manager
open_hw_target
current_hw_device [get_hw_devices xc7a35t_0]
set_property PROGRAM.FILE {path/to/your/bitstream.bit} [get_hw_devices xc7a35t_0]
program_hw_devices [get_hw_devices xc7a35t_0]
```

## Step 4: Check for Simulation

If you have Cocotb or Vivado simulator available, run:
```bash
cd tests
pytest test_mlp_integration.py -v
```

This will verify the RTL logic works correctly independent of FPGA issues.

## Common Problems and Solutions

### Problem: LED[14] (START_MLP) never turns ON
**Cause:** UART controller not receiving/processing execute command
**Solution:** Check UART baud rate, check Python script timing

### Problem: LED[14] turns ON but state stays 0
**Cause:** MLP FSM not transitioning from IDLE
**Solution:**
- Check timing report - might be failing setup timing
- Verify start_mlp signal connectivity in synthesis schematic
- Check for synthesis warnings about optimized-away logic

### Problem: Reset stuck (LED[10] always ON)
**Cause:** Reset circuit not working
**Solution:**
- Verify btnC is not stuck/floating
- Check rst_counter initialization
- Try the debug top-level first

### Problem: No LEDs change at all
**Cause:** Clock not working or bitstream not programmed
**Solution:**
- Verify board is powered
- Try reprogramming bitstream
- Check Vivado hardware manager connection

## Report Back

Please report:
1. **Option A or B results** (LED states)
2. **BRAM utilization**: _____ BRAMs
3. **DSP48 utilization**: _____ DSP blocks
4. **WNS from timing**: _____ ns
5. **LED[14] behavior**: ON / OFF / Flickering
6. **LED[3:0] behavior**: Static / Changing
