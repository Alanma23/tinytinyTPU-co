"""
Test Vector Processing Unit (VPU)
Tests all activation functions: Passthrough, ReLU, ReLU6, Sigmoid, Tanh
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import numpy as np


# Activation type encodings
ACT_PASSTHROUGH = 0b000
ACT_RELU = 0b001
ACT_RELU6 = 0b010
ACT_SIGMOID = 0b011
ACT_TANH = 0b100


@cocotb.test()
async def test_vpu_passthrough(dut):
    """Test VPU passthrough mode"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.data_in0.value = 0
    dut.data_in1.value = 0
    dut.activation_type.value = ACT_PASSTHROUGH
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Test various values
    test_values = [0, 10, -10, 100, -100, 1000, -1000]
    
    for val in test_values:
        dut.data_in0.value = val
        dut.data_in1.value = -val
        dut.valid_in.value = 1
        await ClockCycles(dut.clk, 2)  # Allow pipeline
        
        result0 = int(dut.data_out0.value.signed_integer)
        result1 = int(dut.data_out1.value.signed_integer)
        
        assert result0 == val, f"Passthrough col0: expected {val}, got {result0}"
        assert result1 == -val, f"Passthrough col1: expected {-val}, got {result1}"
        assert int(dut.valid_out.value) == 1, "Valid out should be high"
    
    dut._log.info("PASS: VPU passthrough test")


@cocotb.test()
async def test_vpu_relu(dut):
    """Test VPU ReLU activation"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.activation_type.value = ACT_RELU
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    test_cases = [
        (10, 10),      # Positive -> unchanged
        (-10, 0),      # Negative -> 0
        (0, 0),        # Zero -> 0
        (100, 100),    # Large positive -> unchanged
        (-100, 0),     # Large negative -> 0
    ]
    
    for input_val, expected in test_cases:
        dut.data_in0.value = input_val
        dut.data_in1.value = input_val
        dut.valid_in.value = 1
        await ClockCycles(dut.clk, 2)
        
        result0 = int(dut.data_out0.value.signed_integer)
        result1 = int(dut.data_out1.value.signed_integer)
        
        assert result0 == expected, f"ReLU col0: input {input_val}, expected {expected}, got {result0}"
        assert result1 == expected, f"ReLU col1: input {input_val}, expected {expected}, got {result1}"
    
    dut._log.info("PASS: VPU ReLU test")


@cocotb.test()
async def test_vpu_relu6(dut):
    """Test VPU ReLU6 activation"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.activation_type.value = ACT_RELU6
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    test_cases = [
        (-10, 0),      # Negative -> 0
        (0, 0),        # Zero -> 0
        (3, 3),        # Small positive -> unchanged
        (6, 6),        # Exactly 6 -> 6
        (10, 6),       # Large positive -> clamped to 6
        (100, 6),      # Very large -> clamped to 6
    ]
    
    for input_val, expected in test_cases:
        dut.data_in0.value = input_val
        dut.data_in1.value = input_val
        dut.valid_in.value = 1
        await ClockCycles(dut.clk, 2)
        
        result0 = int(dut.data_out0.value.signed_integer)
        result1 = int(dut.data_out1.value.signed_integer)
        
        assert result0 == expected, f"ReLU6 col0: input {input_val}, expected {expected}, got {result0}"
        assert result1 == expected, f"ReLU6 col1: input {input_val}, expected {expected}, got {result1}"
    
    dut._log.info("PASS: VPU ReLU6 test")


@cocotb.test()
async def test_vpu_sigmoid(dut):
    """Test VPU Sigmoid activation"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.activation_type.value = ACT_SIGMOID
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Sigmoid maps [-inf, +inf] to [0, 1]
    # Our implementation scales to [0, 256]
    test_cases = [
        (-10, 0),      # Very negative -> 0
        (0, 128),      # Zero -> 0.5 (scaled to 128)
        (2, 200),      # Positive -> close to 1 (approximate)
        (10, 255),     # Very positive -> 1 (scaled to 255)
    ]
    
    for input_val, expected_approx in test_cases:
        dut.data_in0.value = input_val
        dut.data_in1.value = input_val
        dut.valid_in.value = 1
        await ClockCycles(dut.clk, 2)
        
        result0 = int(dut.data_out0.value.signed_integer)
        result1 = int(dut.data_out1.value.signed_integer)
        
        # Allow some tolerance for approximation
        assert abs(result0 - expected_approx) < 20, \
            f"Sigmoid col0: input {input_val}, expected ≈{expected_approx}, got {result0}"
        assert abs(result1 - expected_approx) < 20, \
            f"Sigmoid col1: input {input_val}, expected ≈{expected_approx}, got {result1}"
        # Check range [0, 255]
        assert 0 <= result0 <= 255, f"Sigmoid col0 out of range: {result0}"
        assert 0 <= result1 <= 255, f"Sigmoid col1 out of range: {result1}"
    
    dut._log.info("PASS: VPU Sigmoid test")


@cocotb.test()
async def test_vpu_tanh(dut):
    """Test VPU Tanh activation"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.activation_type.value = ACT_TANH
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Tanh maps [-inf, +inf] to [-1, 1]
    # Our implementation scales to [-128, 128]
    test_cases = [
        (-10, -128),   # Very negative -> -1 (scaled to -128)
        (0, 0),        # Zero -> 0
        (2, 100),      # Positive -> close to 1 (approximate)
        (10, 128),     # Very positive -> 1 (scaled to 128)
    ]
    
    for input_val, expected_approx in test_cases:
        dut.data_in0.value = input_val
        dut.data_in1.value = input_val
        dut.valid_in.value = 1
        await ClockCycles(dut.clk, 2)
        
        result0 = int(dut.data_out0.value.signed_integer)
        result1 = int(dut.data_out1.value.signed_integer)
        
        # Allow tolerance for approximation
        assert abs(result0 - expected_approx) < 20, \
            f"Tanh col0: input {input_val}, expected ≈{expected_approx}, got {result0}"
        assert abs(result1 - expected_approx) < 20, \
            f"Tanh col1: input {input_val}, expected ≈{expected_approx}, got {result1}"
        # Check range [-128, 128]
        assert -128 <= result0 <= 128, f"Tanh col0 out of range: {result0}"
        assert -128 <= result1 <= 128, f"Tanh col1 out of range: {result1}"
    
    dut._log.info("PASS: VPU Tanh test")


@cocotb.test()
async def test_vpu_pipeline_latency(dut):
    """Test VPU pipeline latency"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.activation_type.value = ACT_RELU
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Check that valid_out appears 2 cycles after valid_in
    dut.data_in0.value = 10
    dut.data_in1.value = 20
    dut.valid_in.value = 1
    
    # Cycle 0: input registered
    await RisingEdge(dut.clk)
    assert int(dut.valid_out.value) == 0, "Valid out should be low on first cycle"
    
    # Cycle 1: output should appear
    await RisingEdge(dut.clk)
    assert int(dut.valid_out.value) == 1, "Valid out should be high on second cycle"
    
    result0 = int(dut.data_out0.value.signed_integer)
    result1 = int(dut.data_out1.value.signed_integer)
    assert result0 == 10, f"Pipeline latency test: expected 10, got {result0}"
    assert result1 == 20, f"Pipeline latency test: expected 20, got {result1}"
    
    dut._log.info("PASS: VPU pipeline latency test")


def test_vpu_runner():
    """Run VPU tests"""
    import cocotb_tools.runner
    import os
    import sys

    test_dir = os.path.dirname(os.path.abspath(__file__))
    sim_dir = os.path.dirname(test_dir)
    rtl_dir = os.path.join(os.path.dirname(sim_dir), "rtl")

    print("VPU tests should be run via Makefile:")
    print("  make test_vpu")


if __name__ == "__main__":
    test_vpu_runner()

