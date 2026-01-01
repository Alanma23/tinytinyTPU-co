`timescale 1ns / 1ps

// Execution Unit for TPU ISA
// Executes instructions by generating control signals for MLP and VPU

module execution_unit (
    input  logic        clk,
    input  logic        reset,
    
    // Instruction input
    input  logic [7:0]  opcode,
    input  logic [31:0] operand,        // Operand for instructions that need it
    input  logic        instruction_valid,
    
    // Decoded instruction flags (from instruction_decoder)
    input  logic        is_nop,
    input  logic        is_rd_weight,
    input  logic        is_ld_ub,
    input  logic        is_st_ub,
    input  logic        is_matmul,
    input  logic        is_conv2d,
    input  logic        is_matmul_acc,
    input  logic        is_relu,
    input  logic        is_relu6,
    input  logic        is_sigmoid,
    input  logic        is_tanh,
    input  logic        is_maxpool,
    input  logic        is_avgpool,
    input  logic        is_add_bias,
    input  logic        is_batch_norm,
    input  logic        is_sync,
    input  logic        is_cfg_reg,
    input  logic        is_halt,
    
    // MLP control interface
    output logic        mlp_start,
    output logic        mlp_clear_acc,      // Clear accumulator before MATMUL
    output logic        mlp_accumulate_mode, // Accumulate mode for MATMUL_ACC
    
    // VPU control interface
    output logic [2:0]  vpu_activation_type, // VPU activation function selection
    
    // Configuration register interface
    output logic        cfg_reg_wr_en,
    output logic [7:0]  cfg_reg_addr,
    output logic [31:0] cfg_reg_data,
    
    // Status
    input  logic [3:0]  mlp_state,          // MLP FSM state
    output logic        execution_busy,     // Execution in progress
    output logic        execution_done,      // Execution complete
    output logic        halt_flag            // Halt flag set
);

    // MLP FSM states
    localparam logic [3:0] MLP_STATE_IDLE = 4'd0;
    localparam logic [3:0] MLP_STATE_DONE = 4'd8;
    
    // VPU activation type encodings
    localparam logic [2:0] VPU_PASSTHROUGH = 3'b000;
    localparam logic [2:0] VPU_RELU        = 3'b001;
    localparam logic [2:0] VPU_RELU6       = 3'b010;
    localparam logic [2:0] VPU_SIGMOID     = 3'b011;
    localparam logic [2:0] VPU_TANH        = 3'b100;
    
    // Internal state
    logic exec_busy_reg;
    logic exec_done_reg;
    logic halt_flag_reg;
    logic sync_waiting;
    
    // Default outputs
    assign mlp_start = 1'b0;
    assign mlp_clear_acc = 1'b1;  // Default: clear accumulator
    assign mlp_accumulate_mode = 1'b0;
    assign vpu_activation_type = VPU_RELU;  // Default: ReLU
    assign cfg_reg_wr_en = 1'b0;
    assign cfg_reg_addr = 8'h00;
    assign cfg_reg_data = 32'h0;
    assign execution_busy = exec_busy_reg;
    assign execution_done = exec_done_reg;
    assign halt_flag = halt_flag_reg;
    
    // Execution state machine
    always_ff @(posedge clk) begin
        if (reset) begin
            exec_busy_reg <= 1'b0;
            exec_done_reg <= 1'b0;
            halt_flag_reg <= 1'b0;
            sync_waiting <= 1'b0;
        end else begin
            exec_done_reg <= 1'b0;
            
            if (instruction_valid && !halt_flag_reg) begin
                // Execute instruction
                if (is_nop) begin
                    // No operation - do nothing
                    exec_done_reg <= 1'b1;
                end
                else if (is_matmul || is_conv2d) begin
                    // Matrix multiply - start MLP with clear accumulator
                    exec_busy_reg <= 1'b1;
                    sync_waiting <= 1'b1;
                end
                else if (is_matmul_acc) begin
                    // Matrix multiply with accumulate - start MLP without clearing
                    exec_busy_reg <= 1'b1;
                    sync_waiting <= 1'b1;
                end
                else if (is_relu) begin
                    // ReLU activation - configure VPU
                    exec_done_reg <= 1'b1;
                end
                else if (is_relu6) begin
                    // ReLU6 activation - configure VPU
                    exec_done_reg <= 1'b1;
                end
                else if (is_sigmoid) begin
                    // Sigmoid activation - configure VPU
                    exec_done_reg <= 1'b1;
                end
                else if (is_tanh) begin
                    // Tanh activation - configure VPU
                    exec_done_reg <= 1'b1;
                end
                else if (is_sync) begin
                    // Synchronization - wait for MLP to be idle or done
                    if (mlp_state == MLP_STATE_IDLE || mlp_state == MLP_STATE_DONE) begin
                        exec_done_reg <= 1'b1;
                    end else begin
                        sync_waiting <= 1'b1;
                    end
                end
                else if (is_cfg_reg) begin
                    // Configure register - write to config regs
                    exec_done_reg <= 1'b1;
                end
                else if (is_halt) begin
                    // Halt execution
                    halt_flag_reg <= 1'b1;
                    exec_done_reg <= 1'b1;
                end
                else begin
                    // Other instructions (stubs) - mark as done immediately
                    exec_done_reg <= 1'b1;
                end
            end
            
            // Check for sync completion
            if (sync_waiting) begin
                if (mlp_state == MLP_STATE_IDLE || mlp_state == MLP_STATE_DONE) begin
                    exec_busy_reg <= 1'b0;
                    sync_waiting <= 1'b0;
                    exec_done_reg <= 1'b1;
                end
            end
        end
    end
    
    // Combinational control signal generation
    always_comb begin
        // Default values
        mlp_start = 1'b0;
        mlp_clear_acc = 1'b1;
        mlp_accumulate_mode = 1'b0;
        vpu_activation_type = VPU_RELU;
        cfg_reg_wr_en = 1'b0;
        cfg_reg_addr = 8'h00;
        cfg_reg_data = 32'h0;
        
        if (instruction_valid && !halt_flag_reg) begin
            if (is_matmul || is_conv2d) begin
                mlp_start = 1'b1;
                mlp_clear_acc = 1'b1;  // Clear accumulator
                mlp_accumulate_mode = 1'b0;
            end
            else if (is_matmul_acc) begin
                mlp_start = 1'b1;
                mlp_clear_acc = 1'b0;  // Don't clear accumulator
                mlp_accumulate_mode = 1'b1;
            end
            else if (is_relu) begin
                vpu_activation_type = VPU_RELU;
            end
            else if (is_relu6) begin
                vpu_activation_type = VPU_RELU6;
            end
            else if (is_sigmoid) begin
                vpu_activation_type = VPU_SIGMOID;
            end
            else if (is_tanh) begin
                vpu_activation_type = VPU_TANH;
            end
            else if (is_cfg_reg) begin
                cfg_reg_wr_en = 1'b1;
                cfg_reg_addr = operand[7:0];      // Register address
                cfg_reg_data = operand;            // Register value
            end
        end
    end

endmodule

