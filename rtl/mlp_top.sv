`timescale 1ns / 1ps

// Top-level MLP integration module for cocotb testing
// Instantiates: Dual Weight FIFO, Unified Buffers, MMU, Accumulator, Activation Pipeline

module mlp_top (
    input  logic        clk,
    input  logic        reset,

    // Weight FIFO interface
    input  logic        wf_push_col0,
    input  logic        wf_push_col1,
    input  logic [7:0]  wf_data_in,
    input  logic        wf_reset,

    // Initial activation loading
    input  logic        init_act_valid,
    input  logic [15:0] init_act_data,

    // Control
    input  logic        start_mlp,
    input  logic        weights_ready,

    // Activation pipeline configuration
    input  logic signed [15:0] norm_gain,
    input  logic signed [31:0] norm_bias,
    input  logic [4:0]  norm_shift,
    input  logic signed [15:0] q_inv_scale,
    input  logic signed [7:0]  q_zero_point,

    // Status outputs
    output logic [3:0]  state,
    output logic [4:0]  cycle_cnt,
    output logic [2:0]  current_layer,
    output logic        layer_complete,

    // Debug outputs
    output logic [15:0] mmu_acc0_out,
    output logic [15:0] mmu_acc1_out,
    output logic signed [31:0] acc0,
    output logic signed [31:0] acc1,
    output logic        acc_valid
);

    // FSM States
    // synthesis attribute FSM_ENCODING of state_reg is "USER"
    localparam logic [3:0] IDLE         = 4'd0;
    localparam logic [3:0] LOAD_WEIGHT  = 4'd1;
    localparam logic [3:0] LOAD_ACT     = 4'd2;
    localparam logic [3:0] COMPUTE      = 4'd3;
    localparam logic [3:0] DRAIN        = 4'd4;
    localparam logic [3:0] TRANSFER     = 4'd5;
    localparam logic [3:0] NEXT_LAYER   = 4'd6;
    localparam logic [3:0] WAIT_WEIGHTS = 4'd7;
    localparam logic [3:0] DONE         = 4'd8;

    // Set to 1 for single-layer testing, 2+ for multi-layer MLP
    localparam int NUM_LAYERS = 1;

    // Internal state
    logic [3:0]  state_reg;
    logic [4:0]  cycle_cnt_reg;
    logic [2:0]  current_layer_reg;
    logic        buffer_select;
    logic        weights_loaded;

    assign state = state_reg;
    assign cycle_cnt = cycle_cnt_reg;
    assign current_layer = current_layer_reg;

    // Derived control signals
    logic en_load_weight;
    logic compute_phase;
    logic drain_phase;
    logic transfer_phase;

    assign en_load_weight = (state_reg == LOAD_WEIGHT);
    assign compute_phase  = (state_reg == COMPUTE);
    assign drain_phase    = (state_reg == DRAIN);
    assign transfer_phase = (state_reg == TRANSFER);

    // Weight FIFO
    logic [7:0] wf_col0_out, wf_col1_out, wf_col1_raw;

    dual_weight_fifo weight_fifo_u (
        .clk(clk),
        .reset(reset | wf_reset),
        .push_col0(wf_push_col0),
        .push_col1(wf_push_col1),
        .data_in(wf_data_in),
        .pop(en_load_weight),
        .col0_out(wf_col0_out),
        .col1_out(wf_col1_out),
        .col1_raw(wf_col1_raw)
    );

    // Unified Buffers (double buffered)
    logic        ub_a_wr_valid, ub_a_rd_ready;
    logic [15:0] ub_a_wr_data, ub_a_rd_data;
    logic        ub_a_wr_ready, ub_a_rd_valid, ub_a_empty;

    logic        ub_b_wr_valid, ub_b_rd_ready;
    logic [15:0] ub_b_wr_data, ub_b_rd_data;
    logic        ub_b_wr_ready, ub_b_rd_valid, ub_b_empty;

    unified_buffer #(.WIDTH(16), .DEPTH(16)) ub_a (
        .clk(clk),
        .reset(reset),
        .wr_valid(ub_a_wr_valid),
        .wr_data(ub_a_wr_data),
        .wr_ready(ub_a_wr_ready),
        .rd_ready(ub_a_rd_ready),
        .rd_valid(ub_a_rd_valid),
        .rd_data(ub_a_rd_data),
        .full(),
        .empty(ub_a_empty),
        .count()
    );

    unified_buffer #(.WIDTH(16), .DEPTH(16)) ub_b (
        .clk(clk),
        .reset(reset),
        .wr_valid(ub_b_wr_valid),
        .wr_data(ub_b_wr_data),
        .wr_ready(ub_b_wr_ready),
        .rd_ready(ub_b_rd_ready),
        .rd_valid(ub_b_rd_valid),
        .rd_data(ub_b_rd_data),
        .full(),
        .empty(ub_b_empty),
        .count()
    );

    // Buffer selection muxing
    logic        act_ub_rd_valid;
    logic [15:0] act_ub_rd_data;
    logic        act_ub_empty;

    assign act_ub_rd_valid = buffer_select ? ub_b_rd_valid : ub_a_rd_valid;
    assign act_ub_rd_data  = buffer_select ? ub_b_rd_data  : ub_a_rd_data;
    assign act_ub_empty    = buffer_select ? ub_b_empty    : ub_a_empty;

    always_comb begin
        ub_a_rd_ready = 1'b0;
        ub_b_rd_ready = 1'b0;
        if (compute_phase) begin
            if (buffer_select)
                ub_b_rd_ready = 1'b1;
            else
                ub_a_rd_ready = 1'b1;
        end
    end

    // Activation data extraction
    logic [7:0] act_row0_data, act_row1_data;
    assign act_row0_data = act_ub_rd_data[7:0];
    assign act_row1_data = act_ub_rd_data[15:8];

    // Row1 skew register for systolic timing
    logic [7:0] row1_skew_reg;

    always_ff @(posedge clk) begin
        if (reset)
            row1_skew_reg <= 8'd0;
        else if (compute_phase && act_ub_rd_valid)
            row1_skew_reg <= act_row1_data;
    end

    // MMU connections
    logic [7:0] mmu_row0_in, mmu_row1_in;
    logic [7:0] mmu_col0_in, mmu_col1_in;

    assign mmu_row0_in = (compute_phase && act_ub_rd_valid) ? act_row0_data : 8'd0;
    assign mmu_row1_in = compute_phase ? row1_skew_reg : 8'd0;
    assign mmu_col0_in = en_load_weight ? wf_col0_out : 8'd0;
    assign mmu_col1_in = en_load_weight ? wf_col1_out : 8'd0;

    logic en_capture_col0, en_capture_col1;
    assign en_capture_col0 = en_load_weight && (cycle_cnt_reg == 5'd1);
    assign en_capture_col1 = en_load_weight && (cycle_cnt_reg == 5'd2);

    mmu mmu_u (
        .clk(clk),
        .reset(reset),
        .en_weight_pass(en_load_weight),
        .en_capture_col0(en_capture_col0),
        .en_capture_col1(en_capture_col1),
        .row0_in(mmu_row0_in),
        .row1_in(mmu_row1_in),
        .col0_in(mmu_col0_in),
        .col1_in(mmu_col1_in),
        .acc0_out(mmu_acc0_out),
        .acc1_out(mmu_acc1_out)
    );

    // Accumulator
    logic accum_en;
    logic addr_sel;
    logic mmu_valid;

    assign mmu_valid = (compute_phase && cycle_cnt_reg >= 5'd2) || drain_phase;

    accumulator accum_u (
        .clk(clk),
        .reset(reset),
        .valid_in(mmu_valid),
        .accumulator_enable(accum_en),
        .addr_sel(addr_sel),
        .mmu_col0_in(mmu_acc0_out),
        .mmu_col1_in(mmu_acc1_out),
        .acc_col0_out(acc0),
        .acc_col1_out(acc1),
        .valid_out(acc_valid)
    );

    // Activation Pipelines (one per column)
    logic        ap_valid;
    logic signed [7:0] ap_data_col0, ap_data_col1;

    activation_pipeline ap_col0 (
        .clk(clk),
        .reset(reset),
        .valid_in(acc_valid),
        .acc_in(acc0),
        .target_in(32'sd0),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(ap_valid),
        .ub_data_out(ap_data_col0),
        .loss_valid(),
        .loss_out()
    );

    activation_pipeline ap_col1 (
        .clk(clk),
        .reset(reset),
        .valid_in(acc_valid),
        .acc_in(acc1),
        .target_in(32'sd0),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(),
        .ub_data_out(ap_data_col1),
        .loss_valid(),
        .loss_out()
    );

    // Output repacking for UB refill
    logic        refill_valid;
    logic [15:0] refill_data;

    always_ff @(posedge clk) begin
        if (reset) begin
            refill_valid <= 1'b0;
            refill_data <= 16'd0;
        end else begin
            refill_valid <= 1'b0;
            if (ap_valid) begin
                refill_data <= {ap_data_col1, ap_data_col0};
                refill_valid <= 1'b1;
            end
        end
    end

    // UB write muxing
    always_comb begin
        ub_a_wr_valid = 1'b0;
        ub_a_wr_data = 16'd0;
        ub_b_wr_valid = 1'b0;
        ub_b_wr_data = 16'd0;

        if (init_act_valid) begin
            ub_a_wr_valid = 1'b1;
            ub_a_wr_data = init_act_data;
        end else if (drain_phase || transfer_phase) begin
            if (buffer_select) begin
                ub_a_wr_valid = refill_valid;
                ub_a_wr_data = refill_data;
            end else begin
                ub_b_wr_valid = refill_valid;
                ub_b_wr_data = refill_data;
            end
        end
    end

    // FSM Controller
    always_ff @(posedge clk) begin
        if (reset) begin
            state_reg <= IDLE;
            cycle_cnt_reg <= 5'd0;
            current_layer_reg <= 3'd0;
            buffer_select <= 1'b0;
            weights_loaded <= 1'b0;
            layer_complete <= 1'b0;
            accum_en <= 1'b0;
            addr_sel <= 1'b0;
        end else begin
            case (state_reg)
                IDLE: begin
                    cycle_cnt_reg <= 5'd0;
                    layer_complete <= 1'b0;  // Clear completion flag
                    accum_en <= 1'b0;        // Reset accumulator enable
                    addr_sel <= 1'b0;        // Reset address select
                    if (start_mlp) begin
                        state_reg <= LOAD_WEIGHT;
                        current_layer_reg <= 3'd0;
                        buffer_select <= 1'b0;
                        weights_loaded <= 1'b0;  // Clear for fresh computation
                    end
                end

                LOAD_WEIGHT: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    if (cycle_cnt_reg == 5'd2) begin
                        state_reg <= (current_layer_reg == 0) ? LOAD_ACT : COMPUTE;
                        cycle_cnt_reg <= 5'd0;
                        weights_loaded <= 1'b1;
                    end
                end

                LOAD_ACT: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    if (cycle_cnt_reg == 5'd3) begin
                        state_reg <= COMPUTE;
                        cycle_cnt_reg <= 5'd0;
                    end
                end

                COMPUTE: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    // #region agent log
                    if (cycle_cnt_reg == 5'd0)
                        $display("[MLP] COMPUTE started. mmu_valid will be high when cycle_cnt>=2");
                    // #endregion
                    if (cycle_cnt_reg == 5'd2) begin
                        state_reg <= DRAIN;
                        cycle_cnt_reg <= 5'd0;
                    end
                end

                DRAIN: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    accum_en <= 1'b1;  // Enable accumulation during DRAIN to sum partial products
                    // #region agent log
                    if (cycle_cnt_reg == 5'd0)
                        $display("[MLP] DRAIN started. mmu_valid=1 throughout DRAIN. mmu_acc0=%04X, mmu_acc1=%04X", mmu_acc0_out, mmu_acc1_out);
                    if (cycle_cnt_reg == 5'd6)
                        $display("[MLP] DRAIN ending. acc0=0x%08X, acc1=0x%08X, acc_valid=%b", acc0, acc1, acc_valid);
                    // #endregion
                    if (cycle_cnt_reg == 5'd6) begin
                        if (current_layer_reg < 3'(NUM_LAYERS - 1)) begin
                            state_reg <= TRANSFER;
                            cycle_cnt_reg <= 5'd0;
                        end else begin
                            state_reg <= DONE;
                            cycle_cnt_reg <= 5'd0;
                        end
                    end
                end

                TRANSFER: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    if (cycle_cnt_reg == 5'd3) begin
                        state_reg <= NEXT_LAYER;
                        cycle_cnt_reg <= 5'd0;
                    end
                end

                NEXT_LAYER: begin
                    buffer_select <= ~buffer_select;
                    current_layer_reg <= current_layer_reg + 1'd1;
                    state_reg <= WAIT_WEIGHTS;
                    cycle_cnt_reg <= 5'd0;
                    weights_loaded <= 1'b0;
                end

                WAIT_WEIGHTS: begin
                    cycle_cnt_reg <= cycle_cnt_reg + 1'd1;
                    if (weights_ready && !weights_loaded) begin
                        state_reg <= LOAD_WEIGHT;
                        cycle_cnt_reg <= 5'd0;
                    end
                end

                DONE: begin
                    layer_complete <= 1'b1;
                    // #region agent log
                    $display("[MLP] DONE state reached. acc0=0x%08X, acc1=0x%08X, acc_valid=%b", acc0, acc1, acc_valid);
                    // #endregion
                    // Return to IDLE so we can accept new computations
                    state_reg <= IDLE;
                end

                default: state_reg <= IDLE;
            endcase
        end
    end

endmodule
