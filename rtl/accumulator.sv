`timescale 1ns / 1ps

module accumulator (
    input  logic        clk,
    input  logic        reset,
    input  logic        valid_in,  // MMU data valid
    input  logic        accumulator_enable, // add to existing sum or overwrite (1/0)
    input  logic        addr_sel, // buffer selection (buffer 1, or buffer 2)

    input  logic [15:0] mmu_col0_in,
    input  logic [15:0] mmu_col1_in,

    output logic signed [31:0] acc_col0_out,
    output logic signed [31:0] acc_col1_out,
    output logic        valid_out
);

    logic        aligned_valid;
    logic [15:0] aligned_c0;
    logic [15:0] aligned_c1;

    accumulator_align u_align (
        .clk(clk),
        .reset(reset),
        .valid_in(valid_in),
        .raw_col0(mmu_col0_in),
        .raw_col1(mmu_col1_in),
        .aligned_valid(aligned_valid),
        .align_col0(aligned_c0),
        .align_col1(aligned_c1)
    );

    accumulator_mem u_mem (
        .clk(clk),
        .reset(reset),
        .enable(aligned_valid),
        .accumulator_mode(accumulator_enable),
        .buffer_select(addr_sel),
        .in_col0(aligned_c0),
        .in_col1(aligned_c1),
        .valid_out(valid_out),
        .out_col0(acc_col0_out),
        .out_col1(acc_col1_out)
    );

endmodule

