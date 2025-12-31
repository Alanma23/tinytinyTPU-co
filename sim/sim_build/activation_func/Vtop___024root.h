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
    VL_IN8(valid_in,0,0);
    VL_OUT8(valid_out,0,0);
    CData/*0:0*/ activation_func__DOT__clk;
    CData/*0:0*/ activation_func__DOT__reset;
    CData/*0:0*/ activation_func__DOT__valid_in;
    CData/*0:0*/ activation_func__DOT__valid_out;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__activation_func__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__activation_func__DOT__reset__0;
    VL_IN(data_in,31,0);
    VL_OUT(data_out,31,0);
    IData/*31:0*/ activation_func__DOT__data_in;
    IData/*31:0*/ activation_func__DOT__data_out;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*1:0*/ activation_func__DOT__DEFAULT_ACT = 1U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
