`timescale 1ns / 1ps

// Simple synchronous unified buffer (byte-wide FIFO) to capture activation pipeline output.
// Integrates via ready/valid on the write side; provides ready/valid on the read side.
// Uses combinational read output for zero-latency data access.
module unified_buffer #(
    parameter int WIDTH = 8,
    parameter int DEPTH = 256,
    parameter int ADDR_W = $clog2(DEPTH)
) (
    input  logic                 clk,
    input  logic                 reset,

    // Write side (from activation_pipeline)
    input  logic                 wr_valid,
    input  logic [WIDTH-1:0]     wr_data,
    output logic                 wr_ready,

    // Read side (to systolic / consumer)
    input  logic                 rd_ready,
    output logic                 rd_valid,
    output logic [WIDTH-1:0]     rd_data,

    // Status
    output logic                 full,
    output logic                 empty,
    output logic [ADDR_W:0]      count
);

    logic [WIDTH-1:0] mem [DEPTH];
    logic [ADDR_W-1:0] wr_ptr;
    logic [ADDR_W-1:0] rd_ptr;

    assign full  = (count == (ADDR_W+1)'(DEPTH));
    assign empty = (count == '0);
    assign wr_ready = ~full;

    // Combinational read output (zero latency)
    assign rd_data  = mem[rd_ptr];
    assign rd_valid = ~empty & rd_ready;

    // Track simultaneous read and write for count update
    logic do_write;
    logic do_read;

    assign do_write = wr_valid && wr_ready;
    assign do_read  = rd_ready && ~empty;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            wr_ptr <= '0;
            rd_ptr <= '0;
            count  <= '0;
        end else begin
            // Write path
            if (do_write) begin
                mem[wr_ptr] <= wr_data;
                wr_ptr <= wr_ptr + 1'd1;
            end

            // Read path (just advance pointer, data is combinational)
            if (do_read) begin
                rd_ptr <= rd_ptr + 1'd1;
            end

            // Update count based on read/write activity
            if (do_write && !do_read)
                count <= count + 1'd1;
            else if (do_read && !do_write)
                count <= count - 1'd1;
            // else: simultaneous read/write or neither - count unchanged
        end
    end

endmodule

