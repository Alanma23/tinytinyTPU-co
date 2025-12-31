`timescale 1ns / 1ps

module uart_tx #(
    parameter CLOCK_FREQ = 100_000_000,
    parameter BAUD_RATE  = 115200
)(
    input  logic       clk,
    input  logic       rst,
    output logic       tx,
    input  logic [7:0] tx_data,
    input  logic       tx_valid,
    output logic       tx_ready
);

localparam CLKS_PER_BIT = CLOCK_FREQ / BAUD_RATE;

localparam IDLE  = 2'd0;
localparam START = 2'd1;
localparam DATA  = 2'd2;
localparam STOP  = 2'd3;

logic [1:0] state;
logic [15:0] clk_count;
logic [2:0] bit_index;
logic [7:0] tx_byte;

assign tx_ready = (state == IDLE);

always @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        clk_count <= 16'd0;
        bit_index <= 3'd0;
        tx <= 1'b1;
        tx_byte <= 8'd0;
    end else begin
        case (state)
            IDLE: begin
                tx <= 1'b1;  // Idle high
                clk_count <= 16'd0;
                bit_index <= 3'd0;

                if (tx_valid) begin
                    tx_byte <= tx_data;
                    state <= START;
                end
            end

            START: begin
                tx <= 1'b0;  // Start bit

                if (clk_count == CLKS_PER_BIT - 1) begin
                    clk_count <= 16'd0;
                    state <= DATA;
                end else begin
                    clk_count <= clk_count + 1;
                end
            end

            DATA: begin
                tx <= tx_byte[bit_index];

                if (clk_count == CLKS_PER_BIT - 1) begin
                    clk_count <= 16'd0;

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
                tx <= 1'b1;  // Stop bit

                if (clk_count == CLKS_PER_BIT - 1) begin
                    clk_count <= 16'd0;
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
