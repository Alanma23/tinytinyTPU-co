`timescale 1ns / 1ps

module mmu_tb;

    reg clk, reset, en_load_weight;
    reg [7:0] row0_in, row1_in; 
    reg [7:0] col0_in, col1_in; 

    // Outputs
    wire [15:0] acc0_out, acc1_out;

    mmu uut (
        .clk(clk), 
        .reset(reset), 
        .en_load_weight(en_load_weight), 
        .row0_in(row0_in), .row1_in(row1_in), 
        .col0_in(col0_in), .col1_in(col1_in), 
        .acc0_out(acc0_out), .acc1_out(acc1_out)
    );

    // Clock Generation (10ns period)
    always #5 clk = ~clk;

    // --- WATCHDOG TIMER (SafetyNet) ---
    // This runs in parallel. If the main test hangs, this kills it after 500ns.
    initial begin
        #500; 
        $display("ERROR: Watchdog Timeout! Simulation ran too long.");
        $finish;
    end

    
    initial begin
        // --- Initialize ---
        clk = 0; reset = 1; en_load_weight = 0;
        row0_in = 0; row1_in = 0;
        col0_in = 0; col1_in = 0;
        
        #10 reset = 0; 

        // --- Phase 1: Load Weights ---
        en_load_weight = 1;
        // Bottom Row (3, 4)
        col0_in = 3; col1_in = 4;
        #10; 
        // Top Row (1, 2)
        col0_in = 1; col1_in = 2;
        #10;

        en_load_weight = 0;
        col0_in = 0; col1_in = 0;

        // --- Phase 2: Stream Data ---
        // Matrix X = [[10, 20], [30, 40]]
        
        // T=0 (30ns): Row 0 gets X[0,0] (10).
        row0_in = 10; row1_in = 0; 
        #10;

        // T=1 (40ns): Row 0 gets X[1,0] (30). Row 1 gets X[0,1] (20).
        row0_in = 30; row1_in = 20;
        
        // CHECK COL 0 (Expected 70) 
        // Valid Window: 45ns -> 55ns. We check at 40+6 = 46ns.
        #6; 
        if (acc0_out == 70) $display("SUCCESS: Col 0 Result is 70");
        else $display("FAIL: Col 0 Result is %d (Expected 70)", acc0_out);
        #4; // Finish the 10ns cycle

        // T=2 (50ns): Row 0 gets 0. Row 1 gets X[1,1] (40).
        row0_in = 0;  row1_in = 40;
        
        // CHECK COL 1 (Expected 100)
        // Valid Window: 55ns -> 65ns. We check at 50+6 = 56ns.
        #6; 
        if (acc1_out == 100) $display("SUCCESS: Col 1 Result is 100");
        else $display("FAIL: Col 1 Result is %d (Expected 100)", acc1_out);
        #4;

        // T=3: Flush
        row0_in = 0;  row1_in = 0;
        #10;
        
        $display("Simulation Finished.");
        $finish;
    end

endmodule