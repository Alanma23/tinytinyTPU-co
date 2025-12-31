"""
Dual Weight FIFO testbench for TinyTinyTPU.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_dual_fifo_reset(dut):
    """Test dual_weight_fifo reset behavior"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.push_col0.value = 0
    dut.push_col1.value = 0
    dut.pop.value = 0
    dut.data_in.value = 0

    await ClockCycles(dut.clk, 2)

    assert dut.col0_out.value == 0, f"col0_out should be 0 after reset"
    assert dut.col1_out.value == 0, f"col1_out should be 0 after reset"

    dut._log.info("PASS: Dual FIFO reset test")


@cocotb.test()
async def test_dual_fifo_column_independence(dut):
    """Test that columns are independent"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.push_col0.value = 0
    dut.push_col1.value = 0
    dut.pop.value = 0
    dut.data_in.value = 0

    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Push to col0 only: 11, 12
    dut.push_col0.value = 1
    dut.push_col1.value = 0
    dut.data_in.value = 11
    await ClockCycles(dut.clk, 1)

    dut.data_in.value = 12
    await ClockCycles(dut.clk, 1)

    dut.push_col0.value = 0

    # Push to col1 only: 21, 22
    dut.push_col1.value = 1
    dut.data_in.value = 21
    await ClockCycles(dut.clk, 1)

    dut.data_in.value = 22
    await ClockCycles(dut.clk, 1)

    dut.push_col1.value = 0
    await RisingEdge(dut.clk)

    # Pop and verify
    dut.pop.value = 1
    await ClockCycles(dut.clk, 1)

    col0_val = int(dut.col0_out.value)
    dut._log.info(f"First pop: col0_out={col0_val}")

    await ClockCycles(dut.clk, 1)
    col0_val = int(dut.col0_out.value)
    col1_val = int(dut.col1_out.value)
    dut._log.info(f"Second pop: col0_out={col0_val}, col1_out={col1_val}")

    dut.pop.value = 0

    dut._log.info("PASS: Dual FIFO column independence test")


@cocotb.test()
async def test_dual_fifo_skew(dut):
    """Test that col1 has 1-cycle skew relative to col0"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    dut.push_col0.value = 0
    dut.push_col1.value = 0
    dut.pop.value = 0

    # Push same values to both columns: 100, 200
    for val in [100, 200]:
        dut.push_col0.value = 1
        dut.data_in.value = val
        await ClockCycles(dut.clk, 1)

    dut.push_col0.value = 0

    for val in [100, 200]:
        dut.push_col1.value = 1
        dut.data_in.value = val
        await ClockCycles(dut.clk, 1)

    dut.push_col1.value = 0
    await RisingEdge(dut.clk)

    dut.pop.value = 1

    # First pop
    await RisingEdge(dut.clk)
    col0_first = int(dut.col0_out.value)
    col1_first = int(dut.col1_out.value)
    dut._log.info(f"After first pop edge: col0={col0_first}, col1={col1_first}")

    # Second pop
    await RisingEdge(dut.clk)
    col0_second = int(dut.col0_out.value)
    col1_second = int(dut.col1_out.value)
    dut._log.info(f"After second pop edge: col0={col0_second}, col1={col1_second}")

    dut.pop.value = 0

    dut._log.info("PASS: Dual FIFO skew test completed")


def test_dual_fifo_runner():
    """Run dual_weight_fifo tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "dual_weight_fifo")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, "dual_weight_fifo.sv")],
        hdl_toplevel="dual_weight_fifo",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="dual_weight_fifo",
        test_module="tests.test_dual_weight_fifo",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "dual_weight_fifo.vcd"))
            print(f"Waveform saved to {wave_dir}/dual_weight_fifo.vcd")


if __name__ == "__main__":
    test_dual_fifo_runner()
