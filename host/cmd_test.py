#!/usr/bin/env python3
"""
Minimal command test - isolate where TPU commands fail.

Since echo works, UART RX is fine. This tests each command step.
"""

import sys
import time
import serial

def cmd_test(port: str):
    print("TPU Command Isolation Test")
    print("=" * 60)
    print(f"Port: {port}")
    print("\nPrerequisites:")
    print("  - Echo test passed (UART RX works)")
    print("  - Set SW[15:14] = 10 or 11 for debug LEDs")
    print()

    ser = serial.Serial(port, 115200, timeout=2.0)
    time.sleep(0.1)
    ser.reset_input_buffer()

    # Test 1: STATUS command (0x05) - simplest, no data bytes
    print("Test 1: STATUS command (0x05)")
    print("-" * 40)
    print("  Sending 0x05...")
    ser.write(bytes([0x05]))
    time.sleep(0.1)

    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        print(f"  ✓ Response: {resp.hex()} ({len(resp)} bytes)")
        if len(resp) >= 1:
            state = (resp[0] >> 4) & 0x0F
            cycle = resp[0] & 0x0F
            print(f"    State={state}, Cycle={cycle}")
    else:
        print("  ✗ NO RESPONSE - uart_controller may not be processing commands")
        print("    Check LED[15:12] (uart_state) - should change from 0")
    print()

    # Test 2: READ_RESULT command (0x04) - no input data, returns 4 bytes
    print("Test 2: READ_RESULT command (0x04)")
    print("-" * 40)
    ser.reset_input_buffer()
    print("  Sending 0x04...")
    ser.write(bytes([0x04]))
    time.sleep(0.2)

    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        print(f"  ✓ Response: {resp.hex()} ({len(resp)} bytes)")
        if len(resp) >= 4:
            result = int.from_bytes(resp[:4], 'little', signed=True)
            print(f"    Result = {result} (0x{result & 0xFFFFFFFF:08X})")
    else:
        print("  ✗ NO RESPONSE")
    print()

    # Test 3: WRITE_WEIGHT command (0x01 + 4 data bytes)
    print("Test 3: WRITE_WEIGHT command (0x01 + 4 bytes)")
    print("-" * 40)
    ser.reset_input_buffer()
    weights = [0x01, 0x00, 0x00, 0x01]  # Identity matrix
    print(f"  Sending: 0x01 + {weights}")
    ser.write(bytes([0x01] + weights))
    time.sleep(0.2)

    # Check uart_state via STATUS
    ser.write(bytes([0x05]))
    time.sleep(0.1)
    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        state = (resp[0] >> 4) & 0x0F if resp else -1
        print(f"  Status after weights: state={state}")
        if state == 0:
            print("  ✓ Returned to IDLE - weight load completed")
        else:
            print(f"  ⚠ State={state} - may be stuck")
    else:
        print("  ✗ No status response")
    print()

    # Test 4: WRITE_ACT command (0x02 + 4 data bytes)
    print("Test 4: WRITE_ACT command (0x02 + 4 bytes)")
    print("-" * 40)
    ser.reset_input_buffer()
    acts = [10, 20, 10, 20]  # Test activations
    print(f"  Sending: 0x02 + {acts}")
    ser.write(bytes([0x02] + acts))
    time.sleep(0.2)

    ser.write(bytes([0x05]))
    time.sleep(0.1)
    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        state = (resp[0] >> 4) & 0x0F if resp else -1
        print(f"  Status after activations: state={state}")
    print()

    # Test 5: EXECUTE command (0x03)
    print("Test 5: EXECUTE command (0x03)")
    print("-" * 40)
    print("  Watch LED[14] (SW=11) - should flash!")
    ser.reset_input_buffer()
    print("  Sending 0x03...")
    ser.write(bytes([0x03]))
    time.sleep(0.05)  # Quick poll

    # Rapid status polling to catch state changes
    states_seen = []
    for _ in range(20):
        ser.write(bytes([0x05]))
        time.sleep(0.01)
        if ser.in_waiting > 0:
            resp = ser.read(ser.in_waiting)
            if resp:
                state = (resp[0] >> 4) & 0x0F
                states_seen.append(state)

    unique = sorted(set(states_seen))
    print(f"  States observed: {unique}")
    print(f"  (0=IDLE, 1=LOAD_W, 2=LOAD_A, 3=COMPUTE, 4=DRAIN, 8=DONE)")

    if unique == [0]:
        print("  ⚠ Never left IDLE - start_mlp pulse may not be triggering MLP")
    elif 8 in unique or len(unique) > 1:
        print("  ✓ MLP state machine is running!")
    print()

    # Test 6: Read final result
    print("Test 6: Final READ_RESULT")
    print("-" * 40)
    time.sleep(0.5)  # Let computation finish
    ser.reset_input_buffer()
    ser.write(bytes([0x04]))
    time.sleep(0.2)

    if ser.in_waiting > 0:
        resp = ser.read(ser.in_waiting)
        if len(resp) >= 4:
            result = int.from_bytes(resp[:4], 'little', signed=True)
            print(f"  Result = {result}")
            print(f"  Expected for identity @ [10,20,10,20]: acc0=20 or acc1=40")

    print("\n" + "=" * 60)
    print("DIAGNOSIS:")
    if len(unique) <= 1 and 0 in unique:
        print("  → MLP never starts. Check:")
        print("    1. LED[14] on SW=11 - does it flash on EXECUTE?")
        print("    2. start_mlp signal reaching mlp_top")
        print("    3. tpu_bridge pass-through")
    else:
        print("  → MLP runs but result may be wrong")
        print("    Check weight/activation loading")

    ser.close()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 cmd_test.py <serial_port>")
        sys.exit(1)
    cmd_test(sys.argv[1])
