`timescale 1ns / 1ps
// Simple synchronous unified buffer (byte-wide FIFO) to capture activation pipeline output.
// Integrates via ready/valid on the write side; provides ready/valid on the read side.
// Uses combinational read output for zero-latency data access.
module unified_buffer #(
    parameter WIDTH = 8,
    parameter DEPTH = 256,
    parameter ADDR_W = $clog2(DEPTH)
) (
    input  wire                 clk,
    input  wire                 reset,

    // Write side (from activation_pipeline)
    input  wire                 wr_valid,
    input  wire [WIDTH-1:0]     wr_data,
    output wire                 wr_ready,

    // Read side (to systolic / consumer)
    input  wire                 rd_ready,
    output wire                 rd_valid,
    output wire [WIDTH-1:0]     rd_data,

    // Status
    output wire                 full,
    output wire                 empty,
    output reg  [ADDR_W:0]      count
);

    reg [WIDTH-1:0] mem [0:DEPTH-1];
    reg [ADDR_W-1:0] wr_ptr;
    reg [ADDR_W-1:0] rd_ptr;

    assign full  = (count == DEPTH);
    assign empty = (count == 0);
    assign wr_ready = ~full;
    
    // Combinational read output (zero latency)
    assign rd_data  = mem[rd_ptr];
    assign rd_valid = ~empty & rd_ready;

    // Track simultaneous read and write for count update
    wire do_write = wr_valid && wr_ready;
    wire do_read  = rd_ready && ~empty;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            wr_ptr   <= {ADDR_W{1'b0}};
            rd_ptr   <= {ADDR_W{1'b0}};
            count    <= {ADDR_W+1{1'b0}};
        end else begin
            // Write path
            if (do_write) begin
                mem[wr_ptr] <= wr_data;
                wr_ptr <= wr_ptr + 1'b1;
            end

            // Read path (just advance pointer, data is combinational)
            if (do_read) begin
                rd_ptr <= rd_ptr + 1'b1;
            end
            
            // Update count based on read/write activity
            if (do_write && !do_read)
                count <= count + 1'b1;
            else if (do_read && !do_write)
                count <= count - 1'b1;
            // else: simultaneous read/write or neither - count unchanged
        end
    end
endmodule

