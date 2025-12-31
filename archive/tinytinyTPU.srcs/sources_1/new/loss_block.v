`timescale 1ns / 1ps
// Computes per-element L1 loss: |data_in - target_in|
module loss_block (
    input  wire        clk,
    input  wire        reset,
    input  wire        valid_in,
    input  wire signed [31:0] data_in,
    input  wire signed [31:0] target_in,
    output reg         valid_out,
    output reg signed [31:0] loss_out
);

    wire signed [31:0] diff = data_in - target_in;
    wire signed [31:0] abs_diff = diff[31] ? -diff : diff;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            loss_out  <= 32'sd0;
        end else begin
            valid_out <= valid_in;
            loss_out  <= abs_diff;
        end
    end
endmodule

