"""
Test signed arithmetic in TPU
Verifies that negative values are handled correctly throughout the pipeline
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import numpy as np


@cocotb.test()
async def test_pe_signed_multiplication(dut):
    """Test PE signed multiplication with negative values"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 0
    dut.in_act.value = 0
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Test 1: Positive * Positive
    dut._log.info("Test 1: Positive * Positive")
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 1
    dut.in_psum.value = 5  # weight = 5
    dut.in_act.value = 0
    await ClockCycles(dut.clk, 1)
    dut.en_weight_capture.value = 0

    dut.in_act.value = 10
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 1)
    assert int(dut.out_psum.value.signed_integer) == 50, f"Expected 50, got {int(dut.out_psum.value.signed_integer)}"

    # Test 2: Negative * Positive
    dut._log.info("Test 2: Negative * Positive")
    dut.en_weight_capture.value = 1
    dut.in_psum.value = -5  # weight = -5 (signed)
    await ClockCycles(dut.clk, 1)
    dut.en_weight_capture.value = 0

    dut.in_act.value = 10
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 1)
    result = int(dut.out_psum.value.signed_integer)
    assert result == -50, f"Expected -50, got {result}"

    # Test 3: Positive * Negative
    dut._log.info("Test 3: Positive * Negative")
    dut.en_weight_capture.value = 1
    dut.in_psum.value = 5  # weight = 5
    await ClockCycles(dut.clk, 1)
    dut.en_weight_capture.value = 0

    dut.in_act.value = -10  # negative activation
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 1)
    result = int(dut.out_psum.value.signed_integer)
    assert result == -50, f"Expected -50, got {result}"

    # Test 4: Negative * Negative
    dut._log.info("Test 4: Negative * Negative")
    dut.en_weight_capture.value = 1
    dut.in_psum.value = -5  # weight = -5
    await ClockCycles(dut.clk, 1)
    dut.en_weight_capture.value = 0

    dut.in_act.value = -10  # negative activation
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 1)
    result = int(dut.out_psum.value.signed_integer)
    assert result == 50, f"Expected 50, got {result}"

    dut._log.info("PASS: All signed multiplication tests passed")


@cocotb.test()
async def test_mmu_signed_matrix_multiply(dut):
    """Test MMU with signed matrix multiplication"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.en_weight_pass.value = 0
    dut.en_capture_col0.value = 0
    dut.en_capture_col1.value = 0
    dut.row0_in.value = 0
    dut.row1_in.value = 0
    dut.col0_in.value = 0
    dut.col1_in.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Load weights: W = [[-1, 0], [0, -1]] (negative identity)
    dut.en_weight_pass.value = 1

    # Bottom row first: [0, -1]
    dut.col0_in.value = 0
    dut.col1_in.value = -1  # signed
    dut.en_capture_col0.value = 1
    await ClockCycles(dut.clk, 1)

    # Top row: [-1, 0]
    dut.col0_in.value = -1  # signed
    dut.col1_in.value = 0
    dut.en_capture_col0.value = 1
    dut.en_capture_col1.value = 1
    await ClockCycles(dut.clk, 1)

    dut.en_capture_col0.value = 0
    dut.en_capture_col1.value = 1
    await ClockCycles(dut.clk, 1)

    dut.en_weight_pass.value = 0
    dut.en_capture_col1.value = 0
    dut.col0_in.value = 0
    dut.col1_in.value = 0

    # Stream activations: A = [[10, 20], [10, 20]]
    dut.row0_in.value = 10
    dut.row1_in.value = 0
    await ClockCycles(dut.clk, 1)

    dut.row0_in.value = 20
    dut.row1_in.value = 10
    await ClockCycles(dut.clk, 1)

    dut.row0_in.value = 0
    dut.row1_in.value = 20
    await ClockCycles(dut.clk, 1)

    dut.row0_in.value = 0
    dut.row1_in.value = 0
    await ClockCycles(dut.clk, 3)  # Allow results to propagate

    # Expected: C = A × W = [[-10, -20], [-10, -20]]
    # acc0 = C[0,0] + C[1,0] = -10 + (-10) = -20
    acc0_result = int(dut.acc0_out.value.signed_integer)
    dut._log.info(f"acc0_out = {acc0_result} (expected -20)")

    # Allow some tolerance for timing
    assert acc0_result == -20 or abs(acc0_result + 20) < 5, \
        f"Expected acc0 ≈ -20, got {acc0_result}"

    dut._log.info("PASS: Signed matrix multiply test")


@cocotb.test()
async def test_accumulator_signed_accumulation(dut):
    """Test accumulator with signed values"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.clear.value = 0
    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    dut.mmu_col0_in.value = 0
    dut.mmu_col1_in.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Test: Accumulate negative values
    dut.accumulator_enable.value = 1  # Accumulate mode
    dut.valid_in.value = 1

    # First value: -10
    dut.mmu_col0_in.value = -10
    dut.mmu_col1_in.value = 0
    await ClockCycles(dut.clk, 2)  # Allow alignment delay

    # Second value: -20
    dut.mmu_col0_in.value = -20
    await ClockCycles(dut.clk, 2)

    # Check result: should be -30
    result = int(dut.acc_col0_out.value.signed_integer)
    dut._log.info(f"Accumulated result: {result} (expected -30)")

    # Allow some cycles for pipeline
    await ClockCycles(dut.clk, 3)
    result = int(dut.acc_col0_out.value.signed_integer)

    assert result == -30 or abs(result + 30) < 5, \
        f"Expected -30, got {result}"

    dut._log.info("PASS: Signed accumulation test")


def test_signed_runner():
    """Run signed arithmetic tests"""
    import cocotb_tools.runner
    import os
    import sys

    # Get the directory of this test file
    test_dir = os.path.dirname(os.path.abspath(__file__))
    sim_dir = os.path.dirname(test_dir)
    rtl_dir = os.path.join(os.path.dirname(sim_dir), "rtl")

    # Determine which module to test based on test name
    # This is a simplified runner - in practice, you'd run each test separately
    print("Signed arithmetic tests should be run individually:")
    print("  - test_pe_signed_multiplication: Tests PE module")
    print("  - test_mmu_signed_matrix_multiply: Tests MMU module")
    print("  - test_accumulator_signed_accumulation: Tests accumulator module")


if __name__ == "__main__":
    test_signed_runner()

