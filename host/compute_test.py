#!/usr/bin/env python3
"""
TPU Computation Verification Test

Since MLP runs in ~250ns but UART takes ~170µs, we can't catch state transitions.
Instead, verify the computation by checking if results change predictably.
"""

import sys
import time
import serial

def send_cmd(ser, cmd_bytes):
    """Send command and small delay."""
    ser.write(bytes(cmd_bytes))
    time.sleep(0.01)

def read_result(ser):
    """Send READ_RESULT and get 4-byte response."""
    ser.reset_input_buffer()
    ser.write(bytes([0x04]))
    time.sleep(0.05)
    if ser.in_waiting >= 4:
        resp = ser.read(4)
        return int.from_bytes(resp, 'little', signed=True)
    return None

def run_inference(ser, weights, activations):
    """Run full inference: load weights, load activations, execute, read result."""
    # Load weights [W00, W01, W10, W11]
    send_cmd(ser, [0x01] + weights)
    time.sleep(0.02)

    # Load activations [A00, A01, A10, A11]
    send_cmd(ser, [0x02] + activations)
    time.sleep(0.02)

    # Execute
    send_cmd(ser, [0x03])
    time.sleep(0.1)  # Wait for computation

    return read_result(ser)

def compute_test(port: str):
    print("TPU Computation Verification")
    print("=" * 60)

    ser = serial.Serial(port, 115200, timeout=1.0)
    time.sleep(0.1)

    # Expected computation for 2x2 systolic array:
    # C = A × W  (matrix multiply)
    # acc0 = sum of column 0 of C
    # acc1 = sum of column 1 of C

    test_cases = [
        # (weights, activations, name, expected_acc0)
        # Weights: [W00, W01, W10, W11]  → W = [[W00, W01], [W10, W11]]
        # Acts:    [A00, A01, A10, A11]  → A = [[A00, A01], [A10, A11]]
        # C[i,j] = sum_k A[i,k] * W[k,j]
        # acc0 = C[0,0] + C[1,0] = (A00*W00 + A01*W10) + (A10*W00 + A11*W10)

        ([1, 0, 0, 0], [10, 0, 20, 0], "W00=1 only",
         "acc0 = 10*1 + 20*1 = 30"),

        ([0, 0, 0, 1], [0, 10, 0, 20], "W11=1 only",
         "acc1 = 10*1 + 20*1 = 30"),

        ([2, 0, 0, 0], [5, 0, 10, 0], "W00=2",
         "acc0 = 5*2 + 10*2 = 30"),

        ([1, 0, 0, 1], [10, 20, 10, 20], "Identity",
         "acc0 = 10+10 = 20, acc1 = 20+20 = 40"),

        ([0, 0, 0, 0], [10, 20, 10, 20], "Zero weights",
         "acc0 = 0, acc1 = 0"),
    ]

    print("\nRunning inference tests...")
    print("-" * 60)

    results = []
    for weights, acts, name, expected in test_cases:
        result = run_inference(ser, weights, acts)
        results.append(result)
        print(f"{name:20s}: result = {result:6d}  (expected: {expected})")

    print("\n" + "-" * 60)
    print("Analysis:")

    # Check if results are all the same (stuck)
    if len(set(results)) == 1:
        print("  ✗ All results identical - computation not working")
        print("    MLP may not be loading weights/activations correctly")
    else:
        print("  ✓ Results vary - computation IS happening!")

        # Check specific patterns
        if results[4] == 0:  # Zero weights
            print("  ✓ Zero weights gives 0 - weights are being loaded!")
        else:
            print(f"  ⚠ Zero weights gave {results[4]}, expected 0")
            print("    → Weights may not be loading correctly")

    # Additional diagnostic: read result without new computation
    print("\n" + "-" * 60)
    print("Checking if result persists (no new computation):")
    for i in range(3):
        time.sleep(0.1)
        r = read_result(ser)
        print(f"  Read {i+1}: {r}")

    ser.close()
    print("\n" + "=" * 60)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 compute_test.py <serial_port>")
        sys.exit(1)
    compute_test(sys.argv[1])
