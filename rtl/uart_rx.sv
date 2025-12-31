`timescale 1ns / 1ps

// Improved UART RX with oversampling for noise immunity
// Based on Shubhayu-Das/UART-basys3 implementation
// Uses 15x oversampling with majority vote on middle 3 samples

module uart_rx_improved #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200,
    parameter OVERSAMPLE = 15  // Sample each bit 15 times
)(
    input  logic       clk,
    input  logic       rst,
    input  logic       rx,
    output logic [7:0] rx_data,
    output logic       rx_valid,
    output logic       framing_error,
    output logic       rx_ready
);

// Improved baud rate calculation: Compensate for integer truncation error
// CLKS_PER_BIT = 868.056, CLKS_PER_SAMPLE = 57.87 (truncated to 57)
// Error: 0.87 clocks per sample * 15 samples = 13.05 clocks per bit
// Solution: Sample 2 times at 57 clocks, then 13 times at 58 clocks
// Average: (2*57 + 13*58) / 15 = 868/15 = 57.87 (matches ideal)
localparam CLKS_PER_BIT = CLOCK_FREQ / BAUD_RATE;  // = 868
localparam CLKS_PER_SAMPLE = CLKS_PER_BIT / OVERSAMPLE;  // = 57 (truncated from 57.87)
localparam HALF_BIT = CLKS_PER_BIT / 2;
localparam SAMPLE_ADJUST_THRESHOLD = 2;  // First 2 samples (0-1) at 57 clocks, then 13 samples (2-14) at 58 clocks

// Sample middle 3 locations for majority vote (samples 6, 7, 8 out of 15)
localparam SAMPLE_START = 6;
localparam SAMPLE_END = 8;

localparam IDLE  = 2'd0;
localparam START = 2'd1;
localparam DATA  = 2'd2;
localparam STOP  = 2'd3;

logic [1:0] state;
logic [15:0] clk_count;
logic [3:0] sample_count;  // Count samples within a bit period
logic [2:0] bit_index;
logic [7:0] rx_byte;
logic [2:0] sample_buffer;  // Store middle 3 samples for majority vote
logic [15:0] sample_threshold;  // Dynamic threshold based on sample_count

// Synchronize RX input (prevent metastability)
logic rx_sync_1, rx_sync_2;
always @(posedge clk) begin
    rx_sync_1 <= rx;
    rx_sync_2 <= rx_sync_1;
end

// #region agent log - Track RX pin state (HYPOTHESIS A)
// Export RX pin state for debugging (can be read via LEDs or debug interface)
// In UART, idle should be HIGH (1), start bit is LOW (0)
// #endregion

assign rx_ready = (state == IDLE);
assign sample_threshold = (sample_count < SAMPLE_ADJUST_THRESHOLD) ? CLKS_PER_SAMPLE : (CLKS_PER_SAMPLE + 1);

always @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        clk_count <= 16'd0;
        sample_count <= 4'd0;
        bit_index <= 3'd0;
        rx_data <= 8'd0;
        rx_valid <= 1'b0;
        framing_error <= 1'b0;
        rx_byte <= 8'd0;
        sample_buffer <= 3'd0;
    end else begin
        rx_valid <= 1'b0;  // Default
        framing_error <= 1'b0;  // Default

        case (state)
            IDLE: begin
                clk_count <= 16'd0;
                sample_count <= 4'd0;
                bit_index <= 3'd0;

                if (rx_sync_2 == 1'b0) begin  // Start bit detected
                    state <= START;
                    clk_count <= 16'd0;
                end
            end

            START: begin
                // Wait until mid-bit to confirm start bit
                if (clk_count == HALF_BIT - 1) begin
                    if (rx_sync_2 == 1'b0) begin  // Confirm start bit
                        clk_count <= 16'd0;
                        sample_count <= 4'd0;
                        state <= DATA;
                    end else begin
                        state <= IDLE;  // False start
                    end
                end else begin
                    clk_count <= clk_count + 1;
                end
            end

            DATA: begin
                // Sample at CLKS_PER_SAMPLE intervals with error compensation
                // To compensate for integer truncation (57.87 -> 57), sample 2 times at 57 clocks,
                // then 13 times at 58 clocks to average 57.87 clocks per sample
                // This distributes the 13-clock error evenly: (2*57 + 13*58) / 15 = 868/15 = 57.87
                if (clk_count >= sample_threshold - 1) begin
                    // Reset clk_count to 0 (not subtracting threshold to avoid wrap-around issues)
                    clk_count <= 16'd0;
                    
                    // Store middle 3 samples
                    if (sample_count >= SAMPLE_START && sample_count <= SAMPLE_END) begin
                        sample_buffer[sample_count - SAMPLE_START] <= rx_sync_2;
                    end
                    
                    sample_count <= sample_count + 1;
                    
                    // After all samples, do majority vote
                    if (sample_count == OVERSAMPLE - 1) begin
                        // Majority vote: if 2 or 3 samples are 1, bit is 1
                        rx_byte[bit_index] <= (sample_buffer[0] + sample_buffer[1] + sample_buffer[2] >= 2);
                        sample_count <= 4'd0;
                        clk_count <= 16'd0;  // Reset clk_count for next bit sampling

                        if (bit_index == 3'd7) begin
                            bit_index <= 3'd0;
                            state <= STOP;
                        end else begin
                            bit_index <= bit_index + 1;
                        end
                    end
                end else begin
                    clk_count <= clk_count + 1;
                end
            end

            STOP: begin
                if (clk_count == CLKS_PER_BIT - 1) begin
                    clk_count <= 16'd0;
                    if (rx_sync_2 == 1'b1) begin  // Valid stop bit
                        rx_data <= rx_byte;
                        rx_valid <= 1'b1;
                        framing_error <= 1'b0;
                    end else begin
                        // Framing error: stop bit not HIGH
                        framing_error <= 1'b1;
                        rx_valid <= 1'b0;
                    end
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

