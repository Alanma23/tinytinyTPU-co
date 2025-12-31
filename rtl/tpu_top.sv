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
    output logic uart_tx
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

    logic [3:0]  mlp_state;
    logic [4:0]  mlp_cycle_cnt;
    logic [2:0]  mlp_current_layer;
    logic        mlp_layer_complete;
    logic signed [31:0] mlp_acc0;
    logic signed [31:0] mlp_acc1;
    logic        mlp_acc_valid;

    // UART Controller instance
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
        .mlp_state(mlp_state),
        .mlp_cycle_cnt(mlp_cycle_cnt),
        .mlp_current_layer(mlp_current_layer),
        .mlp_layer_complete(mlp_layer_complete),
        .mlp_acc0(mlp_acc0),
        .mlp_acc1(mlp_acc1),
        .mlp_acc_valid(mlp_acc_valid)
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
        .reset(rst),
        // UART Controller interface
        .ctrl_wf_push_col0(wf_push_col0),
        .ctrl_wf_push_col1(wf_push_col1),
        .ctrl_wf_data_in(wf_data_in),
        .ctrl_wf_reset(wf_reset),
        .ctrl_init_act_valid(init_act_valid),
        .ctrl_init_act_data(init_act_data),
        .ctrl_start_mlp(start_mlp),
        .ctrl_weights_ready(weights_ready),
        .mlp_state(mlp_state),
        .mlp_cycle_cnt(mlp_cycle_cnt),
        .mlp_current_layer(mlp_current_layer),
        .mlp_layer_complete(mlp_layer_complete),
        .mlp_acc0(mlp_acc0),
        .mlp_acc1(mlp_acc1),
        .mlp_acc_valid(mlp_acc_valid),
        // MLP Top interface
        .mlp_wf_push_col0(mlp_wf_push_col0),
        .mlp_wf_push_col1(mlp_wf_push_col1),
        .mlp_wf_data_in(mlp_wf_data_in),
        .mlp_wf_reset(mlp_wf_reset),
        .mlp_init_act_valid(mlp_init_act_valid),
        .mlp_init_act_data(mlp_init_act_data),
        .mlp_start_mlp(mlp_start_mlp),
        .mlp_weights_ready(mlp_weights_ready),
        .mlp_norm_gain(mlp_norm_gain),
        .mlp_norm_bias(mlp_norm_bias),
        .mlp_norm_shift(mlp_norm_shift),
        .mlp_q_inv_scale(mlp_q_inv_scale),
        .mlp_q_zero_point(mlp_q_zero_point),
        .mlp_state_in(mlp_state_out),
        .mlp_cycle_cnt_in(mlp_cycle_cnt_out),
        .mlp_current_layer_in(mlp_current_layer_out),
        .mlp_layer_complete_in(mlp_layer_complete_out),
        .mlp_acc0_in(mlp_acc0_out),
        .mlp_acc1_in(mlp_acc1_out),
        .mlp_acc_valid_in(mlp_acc_valid_out)
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

endmodule
