`timescale 1ns / 1ps
// Full Integration TB: 
// FRONT FLOW:  Weight FIFO + Activation UBs -> MMU (with staggering)
// BACK FLOW:   MMU -> Accumulator -> Activation Pipeline -> Output UB
module accel_integration_tb;
    reg clk, reset;

    // FSM States
    localparam IDLE        = 3'd0,
               LOAD_WEIGHT = 3'd1,
               COMPUTE     = 3'd2,
               DRAIN       = 3'd3,
               DONE        = 3'd4;
    
    reg [2:0] state;
    reg [3:0] cycle_cnt;
    
    // Control signals derived from FSM
    wire en_load_weight = (state == LOAD_WEIGHT);
    wire compute_phase  = (state == COMPUTE);
    wire drain_phase    = (state == DRAIN);

    // Timing Verification - Expected Timing Constants
    localparam EXPECTED_WEIGHT_LOAD_CYCLES = 3;   // 3 cycles for staggered column weight loading
    localparam EXPECTED_COMPUTE_CYCLES     = 3;   // 3 cycles for staggered activation flow
    localparam EXPECTED_FIRST_ACC_DELAY    = 5;   // cycles from compute_start to first acc_valid (includes accumulator pipeline)
    localparam EXPECTED_ACC_SPACING        = 1;   // cycles between acc_valid pulses

    // Timing Verification - Global Cycle Counter & Event Capture
    reg [15:0] global_cycle;
    reg [15:0] weight_load_start, weight_load_end;
    reg [15:0] compute_start, compute_end;
    reg [15:0] first_acc_valid_cycle, second_acc_valid_cycle;
    reg        weight_load_start_captured, compute_start_captured;
    reg        first_acc_captured, second_acc_captured;

    always @(posedge clk or posedge reset) begin
        if (reset)
            global_cycle <= 0;
        else
            global_cycle <= global_cycle + 1;
    end

    // Capture timing events
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            weight_load_start <= 0;
            weight_load_end <= 0;
            compute_start <= 0;
            compute_end <= 0;
            first_acc_valid_cycle <= 0;
            second_acc_valid_cycle <= 0;
            weight_load_start_captured <= 0;
            compute_start_captured <= 0;
            first_acc_captured <= 0;
            second_acc_captured <= 0;
        end else begin
            // Capture weight load timing
            if (state == LOAD_WEIGHT && !weight_load_start_captured) begin
                weight_load_start <= global_cycle;
                weight_load_start_captured <= 1;
            end
            if (state == LOAD_WEIGHT && cycle_cnt == 2)
                weight_load_end <= global_cycle;
            
            // Capture compute timing
            if (state == COMPUTE && !compute_start_captured) begin
                compute_start <= global_cycle;
                compute_start_captured <= 1;
            end
            if (state == COMPUTE && cycle_cnt == 2)
                compute_end <= global_cycle;
            
            // Capture accumulator output timing
            if (acc_valid && !first_acc_captured) begin
                first_acc_valid_cycle <= global_cycle;
                first_acc_captured <= 1;
            end else if (acc_valid && first_acc_captured && !second_acc_captured) begin
                second_acc_valid_cycle <= global_cycle;
                second_acc_captured <= 1;
            end
        end
    end

  
    // Weight FIFO
    
    reg        wf_push_col0, wf_push_col1;
    reg [7:0]  wf_data_in;
    wire [7:0] wf_col0_out, wf_col1_out;
    wire [7:0] wf_col1_raw;
    
    dual_weight_fifo weight_fifo_u (
        .clk(clk),
        .reset(reset),
        .push_col0(wf_push_col0),
        .push_col1(wf_push_col1),
        .data_in(wf_data_in),
        .pop(en_load_weight),
        .col0_out(wf_col0_out),
        .col1_out(wf_col1_out),
        .col1_raw(wf_col1_raw)
    );

    // Unified Activation Buffer
    // Single buffer stores activation matrix in row-major order.
    // We read 2 values per cycle (one for each row) during compute.

    reg        act_ub_wr_valid;
    reg [15:0] act_ub_wr_data;       // 16-bit wide {row1_data, row0_data}
    
    wire       act_ub_wr_ready;
    wire       act_ub_rd_valid;
    wire [15:0] act_ub_rd_data;      // 16-bit wide {row1_data, row0_data}
    wire       act_ub_empty;
    
    // Unified buffer for activations two rows
    unified_buffer #(.WIDTH(16), .DEPTH(16)) act_ub (
        .clk(clk),
        .reset(reset),
        .wr_valid(act_ub_wr_valid),
        .wr_data(act_ub_wr_data),
        .wr_ready(act_ub_wr_ready),
        .rd_ready(compute_phase),
        .rd_valid(act_ub_rd_valid),
        .rd_data(act_ub_rd_data),
        .full(),
        .empty(act_ub_empty),
        .count()
    );
    
    // Extract individual row data from unified buffer
    wire [7:0] act_row0_data = act_ub_rd_data[7:0];
    wire [7:0] act_row1_data = act_ub_rd_data[15:8];
    
    // Row 1 Skew Register (1-cycle delay for diagonal wavefront)
    // Only updates when valid data is read from buffer
    reg [7:0] row1_skew_reg;
    always @(posedge clk or posedge reset) begin
        if (reset)
            row1_skew_reg <= 8'd0;
        else if (compute_phase && act_ub_rd_valid)
            row1_skew_reg <= act_row1_data;
    end

    // MMU inputs gated by rd_valid for row0, skew register always valid for row1
    wire [7:0] mmu_row0_in = (compute_phase && act_ub_rd_valid) ? act_row0_data : 8'd0;
    wire [7:0] mmu_row1_in = compute_phase ? row1_skew_reg : 8'd0;  // Skewed, uses previous valid data
    wire [7:0] mmu_col0_in = en_load_weight ? wf_col0_out   : 8'd0;
    wire [7:0] mmu_col1_in = en_load_weight ? wf_col1_out   : 8'd0;
    
    // Per-column weight capture enables for staggered diagonal wavefront
    // With column skew in FIFO: col0 outputs valid data on cycles 0,1; col1 on cycles 1,2
    // Column 0 PEs (PE00, PE10) capture on cycle 1 (when col0 has W[0,0] and psum has W[1,0])
    // Column 1 PEs (PE01, PE11) capture on cycle 2 (when col1 has W[0,1] and psum has W[1,1])
    wire en_capture_col0 = en_load_weight && (cycle_cnt == 1);
    wire en_capture_col1 = en_load_weight && (cycle_cnt == 2);
    
    wire [15:0] mmu_acc0_out, mmu_acc1_out;
    
    mmu mmu_u (
        .clk(clk),
        .reset(reset),
        .en_weight_pass(en_load_weight),      // Pass psum through during entire load phase
        .en_capture_col0(en_capture_col0),    // Column 0 captures on cycle 1
        .en_capture_col1(en_capture_col1),    // Column 1 captures on cycle 2
        .row0_in(mmu_row0_in),
        .row1_in(mmu_row1_in),
        .col0_in(mmu_col0_in),
        .col1_in(mmu_col1_in),
        .acc0_out(mmu_acc0_out),
        .acc1_out(mmu_acc1_out)
    );


    // Accumulator (Forward Pass Only)

    reg         accum_en;
    reg         addr_sel;
    wire        mmu_valid = (compute_phase && cycle_cnt >= 2) || drain_phase;
    
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


    // back flow: Activation Pipeline

    reg signed [15:0] norm_gain;
    reg signed [31:0] norm_bias;
    reg [4:0]  norm_shift;
    reg signed [15:0] q_inv_scale;
    reg signed [7:0]  q_zero_point;
    
    wire ap_valid;
    wire signed [7:0] ap_data;
    wire ub_wr_ready;

    activation_pipeline ap_u (
        .clk(clk),
        .reset(reset),
        .valid_in(acc_valid & ub_wr_ready),
        .acc_in(acc0),
        .target_in(acc1),
        .norm_gain(norm_gain),
        .norm_bias(norm_bias),
        .norm_shift(norm_shift),
        .q_inv_scale(q_inv_scale),
        .q_zero_point(q_zero_point),
        .valid_out(ap_valid),
        .ub_data_out(ap_data),
        .loss_valid(),
        .loss_out()
    );


    // Output Unified Buffer

    reg rd_ready;
    wire ub_rd_valid;
    wire signed [7:0] ub_rd_data;
    wire ub_full, ub_empty;

    unified_buffer ub_out (
        .clk(clk),
        .reset(reset),
        .wr_valid(ap_valid),
        .wr_data(ap_data),
        .wr_ready(ub_wr_ready),
        .rd_ready(rd_ready),
        .rd_valid(ub_rd_valid),
        .rd_data(ub_rd_data),
        .full(ub_full),
        .empty(ub_empty),
        .count()
    );

    // Clock Generation
    always #5 clk = ~clk;

    // FSM Controller
    reg start_compute;
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            cycle_cnt <= 0;
        end else begin
            case (state)
                IDLE: begin
                    cycle_cnt <= 0;
                    if (start_compute)
                        state <= LOAD_WEIGHT;
                end
                
                LOAD_WEIGHT: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // 2x2 array: 3 cycles for staggered column weight loading
                    // Cycle 0: col0=W[1,0], col1=0 (skew). Prime pipeline.
                    // Cycle 1: col0=W[0,0], col1=W[1,1]. Column 0 PEs capture.
                    // Cycle 2: col0=hold, col1=W[0,1]. Column 1 PEs capture.
                    if (cycle_cnt == 2) begin
                        state <= COMPUTE;
                        cycle_cnt <= 0;  // Reset counter for next state
                    end
                end
                
                COMPUTE: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // 2x2 matmul: 3 cycles for staggered activation flow
                    if (cycle_cnt == 2) begin
                        state <= DRAIN;
                        cycle_cnt <= 0;  // Reset counter for next state
                    end
                end
                
                DRAIN: begin
                    cycle_cnt <= cycle_cnt + 1;
                    // Drain pipeline: wait for results to propagate
                    if (cycle_cnt == 4) begin
                        state <= DONE;
                        cycle_cnt <= 0;  // Reset counter for next state
                    end
                end
                
                DONE: begin
                    state <= IDLE;
                end
            endcase
        end
    end

    // Test Results Tracking
    reg [31:0] result_c00, result_c01, result_c10, result_c11;
    reg [1:0] result_count;
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            result_c00 <= 0;
            result_c01 <= 0;
            result_c10 <= 0;
            result_c11 <= 0;
            result_count <= 0;
        end else if (acc_valid) begin
            // Debug: show what we're capturing
            $display("t=%0t cycle=%0d [CAPTURE] result_count=%0d acc0=%0d acc1=%0d", 
                     $time, global_cycle, result_count, acc0, acc1);
            if (result_count < 2) begin
                // Only capture first 2 result pairs (for 2x2 matrix)
                case (result_count)
                    0: begin result_c00 <= acc0; result_c01 <= acc1; end
                    1: begin result_c10 <= acc0; result_c11 <= acc1; end
                endcase
                result_count <= result_count + 1;
            end
        end
    end

    // Forward Pass Test
    reg timing_pass;
    reg [15:0] actual_weight_load_cycles;
    reg [15:0] actual_compute_cycles;
    reg [15:0] actual_first_acc_delay;
    reg [15:0] actual_acc_spacing;
    
    initial begin
        // Initialize
        clk = 0; reset = 1;
        start_compute = 0;
        wf_push_col0 = 0; wf_push_col1 = 0; wf_data_in = 0;
        act_ub_wr_valid = 0; act_ub_wr_data = 0;
        accum_en = 0; addr_sel = 0;
        norm_gain = 16'sd256; norm_bias = 0; norm_shift = 5'd8;
        q_inv_scale = 16'sd256; q_zero_point = 0;
        rd_ready = 0;
        timing_pass = 1;
        
        #20 reset = 0;
        
        $display("******");
        $display("FORWARD PASS INTEGRATION TEST");
        
        // =====================================================================
        // phase 1
        // Weight Matrix W = [[1, 2], [3, 4]]
        //
        // PE layout after weight load:
        //   pe00(w=1) -> pe01(w=2)
        //      |           |
        //      v           v
        //   pe10(w=3) -> pe11(w=4)
        //
        // Load order: bottom row first (weights shift down through psum path)
        // =====================================================================
        $display("\n Phase 1: Loading Weight FIFO ---");
        $display("Weight Matrix W = [[1, 2], [3, 4]]");
        
        // Column 0: [3, 1] (W[1,0], W[0,0]) - bottom first
        @(negedge clk); wf_push_col0 = 1; wf_data_in = 8'd3; // W[1,0]
        @(negedge clk); wf_data_in = 8'd1;                   // W[0,0]
        @(negedge clk); wf_push_col0 = 0;
        
        // Column 1: [4, 2] (W[1,1], W[0,1]) - bottom first
        @(negedge clk); wf_push_col1 = 1; wf_data_in = 8'd4; // W[1,1]
        @(negedge clk); wf_data_in = 8'd2;                   // W[0,1]
        @(negedge clk); wf_push_col1 = 0;
        
        // =====================================================================
        // phase 1
        // Activation Matrix A = [[5, 6], [7, 8]]
        //
        // For systolic array computing C = A × W:
        // - PE row 0 receives column 0 of A: A[0,0]=5, then A[1,0]=7
        // - PE row 1 receives column 1 of A: A[0,1]=6, then A[1,1]=8 (skewed)
        //
        // Stored as {col1_elem, col0_elem} pairs per output row:
        //   Row 0 data: {A[0,1], A[0,0]} = {6, 5}
        //   Row 1 data: {A[1,1], A[1,0]} = {8, 7}
        // =====================================================================
        $display("\n Phase 1: Loading Activation Buffer (Column-Major) ---");
        $display("Activation Matrix A = [[5, 6], [7, 8]]");
        
        // Load as {col1, col0} pairs per output row for proper systolic flow
        @(negedge clk); act_ub_wr_valid = 1; act_ub_wr_data = {8'd6, 8'd5}; // Row 0: A[0,1], A[0,0]
        @(negedge clk); act_ub_wr_data = {8'd8, 8'd7};                      // Row 1: A[1,1], A[1,0]
        @(negedge clk); act_ub_wr_valid = 0;
        
        // =====================================================================
        // phase 2
        // Expected Results:
        //   C[0,0] = A[0,0]*W[0,0] + A[0,1]*W[1,0] = 5*1 + 6*3 = 23
        //   C[0,1] = A[0,0]*W[0,1] + A[0,1]*W[1,1] = 5*2 + 6*4 = 34
        //   C[1,0] = A[1,0]*W[0,0] + A[1,1]*W[1,0] = 7*1 + 8*3 = 31
        //   C[1,1] = A[1,0]*W[0,1] + A[1,1]*W[1,1] = 7*2 + 8*4 = 46
        // =====================================================================
        $display("\n Phase 2: Computing C = A * W ---");
        $display("Expected Results:");
        $display("  C[0,0] = 5*1 + 6*3 = 23");
        $display("  C[0,1] = 5*2 + 6*4 = 34");
        $display("  C[1,0] = 7*1 + 8*3 = 31");
        $display("  C[1,1] = 7*2 + 8*4 = 46");
        
        @(negedge clk);
        start_compute = 1;
        @(negedge clk);
        start_compute = 0;
        
        // Wait for FSM to complete
        wait(state == DONE);
        
        repeat(5) @(negedge clk);
        
        $display("\n Phase 3: Results Verification ---");
        $display("Actual Results from Accumulator:");
        $display("  C[0,0] = %0d (expected 23) %s", result_c00, result_c00 == 23 ? "PASS" : "FAIL");
        $display("  C[0,1] = %0d (expected 34) %s", result_c01, result_c01 == 34 ? "PASS" : "FAIL");
        $display("  C[1,0] = %0d (expected 31) %s", result_c10, result_c10 == 31 ? "PASS" : "FAIL");
        $display("  C[1,1] = %0d (expected 46) %s", result_c11, result_c11 == 46 ? "PASS" : "FAIL");
        
        // PHASE 4: Timing Verification
        $display("\n Phase 4: Timing Verification ---");
        
        // Calculate actual timing values
        actual_weight_load_cycles = weight_load_end - weight_load_start + 1;
        actual_compute_cycles = compute_end - compute_start + 1;
        actual_first_acc_delay = first_acc_valid_cycle - compute_start;
        actual_acc_spacing = second_acc_valid_cycle - first_acc_valid_cycle;
        
        // Weight load timing
        $display("  Weight load duration: %0d cycles (expected %0d) %s", 
                 actual_weight_load_cycles, 
                 EXPECTED_WEIGHT_LOAD_CYCLES,
                 actual_weight_load_cycles == EXPECTED_WEIGHT_LOAD_CYCLES ? "PASS" : "FAIL");
        if (actual_weight_load_cycles != EXPECTED_WEIGHT_LOAD_CYCLES) timing_pass = 0;
        
        // Compute phase timing
        $display("  Compute duration: %0d cycles (expected %0d) %s",
                 actual_compute_cycles,
                 EXPECTED_COMPUTE_CYCLES,
                 actual_compute_cycles == EXPECTED_COMPUTE_CYCLES ? "PASS" : "FAIL");
        if (actual_compute_cycles != EXPECTED_COMPUTE_CYCLES) timing_pass = 0;
        
        // First accumulator output timing
        $display("  First acc_valid delay from compute_start: %0d cycles (expected %0d) %s",
                 actual_first_acc_delay,
                 EXPECTED_FIRST_ACC_DELAY,
                 actual_first_acc_delay == EXPECTED_FIRST_ACC_DELAY ? "PASS" : "FAIL");
        if (actual_first_acc_delay != EXPECTED_FIRST_ACC_DELAY) timing_pass = 0;
        
        // Accumulator output spacing
        $display("  Acc output spacing: %0d cycles (expected %0d) %s",
                 actual_acc_spacing,
                 EXPECTED_ACC_SPACING,
                 actual_acc_spacing == EXPECTED_ACC_SPACING ? "PASS" : "FAIL");
        if (actual_acc_spacing != EXPECTED_ACC_SPACING) timing_pass = 0;
        
        // Detailed timing report
        $display("\n  Timing Details:");
        $display("    weight_load_start: cycle %0d", weight_load_start);
        $display("    weight_load_end:   cycle %0d", weight_load_end);
        $display("    compute_start:     cycle %0d", compute_start);
        $display("    compute_end:       cycle %0d", compute_end);
        $display("    first_acc_valid:   cycle %0d", first_acc_valid_cycle);
        $display("    second_acc_valid:  cycle %0d", second_acc_valid_cycle);

        // Final Summary
        $display("\n--- Final Summary ---");
        
        if (result_c00 == 23 && result_c01 == 34 && result_c10 == 31 && result_c11 == 46)
            $display("  Data correctness: PASS");
        else
            $display("  Data correctness: FAIL");
        
        if (timing_pass)
            $display("  Timing correctness: PASS");
        else
            $display("  Timing correctness: FAIL");
        
        if ((result_c00 == 23 && result_c01 == 34 && result_c10 == 31 && result_c11 == 46) && timing_pass)
            $display("\n*** FORWARD PASS TEST PASSED ***");
        else
            $display("\n*** FORWARD PASS TEST FAILED ***");
        
        $display("\n================================================================");
        $display("          FORWARD PASS TEST COMPLETE");
        
        repeat(10) @(negedge clk);
        $finish;
    end

    // Debug Tracing (with global cycle)
    always @(posedge clk) begin
        if (state == LOAD_WEIGHT)
            $display("t=%0t cycle=%0d [LOAD_WEIGHT] fsm_cnt=%0d col0=%0d col1=%0d | cap_col0=%b cap_col1=%b", 
                     $time, global_cycle, cycle_cnt, wf_col0_out, wf_col1_out, en_capture_col0, en_capture_col1);
        
        if (state == COMPUTE)
            $display("t=%0t cycle=%0d [COMPUTE] fsm_cnt=%0d row0=%0d row1=%0d (skewed) | raw_row1=%0d", 
                     $time, global_cycle, cycle_cnt, mmu_row0_in, mmu_row1_in, act_row1_data);
        
        if (state == DRAIN)
            $display("t=%0t cycle=%0d [DRAIN] fsm_cnt=%0d mmu_out: acc0=%0d acc1=%0d", 
                     $time, global_cycle, cycle_cnt, mmu_acc0_out, mmu_acc1_out);
        
        if (acc_valid)
            $display("t=%0t cycle=%0d [ACCUM] acc0=%0d acc1=%0d", 
                     $time, global_cycle, acc0, acc1);
    end

endmodule
