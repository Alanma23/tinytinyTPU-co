`timescale 1ns / 1ps

module weight_fifo (
    input wire clk,
    input wire rst,
    input wire push,       // From DDR controller
    input wire pop,        // From MMU controller (during en_load_weight)
    input wire [7:0] data_in,
    output reg [7:0] data_out
);

    reg [7:0] buffer [0:3]; // Tiny depth (4 deep)
    reg [1:0] wr_ptr, rd_ptr;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            wr_ptr <= 0;
            rd_ptr <= 0;
            data_out <= 0;
        end else begin
            // Write (Push)
            if (push) begin
                buffer[wr_ptr] <= data_in;
                wr_ptr <= wr_ptr + 1;
            end
            
            // Read (Pop) - Feeds the MMU Column
            if (pop) begin
                data_out <= buffer[rd_ptr];
                rd_ptr <= rd_ptr + 1;
            end
        end
    end
endmodule
