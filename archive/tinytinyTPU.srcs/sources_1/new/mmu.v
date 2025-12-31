`timescale 1ns / 1ps
module mmu ( // for a 2x2 systolic array
    input wire clk,
    input wire reset,
    input wire en_weight_pass,      // Pass psum through all PEs (always during load phase)
    input wire en_capture_col0,     // Capture enable for column 0 PEs (PE00, PE10)
    input wire en_capture_col1,     // Capture enable for column 1 PEs (PE01, PE11)
    
    // UB activations input
    input wire [7:0] row0_in,
    input wire [7:0] row1_in,
    
    // Weight FIFO input
    input wire [7:0] col0_in,
    input wire [7:0] col1_in,
    
    // Accumulator output
    output wire [15:0] acc0_out,
    output wire [15:0] acc1_out
);

    // PE Layout:
    // pe00 -> pe01    Activations flow horizontally (right)
    //   |       |     
    //   v       v     Partial sums flow vertically (down)
    // pe10 -> pe11
    //   |       |
    //   v       v
    // acc0   acc1

    // Systolic array PE connections 
    wire [7:0] pe00_01_act, pe10_11_act;
    wire [15:0] pe00_10_psum, pe01_11_psum;

    pe pe00 (
        .clk(clk), 
        .reset(reset), 
        .en_weight_pass(en_weight_pass),
        .en_weight_capture(en_capture_col0),  // Column 0 capture timing
        .in_act(row0_in),         
        .in_psum({8'b0, col0_in}),     
        .out_act(pe00_01_act),
        .out_psum(pe00_10_psum)
    );

    pe pe01 (
        .clk(clk), 
        .reset(reset), 
        .en_weight_pass(en_weight_pass),
        .en_weight_capture(en_capture_col1),  // Column 1 capture timing (staggered)
        .in_act(pe00_01_act),   
        .in_psum({8'b0, col1_in}),      
        .out_act(), // Activation unconnected at edge of 2x2 array
        .out_psum(pe01_11_psum)
    );

    pe pe10 (
        .clk(clk), 
        .reset(reset), 
        .en_weight_pass(en_weight_pass),
        .en_weight_capture(en_capture_col0),  // Column 0 capture timing
        .in_act(row1_in),       
        .in_psum(pe00_10_psum), 
        .out_act(pe10_11_act),
        .out_psum(acc0_out)       // Output column 0 to accumulator
    );

    pe pe11 (
        .clk(clk), 
        .reset(reset), 
        .en_weight_pass(en_weight_pass),
        .en_weight_capture(en_capture_col1),  // Column 1 capture timing (staggered)
        .in_act(pe10_11_act), 
        .in_psum(pe01_11_psum),
        .out_act(), // Activation unconnected at edge of 2x2 array
        .out_psum(acc1_out)       // Output column 1 to accumulator
    );

endmodule