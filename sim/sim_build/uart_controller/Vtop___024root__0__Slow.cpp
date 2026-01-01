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
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__start_mlp_sticky = 0U;
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
            VL_FATAL_MT("/Users/abiralshakya/Documents/tpu_to_fpga_rev2/tinytinyTPU-co/rtl/uart_controller.sv", 6, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge uart_controller.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge uart_controller.uart_rx_u.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge uart_controller.uart_tx_u.clk)\n");
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
    vlSelf->wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17607047225282717665ull);
    vlSelf->wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15413999677017281515ull);
    vlSelf->wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6655838028478558514ull);
    vlSelf->wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 756852297801786066ull);
    vlSelf->init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9207923663655795732ull);
    vlSelf->init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1919708525650195647ull);
    vlSelf->start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15041482429981211798ull);
    vlSelf->weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13129243201023795017ull);
    vlSelf->mlp_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8692831943072095065ull);
    vlSelf->mlp_cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12232453164381896042ull);
    vlSelf->mlp_acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11332996957773465459ull);
    vlSelf->mlp_acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5900792481030151072ull);
    vlSelf->dbg_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9035414299298431771ull);
    vlSelf->dbg_cmd_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2612432606341277021ull);
    vlSelf->dbg_byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7681673879648583488ull);
    vlSelf->dbg_resp_byte_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6159518555305720404ull);
    vlSelf->dbg_tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3708476144463707885ull);
    vlSelf->dbg_tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18258353134119828042ull);
    vlSelf->dbg_rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 878494597556171531ull);
    vlSelf->dbg_rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12713118429069965386ull);
    vlSelf->dbg_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3782042096314862169ull);
    vlSelf->dbg_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2402596707221088721ull);
    vlSelf->uart_controller__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 57364285701330560ull);
    vlSelf->uart_controller__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14068190972731889609ull);
    vlSelf->uart_controller__DOT__uart_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8078453279423447488ull);
    vlSelf->uart_controller__DOT__uart_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7213237182820531931ull);
    vlSelf->uart_controller__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16463026624154696645ull);
    vlSelf->uart_controller__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5226413688711893906ull);
    vlSelf->uart_controller__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8841501535223144249ull);
    vlSelf->uart_controller__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6621174297909642176ull);
    vlSelf->uart_controller__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7273581962332572340ull);
    vlSelf->uart_controller__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7337368440234367452ull);
    vlSelf->uart_controller__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11602340683192091125ull);
    vlSelf->uart_controller__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11171664000924649459ull);
    vlSelf->uart_controller__DOT__mlp_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16567520233420015060ull);
    vlSelf->uart_controller__DOT__mlp_cycle_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5224528298660500407ull);
    vlSelf->uart_controller__DOT__mlp_acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17627435424942174284ull);
    vlSelf->uart_controller__DOT__mlp_acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6379540176258200081ull);
    vlSelf->uart_controller__DOT__dbg_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4567710670560039954ull);
    vlSelf->uart_controller__DOT__dbg_cmd_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7923907742458731977ull);
    vlSelf->uart_controller__DOT__dbg_byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 343245799771256660ull);
    vlSelf->uart_controller__DOT__dbg_resp_byte_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8301482883402473215ull);
    vlSelf->uart_controller__DOT__dbg_tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8609955351367667874ull);
    vlSelf->uart_controller__DOT__dbg_tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11402754742060536179ull);
    vlSelf->uart_controller__DOT__dbg_rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12759687193426302506ull);
    vlSelf->uart_controller__DOT__dbg_rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6294360938609901493ull);
    vlSelf->uart_controller__DOT__dbg_weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4857891063542083874ull);
    vlSelf->uart_controller__DOT__dbg_start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16288472881198866011ull);
    vlSelf->uart_controller__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16654920076293508606ull);
    vlSelf->uart_controller__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4116698337119723664ull);
    vlSelf->uart_controller__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11474205563670330555ull);
    vlSelf->uart_controller__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17956824251403271912ull);
    vlSelf->uart_controller__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3466907630830854239ull);
    vlSelf->uart_controller__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2847624403403017913ull);
    vlSelf->uart_controller__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13956970119030834747ull);
    vlSelf->uart_controller__DOT__cmd_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16140438210777593569ull);
    vlSelf->uart_controller__DOT__byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9678636096860699557ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->uart_controller__DOT__data_buffer[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9071510333758678568ull);
    }
    vlSelf->uart_controller__DOT__resp_byte_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2900498654916787508ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->uart_controller__DOT__resp_buffer[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3573853113393042896ull);
    }
    vlSelf->uart_controller__DOT__weight_seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8283618322867979297ull);
    vlSelf->uart_controller__DOT__act_seq_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4341567892503190963ull);
    vlSelf->uart_controller__DOT__byte_sent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15724601881559210969ull);
    vlSelf->uart_controller__DOT__resp_delay_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5080762143550626646ull);
    vlSelf->uart_controller__DOT__wf_reset_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14148795724147690916ull);
    vlSelf->uart_controller__DOT__weights_ready_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10178874896522823580ull);
    vlSelf->uart_controller__DOT__mlp_state_prev = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1888967652126595259ull);
    vlSelf->uart_controller__DOT__wf_push_col0_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17767081393674287111ull);
    vlSelf->uart_controller__DOT__wf_push_col1_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18375841711522611043ull);
    vlSelf->uart_controller__DOT__wf_data_in_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15179195168760798339ull);
    vlSelf->uart_controller__DOT__init_act_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17765621183165203721ull);
    vlSelf->uart_controller__DOT__init_act_data_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4354865064131432444ull);
    vlSelf->uart_controller__DOT__start_mlp_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2878153325307913962ull);
    vlSelf->uart_controller__DOT__tx_valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8952292486966680937ull);
    vlSelf->uart_controller__DOT__tx_data_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11433116457270556741ull);
    vlSelf->uart_controller__DOT__start_mlp_sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11221600553967094183ull);
    vlSelf->uart_controller__DOT__rx_data_captured = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8072867404123256605ull);
    vlSelf->uart_controller__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8237725961477419560ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8178400597356041876ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1591910842812105726ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8969350180389072751ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1891960569349221055ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8323257769937514696ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3875777331225692119ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3271742870633951114ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18246621325104921466ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 908006505961861415ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_sync_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10497720432012800056ull);
    vlSelf->uart_controller__DOT__uart_rx_u__DOT__rx_sync_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 949943184578141325ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5263788568367347467ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 39246861720485172ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5737412645424121190ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8972834150098812467ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7566519132593657876ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9780614811772620089ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4536051791151852671ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 677943542869278854ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2974352577799881863ull);
    vlSelf->uart_controller__DOT__uart_tx_u__DOT__tx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14062004825919801953ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2091631477146616917ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7642123052517001528ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13159605773767629959ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
