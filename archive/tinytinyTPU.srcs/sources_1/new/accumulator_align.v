module accumulator_align (
	input wire clk,
	input wire reset,
	
	input wire valid_in,
	input wire [15:0] raw_col0,
	input wire [15:0] raw_col1,
	
	output reg aligned_valid,
	output reg [15:0] align_col0,
	output reg [15:0] align_col1
);

	// Column 0 delay register to align with column 1 (which arrives 1 cycle later
	// for the same result row due to horizontal activation propagation in systolic array)
	reg [15:0] col0_delay_reg;
	reg pending;  // True after first capture, enables output on subsequent valids
	
	always @(posedge clk or posedge reset) begin
		if(reset) begin
			col0_delay_reg <= 0;
			pending <= 0;
			aligned_valid <= 0;
			align_col0 <= 0;
			align_col1 <= 0;
		end 
		else begin
			aligned_valid <= 0;

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