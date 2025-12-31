// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst;
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/uart_controller.sv", 14, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge uart_controller.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge uart_controller.uart_rx_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge uart_controller.uart_rx_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge uart_controller.uart_tx_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge uart_controller.uart_tx_inst.rst)\n");
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
    vlSelf->uart_rx_pin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17022543047208894752ull);
    vlSelf->uart_tx_pin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11263200647376832277ull);
    vlSelf->wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17607047225282717665ull);
    vlSelf->wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15413999677017281515ull);
    vlSelf->wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6655838028478558514ull);
    vlSelf->wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 756852297801786066ull);
    vlSelf->init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9207923663655795732ull);
    vlSelf->init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1919708525650195647ull);
    vlSelf->start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15041482429981211798ull);
    vlSelf->weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13129243201023795017ull);
    vlSelf->state_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8276830675781670612ull);
    vlSelf->layer_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14006444394765142208ull);
    vlSelf->acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10812525088362516050ull);
    vlSelf->acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6014634557126852305ull);
    vlSelf->debug_state = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17458634628187422603ull);
    vlSelf->debug_cmd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9414594909066133659ull);
    vlSelf->uart_controller__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 57364285701330560ull);
    vlSelf->uart_controller__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14068190972731889609ull);
    vlSelf->uart_controller__DOT__uart_rx_pin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7438544076252235729ull);
    vlSelf->uart_controller__DOT__uart_tx_pin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8408326976359720123ull);
    vlSelf->uart_controller__DOT__wf_push_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16463026624154696645ull);
    vlSelf->uart_controller__DOT__wf_push_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5226413688711893906ull);
    vlSelf->uart_controller__DOT__wf_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8841501535223144249ull);
    vlSelf->uart_controller__DOT__wf_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6621174297909642176ull);
    vlSelf->uart_controller__DOT__init_act_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7273581962332572340ull);
    vlSelf->uart_controller__DOT__init_act_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7337368440234367452ull);
    vlSelf->uart_controller__DOT__start_mlp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11602340683192091125ull);
    vlSelf->uart_controller__DOT__weights_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11171664000924649459ull);
    vlSelf->uart_controller__DOT__state_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1194402772504018477ull);
    vlSelf->uart_controller__DOT__layer_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16998072144783250925ull);
    vlSelf->uart_controller__DOT__acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7597088418748061828ull);
    vlSelf->uart_controller__DOT__acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15514399860944002236ull);
    vlSelf->uart_controller__DOT__debug_state = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2116454454716096406ull);
    vlSelf->uart_controller__DOT__debug_cmd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15912786706143194088ull);
    vlSelf->uart_controller__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16654920076293508606ull);
    vlSelf->uart_controller__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4116698337119723664ull);
    vlSelf->uart_controller__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11474205563670330555ull);
    vlSelf->uart_controller__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17956824251403271912ull);
    vlSelf->uart_controller__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3466907630830854239ull);
    vlSelf->uart_controller__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2847624403403017913ull);
    vlSelf->uart_controller__DOT__cmd_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7145797247072347711ull);
    vlSelf->uart_controller__DOT__command = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15867675312184858650ull);
    vlSelf->uart_controller__DOT__byte_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9678636096860699557ull);
    vlSelf->uart_controller__DOT__weight_buffer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17741799226001135588ull);
    vlSelf->uart_controller__DOT__act_buffer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4755880041827484969ull);
    vlSelf->uart_controller__DOT__result_buffer = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6264367489919864063ull);
    vlSelf->uart_controller__DOT__rx_valid_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13231901840222818242ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7463385767399666057ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17893009473465381337ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1585214525885698895ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17548761413035548561ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1153172125277374579ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11418955156681792735ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 866376192626115662ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16993944038085990912ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3906924930931533199ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17202263318667016639ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8023235172312733513ull);
    vlSelf->uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16107277249617483759ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17634762862150681688ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3699403750867764878ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4395927300782836900ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14920766596411429303ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6782422807204928201ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14459293987877785454ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13597592751275654206ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__clk_count = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14597471369309991410ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 49961148635752132ull);
    vlSelf->uart_controller__DOT__uart_tx_inst__DOT__tx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13192972387375044358ull);
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
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4031784378450404342ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11655808655724345805ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10909769900871704809ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18242205461815949410ull);
    vlSelf->__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2254958206167311919ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
