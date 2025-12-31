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

    // Wider product to hold intermediate result
    logic signed [47:0] mult;
    logic signed [47:0] shifted;

    assign mult = data_in * gain;
    assign shifted = mult >>> shift;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            data_out  <= 32'sd0;
        end else begin
            valid_out <= valid_in;
            data_out  <= shifted[31:0] + bias;
        end
    end

endmodule

