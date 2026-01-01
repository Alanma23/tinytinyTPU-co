`timescale 1ns / 1ps

// Instruction Decoder for 20-Instruction TPU ISA
// Decodes 8-bit opcodes into control signals

module instruction_decoder (
    input  logic [7:0] opcode,
    
    // Decoded instruction type
    output logic        is_nop,
    output logic        is_memory_op,
    output logic        is_matrix_op,
    output logic        is_activation_op,
    output logic        is_pooling_op,
    output logic        is_norm_op,
    output logic        is_control_op,
    
    // Specific instruction flags
    output logic        is_rd_weight,
    output logic        is_ld_ub,
    output logic        is_st_ub,
    output logic        is_matmul,
    output logic        is_conv2d,
    output logic        is_matmul_acc,
    output logic        is_relu,
    output logic        is_relu6,
    output logic        is_sigmoid,
    output logic        is_tanh,
    output logic        is_maxpool,
    output logic        is_avgpool,
    output logic        is_add_bias,
    output logic        is_batch_norm,
    output logic        is_sync,
    output logic        is_cfg_reg,
    output logic        is_halt,
    
    // Instruction requires operands
    output logic        needs_operands
);

    // Instruction opcodes
    localparam logic [7:0] OP_NOP          = 8'h00;
    localparam logic [7:0] OP_RD_HOST_MEM = 8'h01;
    localparam logic [7:0] OP_WR_HOST_MEM = 8'h02;
    localparam logic [7:0] OP_RD_WEIGHT   = 8'h03;
    localparam logic [7:0] OP_LD_UB      = 8'h04;
    localparam logic [7:0] OP_ST_UB      = 8'h05;
    localparam logic [7:0] OP_MATMUL     = 8'h10;
    localparam logic [7:0] OP_CONV2D     = 8'h11;
    localparam logic [7:0] OP_MATMUL_ACC = 8'h12;
    localparam logic [7:0] OP_RELU       = 8'h18;
    localparam logic [7:0] OP_RELU6      = 8'h19;
    localparam logic [7:0] OP_SIGMOID    = 8'h1A;
    localparam logic [7:0] OP_TANH       = 8'h1B;
    localparam logic [7:0] OP_MAXPOOL    = 8'h20;
    localparam logic [7:0] OP_AVGPOOL    = 8'h21;
    localparam logic [7:0] OP_ADD_BIAS   = 8'h22;
    localparam logic [7:0] OP_BATCH_NORM = 8'h23;
    localparam logic [7:0] OP_SYNC       = 8'h30;
    localparam logic [7:0] OP_CFG_REG    = 8'h31;
    localparam logic [7:0] OP_HALT       = 8'h3F;
    
    // Legacy opcodes (backward compatibility)
    localparam logic [7:0] LEGACY_WRITE_WEIGHT = 8'h01;  // Maps to RD_HOST_MEM (stub)
    localparam logic [7:0] LEGACY_WRITE_ACT    = 8'h02;  // Maps to WR_HOST_MEM (stub)
    localparam logic [7:0] LEGACY_EXECUTE      = 8'h03;  // Maps to MATMUL
    localparam logic [7:0] LEGACY_READ_RESULT = 8'h04;  // Status read (handled separately)
    localparam logic [7:0] LEGACY_STATUS      = 8'h05;  // Status read (handled separately)

    // Instruction category detection
    assign is_nop = (opcode == OP_NOP);
    assign is_memory_op = (opcode >= 8'h00 && opcode <= 8'h0F) && !is_nop;
    assign is_matrix_op = (opcode >= 8'h10 && opcode <= 8'h1F);
    assign is_activation_op = (opcode >= 8'h18 && opcode <= 8'h1F);
    assign is_pooling_op = (opcode >= 8'h20 && opcode <= 8'h2F);
    assign is_norm_op = (opcode >= 8'h22 && opcode <= 8'h2F);
    assign is_control_op = (opcode >= 8'h30 && opcode <= 8'h3F);

    // Specific instruction detection
    assign is_rd_weight = (opcode == OP_RD_WEIGHT);
    assign is_ld_ub = (opcode == OP_LD_UB);
    assign is_st_ub = (opcode == OP_ST_UB);
    assign is_matmul = (opcode == OP_MATMUL) || (opcode == LEGACY_EXECUTE);
    assign is_conv2d = (opcode == OP_CONV2D);
    assign is_matmul_acc = (opcode == OP_MATMUL_ACC);
    assign is_relu = (opcode == OP_RELU);
    assign is_relu6 = (opcode == OP_RELU6);
    assign is_sigmoid = (opcode == OP_SIGMOID);
    assign is_tanh = (opcode == OP_TANH);
    assign is_maxpool = (opcode == OP_MAXPOOL);
    assign is_avgpool = (opcode == OP_AVGPOOL);
    assign is_add_bias = (opcode == OP_ADD_BIAS);
    assign is_batch_norm = (opcode == OP_BATCH_NORM);
    assign is_sync = (opcode == OP_SYNC);
    assign is_cfg_reg = (opcode == OP_CFG_REG);
    assign is_halt = (opcode == OP_HALT);

    // Instructions that require operands (4 bytes after opcode)
    assign needs_operands = is_rd_weight || is_ld_ub || is_st_ub || is_cfg_reg;

endmodule

