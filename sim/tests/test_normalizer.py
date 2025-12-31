"""
Normalizer testbench for TinyTinyTPU.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_normalizer_passthrough(dut):
    """Test normalizer with gain=256, shift=8 (effectively multiply by 1)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Set gain=256 (1.0 in Q8), shift=8, bias=0
    dut.valid_in.value = 1
    dut.data_in.value = 100
    dut.gain.value = 256  # 1.0 in Q8.8
    dut.bias.value = 0
    dut.shift.value = 8

    await ClockCycles(dut.clk, 2)

    result = dut.data_out.value.signed_integer
    dut._log.info(f"Normalizer passthrough: input=100, output={result}")
    assert result == 100, f"Expected 100, got {result}"

    dut._log.info("PASS: Normalizer passthrough test")


@cocotb.test()
async def test_normalizer_with_bias(dut):
    """Test normalizer with bias"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Set gain=256, shift=8, bias=50
    dut.valid_in.value = 1
    dut.data_in.value = 100
    dut.gain.value = 256
    dut.bias.value = 50
    dut.shift.value = 8

    await ClockCycles(dut.clk, 2)

    result = dut.data_out.value.signed_integer
    expected = 100 + 50  # (100 * 256) >> 8 + 50 = 100 + 50 = 150
    dut._log.info(f"Normalizer with bias: input=100, bias=50, output={result}")
    assert result == expected, f"Expected {expected}, got {result}"

    dut._log.info("PASS: Normalizer with bias test")


@cocotb.test()
async def test_normalizer_scaling(dut):
    """Test normalizer with scaling (gain != 256)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Set gain=512 (2.0 in Q8), shift=8, bias=0
    dut.valid_in.value = 1
    dut.data_in.value = 50
    dut.gain.value = 512  # 2.0 in Q8.8
    dut.bias.value = 0
    dut.shift.value = 8

    await ClockCycles(dut.clk, 2)

    result = dut.data_out.value.signed_integer
    expected = 100  # (50 * 512) >> 8 = 100
    dut._log.info(f"Normalizer scaling: input=50, gain=2.0, output={result}")
    assert result == expected, f"Expected {expected}, got {result}"

    dut._log.info("PASS: Normalizer scaling test")


def test_normalizer_runner():
    """Run normalizer tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "normalizer")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, "normalizer.sv")],
        hdl_toplevel="normalizer",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="normalizer",
        test_module="tests.test_normalizer",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "normalizer.vcd"))
            print(f"Waveform saved to {wave_dir}/normalizer.vcd")


if __name__ == "__main__":
    test_normalizer_runner()
