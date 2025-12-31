#!/usr/bin/env python3
"""
Debug script to diagnose TPU hardware issues
"""

import sys
import time
from tpu_driver import TPUDriver

def debug_tpu(port: str):
    """Run comprehensive diagnostics on TPU hardware."""

    print("TinyTinyTPU Hardware Diagnostics")
    print("=" * 60)
    print(f"Port: {port}\n")

    with TPUDriver(port) as tpu:
        # Test 1: Status check
        print("Test 1: Initial Status Check")
        print("-" * 60)
        state, cycle = tpu.read_status()
        print(f"State: {state} (expected 0=IDLE)")
        print(f"Cycle: {cycle}")

        if state != 0:
            print("⚠ WARNING: TPU not in IDLE state!")
            print("  → Try pressing CENTER button (BTNC) to reset\n")
        else:
            print("✓ TPU in IDLE state\n")

        # Test 2: Simple identity test with detailed monitoring
        print("Test 2: Identity Matrix with Monitoring")
        print("-" * 60)
        weights = [[1, 0], [0, 1]]
        activations = [[10, 20], [10, 20]]

        print("Loading weights: [[1, 0], [0, 1]]")
        tpu.write_weights(weights)
        time.sleep(0.1)

        state, cycle = tpu.read_status()
        print(f"  After weights: state={state}, cycle={cycle}")

        print("Loading activations: [[10, 20], [10, 20]]")
        tpu.write_activations(activations)
        time.sleep(0.1)

        state, cycle = tpu.read_status()
        print(f"  After activations: state={state}, cycle={cycle}")

        print("Executing...")
        tpu.execute()
        time.sleep(0.1)

        state, cycle = tpu.read_status()
        print(f"  After execute: state={state}, cycle={cycle}")

        if state == 0:
            print("  ⚠ WARNING: Still in IDLE - computation may not have started!")

        print("Waiting for completion...")
        start = time.time()
        done = tpu.wait_for_done(timeout=5.0)
        elapsed = time.time() - start

        if done:
            print(f"  ✓ Computation completed in {elapsed:.2f}s")
        else:
            print(f"  ✗ TIMEOUT after {elapsed:.2f}s")
            state, cycle = tpu.read_status()
            print(f"    Final state={state}, cycle={cycle}")

        print("Reading result...")
        result = tpu.read_result()
        print(f"  Result: {result}")
        print(f"  Result (hex): 0x{result:08X}")
        print(f"  Expected: 140 (0x8C) for identity with [10,20,10,20]\n")

        # Test 3: Different inputs to check if result changes
        print("Test 3: Different Inputs Test")
        print("-" * 60)

        test_cases = [
            ([[2, 0], [0, 2]], [[5, 10], [5, 10]], "2x scale"),
            ([[0, 0], [0, 0]], [[5, 10], [5, 10]], "zero weights"),
            ([[1, 1], [1, 1]], [[1, 1], [1, 1]], "all ones"),
        ]

        results = []
        for weights, activations, name in test_cases:
            result = tpu.inference(weights, activations, timeout=5.0)
            results.append(result)
            print(f"{name:15s}: result={result:3d} (0x{result:08X})")

        print()
        if len(set(results)) == 1:
            print("✗ PROBLEM: All results are the same!")
            print("  → TPU is not computing different values")
            print("  → Possible issues:")
            print("    1. Weights/activations not being loaded")
            print("    2. MLP stuck in a state")
            print("    3. Result register not updating")
        else:
            print("✓ Results are different - TPU is computing!\n")

        # Test 4: Raw result register read
        print("Test 4: Raw Result Register Read")
        print("-" * 60)
        print("Reading result 5 times without computing:")
        for i in range(5):
            result = tpu.read_result()
            print(f"  Read {i+1}: {result} (0x{result:08X})")

        if len(set([tpu.read_result() for _ in range(5)])) == 1:
            print("  → Result register is static (not changing)")
        else:
            print("  ⚠ Result register changing without computation!\n")

        # Test 5: Status after multiple operations
        print("\nTest 5: Final Status Check")
        print("-" * 60)
        state, cycle = tpu.read_status()
        print(f"Final state: {state}")
        print(f"Final cycle: {cycle}")
        print()

        # Summary
        print("=" * 60)
        print("DIAGNOSTIC SUMMARY")
        print("=" * 60)
        print("Check the Basys3 LEDs:")
        print("  1. Set SW[15:14] = 00 (down/down)")
        print("  2. LED[3:0] should show MLP state")
        print("     → Should be 0 when idle")
        print("     → Should cycle 0→1→2→3→4→5→0 during compute")
        print("  3. LED[9:10] should flicker during UART communication")
        print()
        print("Next steps:")
        print("  1. Press CENTER button (BTNC) to reset TPU")
        print("  2. Watch LEDs during next inference")
        print("  3. If LED[3:0] stays at 0, MLP is not starting")
        print("  4. If LED[9:10] don't flicker, UART issue")
        print("=" * 60)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 debug_tpu.py <serial_port>")
        print("Example: python3 debug_tpu.py /dev/tty.usbserial-210183A27BE01")
        sys.exit(1)

    debug_tpu(sys.argv[1])
