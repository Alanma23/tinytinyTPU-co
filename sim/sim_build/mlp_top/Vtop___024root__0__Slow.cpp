// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ub_a__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ub_b__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[0U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[1U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[2U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[3U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[0U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[1U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[2U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[3U] = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 = 0U;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_in = 0U;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_in = 0U;
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/mlp_top.sv", 8, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge mlp_top.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge mlp_top.weight_fifo_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge mlp_top.ub_a.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge mlp_top.ub_b.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge mlp_top.mmu_u.pe00.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge mlp_top.mmu_u.pe01.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge mlp_top.mmu_u.pe10.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge mlp_top.mmu_u.pe11.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(posedge mlp_top.accum_u.u_align.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge mlp_top.accum_u.u_mem.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge mlp_top.ap_col0.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(posedge mlp_top.ap_col0.act_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(posedge mlp_top.ap_col0.norm_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(posedge mlp_top.ap_col0.loss_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(posedge mlp_top.ap_col1.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(posedge mlp_top.ap_col1.act_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(posedge mlp_top.ap_col1.norm_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(posedge mlp_top.ap_col1.loss_u.clk)\n");
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
    vlSelf->wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17607047225282717665ull);
    vlSelf->wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15413999677017281515ull);
    vlSelf->wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6655838028478558514ull);
    vlSelf->wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 756852297801786066ull);
    vlSelf->init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9207923663655795732ull);
    vlSelf->init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1919708525650195647ull);
    vlSelf->start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15041482429981211798ull);
    vlSelf->weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13129243201023795017ull);
    vlSelf->norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17536678267404299644ull);
    vlSelf->norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11964020053892010726ull);
    vlSelf->norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2359762326573903141ull);
    vlSelf->q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18256418270766509563ull);
    vlSelf->q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8991204500324134713ull);
    vlSelf->state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9404372463396948974ull);
    vlSelf->cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10774249576030602819ull);
    vlSelf->current_layer = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6744363607239060385ull);
    vlSelf->layer_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14006444394765142208ull);
    vlSelf->mmu_acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 412741172035679630ull);
    vlSelf->mmu_acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11843425132479340909ull);
    vlSelf->acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10812525088362516050ull);
    vlSelf->acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6014634557126852305ull);
    vlSelf->acc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5460124159129922568ull);
    vlSelf->mlp_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14532268046291173616ull);
    vlSelf->mlp_top__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12390913095155513288ull);
    vlSelf->mlp_top__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7924469011506712572ull);
    vlSelf->mlp_top__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 315247536001741897ull);
    vlSelf->mlp_top__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10657109071709591237ull);
    vlSelf->mlp_top__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15924187790806198420ull);
    vlSelf->mlp_top__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15370574681735244691ull);
    vlSelf->mlp_top__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15938844652964583449ull);
    vlSelf->mlp_top__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4815712729974842361ull);
    vlSelf->mlp_top__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11278287463573090655ull);
    vlSelf->mlp_top__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14190322609953172438ull);
    vlSelf->mlp_top__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 43604326993546976ull);
    vlSelf->mlp_top__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2634990624807934682ull);
    vlSelf->mlp_top__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18313335191289153108ull);
    vlSelf->mlp_top__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6395182775513404199ull);
    vlSelf->mlp_top__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14147032800749088138ull);
    vlSelf->mlp_top__DOT__cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13368784781868892720ull);
    vlSelf->mlp_top__DOT__current_layer = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7952765746443977270ull);
    vlSelf->mlp_top__DOT__layer_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1578732617973602634ull);
    vlSelf->mlp_top__DOT__mmu_acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7831629885613212317ull);
    vlSelf->mlp_top__DOT__mmu_acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11786227423724726893ull);
    vlSelf->mlp_top__DOT__acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16300365533434352990ull);
    vlSelf->mlp_top__DOT__acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2591116582311285308ull);
    vlSelf->mlp_top__DOT__acc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11699252726908761697ull);
    vlSelf->mlp_top__DOT__state_reg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11033954398887573442ull);
    vlSelf->mlp_top__DOT__cycle_cnt_reg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4240702225592984095ull);
    vlSelf->mlp_top__DOT__current_layer_reg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7661877989440966356ull);
    vlSelf->mlp_top__DOT__buffer_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11696048623209240397ull);
    vlSelf->mlp_top__DOT__weights_loaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10437039605220380548ull);
    vlSelf->mlp_top__DOT__en_load_weight = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3861992665705789720ull);
    vlSelf->mlp_top__DOT__compute_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12066029459983372688ull);
    vlSelf->mlp_top__DOT__drain_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6836937825970717101ull);
    vlSelf->mlp_top__DOT__transfer_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5133907478692825734ull);
    vlSelf->mlp_top__DOT__wf_col0_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11183278943266656265ull);
    vlSelf->mlp_top__DOT__wf_col1_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11689686539060344177ull);
    vlSelf->mlp_top__DOT__wf_col1_raw = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15279444472535107772ull);
    vlSelf->mlp_top__DOT__ub_a_wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5235533032486962715ull);
    vlSelf->mlp_top__DOT__ub_a_rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11954790156231119814ull);
    vlSelf->mlp_top__DOT__ub_a_wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5699785803931978684ull);
    vlSelf->mlp_top__DOT__ub_a_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6151434607192833322ull);
    vlSelf->mlp_top__DOT__ub_a_wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 732466326578360588ull);
    vlSelf->mlp_top__DOT__ub_a_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14725514605102829615ull);
    vlSelf->mlp_top__DOT__ub_a_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5616789533610113187ull);
    vlSelf->mlp_top__DOT__ub_b_wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17978374721113647504ull);
    vlSelf->mlp_top__DOT__ub_b_rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13584659147258757825ull);
    vlSelf->mlp_top__DOT__ub_b_wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6201351056648180146ull);
    vlSelf->mlp_top__DOT__ub_b_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7242435026094776489ull);
    vlSelf->mlp_top__DOT__ub_b_wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15928541401285244365ull);
    vlSelf->mlp_top__DOT__ub_b_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7846166123277481832ull);
    vlSelf->mlp_top__DOT__ub_b_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3573787167436941590ull);
    vlSelf->mlp_top__DOT__act_ub_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7577389541510209477ull);
    vlSelf->mlp_top__DOT__act_ub_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9605786334484852520ull);
    vlSelf->mlp_top__DOT__act_ub_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6527517503273314592ull);
    vlSelf->mlp_top__DOT__act_row0_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 154739869468050555ull);
    vlSelf->mlp_top__DOT__act_row1_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17321427623407236513ull);
    vlSelf->mlp_top__DOT__row1_skew_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1851240833743244406ull);
    vlSelf->mlp_top__DOT__mmu_row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12925628884078293302ull);
    vlSelf->mlp_top__DOT__mmu_row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16355404380868523412ull);
    vlSelf->mlp_top__DOT__mmu_col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10497458433226154065ull);
    vlSelf->mlp_top__DOT__mmu_col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16428540796949473386ull);
    vlSelf->mlp_top__DOT__en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17814199981500847681ull);
    vlSelf->mlp_top__DOT__en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14839931658564849542ull);
    vlSelf->mlp_top__DOT__accum_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13866526319030553239ull);
    vlSelf->mlp_top__DOT__addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 757845134452612698ull);
    vlSelf->mlp_top__DOT__mmu_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2610560827230840948ull);
    vlSelf->mlp_top__DOT__acc_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2144691934855291030ull);
    vlSelf->mlp_top__DOT__acc_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13370580958896100110ull);
    vlSelf->mlp_top__DOT__ap_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3641899763930940241ull);
    vlSelf->mlp_top__DOT__ap_data_col0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 137997486721224498ull);
    vlSelf->mlp_top__DOT__ap_data_col1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6261474110325985956ull);
    vlSelf->mlp_top__DOT__refill_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11266061294509387905ull);
    vlSelf->mlp_top__DOT__refill_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4411280026472795107ull);
    vlSelf->mlp_top__DOT__state_reg_prev = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7139565482280347209ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13143981681280448406ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8522875781428791957ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 503408139929449204ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16517780353377822759ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3839690525851911760ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7309486674323842737ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__col0_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15151848829821825919ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__col1_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7603722943718507397ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__col1_raw = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8314209286094285202ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mlp_top__DOT__weight_fifo_u__DOT__queue0[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18177715039698269094ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mlp_top__DOT__weight_fifo_u__DOT__queue1[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11863017172807685925ull);
    }
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8209828196032726745ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5344731849567331391ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15505007624514182690ull);
    vlSelf->mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4449266639983637582ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3673960540187483105ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13057072447729351428ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6964799909144672278ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6094014186914927969ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2123595318911485577ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16607367306441663774ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5936573953694481182ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2175561985020431202ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15234136096616053983ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9989274188397869797ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9954117445973048081ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->mlp_top__DOT__ub_a__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17399880433473790563ull);
    }
    vlSelf->mlp_top__DOT__ub_a__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11309597499840063836ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16766022707837921496ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_data_comb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 210742566379279408ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_valid_comb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2562859035891983469ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13991323993637497448ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__rd_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 694975912742016329ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9788536197825950412ull);
    vlSelf->mlp_top__DOT__ub_a__DOT__do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17133622909199851924ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3592601097847345148ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13572792259475031012ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11004462907271423686ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7706512539298677775ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1632866952408173133ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3717239681726399040ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4890782185778845068ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11920123756849770407ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13660926848345165278ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2336806699180990621ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1954404066082187359ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->mlp_top__DOT__ub_b__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11718221154790314117ull);
    }
    vlSelf->mlp_top__DOT__ub_b__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11991213505897784376ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13955642201989382571ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_data_comb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4386827901829336824ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_valid_comb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15757175937119070038ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11599626543199788764ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__rd_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3102502686540005156ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5204892958612665722ull);
    vlSelf->mlp_top__DOT__ub_b__DOT__do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12222854263267427162ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1809734501306039888ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5117097619241181331ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5397247708021618367ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16982352418976038583ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7046001867001618414ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8582457534687794067ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1080746467397110783ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16460636490361863931ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2111593256911287663ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11646007300056754779ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16820588421890091958ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00_01_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12418551852449919760ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10_11_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10496797249044306791ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00_10_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1237280598953095322ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01_11_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15681066494797892851ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17554917177797162085ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11372800237774656622ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16442393711968602255ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12999883330684541545ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12518435313367108907ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1292103737442900062ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5191158314792842388ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11434990073229823771ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe00__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5953149416243728400ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16304346374601478684ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5828341758793604828ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17447313641218470222ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7878619263757954339ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10264362158107686403ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2431201009569277983ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15560841509044264227ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17864415803928811863ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe01__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1842492332101559426ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17313969967006375042ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6700348226516181567ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1648388151392993869ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8426745677683730773ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17370498600701699821ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4266270223639805036ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 949450036958499978ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6833724732554616772ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe10__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15546256061188486886ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18085880872076043509ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12165584142884090877ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7161838213884947132ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13761780635363643634ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3735136414529793321ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4221025585451028515ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 920174906093952673ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14375120227247388748ull);
    vlSelf->mlp_top__DOT__mmu_u__DOT__pe11__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17383936386772166503ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11182963551372506473ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4867447646513814298ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8817829865889590813ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__accumulator_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14019825237293866512ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8244251929474130510ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__mmu_col0_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17860467412556654617ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__mmu_col1_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2820352745080052171ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__acc_col0_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17195691259369974963ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__acc_col1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13250287814477215534ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5533371000681294785ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11956824970415676655ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__aligned_c0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4829780489997643654ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__aligned_c1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1723410340665224681ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14194125708435050588ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11645925133614564747ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2561677322687516946ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8413910189529415656ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 854108672756590980ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16657769050845102192ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14059566494566768588ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14591543320540585261ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4069249105029505674ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_align__DOT__pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7374031040509408579ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4643478836997925507ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2464278463101134603ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14821752298426943088ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11395713895852109279ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12636048061737354664ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2159743025003916623ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14440695093599058821ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3314683222470823585ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16785759382780873913ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12930055819809862604ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1895699058865638424ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12368659011691445585ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5456125813314283167ull);
    vlSelf->mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 665268703553151648ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14578597722213194304ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14304584234267903414ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6264865996611741478ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11868934017531331496ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12193449711679663407ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8170848674219254433ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11835745586069416636ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13962454103723899570ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16188381979645677957ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3311874938814774322ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18312731030053019034ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10031703332876884475ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10975410605849869840ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17782677397976276285ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6281347689338409035ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2384557277741523671ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__target_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5952382874321896270ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4097587979332454547ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__s2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5085816193249951285ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__ub_q_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4390114708389521893ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2231820053317711311ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6323768481782412957ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6411483311397559214ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_inv_scale_d0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4175827082374854302ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_zero_point_d0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16005883889242155638ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14530224303229275197ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2659439568885129357ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__mult_reg = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 7979459680073547125ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_zero_point_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 31330389729230942ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5591120688196976841ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__scaled_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1293380600436974666ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_zero_point_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1418173010853485550ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__q_s4_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8550841840631942678ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__biased_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17643826227882673811ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__unnamedblk1__DOT__mult_rounded = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6574500529746149864ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16466779535889417439ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5185151251808845701ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14150429848833191496ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7677067465353223064ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18237544366436273383ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16049732043455425042ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15904438032051788969ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6530060992843783317ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9118258802295397162ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6854809564462861305ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12865763647017985089ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2137796688837933456ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10071844038836906316ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7247298395126412235ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13528795851737997142ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7341284335828436558ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9717488953350908378ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__gain_d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4389575821442596964ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6065425963369298571ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6846452249102553892ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9747374478898017451ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2088829647818036035ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17033587894594352182ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7577133180167591550ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift_d1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13685418604004652776ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13662003500429555845ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shifted_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10247659937262111315ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16078114691559351212ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10975875471673742696ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 127591992040250188ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8336840423352086387ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1536832343128279289ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4171521562445873891ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13894738096390802065ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15403768900157651828ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4961632729229241360ull);
    vlSelf->mlp_top__DOT__ap_col0__DOT__loss_u__DOT__abs_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16000670156535742527ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14553943560574570502ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9129960906124816578ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3429280118688676454ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17995466390786435740ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1791740333903411098ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3313841753317511011ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13485120259315370522ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17616149459938142529ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1816649486478987110ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10503563480169794906ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12381444633691019987ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3783505749084359865ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16952886535800052754ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4268310050028801038ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1875906856308168933ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12912917796843890066ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__target_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5474079613024428473ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3026827234671688440ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__s2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11753204948520370738ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__ub_q_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5656851435358950203ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17859162782432723205ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8151652475367493132ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15013113258762107006ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_inv_scale_d0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12625317426413762460ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_zero_point_d0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14452844453063965136ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16612324955019654246ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12986773427192327434ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__mult_reg = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11673821243043245164ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_zero_point_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4923515890874338596ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18283586456084155830ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__scaled_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8698475895984076881ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_zero_point_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1263943201664808197ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__q_s4_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18375449220215767190ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__biased_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13030933383157537746ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__unnamedblk1__DOT__mult_rounded = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2878403915782100732ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1689705975516102754ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18172440685801472447ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12953195022918798058ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13988840941536818362ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6808395815555969928ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1221536347320082156ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5367539831590312530ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2096246811794932271ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4091086467851560037ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17208500969098441206ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1256346354687710163ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11509072477224743681ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 144746814128200443ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18272391117833775829ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11972913972951828681ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 997761272077384607ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14004716603421532764ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__gain_d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6834589443684173366ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14772186359994793816ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9736856037052053413ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10311362019117359891ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 100991985856167812ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 18173759296191726268ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13775564536445157547ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift_d1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13604380806891489190ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16086511700089135402ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shifted_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1488252089678840060ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11479606873856120596ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6020911422439003629ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14447825958430722737ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3085623437984052635ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11983484417923722432ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1436356527467517424ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6542544779079930408ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11300783165288525308ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3386690984673617069ull);
    vlSelf->mlp_top__DOT__ap_col1__DOT__loss_u__DOT__abs_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17275895767540774216ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2098107214794044271ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5687399318711306719ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10695207319161536720ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10490673238960529959ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14046027661869914925ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1081346418216099098ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4301160257647799552ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14474202668489204199ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 700405318819209118ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15095017788637371106ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9696026526403313127ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18206540410336046218ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9485472323833773736ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5240988719917772922ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10014928118621450411ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6214104352946895469ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5810476415394236212ull);
    vlSelf->__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1717646690400839818ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
