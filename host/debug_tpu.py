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

        print("Executing with fast polling...")
        tpu.execute()

        # Fast poll to catch state transitions (computation runs in ~20 cycles @ 100MHz = 200ns)
        states_seen = []
        for _ in range(20):
            state, cycle = tpu.read_status()
            states_seen.append(state)

        unique_states = sorted(set(states_seen))
        print(f"  States observed during fast poll: {unique_states}")
        print(f"  (0=IDLE, 1=LOAD_W, 2=LOAD_A, 3=COMPUTE, 4=DRAIN, 5=XFER, 6=NEXT, 7=WAIT, 8=DONE)")

        state, cycle = tpu.read_status()
        print(f"  Final state: {state}, cycle: {cycle}")

        if state == 0 and unique_states == [0]:
            print("  ⚠ WARNING: Never left IDLE - start_mlp pulse may not be working!")

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
        expected = 20  # C = [[10,20],[10,20]], acc0 reads column sum = 10+10=20
        if result == expected:
            print(f"  ✓ Correct! Expected {expected} for identity matrix\n")
        else:
            print(f"  ✗ Expected {expected}, got {result}\n")

        # Test 3: Different inputs to check if result changes
        print("Test 3: Different Inputs Test")
        print("-" * 60)

        # Each test case: (weights, activations, name, expected_result)
        # Expected values based on C = W × A, acc0 = sum of first column of C
        test_cases = [
            # W=[[2,0],[0,2]], A=[[5,10],[5,10]] → C=[[10,20],[10,20]], acc0=10+10=20
            ([[2, 0], [0, 2]], [[5, 10], [5, 10]], "2x scale", 20),
            # W=[[0,0],[0,0]], A=[[5,10],[5,10]] → C=[[0,0],[0,0]], acc0=0
            ([[0, 0], [0, 0]], [[5, 10], [5, 10]], "zero weights", 0),
            # W=[[1,1],[1,1]], A=[[1,1],[1,1]] → C=[[2,2],[2,2]], acc0=2+2=4
            ([[1, 1], [1, 1]], [[1, 1], [1, 1]], "all ones", 4),
        ]

        results = []
        all_passed = True
        for weights, activations, name, expected in test_cases:
            result = tpu.inference(weights, activations, timeout=5.0)
            results.append(result)
            passed = result == expected
            if not passed:
                all_passed = False
            status = "✓" if passed else "✗"
            print(f"{status} {name:15s}: result={result:3d}, expected={expected:3d}")

        print()
        if len(set(results)) == 1:
            print("✗ PROBLEM: All results are the same!")
            print("  → TPU is not computing different values")
            print("  → Possible issues:")
            print("    1. Weights/activations not being loaded")
            print("    2. MLP stuck in a state")
            print("    3. Result register not updating")
        elif all_passed:
            print("✓ All tests passed!\n")
        else:
            print("⚠ Some tests failed - check computation logic\n")

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

        # Check all test results
        if all_passed:
            print("✓ All matrix multiply tests PASSED!")
            print()
            print("The TPU is computing correctly. Expected values:")
            print("  - Identity [[1,0],[0,1]] × [[10,20],[10,20]] → acc0 = 20")
            print("  - 2x scale [[2,0],[0,2]] × [[5,10],[5,10]]   → acc0 = 20")
            print("  - Zero weights → acc0 = 0")
            print("  - All ones → acc0 = 4")
        else:
            print("⚠ Some tests FAILED - check computation logic")
            print()
            print("Expected values (acc0 = sum of column 0 of result matrix):")
            print("  C = W × A, where acc0 = C[0,0] + C[1,0]")
            print()
            print("Debug checklist:")
            print("  1. Verify weight loading order (bottom row first, staggered columns)")
            print("  2. Verify activation packing (column-major for systolic timing)")
            print("  3. Check accumulator clear logic (acc_clear on start_mlp)")
            print("  4. Run simulation tests to compare expected behavior")

        print()
        print("MLP FSM States:")
        print("  0=IDLE, 1=LOAD_WEIGHT, 2=LOAD_ACT, 3=COMPUTE")
        print("  4=DRAIN, 5=TRANSFER, 6=NEXT_LAYER, 7=WAIT_WEIGHTS, 8=DONE")
        print("=" * 60)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 debug_tpu.py <serial_port>")
        print("Example: python3 debug_tpu.py /dev/tty.usbserial-210183A27BE01")
        sys.exit(1)

    debug_tpu(sys.argv[1])
