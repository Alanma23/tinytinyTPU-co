"""
Weight FIFO testbench for TinyTinyTPU.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_weight_fifo_reset(dut):
    """Test weight_fifo reset behavior"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.push.value = 0
    dut.pop.value = 0
    dut.data_in.value = 0

    await ClockCycles(dut.clk, 2)

    assert dut.data_out.value == 0, f"data_out should be 0 after reset"

    dut._log.info("PASS: Weight FIFO reset test")


@cocotb.test()
async def test_weight_fifo_push_pop(dut):
    """Test basic push/pop operations"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst.value = 1
    dut.push.value = 0
    dut.pop.value = 0
    dut.data_in.value = 0

    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Push values 10, 20, 30, 40
    test_values = [10, 20, 30, 40]

    for val in test_values:
        dut.push.value = 1
        dut.data_in.value = val
        await RisingEdge(dut.clk)

    dut.push.value = 0
    dut.data_in.value = 0
    await RisingEdge(dut.clk)

    # Pop and verify
    # The FIFO has registered output: on pop edge, data_out gets buffer[rd_ptr]
    # Sample outputs on falling edge to ensure values have settled

    for i, expected in enumerate(test_values):
        # Set pop before the clock edge
        dut.pop.value = 1
        # Wait for the rising edge where pop is sampled
        await RisingEdge(dut.clk)
        # Wait for falling edge to let values settle
        await FallingEdge(dut.clk)
        # Now read data_out
        actual = int(dut.data_out.value)
        dut._log.info(f"Pop[{i}]: got {actual}, expected {expected}")
        assert actual == expected, f"Expected {expected}, got {actual}"

    dut.pop.value = 0
    await RisingEdge(dut.clk)

    dut._log.info("PASS: Weight FIFO push/pop test")


@cocotb.test()
async def test_weight_fifo_wraparound(dut):
    """Test pointer wraparound (FIFO is 4 deep)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.rst.value = 1
    dut.push.value = 0
    dut.pop.value = 0
    dut.data_in.value = 0

    await ClockCycles(dut.clk, 2)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Fill FIFO twice to test wraparound
    for iteration in range(2):
        dut._log.info(f"Iteration {iteration}: Pushing values")

        # Push 4 values
        for i in range(4):
            dut.push.value = 1
            dut.data_in.value = (iteration * 10) + i
            await RisingEdge(dut.clk)

        dut.push.value = 0
        dut.data_in.value = 0
        await RisingEdge(dut.clk)

        dut._log.info(f"Iteration {iteration}: Popping values")

        # Pop 4 values
        for i in range(4):
            dut.pop.value = 1
            await RisingEdge(dut.clk)
            await FallingEdge(dut.clk)  # Let values settle
            expected = (iteration * 10) + i
            actual = int(dut.data_out.value)
            dut._log.info(f"  Pop[{i}]: got {actual}, expected {expected}")
            assert actual == expected, f"Iteration {iteration}: Expected {expected}, got {actual}"

        dut.pop.value = 0
        await RisingEdge(dut.clk)

    dut._log.info("PASS: Weight FIFO wraparound test")


def test_weight_fifo_runner():
    """Run weight_fifo tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "weight_fifo")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, "weight_fifo.sv")],
        hdl_toplevel="weight_fifo",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="weight_fifo",
        test_module="tests.test_weight_fifo",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "weight_fifo.vcd"))
            print(f"Waveform saved to {wave_dir}/weight_fifo.vcd")


if __name__ == "__main__":
    test_weight_fifo_runner()
