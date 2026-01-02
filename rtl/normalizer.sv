`timescale 1ns / 1ps

// Fixed-point normalization: (data_in * gain) >> shift + bias
// gain is signed Qm.n; shift controls right shift to rescale.
module normalizer (
    input  logic        clk,
    input  logic        reset,
    input  logic        valid_in,
    input  logic signed [31:0] data_in,
    input  logic signed [15:0] gain,
    input  logic signed [31:0] bias,
    input  logic [4:0]  shift,
    output logic        valid_out,
    output logic signed [31:0] data_out
);

    // Stage 1: capture operands
    logic        s1_valid;
    logic signed [31:0] data_in_d;
    logic signed [15:0] gain_d;
    logic signed [31:0] bias_d;
    logic [4:0]         shift_d;

    always_ff @(posedge clk) begin
        if (reset) begin
            s1_valid   <= 1'b0;
            data_in_d  <= '0;
            gain_d     <= '0;
            bias_d     <= '0;
            shift_d    <= '0;
        end else begin
            s1_valid   <= valid_in;
            data_in_d  <= data_in;
            gain_d     <= gain;
            bias_d     <= bias;
            shift_d    <= shift;
        end
    end

    // Stage 2: multiply (maps cleanly into DSP with registered inputs)
    logic        s2_valid;
    (* use_dsp = "yes" *) logic signed [47:0] mult_raw;
    (* keep = "true" *) logic signed [47:0] mult_res;
    logic signed [31:0] bias_d1;
    logic [4:0]         shift_d1;

    always_ff @(posedge clk) begin
        if (reset) begin
            s2_valid  <= 1'b0;
            mult_raw  <= '0;
            mult_res  <= '0;
            bias_d1   <= '0;
            shift_d1  <= '0;
        end else begin
            s2_valid  <= s1_valid;
            mult_raw  <= data_in_d * gain_d;
            mult_res  <= mult_raw;  // Register DSP output
            bias_d1   <= bias_d;
            shift_d1  <= shift_d;
        end
    end

    // Stage 3: shift + bias and present output
    logic        s3_valid;
    logic signed [47:0] shifted_res;
    logic signed [31:0] bias_d2;

    always_ff @(posedge clk) begin
        if (reset) begin
            s3_valid  <= 1'b0;
            shifted_res <= '0;
            bias_d2   <= '0;
        end else begin
            s3_valid  <= s2_valid;
            shifted_res <= mult_res >>> shift_d1;  // Registered shift
            bias_d2   <= bias_d1;
        end
    end

    always_ff @(posedge clk) begin
        if (reset) begin
            valid_out <= 1'b0;
            data_out  <= 32'd0;
        end else begin
            valid_out <= s3_valid;
            data_out  <= shifted_res[31:0] + bias_d2;
        end
    end

endmodule
