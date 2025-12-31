`timescale 1ns / 1ps
// Fixed-point normalization: (data_in * gain) >> shift + bias
// gain is signed Qm.n; shift controls right shift to rescale.
module normalizer (
    input  wire        clk,
    input  wire        reset,
    input  wire        valid_in,
    input  wire signed [31:0] data_in,
    input  wire signed [15:0] gain,
    input  wire signed [31:0] bias,
    input  wire [4:0]  shift,
    output reg         valid_out,
    output reg signed [31:0] data_out
);

    // Wider product to hold intermediate result
    wire signed [47:0] mult = data_in * gain;
    wire signed [47:0] shifted = mult >>> shift;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            data_out  <= 32'sd0;
        end else begin
            valid_out <= valid_in;
            data_out  <= shifted[31:0] + bias;
        end
    end
endmodule

