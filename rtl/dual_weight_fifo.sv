`timescale 1ns / 1ps

module dual_weight_fifo (
    input  logic       clk,
    input  logic       reset,
    // Push interface
    // Simulates a narrow bus filling multiple columns
    input  logic       push_col0,
    input  logic       push_col1,
    input  logic [7:0] data_in, // Shared Data Bus
    // Pop interface
    // The MMU loads weights with column staggering
    input  logic       pop,
    output logic [7:0] col0_out,      // Direct output (combinational, no skew)
    output logic [7:0] col1_out,      // Skewed output (1-cycle delay for diagonal wavefront)
    // Raw outputs (for debugging/monitoring)
    output logic [7:0] col1_raw       // Pre-skew col1 value (for debugging)
);

    // Two 4-deep queues (initialized for simulation and proper synthesis)
    logic [7:0] queue0 [4] = '{8'd0, 8'd0, 8'd0, 8'd0};
    logic [7:0] queue1 [4] = '{8'd0, 8'd0, 8'd0, 8'd0};

    // Pointers for read/write (initialized for deterministic behavior)
    logic [1:0] wr_ptr0 = 2'd0, rd_ptr0 = 2'd0;
    logic [1:0] wr_ptr1 = 2'd0, rd_ptr1 = 2'd0;

    // Column 0: Combinational read (no skew, no latency)
    assign col0_out = queue0[rd_ptr0];

    // Column 1 raw value (pre-skew, for debugging)
    assign col1_raw = queue1[rd_ptr1];

    always_ff @(posedge clk) begin
        if (reset) begin
            wr_ptr0 <= 2'd0;
            rd_ptr0 <= 2'd0;
            wr_ptr1 <= 2'd0;
            rd_ptr1 <= 2'd0;
            col1_out <= 8'd0;
        end else begin
            // Column 0: Push and Pop (no skew)
            if (push_col0) begin
                queue0[wr_ptr0] <= data_in;
                wr_ptr0 <= wr_ptr0 + 1'd1;
            end
            if (pop) begin
                rd_ptr0 <= rd_ptr0 + 1'd1;
            end

            // Column 1: Push and Pop with 1-cycle skew
            // The skew register delays col1 output by 1 cycle for diagonal wavefront
            if (push_col1) begin
                queue1[wr_ptr1] <= data_in;
                wr_ptr1 <= wr_ptr1 + 1'd1;
            end
            if (pop) begin
                // Output current queue value (this is the 1-cycle delayed value)
                col1_out <= queue1[rd_ptr1];
                rd_ptr1 <= rd_ptr1 + 1'd1;
            end
        end
    end

endmodule

