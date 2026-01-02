// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(uart_rx,0,0);
        VL_OUT8(uart_tx,0,0);
        VL_OUT8(wf_push_col0,0,0);
        VL_OUT8(wf_push_col1,0,0);
        VL_OUT8(wf_data_in,7,0);
        VL_OUT8(wf_reset,0,0);
        VL_OUT8(init_act_valid,0,0);
        VL_OUT8(start_mlp,0,0);
        VL_OUT8(weights_ready,0,0);
        VL_IN8(mlp_state,3,0);
        VL_IN8(mlp_cycle_cnt,4,0);
        VL_OUT8(dbg_state,3,0);
        VL_OUT8(dbg_cmd_reg,7,0);
        VL_OUT8(dbg_byte_count,2,0);
        VL_OUT8(dbg_resp_byte_idx,1,0);
        VL_OUT8(dbg_tx_valid,0,0);
        VL_OUT8(dbg_tx_ready,0,0);
        VL_OUT8(dbg_rx_valid,0,0);
        VL_OUT8(dbg_rx_data,7,0);
        VL_OUT8(dbg_weights_ready,0,0);
        VL_OUT8(dbg_start_mlp,0,0);
        CData/*0:0*/ uart_controller__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_rx;
        CData/*0:0*/ uart_controller__DOT__uart_tx;
        CData/*0:0*/ uart_controller__DOT__wf_push_col0;
        CData/*0:0*/ uart_controller__DOT__wf_push_col1;
        CData/*7:0*/ uart_controller__DOT__wf_data_in;
        CData/*0:0*/ uart_controller__DOT__wf_reset;
        CData/*0:0*/ uart_controller__DOT__init_act_valid;
        CData/*0:0*/ uart_controller__DOT__start_mlp;
        CData/*0:0*/ uart_controller__DOT__weights_ready;
        CData/*3:0*/ uart_controller__DOT__mlp_state;
        CData/*4:0*/ uart_controller__DOT__mlp_cycle_cnt;
        CData/*3:0*/ uart_controller__DOT__dbg_state;
        CData/*7:0*/ uart_controller__DOT__dbg_cmd_reg;
        CData/*2:0*/ uart_controller__DOT__dbg_byte_count;
        CData/*1:0*/ uart_controller__DOT__dbg_resp_byte_idx;
        CData/*0:0*/ uart_controller__DOT__dbg_tx_valid;
        CData/*0:0*/ uart_controller__DOT__dbg_tx_ready;
        CData/*0:0*/ uart_controller__DOT__dbg_rx_valid;
        CData/*7:0*/ uart_controller__DOT__dbg_rx_data;
        CData/*0:0*/ uart_controller__DOT__dbg_weights_ready;
        CData/*0:0*/ uart_controller__DOT__dbg_start_mlp;
        CData/*7:0*/ uart_controller__DOT__rx_data;
        CData/*0:0*/ uart_controller__DOT__rx_valid;
        CData/*0:0*/ uart_controller__DOT__rx_ready;
        CData/*7:0*/ uart_controller__DOT__tx_data;
        CData/*0:0*/ uart_controller__DOT__tx_valid;
        CData/*0:0*/ uart_controller__DOT__tx_ready;
        CData/*3:0*/ uart_controller__DOT__state;
        CData/*7:0*/ uart_controller__DOT__cmd_reg;
        CData/*2:0*/ uart_controller__DOT__byte_count;
        CData/*1:0*/ uart_controller__DOT__resp_byte_idx;
        CData/*2:0*/ uart_controller__DOT__weight_seq_idx;
        CData/*1:0*/ uart_controller__DOT__act_seq_idx;
        CData/*0:0*/ uart_controller__DOT__byte_sent;
        CData/*7:0*/ uart_controller__DOT__resp_delay_count;
        CData/*0:0*/ uart_controller__DOT__wf_reset_reg;
        CData/*0:0*/ uart_controller__DOT__weights_ready_reg;
        CData/*3:0*/ uart_controller__DOT__mlp_state_prev;
        CData/*0:0*/ uart_controller__DOT__wf_push_col0_reg;
    };
    struct {
        CData/*0:0*/ uart_controller__DOT__wf_push_col1_reg;
        CData/*7:0*/ uart_controller__DOT__wf_data_in_reg;
        CData/*0:0*/ uart_controller__DOT__init_act_valid_reg;
        CData/*0:0*/ uart_controller__DOT__start_mlp_reg;
        CData/*0:0*/ uart_controller__DOT__tx_valid_reg;
        CData/*7:0*/ uart_controller__DOT__tx_data_reg;
        CData/*0:0*/ uart_controller__DOT__start_mlp_sticky;
        CData/*7:0*/ uart_controller__DOT__rx_data_captured;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rx;
        CData/*7:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_data;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_valid;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_ready;
        CData/*1:0*/ uart_controller__DOT__uart_rx_u__DOT__state;
        CData/*2:0*/ uart_controller__DOT__uart_rx_u__DOT__bit_index;
        CData/*7:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_byte;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_sync_1;
        CData/*0:0*/ uart_controller__DOT__uart_rx_u__DOT__rx_sync_2;
        CData/*0:0*/ uart_controller__DOT__uart_tx_u__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__uart_tx_u__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_tx_u__DOT__tx;
        CData/*7:0*/ uart_controller__DOT__uart_tx_u__DOT__tx_data;
        CData/*0:0*/ uart_controller__DOT__uart_tx_u__DOT__tx_valid;
        CData/*0:0*/ uart_controller__DOT__uart_tx_u__DOT__tx_ready;
        CData/*1:0*/ uart_controller__DOT__uart_tx_u__DOT__state;
        CData/*2:0*/ uart_controller__DOT__uart_tx_u__DOT__bit_index;
        CData/*7:0*/ uart_controller__DOT__uart_tx_u__DOT__tx_byte;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__clk__0;
        VL_OUT16(init_act_data,15,0);
        SData/*15:0*/ uart_controller__DOT__init_act_data;
        SData/*15:0*/ uart_controller__DOT__init_act_data_reg;
        SData/*15:0*/ uart_controller__DOT__uart_rx_u__DOT__clk_count;
        SData/*15:0*/ uart_controller__DOT__uart_tx_u__DOT__clk_count;
        VL_IN(mlp_acc0,31,0);
        VL_IN(mlp_acc1,31,0);
        IData/*31:0*/ uart_controller__DOT__mlp_acc0;
        IData/*31:0*/ uart_controller__DOT__mlp_acc1;
        IData/*31:0*/ uart_controller__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 4> uart_controller__DOT__data_buffer;
        VlUnpacked<CData/*7:0*/, 4> uart_controller__DOT__resp_buffer;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 4>, false, CData/*7:0*/, 1> __VdlyCommitQueueuart_controller__DOT__data_buffer;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 4>, false, CData/*7:0*/, 1> __VdlyCommitQueueuart_controller__DOT__resp_buffer;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_WRITE_WEIGHT = 1U;
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_WRITE_ACT = 2U;
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_EXECUTE = 3U;
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_READ_RESULT = 4U;
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_STATUS = 5U;
    static constexpr CData/*7:0*/ uart_controller__DOT__CMD_READ_RESULT_COL1 = 6U;
    static constexpr CData/*3:0*/ uart_controller__DOT__MLP_STATE_LOAD_WEIGHT = 1U;
    static constexpr IData/*31:0*/ uart_controller__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_u__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_u__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_u__DOT__CLKS_PER_BIT = 0x00000364U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_u__DOT__HALF_BIT = 0x000001b2U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_u__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_u__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_u__DOT__CLKS_PER_BIT = 0x00000364U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
