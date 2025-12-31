`timescale 1ns / 1ps

// UART Controller for mlp_top
// Minimal command protocol to load weights, activations, run inference, read results
//
// Command Protocol:
//   0x01 = Write Weights  (4 bytes follow: W10, W00, W11, W01 in FIFO load order)
//   0x02 = Write Activations (4 bytes follow: A00, A01, A10, A11)
//   0x03 = Execute (start inference)
//   0x04 = Read Status (returns 1 byte: {4'b0, state[3:0]})
//   0x05 = Read Results (returns 8 bytes: acc0[31:0] LSB first, then acc1[31:0])
//   0x06 = Signal Weights Ready (for multi-layer)

module uart_controller #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200
)(
    input  logic        clk,
    input  logic        rst,

    // UART pins
    input  logic        uart_rx_pin,
    output logic        uart_tx_pin,

    // To mlp_top: Weight FIFO interface
    output logic        wf_push_col0,
    output logic        wf_push_col1,
    output logic [7:0]  wf_data_in,
    output logic        wf_reset,

    // To mlp_top: Activation loading
    output logic        init_act_valid,
    output logic [15:0] init_act_data,

    // To mlp_top: Control
    output logic        start_mlp,
    output logic        weights_ready,

    // From mlp_top: Status
    input  logic [3:0]  state_in,
    input  logic        layer_complete,
    input  logic signed [31:0] acc0,
    input  logic signed [31:0] acc1,

    // Debug
    output logic [7:0]  debug_state,
    output logic [7:0]  debug_cmd
);

    // =========================================================================
    // UART RX/TX instances
    // =========================================================================
    logic [7:0] rx_data;
    logic       rx_valid;
    logic       rx_ready;

    uart_rx #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart_rx_inst (
        .clk(clk),
        .rst(rst),
        .rx(uart_rx_pin),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
        .rx_ready(rx_ready)
    );

    logic [7:0] tx_data;
    logic       tx_valid;
    logic       tx_ready;

    uart_tx #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart_tx_inst (
        .clk(clk),
        .rst(rst),
        .tx(uart_tx_pin),
        .tx_data(tx_data),
        .tx_valid(tx_valid),
        .tx_ready(tx_ready)
    );

    // =========================================================================
    // Command State Machine
    // =========================================================================
    typedef enum logic [3:0] {
        IDLE            = 4'd0,
        WRITE_WEIGHTS   = 4'd1,  // Receive 4 weight bytes
        WRITE_ACT       = 4'd2,  // Receive 4 activation bytes
        EXECUTE         = 4'd3,  // Pulse start_mlp
        SEND_STATUS     = 4'd4,  // Send 1 status byte
        SEND_RESULTS    = 4'd5,  // Send 8 result bytes
        SIGNAL_READY    = 4'd6   // Pulse weights_ready
    } cmd_state_t;

    cmd_state_t cmd_state;
    logic [7:0] command;
    logic [2:0] byte_count;      // Count received/sent bytes (0-7)
    logic [31:0] weight_buffer;  // Hold received weights
    logic [31:0] act_buffer;     // Hold received activations
    logic [63:0] result_buffer;  // Hold results to send
    logic        rx_valid_prev;  // For edge detection

    assign debug_state = {4'b0, cmd_state};
    assign debug_cmd = command;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            cmd_state      <= IDLE;
            command        <= 8'd0;
            byte_count     <= 3'd0;
            weight_buffer  <= 32'd0;
            act_buffer     <= 32'd0;
            result_buffer  <= 64'd0;
            rx_valid_prev  <= 1'b0;

            // mlp_top outputs
            wf_push_col0   <= 1'b0;
            wf_push_col1   <= 1'b0;
            wf_data_in     <= 8'd0;
            wf_reset       <= 1'b0;
            init_act_valid <= 1'b0;
            init_act_data  <= 16'd0;
            start_mlp      <= 1'b0;
            weights_ready  <= 1'b0;

            // TX outputs
            tx_valid       <= 1'b0;
            tx_data        <= 8'd0;
        end else begin
            // Edge detection for rx_valid
            rx_valid_prev <= rx_valid;

            // Default: clear single-cycle pulses
            wf_push_col0   <= 1'b0;
            wf_push_col1   <= 1'b0;
            init_act_valid <= 1'b0;
            start_mlp      <= 1'b0;
            weights_ready  <= 1'b0;
            wf_reset       <= 1'b0;

            case (cmd_state)
                // =============================================================
                // IDLE: Wait for command byte
                // =============================================================
                IDLE: begin
                    tx_valid <= 1'b0;
                    byte_count <= 3'd0;

                    if (rx_valid && !rx_valid_prev) begin
                        command <= rx_data;
                        case (rx_data)
                            8'h01: begin
                                cmd_state <= WRITE_WEIGHTS;
                                wf_reset <= 1'b1;  // Reset FIFO before loading new weights
                            end
                            8'h02: cmd_state <= WRITE_ACT;
                            8'h03: cmd_state <= EXECUTE;
                            8'h04: cmd_state <= SEND_STATUS;
                            8'h05: begin
                                cmd_state <= SEND_RESULTS;
                                // Capture results at command time
                                result_buffer <= {acc1, acc0};  // acc0 at LSB
                            end
                            8'h06: cmd_state <= SIGNAL_READY;
                            default: cmd_state <= IDLE;  // Unknown command, ignore
                        endcase
                    end
                end

                // =============================================================
                // WRITE_WEIGHTS: Receive 4 bytes, push to weight FIFO
                // Byte order: W10, W00, W11, W01 (matches dual_weight_fifo load)
                // =============================================================
                WRITE_WEIGHTS: begin
                    if (rx_valid && !rx_valid_prev) begin
                        weight_buffer <= {rx_data, weight_buffer[31:8]};  // Shift in LSB first
                        byte_count <= byte_count + 1;

                        // Push to FIFO as bytes arrive
                        case (byte_count)
                            3'd0: begin  // W10 -> col0
                                wf_push_col0 <= 1'b1;
                                wf_data_in <= rx_data;
                            end
                            3'd1: begin  // W00 -> col0
                                wf_push_col0 <= 1'b1;
                                wf_data_in <= rx_data;
                            end
                            3'd2: begin  // W11 -> col1
                                wf_push_col1 <= 1'b1;
                                wf_data_in <= rx_data;
                            end
                            3'd3: begin  // W01 -> col1
                                wf_push_col1 <= 1'b1;
                                wf_data_in <= rx_data;
                                // Done, send ACK
                                if (tx_ready) begin
                                    tx_valid <= 1'b1;
                                    tx_data <= 8'hAA;  // ACK
                                end
                                cmd_state <= IDLE;
                            end
                            default: cmd_state <= IDLE;
                        endcase
                    end
                end

                // =============================================================
                // WRITE_ACT: Receive 4 bytes, pack into 2x 16-bit words
                // Byte order: A00, A01, A10, A11
                // Packing: init_act_data = {row1, row0} per column pair
                // =============================================================
                WRITE_ACT: begin
                    if (rx_valid && !rx_valid_prev) begin
                        act_buffer <= {rx_data, act_buffer[31:8]};  // Shift in
                        byte_count <= byte_count + 1;

                        case (byte_count)
                            3'd1: begin  // After A00, A01 received
                                // Pack {A01, A00} but we only have A00 so far
                            end
                            3'd3: begin  // All 4 bytes received
                                // Push two 16-bit words to UB
                                // Word 0: {A10, A00} = row0 data for columns
                                // Word 1: {A11, A01} = row1 data for columns
                                // Actually mlp_top expects {row1_col, row0_col} per word
                                // init_act_data = {act[row,1], act[row,0]} packed

                                // Row 0: A[0,0], A[0,1] -> {A01, A00}
                                init_act_valid <= 1'b1;
                                init_act_data <= {act_buffer[15:8], act_buffer[7:0]};  // {A01, A00}
                            end
                            default: ;
                        endcase

                        if (byte_count == 3'd3) begin
                            // Send ACK and go to IDLE
                            if (tx_ready) begin
                                tx_valid <= 1'b1;
                                tx_data <= 8'hAA;
                            end
                            cmd_state <= IDLE;
                        end
                    end
                end

                // =============================================================
                // EXECUTE: Pulse start_mlp for one cycle
                // =============================================================
                EXECUTE: begin
                    start_mlp <= 1'b1;
                    if (tx_ready) begin
                        tx_valid <= 1'b1;
                        tx_data <= 8'hAA;  // ACK
                    end
                    cmd_state <= IDLE;
                end

                // =============================================================
                // SEND_STATUS: Send 1 byte with mlp state
                // =============================================================
                SEND_STATUS: begin
                    if (tx_ready && !tx_valid) begin
                        tx_valid <= 1'b1;
                        tx_data <= {3'b0, layer_complete, state_in};  // [4]=done, [3:0]=state
                        cmd_state <= IDLE;
                    end
                end

                // =============================================================
                // SEND_RESULTS: Send 8 bytes (acc0 then acc1, LSB first)
                // =============================================================
                SEND_RESULTS: begin
                    if (tx_ready) begin
                        if (tx_valid) begin
                            // Previous byte accepted, move to next
                            tx_valid <= 1'b0;
                            result_buffer <= {8'h00, result_buffer[63:8]};  // Shift out LSB
                            byte_count <= byte_count + 1;

                            if (byte_count == 3'd7) begin
                                cmd_state <= IDLE;
                            end
                        end else begin
                            // Send next byte
                            tx_valid <= 1'b1;
                            tx_data <= result_buffer[7:0];
                        end
                    end
                end

                // =============================================================
                // SIGNAL_READY: Pulse weights_ready for multi-layer
                // =============================================================
                SIGNAL_READY: begin
                    weights_ready <= 1'b1;
                    if (tx_ready) begin
                        tx_valid <= 1'b1;
                        tx_data <= 8'hAA;  // ACK
                    end
                    cmd_state <= IDLE;
                end

                default: cmd_state <= IDLE;
            endcase
        end
    end

endmodule

