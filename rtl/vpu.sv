`timescale 1ns / 1ps

// Vector Processing Unit (VPU)
// Configurable activation function unit for neural network inference
// Supports: Passthrough, ReLU, ReLU6, Sigmoid, Tanh

module vpu #(
    parameter int SIGMOID_LUT_SIZE = 256,  // Lookup table size for sigmoid
    parameter int TANH_LUT_SIZE = 256      // Lookup table size for tanh
)(
    input  logic        clk,
    input  logic        reset,
    input  logic        valid_in,
    input  logic signed [31:0] data_in0,   // Column 0 input
    input  logic signed [31:0] data_in1,   // Column 1 input
    input  logic [2:0]  activation_type,   // 000=passthrough, 001=ReLU, 010=ReLU6, 011=Sigmoid, 100=Tanh

    output logic        valid_out,
    output logic signed [31:0] data_out0,  // Column 0 output
    output logic signed [31:0] data_out1   // Column 1 output
);

    // Activation type encoding
    localparam logic [2:0] ACT_PASSTHROUGH = 3'b000;
    localparam logic [2:0] ACT_RELU        = 3'b001;
    localparam logic [2:0] ACT_RELU6       = 3'b010;
    localparam logic [2:0] ACT_SIGMOID     = 3'b011;
    localparam logic [2:0] ACT_TANH        = 3'b100;

    // Pipeline registers
    logic        valid_reg;
    logic [2:0]  act_type_reg;
    logic signed [31:0] data_in0_reg, data_in1_reg;

    // Register inputs for pipeline
    always_ff @(posedge clk) begin
        if (reset) begin
            valid_reg <= 1'b0;
            act_type_reg <= ACT_PASSTHROUGH;
            data_in0_reg <= 32'sd0;
            data_in1_reg <= 32'sd0;
        end else begin
            valid_reg <= valid_in;
            act_type_reg <= activation_type;
            data_in0_reg <= data_in0;
            data_in1_reg <= data_in1;
        end
    end

    // Activation function for column 0
    logic signed [31:0] act_out0;
    always_comb begin
        unique case (act_type_reg)
            ACT_PASSTHROUGH: act_out0 = data_in0_reg;
            ACT_RELU:        act_out0 = data_in0_reg[31] ? 32'sd0 : data_in0_reg;
            ACT_RELU6: begin
                if (data_in0_reg[31])
                    act_out0 = 32'sd0;
                else if (data_in0_reg > 32'sd6)
                    act_out0 = 32'sd6;
                else
                    act_out0 = data_in0_reg;
            end
            ACT_SIGMOID:     act_out0 = sigmoid_approx(data_in0_reg);
            ACT_TANH:        act_out0 = tanh_approx(data_in0_reg);
            default:         act_out0 = data_in0_reg;
        endcase
    end

    // Activation function for column 1
    logic signed [31:0] act_out1;
    always_comb begin
        unique case (act_type_reg)
            ACT_PASSTHROUGH: act_out1 = data_in1_reg;
            ACT_RELU:        act_out1 = data_in1_reg[31] ? 32'sd0 : data_in1_reg;
            ACT_RELU6: begin
                if (data_in1_reg[31])
                    act_out1 = 32'sd0;
                else if (data_in1_reg > 32'sd6)
                    act_out1 = 32'sd6;
                else
                    act_out1 = data_in1_reg;
            end
            ACT_SIGMOID:     act_out1 = sigmoid_approx(data_in1_reg);
            ACT_TANH:        act_out1 = tanh_approx(data_in1_reg);
            default:         act_out1 = data_in1_reg;
        endcase
    end

    // Sigmoid approximation: sigmoid(x) = 1 / (1 + exp(-x))
    // Uses piecewise linear approximation with better accuracy
    // Output range: [0, 1] scaled to [0, 256] for Q8.8 fixed point
    function automatic logic signed [31:0] sigmoid_approx(input logic signed [31:0] x);
        logic signed [31:0] result;
        logic signed [31:0] abs_x;
        
        // Handle negative values: sigmoid(-x) = 1 - sigmoid(x)
        if (x[31]) begin
            abs_x = -x;
            if (abs_x > 32'sd8) begin
                result = 32'sd0;  // sigmoid(-8+) ≈ 0
            end else if (abs_x > 32'sd4) begin
                // sigmoid(-4 to -8): exponential tail, very small
                result = 32'sd1;
            end else if (abs_x > 32'sd2) begin
                // sigmoid(-2 to -4): approximate as small value
                result = 32'sd8 - (abs_x - 32'sd2) * 32'sd3;  // Linear from 8 to 1
            end else begin
                // sigmoid(-2 to 0): use polynomial approximation
                // sigmoid(x) ≈ 0.5 + 0.25*x - 0.020833*x^3 for |x| < 2
                logic signed [31:0] x2, x3;
                x2 = (abs_x * abs_x) >>> 8;  // x^2 scaled
                x3 = (x2 * abs_x) >>> 8;     // x^3 scaled
                result = 32'sd128 - (abs_x << 5) + (x3 >> 1);  // 128 - 32*x + x^3/2
            end
            // For negative x, result = 256 - sigmoid(|x|)
            result = 32'sd256 - result;
            if (result < 32'sd0) result = 32'sd0;
        end else begin
            // Positive x
            if (x > 32'sd8) begin
                result = 32'sd255;  // sigmoid(8+) ≈ 1
            end else if (x > 32'sd4) begin
                // sigmoid(4 to 8): exponential tail, very close to 1
                result = 32'sd255 - (32'sd8 - x);
            end else if (x > 32'sd2) begin
                // sigmoid(2 to 4): approximate
                result = 32'sd248 + (x - 32'sd2) * 32'sd3;  // Linear from 248 to 255
            end else begin
                // sigmoid(0 to 2): polynomial approximation
                logic signed [31:0] x2, x3;
                x2 = (x * x) >>> 8;  // x^2 scaled
                x3 = (x2 * x) >>> 8; // x^3 scaled
                result = 32'sd128 + (x << 5) - (x3 >> 1);  // 128 + 32*x - x^3/2
            end
            if (result > 32'sd255) result = 32'sd255;
        end
        return result;
    endfunction

    // Tanh approximation: tanh(x) = (exp(2x) - 1) / (exp(2x) + 1)
    // Uses piecewise linear approximation
    // Output range: [-1, 1] scaled to [-128, 128] for Q7.8 fixed point
    function automatic logic signed [31:0] tanh_approx(input logic signed [31:0] x);
        logic signed [31:0] result;
        logic signed [31:0] abs_x;
        
        // Handle negative values: tanh(-x) = -tanh(x)
        if (x[31]) begin
            abs_x = -x;
            if (abs_x > 32'sd4) begin
                result = -32'sd128;  // tanh(-4+) ≈ -1
            end else if (abs_x > 32'sd2) begin
                // tanh(-2 to -4): approximate
                result = -32'sd128 + (abs_x - 32'sd2) * 32'sd8;  // Linear from -128 to -112
            end else if (abs_x > 32'sd1) begin
                // tanh(-1 to -2): approximate
                result = -32'sd112 + (abs_x - 32'sd1) * 32'sd16;  // Linear from -112 to -96
            end else begin
                // tanh(-1 to 0): polynomial tanh(x) ≈ x - x^3/3 for |x| < 1
                logic signed [31:0] x2, x3;
                x2 = (abs_x * abs_x) >>> 8;
                x3 = (x2 * abs_x) >>> 8;
                result = -(abs_x << 7) + (x3 >> 1);  // -128*x + x^3/2 (scaled)
            end
        end else begin
            // Positive x
            if (x > 32'sd4) begin
                result = 32'sd128;  // tanh(4+) ≈ 1
            end else if (x > 32'sd2) begin
                // tanh(2 to 4): approximate
                result = 32'sd112 + (x - 32'sd2) * 32'sd8;  // Linear from 112 to 128
            end else if (x > 32'sd1) begin
                // tanh(1 to 2): approximate
                result = 32'sd96 + (x - 32'sd1) * 32'sd16;  // Linear from 96 to 112
            end else begin
                // tanh(0 to 1): polynomial approximation
                logic signed [31:0] x2, x3;
                x2 = (x * x) >>> 8;
                x3 = (x2 * x) >>> 8;
                result = (x << 7) - (x3 >> 1);  // 128*x - x^3/2 (scaled)
            end
            if (result > 32'sd128) result = 32'sd128;
        end
        return result;
    endfunction

    // Output registers
    always_ff @(posedge clk) begin
        if (reset) begin
            valid_out <= 1'b0;
            data_out0 <= 32'sd0;
            data_out1 <= 32'sd0;
        end else begin
            valid_out <= valid_reg;
            data_out0 <= act_out0;
            data_out1 <= act_out1;
        end
    end

endmodule

