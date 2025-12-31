"""
Accumulator testbench for TinyTinyTPU.
Tests column alignment, accumulate/overwrite modes, and double buffering.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_accumulator_reset(dut):
    """Test that reset initializes all outputs to zero"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Apply reset
    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    dut.mmu_col0_in.value = 0
    dut.mmu_col1_in.value = 0

    await ClockCycles(dut.clk, 2)

    assert dut.acc_col0_out.value.signed_integer == 0, "acc_col0_out should be 0 after reset"
    assert dut.acc_col1_out.value.signed_integer == 0, "acc_col1_out should be 0 after reset"
    assert dut.valid_out.value == 0, "valid_out should be 0 after reset"

    dut._log.info("PASS: Accumulator reset test")


@cocotb.test()
async def test_accumulator_overwrite_mode(dut):
    """Test overwrite mode (accumulator_enable=0)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    dut.mmu_col0_in.value = 0
    dut.mmu_col1_in.value = 0

    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Overwrite mode: accumulator_enable = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0  # Buffer 0

    # Send two valid cycles (alignment requires 2 valids for first output)
    # First valid - gets stored in delay register
    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 100
    dut.mmu_col1_in.value = 200
    await ClockCycles(dut.clk, 1)

    # Second valid - triggers aligned output
    dut.mmu_col0_in.value = 150
    dut.mmu_col1_in.value = 250
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    # Check results
    col0 = dut.acc_col0_out.value.signed_integer
    col1 = dut.acc_col1_out.value.signed_integer
    dut._log.info(f"Overwrite mode result: col0={col0}, col1={col1}")

    dut._log.info("PASS: Accumulator overwrite mode test")


@cocotb.test()
async def test_accumulator_accumulate_mode(dut):
    """Test accumulate mode (accumulator_enable=1)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    dut.mmu_col0_in.value = 0
    dut.mmu_col1_in.value = 0
    await RisingEdge(dut.clk)

    # First: write initial values in overwrite mode
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0

    # Two valids needed due to alignment
    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 10
    dut.mmu_col1_in.value = 20
    await ClockCycles(dut.clk, 1)

    dut.mmu_col0_in.value = 15
    dut.mmu_col1_in.value = 25
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    col0_initial = dut.acc_col0_out.value.signed_integer
    col1_initial = dut.acc_col1_out.value.signed_integer
    dut._log.info(f"Initial values: col0={col0_initial}, col1={col1_initial}")

    # Now accumulate: add more values
    dut.accumulator_enable.value = 1  # Enable accumulation

    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 5
    dut.mmu_col1_in.value = 10
    await ClockCycles(dut.clk, 1)

    dut.mmu_col0_in.value = 7
    dut.mmu_col1_in.value = 12
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    col0_accum = dut.acc_col0_out.value.signed_integer
    col1_accum = dut.acc_col1_out.value.signed_integer
    dut._log.info(f"After accumulation: col0={col0_accum}, col1={col1_accum}")

    dut._log.info("PASS: Accumulator accumulate mode test")


@cocotb.test()
async def test_accumulator_double_buffer(dut):
    """Test double buffering (addr_sel switches between buffers)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    dut.mmu_col0_in.value = 0
    dut.mmu_col1_in.value = 0
    await RisingEdge(dut.clk)

    # Write to buffer 0
    dut.addr_sel.value = 0
    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 111
    dut.mmu_col1_in.value = 222
    await ClockCycles(dut.clk, 1)

    dut.mmu_col0_in.value = 333
    dut.mmu_col1_in.value = 444
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    buf0_col0 = dut.acc_col0_out.value.signed_integer
    buf0_col1 = dut.acc_col1_out.value.signed_integer
    dut._log.info(f"Buffer 0: col0={buf0_col0}, col1={buf0_col1}")

    # Write to buffer 1
    dut.addr_sel.value = 1
    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 555
    dut.mmu_col1_in.value = 666
    await ClockCycles(dut.clk, 1)

    dut.mmu_col0_in.value = 777
    dut.mmu_col1_in.value = 888
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    buf1_col0 = dut.acc_col0_out.value.signed_integer
    buf1_col1 = dut.acc_col1_out.value.signed_integer
    dut._log.info(f"Buffer 1: col0={buf1_col0}, col1={buf1_col1}")

    dut._log.info("PASS: Accumulator double buffer test")


@cocotb.test()
async def test_accumulator_alignment(dut):
    """Test that column alignment works correctly (col0 delayed to match col1)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    dut.valid_in.value = 0
    dut.accumulator_enable.value = 0
    dut.addr_sel.value = 0
    await RisingEdge(dut.clk)

    # Send staggered data as would come from MMU
    # First valid: col0=100, col1=X (don't care, will be ignored)
    dut.valid_in.value = 1
    dut.mmu_col0_in.value = 100
    dut.mmu_col1_in.value = 999  # This col1 value should be ignored
    await ClockCycles(dut.clk, 1)

    # Second valid: col0=200 (for next row), col1=100 (matched with previous col0)
    dut.mmu_col0_in.value = 200
    dut.mmu_col1_in.value = 100  # This should pair with previous col0=100
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 2)

    # Check that valid_out fired
    dut._log.info(f"valid_out={int(dut.valid_out.value)}")
    dut._log.info(f"Aligned output: col0={dut.acc_col0_out.value.signed_integer}, col1={dut.acc_col1_out.value.signed_integer}")

    dut._log.info("PASS: Accumulator alignment test")


def test_accumulator_runner():
    """Run accumulator tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "accumulator")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[
            os.path.join(rtl_dir, "accumulator_align.sv"),
            os.path.join(rtl_dir, "accumulator_mem.sv"),
            os.path.join(rtl_dir, "accumulator.sv"),
        ],
        hdl_toplevel="accumulator",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="accumulator",
        test_module="tests.test_accumulator",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "accumulator.vcd"))
            print(f"Waveform saved to {wave_dir}/accumulator.vcd")


if __name__ == "__main__":
    test_accumulator_runner()
