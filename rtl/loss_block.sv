`timescale 1ns / 1ps

// Computes per-element L1 loss: |data_in - target_in|
module loss_block (
    input  logic        clk,
    input  logic        reset,
    input  logic        valid_in,
    input  logic signed [31:0] data_in,
    input  logic signed [31:0] target_in,
    output logic        valid_out,
    output logic signed [31:0] loss_out
);

    logic signed [31:0] diff;
    logic signed [31:0] abs_diff;

    assign diff = data_in - target_in;
    assign abs_diff = diff[31] ? -diff : diff;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            loss_out  <= 32'sd0;
        end else begin
            valid_out <= valid_in;
            loss_out  <= abs_diff;
        end
    end

endmodule

