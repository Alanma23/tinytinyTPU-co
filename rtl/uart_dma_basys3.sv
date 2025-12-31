`timescale 1ns / 1ps

module uart_dma_basys3 #(
    parameter CLOCK_FREQ = 100_000_000,  // 100 MHz
    parameter BAUD_RATE  = 115200
)(
    input logic clk,
    input logic rst,

    // UART Interface (to PC)
    input logic  uart_rx,
    output logic uart_tx,

    // To Unified Buffer (dual-port)
    output logic        ub_wr_en,
    output logic [8:0]  ub_wr_addr,     // 9-bit address for unified buffer
    output logic [8:0]  ub_wr_count,    // Burst count (number of 256-bit words)
    output logic [255:0] ub_wr_data,    // 32 bytes at once
    output logic        ub_rd_en,
    output logic [8:0]  ub_rd_addr,     // 9-bit address for unified buffer
    output logic [8:0]  ub_rd_count,    // Burst count (number of 256-bit words)
    input logic [255:0] ub_rd_data,
    input logic         ub_rd_valid,    // Read data valid signal

    // To Weight Memory
    output logic        wt_wr_en,
    output logic [9:0]  wt_wr_addr,
    output logic [63:0] wt_wr_data,     // 8 bytes at once

    // To Instruction Buffer
    output logic        instr_wr_en,
    output logic [4:0]  instr_wr_addr,
    output logic [31:0] instr_wr_data,

    // To Controller
    output logic        start_execution, // Pulse to start

    // From Datapath (status)
    input logic        sys_busy,
    input logic        sys_done,
    input logic        vpu_busy,
    input logic        vpu_done,
    input logic        ub_busy,
    input logic        ub_done,
    input logic        halt_req,       // Halt signal from controller (for Python script detection)

    // Debug outputs
    output logic [7:0]  debug_state,
    output logic [7:0]  debug_cmd,
    output logic [15:0] debug_byte_count,
    
    // Debug counters for instrumentation
    output logic [31:0] debug_rx_count,      // Count of bytes received
    output logic [31:0] debug_tx_count,      // Count of bytes transmitted
    output logic [31:0] debug_state_changes, // Count of state transitions
    output logic [7:0]  debug_last_rx_byte,  // Last byte received
    output logic        debug_rx_valid_pulse, // Pulse when rx_valid goes high
    output logic        debug_reset_state,    // Current reset state (inverted)
    output logic [31:0] debug_framing_error_count, // Count of framing errors
    output logic [7:0]  debug_last_tx_byte,   // Last byte transmitted (for debugging)
    // Additional READ_UB debug signals
    output logic        debug_read_ub_tx_ready,  // Track tx_ready in READ_UB
    output logic        debug_read_ub_tx_valid, // Track tx_valid in READ_UB
    output logic [15:0] debug_read_ub_length,   // Track length in READ_UB
    output logic [15:0] debug_read_ub_byte_count, // Track byte_count in READ_UB
    output logic [7:0]  debug_read_ub_buffer_lsb, // Track read_buffer[7:0] in READ_UB
    // WRITE_UB debug signals
    output logic        debug_write_ub_rx_valid, // Track rx_valid in WRITE_UB
    output logic [7:0]  debug_write_ub_rx_data,  // Track rx_data in WRITE_UB
    output logic [15:0] debug_write_ub_byte_count, // Track byte_count in WRITE_UB
    output logic [7:0]  debug_ub_buffer_lsb,     // Track ub_buffer[7:0] in WRITE_UB
    output logic [7:0]  debug_ub_buffer_msb,     // Track ub_buffer[255:248] in WRITE_UB
    // Debug instrumentation for 32-byte buffer analysis
    output logic [31:0] debug_ub_buffer_bytes_0_3,   // ub_buffer[31:0] when byte_index==30
    output logic [31:0] debug_ub_buffer_bytes_28_31, // ub_buffer[255:224] when byte_index==30
    output logic [31:0] debug_last_write_bytes_0_3,  // last_ub_write_data[31:0] after construction
    output logic [31:0] debug_last_write_bytes_28_31, // last_ub_write_data[255:224] after construction
    output logic [31:0] debug_read_buffer_bytes_0_3, // read_buffer[31:0] when READ_UB initializes
    output logic [31:0] debug_read_buffer_bytes_28_31 // read_buffer[255:224] when READ_UB initializes
);

// ============================================================================
// UART RX/TX Instances
// ============================================================================

logic [7:0] rx_data;
logic rx_valid;
logic rx_ready;
logic rx_framing_error;

assign rx_ready = 1'b1;

uart_rx #(
    .CLOCK_FREQ(CLOCK_FREQ),
    .BAUD_RATE(BAUD_RATE)
) uart_rx_inst (
    .clk(clk),
    .rst(rst),
    .rx(uart_rx),
    .rx_data(rx_data),
    .rx_valid(rx_valid),
    .framing_error(rx_framing_error),
    .rx_ready(rx_ready)
);

logic [7:0] tx_data;
logic tx_valid;
logic tx_ready;

uart_tx #(
    .CLOCK_FREQ(CLOCK_FREQ),
    .BAUD_RATE(BAUD_RATE)
) uart_tx_inst (
    .clk(clk),
    .rst(rst),
    .tx(uart_tx),
    .tx_data(tx_data),
    .tx_valid(tx_valid),
    .tx_ready(tx_ready)
);

// ============================================================================
// Command Protocol State Machine
// ============================================================================

localparam IDLE           = 8'd0;
localparam READ_CMD       = 8'd1;
localparam READ_ADDR_HI   = 8'd2;
localparam READ_ADDR_LO   = 8'd3;
localparam READ_LENGTH_HI = 8'd4;
localparam READ_LENGTH_LO = 8'd5;
localparam WRITE_UB       = 8'd6;
localparam WRITE_WT       = 8'd7;
localparam WRITE_INSTR    = 8'd8;
localparam READ_UB        = 8'd9;
localparam SEND_STATUS    = 8'd10;
localparam EXECUTE        = 8'd11;
localparam READ_DEBUG     = 8'd20;  // Debug command to read debug counters

logic [7:0] state;
logic [7:0] command;
logic [7:0] addr_hi;
logic [7:0] addr_lo;
logic [15:0] length;
logic [15:0] byte_count;
logic [4:0] byte_index;  // For building up 32-byte writes

// Temporary buffers for accumulating bytes
logic [255:0] ub_buffer;
logic [63:0]  wt_buffer;
logic [31:0]  instr_buffer;

// Read buffer for sending data back
logic [255:0] read_buffer;
logic [7:0]   read_index;
logic         read_ub_initialized;  // Flag to track if READ_UB has been initialized
logic         read_ub_wait_valid;   // Flag to wait for ub_rd_valid signal

// Debug: store last written data
logic [255:0] last_ub_write_data;
logic [7:0]   last_ub_write_addr;

// #region agent log - Debug instrumentation for tracking events
logic rx_valid_prev;
logic [7:0] state_prev;
// #endregion

always @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        command <= 8'h00;
        addr_hi <= 8'h00;
        addr_lo <= 8'h00;
        length <= 16'h0000;
        byte_count <= 16'h0000;
        byte_index <= 5'd0;
        last_ub_write_data <= 256'h0;
        last_ub_write_addr <= 8'h0;

        ub_wr_en <= 1'b0;
        ub_wr_addr <= 9'h0;
        ub_wr_count <= 9'h0;
        ub_rd_en <= 1'b0;
        ub_rd_addr <= 9'h0;
        ub_rd_count <= 9'h0;
        wt_wr_en <= 1'b0;
        instr_wr_en <= 1'b0;
        start_execution <= 1'b0;
        
        read_buffer <= 256'h0;
        read_index <= 8'h0;
        read_ub_initialized <= 1'b0;
        read_ub_wait_valid <= 1'b0;

        tx_valid <= 1'b0;

        debug_state <= 8'h00;
        debug_cmd <= 8'h00;
        debug_byte_count <= 16'h0000;
        
        // Debug counters reset
        debug_rx_count <= 32'h0;
        debug_tx_count <= 32'h0;
        debug_state_changes <= 32'h0;
        debug_last_rx_byte <= 8'h0;
        debug_rx_valid_pulse <= 1'b0;
        debug_reset_state <= 1'b0;
        debug_framing_error_count <= 32'h0;
        debug_last_tx_byte <= 8'h0;

        // WRITE_UB debug signals
        debug_write_ub_rx_valid <= 1'b0;
        debug_write_ub_rx_data <= 8'h0;
        debug_write_ub_byte_count <= 16'h0;
        debug_ub_buffer_lsb <= 8'h0;
        debug_ub_buffer_msb <= 8'h0;

        // Debug instrumentation for buffer analysis
        debug_ub_buffer_bytes_0_3 <= 32'h0;
        debug_ub_buffer_bytes_28_31 <= 32'h0;
        debug_last_write_bytes_0_3 <= 32'h0;
        debug_last_write_bytes_28_31 <= 32'h0;
        debug_read_buffer_bytes_0_3 <= 32'h0;
        debug_read_buffer_bytes_28_31 <= 32'h0;

        rx_valid_prev <= 1'b0;
        state_prev <= IDLE;

    end else begin
        debug_reset_state <= 1'b1;  // 1 = not in reset

        rx_valid_prev <= rx_valid;
        if (rx_valid && !rx_valid_prev) begin
            if (rx_framing_error) begin
                debug_framing_error_count <= debug_framing_error_count + 1;
            end else begin
                debug_rx_count <= debug_rx_count + 1;
                debug_last_rx_byte <= rx_data;
            end
            debug_rx_valid_pulse <= 1'b1;  // Pulse for one cycle
        end else begin
            debug_rx_valid_pulse <= 1'b0;
        end

        state_prev <= state;
        if (state != state_prev) begin
            debug_state_changes <= debug_state_changes + 1;
        end

        // Track TX events
        if (tx_valid && tx_ready) begin
            debug_tx_count <= debug_tx_count + 1;
            debug_last_tx_byte <= tx_data;  // Track what's being transmitted
        end
        // #endregion
        
        // Default: clear write/read enables
        ub_wr_en <= 1'b0;
        wt_wr_en <= 1'b0;
        instr_wr_en <= 1'b0;
        // READ_UB state will set ub_rd_en=1 while waiting for ub_rd_valid
        if (state != READ_UB || !read_ub_wait_valid) begin
            ub_rd_en <= 1'b0;
        end
        start_execution <= 1'b0;
        // Don't clear tx_valid here - let each state manage it
        // tx_valid should stay high until tx_ready is true and byte is accepted

        debug_state <= state;
        debug_cmd <= command;
        debug_byte_count <= byte_count;

        case (state)
            // ================================================================
            // IDLE: Wait for command byte
            // ================================================================
            IDLE: begin
                // Clear tx_valid when idle (unless we're sending error response)
                tx_valid <= 1'b0;

                // Only process rx_valid on rising edge to avoid processing same byte multiple times
                // But only if TX is ready (not busy transmitting previous response)
                if (rx_valid && !rx_valid_prev && !rx_framing_error && tx_ready) begin
                    command <= rx_data;
                    byte_count <= 16'h0000;
                    byte_index <= 5'd0;

                    case (rx_data)
                        8'h01: state <= READ_ADDR_HI;  // Write UB
                        8'h02: state <= READ_ADDR_HI;  // Write Weight
                        8'h03: state <= READ_ADDR_HI;  // Write Instruction
                        8'h04: state <= READ_ADDR_HI;  // Read UB
                        8'h05: state <= EXECUTE;       // Start execution
                        8'h06: state <= SEND_STATUS;   // Read status
                        8'h14: state <= READ_DEBUG;    // Read debug counters (0x14 = 20)
                        default: begin
                            // Unrecognized command - send error response (0xFF) to indicate invalid command
                            // This helps diagnose if communication is working but command is wrong
                            tx_valid <= 1'b1;
                            tx_data <= 8'hFF;  // Error: unrecognized command
                            debug_tx_count <= debug_tx_count + 1;
                            state <= IDLE;  // Stay in IDLE
                        end
                    endcase
                end
                // If tx_ready is false, we wait for it to become true before processing new commands
            end

            // ================================================================
            // READ_ADDR_HI: Read high byte of address
            // ================================================================
            READ_ADDR_HI: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    addr_hi <= rx_data;
                    state <= READ_ADDR_LO;
                end
            end

            // ================================================================
            // READ_ADDR_LO: Read low byte of address
            // ================================================================
            READ_ADDR_LO: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    addr_lo <= rx_data;

                    case (command)
                        8'h01: state <= READ_LENGTH_HI;  // Write UB needs length
                        8'h02: state <= READ_LENGTH_HI;  // Write Weight needs length
                        8'h03: state <= WRITE_INSTR;     // Write Instr (fixed 4 bytes)
                        8'h04: state <= READ_LENGTH_HI;  // Read UB needs length
                        default: state <= IDLE;
                    endcase
                end
            end

            // ================================================================
            // READ_LENGTH_HI/LO: Read transfer length
            // ================================================================
            READ_LENGTH_HI: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    length[15:8] <= rx_data;
                    state <= READ_LENGTH_LO;
                end
            end

            READ_LENGTH_LO: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    length[7:0] <= rx_data;

                    case (command)
                        8'h01: state <= WRITE_UB;
                        8'h02: state <= WRITE_WT;
                        8'h04: begin
                            // Start read operation from Unified Buffer
                            ub_rd_en <= 1'b1;
                            ub_rd_addr <= {addr_hi[0], addr_lo};  // 9-bit address: [8]=bank from addr_hi[0], [7:0]=addr_lo
                            ub_rd_count <= 9'd1;  // Read 1 word (256 bits = 32 bytes)
                            byte_count <= 16'h0000;  // Reset byte count for READ_UB
                            read_ub_initialized <= 1'b0;  // Reset initialization flag
                            read_ub_wait_valid <= 1'b1;   // Wait for ub_rd_valid signal
                            state <= READ_UB;
                        end
                        default: state <= IDLE;
                    endcase
                end
            end

            // ================================================================
            // WRITE_UB: Write data to Unified Buffer (32 bytes at a time)
            // ================================================================
            WRITE_UB: begin
                // Update WRITE_UB debug signals
                debug_write_ub_rx_valid <= rx_valid;
                debug_write_ub_rx_data <= rx_data;
                debug_write_ub_byte_count <= byte_count;
                debug_ub_buffer_lsb <= ub_buffer[7:0];
                debug_ub_buffer_msb <= ub_buffer[255:248];

                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    // Accumulate bytes into buffer (newest byte goes to MSB position)
                    // After shift: [255:248] = newest byte, [247:240] = previous, etc.
                    ub_buffer <= {rx_data, ub_buffer[255:8]};
                    byte_index <= byte_index + 1;
                    byte_count <= byte_count + 1;

                    // When we have 32 bytes, write to UB
                    // Check BEFORE increment: when byte_index is 31, we're receiving byte31 (the 32nd byte)
                    // At this point: ub_buffer has bytes 0-30, rx_data = byte31
                    // CRITICAL: This check MUST be inside rx_valid block to ensure rx_data is valid!
                    if (byte_index == 5'd31) begin
                        ub_wr_en <= 1'b1;
                        ub_wr_addr <= {addr_hi[0], addr_lo};  // 9-bit address: [8]=bank from addr_hi[0], [7:0]=addr_lo
                        ub_wr_count <= 9'd1;  // Write 1 word (256 bits = 32 bytes)
                        // CORRECTED byte ordering: byte 0 at [7:0], byte 31 at [255:248]
                        // After 31 bytes received, buffer state is:
                        //   [255:248]=byte30, [247:240]=byte29, ..., [23:16]=byte1, [15:8]=byte0, [7:0]=0
                        // rx_data = byte 31
                        // We need: [7:0]=byte0, [15:8]=byte1, ..., [247:240]=byte30, [255:248]=byte31
                        ub_wr_data <= {
                            rx_data,             ub_buffer[255:248], ub_buffer[247:240], ub_buffer[239:232], // byte31,30,29,28 -> [255:224]
                            ub_buffer[231:224],  ub_buffer[223:216], ub_buffer[215:208], ub_buffer[207:200], // byte27,26,25,24 -> [223:192]
                            ub_buffer[199:192],  ub_buffer[191:184], ub_buffer[183:176], ub_buffer[175:168], // byte23,22,21,20 -> [191:160]
                            ub_buffer[167:160],  ub_buffer[159:152], ub_buffer[151:144], ub_buffer[143:136], // byte19,18,17,16 -> [159:128]
                            ub_buffer[135:128],  ub_buffer[127:120], ub_buffer[119:112], ub_buffer[111:104], // byte15,14,13,12 -> [127:96]
                            ub_buffer[103:96],   ub_buffer[95:88],   ub_buffer[87:80],   ub_buffer[79:72],   // byte11,10,9,8 -> [95:64]
                            ub_buffer[71:64],    ub_buffer[63:56],   ub_buffer[55:48],   ub_buffer[47:40],   // byte7,6,5,4 -> [63:32]
                            ub_buffer[39:32],    ub_buffer[31:24],   ub_buffer[23:16],   ub_buffer[15:8]     // byte3,2,1,0 -> [31:0] CORRECTED: byte0 is at [15:8], not [7:0]
                        };
                        // CORRECTED last_ub_write_data: same ordering as ub_wr_data
                        last_ub_write_data <= {
                            rx_data,             ub_buffer[255:248], ub_buffer[247:240], ub_buffer[239:232],
                            ub_buffer[231:224],  ub_buffer[223:216], ub_buffer[215:208], ub_buffer[207:200],
                            ub_buffer[199:192],  ub_buffer[191:184], ub_buffer[183:176], ub_buffer[175:168],
                            ub_buffer[167:160],  ub_buffer[159:152], ub_buffer[151:144], ub_buffer[143:136],
                            ub_buffer[135:128],  ub_buffer[127:120], ub_buffer[119:112], ub_buffer[111:104],
                            ub_buffer[103:96],   ub_buffer[95:88],   ub_buffer[87:80],   ub_buffer[79:72],
                            ub_buffer[71:64],    ub_buffer[63:56],   ub_buffer[55:48],   ub_buffer[47:40],
                            ub_buffer[39:32],    ub_buffer[31:24],   ub_buffer[23:16],   ub_buffer[15:8]     // CORRECTED: byte0 is at [15:8], not [7:0]
                        };
                        last_ub_write_addr <= addr_lo;

                        // Debug instrumentation: Capture buffer state at 32-byte write
                        // Capture OLD ub_buffer values (before update)
                        debug_ub_buffer_bytes_0_3 <= ub_buffer[31:0];      // First 4 bytes: ub_buffer[31:24]=byte28, ub_buffer[23:16]=byte29, ub_buffer[15:8]=byte30, ub_buffer[7:0]=byte31
                        debug_ub_buffer_bytes_28_31 <= ub_buffer[255:224]; // Last 4 bytes: ub_buffer[255:248]=byte1, ub_buffer[247:240]=byte2, ub_buffer[239:232]=byte3, ub_buffer[231:224]=byte4
                        // Capture what we're storing in last_ub_write_data (should have byte1 at [7:0], byte32 at [255:248])
                        debug_last_write_bytes_0_3 <= {
                            ub_buffer[255:248], ub_buffer[247:240], ub_buffer[239:232], ub_buffer[231:224]  // bytes 1-4: byte1, byte2, byte3, byte4
                        };
                        debug_last_write_bytes_28_31 <= {
                            ub_buffer[31:24], ub_buffer[23:16], ub_buffer[15:8], rx_data  // bytes 29-32: byte29, byte30, byte31, byte32
                        };

                        addr_lo <= addr_lo + 1;  // Increment address for multi-word writes
                        byte_index <= 5'd0;

                        // Check if we're done (use byte_count + 1 since increment is non-blocking)
                        if (byte_count + 1 >= length) begin
                            // Send ACK byte to confirm write completed
                            if (tx_ready) begin
                                tx_valid <= 1'b1;
                                tx_data <= 8'hAA;  // ACK byte
                            end
                            state <= IDLE;
                        end
                    end else if (byte_count + 1 >= length) begin
                        // Partial write path: less than 32 bytes total
                        // CRITICAL: This is inside rx_valid block - ub_buffer hasn't been updated yet!
                        // We must account for rx_data being the CURRENT byte, not yet shifted in.
                        // The NEW buffer would be {rx_data, ub_buffer[255:8]}, so we shift indices by 8.
                        ub_wr_en <= 1'b1;
                        ub_wr_addr <= {addr_hi[0], addr_lo};  // 9-bit address: [8]=bank from addr_hi[0], [7:0]=addr_lo
                        ub_wr_count <= 9'd1;  // Write 1 word (256 bits = 32 bytes)
                        // Construct ub_wr_data as if ub_buffer already had rx_data shifted in:
                        // - OLD [X:Y] maps to NEW [X-8:Y-8]
                        // - OLD [255:248] (MSB) maps to NEW rx_data
                        ub_wr_data <= {
                            ub_buffer[39:32],   ub_buffer[31:24],   ub_buffer[23:16],   ub_buffer[15:8],
                            ub_buffer[71:64],   ub_buffer[63:56],   ub_buffer[55:48],   ub_buffer[47:40],
                            ub_buffer[103:96],  ub_buffer[95:88],   ub_buffer[87:80],   ub_buffer[79:72],
                            ub_buffer[135:128], ub_buffer[127:120], ub_buffer[119:112], ub_buffer[111:104],
                            ub_buffer[167:160], ub_buffer[159:152], ub_buffer[151:144], ub_buffer[143:136],
                            ub_buffer[199:192], ub_buffer[191:184], ub_buffer[183:176], ub_buffer[175:168],
                            ub_buffer[231:224], ub_buffer[223:216], ub_buffer[215:208], ub_buffer[207:200],
                            rx_data,            ub_buffer[255:248], ub_buffer[247:240], ub_buffer[239:232]
                        };
                        // Same for last_ub_write_data
                        last_ub_write_data <= {
                            ub_buffer[39:32],   ub_buffer[31:24],   ub_buffer[23:16],   ub_buffer[15:8],
                            ub_buffer[71:64],   ub_buffer[63:56],   ub_buffer[55:48],   ub_buffer[47:40],
                            ub_buffer[103:96],  ub_buffer[95:88],   ub_buffer[87:80],   ub_buffer[79:72],
                            ub_buffer[135:128], ub_buffer[127:120], ub_buffer[119:112], ub_buffer[111:104],
                            ub_buffer[167:160], ub_buffer[159:152], ub_buffer[151:144], ub_buffer[143:136],
                            ub_buffer[199:192], ub_buffer[191:184], ub_buffer[183:176], ub_buffer[175:168],
                            ub_buffer[231:224], ub_buffer[223:216], ub_buffer[215:208], ub_buffer[207:200],
                            rx_data,            ub_buffer[255:248], ub_buffer[247:240], ub_buffer[239:232]
                        };
                        last_ub_write_addr <= addr_lo;

                        // Send ACK byte to confirm write completed
                        if (tx_ready) begin
                            tx_valid <= 1'b1;
                            tx_data <= 8'hAA;  // ACK byte
                        end

                        state <= IDLE;
                    end
                end
            end

            // ================================================================
            // WRITE_WT: Write data to Weight Memory (8 bytes at a time)
            // ================================================================
            WRITE_WT: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    // Accumulate bytes into buffer - SHIFT RIGHT so byte0 ends up at LSB
                    // This ensures wt_wr_data[7:0] = byte0, [15:8] = byte1, etc.
                    wt_buffer <= {rx_data, wt_buffer[63:8]};
                    byte_index <= byte_index + 1;
                    byte_count <= byte_count + 1;

                    // When we have 8 bytes, write to Weight Memory
                    if (byte_index == 5'd7) begin
                        wt_wr_en <= 1'b1;
                        wt_wr_addr <= {addr_hi[1:0], addr_lo};
                        wt_wr_data <= {rx_data, wt_buffer[63:8]};

                        addr_lo <= addr_lo + 1;
                        if (addr_lo == 8'hFF) addr_hi <= addr_hi + 1;
                        byte_index <= 5'd0;

                        // Check if done after 8-byte write
                        if (byte_count + 1 >= length) begin
                            if (tx_ready) begin
                                tx_valid <= 1'b1;
                                tx_data <= 8'hBB;  // ACK for weight write
                            end
                            state <= IDLE;
                        end
                    end else if (byte_count + 1 >= length) begin
                        // Partial write (less than 8 bytes total)
                        wt_wr_en <= 1'b1;
                        wt_wr_addr <= {addr_hi[1:0], addr_lo};
                        wt_wr_data <= {rx_data, wt_buffer[63:8]};

                        // Send ACK
                        if (tx_ready) begin
                            tx_valid <= 1'b1;
                            tx_data <= 8'hBB;  // ACK for weight write
                        end

                        state <= IDLE;
                    end
                end
            end

            // ================================================================
            // WRITE_INSTR: Write instruction (4 bytes)
            // ================================================================
            WRITE_INSTR: begin
                // CRITICAL: Must use edge detection to avoid processing same byte multiple times
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    instr_buffer <= {instr_buffer[23:0], rx_data};
                    byte_count <= byte_count + 1;

                    if (byte_count == 16'd3) begin
                        // Write complete instruction
                        instr_wr_en <= 1'b1;
                        instr_wr_addr <= addr_lo[4:0];
                        instr_wr_data <= {instr_buffer[23:0], rx_data};
                        state <= IDLE;
                    end
                end
            end

            // ================================================================
            // READ_UB: Read data from Unified Buffer and send via UART
            // ================================================================
            READ_UB: begin
                // Allow new commands to interrupt this state (but only if TX is ready)
                if (rx_valid && !rx_valid_prev && !rx_framing_error && tx_ready) begin
                    // New command received - abort READ_UB and process new command
                    command <= rx_data;
                    byte_count <= 16'h0000;
                    byte_index <= 5'd0;
                    read_ub_initialized <= 1'b0;  // Reset initialization flag when interrupted
                    read_ub_wait_valid <= 1'b0;   // Reset wait flag when interrupted
                    ub_rd_en <= 1'b0;  // Clear read enable
                    
                    case (rx_data)
                        8'h01: state <= READ_ADDR_HI;  // Write UB
                        8'h02: state <= READ_ADDR_HI;  // Write Weight
                        8'h03: state <= READ_ADDR_HI;  // Write Instruction
                        8'h04: state <= READ_ADDR_HI;  // Read UB (restart)
                        8'h05: state <= EXECUTE;       // Start execution
                        8'h06: state <= SEND_STATUS;   // Read status
                        8'h14: state <= READ_DEBUG;    // Read debug counters
                        default: state <= IDLE;
                    endcase
                end else begin
                    // Debug: Track READ_UB internal signals
                    debug_read_ub_tx_ready <= tx_ready;
                    debug_read_ub_tx_valid <= tx_valid;
                    debug_read_ub_length <= length;
                    debug_read_ub_byte_count <= byte_count;
                    debug_read_ub_buffer_lsb <= read_buffer[7:0];
                    
                    // State machine priority: Wait for valid > Initialize > Advance > Send
                    
                    if (read_ub_wait_valid) begin
                        // Waiting for unified buffer to provide valid data
                        if (ub_rd_valid) begin
                            // Data is now valid - capture it
                            read_buffer <= ub_rd_data;  // Capture actual data from unified buffer
                            read_index <= 8'd0;
                            byte_count <= 16'd0;
                            tx_valid <= 1'b0;
                            read_ub_wait_valid <= 1'b0;  // Done waiting
                            read_ub_initialized <= 1'b1; // Mark as initialized
                            ub_rd_en <= 1'b0;  // Clear read enable after data is captured
                            debug_last_tx_byte <= 8'hAA;  // Debug: mark READ_UB data captured
                            
                            // Debug instrumentation: Capture read_buffer state after initialization
                            debug_read_buffer_bytes_0_3 <= ub_rd_data[31:0];      // First 4 bytes
                            debug_read_buffer_bytes_28_31 <= ub_rd_data[255:224]; // Last 4 bytes
                        end
                        // Otherwise keep waiting with ub_rd_en high
                    end else if (!read_ub_initialized) begin
                        // This should not happen - we should always wait for valid first
                        // But just in case, fall back to last written data
                        read_buffer <= last_ub_write_data;
                        read_index <= 8'd0;
                        byte_count <= 16'd0;
                        tx_valid <= 1'b0;
                        read_ub_initialized <= 1'b1;
                        debug_last_tx_byte <= 8'hEE;  // Debug: fallback path
                        
                        debug_read_buffer_bytes_0_3 <= last_ub_write_data[31:0];
                        debug_read_buffer_bytes_28_31 <= last_ub_write_data[255:224];
                    end else if (tx_ready && tx_valid) begin
                        // Byte was just accepted by TX module - advance to next byte
                        tx_valid <= 1'b0;
                        read_buffer <= {8'h00, read_buffer[255:8]};  // Shift buffer RIGHT
                        read_index <= read_index + 1;
                        byte_count <= byte_count + 1;  // Increment count of bytes sent
                        debug_last_tx_byte <= read_buffer[7:0];  // Debug: what was sent

                        // Check if we've sent all requested bytes
                        if (byte_count + 1 >= length) begin
                            // All bytes sent - go to IDLE
                            state <= IDLE;
                            byte_count <= 16'd0;
                            read_ub_initialized <= 1'b0;  // Reset for next READ_UB
                            read_ub_wait_valid <= 1'b0;   // Reset wait flag
                            debug_last_tx_byte <= 8'hBB;  // Debug: READ_UB complete
                        end
                    end else if (tx_ready && !tx_valid && byte_count < length) begin
                        // TX is ready and we have data to send - send next byte
                        tx_valid <= 1'b1;
                        tx_data <= read_buffer[7:0];  // Send LSB of buffer
                        debug_tx_count <= debug_tx_count + 1;
                        debug_last_tx_byte <= 8'hCC;  // Debug: sending byte
                    end
                    // If none of the above, wait (TX not ready, already sending, or not initialized)
                end
            end

            // ================================================================
            // EXECUTE: Start TPU execution
            // ================================================================
            EXECUTE: begin
                start_execution <= 1'b1;
                state <= IDLE;
            end

            // ================================================================
            // SEND_STATUS: Send status byte back to host
            // ================================================================
            SEND_STATUS: begin
                // Allow new commands to interrupt this state
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    // New command received - abort SEND_STATUS and process new command
                    command <= rx_data;
                    byte_count <= 16'h0000;
                    byte_index <= 5'd0;
                    
                    case (rx_data)
                        8'h01: state <= READ_ADDR_HI;  // Write UB
                        8'h02: state <= READ_ADDR_HI;  // Write Weight
                        8'h03: state <= READ_ADDR_HI;  // Write Instruction
                        8'h04: state <= READ_ADDR_HI;  // Read UB
                        8'h05: state <= EXECUTE;       // Start execution
                        8'h06: state <= SEND_STATUS;   // Read status (restart)
                        8'h14: state <= READ_DEBUG;    // Read debug counters
                        default: state <= IDLE;
                    endcase
                end else begin
                    // Always send status byte when TX is ready
                    // CRITICAL: Status byte format includes halt_req in bit 7 for Python script detection
                    // [7]=halt_req, [6]=0, [5]=ub_done, [4]=ub_busy,
                    // [3]=vpu_done, [2]=vpu_busy, [1]=sys_done, [0]=sys_busy
                    // Python script looks for bit 7 (0x80) to detect HALT completion
                if (tx_ready) begin
                    tx_valid <= 1'b1;
                    tx_data <= {halt_req, 1'b0, ub_done, ub_busy, vpu_done, vpu_busy, sys_done, sys_busy};
                        debug_tx_count <= debug_tx_count + 1;
                        debug_last_tx_byte <= {halt_req, 1'b0, ub_done, ub_busy, vpu_done, vpu_busy, sys_done, sys_busy};  // Track what we're sending
                        state <= IDLE;
                    end else begin
                        // Keep tx_valid high until tx_ready goes true
                        tx_valid <= 1'b1;
                        tx_data <= {halt_req, 1'b0, ub_done, ub_busy, vpu_done, vpu_busy, sys_done, sys_busy};
                    end
                end
            end

            // ================================================================
            // READ_DEBUG: Send debug counters back to host (for debugging)
            // ================================================================
            READ_DEBUG: begin
                // Allow new commands to interrupt this state
                if (rx_valid && !rx_valid_prev && !rx_framing_error) begin
                    // New command received - abort READ_DEBUG and process new command
                    command <= rx_data;
                    byte_count <= 16'h0000;
                    byte_index <= 5'd0;
                    tx_valid <= 1'b0;  // Clear tx_valid when interrupted
                    
                    case (rx_data)
                        8'h01: state <= READ_ADDR_HI;  // Write UB
                        8'h02: state <= READ_ADDR_HI;  // Write Weight
                        8'h03: state <= READ_ADDR_HI;  // Write Instruction
                        8'h04: state <= READ_ADDR_HI;  // Read UB
                        8'h05: state <= EXECUTE;       // Start execution
                        8'h06: state <= SEND_STATUS;   // Read status
                        8'h14: begin
                            // Restart READ_DEBUG
                            byte_count <= 16'h0000;
                            state <= READ_DEBUG;
                        end
                        default: state <= IDLE;
                    endcase
                end else if (tx_ready && tx_valid) begin
                    // Byte was just accepted by TX module - clear tx_valid and increment byte_count
                    tx_valid <= 1'b0;
                    if (byte_count < 16'd9) begin
                        byte_count <= byte_count + 1;
                    end else begin
                        // Last byte sent - go to IDLE
                        byte_count <= 16'd0;
                        state <= IDLE;
                    end
                end else if (tx_ready && !tx_valid) begin
                    // TX is ready and we're not sending - send next byte
                    tx_valid <= 1'b1;
                    case (byte_count)
                        16'd0: tx_data <= state;  // Current state
                        16'd1: tx_data <= debug_rx_count[7:0];  // RX count byte 0
                        16'd2: tx_data <= debug_rx_count[15:8];  // RX count byte 1
                        16'd3: tx_data <= debug_rx_count[23:16];  // RX count byte 2
                        16'd4: tx_data <= debug_rx_count[31:24];  // RX count byte 3
                        16'd5: tx_data <= debug_tx_count[7:0];  // TX count byte 0
                        16'd6: tx_data <= debug_tx_count[15:8];  // TX count byte 1
                        16'd7: tx_data <= debug_tx_count[23:16];  // TX count byte 2
                        16'd8: tx_data <= debug_tx_count[31:24];  // TX count byte 3
                        16'd9: tx_data <= debug_last_rx_byte;  // Last RX byte
                        default: begin
                            tx_valid <= 1'b0;
                            byte_count <= 16'd0;
                    state <= IDLE;
                        end
                    endcase
                end else begin
                    // TX not ready or tx_valid already set - keep current state
                    // tx_valid stays high until tx_ready goes true and byte is accepted
                end
            end

            default: state <= IDLE;
        endcase
    end
end

endmodule
