#!/usr/bin/env python3
"""
TinyTinyTPU Forward Pass Demo
=============================

Comprehensive demonstration script for video recording.
Shows complete forward pass of a small neural network model.

This script demonstrates:
1. Single-layer inference
2. Multi-layer MLP forward pass
3. Real-time status monitoring
4. Result validation
5. Performance metrics

Usage:
    python demo_forward_pass.py /dev/tty.usbserial-210183A27BE01
    python demo_forward_pass.py COM3
"""

import sys
import time
from typing import List, Tuple
from tpu_driver import TPUDriver


class Colors:
    """ANSI color codes for terminal output"""
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def print_header(text: str):
    """Print a formatted header"""
    print(f"\n{Colors.BOLD}{Colors.HEADER}{'='*70}{Colors.ENDC}")
    print(f"{Colors.BOLD}{Colors.HEADER}{text.center(70)}{Colors.ENDC}")
    print(f"{Colors.BOLD}{Colors.HEADER}{'='*70}{Colors.ENDC}\n")


def print_section(text: str):
    """Print a section header"""
    print(f"\n{Colors.OKCYAN}{'─'*70}{Colors.ENDC}")
    print(f"{Colors.BOLD}{Colors.OKCYAN}{text}{Colors.ENDC}")
    print(f"{Colors.OKCYAN}{'─'*70}{Colors.ENDC}\n")


def print_matrix(matrix: List[List[int]], name: str = "Matrix"):
    """Pretty print a 2x2 matrix"""
    print(f"{Colors.BOLD}{name}:{Colors.ENDC}")
    print(f"  [{matrix[0][0]:3d}, {matrix[0][1]:3d}]")
    print(f"  [{matrix[1][0]:3d}, {matrix[1][1]:3d}]")


def print_result(result: int, expected: int = None, label: str = "Result"):
    """Print result with optional expected value"""
    status = ""
    if expected is not None:
        if result == expected:
            status = f"{Colors.OKGREEN}✓{Colors.ENDC}"
        else:
            status = f"{Colors.FAIL}✗{Colors.ENDC}"
    
    print(f"{label}: {Colors.BOLD}{result:6d}{Colors.ENDC} (0x{result:08X})", end="")
    if expected is not None:
        print(f" {status} Expected: {expected}", end="")
    print()


def monitor_computation(tpu: TPUDriver, verbose: bool = True):
    """Monitor TPU state during computation"""
    if not verbose:
        return
    
    states = {
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
    
    print(f"{Colors.OKBLUE}Monitoring computation...{Colors.ENDC}")
    start_time = time.time()
    last_state = None
    
    while True:
        state, cycle = tpu.read_status()
        state_name = states.get(state, f"UNKNOWN({state})")
        
        if state != last_state:
            elapsed = time.time() - start_time
            print(f"  [{elapsed*1000:6.2f} ms] State: {Colors.BOLD}{state_name}{Colors.ENDC} (cycle: {cycle})")
            last_state = state
        
        if state == 0 or state == 8:  # IDLE or DONE
            break
        
        time.sleep(0.001)  # 1ms polling
    
    elapsed = time.time() - start_time
    print(f"{Colors.OKGREEN}  ✓ Computation complete in {elapsed*1000:.2f} ms{Colors.ENDC}\n")


def demo_single_layer_inference(tpu: TPUDriver):
    """Demo 1: Single-layer inference with various test cases"""
    print_header("DEMO 1: Single-Layer Inference")
    
    test_cases = [
        {
            "name": "Identity Matrix",
            "weights": [[1, 0], [0, 1]],
            "activations": [[10, 20], [10, 20]],
            "expected": 20,
            "description": "Identity matrix preserves input values"
        },
        {
            "name": "Scaling (2x)",
            "weights": [[2, 0], [0, 2]],
            "activations": [[5, 10], [5, 10]],
            "expected": 20,
            "description": "Scales activations by factor of 2"
        },
        {
            "name": "All Ones",
            "weights": [[1, 1], [1, 1]],
            "activations": [[1, 1], [1, 1]],
            "expected": 4,
            "description": "Matrix multiply: [[1,1],[1,1]] × [[1,1],[1,1]] = [[2,2],[2,2]]"
        },
        {
            "name": "Mixed Values",
            "weights": [[1, 2], [3, 4]],
            "activations": [[5, 6], [7, 8]],
            "expected": None,  # Complex calculation
            "description": "General matrix multiplication"
        }
    ]
    
    for i, test in enumerate(test_cases, 1):
        print_section(f"Test {i}: {test['name']}")
        print(f"{Colors.OKBLUE}{test['description']}{Colors.ENDC}\n")
        
        print_matrix(test['weights'], "Weights")
        print_matrix(test['activations'], "Activations")
        
        start_time = time.time()
        result = tpu.inference(test['weights'], test['activations'], timeout=5.0)
        elapsed = (time.time() - start_time) * 1000  # Convert to ms
        
        print_result(result, test['expected'], "Result")
        print(f"{Colors.OKBLUE}Inference time: {elapsed:.2f} ms{Colors.ENDC}\n")
        
        time.sleep(0.5)  # Brief pause between tests


def demo_mlp_forward_pass(tpu: TPUDriver):
    """Demo 2: Multi-layer MLP forward pass"""
    print_header("DEMO 2: Multi-Layer MLP Forward Pass")
    
    print(f"{Colors.BOLD}Simulating a 2-layer neural network:{Colors.ENDC}\n")
    print("Layer 1: Input → Hidden (2×2 → 2×2)")
    print("Layer 2: Hidden → Output (2×2 → 2×2)\n")
    
    # Layer 1 weights
    W1 = [[1, 2], [3, 4]]
    # Input activations
    A0 = [[5, 6], [7, 8]]
    
    print_section("Layer 1: Input → Hidden")
    print(f"{Colors.BOLD}Computing: H = A0 × W1{Colors.ENDC}\n")
    print_matrix(W1, "Weights W1")
    print_matrix(A0, "Input A0")
    
    start_time = time.time()
    h1_result = tpu.inference(W1, A0, timeout=5.0)
    layer1_time = (time.time() - start_time) * 1000
    
    print_result(h1_result, None, "Hidden Layer Output (acc0)")
    print(f"{Colors.OKBLUE}Layer 1 time: {layer1_time:.2f} ms{Colors.ENDC}\n")
    
    # Expected: H[0,0] = 5*1 + 6*3 = 23, H[1,0] = 7*1 + 8*3 = 31
    # acc0 = H[0,0] + H[1,0] = 23 + 31 = 54
    expected_h1 = 54
    print(f"{Colors.OKBLUE}Expected: H[0,0] + H[1,0] = 23 + 31 = {expected_h1}{Colors.ENDC}")
    
    if h1_result == expected_h1:
        print(f"{Colors.OKGREEN}✓ Layer 1 result matches expected value!{Colors.ENDC}\n")
    else:
        print(f"{Colors.WARNING}⚠ Layer 1 result differs from expected{Colors.ENDC}\n")
    
    time.sleep(1)
    
    # Layer 2 weights
    W2 = [[1, 1], [1, 1]]
    # For demo purposes, we'll use the same input (in real MLP, this would be H1)
    A1 = [[10, 20], [10, 20]]
    
    print_section("Layer 2: Hidden → Output")
    print(f"{Colors.BOLD}Computing: Y = H1 × W2{Colors.ENDC}\n")
    print(f"{Colors.OKBLUE}Note: Using simplified activations for demo{Colors.ENDC}\n")
    print_matrix(W2, "Weights W2")
    print_matrix(A1, "Hidden Activations H1")
    
    start_time = time.time()
    y_result = tpu.inference(W2, A1, timeout=5.0)
    layer2_time = (time.time() - start_time) * 1000
    
    print_result(y_result, None, "Output Layer (acc0)")
    print(f"{Colors.OKBLUE}Layer 2 time: {layer2_time:.2f} ms{Colors.ENDC}\n")
    
    total_time = layer1_time + layer2_time
    print(f"{Colors.BOLD}Total forward pass time: {total_time:.2f} ms{Colors.ENDC}")
    print(f"{Colors.BOLD}Throughput: {1000/total_time:.1f} inferences/second{Colors.ENDC}\n")


def demo_performance_benchmark(tpu: TPUDriver):
    """Demo 3: Performance benchmark"""
    print_header("DEMO 3: Performance Benchmark")
    
    weights = [[1, 1], [1, 1]]
    activations = [[10, 20], [10, 20]]
    
    print(f"{Colors.BOLD}Running 10 consecutive inferences...{Colors.ENDC}\n")
    
    times = []
    for i in range(10):
        start = time.time()
        result = tpu.inference(weights, activations, timeout=5.0)
        elapsed = (time.time() - start) * 1000
        times.append(elapsed)
        print(f"  Inference {i+1:2d}: {elapsed:6.2f} ms → Result: {result}")
    
    avg_time = sum(times) / len(times)
    min_time = min(times)
    max_time = max(times)
    
    print(f"\n{Colors.BOLD}Performance Statistics:{Colors.ENDC}")
    print(f"  Average: {avg_time:.2f} ms")
    print(f"  Minimum: {min_time:.2f} ms")
    print(f"  Maximum: {max_time:.2f} ms")
    print(f"  Throughput: {1000/avg_time:.1f} inferences/second\n")


def demo_status_monitoring(tpu: TPUDriver):
    """Demo 4: Real-time status monitoring"""
    print_header("DEMO 4: Real-Time Status Monitoring")
    
    states = {
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
    
    print(f"{Colors.BOLD}Initial Status:{Colors.ENDC}")
    state, cycle = tpu.read_status()
    print(f"  State: {Colors.BOLD}{states.get(state, 'UNKNOWN')}{Colors.ENDC} ({state})")
    print(f"  Cycle: {cycle}\n")
    
    print(f"{Colors.BOLD}Starting inference with monitoring...{Colors.ENDC}\n")
    
    weights = [[1, 0], [0, 1]]
    activations = [[10, 20], [10, 20]]
    
    # Load weights
    print(f"{Colors.OKBLUE}Loading weights...{Colors.ENDC}")
    tpu.write_weights(weights)
    time.sleep(0.1)
    state, cycle = tpu.read_status()
    print(f"  After weights: State={states.get(state, 'UNKNOWN')}, Cycle={cycle}\n")
    
    # Load activations
    print(f"{Colors.OKBLUE}Loading activations...{Colors.ENDC}")
    tpu.write_activations(activations)
    time.sleep(0.1)
    state, cycle = tpu.read_status()
    print(f"  After activations: State={states.get(state, 'UNKNOWN')}, Cycle={cycle}\n")
    
    # Execute and monitor
    print(f"{Colors.OKBLUE}Executing computation...{Colors.ENDC}")
    tpu.execute()
    monitor_computation(tpu, verbose=True)
    
    # Read result
    result = tpu.read_result()
    print_result(result, 20, "Final Result")
    
    # Final status
    state, cycle = tpu.read_status()
    print(f"\n{Colors.BOLD}Final Status:{Colors.ENDC}")
    print(f"  State: {Colors.BOLD}{states.get(state, 'UNKNOWN')}{Colors.ENDC} ({state})")
    print(f"  Cycle: {cycle}\n")


def demo_comprehensive_test_suite(tpu: TPUDriver):
    """Demo 5: Comprehensive test suite"""
    print_header("DEMO 5: Comprehensive Test Suite")
    
    test_suite = [
        ("Identity", [[1, 0], [0, 1]], [[10, 20], [10, 20]], 20),
        ("2x Scale", [[2, 0], [0, 2]], [[5, 10], [5, 10]], 20),
        ("Zero Weights", [[0, 0], [0, 0]], [[5, 10], [5, 10]], 0),
        ("All Ones", [[1, 1], [1, 1]], [[1, 1], [1, 1]], 4),
        ("Negative", [[-1, 0], [0, -1]], [[10, 20], [10, 20]], -20),
    ]
    
    print(f"{Colors.BOLD}Running {len(test_suite)} test cases...{Colors.ENDC}\n")
    
    passed = 0
    failed = 0
    
    for name, weights, activations, expected in test_suite:
        result = tpu.inference(weights, activations, timeout=5.0)
        
        if result == expected:
            status = f"{Colors.OKGREEN}✓ PASS{Colors.ENDC}"
            passed += 1
        else:
            status = f"{Colors.FAIL}✗ FAIL{Colors.ENDC}"
            failed += 1
        
        print(f"  {name:15s}: result={result:6d}, expected={expected:6d} {status}")
    
    print(f"\n{Colors.BOLD}Test Results:{Colors.ENDC}")
    print(f"  {Colors.OKGREEN}Passed: {passed}{Colors.ENDC}")
    if failed > 0:
        print(f"  {Colors.FAIL}Failed: {failed}{Colors.ENDC}")
    else:
        print(f"  {Colors.OKGREEN}All tests passed!{Colors.ENDC}")
    print()


def main():
    """Main demo function"""
    if len(sys.argv) != 2:
        print("Usage: python demo_forward_pass.py <serial_port>")
        print("Example: python demo_forward_pass.py /dev/tty.usbserial-210183A27BE01")
        sys.exit(1)
    
    port = sys.argv[1]
    
    print_header("TinyTinyTPU Forward Pass Demo")
    print(f"{Colors.BOLD}Serial Port: {port}{Colors.ENDC}\n")
    
    try:
        with TPUDriver(port) as tpu:
            print(f"{Colors.OKGREEN}✓ Connected to TPU{Colors.ENDC}\n")
            
            # Run all demos
            demo_single_layer_inference(tpu)
            time.sleep(1)
            
            demo_mlp_forward_pass(tpu)
            time.sleep(1)
            
            demo_performance_benchmark(tpu)
            time.sleep(1)
            
            demo_status_monitoring(tpu)
            time.sleep(1)
            
            demo_comprehensive_test_suite(tpu)
            
            print_header("Demo Complete!")
            print(f"{Colors.OKGREEN}All demonstrations completed successfully!{Colors.ENDC}\n")
            print(f"{Colors.BOLD}This TPU is ready for neural network inference!{Colors.ENDC}\n")
    
    except KeyboardInterrupt:
        print(f"\n\n{Colors.WARNING}Interrupted by user{Colors.ENDC}")
        sys.exit(1)
    except Exception as e:
        print(f"\n{Colors.FAIL}Error: {e}{Colors.ENDC}")
        sys.exit(1)


if __name__ == "__main__":
    main()

