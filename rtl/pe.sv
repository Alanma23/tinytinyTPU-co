`timescale 1ns / 1ps

module pe (
    input  logic        clk,
    input  logic        reset,
    input  logic        en_weight_pass,    // Pass in_psum through out_psum (always during load phase)
    input  logic        en_weight_capture, // Capture weight from in_psum (per-PE timing for diagonal)
    input  logic [7:0]  in_act,
    input  logic [15:0] in_psum,
    output logic [7:0]  out_act,
    output logic [15:0] out_psum
);

    logic [7:0] weight;

    always_ff @(posedge clk) begin
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

