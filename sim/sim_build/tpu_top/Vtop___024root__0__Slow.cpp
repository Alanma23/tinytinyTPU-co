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
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__bridge_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[0U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[1U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[2U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[3U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[0U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[1U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[2U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[3U] = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 = 0U;
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
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_gain = 0x0100U;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_bias = 0U;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_shift = 8U;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_q_inv_scale = 0x0100U;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_q_zero_point = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_in = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_in = 0U;
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/tpu_top.sv", 6, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tpu_top.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tpu_top.uart_ctrl_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tpu_top.uart_ctrl_u.uart_rx_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge tpu_top.uart_ctrl_u.uart_tx_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge tpu_top.bridge_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge tpu_top.mlp_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge tpu_top.mlp_u.weight_fifo_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge tpu_top.mlp_u.ub_a.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(posedge tpu_top.mlp_u.ub_b.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge tpu_top.mlp_u.mmu_u.pe00.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge tpu_top.mlp_u.mmu_u.pe01.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(posedge tpu_top.mlp_u.mmu_u.pe10.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(posedge tpu_top.mlp_u.mmu_u.pe11.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(posedge tpu_top.mlp_u.accum_u.u_align.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(posedge tpu_top.mlp_u.accum_u.u_mem.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(posedge tpu_top.mlp_u.ap_col0.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(posedge tpu_top.mlp_u.ap_col0.act_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(posedge tpu_top.mlp_u.ap_col0.norm_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @(posedge tpu_top.mlp_u.ap_col0.loss_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @(posedge tpu_top.mlp_u.ap_col1.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @(posedge tpu_top.mlp_u.ap_col1.act_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @(posedge tpu_top.mlp_u.ap_col1.norm_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @(posedge tpu_top.mlp_u.ap_col1.loss_u.clk)\n");
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
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2399467654730215438ull);
    vlSelf->uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1761512799854230840ull);
    vlSelf->mlp_state_dbg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9872132290368489356ull);
    vlSelf->mlp_cycle_cnt_dbg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17847700253694774769ull);
    vlSelf->mlp_layer_dbg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3816320034707777287ull);
    vlSelf->mlp_layer_complete_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5901823518494597646ull);
    vlSelf->mlp_acc0_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5784185532390468619ull);
    vlSelf->mlp_acc1_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12189994968941842941ull);
    vlSelf->mlp_acc_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14759784445797109915ull);
    vlSelf->uart_state_dbg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15770242556483566210ull);
    vlSelf->uart_cmd_dbg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17944616166956252236ull);
    vlSelf->uart_byte_count_dbg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17978845801927964702ull);
    vlSelf->uart_resp_idx_dbg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14920492027138284255ull);
    vlSelf->uart_tx_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 887436355691817143ull);
    vlSelf->uart_tx_ready_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17027424459054902983ull);
    vlSelf->uart_rx_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6953123713989331974ull);
    vlSelf->uart_rx_data_dbg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11466327522704066499ull);
    vlSelf->uart_weights_ready_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6853294186063696941ull);
    vlSelf->uart_start_mlp_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1939923427685624445ull);
    vlSelf->tpu_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1489916586434812643ull);
    vlSelf->tpu_top__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 686352068584437559ull);
    vlSelf->tpu_top__DOT__uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5425812304599224955ull);
    vlSelf->tpu_top__DOT__uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7538941756941849582ull);
    vlSelf->tpu_top__DOT__mlp_state_dbg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18387099072911302547ull);
    vlSelf->tpu_top__DOT__mlp_cycle_cnt_dbg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12359344805575503484ull);
    vlSelf->tpu_top__DOT__mlp_layer_dbg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7239788530276058499ull);
    vlSelf->tpu_top__DOT__mlp_layer_complete_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1828675003082906930ull);
    vlSelf->tpu_top__DOT__mlp_acc0_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6683874401508667990ull);
    vlSelf->tpu_top__DOT__mlp_acc1_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5844793363421532214ull);
    vlSelf->tpu_top__DOT__mlp_acc_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4301789342293479877ull);
    vlSelf->tpu_top__DOT__uart_state_dbg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4752530826392551293ull);
    vlSelf->tpu_top__DOT__uart_cmd_dbg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14066229919632187603ull);
    vlSelf->tpu_top__DOT__uart_byte_count_dbg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2075552134045341064ull);
    vlSelf->tpu_top__DOT__uart_resp_idx_dbg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5891399664833244332ull);
    vlSelf->tpu_top__DOT__uart_tx_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17834980493890301241ull);
    vlSelf->tpu_top__DOT__uart_tx_ready_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16601291912897158020ull);
    vlSelf->tpu_top__DOT__uart_rx_valid_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9175920705101318847ull);
    vlSelf->tpu_top__DOT__uart_rx_data_dbg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3181485705869122842ull);
    vlSelf->tpu_top__DOT__uart_weights_ready_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4879454649293816003ull);
    vlSelf->tpu_top__DOT__uart_start_mlp_dbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1754341444625775583ull);
    vlSelf->tpu_top__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 757050434793971890ull);
    vlSelf->tpu_top__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12349108518689760008ull);
    vlSelf->tpu_top__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16700760870366213715ull);
    vlSelf->tpu_top__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5434486735167745258ull);
    vlSelf->tpu_top__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18398130086736431102ull);
    vlSelf->tpu_top__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14549949747631969185ull);
    vlSelf->tpu_top__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3300987225393639080ull);
    vlSelf->tpu_top__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1799758645507814611ull);
    vlSelf->tpu_top__DOT__mlp_state_ctrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16944844911500858062ull);
    vlSelf->tpu_top__DOT__mlp_cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5223296096973418477ull);
    vlSelf->tpu_top__DOT__mlp_acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10803118481017131946ull);
    vlSelf->tpu_top__DOT__uart_state_int = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1002085839570355430ull);
    vlSelf->tpu_top__DOT__uart_cmd_int = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7568192193630691844ull);
    vlSelf->tpu_top__DOT__uart_byte_cnt_int = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12923140808789188825ull);
    vlSelf->tpu_top__DOT__uart_resp_idx_int = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13909399814888133181ull);
    vlSelf->tpu_top__DOT__uart_tx_valid_int = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1482661956102739222ull);
    vlSelf->tpu_top__DOT__uart_tx_ready_int = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5104325400324978157ull);
    vlSelf->tpu_top__DOT__uart_rx_valid_int = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2163501181987997991ull);
    vlSelf->tpu_top__DOT__uart_rx_data_int = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9610291482074523992ull);
    vlSelf->tpu_top__DOT__uart_weights_ready_int = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 516795647746531129ull);
    vlSelf->tpu_top__DOT__uart_start_mlp_int = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 664239948844865764ull);
    vlSelf->tpu_top__DOT__mlp_wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10765872013531319987ull);
    vlSelf->tpu_top__DOT__mlp_wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6392416172910022539ull);
    vlSelf->tpu_top__DOT__mlp_wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9909127114444942491ull);
    vlSelf->tpu_top__DOT__mlp_wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12064836406897747344ull);
    vlSelf->tpu_top__DOT__mlp_init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11772485175293552827ull);
    vlSelf->tpu_top__DOT__mlp_init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4903205050854821575ull);
    vlSelf->tpu_top__DOT__mlp_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2089254106890815171ull);
    vlSelf->tpu_top__DOT__mlp_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4356961218133699117ull);
    vlSelf->tpu_top__DOT__mlp_norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13074450131459415440ull);
    vlSelf->tpu_top__DOT__mlp_norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15112960802060346856ull);
    vlSelf->tpu_top__DOT__mlp_norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7426150281551833020ull);
    vlSelf->tpu_top__DOT__mlp_q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9843979211336344085ull);
    vlSelf->tpu_top__DOT__mlp_q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17546780937317877625ull);
    vlSelf->tpu_top__DOT__mlp_state_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9900534524399771824ull);
    vlSelf->tpu_top__DOT__mlp_cycle_cnt_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8367552232978069005ull);
    vlSelf->tpu_top__DOT__mlp_current_layer_out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8506474420510550055ull);
    vlSelf->tpu_top__DOT__mlp_layer_complete_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9126546494942753162ull);
    vlSelf->tpu_top__DOT__mlp_acc0_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7424131280505902156ull);
    vlSelf->tpu_top__DOT__mlp_acc1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9274200432945477391ull);
    vlSelf->tpu_top__DOT__mlp_acc_valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4212452545028155125ull);
    vlSelf->tpu_top__DOT__mlp_state_out_prev = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15511075050041547122ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13403750012702365789ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5602986250662639020ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15171533154888514151ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 742618652219737261ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5350457826874865941ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5653136296803640521ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1600801968533358641ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3489175738905195650ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8379711551148473098ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14443689540681249560ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 349811904310014691ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10462555223740165016ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__mlp_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11267673616107436408ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12644810420535235496ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6552787705988342839ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7555347197016266283ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_cmd_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14784438065788532790ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6063674469044598601ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_resp_byte_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1876351121274881820ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11653732004702929888ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11121870909016534395ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4494344880469176739ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 850442269947081065ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9860306294092922625ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__dbg_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12657748547446466362ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5889448610999103237ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17732892812341802656ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12525389585551053227ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15638753406017645913ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15841510761403606188ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18134020193863543522ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16320195863540177877ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18123064416418439483ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15191949208091188352ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__data_buffer[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3222434038113498904ull);
    }
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4076445337819895651ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9609320683371910889ull);
    }
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2915431297930616938ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5861720073517569824ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17882505436040957226ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13354802172738134699ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4093297148243410500ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15105499195612569780ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14094348665689967664ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16308974865602172729ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14141850595038187079ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8296539011237203077ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14633024845857841791ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9400560479440915792ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15192400875934918563ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14076862977305668946ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__tx_data_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18278044846076371430ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 608252201375146913ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__rx_data_captured = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17907337709695447165ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13399931875220347492ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8693502752964006168ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17744609285452074824ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7829702266252902254ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18157155565597662951ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4339564236381395299ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6543377842914756657ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5561282407375970659ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8620589526891895242ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11424726293415996802ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8967962442263096995ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1607165025617430843ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10914575277137627791ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9731405294374987184ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12488405794635577518ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16011466164960160897ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18303824676799645800ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15137840272027617420ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1486767158499746911ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17765445738157700701ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14915222359906986254ull);
    vlSelf->tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18041108173567524005ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11697935642183468992ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5888617658569409534ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15235031345515735505ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1843493401618144954ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17068724480913895595ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8855273824447496407ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10321920936475260279ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8199042078307121915ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__ctrl_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15182062534066519271ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5926180431061781175ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11098904945627235407ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14938035309490284814ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9724913430120083072ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15914489851584338295ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13950370281315940078ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1226917940388830106ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10026317035267583338ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16330866426079120162ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16626362999457905853ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9409802376826246555ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9885432111063526162ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11492024584551909964ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4219929286676582804ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3341929146212132377ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4555412332732797187ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_state_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5053565076493604908ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt_in = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1322330517475489240ull);
    vlSelf->tpu_top__DOT__bridge_u__DOT__mlp_acc0_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18234336025848895848ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2992669801848389169ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17667887313982704815ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14000138701858510769ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15230707382563558620ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13552117199074940939ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4132252121875591818ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14566506948540848469ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10936649058794603615ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1797416123747297366ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1714621509866687509ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 336088402056706644ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1921617578058289745ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10572782583158217821ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7459091506716792578ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15584433287770511381ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 295308016544408927ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11461360424317221253ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__current_layer = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17469405716830944568ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__layer_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15640784679546680832ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9533286372833292601ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16254987209980740604ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11064840739374496188ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14263963092157143300ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__acc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 964408983737146129ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__state_reg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14023128435506611420ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1963048110534782469ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__current_layer_reg = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5897879135610330772ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__buffer_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11838650416524023931ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weights_loaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10173226099949054193ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__en_load_weight = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5296481974036678938ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__compute_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14385259679689214243ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__drain_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14932766171796225453ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__transfer_phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3474667766601195740ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_col0_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6180827767961888203ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_col1_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15521014428465592061ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__wf_col1_raw = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5303548640473308535ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7357696394704285140ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2054080379569189796ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 686769280840089133ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16220604809139528152ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5022864819189279387ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13869647250327095822ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9007198654287468208ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13838129797837310864ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7602194107568379995ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13989479655547073860ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5729590441854305990ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15887073493781514401ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1225651378620326968ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7562574370531225721ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10614871477417566544ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__act_ub_rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2998088691300704196ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__act_ub_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16318338390998691230ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__act_row0_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5702449834825914225ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__act_row1_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16565077562196880065ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__row1_skew_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6872669570698719920ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1678864167434508666ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5382096037950650407ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10431634005952578129ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1503461743791709595ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15294759978489952784ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1071193480478892516ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14517880116941639642ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3831710215888576763ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2011018346367406512ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__acc_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15341558580766826541ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__acc_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4046323945729519573ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15728191029353251971ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_data_col0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 280369031182594289ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_data_col1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10743229520172924709ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__refill_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8375095180402379167ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__refill_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8796717159649477434ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__state_reg_prev = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3580594008666849092ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2316568352361606788ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12960310104547969629ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18112951240932964927ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7869960155231994506ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7289646413506330389ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1713576674049564379ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6570592065149407382ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col0_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7278215857837771852ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9430285254625832334ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_raw = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8743708802142664403ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12208525996763234437ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5734298025222397554ull);
    }
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14124883297952478329ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 596171825181779627ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16040439353274784345ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8416411053696936559ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16640434123417233771ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9480130282564601090ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6163151281023261125ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 832719983122433024ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2136145546644340309ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15718360217904305116ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5585438930628555123ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10970703076045524325ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1650437684847535039ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6026421214837111350ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14034924344881298828ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 657921400642214690ull);
    }
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17270916897974726562ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9822902787750449401ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_comb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2071034328270288745ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10812653610083756053ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16565547831120437016ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17757657429483761490ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3085752193560066084ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4851597782217569168ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2230338109087658556ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1752178548406884605ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13262113020315372413ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11416759683083835874ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9224180360606192593ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3190345755336432219ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2969085522497705803ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17081217378045323745ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15154031883666741306ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7814386473584489050ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2241794721410044305ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14840056079874412897ull);
    }
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7117348513996293065ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6653814889187442116ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_comb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7670917037175129936ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8553982991422357738ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15838720414132177076ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4865029025034235935ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5592970994699237244ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11043103536865278434ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13486351338697708618ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11572977956270322503ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11453557141227321673ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3474102670655337326ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1637495169208504146ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2342831637350976692ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17037265917086391767ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3715522040900809161ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 604148490188644887ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5174790503231059094ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16807367344226454109ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_01_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5894720657562459326ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10_11_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12054918981636238311ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_10_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17861787484045236037ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01_11_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6593369252537489628ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13291306285527988808ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13159741028777556207ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8969385448043409075ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18439861377587387203ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8988413300539262797ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3090716862883468089ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15621662836161700124ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11084330130762214436ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4072915326092991127ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2643941034076639453ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9970693591621062951ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15773077382153564885ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7505972773408227458ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2162620179256050230ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11084320458097528100ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10469385512448174121ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4465697283675198331ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9829559037686420161ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4466345686266888236ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9544387838919626474ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10702317114675093188ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2112791118281924479ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4636117174977971861ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 418015287729661825ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14989753856956812166ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3810041512380803078ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10011450332621313006ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8237385556251051953ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9538224155397910914ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1243332890130439081ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18252432723546031168ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17409858526969823181ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9518351408250940648ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7457316892309560546ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15698074720093598620ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14528956297342628157ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15142751111004079654ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4988743986646564032ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7165877667282702070ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__accumulator_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15742305539707497465ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1653485316064341504ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col0_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8322305928528071282ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col1_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16039206613835324490ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col0_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7142207059544510296ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3257033904265280484ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4695501532192134172ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15590214281476744305ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5367957746537403021ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2964917655256250918ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7682905500827536549ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11680502858592918831ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1422405775554952548ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4511181806387372879ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4838797897815260830ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17165142104370344148ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1407743165981783674ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5590691214745474357ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15576423165042543176ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12025523326449298452ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13814498613528535121ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11757414078930869845ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6689410351171919249ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1424548882195637640ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4996212620704935299ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7291691972272102982ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8769921210081986552ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12327546060840260676ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3524025918512505020ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14445444575986008234ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5659024829312442761ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11364356435511708279ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11826699212250479846ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2747099210011164157ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6353732024144575600ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3205831096286165622ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1907611615236642026ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1046303784178011172ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1720163026975236729ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5361631595853841491ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10920662093530838837ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4744840455654804492ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6797381970001680058ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2598694870573088475ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15584425644884037745ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10895549837823838036ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7219972060268683231ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17022546322879641489ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7900640849743665929ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16849042200938024730ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17667819837260147513ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135497461014848206ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18285804815586958657ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_q_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 192090968046114890ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10434443901424533663ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16662447650384477597ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 335641420169711280ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale_d0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17839453416919580928ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1938125558744705150ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9047804929297289428ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9389665232439801140ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_reg = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3770565043445980852ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9662433032786701765ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5195099380686180607ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__scaled_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3488805021929389346ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2884984397851653397ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s4_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16354305358889309363ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__biased_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13171195130948886049ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__unnamedblk1__DOT__mult_rounded = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11914335104965077114ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10216065783445131997ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6111984820484817497ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 65871845907045724ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15420788224612404913ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8679721875470654540ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3417766571081197869ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14811875008592197338ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13740436711938000174ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11877620256911135009ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13806644687935506897ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6387643853240488626ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16446982721770676178ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14716103266356514026ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5721521955280278348ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16956238665319017184ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17312377000345031649ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6313366351367944162ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain_d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13815576169501151236ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17736740990842967499ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8199409668007077028ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2612159181438386068ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15126720764916372573ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3568910198281808848ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12787179463241187917ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2551228576813614038ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7875271735535898968ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shifted_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3735378740482404718ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12095143484888908298ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17550682396110157825ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4288053860813374945ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14189883904440837284ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14720976588687849265ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8893344771113804319ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1912477221762306064ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4693372675801106902ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15235445016617200515ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__abs_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13085203853519064751ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7176155407824508271ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13690432709010651500ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16907792727009577271ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__acc_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 164782105313410960ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10991967950047620113ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16267267657968016948ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15680216138237713656ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4685668478184183761ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8191442956575531724ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7781757723223185325ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3598348112805546329ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6759830973633618043ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16502333002142641527ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18358882389652990014ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12455326332469459030ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7499262540814344768ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7394339190905514681ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12532479669187301824ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6821075412669317442ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_q_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15500996404469092293ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 328412378197664949ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17779496825821042673ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2920014142067738317ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale_d0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6199665608693692464ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10017318100426677072ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14426740905884276541ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10329134892692619853ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_reg = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11639243828821521788ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1266721600049310885ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9819735697792069172ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__scaled_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18134493127654090409ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11652683953427621916ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s4_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16264203228717277090ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__biased_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7903737672408331029ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__unnamedblk1__DOT__mult_rounded = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15643977455991385716ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3307363376523341719ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2552835372885180062ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9886471380726985747ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10367943464037041884ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13739744855061793343ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5836313800923819821ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4266792432699169539ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11416175142893183913ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7272576372937116362ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18294687794199105470ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8927160916777620841ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3744419627782372756ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4914712016064205582ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1727734859055104375ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4037768704200622436ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16301222389019173897ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2748988565204318665ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain_d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17530616318136393775ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18360918693660785830ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6398189065538623382ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15673827497344223220ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_raw = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8870258899811031249ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2965422175747396176ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1392225654411129195ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13893368803124097944ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s3_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6772017778695529270ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shifted_res = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 900041059766380061ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11054675011191450342ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4235442116150351264ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14981979666799104692ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17006274050273536754ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5451019357273663956ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__target_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12839703441680706901ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10143190292588700179ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__loss_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6870390492641532352ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6846488797434752610ull);
    vlSelf->tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__abs_diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6889809138668790615ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11305301593595015112ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9483224249351564831ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 716520874493381189ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11008039217362695386ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__bridge_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16451870169202471187ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11841874773551672493ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10253914984088046373ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 232898200339173978ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2993409706946651593ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4083874938698377345ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16496779857494330523ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6539803790242561042ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9923114658482381321ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17191774022501562171ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4419627554675459730ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 42214472943595536ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7503131566882234565ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18232458083114376205ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6449030204191414068ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12414258472564422159ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7778169326540428026ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6326678783462440575ull);
    vlSelf->__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7065205083895149386ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
