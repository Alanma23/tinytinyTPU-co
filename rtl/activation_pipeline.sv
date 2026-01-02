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
    always_ff @(posedge clk) begin
        if (reset)
            target_d1 <= 32'd0;
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
    // Pipeline the arithmetic to ease DSP timing
    logic signed [7:0] ub_q_reg;
    logic             valid_reg;

    // Stage 3b.1 - capture operands
    logic             q_s1_valid;
    logic signed [31:0] q_s1_data;
    logic signed [15:0] q_inv_scale_d0;
    logic signed [7:0]  q_zero_point_d0;

    always_ff @(posedge clk) begin
        if (reset) begin
            q_s1_valid      <= 1'b0;
            q_s1_data       <= '0;
            q_inv_scale_d0  <= '0;
            q_zero_point_d0 <= '0;
        end else begin
            q_s1_valid      <= s2_valid;
            q_s1_data       <= s2_data;
            q_inv_scale_d0  <= q_inv_scale;
            q_zero_point_d0 <= q_zero_point;
        end
    end

    // Stage 3b.2 - multiply via DSP
    logic             q_s2_valid;
    (* use_dsp = "yes" *) logic signed [47:0] mult_raw;
    (* keep = "true" *) logic signed [47:0] mult_reg;
    logic signed [7:0]  q_zero_point_d1;

    always_ff @(posedge clk) begin
        if (reset) begin
            q_s2_valid     <= 1'b0;
            mult_raw       <= '0;
            mult_reg       <= '0;
            q_zero_point_d1<= '0;
        end else begin
            q_s2_valid      <= q_s1_valid;
            mult_raw        <= q_s1_data * q_inv_scale_d0;  // 32x16 -> 48-bit
            mult_reg        <= mult_raw;  // Register DSP output
            q_zero_point_d1 <= q_zero_point_d0;
        end
    end

    // Stage 3b.3 - round and shift back to Q0
    logic             q_s3_valid;
    logic signed [31:0] scaled_reg;
    logic signed [7:0]  q_zero_point_d2;

    always_ff @(posedge clk) begin
        if (reset) begin
            q_s3_valid      <= 1'b0;
            scaled_reg      <= '0;
            q_zero_point_d2 <= '0;
        end else begin
            logic signed [47:0] mult_rounded;
            mult_rounded       = mult_reg + 48'd128; // +0.5 * 2^8 for nearest

            q_s3_valid      <= q_s2_valid;
            scaled_reg      <= 32'(mult_rounded >>> 8);
            q_zero_point_d2 <= q_zero_point_d1;
        end
    end

    // Stage 3b.4 - apply zero point / bias term
    logic             q_s4_valid;
    logic signed [31:0] biased_reg;

    always_ff @(posedge clk) begin
        if (reset) begin
            q_s4_valid <= 1'b0;
            biased_reg <= '0;
        end else begin
            q_s4_valid <= q_s3_valid;
            biased_reg <= scaled_reg + {{24{q_zero_point_d2[7]}}, q_zero_point_d2};
        end
    end

    // Saturation logic (Yosys-compatible, inlined instead of function)
    logic signed [7:0] sat_result;
    always_comb begin
        if (biased_reg > 127)
            sat_result = 8'd127;
        else if (biased_reg < -128)
            sat_result = -8'd128;
        else
            sat_result = biased_reg[7:0];
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            valid_reg <= 1'b0;
            ub_q_reg  <= 8'd0;
        end else begin
            valid_reg <= q_s4_valid;
            ub_q_reg  <= sat_result;
        end
    end

    assign valid_out   = valid_reg;
    assign ub_data_out = ub_q_reg;

endmodule
