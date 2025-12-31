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
    VL_IN8(reset,0,0);
    VL_IN8(push_col0,0,0);
    VL_IN8(push_col1,0,0);
    VL_IN8(data_in,7,0);
    VL_IN8(pop,0,0);
    VL_OUT8(col0_out,7,0);
    VL_OUT8(col1_out,7,0);
    VL_OUT8(col1_raw,7,0);
    CData/*0:0*/ dual_weight_fifo__DOT__clk;
    CData/*0:0*/ dual_weight_fifo__DOT__reset;
    CData/*0:0*/ dual_weight_fifo__DOT__push_col0;
    CData/*0:0*/ dual_weight_fifo__DOT__push_col1;
    CData/*7:0*/ dual_weight_fifo__DOT__data_in;
    CData/*0:0*/ dual_weight_fifo__DOT__pop;
    CData/*7:0*/ dual_weight_fifo__DOT__col0_out;
    CData/*7:0*/ dual_weight_fifo__DOT__col1_out;
    CData/*7:0*/ dual_weight_fifo__DOT__col1_raw;
    CData/*1:0*/ dual_weight_fifo__DOT__wr_ptr0;
    CData/*1:0*/ dual_weight_fifo__DOT__rd_ptr0;
    CData/*1:0*/ dual_weight_fifo__DOT__wr_ptr1;
    CData/*1:0*/ dual_weight_fifo__DOT__rd_ptr1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dual_weight_fifo__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dual_weight_fifo__DOT__reset__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4> dual_weight_fifo__DOT__queue0;
    VlUnpacked<CData/*7:0*/, 4> dual_weight_fifo__DOT__queue1;
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
