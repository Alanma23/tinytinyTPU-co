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
    input  logic [2:0]  mlp_current_layer,
    input  logic        mlp_layer_complete,
    input  logic signed [31:0] mlp_acc0,
    input  logic signed [31:0] mlp_acc1,
    input  logic        mlp_acc_valid,

    // Debug taps
    output logic [3:0]  dbg_state,
    output logic [7:0]  dbg_cmd_reg,
    output logic [2:0]  dbg_byte_count,
    output logic [1:0]  dbg_resp_byte_idx,
    output logic        dbg_tx_valid,
    output logic        dbg_tx_ready,
    output logic        dbg_rx_valid,
    output logic        dbg_weights_ready,
    output logic        dbg_start_mlp
);

    // Command definitions
    localparam logic [7:0] CMD_WRITE_WEIGHT = 8'h01;
    localparam logic [7:0] CMD_WRITE_ACT    = 8'h02;
    localparam logic [7:0] CMD_EXECUTE     = 8'h03;
    localparam logic [7:0] CMD_READ_RESULT = 8'h04;
    localparam logic [7:0] CMD_STATUS       = 8'h05;

    // UART RX/TX instances
    logic [7:0] rx_data;
    logic       rx_valid;
    logic       rx_ready;
    
    logic [7:0] tx_data;
    logic       tx_valid;
    logic       tx_ready;

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

    ctrl_state_t state;
    logic [7:0]  cmd_reg;
    logic [2:0]  byte_count;
    logic [7:0]  data_buffer [0:3];  // Buffer for multi-byte commands
    logic [1:0]  resp_byte_idx;
    logic [7:0]  resp_buffer [0:3];   // Response buffer
    logic [1:0]  weight_seq_idx;      // For sequencing weight writes
    logic [1:0]  act_seq_idx;          // For sequencing activation writes
    logic        byte_sent;            // Flag to track if current response byte has been sent
    logic [7:0]  resp_delay_count;     // Delay counter before starting response transmission

    // MLP control signals
    logic wf_reset_reg;
    logic weights_ready_reg;
    
    assign wf_reset = wf_reset_reg;
    assign weights_ready = weights_ready_reg;

    // Output registers
    logic wf_push_col0_reg;
    logic wf_push_col1_reg;
    logic [7:0] wf_data_in_reg;
    logic init_act_valid_reg;
    logic [15:0] init_act_data_reg;
    logic start_mlp_reg;
    logic tx_valid_reg;
    logic [7:0] tx_data_reg;

    assign wf_push_col0 = wf_push_col0_reg;
    assign wf_push_col1 = wf_push_col1_reg;
    assign wf_data_in = wf_data_in_reg;
    assign init_act_valid = init_act_valid_reg;
    assign init_act_data = init_act_data_reg;
    assign start_mlp = start_mlp_reg;
    assign tx_valid = tx_valid_reg;
    assign tx_data = tx_data_reg;
    assign dbg_state = state;
    assign dbg_cmd_reg = cmd_reg;
    assign dbg_byte_count = byte_count;
    assign dbg_resp_byte_idx = resp_byte_idx;
    assign dbg_tx_valid = tx_valid_reg;
    assign dbg_tx_ready = tx_ready;
    assign dbg_rx_valid = rx_valid;
    assign dbg_weights_ready = weights_ready_reg;
    assign dbg_start_mlp = start_mlp_reg;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            cmd_reg <= 8'd0;
            byte_count <= 3'd0;
            weight_seq_idx <= 2'd0;
            act_seq_idx <= 2'd0;
            for (int i = 0; i < 4; i++) begin
                data_buffer[i] <= 8'd0;
                resp_buffer[i] <= 8'd0;
            end
            resp_byte_idx <= 2'd0;
            byte_sent <= 1'b0;
            resp_delay_count <= 8'd0;
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
        end else begin
            // Default: clear control signals (pulse signals)
            wf_push_col0_reg <= 1'b0;
            wf_push_col1_reg <= 1'b0;
            init_act_valid_reg <= 1'b0;
            start_mlp_reg <= 1'b0;
            // Don't clear tx_valid_reg here - it's managed by SEND_RESP state
            // tx_valid_reg <= 1'b0;

            case (state)
                IDLE: begin
                    byte_count <= 3'd0;
                    resp_byte_idx <= 2'd0;
                    byte_sent <= 1'b0;
                    resp_delay_count <= 8'd0;
                    weight_seq_idx <= 2'd0;
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
                        if (rx_data == CMD_WRITE_WEIGHT || rx_data == CMD_WRITE_ACT) begin
                            state <= RECV_DATA;
                        end else if (rx_data == CMD_EXECUTE || 
                                    rx_data == CMD_READ_RESULT || 
                                    rx_data == CMD_STATUS) begin
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
                                weight_seq_idx <= 2'd0;
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
                                state <= EXEC_CMD;
                            end
                        end else begin
                            byte_count <= byte_count + 1;
                        end
                    end
                end

                WRITE_WEIGHT_SEQ: begin
                    // Sequence: W00->col0, W01->col1, W10->col0, W11->col1
                    case (weight_seq_idx)
                        2'd0: begin  // W00 -> col0
                            wf_data_in_reg <= data_buffer[0];
                            wf_push_col0_reg <= 1'b1;
                            weight_seq_idx <= 2'd1;
                        end
                        2'd1: begin  // W01 -> col1
                            wf_data_in_reg <= data_buffer[1];
                            wf_push_col1_reg <= 1'b1;
                            weight_seq_idx <= 2'd2;
                        end
                        2'd2: begin  // W10 -> col0
                            wf_data_in_reg <= data_buffer[2];
                            wf_push_col0_reg <= 1'b1;
                            weight_seq_idx <= 2'd3;
                        end
                        2'd3: begin  // W11 -> col1
                            wf_data_in_reg <= data_buffer[3];
                            wf_push_col1_reg <= 1'b1;
                            weights_ready_reg <= 1'b1;  // Mark weights as ready
                            state <= IDLE;
                        end
                        default: begin
                            state <= IDLE;
                        end
                    endcase
                end

                WRITE_ACT_SEQ: begin
                    // Sequence: Row 0 (A00, A01), Row 1 (A10, A11)
                    case (act_seq_idx)
                        2'd0: begin  // Row 0: A00 (LSB), A01 (MSB)
                            init_act_data_reg <= {data_buffer[1], data_buffer[0]};
                            init_act_valid_reg <= 1'b1;
                            act_seq_idx <= 2'd1;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_ACT_SEQ[0]: Writing row0=0x%04X (A01=%02X, A00=%02X), init_act_valid=1",
                                     {data_buffer[1], data_buffer[0]}, data_buffer[1], data_buffer[0]);
                            // #endregion
                        end
                        2'd1: begin  // Row 1: A10 (LSB), A11 (MSB)
                            init_act_data_reg <= {data_buffer[3], data_buffer[2]};
                            init_act_valid_reg <= 1'b1;
                            state <= IDLE;
                            // #region agent log
                            $display("[UART_CTRL] WRITE_ACT_SEQ[1]: Writing row1=0x%04X (A11=%02X, A10=%02X), init_act_valid=1, going to IDLE",
                                     {data_buffer[3], data_buffer[2]}, data_buffer[3], data_buffer[2]);
                            // #endregion
                        end
                        default: begin
                            state <= IDLE;
                        end
                    endcase
                end

                EXEC_CMD: begin
                    case (cmd_reg)
                        CMD_EXECUTE: begin
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_EXECUTE - setting start_mlp_reg=1, state=%0d", state);
                            // #endregion
                            start_mlp_reg <= 1'b1;
                            // Clear start_mlp_reg next cycle and go to IDLE
                            // The default assignment will clear it, but we set it here so it's visible for one cycle
                            state <= IDLE;
                        end

                        CMD_READ_RESULT: begin
                            // Return 4 bytes: acc0[7:0], acc0[15:8], acc0[23:16], acc0[31:24]
                            resp_buffer[0] <= mlp_acc0[7:0];
                            resp_buffer[1] <= mlp_acc0[15:8];
                            resp_buffer[2] <= mlp_acc0[23:16];
                            resp_buffer[3] <= mlp_acc0[31:24];
                            resp_byte_idx <= 2'd0;
                            byte_sent <= 1'b0;  // Clear flag for new response
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_READ_RESULT - acc0=0x%08X, packing bytes: [7:0]=0x%02X, [15:8]=0x%02X, [23:16]=0x%02X, [31:24]=0x%02X, resp_buffer current=[0x%02X,0x%02X,0x%02X,0x%02X]",
                                     mlp_acc0, mlp_acc0[7:0], mlp_acc0[15:8], mlp_acc0[23:16], mlp_acc0[31:24],
                                     resp_buffer[0], resp_buffer[1], resp_buffer[2], resp_buffer[3]);
                            // #endregion
                            state <= SEND_RESP;
                        end

                        CMD_STATUS: begin
                            // Return 1 byte: [state(2:0) | cycle_cnt(4:0)] = 3+5=8 bits
                            // Use lower 3 bits of state to fit in 8-bit response
                            // Pack the value directly - non-blocking assignment will update resp_buffer[0] at end of time step
                            resp_buffer[0] <= {mlp_state[2:0], mlp_cycle_cnt[4:0]};
                            resp_byte_idx <= 2'd0;
                            byte_sent <= 1'b0;  // Clear flag for new response
                            // #region agent log
                            $display("[UART_CTRL] EXEC_CMD: CMD_STATUS - mlp_state=0x%X[3:0], mlp_cycle_cnt=0x%X[4:0], packed_value=0x%02X (packed: state[2:0]=0x%X, cycle[4:0]=0x%X), resp_buffer[0] current=0x%02X",
                                     mlp_state, mlp_cycle_cnt, {mlp_state[2:0], mlp_cycle_cnt[4:0]}, mlp_state[2:0], mlp_cycle_cnt[4:0], resp_buffer[0]);
                            // #endregion
                            state <= SEND_RESP;
                            // Note: resp_buffer[0] will be updated at end of this time step due to non-blocking assignment
                            // On next cycle in SEND_RESP, resp_buffer[0] will have the new value
                        end

                        default: begin
                            state <= IDLE;
                        end
                    endcase
                end

                SEND_RESP: begin
                    // Add small delay before starting transmission to give test time to start listening
                    if (resp_delay_count < 8'd10) begin
                        resp_delay_count <= resp_delay_count + 1;
                    end else if (!tx_valid_reg && tx_ready && !byte_sent) begin
                        // TX is ready and we haven't sent this byte yet - send it
                        tx_data_reg <= resp_buffer[resp_byte_idx];
                        tx_valid_reg <= 1'b1;
                        byte_sent <= 1'b1;  // Mark byte as sent
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Sending byte[%0d]=0x%02X (from resp_buffer[%0d]=0x%02X), cmd=0x%02X, tx_ready=%b, total_bytes=%0d",
                                 resp_byte_idx, resp_buffer[resp_byte_idx], resp_byte_idx, resp_buffer[resp_byte_idx], cmd_reg, tx_ready,
                                 (cmd_reg == CMD_READ_RESULT) ? 4 : 1);
                        // #endregion
                    end else if (tx_valid_reg && tx_ready) begin
                        // TX valid asserted, waiting for UART TX to accept (tx_ready will go low next cycle)
                        // Just wait - do nothing
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Byte[%0d] waiting for UART TX to accept", resp_byte_idx);
                        // #endregion
                    end else if (tx_valid_reg && !tx_ready) begin
                        // TX accepted the byte (tx_ready went low) - clear tx_valid immediately
                        tx_valid_reg <= 1'b0;
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Byte[%0d] accepted by UART TX, clearing tx_valid", resp_byte_idx);
                        // #endregion
                    end else if (!tx_valid_reg && !tx_ready) begin
                        // TX is transmitting - wait for it to finish
                        // No logging here to avoid spam
                    end else if (!tx_valid_reg && tx_ready && byte_sent) begin
                        // TX finished transmission and is ready - move to next byte or done
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
                                // #region agent log
                                $display("[UART_CTRL] SEND_RESP: Moving to next byte, resp_byte_idx=%0d->%0d",
                                         resp_byte_idx, resp_byte_idx + 1);
                                // #endregion
                            end
                        end else begin
                            // Unknown command
                            // #region agent log
                            $display("[UART_CTRL] SEND_RESP: Unknown command, going to IDLE");
                            // #endregion
                            state <= IDLE;
                        end
                    end else begin
                        // Unexpected state: tx_valid_reg && tx_ready with byte already sent
                        // This shouldn't happen with the new logic
                        // #region agent log
                        $display("[UART_CTRL] SEND_RESP: Unexpected state - tx_valid=%b, tx_ready=%b, byte_sent=%b",
                                 tx_valid_reg, tx_ready, byte_sent);
                        // #endregion
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
