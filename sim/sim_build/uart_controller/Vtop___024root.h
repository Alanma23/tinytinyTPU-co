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
        VL_IN8(uart_rx_pin,0,0);
        VL_OUT8(uart_tx_pin,0,0);
        VL_OUT8(wf_push_col0,0,0);
        VL_OUT8(wf_push_col1,0,0);
        VL_OUT8(wf_data_in,7,0);
        VL_OUT8(wf_reset,0,0);
        VL_OUT8(init_act_valid,0,0);
        VL_OUT8(start_mlp,0,0);
        VL_OUT8(weights_ready,0,0);
        VL_IN8(state_in,3,0);
        VL_IN8(layer_complete,0,0);
        VL_OUT8(debug_state,7,0);
        VL_OUT8(debug_cmd,7,0);
        CData/*0:0*/ uart_controller__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_rx_pin;
        CData/*0:0*/ uart_controller__DOT__uart_tx_pin;
        CData/*0:0*/ uart_controller__DOT__wf_push_col0;
        CData/*0:0*/ uart_controller__DOT__wf_push_col1;
        CData/*7:0*/ uart_controller__DOT__wf_data_in;
        CData/*0:0*/ uart_controller__DOT__wf_reset;
        CData/*0:0*/ uart_controller__DOT__init_act_valid;
        CData/*0:0*/ uart_controller__DOT__start_mlp;
        CData/*0:0*/ uart_controller__DOT__weights_ready;
        CData/*3:0*/ uart_controller__DOT__state_in;
        CData/*0:0*/ uart_controller__DOT__layer_complete;
        CData/*7:0*/ uart_controller__DOT__debug_state;
        CData/*7:0*/ uart_controller__DOT__debug_cmd;
        CData/*7:0*/ uart_controller__DOT__rx_data;
        CData/*0:0*/ uart_controller__DOT__rx_valid;
        CData/*0:0*/ uart_controller__DOT__rx_ready;
        CData/*7:0*/ uart_controller__DOT__tx_data;
        CData/*0:0*/ uart_controller__DOT__tx_valid;
        CData/*0:0*/ uart_controller__DOT__tx_ready;
        CData/*3:0*/ uart_controller__DOT__cmd_state;
        CData/*7:0*/ uart_controller__DOT__command;
        CData/*2:0*/ uart_controller__DOT__byte_count;
        CData/*0:0*/ uart_controller__DOT__rx_valid_prev;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx;
        CData/*7:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_data;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_valid;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_ready;
        CData/*1:0*/ uart_controller__DOT__uart_rx_inst__DOT__state;
        CData/*2:0*/ uart_controller__DOT__uart_rx_inst__DOT__bit_index;
        CData/*7:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_byte;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1;
        CData/*0:0*/ uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2;
        CData/*0:0*/ uart_controller__DOT__uart_tx_inst__DOT__clk;
        CData/*0:0*/ uart_controller__DOT__uart_tx_inst__DOT__rst;
        CData/*0:0*/ uart_controller__DOT__uart_tx_inst__DOT__tx;
        CData/*7:0*/ uart_controller__DOT__uart_tx_inst__DOT__tx_data;
        CData/*0:0*/ uart_controller__DOT__uart_tx_inst__DOT__tx_valid;
        CData/*0:0*/ uart_controller__DOT__uart_tx_inst__DOT__tx_ready;
        CData/*1:0*/ uart_controller__DOT__uart_tx_inst__DOT__state;
        CData/*2:0*/ uart_controller__DOT__uart_tx_inst__DOT__bit_index;
        CData/*7:0*/ uart_controller__DOT__uart_tx_inst__DOT__tx_byte;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__rst__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__rst__0;
        VL_OUT16(init_act_data,15,0);
        SData/*15:0*/ uart_controller__DOT__init_act_data;
        SData/*15:0*/ uart_controller__DOT__uart_rx_inst__DOT__clk_count;
        SData/*15:0*/ uart_controller__DOT__uart_tx_inst__DOT__clk_count;
        VL_IN(acc0,31,0);
        VL_IN(acc1,31,0);
        IData/*31:0*/ uart_controller__DOT__acc0;
        IData/*31:0*/ uart_controller__DOT__acc1;
        IData/*31:0*/ uart_controller__DOT__weight_buffer;
        IData/*31:0*/ uart_controller__DOT__act_buffer;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ uart_controller__DOT__result_buffer;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ uart_controller__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_inst__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_inst__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_inst__DOT__CLKS_PER_BIT = 0x00000364U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_rx_inst__DOT__HALF_BIT = 0x000001b2U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_inst__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_inst__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_controller__DOT__uart_tx_inst__DOT__CLKS_PER_BIT = 0x00000364U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
