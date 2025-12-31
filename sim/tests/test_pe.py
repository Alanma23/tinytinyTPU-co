"""
Processing Element (PE) testbench for TinyTinyTPU.
Tests weight loading, MAC operation, and activation propagation.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_pe_reset(dut):
    """Test that reset initializes all outputs to zero"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Apply reset
    dut.reset.value = 1
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 0
    dut.in_act.value = 0
    dut.in_psum.value = 0

    await ClockCycles(dut.clk, 2)

    # Check outputs are zero
    assert dut.out_act.value == 0, f"out_act should be 0 after reset, got {dut.out_act.value}"
    assert dut.out_psum.value == 0, f"out_psum should be 0 after reset, got {dut.out_psum.value}"

    dut._log.info("PASS: Reset test")


@cocotb.test()
async def test_pe_weight_passthrough(dut):
    """Test that psum passes through during weight loading mode"""
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

    # Enable weight pass mode
    dut.en_weight_pass.value = 1
    dut.en_weight_capture.value = 0  # Don't capture yet
    dut.in_psum.value = 42

    await ClockCycles(dut.clk, 2)

    # Check passthrough
    assert dut.out_psum.value == 42, f"Expected psum passthrough of 42, got {dut.out_psum.value}"
    assert dut.out_act.value == 0, f"out_act should be 0 during weight load, got {dut.out_act.value}"

    dut._log.info("PASS: Weight passthrough test")


@cocotb.test()
async def test_pe_weight_capture(dut):
    """Test that weight is captured when en_weight_capture is high"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Load weight = 5 via psum
    dut.en_weight_pass.value = 1
    dut.en_weight_capture.value = 1
    dut.in_act.value = 0
    dut.in_psum.value = 5

    await ClockCycles(dut.clk, 2)

    # Switch to compute mode: activation=2, psum_in=10
    # Expected: out_psum = 2 * 5 + 10 = 20
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 0
    dut.in_act.value = 2
    dut.in_psum.value = 10

    await ClockCycles(dut.clk, 2)

    assert dut.out_psum.value == 20, f"Expected MAC result 20, got {dut.out_psum.value}"
    dut._log.info("PASS: Weight capture and MAC test")


@cocotb.test()
async def test_pe_mac_operation(dut):
    """Test MAC operation: out_psum = in_act * weight + in_psum"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Load weight = 7
    dut.en_weight_pass.value = 1
    dut.en_weight_capture.value = 1
    dut.in_psum.value = 7
    await ClockCycles(dut.clk, 2)

    # Test case 1: 3 * 7 + 0 = 21
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 0
    dut.in_act.value = 3
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 2)

    assert dut.out_psum.value == 21, f"Expected 21, got {dut.out_psum.value}"

    # Test case 2: 4 * 7 + 100 = 128
    dut.in_act.value = 4
    dut.in_psum.value = 100
    await ClockCycles(dut.clk, 2)

    assert dut.out_psum.value == 128, f"Expected 128, got {dut.out_psum.value}"

    dut._log.info("PASS: MAC operation test")


@cocotb.test()
async def test_pe_activation_propagation(dut):
    """Test that activations propagate through the PE"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Load weight
    dut.en_weight_pass.value = 1
    dut.en_weight_capture.value = 1
    dut.in_psum.value = 1
    await ClockCycles(dut.clk, 2)

    # Compute mode with activation = 99
    dut.en_weight_pass.value = 0
    dut.en_weight_capture.value = 0
    dut.in_act.value = 99
    dut.in_psum.value = 0
    await ClockCycles(dut.clk, 2)

    assert dut.out_act.value == 99, f"Expected out_act=99, got {dut.out_act.value}"

    # Change activation
    dut.in_act.value = 42
    await ClockCycles(dut.clk, 2)

    assert dut.out_act.value == 42, f"Expected out_act=42, got {dut.out_act.value}"

    dut._log.info("PASS: Activation propagation test")


def test_pe_runner():
    """Run PE tests using cocotb_tools.runner with waveform support"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "pe")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, "pe.sv")],
        hdl_toplevel="pe",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="pe",
        test_module="tests.test_pe",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "pe.vcd"))
            print(f"Waveform saved to {wave_dir}/pe.vcd")


if __name__ == "__main__":
    test_pe_runner()
