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
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(rx,0,0);
    VL_OUT8(rx_data,7,0);
    VL_OUT8(rx_valid,0,0);
    VL_OUT8(rx_ready,0,0);
    CData/*0:0*/ uart_rx__DOT__clk;
    CData/*0:0*/ uart_rx__DOT__rst;
    CData/*0:0*/ uart_rx__DOT__rx;
    CData/*7:0*/ uart_rx__DOT__rx_data;
    CData/*0:0*/ uart_rx__DOT__rx_valid;
    CData/*0:0*/ uart_rx__DOT__rx_ready;
    CData/*1:0*/ uart_rx__DOT__state;
    CData/*2:0*/ uart_rx__DOT__bit_index;
    CData/*7:0*/ uart_rx__DOT__rx_byte;
    CData/*0:0*/ uart_rx__DOT__rx_sync_1;
    CData/*0:0*/ uart_rx__DOT__rx_sync_2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__uart_rx__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__uart_rx__DOT__rst__0;
    SData/*15:0*/ uart_rx__DOT__clk_count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ uart_rx__DOT__CLOCK_FREQ = 0x05f5e100U;
    static constexpr IData/*31:0*/ uart_rx__DOT__BAUD_RATE = 0x0001c200U;
    static constexpr IData/*31:0*/ uart_rx__DOT__CLKS_PER_BIT = 0x00000364U;
    static constexpr IData/*31:0*/ uart_rx__DOT__HALF_BIT = 0x000001b2U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
