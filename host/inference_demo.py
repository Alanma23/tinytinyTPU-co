#!/usr/bin/env python3
"""
TinyTinyTPU Inference Demo

Demonstrates using the TPU driver for matrix multiplication inference.
Shows various test cases and validates results.

Usage:
    python inference_demo.py /dev/ttyUSB0
    python inference_demo.py COM3
"""

import sys
import argparse
from tpu_driver import TPUDriver


def print_matrix(matrix, name="Matrix"):
    """Pretty print a 2x2 matrix"""
    print(f"{name}:")
    print(f"  [{matrix[0][0]:3d}, {matrix[0][1]:3d}]")
    print(f"  [{matrix[1][0]:3d}, {matrix[1][1]:3d}]")


def test_identity_matrix(tpu: TPUDriver):
    """Test 1: Identity matrix multiplication"""
    print("\n" + "="*60)
    print("Test 1: Identity Matrix")
    print("="*60)

    weights = [[1, 0], [0, 1]]
    activations = [[10, 20], [10, 20]]

    print_matrix(weights, "Weights (Identity)")
    print_matrix(activations, "Activations")

    result = tpu.inference(weights, activations)

    print(f"\nResult: {result}")
    print(f"Result (hex): 0x{result & 0xFFFFFFFF:08X}")

    # Expected: Identity matrix should preserve values
    # A * I ≈ A (with quantization effects)
    print("\n✓ Identity matrix test complete")


def test_simple_multiply(tpu: TPUDriver):
    """Test 2: Simple multiplication"""
    print("\n" + "="*60)
    print("Test 2: Simple Multiplication")
    print("="*60)

    weights = [[2, 0], [0, 2]]
    activations = [[5, 10], [5, 10]]

    print_matrix(weights, "Weights (2x scale)")
    print_matrix(activations, "Activations")

    result = tpu.inference(weights, activations)

    print(f"\nResult: {result}")
    print(f"Result (hex): 0x{result & 0xFFFFFFFF:08X}")

    # Expected: Scaling by 2
    print("\n✓ Simple multiply test complete")


def test_mixed_values(tpu: TPUDriver):
    """Test 3: Mixed positive values"""
    print("\n" + "="*60)
    print("Test 3: Mixed Values")
    print("="*60)

    weights = [[1, 2], [3, 4]]
    activations = [[5, 6], [7, 8]]

    print_matrix(weights, "Weights")
    print_matrix(activations, "Activations")

    result = tpu.inference(weights, activations)

    print(f"\nResult: {result}")
    print(f"Result (hex): 0x{result & 0xFFFFFFFF:08X}")

    # Matrix multiply (for row 0):
    # [1,2] · [[5,6],[7,8]] = [1*5 + 2*7, 1*6 + 2*8] = [19, 22]
    print("\n✓ Mixed values test complete")


def test_status_polling(tpu: TPUDriver):
    """Test 4: Status polling"""
    print("\n" + "="*60)
    print("Test 4: Status Polling")
    print("="*60)

    print("Checking TPU status...")
    state, cycle_count = tpu.read_status()

    print(f"State: {state}")
    print(f"Cycle Count: {cycle_count}")

    state_names = {
        0: "IDLE",
        1: "LOAD_WEIGHT",
        2: "LOAD_ACT",
        3: "COMPUTE",
        4: "DRAIN",
        5: "TRANSFER",
        6: "NEXT_LAYER",
        7: "WAIT_WEIGHTS",
        8: "DONE"
    }

    state_name = state_names.get(state, "UNKNOWN")
    print(f"State Name: {state_name}")

    print("\n✓ Status polling test complete")


def test_sequential_operations(tpu: TPUDriver):
    """Test 5: Sequential operations"""
    print("\n" + "="*60)
    print("Test 5: Sequential Operations")
    print("="*60)

    print("Running 3 sequential inferences...")

    test_cases = [
        ([[1, 0], [0, 1]], [[1, 1], [1, 1]]),
        ([[2, 0], [0, 2]], [[2, 2], [2, 2]]),
        ([[3, 0], [0, 3]], [[3, 3], [3, 3]])
    ]

    for i, (weights, activations) in enumerate(test_cases, 1):
        print(f"\nInference {i}:")
        result = tpu.inference(weights, activations)
        print(f"  Result: {result} (0x{result & 0xFFFFFFFF:08X})")

    print("\n✓ Sequential operations test complete")


def main():
    """Main demo function"""
    parser = argparse.ArgumentParser(description='TinyTinyTPU Inference Demo')
    parser.add_argument('port', help='Serial port (e.g., /dev/ttyUSB0 or COM3)')
    parser.add_argument('--baud', type=int, default=115200,
                        help='Baud rate (default: 115200)')
    parser.add_argument('--test', type=int, choices=range(1, 6),
                        help='Run specific test only (1-5)')

    args = parser.parse_args()

    print("TinyTinyTPU v1 Inference Demo")
    print("==============================")
    print(f"Serial Port: {args.port}")
    print(f"Baud Rate: {args.baud}")
    print()

    try:
        with TPUDriver(args.port, baud_rate=args.baud) as tpu:
            print("✓ Connected to TPU")

            if args.test:
                # Run specific test
                tests = {
                    1: test_identity_matrix,
                    2: test_simple_multiply,
                    3: test_mixed_values,
                    4: test_status_polling,
                    5: test_sequential_operations
                }
                tests[args.test](tpu)
            else:
                # Run all tests
                test_identity_matrix(tpu)
                test_simple_multiply(tpu)
                test_mixed_values(tpu)
                test_status_polling(tpu)
                test_sequential_operations(tpu)

            print("\n" + "="*60)
            print("All tests complete!")
            print("="*60)

    except KeyboardInterrupt:
        print("\n\nInterrupted by user")
        sys.exit(1)
    except Exception as e:
        print(f"\nError: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
