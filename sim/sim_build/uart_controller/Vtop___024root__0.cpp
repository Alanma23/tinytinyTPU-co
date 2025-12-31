// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__mlp_state = vlSelfRef.mlp_state;
    vlSelfRef.uart_controller__DOT__mlp_cycle_cnt = vlSelfRef.mlp_cycle_cnt;
    vlSelfRef.uart_controller__DOT__mlp_current_layer 
        = vlSelfRef.mlp_current_layer;
    vlSelfRef.uart_controller__DOT__mlp_layer_complete 
        = vlSelfRef.mlp_layer_complete;
    vlSelfRef.uart_controller__DOT__mlp_acc0 = vlSelfRef.mlp_acc0;
    vlSelfRef.uart_controller__DOT__mlp_acc1 = vlSelfRef.mlp_acc1;
    vlSelfRef.uart_controller__DOT__mlp_acc_valid = vlSelfRef.mlp_acc_valid;
    vlSelfRef.uart_controller__DOT__rx_data = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_data;
    vlSelfRef.uart_controller__DOT__rx_valid = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid;
    vlSelfRef.uart_controller__DOT__uart_rx = vlSelfRef.uart_rx;
    vlSelfRef.uart_controller__DOT__uart_tx = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx;
    vlSelfRef.uart_controller__DOT__wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0_reg;
    vlSelfRef.uart_controller__DOT__wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1_reg;
    vlSelfRef.uart_controller__DOT__wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in_reg;
    vlSelfRef.uart_controller__DOT__wf_reset = vlSelfRef.uart_controller__DOT__wf_reset_reg;
    vlSelfRef.uart_controller__DOT__init_act_valid 
        = vlSelfRef.uart_controller__DOT__init_act_valid_reg;
    vlSelfRef.uart_controller__DOT__init_act_data = vlSelfRef.uart_controller__DOT__init_act_data_reg;
    vlSelfRef.uart_controller__DOT__start_mlp = vlSelfRef.uart_controller__DOT__start_mlp_reg;
    vlSelfRef.uart_controller__DOT__weights_ready = vlSelfRef.uart_controller__DOT__weights_ready_reg;
    vlSelfRef.uart_controller__DOT__tx_valid = vlSelfRef.uart_controller__DOT__tx_valid_reg;
    vlSelfRef.uart_controller__DOT__tx_data = vlSelfRef.uart_controller__DOT__tx_data_reg;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state));
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state));
    vlSelfRef.uart_controller__DOT__clk = vlSelfRef.clk;
    vlSelfRef.uart_controller__DOT__rst = vlSelfRef.rst;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx 
        = vlSelfRef.uart_controller__DOT__uart_rx;
    vlSelfRef.uart_tx = vlSelfRef.uart_controller__DOT__uart_tx;
    vlSelfRef.wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0;
    vlSelfRef.wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1;
    vlSelfRef.wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in;
    vlSelfRef.wf_reset = vlSelfRef.uart_controller__DOT__wf_reset;
    vlSelfRef.init_act_valid = vlSelfRef.uart_controller__DOT__init_act_valid;
    vlSelfRef.init_act_data = vlSelfRef.uart_controller__DOT__init_act_data;
    vlSelfRef.start_mlp = vlSelfRef.uart_controller__DOT__start_mlp;
    vlSelfRef.weights_ready = vlSelfRef.uart_controller__DOT__weights_ready;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_valid 
        = vlSelfRef.uart_controller__DOT__tx_valid;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_data 
        = vlSelfRef.uart_controller__DOT__tx_data;
    vlSelfRef.uart_controller__DOT__rx_ready = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_ready;
    vlSelfRef.uart_controller__DOT__tx_ready = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_ready;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rst 
        = vlSelfRef.uart_controller__DOT__rst;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__rst 
        = vlSelfRef.uart_controller__DOT__rst;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__rst) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__rst__0))) 
                                                       << 5U) 
                                                      | (((IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__clk__0))) 
                                                         << 4U)) 
                                                     | (((((IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rst) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__rst__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.uart_controller__DOT__rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__rst__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.uart_controller__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_u__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_u__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__uart_controller__DOT__uart_tx_u__DOT__state;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 0;
    SData/*15:0*/ __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte = 0;
    // Body
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_byte;
    __Vdly__uart_controller__DOT__uart_tx_u__DOT__state 
        = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state;
    if (vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__rst) {
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 0U;
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index = 0U;
        vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx = 1U;
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte = 0U;
    } else if ((2U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state))) {
            vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx = 1U;
            if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0U;
                __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 0U;
            } else {
                __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count)));
            }
        } else {
            vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx 
                = (1U & ((IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_byte) 
                         >> (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index)));
            if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0U;
                if ((7U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index))) {
                    __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index = 0U;
                    __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 3U;
                } else {
                    __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index)));
                }
            } else {
                __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count)));
            }
        }
    } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state))) {
        vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx = 0U;
        if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count))) {
            __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0U;
            __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 2U;
        } else {
            __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count)));
        }
    } else {
        vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx = 1U;
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index = 0U;
        if (vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_valid) {
            __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte 
                = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_data;
            __Vdly__uart_controller__DOT__uart_tx_u__DOT__state = 1U;
        }
    }
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count 
        = __Vdly__uart_controller__DOT__uart_tx_u__DOT__clk_count;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index 
        = __Vdly__uart_controller__DOT__uart_tx_u__DOT__bit_index;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_byte 
        = __Vdly__uart_controller__DOT__uart_tx_u__DOT__tx_byte;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state 
        = __Vdly__uart_controller__DOT__uart_tx_u__DOT__state;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state));
    vlSelfRef.uart_controller__DOT__uart_tx = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx;
    vlSelfRef.uart_tx = vlSelfRef.uart_controller__DOT__uart_tx;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__uart_controller__DOT__uart_rx_u__DOT__state;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 0;
    SData/*15:0*/ __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte = 0;
    // Body
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_byte;
    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state;
    if (vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rst) {
        __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 0U;
        __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index = 0U;
        vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_data = 0U;
        vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid = 0U;
        __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte = 0U;
    } else {
        vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid = 0U;
        if ((2U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state))) {
                if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count))) {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0U;
                    if (vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2) {
                        vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_data 
                            = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_byte;
                        vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid = 1U;
                    }
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 0U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count)));
                }
            } else if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0U;
                __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index))) 
                        & (IData)(__Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte)) 
                       | (0x00ffU & ((IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2) 
                                     << (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index))));
                if ((7U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index))) {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index = 0U;
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 3U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index)));
                }
            } else {
                __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count)));
            }
        } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state))) {
            if ((0x01b1U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count))) {
                if (vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2) {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 0U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0U;
                    __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 2U;
                }
            } else {
                __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count)));
            }
        } else {
            __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count = 0U;
            __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index = 0U;
            if ((1U & (~ (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2)))) {
                __Vdly__uart_controller__DOT__uart_rx_u__DOT__state = 1U;
            }
        }
    }
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count 
        = __Vdly__uart_controller__DOT__uart_rx_u__DOT__clk_count;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index 
        = __Vdly__uart_controller__DOT__uart_rx_u__DOT__bit_index;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_byte 
        = __Vdly__uart_controller__DOT__uart_rx_u__DOT__rx_byte;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state 
        = __Vdly__uart_controller__DOT__uart_rx_u__DOT__state;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state));
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__uart_controller__DOT__state;
    __Vdly__uart_controller__DOT__state = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__cmd_reg;
    __Vdly__uart_controller__DOT__cmd_reg = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__byte_count;
    __Vdly__uart_controller__DOT__byte_count = 0;
    CData/*1:0*/ __Vdly__uart_controller__DOT__weight_seq_idx;
    __Vdly__uart_controller__DOT__weight_seq_idx = 0;
    CData/*1:0*/ __Vdly__uart_controller__DOT__act_seq_idx;
    __Vdly__uart_controller__DOT__act_seq_idx = 0;
    CData/*1:0*/ __Vdly__uart_controller__DOT__resp_byte_idx;
    __Vdly__uart_controller__DOT__resp_byte_idx = 0;
    CData/*0:0*/ __Vdly__uart_controller__DOT__byte_sent;
    __Vdly__uart_controller__DOT__byte_sent = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__resp_delay_count;
    __Vdly__uart_controller__DOT__resp_delay_count = 0;
    CData/*0:0*/ __Vdly__uart_controller__DOT__tx_valid_reg;
    __Vdly__uart_controller__DOT__tx_valid_reg = 0;
    CData/*1:0*/ __VdlyDim0__uart_controller__DOT__data_buffer__v0;
    __VdlyDim0__uart_controller__DOT__data_buffer__v0 = 0;
    CData/*1:0*/ __VdlyDim0__uart_controller__DOT__resp_buffer__v0;
    __VdlyDim0__uart_controller__DOT__resp_buffer__v0 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__resp_buffer__v1;
    __VdlyVal__uart_controller__DOT__resp_buffer__v1 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__resp_buffer__v2;
    __VdlyVal__uart_controller__DOT__resp_buffer__v2 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__resp_buffer__v3;
    __VdlyVal__uart_controller__DOT__resp_buffer__v3 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__resp_buffer__v4;
    __VdlyVal__uart_controller__DOT__resp_buffer__v4 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__resp_buffer__v5;
    __VdlyVal__uart_controller__DOT__resp_buffer__v5 = 0;
    CData/*7:0*/ __VdlyVal__uart_controller__DOT__data_buffer__v1;
    __VdlyVal__uart_controller__DOT__data_buffer__v1 = 0;
    CData/*1:0*/ __VdlyDim0__uart_controller__DOT__data_buffer__v1;
    __VdlyDim0__uart_controller__DOT__data_buffer__v1 = 0;
    // Body
    __Vdly__uart_controller__DOT__state = vlSelfRef.uart_controller__DOT__state;
    __Vdly__uart_controller__DOT__cmd_reg = vlSelfRef.uart_controller__DOT__cmd_reg;
    __Vdly__uart_controller__DOT__byte_count = vlSelfRef.uart_controller__DOT__byte_count;
    __Vdly__uart_controller__DOT__weight_seq_idx = vlSelfRef.uart_controller__DOT__weight_seq_idx;
    __Vdly__uart_controller__DOT__act_seq_idx = vlSelfRef.uart_controller__DOT__act_seq_idx;
    __Vdly__uart_controller__DOT__resp_byte_idx = vlSelfRef.uart_controller__DOT__resp_byte_idx;
    __Vdly__uart_controller__DOT__byte_sent = vlSelfRef.uart_controller__DOT__byte_sent;
    __Vdly__uart_controller__DOT__resp_delay_count 
        = vlSelfRef.uart_controller__DOT__resp_delay_count;
    __Vdly__uart_controller__DOT__tx_valid_reg = vlSelfRef.uart_controller__DOT__tx_valid_reg;
    if (vlSelfRef.uart_controller__DOT__rst) {
        vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i = 0U;
        __Vdly__uart_controller__DOT__state = 0U;
        __Vdly__uart_controller__DOT__cmd_reg = 0U;
        __Vdly__uart_controller__DOT__byte_count = 0U;
        __Vdly__uart_controller__DOT__weight_seq_idx = 0U;
        __Vdly__uart_controller__DOT__act_seq_idx = 0U;
        while (VL_GTS_III(32, 4U, vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__uart_controller__DOT__data_buffer__v0 
                = (3U & vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueueuart_controller__DOT__data_buffer.enqueue(0U, (IData)(__VdlyDim0__uart_controller__DOT__data_buffer__v0));
            __VdlyDim0__uart_controller__DOT__resp_buffer__v0 
                = (3U & vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(0U, (IData)(__VdlyDim0__uart_controller__DOT__resp_buffer__v0));
            vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i);
        }
        __Vdly__uart_controller__DOT__resp_byte_idx = 0U;
        __Vdly__uart_controller__DOT__byte_sent = 0U;
        __Vdly__uart_controller__DOT__resp_delay_count = 0U;
        vlSelfRef.uart_controller__DOT__wf_push_col0_reg = 0U;
        vlSelfRef.uart_controller__DOT__wf_push_col1_reg = 0U;
        vlSelfRef.uart_controller__DOT__wf_data_in_reg = 0U;
        vlSelfRef.uart_controller__DOT__init_act_valid_reg = 0U;
        vlSelfRef.uart_controller__DOT__init_act_data_reg = 0U;
        vlSelfRef.uart_controller__DOT__start_mlp_reg = 0U;
        __Vdly__uart_controller__DOT__tx_valid_reg = 0U;
        vlSelfRef.uart_controller__DOT__tx_data_reg = 0U;
        vlSelfRef.uart_controller__DOT__wf_reset_reg = 0U;
        vlSelfRef.uart_controller__DOT__weights_ready_reg = 0U;
    } else {
        vlSelfRef.uart_controller__DOT__wf_push_col0_reg = 0U;
        vlSelfRef.uart_controller__DOT__wf_push_col1_reg = 0U;
        vlSelfRef.uart_controller__DOT__init_act_valid_reg = 0U;
        vlSelfRef.uart_controller__DOT__start_mlp_reg = 0U;
        if ((8U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
            __Vdly__uart_controller__DOT__state = 0U;
        } else if ((4U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
                    __Vdly__uart_controller__DOT__state = 0U;
                } else if ((0U == (IData)(vlSelfRef.uart_controller__DOT__act_seq_idx))) {
                    vlSelfRef.uart_controller__DOT__init_act_data_reg 
                        = ((vlSelfRef.uart_controller__DOT__data_buffer
                            [1U] << 8U) | vlSelfRef.uart_controller__DOT__data_buffer
                           [0U]);
                    vlSelfRef.uart_controller__DOT__init_act_valid_reg = 1U;
                    __Vdly__uart_controller__DOT__act_seq_idx = 1U;
                } else if ((1U == (IData)(vlSelfRef.uart_controller__DOT__act_seq_idx))) {
                    vlSelfRef.uart_controller__DOT__init_act_data_reg 
                        = ((vlSelfRef.uart_controller__DOT__data_buffer
                            [3U] << 8U) | vlSelfRef.uart_controller__DOT__data_buffer
                           [2U]);
                    vlSelfRef.uart_controller__DOT__init_act_valid_reg = 1U;
                    __Vdly__uart_controller__DOT__state = 0U;
                } else {
                    __Vdly__uart_controller__DOT__state = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.uart_controller__DOT__weight_seq_idx))) {
                    if ((1U & (IData)(vlSelfRef.uart_controller__DOT__weight_seq_idx))) {
                        vlSelfRef.uart_controller__DOT__wf_data_in_reg 
                            = vlSelfRef.uart_controller__DOT__data_buffer
                            [3U];
                        vlSelfRef.uart_controller__DOT__wf_push_col1_reg = 1U;
                        vlSelfRef.uart_controller__DOT__weights_ready_reg = 1U;
                        __Vdly__uart_controller__DOT__state = 0U;
                    } else {
                        vlSelfRef.uart_controller__DOT__wf_data_in_reg 
                            = vlSelfRef.uart_controller__DOT__data_buffer
                            [2U];
                        vlSelfRef.uart_controller__DOT__wf_push_col0_reg = 1U;
                        __Vdly__uart_controller__DOT__weight_seq_idx = 3U;
                    }
                } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__weight_seq_idx))) {
                    vlSelfRef.uart_controller__DOT__wf_data_in_reg 
                        = vlSelfRef.uart_controller__DOT__data_buffer
                        [1U];
                    vlSelfRef.uart_controller__DOT__wf_push_col1_reg = 1U;
                    __Vdly__uart_controller__DOT__weight_seq_idx = 2U;
                } else {
                    vlSelfRef.uart_controller__DOT__wf_data_in_reg 
                        = vlSelfRef.uart_controller__DOT__data_buffer
                        [0U];
                    vlSelfRef.uart_controller__DOT__wf_push_col0_reg = 1U;
                    __Vdly__uart_controller__DOT__weight_seq_idx = 1U;
                }
            } else if ((0x0aU > (IData)(vlSelfRef.uart_controller__DOT__resp_delay_count))) {
                __Vdly__uart_controller__DOT__resp_delay_count 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__resp_delay_count)));
            } else if (VL_UNLIKELY(((((~ (IData)(vlSelfRef.uart_controller__DOT__tx_valid_reg)) 
                                      & (IData)(vlSelfRef.uart_controller__DOT__tx_ready)) 
                                     & (~ (IData)(vlSelfRef.uart_controller__DOT__byte_sent)))))) {
                vlSelfRef.uart_controller__DOT__tx_data_reg 
                    = vlSelfRef.uart_controller__DOT__resp_buffer
                    [vlSelfRef.uart_controller__DOT__resp_byte_idx];
                __Vdly__uart_controller__DOT__tx_valid_reg = 1U;
                __Vdly__uart_controller__DOT__byte_sent = 1U;
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Sending byte[%0#]=0x%02x (from resp_buffer[%0#]=0x%02x), cmd=0x%02x, tx_ready=%b, total_bytes=%0d\n",0,
                             2,vlSelfRef.uart_controller__DOT__resp_byte_idx,
                             8,vlSelfRef.uart_controller__DOT__resp_buffer
                             [vlSelfRef.uart_controller__DOT__resp_byte_idx],
                             2,vlSelfRef.uart_controller__DOT__resp_byte_idx,
                             8,vlSelfRef.uart_controller__DOT__resp_buffer
                             [vlSelfRef.uart_controller__DOT__resp_byte_idx],
                             8,vlSelfRef.uart_controller__DOT__cmd_reg,
                             1,(IData)(vlSelfRef.uart_controller__DOT__tx_ready),
                             32,((4U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))
                                  ? 4U : 1U));
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.uart_controller__DOT__tx_valid_reg) 
                                     & (IData)(vlSelfRef.uart_controller__DOT__tx_ready))))) {
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] waiting for UART TX to accept\n",0,
                             2,vlSelfRef.uart_controller__DOT__resp_byte_idx);
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.uart_controller__DOT__tx_valid_reg) 
                                     & (~ (IData)(vlSelfRef.uart_controller__DOT__tx_ready)))))) {
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] accepted by UART TX, clearing tx_valid\n",0,
                             2,vlSelfRef.uart_controller__DOT__resp_byte_idx);
                __Vdly__uart_controller__DOT__tx_valid_reg = 0U;
            } else if ((1U & (~ ((~ (IData)(vlSelfRef.uart_controller__DOT__tx_valid_reg)) 
                                 & (~ (IData)(vlSelfRef.uart_controller__DOT__tx_ready)))))) {
                if ((((~ (IData)(vlSelfRef.uart_controller__DOT__tx_valid_reg)) 
                      & (IData)(vlSelfRef.uart_controller__DOT__tx_ready)) 
                     & (IData)(vlSelfRef.uart_controller__DOT__byte_sent))) {
                    VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] transmission complete, cmd=0x%02x\n",0,
                                 2,vlSelfRef.uart_controller__DOT__resp_byte_idx,
                                 8,(IData)(vlSelfRef.uart_controller__DOT__cmd_reg));
                    if (VL_UNLIKELY(((5U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))))) {
                        VL_WRITEF_NX("[UART_CTRL] SEND_RESP: STATUS done, going to IDLE\n",0);
                        __Vdly__uart_controller__DOT__state = 0U;
                    } else if (VL_LIKELY(((4U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))))) {
                        if ((3U == (IData)(vlSelfRef.uart_controller__DOT__resp_byte_idx))) {
                            VL_WRITEF_NX("[UART_CTRL] SEND_RESP: All 4 bytes sent (0,1,2,3), going to IDLE\n",0);
                            __Vdly__uart_controller__DOT__state = 0U;
                        } else {
                            __Vdly__uart_controller__DOT__resp_byte_idx 
                                = (3U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.uart_controller__DOT__resp_byte_idx)));
                            VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Moving to next byte, resp_byte_idx=%0#->%0#\n",0,
                                         2,vlSelfRef.uart_controller__DOT__resp_byte_idx,
                                         32,((IData)(1U) 
                                             + (IData)(vlSelfRef.uart_controller__DOT__resp_byte_idx)));
                            __Vdly__uart_controller__DOT__byte_sent = 0U;
                            __Vdly__uart_controller__DOT__resp_delay_count = 0x0aU;
                        }
                    } else {
                        VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Unknown command, going to IDLE\n",0);
                        __Vdly__uart_controller__DOT__state = 0U;
                    }
                } else {
                    VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Unexpected state - tx_valid=%b, tx_ready=%b, byte_sent=%b\n",0,
                                 1,vlSelfRef.uart_controller__DOT__tx_valid_reg,
                                 1,(IData)(vlSelfRef.uart_controller__DOT__tx_ready),
                                 1,vlSelfRef.uart_controller__DOT__byte_sent);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
                if (VL_UNLIKELY(((3U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_EXECUTE - setting start_mlp_reg=1, state=%0#\n",0,
                                 4,vlSelfRef.uart_controller__DOT__state);
                    vlSelfRef.uart_controller__DOT__start_mlp_reg = 1U;
                    __Vdly__uart_controller__DOT__state = 0U;
                } else if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_READ_RESULT - acc0=0x%08x, packing bytes: [7:0]=0x%02x, [15:8]=0x%02x, [23:16]=0x%02x, [31:24]=0x%02x, resp_buffer current=[0x%02x,0x%02x,0x%02x,0x%02x]\n",0,
                                 32,vlSelfRef.uart_controller__DOT__mlp_acc0,
                                 8,(0x000000ffU & vlSelfRef.uart_controller__DOT__mlp_acc0),
                                 8,(0x000000ffU & (vlSelfRef.uart_controller__DOT__mlp_acc0 
                                                   >> 8U)),
                                 8,(0x000000ffU & (vlSelfRef.uart_controller__DOT__mlp_acc0 
                                                   >> 0x10U)),
                                 8,(vlSelfRef.uart_controller__DOT__mlp_acc0 
                                    >> 0x18U),8,vlSelfRef.uart_controller__DOT__resp_buffer
                                 [0U],8,vlSelfRef.uart_controller__DOT__resp_buffer
                                 [1U],8,vlSelfRef.uart_controller__DOT__resp_buffer
                                 [2U],8,vlSelfRef.uart_controller__DOT__resp_buffer
                                 [3U]);
                    __Vdly__uart_controller__DOT__resp_byte_idx = 0U;
                    __Vdly__uart_controller__DOT__byte_sent = 0U;
                    __Vdly__uart_controller__DOT__state = 4U;
                    __VdlyVal__uart_controller__DOT__resp_buffer__v1 
                        = (0x000000ffU & vlSelfRef.uart_controller__DOT__mlp_acc0);
                    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(__VdlyVal__uart_controller__DOT__resp_buffer__v1, 0U);
                    __VdlyVal__uart_controller__DOT__resp_buffer__v2 
                        = (0x000000ffU & (vlSelfRef.uart_controller__DOT__mlp_acc0 
                                          >> 8U));
                    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(__VdlyVal__uart_controller__DOT__resp_buffer__v2, 1U);
                    __VdlyVal__uart_controller__DOT__resp_buffer__v3 
                        = (0x000000ffU & (vlSelfRef.uart_controller__DOT__mlp_acc0 
                                          >> 0x10U));
                    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(__VdlyVal__uart_controller__DOT__resp_buffer__v3, 2U);
                    __VdlyVal__uart_controller__DOT__resp_buffer__v4 
                        = (vlSelfRef.uart_controller__DOT__mlp_acc0 
                           >> 0x18U);
                    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(__VdlyVal__uart_controller__DOT__resp_buffer__v4, 3U);
                } else if (VL_UNLIKELY(((5U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_STATUS - mlp_state=0x%x[3:0], mlp_cycle_cnt=0x%x[4:0], packed_value=0x%02x (packed: state[2:0]=0x%x, cycle[4:0]=0x%x), resp_buffer[0] current=0x%02x\n",0,
                                 4,vlSelfRef.uart_controller__DOT__mlp_state,
                                 5,(IData)(vlSelfRef.uart_controller__DOT__mlp_cycle_cnt),
                                 8,((0x000000e0U & 
                                     ((IData)(vlSelfRef.uart_controller__DOT__mlp_state) 
                                      << 5U)) | (IData)(vlSelfRef.uart_controller__DOT__mlp_cycle_cnt)),
                                 3,(7U & (IData)(vlSelfRef.uart_controller__DOT__mlp_state)),
                                 5,(IData)(vlSelfRef.uart_controller__DOT__mlp_cycle_cnt),
                                 8,vlSelfRef.uart_controller__DOT__resp_buffer
                                 [0U]);
                    __Vdly__uart_controller__DOT__resp_byte_idx = 0U;
                    __Vdly__uart_controller__DOT__byte_sent = 0U;
                    __Vdly__uart_controller__DOT__state = 4U;
                    __VdlyVal__uart_controller__DOT__resp_buffer__v5 
                        = ((0x000000e0U & ((IData)(vlSelfRef.uart_controller__DOT__mlp_state) 
                                           << 5U)) 
                           | (IData)(vlSelfRef.uart_controller__DOT__mlp_cycle_cnt));
                    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.enqueue(__VdlyVal__uart_controller__DOT__resp_buffer__v5, 0U);
                } else {
                    __Vdly__uart_controller__DOT__state = 0U;
                }
            } else if (vlSelfRef.uart_controller__DOT__rx_valid) {
                __VdlyVal__uart_controller__DOT__data_buffer__v1 
                    = vlSelfRef.uart_controller__DOT__rx_data;
                __VdlyDim0__uart_controller__DOT__data_buffer__v1 
                    = (3U & (IData)(vlSelfRef.uart_controller__DOT__byte_count));
                vlSelfRef.__VdlyCommitQueueuart_controller__DOT__data_buffer.enqueue(__VdlyVal__uart_controller__DOT__data_buffer__v1, (IData)(__VdlyDim0__uart_controller__DOT__data_buffer__v1));
                if ((3U == (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    if ((1U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))) {
                        __Vdly__uart_controller__DOT__weight_seq_idx = 0U;
                        __Vdly__uart_controller__DOT__state = 5U;
                    } else if ((2U == (IData)(vlSelfRef.uart_controller__DOT__cmd_reg))) {
                        __Vdly__uart_controller__DOT__act_seq_idx = 0U;
                        __Vdly__uart_controller__DOT__state = 6U;
                    } else {
                        __Vdly__uart_controller__DOT__state = 3U;
                    }
                } else {
                    __Vdly__uart_controller__DOT__byte_count 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__byte_count)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__state))) {
            if (VL_UNLIKELY((vlSelfRef.uart_controller__DOT__rx_valid))) {
                VL_WRITEF_NX("[UART_CTRL] WAIT_CMD: Received cmd=0x%02x\n",0,
                             8,vlSelfRef.uart_controller__DOT__rx_data);
                __Vdly__uart_controller__DOT__cmd_reg 
                    = vlSelfRef.uart_controller__DOT__rx_data;
                __Vdly__uart_controller__DOT__byte_count = 0U;
                __Vdly__uart_controller__DOT__state 
                    = (((1U == (IData)(vlSelfRef.uart_controller__DOT__rx_data)) 
                        | (2U == (IData)(vlSelfRef.uart_controller__DOT__rx_data)))
                        ? 2U : ((((3U == (IData)(vlSelfRef.uart_controller__DOT__rx_data)) 
                                  | (4U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) 
                                 | (5U == (IData)(vlSelfRef.uart_controller__DOT__rx_data)))
                                 ? 3U : 0U));
            }
        } else {
            __Vdly__uart_controller__DOT__byte_count = 0U;
            __Vdly__uart_controller__DOT__resp_byte_idx = 0U;
            __Vdly__uart_controller__DOT__byte_sent = 0U;
            __Vdly__uart_controller__DOT__resp_delay_count = 0U;
            __Vdly__uart_controller__DOT__weight_seq_idx = 0U;
            __Vdly__uart_controller__DOT__act_seq_idx = 0U;
            if (vlSelfRef.uart_controller__DOT__rx_ready) {
                __Vdly__uart_controller__DOT__state = 1U;
            }
        }
    }
    vlSelfRef.uart_controller__DOT__state = __Vdly__uart_controller__DOT__state;
    vlSelfRef.uart_controller__DOT__cmd_reg = __Vdly__uart_controller__DOT__cmd_reg;
    vlSelfRef.uart_controller__DOT__byte_count = __Vdly__uart_controller__DOT__byte_count;
    vlSelfRef.uart_controller__DOT__weight_seq_idx 
        = __Vdly__uart_controller__DOT__weight_seq_idx;
    vlSelfRef.uart_controller__DOT__act_seq_idx = __Vdly__uart_controller__DOT__act_seq_idx;
    vlSelfRef.uart_controller__DOT__resp_byte_idx = __Vdly__uart_controller__DOT__resp_byte_idx;
    vlSelfRef.uart_controller__DOT__byte_sent = __Vdly__uart_controller__DOT__byte_sent;
    vlSelfRef.uart_controller__DOT__resp_delay_count 
        = __Vdly__uart_controller__DOT__resp_delay_count;
    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__data_buffer.commit(vlSelfRef.uart_controller__DOT__data_buffer);
    vlSelfRef.__VdlyCommitQueueuart_controller__DOT__resp_buffer.commit(vlSelfRef.uart_controller__DOT__resp_buffer);
    vlSelfRef.uart_controller__DOT__tx_valid_reg = __Vdly__uart_controller__DOT__tx_valid_reg;
    vlSelfRef.uart_controller__DOT__wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0_reg;
    vlSelfRef.uart_controller__DOT__wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1_reg;
    vlSelfRef.uart_controller__DOT__wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in_reg;
    vlSelfRef.uart_controller__DOT__init_act_valid 
        = vlSelfRef.uart_controller__DOT__init_act_valid_reg;
    vlSelfRef.uart_controller__DOT__init_act_data = vlSelfRef.uart_controller__DOT__init_act_data_reg;
    vlSelfRef.uart_controller__DOT__start_mlp = vlSelfRef.uart_controller__DOT__start_mlp_reg;
    vlSelfRef.uart_controller__DOT__tx_valid = vlSelfRef.uart_controller__DOT__tx_valid_reg;
    vlSelfRef.uart_controller__DOT__tx_data = vlSelfRef.uart_controller__DOT__tx_data_reg;
    vlSelfRef.uart_controller__DOT__wf_reset = vlSelfRef.uart_controller__DOT__wf_reset_reg;
    vlSelfRef.uart_controller__DOT__weights_ready = vlSelfRef.uart_controller__DOT__weights_ready_reg;
    vlSelfRef.wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0;
    vlSelfRef.wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1;
    vlSelfRef.wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in;
    vlSelfRef.init_act_valid = vlSelfRef.uart_controller__DOT__init_act_valid;
    vlSelfRef.init_act_data = vlSelfRef.uart_controller__DOT__init_act_data;
    vlSelfRef.start_mlp = vlSelfRef.uart_controller__DOT__start_mlp;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_valid 
        = vlSelfRef.uart_controller__DOT__tx_valid;
    vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_data 
        = vlSelfRef.uart_controller__DOT__tx_data;
    vlSelfRef.wf_reset = vlSelfRef.uart_controller__DOT__wf_reset;
    vlSelfRef.weights_ready = vlSelfRef.uart_controller__DOT__weights_ready;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_1;
    vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_1 
        = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__tx_ready = vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_ready;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__rx_valid = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid;
    vlSelfRef.uart_controller__DOT__rx_data = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_data;
    vlSelfRef.uart_controller__DOT__rx_ready = vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_ready;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/Users/abiralshakya/Documents/tpu_to_fpga_rev2/tinytinyTPU-co/rtl/uart_controller.sv", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/abiralshakya/Documents/tpu_to_fpga_rev2/tinytinyTPU-co/rtl/uart_controller.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/abiralshakya/Documents/tpu_to_fpga_rev2/tinytinyTPU-co/rtl/uart_controller.sv", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.uart_rx & 0xfeU)))) {
        Verilated::overWidthError("uart_rx");
    }
    if (VL_UNLIKELY(((vlSelfRef.mlp_state & 0xf0U)))) {
        Verilated::overWidthError("mlp_state");
    }
    if (VL_UNLIKELY(((vlSelfRef.mlp_cycle_cnt & 0xe0U)))) {
        Verilated::overWidthError("mlp_cycle_cnt");
    }
    if (VL_UNLIKELY(((vlSelfRef.mlp_current_layer & 0xf8U)))) {
        Verilated::overWidthError("mlp_current_layer");
    }
    if (VL_UNLIKELY(((vlSelfRef.mlp_layer_complete 
                      & 0xfeU)))) {
        Verilated::overWidthError("mlp_layer_complete");
    }
    if (VL_UNLIKELY(((vlSelfRef.mlp_acc_valid & 0xfeU)))) {
        Verilated::overWidthError("mlp_acc_valid");
    }
}
#endif  // VL_DEBUG
