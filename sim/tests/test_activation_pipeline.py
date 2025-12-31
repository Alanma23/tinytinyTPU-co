"""
Activation Pipeline testbench for TinyTinyTPU.
Tests the full pipeline: activation -> normalization -> quantization.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import os
import shutil


@cocotb.test()
async def test_pipeline_reset(dut):
    """Test activation_pipeline reset behavior"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.valid_in.value = 0
    dut.acc_in.value = 0
    dut.target_in.value = 0
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0

    await ClockCycles(dut.clk, 2)

    assert dut.valid_out.value == 0, "valid_out should be 0 after reset"
    assert dut.ub_data_out.value.signed_integer == 0, "ub_data_out should be 0 after reset"

    dut._log.info("PASS: Activation pipeline reset test")


@cocotb.test()
async def test_pipeline_passthrough(dut):
    """Test pipeline with passthrough config (no scaling, no clipping)"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Configure for passthrough
    dut.norm_gain.value = 256    # 1.0
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256  # 1.0
    dut.q_zero_point.value = 0
    dut.target_in.value = 0

    # Send value through pipeline
    dut.valid_in.value = 1
    dut.acc_in.value = 42
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    # Wait for pipeline latency (activation + normalizer + quantize = 3 stages)
    await ClockCycles(dut.clk, 5)

    result = dut.ub_data_out.value.signed_integer
    dut._log.info(f"Pipeline passthrough: input=42, output={result}")

    dut._log.info("PASS: Activation pipeline passthrough test")


@cocotb.test()
async def test_pipeline_relu_clipping(dut):
    """Test that ReLU clips negative values"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Configure for passthrough
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0
    dut.target_in.value = 0

    # Send negative value
    dut.valid_in.value = 1
    dut.acc_in.value = (-50) & 0xFFFFFFFF  # Negative in two's complement
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 5)

    result = dut.ub_data_out.value.signed_integer
    dut._log.info(f"Pipeline ReLU: input=-50, output={result}")
    assert result == 0, f"ReLU should clip -50 to 0, got {result}"

    dut._log.info("PASS: Activation pipeline ReLU clipping test")


@cocotb.test()
async def test_pipeline_quantization_saturation(dut):
    """Test that quantization saturates to int8 range"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Configure - will result in value > 127
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0
    dut.target_in.value = 0

    # Send large positive value
    dut.valid_in.value = 1
    dut.acc_in.value = 200  # Should saturate to 127
    await ClockCycles(dut.clk, 1)

    dut.valid_in.value = 0
    await ClockCycles(dut.clk, 5)

    result = dut.ub_data_out.value.signed_integer
    dut._log.info(f"Pipeline saturation: input=200, output={result}")
    assert result == 127, f"Should saturate to 127, got {result}"

    dut._log.info("PASS: Activation pipeline saturation test")


def test_activation_pipeline_runner():
    """Run activation_pipeline tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "activation_pipeline")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    runner = get_runner("verilator")
    runner.build(
        sources=[
            os.path.join(rtl_dir, "activation_func.sv"),
            os.path.join(rtl_dir, "normalizer.sv"),
            os.path.join(rtl_dir, "loss_block.sv"),
            os.path.join(rtl_dir, "activation_pipeline.sv"),
        ],
        hdl_toplevel="activation_pipeline",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNUSEDSIGNAL"]
    )
    runner.test(
        hdl_toplevel="activation_pipeline",
        test_module="tests.test_activation_pipeline",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "activation_pipeline.vcd"))
            print(f"Waveform saved to {wave_dir}/activation_pipeline.vcd")


if __name__ == "__main__":
    test_activation_pipeline_runner()
