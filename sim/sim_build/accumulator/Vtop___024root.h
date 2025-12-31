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
    VL_IN8(accumulator_enable,0,0);
    VL_IN8(addr_sel,0,0);
    VL_OUT8(valid_out,0,0);
    CData/*0:0*/ accumulator__DOT__clk;
    CData/*0:0*/ accumulator__DOT__reset;
    CData/*0:0*/ accumulator__DOT__valid_in;
    CData/*0:0*/ accumulator__DOT__accumulator_enable;
    CData/*0:0*/ accumulator__DOT__addr_sel;
    CData/*0:0*/ accumulator__DOT__valid_out;
    CData/*0:0*/ accumulator__DOT__aligned_valid;
    CData/*0:0*/ accumulator__DOT__u_align__DOT__clk;
    CData/*0:0*/ accumulator__DOT__u_align__DOT__reset;
    CData/*0:0*/ accumulator__DOT__u_align__DOT__valid_in;
    CData/*0:0*/ accumulator__DOT__u_align__DOT__aligned_valid;
    CData/*0:0*/ accumulator__DOT__u_align__DOT__pending;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__clk;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__reset;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__enable;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__accumulator_mode;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__buffer_select;
    CData/*0:0*/ accumulator__DOT__u_mem__DOT__valid_out;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__reset__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__reset__0;
    VL_IN16(mmu_col0_in,15,0);
    VL_IN16(mmu_col1_in,15,0);
    SData/*15:0*/ accumulator__DOT__mmu_col0_in;
    SData/*15:0*/ accumulator__DOT__mmu_col1_in;
    SData/*15:0*/ accumulator__DOT__aligned_c0;
    SData/*15:0*/ accumulator__DOT__aligned_c1;
    SData/*15:0*/ accumulator__DOT__u_align__DOT__raw_col0;
    SData/*15:0*/ accumulator__DOT__u_align__DOT__raw_col1;
    SData/*15:0*/ accumulator__DOT__u_align__DOT__align_col0;
    SData/*15:0*/ accumulator__DOT__u_align__DOT__align_col1;
    SData/*15:0*/ accumulator__DOT__u_align__DOT__col0_delay_reg;
    SData/*15:0*/ accumulator__DOT__u_mem__DOT__in_col0;
    SData/*15:0*/ accumulator__DOT__u_mem__DOT__in_col1;
    VL_OUT(acc_col0_out,31,0);
    VL_OUT(acc_col1_out,31,0);
    IData/*31:0*/ accumulator__DOT__acc_col0_out;
    IData/*31:0*/ accumulator__DOT__acc_col1_out;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__out_col0;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__out_col1;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__mem_buff0_col0;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__mem_buff0_col1;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__mem_buff1_col0;
    IData/*31:0*/ accumulator__DOT__u_mem__DOT__mem_buff1_col1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*0:0*/ accumulator__DOT__u_mem__DOT__BYPASS_READ_NEW = 1U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
