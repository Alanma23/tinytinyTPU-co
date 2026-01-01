`timescale 1ns / 1ps

// UART Controller - Command parser for TPU control
// Receives commands via UART and controls MLP module

module uart_controller #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200
)(
    input  logic        clk,
    input  logic        rst,
    
    // UART interface
    input  logic        uart_rx,
    output logic        uart_tx,
    
    // MLP control interface
    output logic        wf_push_col0,
    output logic        wf_push_col1,
    output logic [7:0]  wf_data_in,
    output logic        wf_reset,
    output logic        init_act_valid,
    output logic [15:0] init_act_data,
    output logic        start_mlp,
    output logic        weights_ready,
    
    // MLP status interface
    input  logic [3:0]  mlp_state,
    input  logic [4:0]  mlp_cycle_cnt,
    input  logic signed [31:0] mlp_acc0,

    // Debug taps
    output logic [3:0]  dbg_state,
    output logic [7:0]  dbg_cmd_reg,
    output logic [2:0]  dbg_byte_count,
    output logic [1:0]  dbg_resp_byte_idx,
    output logic        dbg_tx_valid,
    output logic        dbg_tx_ready,
    output logic        dbg_rx_valid,
    output logic [7:0]  dbg_rx_data,
    output logic        dbg_weights_ready,
    output logic        dbg_start_mlp
);

    // Legacy command definitions (backward compatibility)
    localparam logic [7:0] CMD_WRITE_WEIGHT = 8'h01;
    localparam logic [7:0] CMD_WRITE_ACT    = 8'h02;
    localparam logic [7:0] CMD_EXECUTE      = 8'h03;  // Maps to MATMUL (0x10)
    localparam logic [7:0] CMD_READ_RESULT  = 8'h04;
    localparam logic [7:0] CMD_STATUS       = 8'h05;
    
    // New ISA instruction opcodes
    localparam logic [7:0] OP_NOP          = 8'h00;
    localparam logic [7:0] OP_RD_HOST_MEM  = 8'h01;
    localparam logic [7:0] OP_WR_HOST_MEM  = 8'h02;
    localparam logic [7:0] OP_RD_WEIGHT    = 8'h03;
    localparam logic [7:0] OP_LD_UB        = 8'h04;
    localparam logic [7:0] OP_ST_UB        = 8'h05;
    localparam logic [7:0] OP_MATMUL       = 8'h10;
    localparam logic [7:0] OP_CONV2D       = 8'h11;
    localparam logic [7:0] OP_MATMUL_ACC   = 8'h12;
    localparam logic [7:0] OP_RELU         = 8'h18;
    localparam logic [7:0] OP_RELU6        = 8'h19;
    localparam logic [7:0] OP_SIGMOID      = 8'h1A;
    localparam logic [7:0] OP_TANH         = 8'h1B;
    localparam logic [7:0] OP_MAXPOOL      = 8'h20;
    localparam logic [7:0] OP_AVGPOOL        = 8'h21;
    localparam logic [7:0] OP_ADD_BIAS      = 8'h22;
    localparam logic [7:0] OP_BATCH_NORM    = 8'h23;
    localparam logic [7:0] OP_SYNC          = 8'h30;
    localparam logic [7:0] OP_CFG_REG       = 8'h31;
    localparam logic [7:0] OP_HALT          = 8'h3F;

    // Mirror MLP state encodings for clarity
    localparam logic [3:0] MLP_STATE_LOAD_WEIGHT = 4'd1;
    
    // Instruction decoder and execution unit signals
    logic [7:0]  decoded_opcode;
    logic        decoder_is_nop;
    logic        decoder_is_rd_weight;
    logic        decoder_is_ld_ub;
    logic        decoder_is_st_ub;
    logic        decoder_is_matmul;
    logic        decoder_is_conv2d;
    logic        decoder_is_matmul_acc;
    logic        decoder_is_relu;
    logic        decoder_is_relu6;
    logic        decoder_is_sigmoid;
    logic        decoder_is_tanh;
    logic        decoder_is_maxpool;
    logic        decoder_is_avgpool;
    logic        decoder_is_add_bias;
    logic        decoder_is_batch_norm;
    logic        decoder_is_sync;
    logic        decoder_is_cfg_reg;
    logic        decoder_is_halt;
    logic        decoder_needs_operands;
    
    // Execution unit signals
    logic        exec_mlp_start;
    logic        exec_mlp_clear_acc;
    logic        exec_mlp_accumulate_mode;
    logic [2:0]  exec_vpu_activation_type;
    logic        exec_cfg_reg_wr_en;
    logic [7:0]  exec_cfg_reg_addr;
    logic [31:0] exec_cfg_reg_data;
    logic        exec_busy;
    logic        exec_done;
    logic        exec_halt_flag;
    logic        instruction_valid_reg;
    logic [31:0] operand_reg;

    // UART RX/TX instances
    logic [7:0] rx_data;
    logic       rx_valid;
    logic       rx_ready;
    
    logic [7:0] tx_data;
    (* keep = "true" *) logic       tx_valid;
    (* keep = "true" *) logic       tx_ready;

    uart_rx #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart_rx_u (
        .clk(clk),
        .rst(rst),
        .rx(uart_rx),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
        .rx_ready(rx_ready)
    );

    uart_tx #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart_tx_u (
        .clk(clk),
        .rst(rst),
        .tx(uart_tx),
        .tx_data(tx_data),
        .tx_valid(tx_valid),
        .tx_ready(tx_ready)
    );
    
    // Instruction decoder instance
    instruction_decoder decoder_u (
        .opcode(decoded_opcode),
        .is_nop(decoder_is_nop),
        .is_memory_op(),
        .is_matrix_op(),
        .is_activation_op(),
        .is_pooling_op(),
        .is_norm_op(),
        .is_control_op(),
        .is_rd_weight(decoder_is_rd_weight),
        .is_ld_ub(decoder_is_ld_ub),
        .is_st_ub(decoder_is_st_ub),
        .is_matmul(decoder_is_matmul),
        .is_conv2d(decoder_is_conv2d),
        .is_matmul_acc(decoder_is_matmul_acc),
        .is_relu(decoder_is_relu),
        .is_relu6(decoder_is_relu6),
        .is_sigmoid(decoder_is_sigmoid),
        .is_tanh(decoder_is_tanh),
        .is_maxpool(decoder_is_maxpool),
        .is_avgpool(decoder_is_avgpool),
        .is_add_bias(decoder_is_add_bias),
        .is_batch_norm(decoder_is_batch_norm),
        .is_sync(decoder_is_sync),
        .is_cfg_reg(decoder_is_cfg_reg),
        .is_halt(decoder_is_halt),
        .needs_operands(decoder_needs_operands)
    );
    
    // Execution unit instance
    execution_unit exec_u (
        .clk(clk),
        .reset(rst),
        .opcode(decoded_opcode),
        .operand(operand_reg),
        .instruction_valid(instruction_valid_reg),
        .is_nop(decoder_is_nop),
        .is_rd_weight(decoder_is_rd_weight),
        .is_ld_ub(decoder_is_ld_ub),
        .is_st_ub(decoder_is_st_ub),
        .is_matmul(decoder_is_matmul),
        .is_conv2d(decoder_is_conv2d),
        .is_matmul_acc(decoder_is_matmul_acc),
        .is_relu(decoder_is_relu),
        .is_relu6(decoder_is_relu6),
        .is_sigmoid(decoder_is_sigmoid),
        .is_tanh(decoder_is_tanh),
        .is_maxpool(decoder_is_maxpool),
        .is_avgpool(decoder_is_avgpool),
        .is_add_bias(decoder_is_add_bias),
        .is_batch_norm(decoder_is_batch_norm),
        .is_sync(decoder_is_sync),
        .is_cfg_reg(decoder_is_cfg_reg),
        .is_halt(decoder_is_halt),
        .mlp_start(exec_mlp_start),
        .mlp_clear_acc(exec_mlp_clear_acc),
        .mlp_accumulate_mode(exec_mlp_accumulate_mode),
        .vpu_activation_type(exec_vpu_activation_type),
        .cfg_reg_wr_en(exec_cfg_reg_wr_en),
        .cfg_reg_addr(exec_cfg_reg_addr),
        .cfg_reg_data(exec_cfg_reg_data),
        .mlp_state(mlp_state),
        .execution_busy(exec_busy),
        .execution_done(exec_done),
        .halt_flag(exec_halt_flag)
    );
    
    // Configuration register file instance
    config_regs cfg_regs_u (
        .clk(clk),
        .reset(rst),
        .wr_en(exec_cfg_reg_wr_en),
        .reg_addr(exec_cfg_reg_addr),
        .reg_data(exec_cfg_reg_data),
        .rd_addr(8'h00),  // Not used for now
        .rd_data(),        // Not used for now
        .vpu_activation_type(),  // Will be routed to MLP via bridge
        .matmul_clear_acc(),     // Will be routed to MLP
        .normalization_enable(), // Will be routed to MLP
        .quantization_enable()   // Will be routed to MLP
    );

    // Controller FSM
    typedef enum logic [3:0] {
        IDLE            = 4'd0,
        WAIT_CMD        = 4'd1,
        RECV_DATA       = 4'd2,
        EXEC_CMD        = 4'd3,
        SEND_RESP       = 4'd4,
        WRITE_WEIGHT_SEQ = 4'd5,
        WRITE_ACT_SEQ    = 4'd6
    } ctrl_state_t;

    (* fsm_encoding = "one_hot" *) ctrl_state_t state;
    logic [7:0]  cmd_reg;
    logic [2:0]  byte_count;
    logic [7:0]  data_buffer [0:3];  // Buffer for multi-byte commands
    logic [1:0]  resp_byte_idx;
    (* keep = "true" *) logic [7:0]  resp_buffer [0:3];   // Response buffer
    logic [2:0]  weight_seq_idx;      // For sequencing weight writes (0=reset, 1-4=weights)
    logic [1:0]  act_seq_idx;          // For sequencing activation writes
    logic        byte_sent;            // Flag to track if current response byte has been sent
    logic [7:0]  resp_delay_count;     // Delay counter before starting response transmission
    logic [15:0] send_resp_timeout;   // Timeout counter to prevent infinite waiting in SEND_RESP

    // MLP control signals
    logic wf_reset_reg;
    logic weights_ready_reg;
    logic [3:0] mlp_state_prev;  // Track previous MLP state to detect transitions
    
    // Instruction decoder and execution unit signals
    assign decoded_opcode = cmd_reg;
    // Only enable execution unit for new ISA instructions, not legacy commands
    // Legacy commands: 0x01-0x05 (WRITE_WEIGHT, WRITE_ACT, EXECUTE, READ_RESULT, STATUS)
    assign instruction_valid_reg = (state == EXEC_CMD) && !exec_halt_flag && 
                                    (cmd_reg >= 8'h10 || cmd_reg == 8'h00 || cmd_reg == 8'h3F);
    assign operand_reg = {data_buffer[3], data_buffer[2], data_buffer[1], data_buffer[0]};
    
    assign wf_reset = wf_reset_reg;
    assign weights_ready = weights_ready_reg;

    // Output registers
    logic wf_push_col0_reg;
    logic wf_push_col1_reg;
    logic [7:0] wf_data_in_reg;
    logic init_act_valid_reg;
    logic [15:0] init_act_data_reg;
    logic start_mlp_reg;
    (* keep = "true" *) logic tx_valid_reg;
    logic [7:0] tx_data_reg;

    assign wf_push_col0 = wf_push_col0_reg;
    assign wf_push_col1 = wf_push_col1_reg;
    assign wf_data_in = wf_data_in_reg;
    assign init_act_valid = init_act_valid_reg;
    assign init_act_data = init_act_data_reg;
    assign start_mlp = start_mlp_reg;
    assign tx_valid = tx_valid_reg;
    assign tx_data = tx_data_reg;
    // Debug: Capture start_mlp pulses in a sticky bit for LED visibility
    logic start_mlp_sticky = 1'b0;

    assign dbg_state = state;
    assign dbg_cmd_reg = cmd_reg;
    assign dbg_byte_count = byte_count;
    assign dbg_resp_byte_idx = resp_byte_idx;
    assign dbg_tx_valid = tx_valid_reg;
    assign dbg_tx_ready = tx_ready;
    assign dbg_rx_valid = rx_valid;
    assign dbg_weights_ready = weights_ready_reg;
    assign dbg_start_mlp = start_mlp_sticky;  // Show sticky version for LED visibility

    // Capture last received byte for echo test
    logic [7:0] rx_data_captured;
    always_ff @(posedge clk) begin
        if (rst) begin
            rx_data_captured <= 8'd0;
        end else if (rx_valid) begin
            rx_data_captured <= rx_data;
        end
    end
    assign dbg_rx_data = rx_data_captured;

    // Capture start_mlp pulses
    always_ff @(posedge clk) begin
        if (rst) begin
            start_mlp_sticky <= 1'b0;
        end else begin
            if (start_mlp_reg) begin
                start_mlp_sticky <= 1'b1;  // Set on pulse
            end
            // Auto-clear after some time in IDLE
            if (state == IDLE && byte_count == 3'd0) begin
                start_mlp_sticky <= 1'b0;
            end
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            cmd_reg <= 8'd0;
            byte_count <= 3'd0;
            weight_seq_idx <= 3'd0;
            act_seq_idx <= 2'd0;
            for (int i = 0; i < 4; i++) begin
                data_buffer[i] <= 8'd0;
                resp_buffer[i] <= 8'd0;
            end
            resp_byte_idx <= 2'd0;
            byte_sent <= 1'b0;
            resp_delay_count <= 8'd0;
            send_resp_timeout <= 16'd0;
            wf_push_col0_reg <= 1'b0;
            wf_push_col1_reg <= 1'b0;
            wf_data_in_reg <= 8'd0;
            init_act_valid_reg <= 1'b0;
            init_act_data_reg <= 16'd0;
            start_mlp_reg <= 1'b0;
            tx_valid_reg <= 1'b0;
            tx_data_reg <= 8'd0;
            wf_reset_reg <= 1'b0;
            weights_ready_reg <= 1'b0;
            mlp_state_prev <= 4'd0;
        end else begin
            // Default: clear control signals (pulse signals)
            wf_push_col0_reg <= 1'b0;
            wf_push_col1_reg <= 1'b0;
            wf_reset_reg <= 1'b0;  // Clear FIFO reset after one cycle
            init_act_valid_reg <= 1'b0;
            
            // Track MLP state transitions
            mlp_state_prev <= mlp_state;
            
            // Clear start_mlp_reg and weights_ready when MLP has acknowledged it (left IDLE)
            // This ensures the pulse is visible long enough for MLP to see it
            if (start_mlp_reg && mlp_state != 4'd0 && mlp_state_prev == 4'd0) begin
                // MLP just left IDLE - clear start_mlp_reg and weights_ready
                // #region agent log
                $display("[UART_CTRL] MLP started! Clearing start_mlp_reg and weights_ready_reg (state %d -> %d)", mlp_state_prev, mlp_state);
                // #endregion
                start_mlp_reg <= 1'b0;
                weights_ready_reg <= 1'b0;  // Weights consumed by MLP
            end else if (start_mlp_reg && mlp_state == 4'd0) begin
                // #region agent log
                // Log every 100 cycles to avoid spam
                if (resp_delay_count[6:0] == 7'd0)
                    $display("[UART_CTRL] start_mlp_reg still set, MLP still in IDLE (state=%d)", mlp_state);
                // #endregion
                // Keep start_mlp_reg set until MLP responds
            end
            // Don't clear tx_valid_reg here - it's managed by SEND_RESP state
            // tx_valid_reg <= 1'b0;

            case (state)
                IDLE: begin
                    byte_count <= 3'd0;
                    resp_byte_idx <= 2'd0;
                    byte_sent <= 1'b0;
                    resp_delay_count <= 8'd0;
                    send_resp_timeout <= 16'd0;  // Reset timeout when entering IDLE
                    weight_seq_idx <= 3'd0;
                    act_seq_idx <= 2'd0;
                    if (rx_ready) begin
                        state <= WAIT_CMD;
                    end
                end

                WAIT_CMD: begin
                    if (rx_valid) begin
                        cmd_reg <= rx_data;
                        byte_count <= 3'd0;
                        // #region agent log
                        $display("[UART_CTRL] WAIT_CMD: Received cmd=0x%02X", rx_data);
                        // #endregion
                        
                        // Determine how many data bytes to expect
                        // Legacy commands (backward compatibility)
                        if (rx_data == CMD_WRITE_WEIGHT || rx_data == CMD_WRITE_ACT) begin
                            state <= RECV_DATA;
                        end
                        // New ISA instructions that need operands
                        else if (rx_data == OP_RD_WEIGHT || rx_data == OP_LD_UB || 
                                 rx_data == OP_ST_UB || rx_data == OP_CFG_REG) begin
                            state <= RECV_DATA;
                        end
                        // Instructions that execute immediately (no operands)
                        else if (rx_data == CMD_EXECUTE || rx_data == OP_MATMUL ||
                                 rx_data == OP_CONV2D || rx_data == OP_MATMUL_ACC ||
                                 rx_data == OP_RELU || rx_data == OP_RELU6 ||
                                 rx_data == OP_SIGMOID || rx_data == OP_TANH ||
                                 rx_data == OP_MAXPOOL || rx_data == OP_AVGPOOL ||
                                 rx_data == OP_ADD_BIAS || rx_data == OP_BATCH_NORM ||
                                 rx_data == OP_SYNC || rx_data == OP_HALT ||
                                 rx_data == OP_NOP ||
                                 rx_data == CMD_READ_RESULT || rx_data == CMD_STATUS) begin
                            state <= EXEC_CMD;
                        end else begin
                            // Unknown command, go back to IDLE
                            state <= IDLE;
                        end
                    end
                end

                RECV_DATA: begin
                    if (rx_valid) begin
                        data_buffer[byte_count] <= rx_data;
                        if (byte_count == 3'd3) begin
                            // All data received, start execution
                            if (cmd_reg == CMD_WRITE_WEIGHT) begin
                                weight_seq_idx <= 3'd0;
                                state <= WRITE_WEIGHT_SEQ;
                                // #region agent log
                                $display("[UART_CTRL] RECV_DATA: Got 4 bytes for CMD_WRITE_WEIGHT, going to WRITE_WEIGHT_SEQ. Data=[%02X,%02X,%02X,%02X]",
                                         data_buffer[0], data_buffer[1], data_buffer[2], rx_data);
                                // #endregion
                            end else if (cmd_reg == CMD_WRITE_ACT) begin
                                act_seq_idx <= 2'd0;
                                state <= WRITE_ACT_SEQ;
                                // #region agent log
                                $display("[UART_CTRL] RECV_DATA: Got 4 bytes for CMD_WRITE_ACT, going to WRITE_ACT_SEQ. Data=[%02X,%02X,%02X,%02X]",
                                         data_buffer[0], data_buffer[1], data_buffer[2], rx_data);
                                // #endregion
                            end else begin
                                // New ISA instruction with operands - execute
                                state <= EXEC_CMD;
                            end
                        end else begin
                            byte_count <= byte_count + 1;
                        end
                    end
                end

                WRITE_WEIGHT_SEQ: begin
                    // Sequence: Reset FIFO, then W00->col0, W01->col1, W10->col0, W11->col1
                    // Steps: 0=reset, 1=W00, 2=W01, 3=W10, 4=W11
                    case (weight_seq_idx)
                        3'd0: begin  // Reset FIFO pointers first
                            wf_reset_reg <= 1'b1;
                            weight_seq_idx <= 3'd1;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_WEIGHT_SEQ[0]: Resetting weight FIFO");
                            // #endregion
                        end
                        3'd1: begin  // W00 -> col0
                            wf_data_in_reg <= data_buffer[0];
                            wf_push_col0_reg <= 1'b1;
                            weight_seq_idx <= 3'd2;
                        end
                        3'd2: begin  // W01 -> col1
                            wf_data_in_reg <= data_buffer[1];
                            wf_push_col1_reg <= 1'b1;
                            weight_seq_idx <= 3'd3;
                        end
                        3'd3: begin  // W10 -> col0
                            wf_data_in_reg <= data_buffer[2];
                            wf_push_col0_reg <= 1'b1;
                            weight_seq_idx <= 3'd4;
                        end
                        3'd4: begin  // W11 -> col1, done
                            wf_data_in_reg <= data_buffer[3];
                            wf_push_col1_reg <= 1'b1;
                            weights_ready_reg <= 1'b1;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_WEIGHT_SEQ[4]: Completed, weights=[%02X,%02X,%02X,%02X]",
                                     data_buffer[0], data_buffer[1], data_buffer[2], data_buffer[3]);
                            // #endregion
                            state <= IDLE;
                        end
                        default: state <= IDLE;
                    endcase
                end

                WRITE_ACT_SEQ: begin
                    // Systolic array needs activations by COLUMN for timing:
                    //   Step 0: {A10, A00} - first column (fed to row0 and row1 in parallel)
                    //   Step 1: {A11, A01} - second column
                    // data_buffer = [A00, A01, A10, A11]
                    case (act_seq_idx)
                        2'd0: begin  // Column 0: A00 (row0), A10 (row1)
                            init_act_data_reg <= {data_buffer[2], data_buffer[0]};
                            init_act_valid_reg <= 1'b1;
                            act_seq_idx <= 2'd1;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_ACT_SEQ[0]: Writing col0=0x%04X (A10=%02X, A00=%02X), init_act_valid=1",
                                     {data_buffer[2], data_buffer[0]}, data_buffer[2], data_buffer[0]);
                            // #endregion
                        end
                        2'd1: begin  // Column 1: A01 (row0), A11 (row1)
                            init_act_data_reg <= {data_buffer[3], data_buffer[1]};
                            init_act_valid_reg <= 1'b1;
                            state <= IDLE;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_ACT_SEQ[1]: Writing col1=0x%04X (A11=%02X, A01=%02X), init_act_valid=1, going to IDLE",
                                     {data_buffer[3], data_buffer[1]}, data_buffer[3], data_buffer[1]);
                            // #endregion
                        end
                        default: begin
                            state <= IDLE;
                        end
                    endcase
                end

                EXEC_CMD: begin
                    // Legacy commands completely bypass execution_unit - they don't check exec_halt_flag
                    // Only new ISA instructions (>= 0x10) use execution_unit
                    case (cmd_reg)
                        // Legacy commands (backward compatibility)
                        CMD_EXECUTE: begin
                            // Legacy EXECUTE command - use original path (bypasses execution_unit)
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_EXECUTE - setting start_mlp_reg=1");
                            // #endregion
                            start_mlp_reg <= 1'b1;
                            // Keep weights_ready set - MLP may need it to start
                            state <= IDLE;
                        end
                        
                        OP_MATMUL: begin
                            // New ISA MATMUL instruction - use execution unit
                            // Route execution unit signal to MLP control
                            if (exec_mlp_start) begin
                                start_mlp_reg <= 1'b1;
                            end
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: OP_MATMUL - exec_mlp_start=%b", exec_mlp_start);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_CONV2D: begin
                            // 2D convolution (stub - same as MATMUL for now)
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CONV2D - exec_mlp_start=%b", exec_mlp_start);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_MATMUL_ACC: begin
                            // Matrix multiply with accumulate
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: MATMUL_ACC - exec_mlp_start=%b, accumulate_mode=%b", 
                                     exec_mlp_start, exec_mlp_accumulate_mode);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Activation instructions (configure VPU)
                        OP_RELU: begin
                            // ReLU activation - VPU configured via execution unit
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: RELU - vpu_activation_type=%b", exec_vpu_activation_type);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_RELU6: begin
                            // ReLU6 activation
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: RELU6 - vpu_activation_type=%b", exec_vpu_activation_type);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_SIGMOID: begin
                            // Sigmoid activation
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: SIGMOID - vpu_activation_type=%b", exec_vpu_activation_type);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_TANH: begin
                            // Tanh activation
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: TANH - vpu_activation_type=%b", exec_vpu_activation_type);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Pooling instructions (stubs)
                        OP_MAXPOOL, OP_AVGPOOL: begin
                            // Pooling operations - stubs for now
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: POOLING (stub) - opcode=0x%02X", cmd_reg);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Normalization instructions
                        OP_ADD_BIAS, OP_BATCH_NORM: begin
                            // Normalization operations - use existing normalizer
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: NORMALIZATION - opcode=0x%02X", cmd_reg);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Control instructions
                        OP_SYNC: begin
                            // Synchronization - wait for MLP to complete
                            // Execution unit handles waiting
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: SYNC - waiting for MLP completion");
                            // #endregion
                            if (exec_done) begin
                                state <= IDLE;
                            end
                            // Stay in EXEC_CMD until execution unit signals done
                        end
                        
                        OP_CFG_REG: begin
                            // Configure register
                            // Execution unit handles register write
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CFG_REG - reg_addr=0x%02X, reg_data=0x%08X",
                                     exec_cfg_reg_addr, exec_cfg_reg_data);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_HALT: begin
                            // Halt execution
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: HALT - execution halted");
                            // #endregion
                            state <= IDLE;
                        end
                        
                        OP_NOP: begin
                            // No operation
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: NOP");
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Memory operations (stubs)
                        OP_RD_WEIGHT, OP_LD_UB, OP_ST_UB: begin
                            // Memory operations - stubs for now
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: MEMORY_OP (stub) - opcode=0x%02X", cmd_reg);
                            // #endregion
                            state <= IDLE;
                        end
                        
                        // Legacy status/result commands
                        CMD_READ_RESULT: begin
                            // Legacy READ_RESULT command - completely bypasses execution_unit
                            // Return 4 bytes: acc0[7:0], acc0[15:8], acc0[23:16], acc0[31:24]
                            resp_buffer[0] <= mlp_acc0[7:0];
                            resp_buffer[1] <= mlp_acc0[15:8];
                            resp_buffer[2] <= mlp_acc0[23:16];
                            resp_buffer[3] <= mlp_acc0[31:24];
                            resp_byte_idx <= 2'd0;
                            byte_sent <= 1'b0;
                            resp_delay_count <= 8'd0;  // Reset delay counter
                            send_resp_timeout <= 16'd0;  // Reset timeout counter
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_READ_RESULT - acc0=0x%08X", mlp_acc0);
                            // #endregion
                            state <= SEND_RESP;
                        end

                        CMD_STATUS: begin
                            // Legacy STATUS command - completely bypasses execution_unit
                            // Return 1 byte: [state(3:0) | cycle_cnt(3:0)]
                            resp_buffer[0] <= {mlp_state[3:0], mlp_cycle_cnt[3:0]};
                            resp_byte_idx <= 2'd0;
                            byte_sent <= 1'b0;
                            resp_delay_count <= 8'd0;  // Reset delay counter
                            send_resp_timeout <= 16'd0;  // Reset timeout counter
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_STATUS - state=%d, cycle=%d, resp_buffer[0]=0x%02X", 
                                     mlp_state, mlp_cycle_cnt, {mlp_state[3:0], mlp_cycle_cnt[3:0]});
                            // #endregion
                            state <= SEND_RESP;
                        end

                        default: begin
                            // Unknown command
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: Unknown command 0x%02X", cmd_reg);
                            // #endregion
                            state <= IDLE;
                        end
                    endcase
                end

                SEND_RESP: begin
                    // Increment timeout counter every cycle to detect stuck conditions
                    send_resp_timeout <= send_resp_timeout + 1;
                    
                    // Timeout safety: if stuck for too long (~100us at 100MHz), abort and return to IDLE
                    if (send_resp_timeout > 16'd10000) begin
                        // Force progression - something is wrong, abort transmission
                        tx_valid_reg <= 1'b0;
                        byte_sent <= 1'b0;
                        send_resp_timeout <= 16'd0;
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Timeout! Aborting and returning to IDLE (tx_valid=%b, tx_ready=%b, byte_sent=%b)",
                                 tx_valid_reg, tx_ready, byte_sent);
                        // #endregion
                        state <= IDLE;
                    end
                    // Add small delay before starting transmission to give test time to start listening
                    else if (resp_delay_count < 8'd10) begin
                        resp_delay_count <= resp_delay_count + 1;
                    end
                    // TX is ready and we haven't sent this byte yet - send it
                    else if (!tx_valid_reg && tx_ready && !byte_sent) begin
                        tx_data_reg <= resp_buffer[resp_byte_idx];
                        tx_valid_reg <= 1'b1;
                        byte_sent <= 1'b1;  // Mark byte as sent
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Sending byte[%0d]=0x%02X (from resp_buffer[%0d]=0x%02X), cmd=0x%02X, tx_ready=%b, total_bytes=%0d",
                                 resp_byte_idx, resp_buffer[resp_byte_idx], resp_byte_idx, resp_buffer[resp_byte_idx], cmd_reg, tx_ready,
                                 (cmd_reg == CMD_READ_RESULT) ? 4 : 1);
                        // #endregion
                    end
                    // TX valid asserted, waiting for UART TX to accept (tx_ready will go low next cycle)
                    else if (tx_valid_reg && tx_ready) begin
                        // Just wait - do nothing, UART TX will accept on next cycle
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Byte[%0d] waiting for UART TX to accept", resp_byte_idx);
                        // #endregion
                    end
                    // TX accepted the byte (tx_ready went low) - clear tx_valid immediately
                    else if (tx_valid_reg && !tx_ready) begin
                        tx_valid_reg <= 1'b0;
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Byte[%0d] accepted by UART TX, clearing tx_valid", resp_byte_idx);
                        // #endregion
                    end
                    // TX is transmitting - wait for it to finish
                    else if (!tx_valid_reg && !tx_ready) begin
                        // TX is busy transmitting - wait for it to finish (tx_ready will go high when done)
                        // No logging here to avoid spam
                    end
                    // TX finished transmission and is ready - move to next byte or done
                    else if (!tx_valid_reg && tx_ready && byte_sent) begin
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Byte[%0d] transmission complete, cmd=0x%02X", resp_byte_idx, cmd_reg);
                        // #endregion

                        // Decide what to do next based on command type
                        if (cmd_reg == CMD_STATUS) begin
                            // Single byte response - done
                            // #region agent log
                            $display("[UART_CTRL] SEND_RESP: STATUS done, going to IDLE");
                            // #endregion
                            state <= IDLE;
                        end else if (cmd_reg == CMD_READ_RESULT) begin
                            // 4 byte response: bytes 0, 1, 2, 3
                            if (resp_byte_idx == 2'd3) begin
                                // All 4 bytes sent - done
                                // #region agent log
                                $display("[UART_CTRL] SEND_RESP: All 4 bytes sent (0,1,2,3), going to IDLE");
                                // #endregion
                                state <= IDLE;
                            end else begin
                                // Move to next byte
                                resp_byte_idx <= resp_byte_idx + 1;
                                byte_sent <= 1'b0;  // Clear flag for next byte
                                resp_delay_count <= 8'd10;  // Skip delay for subsequent bytes (already listening)
                                send_resp_timeout <= 16'd0;  // Reset timeout for next byte
                                // #region agent log
                                $display("[UART_CTRL] SEND_RESP: Moving to next byte, resp_byte_idx=%0d->%0d",
                                         resp_byte_idx, resp_byte_idx + 1);
                                // #endregion
                            end
                        end else begin
                            // Unknown command - abort and return to IDLE
                            // #region agent log
                            $display("[UART_CTRL] SEND_RESP: Unknown command, going to IDLE");
                            // #endregion
                            state <= IDLE;
                        end
                    end
                    // Default case: unexpected state - recover by resetting and returning to IDLE
                    else begin
                        // Unexpected state: recover by resetting transmission state
                        tx_valid_reg <= 1'b0;
                        byte_sent <= 1'b0;
                        send_resp_timeout <= 16'd0;
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Unexpected state - recovering (tx_valid=%b, tx_ready=%b, byte_sent=%b)",
                                 tx_valid_reg, tx_ready, byte_sent);
                        // #endregion
                        state <= IDLE;  // Force return to IDLE to recover
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
