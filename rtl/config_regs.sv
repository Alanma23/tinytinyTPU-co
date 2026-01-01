`timescale 1ns / 1ps

// Configuration Register File
// Stores runtime-configurable parameters for TPU operation

module config_regs (
    input  logic        clk,
    input  logic        reset,
    
    // Write interface
    input  logic        wr_en,
    input  logic [7:0]  reg_addr,      // Register address
    input  logic [31:0] reg_data,      // Register data
    
    // Read interface (combinational)
    input  logic [7:0]  rd_addr,
    output logic [31:0] rd_data,
    
    // Configuration outputs
    output logic [2:0]  vpu_activation_type,  // VPU activation function
    output logic        matmul_clear_acc,      // Clear accumulator before MATMUL
    output logic        normalization_enable,   // Enable normalization
    output logic        quantization_enable    // Enable quantization
);

    // Register address map
    localparam logic [7:0] REG_VPU_ACTIVATION_TYPE = 8'h00;
    localparam logic [7:0] REG_MATMUL_CLEAR_ACC     = 8'h01;
    localparam logic [7:0] REG_NORMALIZATION_ENABLE = 8'h02;
    localparam logic [7:0] REG_QUANTIZATION_ENABLE  = 8'h03;
    
    // Configuration registers
    logic [2:0]  reg_vpu_activation_type;
    logic        reg_matmul_clear_acc;
    logic        reg_normalization_enable;
    logic        reg_quantization_enable;
    
    // Register write
    always_ff @(posedge clk) begin
        if (reset) begin
            reg_vpu_activation_type <= 3'b001;  // Default: ReLU
            reg_matmul_clear_acc <= 1'b1;       // Default: clear accumulator
            reg_normalization_enable <= 1'b1;    // Default: enable normalization
            reg_quantization_enable <= 1'b1;    // Default: enable quantization
        end else if (wr_en) begin
            unique case (reg_addr)
                REG_VPU_ACTIVATION_TYPE: reg_vpu_activation_type <= reg_data[2:0];
                REG_MATMUL_CLEAR_ACC:     reg_matmul_clear_acc <= reg_data[0];
                REG_NORMALIZATION_ENABLE: reg_normalization_enable <= reg_data[0];
                REG_QUANTIZATION_ENABLE:  reg_quantization_enable <= reg_data[0];
                default: ; // Unknown register, ignore
            endcase
        end
    end
    
    // Register read (combinational)
    always_comb begin
        unique case (rd_addr)
            REG_VPU_ACTIVATION_TYPE: rd_data = {29'b0, reg_vpu_activation_type};
            REG_MATMUL_CLEAR_ACC:     rd_data = {31'b0, reg_matmul_clear_acc};
            REG_NORMALIZATION_ENABLE: rd_data = {31'b0, reg_normalization_enable};
            REG_QUANTIZATION_ENABLE:  rd_data = {31'b0, reg_quantization_enable};
            default:                  rd_data = 32'b0;
        endcase
    end
    
    // Output assignments
    assign vpu_activation_type = reg_vpu_activation_type;
    assign matmul_clear_acc = reg_matmul_clear_acc;
    assign normalization_enable = reg_normalization_enable;
    assign quantization_enable = reg_quantization_enable;

endmodule

