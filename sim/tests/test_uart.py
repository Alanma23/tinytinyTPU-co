"""
UART RX/TX and Controller tests for TinyTinyTPU.
Tests the minimal UART modules and command protocol.
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles, Timer
import os
import shutil


# UART timing helper
class UARTHelper:
    """Helper class for UART bit-banging in simulation."""

    def __init__(self, dut, clock_freq=100_000_000, baud_rate=115200):
        self.dut = dut
        self.clock_freq = clock_freq
        self.baud_rate = baud_rate
        self.clks_per_bit = clock_freq // baud_rate
        self.bit_time_ns = (1_000_000_000 // baud_rate)  # Bit time in ns

    async def send_byte(self, byte_val):
        """Send a byte via UART TX (bit-bang on rx pin)."""
        dut = self.dut

        # Start bit (low)
        dut.uart_rx_pin.value = 0
        await ClockCycles(dut.clk, self.clks_per_bit)

        # 8 data bits (LSB first)
        for i in range(8):
            bit = (byte_val >> i) & 1
            dut.uart_rx_pin.value = bit
            await ClockCycles(dut.clk, self.clks_per_bit)

        # Stop bit (high)
        dut.uart_rx_pin.value = 1
        await ClockCycles(dut.clk, self.clks_per_bit)

        # Extra idle time
        await ClockCycles(dut.clk, self.clks_per_bit // 2)

    async def receive_byte(self, timeout_cycles=20000):
        """Receive a byte from UART TX pin."""
        dut = self.dut

        # Wait for start bit (falling edge on tx pin)
        for _ in range(timeout_cycles):
            await RisingEdge(dut.clk)
            if dut.uart_tx_pin.value == 0:
                break
        else:
            raise TimeoutError("Timeout waiting for TX start bit")

        # Wait half bit to sample in middle
        await ClockCycles(dut.clk, self.clks_per_bit // 2)

        # Read 8 data bits
        byte_val = 0
        for i in range(8):
            await ClockCycles(dut.clk, self.clks_per_bit)
            bit = int(dut.uart_tx_pin.value)
            byte_val |= (bit << i)

        # Wait for stop bit
        await ClockCycles(dut.clk, self.clks_per_bit)
        assert dut.uart_tx_pin.value == 1, "Stop bit should be high"

        return byte_val

    async def send_command(self, cmd, data=None):
        """Send a command and optional data bytes."""
        await self.send_byte(cmd)
        if data:
            for b in data:
                await self.send_byte(b)


# ============================================================================
# UART Controller Tests
# ============================================================================

@cocotb.test()
async def test_uart_controller_status(dut):
    """Test status read command (0x04)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    uart = UARTHelper(dut)

    # Reset
    dut.rst.value = 1
    dut.uart_rx_pin.value = 1  # Idle high
    dut.state_in.value = 0
    dut.layer_complete.value = 0
    dut.acc0.value = 0
    dut.acc1.value = 0
    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    await ClockCycles(dut.clk, 10)

    # Set a known state
    dut.state_in.value = 0x05  # Some state value
    dut.layer_complete.value = 1

    # Send status command
    dut._log.info("Sending STATUS command (0x04)")
    await uart.send_byte(0x04)

    # Receive status byte
    status = await uart.receive_byte()
    dut._log.info(f"Received status: 0x{status:02X}")

    # Check: [4]=layer_complete, [3:0]=state
    expected = (1 << 4) | 0x05  # 0x15
    assert status == expected, f"Expected 0x{expected:02X}, got 0x{status:02X}"

    dut._log.info("PASS: Status command test")


@cocotb.test()
async def test_uart_controller_execute(dut):
    """Test execute command (0x03)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    uart = UARTHelper(dut)

    # Reset
    dut.rst.value = 1
    dut.uart_rx_pin.value = 1
    dut.state_in.value = 0
    dut.layer_complete.value = 0
    dut.acc0.value = 0
    dut.acc1.value = 0
    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    await ClockCycles(dut.clk, 10)

    # Send execute command
    dut._log.info("Sending EXECUTE command (0x03)")
    await uart.send_byte(0x03)

    # Wait a bit and check start_mlp pulsed
    start_seen = False
    for _ in range(100):
        await RisingEdge(dut.clk)
        if dut.start_mlp.value == 1:
            start_seen = True
            dut._log.info("start_mlp pulse detected")
            break

    assert start_seen, "start_mlp should pulse on EXECUTE command"

    # Receive ACK
    ack = await uart.receive_byte()
    assert ack == 0xAA, f"Expected ACK 0xAA, got 0x{ack:02X}"

    dut._log.info("PASS: Execute command test")


@cocotb.test()
async def test_uart_controller_write_weights(dut):
    """Test write weights command (0x01)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    uart = UARTHelper(dut)

    # Reset
    dut.rst.value = 1
    dut.uart_rx_pin.value = 1
    dut.state_in.value = 0
    dut.layer_complete.value = 0
    dut.acc0.value = 0
    dut.acc1.value = 0
    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    await ClockCycles(dut.clk, 10)

    # Send write weights command with 4 bytes
    dut._log.info("Sending WRITE_WEIGHTS command (0x01) with [0x03, 0x01, 0x04, 0x02]")
    weights = [0x03, 0x01, 0x04, 0x02]  # W10, W00, W11, W01

    await uart.send_byte(0x01)

    # Track FIFO pushes
    col0_pushes = []
    col1_pushes = []

    for w in weights:
        await uart.send_byte(w)
        # Wait a cycle to see push
        await RisingEdge(dut.clk)
        if dut.wf_push_col0.value:
            col0_pushes.append(int(dut.wf_data_in.value))
        if dut.wf_push_col1.value:
            col1_pushes.append(int(dut.wf_data_in.value))

    dut._log.info(f"Col0 pushes: {col0_pushes}")
    dut._log.info(f"Col1 pushes: {col1_pushes}")

    # Receive ACK
    ack = await uart.receive_byte()
    assert ack == 0xAA, f"Expected ACK 0xAA, got 0x{ack:02X}"

    dut._log.info("PASS: Write weights command test")


@cocotb.test()
async def test_uart_controller_read_results(dut):
    """Test read results command (0x05)."""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    uart = UARTHelper(dut)

    # Reset
    dut.rst.value = 1
    dut.uart_rx_pin.value = 1
    dut.state_in.value = 0
    dut.layer_complete.value = 0
    await ClockCycles(dut.clk, 10)
    dut.rst.value = 0
    await ClockCycles(dut.clk, 10)

    # Set known accumulator values
    test_acc0 = 0x12345678
    test_acc1 = 0xDEADBEEF
    dut.acc0.value = test_acc0
    dut.acc1.value = test_acc1

    # Send read results command
    dut._log.info(f"Sending READ_RESULTS command (0x05), expecting acc0=0x{test_acc0:08X}, acc1=0x{test_acc1:08X}")
    await uart.send_byte(0x05)

    # Receive 8 bytes (acc0 LSB first, then acc1 LSB first)
    received = []
    for i in range(8):
        byte_val = await uart.receive_byte()
        received.append(byte_val)
        dut._log.info(f"Received byte {i}: 0x{byte_val:02X}")

    # Reconstruct acc0 and acc1
    acc0_rx = received[0] | (received[1] << 8) | (received[2] << 16) | (received[3] << 24)
    acc1_rx = received[4] | (received[5] << 8) | (received[6] << 16) | (received[7] << 24)

    dut._log.info(f"Reconstructed acc0: 0x{acc0_rx:08X}")
    dut._log.info(f"Reconstructed acc1: 0x{acc1_rx:08X}")

    assert acc0_rx == test_acc0, f"acc0 mismatch: expected 0x{test_acc0:08X}, got 0x{acc0_rx:08X}"
    assert acc1_rx == test_acc1, f"acc1 mismatch: expected 0x{test_acc1:08X}, got 0x{acc1_rx:08X}"

    dut._log.info("PASS: Read results command test")


# ============================================================================
# Test Runner
# ============================================================================

def test_uart_runner():
    """Run UART controller tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner

    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "uart_controller")

    os.makedirs(wave_dir, exist_ok=True)

    # Clean existing build
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)

    waves_enabled = os.environ.get("WAVES", "0") != "0"

    rtl_sources = [
        os.path.join(rtl_dir, "uart_rx.sv"),
        os.path.join(rtl_dir, "uart_tx.sv"),
        os.path.join(rtl_dir, "uart_controller.sv"),
    ]

    runner = get_runner("verilator")
    runner.build(
        sources=rtl_sources,
        hdl_toplevel="uart_controller",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                    "-Wno-PINCONNECTEMPTY", "-Wno-UNUSEDSIGNAL",
                    "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC"]
    )
    runner.test(
        hdl_toplevel="uart_controller",
        test_module="tests.test_uart",
        waves=waves_enabled
    )

    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "uart_controller.vcd"))
            print(f"Waveform saved to {wave_dir}/uart_controller.vcd")


if __name__ == "__main__":
    test_uart_runner()

