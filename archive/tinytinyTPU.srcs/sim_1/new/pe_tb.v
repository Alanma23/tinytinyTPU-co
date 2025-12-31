`timescale 1ns / 1ps


module pe_tb;
    reg clk, reset, en_load_weight;
	reg [7:0] in_act;
	reg [15:0] in_psum;
    wire [7:0] out_act;
    wire [15:0] out_psum;
  
  pe dut ( 
        .clk(clk),
        .reset(reset),
        .en_load_weight(en_load_weight),
        .in_act(in_act),
        .in_psum(in_psum),
        .out_act(out_act),
        .out_psum(out_psum)
  );
  
	always #5 clk = ~clk;
	
	initial begin
		// initial reset
		clk = 0;
		reset = 1;
		en_load_weight = 0;
		in_act = 0;
		in_psum = 0;
		#10 reset = 0;
		
		
		// load weights
		$display("Load Weights");
		en_load_weight = 1;
		in_psum = 16'd5;
		#10;
		
		if (out_psum !== 16'd5) begin
            $display("FAILED: weight pass-through. Expected 5, got %d", out_psum);
        end else begin
            $display("PASSED: weight pass-through");
        end
		
		
		// compute check e.g. activation = 2; top sum = 10;
		en_load_weight = 0;
		in_act = 8'd2;
		in_psum = 16'd10;
		#10;
		
		if (out_psum !== 16'd20) begin
            $display("FAILED: calculation. Expected 20, got %d", out_psum);
        end else begin
            $display("PASSED: calculation, got value 20");
        end
		
		if (out_act !== 8'd2) begin
            $display("FAILED: activation propagation. Expected 2, got %d", out_act);
        end else begin
            $display("PASSED: activation propagation, got 2");
        end
	end
endmodule
