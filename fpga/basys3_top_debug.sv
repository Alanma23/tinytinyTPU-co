`timescale 1ns / 1ps

// Minimal debug top-level to verify clock and reset are working
// Build this to verify basic functionality before debugging full TPU

module basys3_top_debug (
    input  logic        clk,
    input  logic        btnC,
    output logic [15:0] led
);

    // Global clock buffer
    logic clk_100mhz;
    BUFG bufg_inst (
        .I(clk),
        .O(clk_100mhz)
    );

    // Power-on reset counter
    logic [7:0] rst_counter = 8'hFF;
    logic rst;

    // Synchronize button input
    logic btnC_sync1 = 1'b0, btnC_sync2 = 1'b0;
    always_ff @(posedge clk_100mhz) begin
        btnC_sync1 <= btnC;
        btnC_sync2 <= btnC_sync1;
    end

    always_ff @(posedge clk_100mhz) begin
        if (btnC_sync2) begin
            rst_counter <= 8'hFF;
        end else if (rst_counter != 8'h00) begin
            rst_counter <= rst_counter - 1'b1;
        end
    end

    assign rst = (rst_counter != 8'h00);

    // LED[0]: Heartbeat (toggles every ~10 million clocks = ~0.1 second)
    logic [23:0] heartbeat_counter = 24'd0;
    logic heartbeat = 1'b0;

    always_ff @(posedge clk_100mhz) begin
        if (rst) begin
            heartbeat_counter <= 24'd0;
            heartbeat <= 1'b0;
        end else begin
            if (heartbeat_counter == 24'd10_000_000) begin
                heartbeat_counter <= 24'd0;
                heartbeat <= ~heartbeat;
            end else begin
                heartbeat_counter <= heartbeat_counter + 1'b1;
            end
        end
    end

    // LED[7:0]: Show reset counter (should count down from FF to 00 then stay at 00)
    // LED[8]: Heartbeat
    // LED[9]: Button state
    // LED[10]: Reset signal
    assign led[7:0] = rst_counter;
    assign led[8] = heartbeat;
    assign led[9] = btnC_sync2;
    assign led[10] = rst;
    assign led[15:11] = 5'b0;

endmodule
