`timescale 1ns / 1ps

// Minimal UART RX module
// 8N1 format: 1 start bit, 8 data bits, 1 stop bit, no parity
// Simple mid-bit sampling (no oversampling for simplicity)

module uart_rx #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200
)(
    input  logic       clk,
    input  logic       rst,
    input  logic       rx,
    output logic [7:0] rx_data,
    output logic       rx_valid,
    output logic       rx_ready
);

    localparam CLKS_PER_BIT = CLOCK_FREQ / BAUD_RATE;
    localparam HALF_BIT = CLKS_PER_BIT / 2;

    typedef enum logic [1:0] {
        IDLE  = 2'd0,
        START = 2'd1,
        DATA  = 2'd2,
        STOP  = 2'd3
    } state_t;

    state_t state;
    logic [15:0] clk_count;
    logic [2:0]  bit_index;
    logic [7:0]  rx_byte;

    // Synchronize RX input (prevent metastability)
    logic rx_sync_1, rx_sync_2;
    always_ff @(posedge clk) begin
        rx_sync_1 <= rx;
        rx_sync_2 <= rx_sync_1;
    end

    assign rx_ready = (state == IDLE);

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state     <= IDLE;
            clk_count <= 16'd0;
            bit_index <= 3'd0;
            rx_data   <= 8'd0;
            rx_valid  <= 1'b0;
            rx_byte   <= 8'd0;
        end else begin
            rx_valid <= 1'b0;  // Default: pulse for one cycle

            case (state)
                IDLE: begin
                    clk_count <= 16'd0;
                    bit_index <= 3'd0;

                    if (rx_sync_2 == 1'b0) begin  // Start bit detected (falling edge)
                        state <= START;
                    end
                end

                START: begin
                    // Wait until mid-bit to confirm start bit
                    if (clk_count == HALF_BIT - 1) begin
                        if (rx_sync_2 == 1'b0) begin  // Confirm start bit is still low
                            clk_count <= 16'd0;
                            state <= DATA;
                        end else begin
                            state <= IDLE;  // False start, go back
                        end
                    end else begin
                        clk_count <= clk_count + 1;
                    end
                end

                DATA: begin
                    // Sample at mid-bit of each data bit
                    if (clk_count == CLKS_PER_BIT - 1) begin
                        clk_count <= 16'd0;
                        rx_byte[bit_index] <= rx_sync_2;  // LSB first

                        if (bit_index == 3'd7) begin
                            bit_index <= 3'd0;
                            state <= STOP;
                        end else begin
                            bit_index <= bit_index + 1;
                        end
                    end else begin
                        clk_count <= clk_count + 1;
                    end
                end

                STOP: begin
                    // Wait for stop bit duration
                    if (clk_count == CLKS_PER_BIT - 1) begin
                        clk_count <= 16'd0;
                        if (rx_sync_2 == 1'b1) begin  // Valid stop bit
                            rx_data  <= rx_byte;
                            rx_valid <= 1'b1;
                        end
                        // Go back to IDLE regardless (even on framing error)
                        state <= IDLE;
                    end else begin
                        clk_count <= clk_count + 1;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
