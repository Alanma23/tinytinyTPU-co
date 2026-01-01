`timescale 1ns / 1ps

// TPU Bridge - Connects UART Controller to MLP Top
// Handles signal routing and provides default activation pipeline configuration

module tpu_bridge (
    input  logic        clk,

    // UART Controller → MLP (pass-through)
    input  logic        ctrl_wf_push_col0,
    input  logic        ctrl_wf_push_col1,
    input  logic [7:0]  ctrl_wf_data_in,
    input  logic        ctrl_wf_reset,
    input  logic        ctrl_init_act_valid,
    input  logic [15:0] ctrl_init_act_data,
    input  logic        ctrl_start_mlp,
    input  logic        ctrl_weights_ready,

    // MLP → UART Controller (pass-through)
    output logic [3:0]  mlp_state,
    output logic [4:0]  mlp_cycle_cnt,
    output logic signed [31:0] mlp_acc0,

    // MLP Top interface
    output logic        mlp_wf_push_col0,
    output logic        mlp_wf_push_col1,
    output logic [7:0]  mlp_wf_data_in,
    output logic        mlp_wf_reset,
    output logic        mlp_init_act_valid,
    output logic [15:0] mlp_init_act_data,
    output logic        mlp_start_mlp,
    output logic        mlp_weights_ready,
    output logic [2:0]  mlp_vpu_activation_type, // VPU activation function
    output logic signed [15:0] mlp_norm_gain,
    output logic signed [31:0] mlp_norm_bias,
    output logic [4:0]  mlp_norm_shift,
    output logic signed [15:0] mlp_q_inv_scale,
    output logic signed [7:0]  mlp_q_zero_point,

    input  logic [3:0]  mlp_state_in,
    input  logic [4:0]  mlp_cycle_cnt_in,
    input  logic signed [31:0] mlp_acc0_in
);

    // Pass-through: UART Controller → MLP
    assign mlp_wf_push_col0 = ctrl_wf_push_col0;
    assign mlp_wf_push_col1 = ctrl_wf_push_col1;
    assign mlp_wf_data_in = ctrl_wf_data_in;
    assign mlp_wf_reset = ctrl_wf_reset;
    assign mlp_init_act_valid = ctrl_init_act_valid;
    assign mlp_init_act_data = ctrl_init_act_data;
    assign mlp_start_mlp = ctrl_start_mlp;
    assign mlp_weights_ready = ctrl_weights_ready;

    // #region agent log
    always_ff @(posedge clk) begin
        if (ctrl_start_mlp)
            $display("[TPU_BRIDGE] ctrl_start_mlp=1, passing to mlp_start_mlp=%b, mlp_state_in=%d", mlp_start_mlp, mlp_state_in);
    end
    // #endregion

    // Default activation pipeline configuration
    // Default to ReLU activation (001)
    assign mlp_vpu_activation_type = 3'b001;  // ReLU by default
    assign mlp_norm_gain = 16'sd256;      // 1.0 in Q8 format
    assign mlp_norm_bias = 32'sd0;        // No bias
    assign mlp_norm_shift = 5'd8;         // Shift back by 8 to undo Q8
    assign mlp_q_inv_scale = 16'sd256;    // 1.0 scale
    assign mlp_q_zero_point = 8'sd0;      // No zero point

    // Pass-through: MLP → UART Controller
    assign mlp_state = mlp_state_in;
    assign mlp_cycle_cnt = mlp_cycle_cnt_in;
    assign mlp_acc0 = mlp_acc0_in;

endmodule
