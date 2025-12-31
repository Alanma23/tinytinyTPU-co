`timescale 1ns / 1ps

module activation_pipeline_tb;
    reg clk, reset;
    reg valid_in;
    reg signed [31:0] acc_in;
    reg signed [31:0] target_in;

    // Config
    reg signed [15:0] norm_gain;
    reg signed [31:0] norm_bias;
    reg [4:0] norm_shift;
    reg signed [15:0] q_inv_scale; // 1/S in Q8.8
    reg signed [7:0] q_zero_point;

    wire        valid_out;
    wire signed [7:0] ub_data_out;
    wire        loss_valid;
    wire signed [31:0] loss_out;

    // Scoreboard storage
    integer head = 0, tail = 0;
    reg signed [31:0] exp_ub   [0:63];
    reg signed [31:0] exp_loss [0:63];

    activation_pipeline dut (
        .clk(clk),
        .reset(reset),
        .valid_in(valid_in),
        .acc_in(acc_in),
        .target_in(target_in),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(valid_out),
        .ub_data_out(ub_data_out),
        .loss_valid(loss_valid),
        .loss_out(loss_out)
    );

    // 10ns clock
    always #5 clk = ~clk;

    initial begin
        clk = 0; reset = 1; valid_in = 0;
        acc_in = 0; target_in = 0;
        norm_gain = 16'sd256;     // 1.0 in Q8
        norm_bias = 32'sd0;
        norm_shift = 5'd8;        // divide by 256 to undo gain
        q_inv_scale = 16'sd256;   // 1/S with S=1.0 in Q8.8
        q_zero_point = 8'sd0;

        #12 reset = 0;

        // --- Base config: S=1.0, ReLU default ---
        send_sample(32'sd20, 32'sd15);    // expect 20, loss 5
        send_sample(-32'sd5, 32'sd2);     // expect 0, loss 2 (ReLU clamp)
        send_sample(32'sd200, 32'sd100);  // expect saturation to 127, loss 100

        // --- Change quant scale to S=0.5 (q_inv_scale = 2.0 in Q8.8 = 512) ---
        @(negedge clk);
        q_inv_scale = 16'sd512;           // scale up by 2x before saturation
        send_sample(32'sd50, 32'sd0);     // expect 100
        send_sample(32'sd80, 32'sd10);    // expect 160 -> saturate 127, loss based on norm

        // --- Add bias test on normalization ---
        @(negedge clk);
        norm_bias = 32'sd10;
        norm_gain = 16'sd256; // keep 1.0
        norm_shift = 5'd8;
        send_sample(32'sd5, 32'sd0);      // ReLU->5, norm adds 10 => 15

        #200;
        $display("TB finished.");
        if (head != tail) $fatal("Did not consume all expected samples (head=%0d tail=%0d)", head, tail);
        $finish;
    end

    task send_sample(input signed [31:0] acc, input signed [31:0] tgt);
        reg signed [31:0] act;
        reg signed [31:0] norm;
        reg signed [31:0] qexp;
        reg signed [31:0] loss;
        begin
            // Compute expected activation (DEFAULT_ACT is ReLU)
            act = acc[31] ? 32'sd0 : acc;

            // Normalization: (act * gain) >> shift + bias
            norm = ((act * norm_gain) >>> norm_shift) + norm_bias;

            // Quantization: x_q = clip(round(norm * (1/S)) + Z, -128, 127)
            qexp = quantize_expected(norm, q_inv_scale, q_zero_point);

            // Loss: |norm - target|
            loss = norm - tgt;
            if (loss[31]) loss = -loss;

            exp_ub[tail]   = qexp;
            exp_loss[tail] = loss;
            tail = tail + 1;

            @(negedge clk);
            acc_in <= acc;
            target_in <= tgt;
            valid_in <= 1'b1;
            @(negedge clk);
            valid_in <= 1'b0;
        end
    endtask

    function signed [31:0] quantize_expected;
        input signed [31:0] val;
        input signed [15:0] inv_scale;
        input signed [7:0]  zpt;
        reg signed [47:0] mult;
        reg signed [47:0] mult_r;
        reg signed [31:0] scaled;
        reg signed [31:0] biased;
        begin
            mult   = val * inv_scale;
            mult_r = mult + 48'sd128;      // round half-up
            scaled = mult_r >>> 8;
            biased = scaled + {{24{zpt[7]}}, zpt};
            if (biased > 32'sd127)       quantize_expected = 32'sd127;
            else if (biased < -32'sd128) quantize_expected = -32'sd128;
            else                         quantize_expected = biased;
        end
    endfunction

    // Check outputs against scoreboard
    always @(posedge clk) begin
        if (valid_out || loss_valid) begin
            if (head >= tail) $fatal("Unexpected valid without expected data (head=%0d tail=%0d)", head, tail);
            if (valid_out && (ub_data_out !== exp_ub[head]))
                $fatal("UB mismatch at time %0t: got %0d exp %0d", $time, ub_data_out, exp_ub[head]);
            if (loss_valid && (loss_out !== exp_loss[head]))
                $fatal("Loss mismatch at time %0t: got %0d exp %0d", $time, loss_out, exp_loss[head]);
            head = head + 1; // loss_valid and valid_out should be aligned
        end
    end

    // Monitor outputs
    always @(posedge clk) begin
        if (valid_out) begin
            $display("Time %0t : UB Out = %0d", $time, ub_data_out);
        end
        if (loss_valid) begin
            $display("Time %0t : Loss = %0d", $time, loss_out);
        end
    end
endmodule

