`timescale 1ns / 1ps

// TPU Top - Complete system integrating UART Controller, Bridge, and MLP
// Implements TPU v1 architecture from chewingonchips.substack.com

module tpu_top #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200
)(
    input  logic clk,
    input  logic rst,

    // UART interface
    input  logic uart_rx,
    output logic uart_tx,

    // Debug/status taps
    output logic [3:0]  mlp_state_dbg,
    output logic [4:0]  mlp_cycle_cnt_dbg,
    output logic [2:0]  mlp_layer_dbg,
    output logic        mlp_layer_complete_dbg,
    output logic signed [31:0] mlp_acc0_dbg,
    output logic signed [31:0] mlp_acc1_dbg,
    output logic        mlp_acc_valid_dbg,
    output logic [3:0]  uart_state_dbg,
    output logic [7:0]  uart_cmd_dbg,
    output logic [2:0]  uart_byte_count_dbg,
    output logic [1:0]  uart_resp_idx_dbg,
    output logic        uart_tx_valid_dbg,
    output logic        uart_tx_ready_dbg,
    output logic        uart_rx_valid_dbg,
    output logic [7:0]  uart_rx_data_dbg,
    output logic        uart_weights_ready_dbg,
    output logic        uart_start_mlp_dbg
);

    // UART Controller signals
    logic        wf_push_col0;
    logic        wf_push_col1;
    logic [7:0]  wf_data_in;
    logic        wf_reset;
    logic        init_act_valid;
    logic [15:0] init_act_data;
    logic        start_mlp;
    logic        weights_ready;

    logic [3:0]  mlp_state_ctrl;
    logic [4:0]  mlp_cycle_cnt;
    logic signed [31:0] mlp_acc0;

    // UART Controller instance
    logic [3:0]  uart_state_int;
    logic [7:0]  uart_cmd_int;
    logic [2:0]  uart_byte_cnt_int;
    logic [1:0]  uart_resp_idx_int;
    logic        uart_tx_valid_int;
    logic        uart_tx_ready_int;
    logic        uart_rx_valid_int;
    logic [7:0]  uart_rx_data_int;
    logic        uart_weights_ready_int;
    logic        uart_start_mlp_int;

    uart_controller #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart_ctrl_u (
        .clk(clk),
        .rst(rst),
        .uart_rx(uart_rx),
        .uart_tx(uart_tx),
        .wf_push_col0(wf_push_col0),
        .wf_push_col1(wf_push_col1),
        .wf_data_in(wf_data_in),
        .wf_reset(wf_reset),
        .init_act_valid(init_act_valid),
        .init_act_data(init_act_data),
        .start_mlp(start_mlp),
        .weights_ready(weights_ready),
        .mlp_state(mlp_state_ctrl),
        .mlp_cycle_cnt(mlp_cycle_cnt),
        .mlp_acc0(mlp_acc0),
        .dbg_state(uart_state_int),
        .dbg_cmd_reg(uart_cmd_int),
        .dbg_byte_count(uart_byte_cnt_int),
        .dbg_resp_byte_idx(uart_resp_idx_int),
        .dbg_tx_valid(uart_tx_valid_int),
        .dbg_tx_ready(uart_tx_ready_int),
        .dbg_rx_valid(uart_rx_valid_int),
        .dbg_rx_data(uart_rx_data_int),
        .dbg_weights_ready(uart_weights_ready_int),
        .dbg_start_mlp(uart_start_mlp_int)
    );

    // Bridge signals to MLP
    logic        mlp_wf_push_col0;
    logic        mlp_wf_push_col1;
    logic [7:0]  mlp_wf_data_in;
    logic        mlp_wf_reset;
    logic        mlp_init_act_valid;
    logic [15:0] mlp_init_act_data;
    logic        mlp_start_mlp;
    logic        mlp_weights_ready;
    logic [2:0]  mlp_vpu_activation_type;
    logic signed [15:0] mlp_norm_gain;
    logic signed [31:0] mlp_norm_bias;
    logic [4:0]  mlp_norm_shift;
    logic signed [15:0] mlp_q_inv_scale;
    logic signed [7:0]  mlp_q_zero_point;

    logic [3:0]  mlp_state_out;
    logic [4:0]  mlp_cycle_cnt_out;
    logic [2:0]  mlp_current_layer_out;
    logic        mlp_layer_complete_out;
    logic signed [31:0] mlp_acc0_out;
    logic signed [31:0] mlp_acc1_out;
    logic        mlp_acc_valid_out;

    // TPU Bridge instance
    tpu_bridge bridge_u (
        .clk(clk),
        // UART Controller interface
        .ctrl_wf_push_col0(wf_push_col0),
        .ctrl_wf_push_col1(wf_push_col1),
        .ctrl_wf_data_in(wf_data_in),
        .ctrl_wf_reset(wf_reset),
        .ctrl_init_act_valid(init_act_valid),
        .ctrl_init_act_data(init_act_data),
        .ctrl_start_mlp(start_mlp),
        .ctrl_weights_ready(weights_ready),
        .mlp_state(mlp_state_ctrl),
        .mlp_cycle_cnt(mlp_cycle_cnt),
        .mlp_acc0(mlp_acc0),
        // MLP Top interface
        .mlp_wf_push_col0(mlp_wf_push_col0),
        .mlp_wf_push_col1(mlp_wf_push_col1),
        .mlp_wf_data_in(mlp_wf_data_in),
        .mlp_wf_reset(mlp_wf_reset),
        .mlp_init_act_valid(mlp_init_act_valid),
        .mlp_init_act_data(mlp_init_act_data),
        .mlp_start_mlp(mlp_start_mlp),
        .mlp_weights_ready(mlp_weights_ready),
        .mlp_vpu_activation_type(mlp_vpu_activation_type),
        .mlp_norm_gain(mlp_norm_gain),
        .mlp_norm_bias(mlp_norm_bias),
        .mlp_norm_shift(mlp_norm_shift),
        .mlp_q_inv_scale(mlp_q_inv_scale),
        .mlp_q_zero_point(mlp_q_zero_point),
        .mlp_state_in(mlp_state_out),
        .mlp_cycle_cnt_in(mlp_cycle_cnt_out),
        .mlp_acc0_in(mlp_acc0_out)
    );

    // MLP Top instance
    mlp_top mlp_u (
        .clk(clk),
        .reset(rst),
        // Weight FIFO interface
        .wf_push_col0(mlp_wf_push_col0),
        .wf_push_col1(mlp_wf_push_col1),
        .wf_data_in(mlp_wf_data_in),
        .wf_reset(mlp_wf_reset),
        // Initial activation loading
        .init_act_valid(mlp_init_act_valid),
        .init_act_data(mlp_init_act_data),
        // Control
        .start_mlp(mlp_start_mlp),
        .weights_ready(mlp_weights_ready),
        // Activation pipeline configuration
        .vpu_activation_type(mlp_vpu_activation_type),
        .norm_gain(mlp_norm_gain),
        .norm_bias(mlp_norm_bias),
        .norm_shift(mlp_norm_shift),
        .q_inv_scale(mlp_q_inv_scale),
        .q_zero_point(mlp_q_zero_point),
        // Status outputs
        .state(mlp_state_out),
        .cycle_cnt(mlp_cycle_cnt_out),
        .current_layer(mlp_current_layer_out),
        .layer_complete(mlp_layer_complete_out),
        // Debug outputs
        .mmu_acc0_out(),  // Not used in this integration
        .mmu_acc1_out(),  // Not used in this integration
        .acc0(mlp_acc0_out),
        .acc1(mlp_acc1_out),
        .acc_valid(mlp_acc_valid_out)
    );

    // Note: mlp_state_ctrl, mlp_cycle_cnt, and mlp_acc0 are connected via tpu_bridge
    // (bridge receives mlp_state_in/mlp_cycle_cnt_in/mlp_acc0_in from mlp_u,
    //  and outputs mlp_state/mlp_cycle_cnt/mlp_acc0 to uart_controller)
    // No additional assigns needed - avoid multi-driver conflict

    // #region agent log
    logic [3:0] mlp_state_out_prev;
    always_ff @(posedge clk) begin
        if (!rst) begin  // Only log when not in reset
            if (mlp_state_out != mlp_state_out_prev) begin
                $display("[TPU_TOP] State change: mlp_state_out=%d->%d, mlp_cycle_cnt_out=%d, mlp_acc0_out=0x%08X",
                         mlp_state_out_prev, mlp_state_out, mlp_cycle_cnt_out, mlp_acc0_out);
            end
            mlp_state_out_prev <= mlp_state_out;
        end else begin
            mlp_state_out_prev <= 4'd0;
        end
    end
    // #endregion

    // Debug exports
    assign mlp_state_dbg = mlp_state_out;
    assign mlp_cycle_cnt_dbg = mlp_cycle_cnt_out;
    assign mlp_layer_dbg = mlp_current_layer_out;
    assign mlp_layer_complete_dbg = mlp_layer_complete_out;
    assign mlp_acc0_dbg = mlp_acc0_out;
    assign mlp_acc1_dbg = mlp_acc1_out;
    assign mlp_acc_valid_dbg = mlp_acc_valid_out;
    assign uart_state_dbg = uart_state_int;
    assign uart_cmd_dbg = uart_cmd_int;
    assign uart_byte_count_dbg = uart_byte_cnt_int;
    assign uart_resp_idx_dbg = uart_resp_idx_int;
    assign uart_tx_valid_dbg = uart_tx_valid_int;
    assign uart_tx_ready_dbg = uart_tx_ready_int;
    assign uart_rx_valid_dbg = uart_rx_valid_int;
    assign uart_rx_data_dbg = uart_rx_data_int;
    assign uart_weights_ready_dbg = uart_weights_ready_int;
    assign uart_start_mlp_dbg = uart_start_mlp_int;

endmodule
