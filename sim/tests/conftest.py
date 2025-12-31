"""
Shared pytest fixtures and cocotb utilities for TinyTinyTPU testbenches.
"""
import os
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles, Timer

# Try to import waveform support
try:
    from cocotb.wavedrom import Wavedrom
    HAS_WAVEDROM = True
except ImportError:
    HAS_WAVEDROM = False

# Clock period in nanoseconds
CLK_PERIOD_NS = 10


def enable_verilator_trace():
    """
    Enable Verilator trace dumping.
    Call this at the start of tests if you want waveforms.
    """
    import cocotb.simulator as simulator
    # Try to enable trace via VPI
    try:
        # For Verilator, the trace is controlled via plusargs
        # The --trace flag during compile enables trace capability
        # Actual dumping happens automatically if properly configured
        pass
    except Exception as e:
        cocotb.log.warning(f"Could not enable trace: {e}")


async def setup_clock(dut, period_ns=CLK_PERIOD_NS):
    """Start the clock on dut.clk"""
    clock = Clock(dut.clk, period_ns, units="ns")
    cocotb.start_soon(clock.start())
    return clock


async def reset_dut(dut, cycles=2):
    """Apply reset for specified number of cycles"""
    dut.reset.value = 1
    await ClockCycles(dut.clk, cycles)
    dut.reset.value = 0
    await RisingEdge(dut.clk)


async def wait_cycles(dut, n):
    """Wait for n clock cycles"""
    await ClockCycles(dut.clk, n)


def get_wave_dir():
    """Return path to waves directory"""
    return os.path.join(os.path.dirname(__file__), "..", "..", "waves")


def log_signal(dut, name, signal):
    """Log a signal value for debugging"""
    dut._log.info(f"{name} = {signal.value}")


class TPUTestHelper:
    """Helper class for common TPU test operations"""

    def __init__(self, dut):
        self.dut = dut

    async def setup(self, period_ns=CLK_PERIOD_NS):
        """Initialize clock and reset"""
        await setup_clock(self.dut, period_ns)
        await reset_dut(self.dut)

    async def tick(self, n=1):
        """Wait for n clock cycles"""
        await ClockCycles(self.dut.clk, n)

    async def wait_for(self, signal, value=1, timeout=100):
        """Wait for signal to reach value, with timeout"""
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if signal.value == value:
                return True
        return False

    def assert_eq(self, actual, expected, msg=""):
        """Assert equality with logging"""
        if actual != expected:
            self.dut._log.error(f"FAIL: {msg} - expected {expected}, got {actual}")
            assert False, f"{msg}: expected {expected}, got {actual}"
        else:
            self.dut._log.info(f"PASS: {msg} - got {expected}")

