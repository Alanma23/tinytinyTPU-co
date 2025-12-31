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
    VL_IN8(push,0,0);
    VL_IN8(pop,0,0);
    VL_IN8(data_in,7,0);
    VL_OUT8(data_out,7,0);
    CData/*0:0*/ weight_fifo__DOT__clk;
    CData/*0:0*/ weight_fifo__DOT__rst;
    CData/*0:0*/ weight_fifo__DOT__push;
    CData/*0:0*/ weight_fifo__DOT__pop;
    CData/*7:0*/ weight_fifo__DOT__data_in;
    CData/*7:0*/ weight_fifo__DOT__data_out;
    CData/*1:0*/ weight_fifo__DOT__wr_ptr;
    CData/*1:0*/ weight_fifo__DOT__rd_ptr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__weight_fifo__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__weight_fifo__DOT__rst__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4> weight_fifo__DOT__buffer;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
