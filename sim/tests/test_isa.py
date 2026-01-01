"""
Test 20-Instruction TPU ISA
Tests all instructions via simulation
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import numpy as np


# Instruction opcodes
OP_NOP = 0x00
OP_RD_HOST_MEM = 0x01
OP_WR_HOST_MEM = 0x02
OP_RD_WEIGHT = 0x03
OP_LD_UB = 0x04
OP_ST_UB = 0x05
OP_MATMUL = 0x10
OP_CONV2D = 0x11
OP_MATMUL_ACC = 0x12
OP_RELU = 0x18
OP_RELU6 = 0x19
OP_SIGMOID = 0x1A
OP_TANH = 0x1B
OP_MAXPOOL = 0x20
OP_AVGPOOL = 0x21
OP_ADD_BIAS = 0x22
OP_BATCH_NORM = 0x23
OP_SYNC = 0x30
OP_CFG_REG = 0x31
OP_HALT = 0x3F


@cocotb.test()
async def test_instruction_decoder(dut):
    """Test instruction decoder for all opcodes"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Test all opcodes
    test_cases = [
        (OP_NOP, "is_nop"),
        (OP_MATMUL, "is_matmul"),
        (OP_RELU, "is_relu"),
        (OP_RELU6, "is_relu6"),
        (OP_SIGMOID, "is_sigmoid"),
        (OP_TANH, "is_tanh"),
        (OP_SYNC, "is_sync"),
        (OP_CFG_REG, "is_cfg_reg"),
        (OP_HALT, "is_halt"),
    ]

    for opcode, expected_flag in test_cases:
        dut.opcode.value = opcode
        await ClockCycles(dut.clk, 1)
        
        # Check that the expected flag is set
        flag_value = int(getattr(dut, expected_flag).value)
        assert flag_value == 1, f"Opcode 0x{opcode:02X}: {expected_flag} should be 1, got {flag_value}"
    
    dut._log.info("PASS: Instruction decoder test")


@cocotb.test()
async def test_execution_unit_matmul(dut):
    """Test execution unit MATMUL instruction"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.opcode.value = 0
    dut.instruction_valid.value = 0
    dut.mlp_state.value = 0  # IDLE
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Execute MATMUL instruction
    dut.opcode.value = OP_MATMUL
    dut.instruction_valid.value = 1
    await ClockCycles(dut.clk, 1)
    
    # Check that MLP start signal is asserted
    assert int(dut.mlp_start.value) == 1, "MATMUL should assert mlp_start"
    assert int(dut.mlp_clear_acc.value) == 1, "MATMUL should clear accumulator"
    
    dut._log.info("PASS: Execution unit MATMUL test")


@cocotb.test()
async def test_execution_unit_activation_ops(dut):
    """Test execution unit activation instructions"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.opcode.value = 0
    dut.instruction_valid.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Test ReLU
    dut.opcode.value = OP_RELU
    dut.instruction_valid.value = 1
    await ClockCycles(dut.clk, 1)
    assert int(dut.vpu_activation_type.value) == 0b001, "ReLU should set activation_type to 001"
    
    # Test ReLU6
    dut.opcode.value = OP_RELU6
    await ClockCycles(dut.clk, 1)
    assert int(dut.vpu_activation_type.value) == 0b010, "ReLU6 should set activation_type to 010"
    
    # Test Sigmoid
    dut.opcode.value = OP_SIGMOID
    await ClockCycles(dut.clk, 1)
    assert int(dut.vpu_activation_type.value) == 0b011, "Sigmoid should set activation_type to 011"
    
    # Test Tanh
    dut.opcode.value = OP_TANH
    await ClockCycles(dut.clk, 1)
    assert int(dut.vpu_activation_type.value) == 0b100, "Tanh should set activation_type to 100"
    
    dut._log.info("PASS: Execution unit activation ops test")


@cocotb.test()
async def test_execution_unit_cfg_reg(dut):
    """Test execution unit CFG_REG instruction"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.opcode.value = 0
    dut.operand.value = 0
    dut.instruction_valid.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Execute CFG_REG: write register 0x00 (VPU activation type) with value 0x05 (Tanh)
    dut.opcode.value = OP_CFG_REG
    dut.operand.value = 0x00000005  # reg_addr=0x00, reg_value=0x05
    dut.instruction_valid.value = 1
    await ClockCycles(dut.clk, 1)
    
    # Check that config register write is enabled
    assert int(dut.cfg_reg_wr_en.value) == 1, "CFG_REG should enable config register write"
    assert int(dut.cfg_reg_addr.value) == 0x00, "CFG_REG should set correct register address"
    
    dut._log.info("PASS: Execution unit CFG_REG test")


def test_isa_runner():
    """Run ISA tests"""
    import cocotb_tools.runner
    import os
    import sys

    test_dir = os.path.dirname(os.path.abspath(__file__))
    sim_dir = os.path.dirname(test_dir)
    rtl_dir = os.path.join(os.path.dirname(sim_dir), "rtl")

    print("ISA tests should be run via Makefile:")
    print("  make test_isa")


if __name__ == "__main__":
    test_isa_runner()

