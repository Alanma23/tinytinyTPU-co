`timescale 1ns / 1ps

// Basys3 Top-Level Wrapper for TinyTinyTPU v1
// Artix-7 XC7A35T-1CPG236C FPGA
//
// Features:
// - 100 MHz clock input (matches TPU clock requirement)
// - USB-UART interface for host communication
// - LED indicators for status visualization
// - Push button reset
// - Switch-based debug controls

module basys3_top (
    // Clock (100 MHz oscillator)
    input  logic        clk,

    // Reset button (active high, CENTER button)
    input  logic        btnC,

    // UART (USB-UART bridge)
    input  logic        uart_rx,   // From PC to FPGA (RX)
    output logic        uart_tx,   // From FPGA to PC (TX)

    // LEDs for status indication
    output logic [15:0] led,

    // Switches for debug/control
    input  logic [15:0] sw
);

    // ========================================================================
    // Clock and Reset Management
    // ========================================================================

    // Global clock buffer for 100 MHz clock (IBUF will be inferred)
    logic clk_100mhz;
    BUFG bufg_inst (
        .I(clk),
        .O(clk_100mhz)
    );

    // Power-on reset and button reset logic
    // Generate 255-cycle reset pulse on power-up, plus reset on button press
    logic [7:0] rst_counter = 8'hFF;  // Power-on reset: starts at FF, counts down to 0
    logic rst;

    // Synchronize button input (initialized to prevent X propagation)
    logic btnC_sync1 = 1'b0, btnC_sync2 = 1'b0;
    always_ff @(posedge clk_100mhz) begin
        btnC_sync1 <= btnC;
        btnC_sync2 <= btnC_sync1;
    end

    // Reset counter: counts down from FF to 0, or resets to FF on button press
    always_ff @(posedge clk_100mhz) begin
        if (btnC_sync2) begin
            rst_counter <= 8'hFF;  // Button pressed: restart reset pulse
        end else if (rst_counter != 8'h00) begin
            rst_counter <= rst_counter - 1'b1;  // Count down
        end
    end

    // Reset is active while counter is non-zero
    assign rst = (rst_counter != 8'h00);

    // ========================================================================
    // TPU Instantiation
    // ========================================================================

    // TPU status signals
    logic [3:0]  tpu_mlp_state;
    logic [4:0]  tpu_mlp_cycle_cnt;
    logic [2:0]  tpu_mlp_layer;
    logic        tpu_layer_complete;
    logic signed [31:0] tpu_acc0;
    logic signed [31:0] tpu_acc1;
    logic        tpu_acc_valid;
    logic [3:0]  uart_state_dbg;
    logic [7:0]  uart_cmd_dbg;
    logic [2:0]  uart_byte_count_dbg;
    logic [1:0]  uart_resp_idx_dbg;
    logic        uart_tx_valid_dbg;
    logic        uart_tx_ready_dbg;
    logic        uart_rx_valid_dbg;
    logic [7:0]  uart_rx_data_dbg;
    logic        uart_weights_ready_dbg;
    logic        uart_start_mlp_dbg;

    // #region agent log
    always_ff @(posedge clk_100mhz) begin
        if (rst_counter == 8'hFE || rst_counter == 8'h01 || (rst_counter[3:0] == 4'h0 && rst_counter != 8'h00)) begin
            $display("[BASYS3_TOP] rst=%d, rst_counter=0x%02X, tpu_mlp_state=%d, tpu_mlp_cycle_cnt=%d, tpu_mlp_acc0=%d, uart_state=%d",
                     rst, rst_counter, tpu_mlp_state, tpu_mlp_cycle_cnt, tpu_acc0, uart_state_dbg);
        end
    end
    // #endregion

    // Instantiate TPU
    tpu_top #(
        .CLOCK_FREQ(100_000_000),  // 100 MHz
        .BAUD_RATE(115200)          // 115200 baud
    ) tpu_inst (
        .clk(clk_100mhz),
        .rst(rst),
        .uart_rx(uart_rx),
        .uart_tx(uart_tx),
        .mlp_state_dbg(tpu_mlp_state),
        .mlp_cycle_cnt_dbg(tpu_mlp_cycle_cnt),
        .mlp_layer_dbg(tpu_mlp_layer),
        .mlp_layer_complete_dbg(tpu_layer_complete),
        .mlp_acc0_dbg(tpu_acc0),
        .mlp_acc1_dbg(tpu_acc1),
        .mlp_acc_valid_dbg(tpu_acc_valid),
        .uart_state_dbg(uart_state_dbg),
        .uart_cmd_dbg(uart_cmd_dbg),
        .uart_byte_count_dbg(uart_byte_count_dbg),
        .uart_resp_idx_dbg(uart_resp_idx_dbg),
        .uart_tx_valid_dbg(uart_tx_valid_dbg),
        .uart_tx_ready_dbg(uart_tx_ready_dbg),
        .uart_rx_valid_dbg(uart_rx_valid_dbg),
        .uart_rx_data_dbg(uart_rx_data_dbg),
        .uart_weights_ready_dbg(uart_weights_ready_dbg),
        .uart_start_mlp_dbg(uart_start_mlp_dbg)
    );


    // ========================================================================
    // Debug Signal Extraction
    // ========================================================================

    // Extract internal status signals for LED display
    // (Signals already driven by tpu_top connections above)


    // ========================================================================
    // LED Status Display (Registered outputs to avoid unbuffered IO errors)
    // ========================================================================

    // Synchronize switch inputs
    logic [15:0] sw_sync1, sw_sync2;
    always_ff @(posedge clk_100mhz) begin
        sw_sync1 <= sw;
        sw_sync2 <= sw_sync1;
    end

// LED mapping based on sw[15:14] mode select
// Mode 00: MLP State and Status (LED9/10 inverted for visibility)
// Mode 01: Accumulator Result (acc0 lower 16 bits)
// Mode 10: UART Controller Detail
// Mode 11: UART Controller Internal Debug

// Debug LED test patterns (use SW[13:12] when SW[15:14] = 00)
logic [15:0] debug_led_test;
always_comb begin
    case (sw_sync2[13:12])
        2'b00: debug_led_test = 16'h0000;  // All off
        2'b01: debug_led_test = 16'h5555;  // 01010101...
        2'b10: debug_led_test = 16'hAAAA;  // 10101010...
        2'b11: debug_led_test = 16'hFFFF;  // All on
    endcase
end

    logic [15:0] led_next;

    always_comb begin
        led_next = 16'h0000;
        case (sw_sync2[15:14])
            2'b00: begin  // MLP State and Status
                // Use debug test pattern if SW[13:12] != 00, otherwise show actual status
                if (sw_sync2[13:12] != 2'b00) begin
                    led_next = debug_led_test;  // Debug LED test pattern
                end else begin
                    led_next[3:0]   = tpu_mlp_state;           // MLP FSM state
                    led_next[6:4]   = tpu_mlp_layer;           // Current layer
                    led_next[7]     = tpu_layer_complete;      // Layer complete flag
                    led_next[8]     = tpu_acc_valid;           // Accumulator valid
                    led_next[9]     = ~uart_rx;                // UART RX line state (inverted for visibility)
                    led_next[10]    = ~uart_tx;                // UART TX line state (inverted for visibility)
                    led_next[11]    = rst;                     // Reset indicator
                    led_next[15:12] = uart_state_dbg;          // UART controller state
                end
            end

            2'b01: begin  // Accumulator Result (lower 16 bits of acc0)
                led_next[15:0] = tpu_acc0[15:0];
            end

            2'b10: begin  // UART Controller Detail / Echo Test
                if (sw_sync2[13]) begin
                    // Echo mode: Display last received byte
                    led_next[7:0]   = uart_rx_data_dbg;  // Last received byte on LEDs[7:0]
                    led_next[8]     = uart_rx_valid_dbg;  // RX valid indicator
                    led_next[15:9]  = 7'b0;               // Upper LEDs off
                end else begin
                    // UART Controller Detail
                    led_next[3:0]   = uart_state_dbg;
                    led_next[7:4]   = uart_cmd_dbg[3:0];
                    led_next[10:8]  = uart_byte_count_dbg;
                    led_next[12:11] = uart_resp_idx_dbg;
                    led_next[13]    = uart_tx_valid_dbg;
                    led_next[14]    = uart_rx_valid_dbg;
                    led_next[15]    = uart_weights_ready_dbg;
                end
            end

            2'b11: begin  // Debug: UART Controller Internal State
                led_next[3:0]   = uart_state_dbg;
                led_next[7:4]   = uart_cmd_dbg[7:4];
                led_next[10:8]  = uart_byte_count_dbg;
                led_next[11]    = uart_rx_valid_dbg;
                led_next[12]    = uart_tx_ready_dbg;
                led_next[13]    = uart_weights_ready_dbg;
                led_next[14]    = uart_start_mlp_dbg;
                led_next[15]   = rst;                            // Reset
            end

            default: led_next = 16'h0000;
        endcase
    end

    // Register LED outputs
    logic [15:0] led_reg;
    always_ff @(posedge clk_100mhz) begin
        if (rst) begin
            led_reg <= 16'b0;
        end else begin
            led_reg <= led_next;
        end
    end

    // Connect to output port (OBUFs will be inferred)
    assign led = led_reg;

endmodule
