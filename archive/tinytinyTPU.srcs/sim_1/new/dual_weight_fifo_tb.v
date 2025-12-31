`timescale 1ns / 1ps

// column staggering: verify that col1_out is delayed by 1 cycle relative to col0_out
// to create the diagonal wavefront for systolic weight loading
module dual_weight_fifo_tb;

    reg clk, reset;
    reg push_col0, push_col1;
    reg [7:0] data_in;
    reg pop;
    wire [7:0] col0_out, col1_out;
    wire [7:0] col1_raw;
    
    integer errors = 0;

    dual_weight_fifo uut (
        .clk(clk), .reset(reset),
        .push_col0(push_col0), .push_col1(push_col1),
        .data_in(data_in),
        .pop(pop),
        .col0_out(col0_out), .col1_out(col1_out),
        .col1_raw(col1_raw)
    );

    always #5 clk = ~clk;

    initial begin
        clk = 0; reset = 1;
        push_col0 = 0; push_col1 = 0;
        pop = 0; data_in = 0;
        
        #10 reset = 0;

        // PHASE 1: LOAD WEIGHT MATRIX
        // Weight Matrix W = [[1, 2], [3, 4]]
        // Load order: bottom row first (3, 4), then top row (1, 2)
        $display("=== Loading Weight Matrix ===");
        $display("W = [[1, 2], [3, 4]]");
        $display("Load order: bottom row first, then top row");

        // Push Column 0: [3, 1] (bottom to top)
        push_col0 = 1; data_in = 3; #10; // W10
        push_col0 = 0; #10;
        push_col0 = 1; data_in = 1; #10; // W00
        push_col0 = 0; #10;

        // Push Column 1: [4, 2] (bottom to top)
        push_col1 = 1; data_in = 4; #10; // W11
        push_col1 = 0; #10;
        push_col1 = 1; data_in = 2; #10; // W01
        push_col1 = 0; #10;

        // PHASE 2: POP WITH STAGGERED OUTPUT
        // Col0 is immediate, Col1 is delayed by 1 cycle
        // This matches the systolic diagonal wavefront
        $display("");
        $display("=== Popping with Column Staggering ===");
        $display("Expected: Col0 immediate, Col1 delayed by 1 cycle");
        $display("");
        
        // Pop cycle 1: Col0 gets first value (3), Col1 still 0 (skew delay)
        pop = 1;
        #10;
        $display("Cycle 1: col0_out=%d (exp 3), col1_out=%d (exp 0, skew delay), col1_raw=%d", 
                 col0_out, col1_out, col1_raw);
        if (col0_out != 3) begin
            $display("  FAIL: col0_out expected 3, got %d", col0_out);
            errors = errors + 1;
        end else $display("  PASS: col0_out correct");
        
        if (col1_out != 0) begin
            $display("  FAIL: col1_out expected 0 (skew delay), got %d", col1_out);
            errors = errors + 1;
        end else $display("  PASS: col1_out correctly delayed");

        // Pop cycle 2: Col0 gets second value (1), Col1 gets first value (4, delayed)
        #10;
        $display("Cycle 2: col0_out=%d (exp 1), col1_out=%d (exp 4, from prev cycle)", 
                 col0_out, col1_out);
        if (col0_out != 1) begin
            $display("  FAIL: col0_out expected 1, got %d", col0_out);
            errors = errors + 1;
        end else $display("  PASS: col0_out correct");
        
        if (col1_out != 4) begin
            $display("  FAIL: col1_out expected 4, got %d", col1_out);
            errors = errors + 1;
        end else $display("  PASS: col1_out correct (delayed)");

        // Pop cycle 3: Col0 exhausted (repeats), Col1 gets second value (2, delayed)
        #10;
        $display("Cycle 3: col0_out=%d (exhausted), col1_out=%d (exp 2, from prev cycle)", 
                 col0_out, col1_out);
        if (col1_out != 2) begin
            $display("  FAIL: col1_out expected 2, got %d", col1_out);
            errors = errors + 1;
        end else $display("  PASS: col1_out correct (delayed)");

        pop = 0;
        #10;
        $finish;
    end
endmodule