`timescale 1ns / 1ps

module pe(
    input wire clk, 
    input wire reset,
    input wire en_weight_pass,    // Pass in_psum through out_psum (always during load phase)
    input wire en_weight_capture, // Capture weight from in_psum (per-PE timing for diagonal)
    input wire [7:0] in_act,
    input wire [15:0] in_psum,
    output reg [7:0] out_act,
    output reg [15:0] out_psum
);

    reg [7:0] weight;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            out_act <= 8'd0;
            out_psum <= 16'd0;
            weight <= 8'd0;
        end
        else begin
            if (en_weight_pass) begin
                // Weight loading mode: pass psum through, reset activation
                out_psum <= in_psum;
                out_act <= 8'd0;
                // Capture weight only when this PE's capture signal is active
                if (en_weight_capture) begin
                    weight <= in_psum[7:0];
                end
            end
            else begin
                // Compute mode: MAC operation
                out_act <= in_act;
                out_psum <= (in_act * weight) + in_psum;
            end
        end
    end

endmodule