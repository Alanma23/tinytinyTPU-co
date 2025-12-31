module accumulator_mem #(
    parameter BYPASS_READ_NEW = 1 // 1: output newly written value same cycle
) (
	input wire clk,
	input wire reset,
	
	input wire enable, // valid data
	input wire accumulator_mode, // 0/1 overwrite/add
	input wire buffer_select, // double buffer selection
	
	input wire [15:0] in_col0,
	input wire [15:0] in_col1,
	
	output reg valid_out,
	output reg signed [31:0] out_col0,
	output reg signed [31:0] out_col1
);

	// 2 x 2 x 32 bits
    reg signed [31:0] mem_buff0_col0;
    reg signed [31:0] mem_buff0_col1;
    reg signed [31:0] mem_buff1_col0;
    reg signed [31:0] mem_buff1_col1;
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            valid_out <= 0;
            out_col0 <= 0;
            out_col1 <= 0;
            mem_buff0_col0 <= 0;
            mem_buff0_col1 <= 0 ;
            mem_buff1_col0 <= 0;
            mem_buff1_col1 <= 0 ;
            end
            
            else begin
            if (enable) begin
                case (buffer_select)
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
                valid_out <= 1;
            end 
            else begin
                valid_out <= 0;
            end
        end
    end  
    
endmodule