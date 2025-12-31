"""
UART TX/RX cocotb regression for TinyTinyTPU.

Exercises the standalone uart_tx and uart_rx RTL blocks with a mix of
functional, timing, and error-condition scenarios.
"""
import os
import shutil

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import (
    RisingEdge,
    FallingEdge,
    ClockCycles,
    Timer,
    with_timeout,
    SimTimeoutError,
)


CLK_PERIOD_NS = 10
DEFAULT_CLOCK_FREQ = 100_000_000
DEFAULT_BAUD = 115_200


def _is_uart_tx(dut):
    return "uart_tx" in dut._name.lower()


def _is_uart_rx(dut):
    return "uart_rx" in dut._name.lower()


def _get_param(dut, name, default):
    handle = getattr(dut, name, None)
    if handle is None:
        return default
    try:
        return int(handle.value)
    except AttributeError:
        return int(handle)


def _get_bit_timing(dut):
    clock_freq = _get_param(dut, "CLOCK_FREQ", DEFAULT_CLOCK_FREQ)
    baud_rate = _get_param(dut, "BAUD_RATE", DEFAULT_BAUD)
    clks_per_bit = _get_param(dut, "CLKS_PER_BIT", clock_freq // baud_rate)
    bit_period_ns = clks_per_bit * CLK_PERIOD_NS
    return clks_per_bit, bit_period_ns


async def _setup_uart_tx(dut):
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())
    dut.rst.value = 1
    dut.tx_valid.value = 0
    dut.tx_data.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst.value = 0
    await RisingEdge(dut.clk)
    return _get_bit_timing(dut)


async def _setup_uart_rx(dut):
    clock = Clock(dut.clk, CLK_PERIOD_NS, unit="ns")
    cocotb.start_soon(clock.start())
    dut.rst.value = 1
    dut.rx.value = 1
    await ClockCycles(dut.clk, 5)
    dut.rst.value = 0
    await RisingEdge(dut.clk)
    return _get_bit_timing(dut)


async def _launch_tx_byte(dut, value):
    while not bool(dut.tx_ready.value):
        await RisingEdge(dut.clk)
    dut.tx_data.value = value
    dut.tx_valid.value = 1
    await RisingEdge(dut.clk)
    dut.tx_valid.value = 0


async def _capture_tx_frame(dut, bit_period_ns):
    await FallingEdge(dut.tx)  # Start bit
    samples = []
    await Timer(bit_period_ns // 2, unit="ns")
    samples.append(int(dut.tx.value))

    for _ in range(8):
        await Timer(bit_period_ns, unit="ns")
        samples.append(int(dut.tx.value))

    await Timer(bit_period_ns, unit="ns")
    samples.append(int(dut.tx.value))
    return samples


def _decode_frame(bits):
    data_bits = bits[1:9]
    value = 0
    for idx, bit in enumerate(data_bits):
        value |= (bit & 1) << idx
    return value


def _expected_frame(byte):
    return [0] + [((byte >> i) & 1) for i in range(8)] + [1]


async def _drive_uart_frame(dut, byte, clks_per_bit, stop_high=True):
    await ClockCycles(dut.clk, 1)
    dut.rx.value = 0  # Start bit
    await ClockCycles(dut.clk, clks_per_bit)
    for i in range(8):
        dut.rx.value = (byte >> i) & 1
        await ClockCycles(dut.clk, clks_per_bit)
    dut.rx.value = 1 if stop_high else 0
    await ClockCycles(dut.clk, clks_per_bit)
    dut.rx.value = 1


async def _drive_false_start(dut, clks_per_bit):
    await ClockCycles(dut.clk, clks_per_bit)
    dut.rx.value = 0
    glitch_cycles = max(1, clks_per_bit // 4)
    await ClockCycles(dut.clk, glitch_cycles)
    dut.rx.value = 1
    await ClockCycles(dut.clk, clks_per_bit)


@cocotb.test()
async def test_uart_tx_reset(dut):
    if not _is_uart_tx(dut):
        dut._log.info("Skipping TX-only test for %s", dut._name)
        return
    await _setup_uart_tx(dut)
    assert dut.tx.value == 1, "TX line should idle high after reset"
    assert dut.tx_ready.value == 1, "TX ready should be asserted when idle"


@cocotb.test()
async def test_uart_tx_single_byte(dut):
    if not _is_uart_tx(dut):
        dut._log.info("Skipping TX-only test for %s", dut._name)
        return
    _, bit_period_ns = await _setup_uart_tx(dut)
    await _launch_tx_byte(dut, 0x55)
    frame = await _capture_tx_frame(dut, bit_period_ns)
    assert frame == _expected_frame(0x55), f"Unexpected TX frame: {frame}"


@cocotb.test()
async def test_uart_tx_multiple_bytes(dut):
    if not _is_uart_tx(dut):
        dut._log.info("Skipping TX-only test for %s", dut._name)
        return
    _, bit_period_ns = await _setup_uart_tx(dut)
    pattern = [0x00, 0xFF, 0xA5, 0x5A]
    for byte in pattern:
        await _launch_tx_byte(dut, byte)
        frame = await _capture_tx_frame(dut, bit_period_ns)
        assert frame == _expected_frame(byte), f"Frame mismatch for byte {byte:#04x}"
        assert dut.tx_ready.value == 0, "tx_ready should stay low while busy"
        await Timer(bit_period_ns, unit="ns")  # allow stop bit to finish
        # ensure we sample stop bit completion
        await RisingEdge(dut.clk)
    assert dut.tx_ready.value == 1, "tx_ready should return high after final byte"


@cocotb.test()
async def test_uart_tx_edge_cases(dut):
    if not _is_uart_tx(dut):
        dut._log.info("Skipping TX-only test for %s", dut._name)
        return
    _, bit_period_ns = await _setup_uart_tx(dut)
    for byte in (0x00, 0xFF):
        await _launch_tx_byte(dut, byte)
        frame = await _capture_tx_frame(dut, bit_period_ns)
        assert frame == _expected_frame(byte), f"Edge-case frame mismatch for {byte:#04x}"


@cocotb.test()
async def test_uart_tx_timing(dut):
    if not _is_uart_tx(dut):
        dut._log.info("Skipping TX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_tx(dut)
    await _launch_tx_byte(dut, 0x02)
    await FallingEdge(dut.tx)
    for _ in range(clks_per_bit):
        await RisingEdge(dut.clk)
        assert dut.tx.value == 0, "Start bit should remain low for full bit period"
    await RisingEdge(dut.clk)
    assert dut.tx.value == 0, "First data bit (LSB) should be 0 for 0x02"
    await Timer(bit_period_ns * 9, unit="ns")
    assert dut.tx.value == 1, "Stop bit should idle high"


@cocotb.test()
async def test_uart_rx_reset(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    await _setup_uart_rx(dut)
    assert dut.rx_ready.value == 1, "RX ready should be high at idle"
    assert dut.rx_valid.value == 0, "RX valid must clear on reset"


@cocotb.test()
async def test_uart_rx_single_byte(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
    byte = 0x96
    driver = cocotb.start_soon(_drive_uart_frame(dut, byte, clks_per_bit))
    await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
    assert int(dut.rx_data.value) == byte, "RX data mismatch"
    await driver
    await RisingEdge(dut.clk)
    assert dut.rx_ready.value == 1, "RX should return to ready after byte"


@cocotb.test()
async def test_uart_rx_multiple_bytes(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
    pattern = [0x00, 0xFF, 0xA5, 0x5A]
    for byte in pattern:
        driver = cocotb.start_soon(_drive_uart_frame(dut, byte, clks_per_bit))
        await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
        assert int(dut.rx_data.value) == byte, f"RX byte mismatch for {byte:#04x}"
        await driver
        await RisingEdge(dut.clk)
    assert dut.rx_ready.value == 1, "RX ready should be high after burst"


@cocotb.test()
async def test_uart_rx_edge_cases(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
    for byte in (0x00, 0xFF):
        driver = cocotb.start_soon(_drive_uart_frame(dut, byte, clks_per_bit))
        await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
        assert int(dut.rx_data.value) == byte, f"RX edge byte mismatch {byte:#04x}"
        await driver
        await RisingEdge(dut.clk)


@cocotb.test()
async def test_uart_rx_false_start(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
    driver = cocotb.start_soon(_drive_false_start(dut, clks_per_bit))
    try:
        await with_timeout(RisingEdge(dut.rx_valid), 6 * bit_period_ns, timeout_unit="ns")
        assert False, "False start should not produce rx_valid"
    except SimTimeoutError:
        pass
    await driver
    assert dut.rx_ready.value == 1, "RX should recover to idle after false start"


@cocotb.test()
async def test_uart_rx_framing_error(dut):
    if not _is_uart_rx(dut):
        dut._log.info("Skipping RX-only test for %s", dut._name)
        return
    clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
    driver = cocotb.start_soon(_drive_uart_frame(dut, 0x3C, clks_per_bit, stop_high=False))
    try:
        await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
        assert False, "Framing error should suppress rx_valid"
    except SimTimeoutError:
        pass
    await driver
    assert dut.rx_ready.value == 1, "RX should return to IDLE after framing error"


@cocotb.test()
async def test_uart_loopback_single(dut):
    if _is_uart_tx(dut):
        _, bit_period_ns = await _setup_uart_tx(dut)
        await _launch_tx_byte(dut, 0xAB)
        frame = await _capture_tx_frame(dut, bit_period_ns)
        assert _decode_frame(frame) == 0xAB, "Loopback decode mismatch for TX"
    elif _is_uart_rx(dut):
        clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
        driver = cocotb.start_soon(_drive_uart_frame(dut, 0xAB, clks_per_bit))
        await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
        # recent sample ensures going through handshake
        assert int(dut.rx_data.value) == 0xAB, "Loopback RX mismatch"
        await driver
    else:
        dut._log.info("Loopback test only applies to UART blocks")
        return


@cocotb.test()
async def test_uart_loopback_multiple(dut):
    if _is_uart_tx(dut):
        _, bit_period_ns = await _setup_uart_tx(dut)
        payload = [0x12, 0x34, 0x56]
        for byte in payload:
            await _launch_tx_byte(dut, byte)
            frame = await _capture_tx_frame(dut, bit_period_ns)
            assert _decode_frame(frame) == byte, f"TX loopback mismatch for {byte:#04x}"
    elif _is_uart_rx(dut):
        clks_per_bit, bit_period_ns = await _setup_uart_rx(dut)
        payload = [0x12, 0x34, 0x56]
        for byte in payload:
            driver = cocotb.start_soon(_drive_uart_frame(dut, byte, clks_per_bit))
            await with_timeout(RisingEdge(dut.rx_valid), 12 * bit_period_ns, timeout_unit="ns")
            assert int(dut.rx_data.value) == byte, f"RX loopback mismatch for {byte:#04x}"
            await driver
            await RisingEdge(dut.clk)
    else:
        dut._log.info("Loopback test only applies to UART blocks")
        return


def _run_uart(module_name):
    from cocotb_tools.runner import get_runner

    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", module_name)

    os.makedirs(wave_dir, exist_ok=True)
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)

    waves_enabled = os.environ.get("WAVES", "0") != "0"

    runner = get_runner("verilator")
    runner.build(
        sources=[os.path.join(rtl_dir, f"{module_name}.sv")],
        hdl_toplevel=module_name,
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=[
            "--timing",
            "-Wno-WIDTHEXPAND",
            "-Wno-WIDTHTRUNC",
            "-Wno-UNUSEDSIGNAL",
        ],
    )
    runner.test(
        hdl_toplevel=module_name,
        test_module="tests.test_uart",
        waves=waves_enabled,
    )

    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, f"{module_name}.vcd"))


def test_uart_tx_runner():
    _run_uart("uart_tx")


def test_uart_rx_runner():
    _run_uart("uart_rx")


if __name__ == "__main__":
    test_uart_tx_runner()
    test_uart_rx_runner()
