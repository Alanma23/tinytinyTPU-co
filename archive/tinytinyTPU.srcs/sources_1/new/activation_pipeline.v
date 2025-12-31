`timescale 1ns / 1ps
// Top-level activation pipeline: Accumulator -> Activation -> Normalization -> Loss -> Quantize -> Unified Buffer input
module activation_pipeline (
    input  wire        clk,
    input  wire        reset,
    input  wire        valid_in,
    input  wire signed [31:0] acc_in,       // from accumulator
    input  wire signed [31:0] target_in,    // optional target for loss (set to 0 if unused)

    // Configuration
    input  wire signed [15:0] norm_gain,
    input  wire signed [31:0] norm_bias,
    input  wire [4:0]  norm_shift,
    input  wire signed [15:0] q_inv_scale, // 1/S in Q8.8
    input  wire signed [7:0] q_zero_point,

    // Outputs
    output wire        valid_out,
    output wire signed [7:0] ub_data_out,   // to unified buffer
    output wire        loss_valid,
    output wire signed [31:0] loss_out
);

    // Stage 1: Activation
    wire        s1_valid;
    wire signed [31:0] s1_data;
    reg  signed [31:0] target_d1;

    activation_func act_u (
        .clk(clk),
        .reset(reset),
        .valid_in(valid_in),
        .data_in(acc_in),
        .valid_out(s1_valid),
        .data_out(s1_data)
    );

    // Align target with pipeline (normalizer adds one cycle)
    always @(posedge clk or posedge reset) begin
        if (reset) target_d1 <= 32'sd0;
        else if (valid_in) target_d1 <= target_in;
    end

    // Stage 2: Normalization
    wire        s2_valid;
    wire signed [31:0] s2_data;
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
    reg signed [7:0] ub_q_reg;
    reg valid_reg;

    wire signed [47:0] mult = s2_data * q_inv_scale;       // 32x16 -> 48
    wire signed [47:0] mult_rounded = mult + 48'sd128;     // +0.5 * 2^8 for nearest
    wire signed [31:0] scaled = mult_rounded >>> 8;        // back to Q0
    wire signed [31:0] biased = scaled + {{24{q_zero_point[7]}}, q_zero_point};

    function signed [7:0] sat_int8;
        input signed [31:0] val;
        begin
            if (val > 32'sd127)       sat_int8 = 8'sd127;
            else if (val < -32'sd128) sat_int8 = -8'sd128;
            else                      sat_int8 = val[7:0];
        end
    endfunction

    always @(posedge clk or posedge reset) begin
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

