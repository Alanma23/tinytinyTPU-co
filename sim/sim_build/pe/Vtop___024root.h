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
    VL_IN8(en_weight_pass,0,0);
    VL_IN8(en_weight_capture,0,0);
    VL_IN8(in_act,7,0);
    VL_OUT8(out_act,7,0);
    CData/*0:0*/ pe__DOT__clk;
    CData/*0:0*/ pe__DOT__reset;
    CData/*0:0*/ pe__DOT__en_weight_pass;
    CData/*0:0*/ pe__DOT__en_weight_capture;
    CData/*7:0*/ pe__DOT__in_act;
    CData/*7:0*/ pe__DOT__out_act;
    CData/*7:0*/ pe__DOT__weight;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pe__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pe__DOT__reset__0;
    VL_IN16(in_psum,15,0);
    VL_OUT16(out_psum,15,0);
    SData/*15:0*/ pe__DOT__in_psum;
    SData/*15:0*/ pe__DOT__out_psum;
    IData/*31:0*/ __VactIterCount;
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
