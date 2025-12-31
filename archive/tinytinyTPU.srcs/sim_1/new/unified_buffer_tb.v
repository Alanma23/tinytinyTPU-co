`timescale 1ns / 1ps

module unified_buffer_tb;
    localparam WIDTH = 8;
    localparam DEPTH = 8;
    reg clk, reset;
    reg wr_valid;
    reg [WIDTH-1:0] wr_data;
    wire wr_ready;
    reg rd_ready;
    wire rd_valid;
    wire [WIDTH-1:0] rd_data;
    wire full, empty;
    wire [3:0] count;

    // Scoreboard
    reg [WIDTH-1:0] exp_mem [0:63];
    integer head = 0, tail = 0;

    unified_buffer #(.WIDTH(WIDTH), .DEPTH(DEPTH)) dut (
        .clk(clk),
        .reset(reset),
        .wr_valid(wr_valid),
        .wr_data(wr_data),
        .wr_ready(wr_ready),
        .rd_ready(rd_ready),
        .rd_valid(rd_valid),
        .rd_data(rd_data),
        .full(full),
        .empty(empty),
        .count(count)
    );

    always #5 clk = ~clk;

    initial begin
        clk = 0; reset = 1;
        wr_valid = 0; wr_data = 0; rd_ready = 0;
        #12 reset = 0;

        // Fill half
        repeat (4) push_byte($random);
        // Pop 2
        repeat (2) pop_byte();
        // Fill to full
        repeat (6) push_byte($random);
        // Drain all
        repeat (8) pop_byte();

        #50;
        $display("UB TB finished");
        $finish;
    end

    task push_byte(input [WIDTH-1:0] d);
        begin
            @(negedge clk);
            wr_data  <= d;
            wr_valid <= 1'b1;
            @(negedge clk);
            wr_valid <= 1'b0;
        end
    endtask

    task pop_byte;
        begin
            @(negedge clk);
            rd_ready <= 1'b1;
            @(negedge clk);
            rd_ready <= 1'b0;
        end
    endtask

    // Assertions and scoreboard updates
    always @(posedge clk) begin
        // Protocol violations
        if (wr_valid && !wr_ready) $fatal(1, "Write when not ready at t=%0t", $time);
        if (rd_ready && empty)     $fatal(1, "Read when empty at t=%0t", $time);

        // Capture expected stream on writes
        if (wr_valid && wr_ready) begin
            exp_mem[tail] <= wr_data;
            tail = tail + 1;
        end

        // Check ordering on reads
        if (rd_valid && rd_ready) begin
            if (head >= tail) $fatal(1, "Read with no expected data at t=%0t", $time);
            if (rd_data !== exp_mem[head])
                $fatal(1, "Data mismatch at t=%0t got %0d exp %0d", $time, rd_data, exp_mem[head]);
            head = head + 1;
        end
    end

    always @(posedge clk) begin
        if (wr_valid && wr_ready) $display("t=%0t WR %0d count=%0d", $time, wr_data, count + 1);
        if (rd_valid && rd_ready) $display("t=%0t RD %0d count=%0d", $time, rd_data, count);
        if (full)  $display("t=%0t FULL", $time);
        if (empty) $display("t=%0t EMPTY", $time);
    end
endmodule

