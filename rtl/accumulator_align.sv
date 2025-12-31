`timescale 1ns / 1ps

module accumulator_align (
    input  logic        clk,
    input  logic        reset,

    input  logic        valid_in,
    input  logic [15:0] raw_col0,
    input  logic [15:0] raw_col1,

    output logic        aligned_valid,
    output logic [15:0] align_col0,
    output logic [15:0] align_col1
);

    // Column 0 delay register to align with column 1 (which arrives 1 cycle later
    // for the same result row due to horizontal activation propagation in systolic array)
    logic [15:0] col0_delay_reg;
    logic pending;  // True after first capture, enables output on subsequent valids

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            col0_delay_reg <= 16'd0;
            pending <= 1'b0;
            aligned_valid <= 1'b0;
            align_col0 <= 16'd0;
            align_col1 <= 16'd0;
        end
        else begin
            aligned_valid <= 1'b0;

            if (valid_in) begin
                if (!pending) begin
                    // First valid: capture col0 for pairing with next cycle's col1
                    col0_delay_reg <= raw_col0;
                    pending <= 1'b1;
                end else begin
                    // Subsequent valids: output aligned pair AND capture new col0
                    aligned_valid <= 1'b1;
                    align_col0 <= col0_delay_reg;  // Previous cycle's col0
                    align_col1 <= raw_col1;         // Current cycle's col1
                    col0_delay_reg <= raw_col0;     // Capture current col0 for next pair
                    // pending stays 1 for continuous streaming
                end
            end else begin
                // No valid input - reset pending for next batch
                pending <= 1'b0;
            end
        end
    end

endmodule

