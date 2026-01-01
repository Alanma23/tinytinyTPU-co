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

    assign full  = (count == DEPTH[ADDR_W:0]);
    assign empty = (count == '0);
    assign wr_ready = ~full;

    // Registered read output to break critical path (adds 1 cycle latency)
    // Internal combinational signals for read data
    wire [WIDTH-1:0] rd_data_comb = mem[rd_ptr];
    wire             rd_valid_comb = ~empty;

    // Output registers for timing improvement
    logic [WIDTH-1:0] rd_data_reg;
    logic             rd_valid_reg;

    always_ff @(posedge clk) begin
        if (reset) begin
            rd_data_reg  <= '0;
            rd_valid_reg <= 1'b0;
        end else begin
            rd_data_reg  <= rd_data_comb;
            rd_valid_reg <= rd_valid_comb;
        end
    end

    assign rd_data  = rd_data_reg;
    assign rd_valid = rd_valid_reg;

    // Track simultaneous read and write for count update
    logic do_write;
    logic do_read;

    assign do_write = wr_valid && wr_ready;
    assign do_read  = rd_ready && ~empty;

    // Memory write (no reset - BRAM friendly)
    always_ff @(posedge clk) begin
        if (do_write) begin
            mem[wr_ptr] <= wr_data;
        end
    end

    // Control logic with synchronous reset
    always_ff @(posedge clk) begin
        if (reset) begin
            wr_ptr <= '0;
            rd_ptr <= '0;
            count  <= '0;
        end else begin
            // Write pointer
            if (do_write) begin
                wr_ptr <= wr_ptr + 1'd1;
            end

            // Read path (just advance pointer, data is combinational)
            if (do_read) begin
                rd_ptr <= rd_ptr + 1'd1;
            end

            // Update count based on read/write activity
            unique case ({do_write, do_read})
                2'b10: count <= count + 1'd1;   // write only
                2'b01: count <= count - 1'd1;   // read only
                default: /* simultaneous or idle */ count <= count;
            endcase
        end
    end

endmodule
