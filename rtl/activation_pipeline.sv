`timescale 1ns / 1ps

// Top-level activation pipeline: Accumulator -> Activation -> Normalization -> Loss -> Quantize -> Unified Buffer input
module activation_pipeline (
    input  logic        clk,
    input  logic        reset,
    input  logic        valid_in,
    input  logic signed [31:0] acc_in,       // from accumulator
    input  logic signed [31:0] target_in,    // optional target for loss (set to 0 if unused)

    // Configuration
    input  logic signed [15:0] norm_gain,
    input  logic signed [31:0] norm_bias,
    input  logic [4:0]  norm_shift,
    input  logic signed [15:0] q_inv_scale, // 1/S in Q8.8
    input  logic signed [7:0] q_zero_point,

    // Outputs
    output logic        valid_out,
    output logic signed [7:0] ub_data_out,   // to unified buffer
    output logic        loss_valid,
    output logic signed [31:0] loss_out
);

    // Stage 1: Activation
    logic        s1_valid;
    logic signed [31:0] s1_data;
    logic signed [31:0] target_d1;

    activation_func act_u (
        .clk(clk),
        .reset(reset),
        .valid_in(valid_in),
        .data_in(acc_in),
        .valid_out(s1_valid),
        .data_out(s1_data)
    );

    // Align target with pipeline (normalizer adds one cycle)
    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            target_d1 <= 32'sd0;
        else if (valid_in)
            target_d1 <= target_in;
    end

    // Stage 2: Normalization
    logic        s2_valid;
    logic signed [31:0] s2_data;

    normalizer norm_u (
        .clk(clk),
        .reset(reset),
        .valid_in(s1_valid),
        .data_in(s1_data),
        .gain(norm_gain),
        .bias(norm_bias),
        .shift(norm_shift),
        .valid_out(s2_valid),
        .data_out(s2_data)
    );

    // Stage 3a: Loss (in parallel with quantization)
    loss_block loss_u (
        .clk(clk),
        .reset(reset),
        .valid_in(s2_valid),
        .data_in(s2_data),
        .target_in(target_d1),
        .valid_out(loss_valid),
        .loss_out(loss_out)
    );

    // Stage 3b: Quantization to UB (inlined affine quantization)
    // x_q = clip( round(x * (1/S)) + Z , -128, 127 )
    logic signed [7:0] ub_q_reg;
    logic valid_reg;

    logic signed [47:0] mult;
    logic signed [47:0] mult_rounded;
    logic signed [31:0] scaled;
    logic signed [31:0] biased;

    assign mult = s2_data * q_inv_scale;              // 32x16 -> 48
    assign mult_rounded = mult + 48'sd128;            // +0.5 * 2^8 for nearest
    assign scaled = 32'(mult_rounded >>> 8);          // back to Q0
    assign biased = scaled + {{24{q_zero_point[7]}}, q_zero_point};

    // Saturation function
    function automatic logic signed [7:0] sat_int8(input logic signed [31:0] val);
        if (val > 32'sd127)
            return 8'sd127;
        else if (val < -32'sd128)
            return -8'sd128;
        else
            return val[7:0];
    endfunction

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_reg <= 1'b0;
            ub_q_reg  <= 8'sd0;
        end else begin
            valid_reg <= s2_valid;
            ub_q_reg  <= sat_int8(biased);
        end
    end

    assign valid_out   = valid_reg;
    assign ub_data_out = ub_q_reg;

endmodule

