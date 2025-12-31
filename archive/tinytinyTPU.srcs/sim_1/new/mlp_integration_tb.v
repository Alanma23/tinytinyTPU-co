`timescale 1ns / 1ps
// Demo: 2-Layer MLP
//  Hidden Layer 1: H = ReLU(A x W1) 
//  Output Layer 2: Y = ReLU(H x W2)
//  Weight FIFO + UB -> MMU -> Accumulator -> Activation Pipeline -> UB

module mlp_integration_tb;
    reg clk, reset;
    localparam IDLE          = 4'd0,
               LOAD_WEIGHT   = 4'd1,   // Load weights for current layer
               LOAD_ACT      = 4'd2,   // Load activations
               COMPUTE       = 4'd3,   // Systolic array computation
               DRAIN         = 4'd4,   // Drain pipeline to accumulator
               TRANSFER      = 4'd5,   // Transfer output UB -> input UB (reload)
               NEXT_LAYER    = 4'd6,   // Prepare for next layer
               WAIT_WEIGHTS  = 4'd7,   // Wait for external weight loading
               DONE          = 4'd8;

    reg [3:0] state;
    reg [4:0] cycle_cnt;
    reg [2:0] current_layer;
    
    localparam NUM_LAYERS = 2;

    wire en_load_weight = (state == LOAD_WEIGHT);
    wire compute_phase  = (state == COMPUTE);
    wire drain_phase    = (state == DRAIN);
    wire transfer_phase = (state == TRANSFER);
    reg [15:0] global_cycle;
    always @(posedge clk or posedge reset) begin
        if (reset)
            global_cycle <= 0;
        else
            global_cycle <= global_cycle + 1;
    end

    reg        wf_push_col0, wf_push_col1;
    reg [7:0]  wf_data_in;
    wire [7:0] wf_col0_out, wf_col1_out;
    wire [7:0] wf_col1_raw;
    reg        wf_reset;  // Per-layer FIFO reset
    
    dual_weight_fifo weight_fifo_u (
        .clk(clk),
        .reset(reset | wf_reset),
        .push_col0(wf_push_col0),
        .push_col1(wf_push_col1),
        .data_in(wf_data_in),
        .pop(en_load_weight),
        .col0_out(wf_col0_out),
        .col1_out(wf_col1_out),
        .col1_raw(wf_col1_raw)
    );
    // Unified Buffer has depth 2, essentially double buffering between "A" and "B" versions
    // select signal 0 maps to A, 1 maps to B respecitvely.
    reg buffer_select;

    // A buff
    reg         ub_a_wr_valid;
    reg  [15:0] ub_a_wr_data;
    wire        ub_a_wr_ready;
    reg         ub_a_rd_ready;
    wire        ub_a_rd_valid;
    wire [15:0] ub_a_rd_data;
    wire        ub_a_empty;
    wire [4:0]  ub_a_count;
    unified_buffer #(.WIDTH(16), .DEPTH(16)) ub_a (
        .clk(clk),
        .reset(reset),
        .wr_valid(ub_a_wr_valid),
        .wr_data(ub_a_wr_data),
        .wr_ready(ub_a_wr_ready),
        .rd_ready(ub_a_rd_ready),
        .rd_valid(ub_a_rd_valid),
        .rd_data(ub_a_rd_data),
        .full(),
        .empty(ub_a_empty),
        .count(ub_a_count)
    );
    
    // B buffer
    reg         ub_b_wr_valid;
    reg  [15:0] ub_b_wr_data;
    wire        ub_b_wr_ready;
    reg         ub_b_rd_ready;
    wire        ub_b_rd_valid;
    wire [15:0] ub_b_rd_data;
    wire        ub_b_empty;
    wire [4:0]  ub_b_count;
    unified_buffer #(.WIDTH(16), .DEPTH(16)) ub_b (
        .clk(clk),
        .reset(reset),
        .wr_valid(ub_b_wr_valid),
        .wr_data(ub_b_wr_data),
        .wr_ready(ub_b_wr_ready),
        .rd_ready(ub_b_rd_ready),
        .rd_valid(ub_b_rd_valid),
        .rd_data(ub_b_rd_data),
        .full(),
        .empty(ub_b_empty),
        .count(ub_b_count)
    );
    
    wire        act_ub_rd_valid = buffer_select ? ub_b_rd_valid : ub_a_rd_valid;
    wire [15:0] act_ub_rd_data  = buffer_select ? ub_b_rd_data  : ub_a_rd_data;
    wire        act_ub_empty    = buffer_select ? ub_b_empty    : ub_a_empty;
    
    always @(*) begin
        ub_a_rd_ready = 0;
        ub_b_rd_ready = 0;
        if (compute_phase) begin
            if (buffer_select)
                ub_b_rd_ready = 1;
            else
                ub_a_rd_ready = 1;
        end
    end
    
    wire [7:0] act_row0_data = act_ub_rd_data[7:0];
    wire [7:0] act_row1_data = act_ub_rd_data[15:8];
    
    // staggering UB
    reg [7:0] row1_skew_reg;
    always @(posedge clk or posedge reset) begin
        if (reset)
            row1_skew_reg <= 8'd0;
        else if (compute_phase && act_ub_rd_valid)
            row1_skew_reg <= act_row1_data;
    end

    // MMU start
    wire [7:0] mmu_row0_in = (compute_phase && act_ub_rd_valid) ? act_row0_data : 8'd0;
    wire [7:0] mmu_row1_in = compute_phase ? row1_skew_reg : 8'd0;
    wire [7:0] mmu_col0_in = en_load_weight ? wf_col0_out : 8'd0;
    wire [7:0] mmu_col1_in = en_load_weight ? wf_col1_out : 8'd0;

    wire en_capture_col0 = en_load_weight && (cycle_cnt == 1);
    wire en_capture_col1 = en_load_weight && (cycle_cnt == 2);
    wire [15:0] mmu_acc0_out, mmu_acc1_out;
    
    mmu mmu_u (
        .clk(clk),
        .reset(reset),
        .en_weight_pass(en_load_weight),
        .en_capture_col0(en_capture_col0),
        .en_capture_col1(en_capture_col1),
        .row0_in(mmu_row0_in),
        .row1_in(mmu_row1_in),
        .col0_in(mmu_col0_in),
        .col1_in(mmu_col1_in),
        .acc0_out(mmu_acc0_out),
        .acc1_out(mmu_acc1_out)
    );

    // Accumulator unit
    reg  accum_en;
    reg  addr_sel;
    wire mmu_valid = (compute_phase && cycle_cnt >= 2) || drain_phase;
    
    wire signed [31:0] acc0, acc1;
    wire acc_valid;
    
    accumulator accum_u (
        .clk(clk),
        .reset(reset),
        .valid_in(mmu_valid),
        .accumulator_enable(accum_en),
        .addr_sel(addr_sel),
        .mmu_col0_in(mmu_acc0_out),
        .mmu_col1_in(mmu_acc1_out),
        .acc_col0_out(acc0),
        .acc_col1_out(acc1),
        .valid_out(acc_valid)
    );

    // activation pipeline
    reg signed [15:0] norm_gain;
    reg signed [31:0] norm_bias;
    reg [4:0]  norm_shift;
    reg signed [15:0] q_inv_scale;
    reg signed [7:0]  q_zero_point;
    
    wire ap_valid;
    wire signed [7:0] ap_data_col0;
    wire signed [7:0] ap_data_col1;
    
    activation_pipeline ap_col0 (
        .clk(clk),
        .reset(reset),
        .valid_in(acc_valid),
        .acc_in(acc0),
        .target_in(32'd0),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(ap_valid),
        .ub_data_out(ap_data_col0),
        .loss_valid(),
        .loss_out()
    );
    
    wire ap_valid_col1;
    activation_pipeline ap_col1 (
        .clk(clk),
        .reset(reset),
        .valid_in(acc_valid),
        .acc_in(acc1),
        .target_in(32'd0),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(ap_valid_col1),
        .ub_data_out(ap_data_col1),
        .loss_valid(),
        .loss_out()
    );

    // catching output for UB to refill
    reg       refill_valid;
    reg [15:0] refill_data;
    
    // Direct repacking: each ap_valid gives us a complete row
    // Pack as {col1, col0} to match activation buffer format
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            refill_valid <= 0;
            refill_data <= 0;
        end else begin
            refill_valid <= 0;
            
            if (ap_valid) begin
                refill_data <= {ap_data_col1, ap_data_col0};
                refill_valid <= 1;
            end
        end
    end
    
    wire out_ub_wr_valid = refill_valid;
    wire [15:0] out_ub_wr_data = refill_data;
    reg [15:0] init_act_data;
    reg        init_act_valid;
    
    always @(*) begin
        ub_a_wr_valid = 0;
        ub_a_wr_data = 0;
        ub_b_wr_valid = 0;
        ub_b_wr_data = 0;
        
        if (init_act_valid) begin
            ub_a_wr_valid = 1;
            ub_a_wr_data = init_act_data;
        end else if (drain_phase || transfer_phase) begin
            if (buffer_select) begin
                ub_a_wr_valid = out_ub_wr_valid;
                ub_a_wr_data = out_ub_wr_data;
            end else begin
                ub_b_wr_valid = out_ub_wr_valid;
                ub_b_wr_data = out_ub_wr_data;
            end
        end
    end

    // RESULTS
    reg [31:0] layer_results [0:NUM_LAYERS-1][0:3]; // [layer][element]
    reg [1:0]  result_count;
    reg        capturing_results;
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            result_count <= 0;
            capturing_results <= 0;
        end else begin
            if (state == COMPUTE && cycle_cnt == 0) begin
                result_count <= 0;
                capturing_results <= 1;
            end
            
            if (capturing_results && acc_valid && result_count < 2) begin
                layer_results[current_layer][result_count*2]   <= acc0;
                layer_results[current_layer][result_count*2+1] <= acc1;
                result_count <= result_count + 1;
                
                $display("t=%0t cycle=%0d [LAYER %0d RESULT] row=%0d: C[%0d,0]=%0d C[%0d,1]=%0d",
                         $time, global_cycle, current_layer, result_count,
                         result_count, acc0, result_count, acc1);
            end
            
            if (state == DRAIN && cycle_cnt == 4) begin
                capturing_results <= 0;
            end
        end
    end

    // clk cycle
    always #5 clk = ~clk;

    // FSM controller
    reg start_mlp;
    reg weights_loaded;
    reg layer_complete;
    reg weights_ready;  // Testbench sets this when weights are loaded for next layer
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            cycle_cnt <= 0;
            current_layer <= 0;
            buffer_select <= 0;
            weights_loaded <= 0;
            layer_complete <= 0;
            wf_reset <= 0;
        end else begin
            wf_reset <= 0;
            
            case (state)
                IDLE: begin
                    cycle_cnt <= 0;
                    if (start_mlp) begin
                        state <= LOAD_WEIGHT;
                        current_layer <= 0;
                        buffer_select <= 0;  // UBuff A is input for layer 0
                    end
                end
                
                LOAD_WEIGHT: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // 3 cycles for staggered column weight loading
                    if (cycle_cnt == 2) begin
                        state <= (current_layer == 0) ? LOAD_ACT : COMPUTE;
                        cycle_cnt <= 0;
                        weights_loaded <= 1;
                    end
                end
                
                LOAD_ACT: begin
                    // Wait for initial activations to be loaded (done in initial block)
                    cycle_cnt <= cycle_cnt + 1;
                    if (cycle_cnt == 3) begin
                        state <= COMPUTE;
                        cycle_cnt <= 0;
                    end
                end
                
                COMPUTE: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // 3 cycles for staggered activation flow
                    if (cycle_cnt == 2) begin
                        state <= DRAIN;
                        cycle_cnt <= 0;
                    end
                end
                
                DRAIN: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // wait for results to propagate through activation pipeline
                    if (cycle_cnt == 6) begin
                        if (current_layer < NUM_LAYERS - 1) begin
                            state <= TRANSFER;
                            cycle_cnt <= 0;
                        end else begin
                            state <= DONE;
                            cycle_cnt <= 0;
                        end
                    end
                end
                
                TRANSFER: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // Allow time for repacked data to be written
                    if (cycle_cnt == 3) begin
                        state <= NEXT_LAYER;
                        cycle_cnt <= 0;
                    end
                end
                
                NEXT_LAYER: begin
                    // swao=p buffers and prepare for next layer
                    buffer_select <= ~buffer_select;
                    current_layer <= current_layer + 1;
                    wf_reset <= 1;  // Reset weight FIFO for new weights
                    state <= WAIT_WEIGHTS;
                    cycle_cnt <= 0;
                    weights_loaded <= 0;
                end
                
                WAIT_WEIGHTS: begin
                    // wait for external weight loading to complete
                    // Testbench sets weights_ready when weights are in FIFO
                    cycle_cnt <= cycle_cnt + 1;
                    if (weights_ready) begin
                        state <= LOAD_WEIGHT;
                        cycle_cnt <= 0;
                    end
                end
                
                DONE: begin
                    layer_complete <= 1;
                end
            endcase
        end
    end

    // weight loading for weight FIFO
    task load_weights;
        input [7:0] w00, w01, w10, w11;
        begin
            // col 0
            @(negedge clk); wf_push_col0 = 1; wf_data_in = w10;
            @(negedge clk); wf_data_in = w00;
            @(negedge clk); wf_push_col0 = 0;
            
            // col 1
            @(negedge clk); wf_push_col1 = 1; wf_data_in = w11;
            @(negedge clk); wf_data_in = w01;
            @(negedge clk); wf_push_col1 = 0;
        end
    endtask

    // main test
    initial begin
        // Initialize
        clk = 0; reset = 1;
        start_mlp = 0;
        weights_ready = 0;
        wf_push_col0 = 0; wf_push_col1 = 0; wf_data_in = 0;
        init_act_data = 0;
        init_act_valid = 0;
        accum_en = 0; addr_sel = 0;
        
        // Activation pipeline config: passthrough (gain=256, shift=8 → multiply by 1)
        norm_gain = 16'sd256;
        norm_bias = 32'sd0;
        norm_shift = 5'd8;
        q_inv_scale = 16'sd256;  // 1.0 in Q8.8
        q_zero_point = 8'sd0;
        
        #20 reset = 0;
        
        $display("2 layer MLP test");
        
        // Network Configuration:
        //   Layer 1: H = ReLU(A × W1)
        //   Layer 2: Y = ReLU(H × W2)
        //
        // Input:  A  = [[5, 6], [7, 8]]
        // W1:     W1 = [[1, 2], [3, 4]]
        // W2:     W2 = [[1, 1], [1, 1]]  (sum reduction for demo)

        $display("\n Network Architecture");
        $display("  Input A  = [[5, 6], [7, 8]]");
        $display("  Layer 1: W1 = [[1, 2], [3, 4]]");
        $display("  Layer 2: W2 = [[1, 1], [1, 1]]");
        
        $display("\n Expected Computation");
        $display("  Layer 1: H = A x W1");
        $display("    H[0,0] = 5*1 + 6*3 = 23");
        $display("    H[0,1] = 5*2 + 6*4 = 34");
        $display("    H[1,0] = 7*1 + 8*3 = 31");
        $display("    H[1,1] = 7*2 + 8*4 = 46");
        $display("    After ReLU: H = [[23, 34], [31, 46]]");
        $display("");
        $display("  Layer 2: Y = H x W2");
        $display("    Y[0,0] = 23*1 + 34*1 = 57");
        $display("    Y[0,1] = 23*1 + 34*1 = 57");
        $display("    Y[1,0] = 31*1 + 46*1 = 77");
        $display("    Y[1,1] = 31*1 + 46*1 = 77");
        
        $display(" \n loading layer 1 weights");
        
        load_weights(8'd1, 8'd2, 8'd3, 8'd4);
        
        $display("\n  Loading Activations]");
        
        // Load activations as {row1_data, row0_data} packed pairs
        @(negedge clk);
        init_act_valid = 1;
        init_act_data = {8'd6, 8'd5};  // Row 0: {A[0,1], A[0,0]}
        @(negedge clk);
        init_act_data = {8'd8, 8'd7};  // Row 1: {A[1,1], A[1,0]}
        @(negedge clk);
        init_act_valid = 0;
        
        // MLP exec
        $display("\n  Starting MLP\n");
        
        @(negedge clk);
        start_mlp = 1;
        @(negedge clk);
        start_mlp = 0;
        
        // Wait for layer 1 to complete weight loading
        wait(state == LOAD_ACT);
        $display("  [Layer 1] Weights loaded, activations already in buffer...");
        
        wait(state == COMPUTE && current_layer == 0);
        $display("  [Layer 1] Computing H = A x W1...");
        
        wait(state == DRAIN && current_layer == 0);
        $display("  [Layer 1] Draining results...");
        
        // layer 2 of MLP
        wait(state == TRANSFER);
        $display("\n  [Transfer] Moving Layer 1 output to Layer 2 input...");
        
        // Wait for FSM to enter WAIT_WEIGHTS state (FIFO is reset)
        wait(state == WAIT_WEIGHTS);
        $display("  [Preparing Layer 2]");
        @(negedge clk); // Wait one cycle for wf_reset to take effect
        @(negedge clk);
        
        // Load Layer 2 weights BEFORE signaling ready
        $display("\n layer 2: Loading Weights W2");
        
        load_weights(8'd1, 8'd1, 8'd1, 8'd1);
        
        // Signal FSM that weights are ready
        @(negedge clk);
        weights_ready = 1;
        @(negedge clk);
        weights_ready = 0;
        
        wait(state == COMPUTE && current_layer == 1);
        $display("  [Layer 2] Computing Y = H x W2...");
        
        wait(state == DRAIN && current_layer == 1);
        $display("  [Layer 2] Draining results...");
        
        // Wait for completion
        wait(state == DONE);
        repeat(10) @(negedge clk);
        $display("------------------------");
        $display("\n RESULTS VERIFICATION");
        
        $display("\n  Layer 1 Results (H = A × W1):");
        $display("    H[0,0] = %0d (expected 23) %s", layer_results[0][0], 
                 layer_results[0][0] == 23 ? "PASS" : "FAIL");
        $display("    H[0,1] = %0d (expected 34) %s", layer_results[0][1],
                 layer_results[0][1] == 34 ? "PASS" : "FAIL");
        $display("    H[1,0] = %0d (expected 31) %s", layer_results[0][2],
                 layer_results[0][2] == 31 ? "PASS" : "FAIL");
        $display("    H[1,1] = %0d (expected 46) %s", layer_results[0][3],
                 layer_results[0][3] == 46 ? "PASS" : "FAIL");
        
        $display("\n  Layer 2 Results (Y = H × W2):");
        $display("    Y[0,0] = %0d (expected 57) %s", layer_results[1][0],
                 layer_results[1][0] == 57 ? "PASS" : "FAIL");
        $display("    Y[0,1] = %0d (expected 57) %s", layer_results[1][1],
                 layer_results[1][1] == 57 ? "PASS" : "FAIL");
        $display("    Y[1,0] = %0d (expected 77) %s", layer_results[1][2],
                 layer_results[1][2] == 77 ? "PASS" : "FAIL");
        $display("    Y[1,1] = %0d (expected 77) %s", layer_results[1][3],
                 layer_results[1][3] == 77 ? "PASS" : "FAIL");
        
        $display("------------------------");
        
        if (layer_results[0][0] == 23 && layer_results[0][1] == 34 &&
            layer_results[0][2] == 31 && layer_results[0][3] == 46 &&
            layer_results[1][0] == 57 && layer_results[1][1] == 57 &&
            layer_results[1][2] == 77 && layer_results[1][3] == 77) begin
            $display("   TEST PASSED ");
        end else begin
            $display("  TEST FAILED ");
        end
        
        $display("------------------------");
        
        repeat(10) @(negedge clk);
        $finish;
    end

    // tracing for debug
    always @(posedge clk) begin
        if (state == LOAD_WEIGHT)
            $display("t=%0t cycle=%0d [L%0d LOAD_WEIGHT] cnt=%0d col0=%0d col1=%0d cap0=%b cap1=%b",
                     $time, global_cycle, current_layer, cycle_cnt, 
                     wf_col0_out, wf_col1_out, en_capture_col0, en_capture_col1);
        
        if (state == WAIT_WEIGHTS)
            $display("t=%0t cycle=%0d [L%0d WAIT_WEIGHTS] cnt=%0d weights_ready=%b",
                     $time, global_cycle, current_layer, cycle_cnt, weights_ready);
        
        if (state == COMPUTE)
            $display("t=%0t cycle=%0d [L%0d COMPUTE] cnt=%0d row0=%0d row1=%0d buf_sel=%b",
                     $time, global_cycle, current_layer, cycle_cnt,
                     mmu_row0_in, mmu_row1_in, buffer_select);
        
        if (state == DRAIN)
            $display("t=%0t cycle=%0d [L%0d DRAIN] cnt=%0d mmu: acc0=%0d acc1=%0d",
                     $time, global_cycle, current_layer, cycle_cnt,
                     mmu_acc0_out, mmu_acc1_out);
        
        if (ap_valid)
            $display("t=%0t cycle=%0d [L%0d ACTPIPE] col0_q=%0d col1_q=%0d",
                     $time, global_cycle, current_layer, ap_data_col0, ap_data_col1);
        
        if (state == TRANSFER)
            $display("t=%0t cycle=%0d [TRANSFER] cnt=%0d repack_valid=%b data=%h",
                     $time, global_cycle, cycle_cnt, repack_valid, repacked_data);
    end

endmodule
