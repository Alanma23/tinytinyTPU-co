`timescale 1ns / 1ps
// Simple activation block with selectable function.
// DEFAULT_ACT: 00=passthrough, 01=ReLU, 10=ReLU6 (clamps to 6)
module activation_func #(
    parameter [1:0] DEFAULT_ACT = 2'b01
) (
    input  wire        clk,
    input  wire        reset,
    input  wire        valid_in,
    input  wire signed [31:0] data_in,
    output reg         valid_out,
    output reg signed [31:0] data_out
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            data_out  <= 32'sd0;
        end else begin
            valid_out <= valid_in;
            case (DEFAULT_ACT)
                2'b00: data_out <= data_in;                          // passthrough
                2'b01: data_out <= data_in[31] ? 32'sd0 : data_in;   // ReLU
                2'b10: begin                                         // ReLU6 (clamp to 6)
                    if (data_in[31])       data_out <= 32'sd0;
                    else if (data_in > 32'sd6) data_out <= 32'sd6;
                    else                   data_out <= data_in;
                end
                default: data_out <= data_in;
            endcase
        end
    end
endmodule

