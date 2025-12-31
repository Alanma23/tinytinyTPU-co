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
    input  logic        uart_rxd_out,  // From PC to FPGA (RX)
    output logic        uart_txd_in,   // From FPGA to PC (TX)

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

    // Synchronize reset button (active high) - double synchronizer
    logic rst_sync1, rst_sync2, rst;
    always_ff @(posedge clk_100mhz) begin
        rst_sync1 <= btnC;
        rst_sync2 <= rst_sync1;
        rst <= rst_sync2;
    end


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

    // Instantiate TPU
    tpu_top #(
        .CLOCK_FREQ(100_000_000),  // 100 MHz
        .BAUD_RATE(115200)          // 115200 baud
    ) tpu_inst (
        .clk(clk_100mhz),
        .rst(rst),
        .uart_rx(uart_rxd_out),     // From PC (buffers inferred)
        .uart_tx(uart_txd_in)       // To PC (buffers inferred)
    );


    // ========================================================================
    // Debug Signal Extraction
    // ========================================================================

    // Extract internal status signals for LED display
    assign tpu_mlp_state      = tpu_inst.mlp_u.state;
    assign tpu_mlp_cycle_cnt  = tpu_inst.mlp_u.cycle_cnt;
    assign tpu_mlp_layer      = tpu_inst.mlp_u.current_layer;
    assign tpu_layer_complete = tpu_inst.mlp_u.layer_complete;
    assign tpu_acc0           = tpu_inst.mlp_u.acc0;
    assign tpu_acc1           = tpu_inst.mlp_u.acc1;
    assign tpu_acc_valid      = tpu_inst.mlp_u.acc_valid;


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

    logic [15:0] led_next;

    always_comb begin
        case (sw_sync2[15:14])
            2'b00: begin  // MLP State and Status
                led_next[3:0]   = tpu_mlp_state;           // MLP FSM state
                led_next[6:4]   = tpu_mlp_layer;           // Current layer
                led_next[7]     = tpu_layer_complete;      // Layer complete flag
                led_next[8]     = tpu_acc_valid;           // Accumulator valid
                led_next[9]     = ~uart_rxd_out;           // UART RX line state (inverted for visibility)
                led_next[10]    = ~uart_txd_in;            // UART TX line state (inverted for visibility)
                led_next[11]    = rst;                     // Reset indicator
                led_next[15:12] = tpu_inst.uart_ctrl_u.state;  // UART controller state
            end

            2'b01: begin  // Accumulator Result (lower 16 bits of acc0)
                led_next[15:0] = tpu_acc0[15:0];
            end

            2'b10: begin  // UART Controller Detail
                led_next[3:0]  = tpu_inst.uart_ctrl_u.state;
                led_next[7:4]  = {tpu_inst.uart_ctrl_u.cmd_reg[3:0]};
                led_next[10:8] = tpu_inst.uart_ctrl_u.byte_count;
                led_next[12:11] = tpu_inst.uart_ctrl_u.resp_byte_idx;
                led_next[13]   = tpu_inst.uart_ctrl_u.tx_valid_reg;
                led_next[14]   = tpu_inst.uart_ctrl_u.rx_valid;
                led_next[15]   = tpu_inst.uart_ctrl_u.weights_ready_reg;
            end

            2'b11: begin  // Debug: UART Controller Internal State
                led_next[3:0]  = tpu_inst.uart_ctrl_u.state;    // UART controller state
                led_next[7:4]  = {tpu_inst.uart_ctrl_u.cmd_reg[3:0]}; // Current command
                led_next[10:8] = tpu_inst.uart_ctrl_u.byte_count; // Byte counter
                led_next[11]   = tpu_inst.uart_ctrl_u.rx_valid;   // RX valid
                led_next[12]   = tpu_inst.uart_ctrl_u.tx_ready;   // TX ready
                led_next[13]   = tpu_inst.uart_ctrl_u.weights_ready_reg; // Weights ready
                led_next[14]   = tpu_inst.uart_ctrl_u.start_mlp_reg; // Start MLP signal
                led_next[15]   = rst;                            // Reset
            end
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
