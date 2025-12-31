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
        VL_IN8(valid_in,0,0);
        VL_IN8(norm_shift,4,0);
        VL_IN8(q_zero_point,7,0);
        VL_OUT8(valid_out,0,0);
        VL_OUT8(ub_data_out,7,0);
        VL_OUT8(loss_valid,0,0);
        CData/*0:0*/ activation_pipeline__DOT__clk;
        CData/*0:0*/ activation_pipeline__DOT__reset;
        CData/*0:0*/ activation_pipeline__DOT__valid_in;
        CData/*4:0*/ activation_pipeline__DOT__norm_shift;
        CData/*7:0*/ activation_pipeline__DOT__q_zero_point;
        CData/*0:0*/ activation_pipeline__DOT__valid_out;
        CData/*7:0*/ activation_pipeline__DOT__ub_data_out;
        CData/*0:0*/ activation_pipeline__DOT__loss_valid;
        CData/*0:0*/ activation_pipeline__DOT__s1_valid;
        CData/*0:0*/ activation_pipeline__DOT__s2_valid;
        CData/*7:0*/ activation_pipeline__DOT__ub_q_reg;
        CData/*0:0*/ activation_pipeline__DOT__valid_reg;
        CData/*0:0*/ activation_pipeline__DOT__act_u__DOT__clk;
        CData/*0:0*/ activation_pipeline__DOT__act_u__DOT__reset;
        CData/*0:0*/ activation_pipeline__DOT__act_u__DOT__valid_in;
        CData/*0:0*/ activation_pipeline__DOT__act_u__DOT__valid_out;
        CData/*0:0*/ activation_pipeline__DOT__norm_u__DOT__clk;
        CData/*0:0*/ activation_pipeline__DOT__norm_u__DOT__reset;
        CData/*0:0*/ activation_pipeline__DOT__norm_u__DOT__valid_in;
        CData/*4:0*/ activation_pipeline__DOT__norm_u__DOT__shift;
        CData/*0:0*/ activation_pipeline__DOT__norm_u__DOT__valid_out;
        CData/*0:0*/ activation_pipeline__DOT__loss_u__DOT__clk;
        CData/*0:0*/ activation_pipeline__DOT__loss_u__DOT__reset;
        CData/*0:0*/ activation_pipeline__DOT__loss_u__DOT__valid_in;
        CData/*0:0*/ activation_pipeline__DOT__loss_u__DOT__valid_out;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__reset__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__reset__0;
        VL_IN16(norm_gain,15,0);
        VL_IN16(q_inv_scale,15,0);
        SData/*15:0*/ activation_pipeline__DOT__norm_gain;
        SData/*15:0*/ activation_pipeline__DOT__q_inv_scale;
        SData/*15:0*/ activation_pipeline__DOT__norm_u__DOT__gain;
        VL_IN(acc_in,31,0);
        VL_IN(target_in,31,0);
        VL_IN(norm_bias,31,0);
        VL_OUT(loss_out,31,0);
        IData/*31:0*/ activation_pipeline__DOT__acc_in;
        IData/*31:0*/ activation_pipeline__DOT__target_in;
        IData/*31:0*/ activation_pipeline__DOT__norm_bias;
        IData/*31:0*/ activation_pipeline__DOT__loss_out;
        IData/*31:0*/ activation_pipeline__DOT__s1_data;
        IData/*31:0*/ activation_pipeline__DOT__target_d1;
        IData/*31:0*/ activation_pipeline__DOT__s2_data;
        IData/*31:0*/ activation_pipeline__DOT__scaled;
        IData/*31:0*/ activation_pipeline__DOT__biased;
        IData/*31:0*/ activation_pipeline__DOT__act_u__DOT__data_in;
        IData/*31:0*/ activation_pipeline__DOT__act_u__DOT__data_out;
        IData/*31:0*/ activation_pipeline__DOT__norm_u__DOT__data_in;
    };
    struct {
        IData/*31:0*/ activation_pipeline__DOT__norm_u__DOT__bias;
        IData/*31:0*/ activation_pipeline__DOT__norm_u__DOT__data_out;
        IData/*31:0*/ activation_pipeline__DOT__loss_u__DOT__data_in;
        IData/*31:0*/ activation_pipeline__DOT__loss_u__DOT__target_in;
        IData/*31:0*/ activation_pipeline__DOT__loss_u__DOT__loss_out;
        IData/*31:0*/ activation_pipeline__DOT__loss_u__DOT__diff;
        IData/*31:0*/ activation_pipeline__DOT__loss_u__DOT__abs_diff;
        IData/*31:0*/ __VactIterCount;
        QData/*47:0*/ activation_pipeline__DOT__mult;
        QData/*47:0*/ activation_pipeline__DOT__mult_rounded;
        QData/*47:0*/ activation_pipeline__DOT__norm_u__DOT__mult;
        QData/*47:0*/ activation_pipeline__DOT__norm_u__DOT__shifted;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*1:0*/ activation_pipeline__DOT__act_u__DOT__DEFAULT_ACT = 1U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
