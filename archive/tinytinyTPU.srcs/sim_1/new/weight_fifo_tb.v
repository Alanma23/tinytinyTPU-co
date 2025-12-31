`timescale 1ns / 1ps

module weight_fifo_tb;

    reg clk, rst;
    reg push, pop;
    reg [7:0] data_in;
    wire [7:0] data_out;

    weight_fifo uut (
        .clk(clk),
        .rst(rst),
        .push(push),
        .pop(pop),
        .data_in(data_in),
        .data_out(data_out)
    );

    // Clock Generation
    always #5 clk = ~clk;

    initial begin
        // Initialize Inputs
        clk = 0; rst = 1;
        push = 0; pop = 0;
        data_in = 0;

        // Reset the FIFO
        #10 rst = 0;

        // --- TEST CASE 1: PUSH DATA ---
        $display("--- Filling FIFO ---");
        
        // Push 10
        push = 1; data_in = 10;
        #10;
        
        // Push 20
        data_in = 20;
        #10;

        // Push 30
        data_in = 30;
        #10;
        
        // Stop pushing
        push = 0; data_in = 0;
        #10;

        // --- TEST CASE 2: POP DATA ---
        $display("--- Emptying FIFO ---");
        
        // Pop 1st value (Should be 10)
        pop = 1;
        #10;
        if (data_out == 10) $display("PASS: Got 10");
        else $display("FAIL: Expected 10, Got %d", data_out);

        // Pop 2nd value (Should be 20)
        #10;
        if (data_out == 20) $display("PASS: Got 20");
        else $display("FAIL: Expected 20, Got %d", data_out);

        // Pop 3rd value (Should be 30)
        #10;
        if (data_out == 30) $display("PASS: Got 30");
        else $display("FAIL: Expected 30, Got %d", data_out);

        // Stop popping
        pop = 0;
        #10;

        $finish;
    end

endmodule