`timescale 1ns / 1ps

module accumulator_tb;
    reg clk, reset;
    // Inputs
    reg valid_in;
    reg accum_en;
    reg addr_sel;
    reg [15:0] mmu_col0_in, mmu_col1_in;
    
    // Outputs
    wire [31:0] out0, out1;
    wire valid_out;

    accumulator uut (
        .clk(clk), .reset(reset),
        .valid_in(valid_in),
        .accumulator_enable(accum_en),
        .addr_sel(addr_sel),
        .mmu_col0_in(mmu_col0_in),
        .mmu_col1_in(mmu_col1_in),
        .acc_col0_out(out0), .acc_col1_out(out1),
        .valid_out(valid_out)
    );

    always #5 clk = ~clk;

    initial begin
        clk = 0; reset = 1;
        valid_in = 0; accum_en = 0; addr_sel = 0;
        mmu_col0_in = 0; mmu_col1_in = 0;
        
        #10 reset = 0;

        // --- TEST 1: FIRST WAVE (Overwrite Mode) ---
        // Staggered Input: Col 0 arrives at T, Col 1 at T+1
        $display("--- Test 1: First Wave (Value 100, 200) ---");
        
        // T=0: Col 0 arrives (Value 100)
        valid_in = 1; 
        accum_en = 0; // Overwrite
        mmu_col0_in = 16'd100;
        mmu_col1_in = 16'd0; // Should be ignored by deskewer logic
        #10;
        
        // T=1: Col 1 arrives (Value 200)
        // Note: valid_in can stay high if streaming, or pulse. 
        // Let's assume pulsed for single shot test.
        valid_in = 0; 
        mmu_col0_in = 0;
        mmu_col1_in = 16'd200;
        #10;
        
        // T=2: Wait for Alignment delay + Memory delay
        #10;
        
        if (out0 == 32'd100 && out1 == 32'd200) 
            $display("PASS: Data Aligned and Stored correctly.");
        else 
            $display("FAIL: Got %d, %d (Exp 100, 200)", out0, out1);


        // --- TEST 2: SECOND WAVE (Accumulate Mode) ---
        // Add 50 to both cols.
        $display("--- Test 2: Accumulate (+50) ---");
        
        // T=10: Col 0 arrives (50)
        valid_in = 1;
        accum_en = 1; // ENABLE ACCUMULATION
        mmu_col0_in = 16'd50;
        mmu_col1_in = 0;
        #10;
        
        // T=11: Col 1 arrives (50)
        valid_in = 0;
        mmu_col0_in = 0;
        mmu_col1_in = 16'd50;
        #10;
        
        // T=12: Check results
        #10;
        
        // Expected: 100+50=150, 200+50=250
        if (out0 == 32'd150 && out1 == 32'd250) 
            $display("PASS: Accumulation Logic Correct.");
        else 
            $display("FAIL: Got %d, %d (Exp 150, 250)", out0, out1);

        $finish;
    end

endmodule