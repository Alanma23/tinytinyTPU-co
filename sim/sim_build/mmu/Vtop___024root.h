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
        VL_IN8(reset,0,0);
        VL_IN8(en_weight_pass,0,0);
        VL_IN8(en_capture_col0,0,0);
        VL_IN8(en_capture_col1,0,0);
        VL_IN8(row0_in,7,0);
        VL_IN8(row1_in,7,0);
        VL_IN8(col0_in,7,0);
        VL_IN8(col1_in,7,0);
        CData/*0:0*/ mmu__DOT__clk;
        CData/*0:0*/ mmu__DOT__reset;
        CData/*0:0*/ mmu__DOT__en_weight_pass;
        CData/*0:0*/ mmu__DOT__en_capture_col0;
        CData/*0:0*/ mmu__DOT__en_capture_col1;
        CData/*7:0*/ mmu__DOT__row0_in;
        CData/*7:0*/ mmu__DOT__row1_in;
        CData/*7:0*/ mmu__DOT__col0_in;
        CData/*7:0*/ mmu__DOT__col1_in;
        CData/*7:0*/ mmu__DOT__pe00_01_act;
        CData/*7:0*/ mmu__DOT__pe10_11_act;
        CData/*0:0*/ mmu__DOT__pe00__DOT__clk;
        CData/*0:0*/ mmu__DOT__pe00__DOT__reset;
        CData/*0:0*/ mmu__DOT__pe00__DOT__en_weight_pass;
        CData/*0:0*/ mmu__DOT__pe00__DOT__en_weight_capture;
        CData/*7:0*/ mmu__DOT__pe00__DOT__in_act;
        CData/*7:0*/ mmu__DOT__pe00__DOT__out_act;
        CData/*7:0*/ mmu__DOT__pe00__DOT__weight;
        CData/*0:0*/ mmu__DOT__pe01__DOT__clk;
        CData/*0:0*/ mmu__DOT__pe01__DOT__reset;
        CData/*0:0*/ mmu__DOT__pe01__DOT__en_weight_pass;
        CData/*0:0*/ mmu__DOT__pe01__DOT__en_weight_capture;
        CData/*7:0*/ mmu__DOT__pe01__DOT__in_act;
        CData/*7:0*/ mmu__DOT__pe01__DOT__out_act;
        CData/*7:0*/ mmu__DOT__pe01__DOT__weight;
        CData/*0:0*/ mmu__DOT__pe10__DOT__clk;
        CData/*0:0*/ mmu__DOT__pe10__DOT__reset;
        CData/*0:0*/ mmu__DOT__pe10__DOT__en_weight_pass;
        CData/*0:0*/ mmu__DOT__pe10__DOT__en_weight_capture;
        CData/*7:0*/ mmu__DOT__pe10__DOT__in_act;
        CData/*7:0*/ mmu__DOT__pe10__DOT__out_act;
        CData/*7:0*/ mmu__DOT__pe10__DOT__weight;
        CData/*0:0*/ mmu__DOT__pe11__DOT__clk;
        CData/*0:0*/ mmu__DOT__pe11__DOT__reset;
        CData/*0:0*/ mmu__DOT__pe11__DOT__en_weight_pass;
        CData/*0:0*/ mmu__DOT__pe11__DOT__en_weight_capture;
        CData/*7:0*/ mmu__DOT__pe11__DOT__in_act;
        CData/*7:0*/ mmu__DOT__pe11__DOT__out_act;
        CData/*7:0*/ mmu__DOT__pe11__DOT__weight;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__clk__0;
        VL_OUT16(acc0_out,15,0);
        VL_OUT16(acc1_out,15,0);
        SData/*15:0*/ mmu__DOT__acc0_out;
        SData/*15:0*/ mmu__DOT__acc1_out;
        SData/*15:0*/ mmu__DOT__pe00_10_psum;
        SData/*15:0*/ mmu__DOT__pe01_11_psum;
        SData/*15:0*/ mmu__DOT__pe00__DOT__in_psum;
        SData/*15:0*/ mmu__DOT__pe00__DOT__out_psum;
        SData/*15:0*/ mmu__DOT__pe01__DOT__in_psum;
        SData/*15:0*/ mmu__DOT__pe01__DOT__out_psum;
    };
    struct {
        SData/*15:0*/ mmu__DOT__pe10__DOT__in_psum;
        SData/*15:0*/ mmu__DOT__pe10__DOT__out_psum;
        SData/*15:0*/ mmu__DOT__pe11__DOT__in_psum;
        SData/*15:0*/ mmu__DOT__pe11__DOT__out_psum;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

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
