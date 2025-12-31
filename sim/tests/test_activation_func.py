"""
Activation Function testbench for TinyTinyTPU.
Tests passthrough, ReLU, and ReLU6 modes.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


def to_signed32(val):
    """Convert to signed 32-bit representation"""
    if val >= 2**31:
        return val - 2**32
    return val


@cocotb.test()
async def test_activation_relu_positive(dut):
    """Test ReLU with positive input (should pass through)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.data_in.value = 0
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Apply positive input
    dut.valid_in.value = 1
    dut.data_in.value = 42
    await ClockCycles(dut.clk, 2)

    result = to_signed32(int(dut.data_out.value))
    assert result == 42, f"Expected 42, got {result}"
    assert dut.valid_out.value == 1, "valid_out should be high"

    dut._log.info("PASS: ReLU positive test")


@cocotb.test()
async def test_activation_relu_negative(dut):
    """Test ReLU with negative input (should clamp to 0)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Apply negative input (-10 in two's complement)
    dut.valid_in.value = 1
    dut.data_in.value = (2**32 - 10) & 0xFFFFFFFF  # -10 as unsigned
    await ClockCycles(dut.clk, 2)

    result = to_signed32(int(dut.data_out.value))
    assert result == 0, f"Expected 0 for ReLU(-10), got {result}"

    dut._log.info("PASS: ReLU negative test")


@cocotb.test()
async def test_activation_relu_zero(dut):
    """Test ReLU with zero input"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Apply zero
    dut.valid_in.value = 1
    dut.data_in.value = 0
    await ClockCycles(dut.clk, 2)

    result = to_signed32(int(dut.data_out.value))
    assert result == 0, f"Expected 0, got {result}"

    dut._log.info("PASS: ReLU zero test")


@cocotb.test()
async def test_activation_valid_propagation(dut):
    """Test that valid signal propagates correctly"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Valid low
    dut.valid_in.value = 0
    dut.data_in.value = 100
    await ClockCycles(dut.clk, 2)

    assert dut.valid_out.value == 0, "valid_out should be low when valid_in is low"

    # Valid high
    dut.valid_in.value = 1
    await ClockCycles(dut.clk, 2)

    assert dut.valid_out.value == 1, "valid_out should be high when valid_in is high"

    dut._log.info("PASS: Valid propagation test")


def test_activation_func_runner():
    """Run activation_func tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner

    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "activation_func")

    os.makedirs(wave_dir, exist_ok=True)

    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)

    waves_enabled = os.environ.get("WAVES", "0") != "0"

    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, "activation_func.sv")],
        hdl_toplevel="activation_func",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="activation_func",
        test_module="tests.test_activation_func",
        waves=waves_enabled
    )

    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "activation_func.vcd"))
            print(f"Waveform saved to {wave_dir}/activation_func.vcd")


if __name__ == "__main__":
    test_activation_func_runner()


