// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__clk__0 
        = vlSelfRef.activation_pipeline__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__reset__0 
        = vlSelfRef.activation_pipeline__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__clk__0 
        = vlSelfRef.activation_pipeline__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__reset__0 
        = vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__reset__0 
        = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__reset__0 
        = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/activation_pipeline.sv", 4, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge activation_pipeline.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge activation_pipeline.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge activation_pipeline.act_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge activation_pipeline.act_u.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge activation_pipeline.norm_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge activation_pipeline.norm_u.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge activation_pipeline.loss_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge activation_pipeline.loss_u.reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16540271516330450727ull);
    vlSelf->acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3264398903847737890ull);
    vlSelf->target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9374851311603364689ull);
    vlSelf->norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17536678267404299644ull);
    vlSelf->norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11964020053892010726ull);
    vlSelf->norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2359762326573903141ull);
    vlSelf->q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18256418270766509563ull);
    vlSelf->q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8991204500324134713ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9300762645159780298ull);
    vlSelf->loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8132995893749413635ull);
    vlSelf->loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7671170765256168753ull);
    vlSelf->activation_pipeline__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3002205482624638985ull);
    vlSelf->activation_pipeline__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9290747707346890268ull);
    vlSelf->activation_pipeline__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17769562320494049993ull);
    vlSelf->activation_pipeline__DOT__acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 995751062510360675ull);
    vlSelf->activation_pipeline__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7225748160833938635ull);
    vlSelf->activation_pipeline__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7226158484147423359ull);
    vlSelf->activation_pipeline__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12101564981417362678ull);
    vlSelf->activation_pipeline__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9742275911697566217ull);
    vlSelf->activation_pipeline__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8854343487347308365ull);
    vlSelf->activation_pipeline__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 696602668138169928ull);
    vlSelf->activation_pipeline__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17797885547833619326ull);
    vlSelf->activation_pipeline__DOT__ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2002476677853989381ull);
    vlSelf->activation_pipeline__DOT__loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2877025091009752352ull);
    vlSelf->activation_pipeline__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9525401862665375949ull);
    vlSelf->activation_pipeline__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13434073947816769988ull);
    vlSelf->activation_pipeline__DOT__s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1902667299657436114ull);
    vlSelf->activation_pipeline__DOT__target_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12692348366666012858ull);
    vlSelf->activation_pipeline__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11929767659643001128ull);
    vlSelf->activation_pipeline__DOT__s2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16253496412960176984ull);
    vlSelf->activation_pipeline__DOT__ub_q_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3208802694976884708ull);
    vlSelf->activation_pipeline__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9679916056815886194ull);
    vlSelf->activation_pipeline__DOT__mult = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13667759529885576681ull);
    vlSelf->activation_pipeline__DOT__mult_rounded = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10543586219224754411ull);
    vlSelf->activation_pipeline__DOT__scaled = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10035443311920236459ull);
    vlSelf->activation_pipeline__DOT__biased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5855458399056064346ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12725810827456036976ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17368273703226644193ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11849674422521061830ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12750933662342309202ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3291427339169133731ull);
    vlSelf->activation_pipeline__DOT__act_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6773182667446443860ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17850662362252265627ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10838112885771723098ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1580720560655629749ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1426570185971037360ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15716743634935667838ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6216754249544003176ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3739111404101128535ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1026760994556804250ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 836783403018737267ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__mult = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5873158818425739244ull);
    vlSelf->activation_pipeline__DOT__norm_u__DOT__shifted = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2356450054210482813ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12274075388771942158ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5520492158856831699ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12655654977599143225ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9758417967234101853ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1981005856928222427ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11982479483462974646ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10354708590164183151ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14159902334601614332ull);
    vlSelf->activation_pipeline__DOT__loss_u__DOT__abs_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1960105518226274041ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18010949571667271902ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 310994138175561412ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17627486778519425611ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17513301455126519751ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3097265990183091034ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7888201791701699197ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4097249320903990ull);
    vlSelf->__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 488697375214914007ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
