`timescale 1ns / 1ps

module accumulator_mem #(
    parameter bit BYPASS_READ_NEW = 1'b1 // 1: output newly written value same cycle
) (
    input  logic        clk,
    input  logic        reset,

    input  logic        enable, // valid data
    input  logic        accumulator_mode, // 0/1 overwrite/add
    input  logic        buffer_select, // double buffer selection

    input  logic [15:0] in_col0,
    input  logic [15:0] in_col1,

    output logic        valid_out,
    output logic signed [31:0] out_col0,
    output logic signed [31:0] out_col1
);

    // 2 x 2 x 32 bits
    logic signed [31:0] mem_buff0_col0;
    logic signed [31:0] mem_buff0_col1;
    logic signed [31:0] mem_buff1_col0;
    logic signed [31:0] mem_buff1_col1;

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 1'b0;
            out_col0 <= 32'sd0;
            out_col1 <= 32'sd0;
            mem_buff0_col0 <= 32'sd0;
            mem_buff0_col1 <= 32'sd0;
            mem_buff1_col0 <= 32'sd0;
            mem_buff1_col1 <= 32'sd0;
        end
        else begin
            if (enable) begin
                unique case (buffer_select)
                    1'b0: begin // --- BUFFER 0 ---
                        if (accumulator_mode) begin
                            mem_buff0_col0 <= mem_buff0_col0 + $signed({16'b0, in_col0});
                            mem_buff0_col1 <= mem_buff0_col1 + $signed({16'b0, in_col1});
                        end else begin
                            mem_buff0_col0 <= $signed({16'b0, in_col0});
                            mem_buff0_col1 <= $signed({16'b0, in_col1});
                        end
                        if (BYPASS_READ_NEW) begin
                            out_col0 <= accumulator_mode ? (mem_buff0_col0 + $signed({16'b0, in_col0})) : $signed({16'b0, in_col0});
                            out_col1 <= accumulator_mode ? (mem_buff0_col1 + $signed({16'b0, in_col1})) : $signed({16'b0, in_col1});
                        end else begin
                            out_col0 <= mem_buff0_col0;
                            out_col1 <= mem_buff0_col1;
                        end
                    end

                    1'b1: begin // --- BUFFER 1 ---
                        if (accumulator_mode) begin
                            mem_buff1_col0 <= mem_buff1_col0 + $signed({16'b0, in_col0});
                            mem_buff1_col1 <= mem_buff1_col1 + $signed({16'b0, in_col1});
                        end else begin
                            mem_buff1_col0 <= $signed({16'b0, in_col0});
                            mem_buff1_col1 <= $signed({16'b0, in_col1});
                        end
                        if (BYPASS_READ_NEW) begin
                            out_col0 <= accumulator_mode ? (mem_buff1_col0 + $signed({16'b0, in_col0})) : $signed({16'b0, in_col0});
                            out_col1 <= accumulator_mode ? (mem_buff1_col1 + $signed({16'b0, in_col1})) : $signed({16'b0, in_col1});
                        end else begin
                            out_col0 <= mem_buff1_col0;
                            out_col1 <= mem_buff1_col1;
                        end
                    end
                endcase
                valid_out <= 1'b1;
            end
            else begin
                valid_out <= 1'b0;
            end
        end
    end

endmodule

