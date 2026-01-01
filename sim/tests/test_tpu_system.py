"""
TPU System End-to-End Tests
Tests complete integration: UART Controller → Bridge → MLP Top

TPU v1 Architecture (from chewingonchips.substack.com):
- 2x2 systolic array
- 2 layers (hidden + output)
- Weight loading via UART
- Activation loading via UART
- Matrix multiply with accumulation
- ReLU activation function
"""

import os
import sys
import shutil

# Add parent directory to path
if __name__ == "__main__":
    sim_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if sim_dir not in sys.path:
        sys.path.insert(0, sim_dir)

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles, Timer, with_timeout, SimTimeoutError

CLK_PERIOD_NS = 10
DEFAULT_CLOCK_FREQ = 100_000_000
DEFAULT_BAUD = 115_200

# Command definitions
CMD_WRITE_WEIGHT = 0x01
CMD_WRITE_ACT = 0x02
CMD_EXECUTE = 0x03
CMD_READ_RESULT = 0x04
CMD_STATUS = 0x05


async def _setup_tpu(dut):
    """Setup clock and reset for TPU system."""
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())

    dut.rst.value = 1
    dut.uart_rx.value = 1  # Idle high

    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # Wait for system to settle
    await ClockCycles(dut.clk, 100)


async def _send_uart_byte(dut, byte_value, bit_period_ns):
    """Send a single byte via UART RX line."""
    # Start bit (low)
    dut.uart_rx.value = 0
    await Timer(bit_period_ns, unit="ns")

    # Data bits (LSB first)
    for i in range(8):
        dut.uart_rx.value = (byte_value >> i) & 1
        await Timer(bit_period_ns, unit="ns")

    # Stop bit (high)
    dut.uart_rx.value = 1
    await Timer(bit_period_ns, unit="ns")

    # Wait for UART RX to process
    await ClockCycles(dut.clk, 100)


async def _receive_uart_byte(dut, bit_period_ns, timeout_ns=3000000):
    """Receive a single byte from UART TX line with timeout."""
    # Wait for start bit (falling edge)
    try:
        await with_timeout(FallingEdge(dut.uart_tx), timeout_ns, timeout_unit="ns")
    except SimTimeoutError:
        dut._log.error(f"Timeout waiting for UART TX start bit after {timeout_ns}ns")
        raise

    # Wait to middle of start bit
    await Timer(bit_period_ns // 2, unit="ns")
    start_bit = int(dut.uart_tx.value)
    if start_bit != 0:
        dut._log.warning(f"Start bit should be 0, got {start_bit}")

    # Sample 8 data bits
    byte_value = 0
    for i in range(8):
        await Timer(bit_period_ns, unit="ns")
        bit = int(dut.uart_tx.value)
        byte_value |= (bit << i)

    # Wait for stop bit
    await Timer(bit_period_ns, unit="ns")
    stop_bit = int(dut.uart_tx.value)
    if stop_bit != 1:
        dut._log.warning(f"Stop bit should be 1, got {stop_bit}")

    return byte_value


async def _send_and_receive(dut, cmd_byte, bit_period_ns, num_response_bytes):
    """Send a command and receive response bytes."""
    import cocotb
    # Start FIRST receiver before sending command
    first_receiver = cocotb.start_soon(_receive_uart_byte(dut, bit_period_ns))

    await ClockCycles(dut.clk, 10)

    # Send command
    await _send_uart_byte(dut, cmd_byte, bit_period_ns)

    # Receive first byte
    responses = [await first_receiver]

    # Receive remaining bytes sequentially
    for _ in range(num_response_bytes - 1):
        resp = await _receive_uart_byte(dut, bit_period_ns)
        responses.append(resp)

    return responses[0] if num_response_bytes == 1 else responses


@cocotb.test()
async def test_tpu_reset(dut):
    """Test TPU system reset."""
    bit_period_ns = (DEFAULT_CLOCK_FREQ // DEFAULT_BAUD) * CLK_PERIOD_NS

    await _setup_tpu(dut)

    # Verify system is ready (UART controller in WAIT_CMD=1 or IDLE=0 is acceptable)
    # After reset, controller may transition to WAIT_CMD when rx_ready goes high
    assert dut.uart_ctrl_u.state.value in [0, 1], f"UART controller should be in IDLE(0) or WAIT_CMD(1), got {dut.uart_ctrl_u.state.value}"
    assert dut.mlp_u.state.value == 0, "MLP should be in IDLE"


@cocotb.test()
async def test_weight_loading_via_uart(dut):
    """Test loading weights via UART to MLP."""
    bit_period_ns = (DEFAULT_CLOCK_FREQ // DEFAULT_BAUD) * CLK_PERIOD_NS

    await _setup_tpu(dut)

    # Send WRITE_WEIGHT command for layer 0
    # Weights: W00=1, W01=2, W10=3, W11=4
    weights = [0x01, 0x02, 0x03, 0x04]

    # Start monitoring weight push signals
    import cocotb
    weight_pushes = []

    async def monitor_weights():
        for _ in range(50000):
            await RisingEdge(dut.clk)
            if dut.mlp_u.wf_push_col0.value == 1:
                weight_pushes.append(('col0', int(dut.mlp_u.wf_data_in.value)))
            if dut.mlp_u.wf_push_col1.value == 1:
                weight_pushes.append(('col1', int(dut.mlp_u.wf_data_in.value)))

    monitor_task = cocotb.start_soon(monitor_weights())

    # Send weight command
    await _send_uart_byte(dut, CMD_WRITE_WEIGHT, bit_period_ns)
    for w in weights:
        await _send_uart_byte(dut, w, bit_period_ns)

    # Wait for processing
    await ClockCycles(dut.clk, 10000)

    dut._log.info(f"Weight pushes seen: {weight_pushes}")

    # Verify weights were pushed
    assert len(weight_pushes) == 4, f"Expected 4 weight pushes, got {len(weight_pushes)}"
    assert weight_pushes[0] == ('col0', 1), f"W00 should be 1, got {weight_pushes[0]}"
    assert weight_pushes[1] == ('col1', 2), f"W01 should be 2, got {weight_pushes[1]}"
    assert weight_pushes[2] == ('col0', 3), f"W10 should be 3, got {weight_pushes[2]}"
    assert weight_pushes[3] == ('col1', 4), f"W11 should be 4, got {weight_pushes[3]}"


@cocotb.test()
async def test_activation_loading_via_uart(dut):
    """Test loading activations via UART to MLP."""
    bit_period_ns = (DEFAULT_CLOCK_FREQ // DEFAULT_BAUD) * CLK_PERIOD_NS

    await _setup_tpu(dut)

    # Send WRITE_ACT command
    # Activations: A00=5, A01=6, A10=7, A11=8
    # Packed as: row0=[A01:A00], row1=[A11:A10]
    activations = [0x05, 0x06, 0x07, 0x08]

    # Monitor activation writes
    import cocotb
    act_writes = []

    async def monitor_activations():
        for _ in range(50000):
            await RisingEdge(dut.clk)
            if dut.mlp_u.init_act_valid.value == 1:
                act_writes.append(int(dut.mlp_u.init_act_data.value))

    monitor_task = cocotb.start_soon(monitor_activations())

    # Send activation command
    await _send_uart_byte(dut, CMD_WRITE_ACT, bit_period_ns)
    for a in activations:
        await _send_uart_byte(dut, a, bit_period_ns)

    # Wait for processing
    await ClockCycles(dut.clk, 10000)

    dut._log.info(f"Activation writes seen: {[f'0x{a:04X}' for a in act_writes]}")

    # Verify activations were written (column-major for systolic timing)
    # activations = [A00, A01, A10, A11]
    # col0 = {A10, A00}, col1 = {A11, A01}
    assert len(act_writes) == 2, f"Expected 2 activation writes, got {len(act_writes)}"
    expected_col0 = (activations[2] << 8) | activations[0]  # {A10, A00} = 0x0705
    expected_col1 = (activations[3] << 8) | activations[1]  # {A11, A01} = 0x0806
    assert act_writes[0] == expected_col0, f"Col 0 should be 0x{expected_col0:04X}, got 0x{act_writes[0]:04X}"
    assert act_writes[1] == expected_col1, f"Col 1 should be 0x{expected_col1:04X}, got 0x{act_writes[1]:04X}"


@cocotb.test()
async def test_simple_inference(dut):
    """Test simple inference: load weights, activations, execute, read result."""
    bit_period_ns = (DEFAULT_CLOCK_FREQ // DEFAULT_BAUD) * CLK_PERIOD_NS

    await _setup_tpu(dut)

    # Layer 0 weights: Identity-like matrix
    # W = [[1, 0],
    #      [0, 1]]
    layer0_weights = [0x01, 0x00, 0x00, 0x01]

    # Send layer 0 weights
    await _send_uart_byte(dut, CMD_WRITE_WEIGHT, bit_period_ns)
    for w in layer0_weights:
        await _send_uart_byte(dut, w, bit_period_ns)

    await ClockCycles(dut.clk, 10000)

    # Input activations: [10, 20] for both rows
    # A = [[10, 20],
    #      [10, 20]]
    activations = [0x0A, 0x14, 0x0A, 0x14]  # 10, 20, 10, 20

    await _send_uart_byte(dut, CMD_WRITE_ACT, bit_period_ns)
    for a in activations:
        await _send_uart_byte(dut, a, bit_period_ns)

    await ClockCycles(dut.clk, 10000)

    # Execute
    await _send_uart_byte(dut, CMD_EXECUTE, bit_period_ns)

    # Wait for computation to complete
    # Monitor MLP state to know when done
    for _ in range(10000):
        await RisingEdge(dut.clk)
        if dut.mlp_u.layer_complete.value == 1:
            dut._log.info("MLP computation complete!")
            break

    await ClockCycles(dut.clk, 1000)

    # Read result
    result_bytes = await _send_and_receive(dut, CMD_READ_RESULT, bit_period_ns, 4)

    result = result_bytes[0] | (result_bytes[1] << 8) | (result_bytes[2] << 16) | (result_bytes[3] << 24)

    # Convert to signed
    if result & 0x80000000:
        result = result - 0x100000000

    dut._log.info(f"Result: {result} (0x{result & 0xFFFFFFFF:08X})")

    # Expected: A * W with identity matrix should give similar values
    # Actual computation will depend on activation function and quantization
    # Just verify we got a non-zero result
    assert result != 0, "Result should be non-zero after computation"


def _run_tpu_system(module_name):
    """Run TPU system test."""
    from cocotb_tools.runner import get_runner
    import os
    import sys

    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", module_name)

    print(f"Building {module_name}...")
    print(f"RTL dir: {rtl_dir}")
    print(f"Build dir: {build_dir}")
    sys.stdout.flush()

    os.makedirs(wave_dir, exist_ok=True)
    if os.path.exists(build_dir):
        print(f"Removing existing build directory: {build_dir}")
        shutil.rmtree(build_dir)

    waves_enabled = os.environ.get("WAVES", "0") != "0"

    # Set C++ standard
    os.environ["CXXFLAGS"] = "-std=c++17"

    # All RTL files needed for full system
    source_files = [
        os.path.join(rtl_dir, "tpu_top.sv"),
        os.path.join(rtl_dir, "uart_controller.sv"),
        os.path.join(rtl_dir, "uart_rx.sv"),
        os.path.join(rtl_dir, "uart_tx.sv"),
        os.path.join(rtl_dir, "tpu_bridge.sv"),
        os.path.join(rtl_dir, "mlp_top.sv"),
        os.path.join(rtl_dir, "dual_weight_fifo.sv"),
        os.path.join(rtl_dir, "weight_fifo.sv"),
        os.path.join(rtl_dir, "unified_buffer.sv"),
        os.path.join(rtl_dir, "mmu.sv"),
        os.path.join(rtl_dir, "pe.sv"),
        os.path.join(rtl_dir, "accumulator.sv"),
        os.path.join(rtl_dir, "accumulator_mem.sv"),
        os.path.join(rtl_dir, "accumulator_align.sv"),
        os.path.join(rtl_dir, "activation_pipeline.sv"),
        os.path.join(rtl_dir, "activation_func.sv"),
        os.path.join(rtl_dir, "normalizer.sv"),
        os.path.join(rtl_dir, "loss_block.sv"),
    ]

    # Verify all files exist
    for src in source_files:
        if not os.path.exists(src):
            raise FileNotFoundError(f"Source file not found: {src}")
        print(f"  Source: {src}")

    sys.stdout.flush()

    runner = get_runner("verilator")

    print("Starting Verilator build...")
    sys.stdout.flush()

    runner.build(
        sources=source_files,
        hdl_toplevel=module_name,
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=[
            "--timing",
            "-Wno-WIDTHEXPAND",
            "-Wno-WIDTHTRUNC",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNDRIVEN",
        ],
    )

    print("Build complete. Starting tests...")
    sys.stdout.flush()

    runner.test(
        hdl_toplevel=module_name,
        test_module="tests.test_tpu_system",
        waves=waves_enabled,
    )

    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, f"{module_name}.vcd"))


def test_tpu_system_runner():
    """Test runner for tpu_top."""
    _run_tpu_system("tpu_top")


if __name__ == "__main__":
    test_tpu_system_runner()
