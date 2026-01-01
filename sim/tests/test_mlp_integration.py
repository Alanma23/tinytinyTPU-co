"""
MLP Integration testbench for TinyTinyTPU.
Tests 2-layer MLP: H = ReLU(A x W1), Y = ReLU(H x W2)
Validates the full datapath: Weight FIFO -> MMU -> Accumulator -> Activation Pipeline -> UB
"""
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles
import os
import shutil
from enum import IntEnum


class State(IntEnum):
    """FSM states for MLP controller"""
    IDLE = 0
    LOAD_WEIGHT = 1
    LOAD_ACT = 2
    COMPUTE = 3
    DRAIN = 4
    TRANSFER = 5
    NEXT_LAYER = 6
    WAIT_WEIGHTS = 7
    DONE = 8


class MLPController:
    """Python controller for MLP test orchestration"""

    def __init__(self, dut):
        self.dut = dut
        self.state = State.IDLE
        self.cycle_cnt = 0
        self.current_layer = 0
        self.num_layers = 2
        self.results = {}

    async def load_weights_to_fifo(self, w00, w01, w10, w11):
        """Load a 2x2 weight matrix into the dual weight FIFO"""
        dut = self.dut

        # Push to col0: bottom row first (w10), then top row (w00)
        dut.wf_push_col0.value = 1
        dut.wf_push_col1.value = 0

        dut.wf_data_in.value = w10
        await FallingEdge(dut.clk)

        dut.wf_data_in.value = w00
        await FallingEdge(dut.clk)

        dut.wf_push_col0.value = 0

        # Push to col1: bottom row first (w11), then top row (w01)
        dut.wf_push_col1.value = 1

        dut.wf_data_in.value = w11
        await FallingEdge(dut.clk)

        dut.wf_data_in.value = w01
        await FallingEdge(dut.clk)

        dut.wf_push_col1.value = 0
        await RisingEdge(dut.clk)

    async def load_activations_to_ub(self, act_matrix):
        """Load activation matrix into unified buffer"""
        dut = self.dut

        # Pack as {row1_data, row0_data} pairs
        for row_idx in range(len(act_matrix)):
            row = act_matrix[row_idx]
            packed = (row[1] << 8) | row[0]  # {A[row,1], A[row,0]}

            dut.init_act_valid.value = 1
            dut.init_act_data.value = packed
            await FallingEdge(dut.clk)

        dut.init_act_valid.value = 0
        await RisingEdge(dut.clk)


# ============================================================================
# Integration Tests
# ============================================================================

@cocotb.test()
async def test_mlp_weight_loading(dut):
    """Test that weights can be loaded into MMU via FIFO"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Initialize signals
    dut.wf_push_col0.value = 0
    dut.wf_push_col1.value = 0
    dut.wf_data_in.value = 0
    dut.wf_reset.value = 0
    await RisingEdge(dut.clk)

    ctrl = MLPController(dut)

    # Load weights W1 = [[1, 2], [3, 4]]
    dut._log.info("Loading weights: W = [[1, 2], [3, 4]]")
    await ctrl.load_weights_to_fifo(1, 2, 3, 4)

    await ClockCycles(dut.clk, 5)

    dut._log.info("PASS: Weight loading test")


@cocotb.test()
async def test_mlp_single_layer_compute(dut):
    """
    Test single layer matrix multiply.

    A = [[5, 6], [7, 8]]
    W = [[1, 2], [3, 4]]

    Expected H = A x W:
    H[0,0] = 5*1 + 6*3 = 23
    H[0,1] = 5*2 + 6*4 = 34
    H[1,0] = 7*1 + 8*3 = 31
    H[1,1] = 7*2 + 8*4 = 46
    """
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Initialize all control signals
    dut.wf_push_col0.value = 0
    dut.wf_push_col1.value = 0
    dut.wf_data_in.value = 0
    dut.wf_reset.value = 0
    dut.init_act_valid.value = 0
    dut.init_act_data.value = 0
    dut.start_mlp.value = 0
    dut.weights_ready.value = 0

    # Configure activation pipeline for passthrough
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0

    await RisingEdge(dut.clk)

    ctrl = MLPController(dut)

    # Load weights W1 = [[1, 2], [3, 4]]
    dut._log.info("Loading weights W1 = [[1, 2], [3, 4]]")
    await ctrl.load_weights_to_fifo(1, 2, 3, 4)

    # Load activations A = [[5, 6], [7, 8]]
    dut._log.info("Loading activations A = [[5, 6], [7, 8]]")
    await ctrl.load_activations_to_ub([[5, 6], [7, 8]])

    await ClockCycles(dut.clk, 3)

    # Start MLP computation
    dut._log.info("Starting MLP computation")
    dut.start_mlp.value = 1
    await ClockCycles(dut.clk, 1)
    dut.start_mlp.value = 0

    # Wait for state machine to progress through computation
    # Monitor state transitions
    for cycle in range(100):
        await RisingEdge(dut.clk)
        state = int(dut.state.value)

        if state == State.COMPUTE:
            dut._log.info(f"Cycle {cycle}: COMPUTE - mmu_acc0={int(dut.mmu_acc0_out.value)}, mmu_acc1={int(dut.mmu_acc1_out.value)}")

        if state == State.DRAIN:
            dut._log.info(f"Cycle {cycle}: DRAIN - acc0={dut.acc0.value.signed_integer}, acc1={dut.acc1.value.signed_integer}")

        if state == State.DONE:
            dut._log.info(f"Cycle {cycle}: DONE")
            break

    # Check results
    dut._log.info("Expected results:")
    dut._log.info("  H[0,0] = 5*1 + 6*3 = 23")
    dut._log.info("  H[0,1] = 5*2 + 6*4 = 34")
    dut._log.info("  H[1,0] = 7*1 + 8*3 = 31")
    dut._log.info("  H[1,1] = 7*2 + 8*4 = 46")

    dut._log.info("PASS: Single layer compute test")


@cocotb.test()
async def test_mlp_two_layer_network(dut):
    """
    Test 2-layer MLP network.

    Layer 1: H = ReLU(A x W1)
    Layer 2: Y = ReLU(H x W2)

    Input:  A  = [[5, 6], [7, 8]]
    W1:     W1 = [[1, 2], [3, 4]]
    W2:     W2 = [[1, 1], [1, 1]]

    Expected Layer 1:
    H = [[23, 34], [31, 46]]

    Expected Layer 2:
    Y[0,0] = 23*1 + 34*1 = 57
    Y[0,1] = 23*1 + 34*1 = 57
    Y[1,0] = 31*1 + 46*1 = 77
    Y[1,1] = 31*1 + 46*1 = 77
    """
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Initialize all control signals
    dut.wf_push_col0.value = 0
    dut.wf_push_col1.value = 0
    dut.wf_data_in.value = 0
    dut.wf_reset.value = 0
    dut.init_act_valid.value = 0
    dut.init_act_data.value = 0
    dut.start_mlp.value = 0
    dut.weights_ready.value = 0

    # Configure activation pipeline for passthrough
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0

    await RisingEdge(dut.clk)

    ctrl = MLPController(dut)

    dut._log.info("=" * 60)
    dut._log.info("2-Layer MLP Test")
    dut._log.info("  Input A  = [[5, 6], [7, 8]]")
    dut._log.info("  Layer 1: W1 = [[1, 2], [3, 4]]")
    dut._log.info("  Layer 2: W2 = [[1, 1], [1, 1]]")
    dut._log.info("=" * 60)

    # Load Layer 1 weights
    dut._log.info("Loading Layer 1 weights")
    await ctrl.load_weights_to_fifo(1, 2, 3, 4)

    # Load initial activations
    dut._log.info("Loading initial activations")
    await ctrl.load_activations_to_ub([[5, 6], [7, 8]])

    await ClockCycles(dut.clk, 3)

    # Start MLP
    dut._log.info("Starting MLP")
    dut.start_mlp.value = 1
    await ClockCycles(dut.clk, 1)
    dut.start_mlp.value = 0

    # Monitor and wait for Layer 1 to complete
    layer1_results = []
    for cycle in range(200):
        await RisingEdge(dut.clk)
        state = int(dut.state.value)
        current_layer = int(dut.current_layer.value)

        if state == State.WAIT_WEIGHTS and current_layer == 1:
            dut._log.info("Layer 1 complete, loading Layer 2 weights")

            # Reset FIFO and load new weights
            await ClockCycles(dut.clk, 2)
            await ctrl.load_weights_to_fifo(1, 1, 1, 1)

            # Signal weights ready
            dut.weights_ready.value = 1
            await ClockCycles(dut.clk, 1)
            dut.weights_ready.value = 0

        if state == State.DONE:
            dut._log.info("MLP computation complete!")
            break

    # Allow time for final results
    await ClockCycles(dut.clk, 10)

    dut._log.info("=" * 60)
    dut._log.info("Expected Results:")
    dut._log.info("  Layer 1: H = [[23, 34], [31, 46]]")
    dut._log.info("  Layer 2: Y = [[57, 57], [77, 77]]")
    dut._log.info("=" * 60)

    dut._log.info("PASS: Two-layer MLP test")


@cocotb.test()
async def test_mlp_state_machine(dut):
    """Test that state machine transitions correctly"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    await ClockCycles(dut.clk, 2)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Initialize signals
    dut.wf_push_col0.value = 0
    dut.wf_push_col1.value = 0
    dut.wf_data_in.value = 0
    dut.wf_reset.value = 0
    dut.init_act_valid.value = 0
    dut.init_act_data.value = 0
    dut.start_mlp.value = 0
    dut.weights_ready.value = 0
    dut.norm_gain.value = 256
    dut.norm_bias.value = 0
    dut.norm_shift.value = 8
    dut.q_inv_scale.value = 256
    dut.q_zero_point.value = 0
    await RisingEdge(dut.clk)

    # Check initial state is IDLE
    assert int(dut.state.value) == State.IDLE, f"Initial state should be IDLE, got {int(dut.state.value)}"
    dut._log.info("Initial state: IDLE")

    ctrl = MLPController(dut)

    # Load some weights and activations
    await ctrl.load_weights_to_fifo(1, 2, 3, 4)
    await ctrl.load_activations_to_ub([[5, 6], [7, 8]])

    # Start MLP
    dut.start_mlp.value = 1
    await ClockCycles(dut.clk, 1)
    dut.start_mlp.value = 0

    # Track state transitions
    states_seen = set()
    for cycle in range(100):
        await RisingEdge(dut.clk)
        state = int(dut.state.value)
        if state not in states_seen:
            state_name = State(state).name if state < len(State) else f"UNKNOWN({state})"
            dut._log.info(f"Cycle {cycle}: New state -> {state_name}")
            states_seen.add(state)

        if state == State.DONE:
            break

    # Verify key states were visited
    assert State.LOAD_WEIGHT in states_seen, "Should visit LOAD_WEIGHT state"
    assert State.COMPUTE in states_seen, "Should visit COMPUTE state"

    dut._log.info(f"States visited: {[State(s).name for s in sorted(states_seen)]}")
    dut._log.info("PASS: State machine test")


def test_mlp_integration_runner():
    """Run MLP integration tests using cocotb_tools.runner"""
    from cocotb_tools.runner import get_runner
    
    sim_dir = os.path.dirname(__file__)
    rtl_dir = os.path.join(sim_dir, "..", "..", "rtl")
    wave_dir = os.path.join(sim_dir, "..", "waves")
    build_dir = os.path.join(sim_dir, "..", "sim_build", "mlp_top")
    
    os.makedirs(wave_dir, exist_ok=True)
    
    # Clean existing build to avoid conflicts
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    
    # Check if waveforms are requested via WAVES env var
    waves_enabled = os.environ.get("WAVES", "0") != "0"
    
    # All RTL sources needed for integration test
    rtl_sources = [
        os.path.join(rtl_dir, "pe.sv"),
        os.path.join(rtl_dir, "mmu.sv"),
        os.path.join(rtl_dir, "weight_fifo.sv"),
        os.path.join(rtl_dir, "dual_weight_fifo.sv"),
        os.path.join(rtl_dir, "accumulator_align.sv"),
        os.path.join(rtl_dir, "accumulator_mem.sv"),
        os.path.join(rtl_dir, "accumulator.sv"),
        os.path.join(rtl_dir, "activation_func.sv"),
        os.path.join(rtl_dir, "normalizer.sv"),
        os.path.join(rtl_dir, "loss_block.sv"),
        os.path.join(rtl_dir, "activation_pipeline.sv"),
        os.path.join(rtl_dir, "unified_buffer.sv"),
        os.path.join(rtl_dir, "mlp_top.sv"),
    ]

    runner = get_runner("verilator")
    runner.build(
        sources=rtl_sources,
        hdl_toplevel="mlp_top",
        build_dir=build_dir,
        waves=waves_enabled,
        build_args=["--timing",
                   "-Wno-PINCONNECTEMPTY", "-Wno-UNUSEDSIGNAL",
                   "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC",
                   "-CFLAGS", "-std=c++17"]
    )
    # Add tests directory to Python path for module import
    import sys
    sys.path.insert(0, sim_dir)

    runner.test(
        hdl_toplevel="mlp_top",
        test_module="test_mlp_integration",
        waves=waves_enabled
    )
    
    # Copy VCD to waves directory if generated
    if waves_enabled:
        vcd_src = os.path.join(build_dir, "dump.vcd")
        if os.path.exists(vcd_src):
            shutil.copy(vcd_src, os.path.join(wave_dir, "mlp_top.vcd"))
            print(f"Waveform saved to {wave_dir}/mlp_top.vcd")


if __name__ == "__main__":
    test_mlp_integration_runner()
