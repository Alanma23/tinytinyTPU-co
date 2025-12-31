`timescale 1ns / 1ps

module weight_fifo (
    input  logic       clk,
    input  logic       rst,
    input  logic       push,       // From DDR controller
    input  logic       pop,        // From MMU controller (during en_load_weight)
    input  logic [7:0] data_in,
    output logic [7:0] data_out
);

    logic [7:0] buffer [4]; // Tiny depth (4 deep)
    logic [1:0] wr_ptr, rd_ptr;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            wr_ptr <= 2'd0;
            rd_ptr <= 2'd0;
            data_out <= 8'd0;
        end else begin
            // Write (Push)
            if (push) begin
                buffer[wr_ptr] <= data_in;
                wr_ptr <= wr_ptr + 1'd1;
            end

            // Read (Pop) - Feeds the MMU Column
            if (pop) begin
                data_out <= buffer[rd_ptr];
                rd_ptr <= rd_ptr + 1'd1;
            end
        end
    end

endmodule

