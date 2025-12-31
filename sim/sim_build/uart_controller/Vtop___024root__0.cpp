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
    vlSelfRef.wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0;
    vlSelfRef.wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1;
    vlSelfRef.wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in;
    vlSelfRef.wf_reset = vlSelfRef.uart_controller__DOT__wf_reset;
    vlSelfRef.init_act_valid = vlSelfRef.uart_controller__DOT__init_act_valid;
    vlSelfRef.init_act_data = vlSelfRef.uart_controller__DOT__init_act_data;
    vlSelfRef.start_mlp = vlSelfRef.uart_controller__DOT__start_mlp;
    vlSelfRef.weights_ready = vlSelfRef.uart_controller__DOT__weights_ready;
    vlSelfRef.uart_controller__DOT__state_in = vlSelfRef.state_in;
    vlSelfRef.uart_controller__DOT__layer_complete 
        = vlSelfRef.layer_complete;
    vlSelfRef.uart_controller__DOT__acc0 = vlSelfRef.acc0;
    vlSelfRef.uart_controller__DOT__acc1 = vlSelfRef.acc1;
    vlSelfRef.uart_controller__DOT__rx_data = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_data;
    vlSelfRef.uart_controller__DOT__rx_valid = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_data 
        = vlSelfRef.uart_controller__DOT__tx_data;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_valid 
        = vlSelfRef.uart_controller__DOT__tx_valid;
    vlSelfRef.uart_controller__DOT__uart_rx_pin = vlSelfRef.uart_rx_pin;
    vlSelfRef.uart_controller__DOT__uart_tx_pin = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx;
    vlSelfRef.uart_controller__DOT__debug_state = vlSelfRef.uart_controller__DOT__cmd_state;
    vlSelfRef.uart_controller__DOT__debug_cmd = vlSelfRef.uart_controller__DOT__command;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state));
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state));
    vlSelfRef.uart_controller__DOT__clk = vlSelfRef.clk;
    vlSelfRef.uart_controller__DOT__rst = vlSelfRef.rst;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx 
        = vlSelfRef.uart_controller__DOT__uart_rx_pin;
    vlSelfRef.uart_tx_pin = vlSelfRef.uart_controller__DOT__uart_tx_pin;
    vlSelfRef.debug_state = vlSelfRef.uart_controller__DOT__debug_state;
    vlSelfRef.debug_cmd = vlSelfRef.uart_controller__DOT__debug_cmd;
    vlSelfRef.uart_controller__DOT__rx_ready = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_ready;
    vlSelfRef.uart_controller__DOT__tx_ready = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_ready;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk 
        = vlSelfRef.uart_controller__DOT__clk;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst 
        = vlSelfRef.uart_controller__DOT__rst;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst 
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
                                                    (((((IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__rst__0))) 
                                                       << 5U) 
                                                      | (((IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__clk__0))) 
                                                         << 4U)) 
                                                     | (((((IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__rst__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__clk__0))) 
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
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_rx_inst__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__clk__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_controller__DOT__uart_tx_inst__DOT__rst__0 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst;
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
    CData/*1:0*/ __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 0;
    SData/*15:0*/ __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte = 0;
    // Body
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_byte;
    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state 
        = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state;
    if (vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst) {
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 0U;
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index = 0U;
        vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx = 1U;
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte = 0U;
    } else if ((2U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state))) {
            vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx = 1U;
            if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0U;
                __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 0U;
            } else {
                __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count)));
            }
        } else {
            vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx 
                = (1U & ((IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_byte) 
                         >> (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index)));
            if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0U;
                if ((7U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index))) {
                    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index = 0U;
                    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 3U;
                } else {
                    __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index)));
                }
            } else {
                __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count)));
            }
        }
    } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state))) {
        vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx = 0U;
        if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count))) {
            __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0U;
            __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 2U;
        } else {
            __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count)));
        }
    } else {
        vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx = 1U;
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index = 0U;
        if (vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_valid) {
            __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte 
                = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_data;
            __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state = 1U;
        }
    }
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count 
        = __Vdly__uart_controller__DOT__uart_tx_inst__DOT__clk_count;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index 
        = __Vdly__uart_controller__DOT__uart_tx_inst__DOT__bit_index;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_byte 
        = __Vdly__uart_controller__DOT__uart_tx_inst__DOT__tx_byte;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state 
        = __Vdly__uart_controller__DOT__uart_tx_inst__DOT__state;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state));
    vlSelfRef.uart_controller__DOT__uart_tx_pin = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx;
    vlSelfRef.uart_tx_pin = vlSelfRef.uart_controller__DOT__uart_tx_pin;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 0;
    SData/*15:0*/ __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte = 0;
    // Body
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_byte;
    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state;
    if (vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst) {
        __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 0U;
        __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0U;
        __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index = 0U;
        vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_data = 0U;
        vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid = 0U;
        __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte = 0U;
    } else {
        vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid = 0U;
        if ((2U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state))) {
                if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count))) {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0U;
                    if (vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2) {
                        vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_data 
                            = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_byte;
                        vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid = 1U;
                    }
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 0U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count)));
                }
            } else if ((0x0363U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count))) {
                __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0U;
                __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index))) 
                        & (IData)(__Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte)) 
                       | (0x00ffU & ((IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2) 
                                     << (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index))));
                if ((7U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index))) {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index = 0U;
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 3U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index)));
                }
            } else {
                __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count)));
            }
        } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state))) {
            if ((0x01b1U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count))) {
                if (vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2) {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 0U;
                } else {
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0U;
                    __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 2U;
                }
            } else {
                __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count)));
            }
        } else {
            __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count = 0U;
            __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index = 0U;
            if ((1U & (~ (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2)))) {
                __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state = 1U;
            }
        }
    }
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count 
        = __Vdly__uart_controller__DOT__uart_rx_inst__DOT__clk_count;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index 
        = __Vdly__uart_controller__DOT__uart_rx_inst__DOT__bit_index;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_byte 
        = __Vdly__uart_controller__DOT__uart_rx_inst__DOT__rx_byte;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state 
        = __Vdly__uart_controller__DOT__uart_rx_inst__DOT__state;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state));
    vlSelfRef.uart_controller__DOT__rx_ready = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_ready;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__uart_controller__DOT__cmd_state;
    __Vdly__uart_controller__DOT__cmd_state = 0;
    CData/*2:0*/ __Vdly__uart_controller__DOT__byte_count;
    __Vdly__uart_controller__DOT__byte_count = 0;
    IData/*31:0*/ __Vdly__uart_controller__DOT__weight_buffer;
    __Vdly__uart_controller__DOT__weight_buffer = 0;
    IData/*31:0*/ __Vdly__uart_controller__DOT__act_buffer;
    __Vdly__uart_controller__DOT__act_buffer = 0;
    QData/*63:0*/ __Vdly__uart_controller__DOT__result_buffer;
    __Vdly__uart_controller__DOT__result_buffer = 0;
    CData/*0:0*/ __Vdly__uart_controller__DOT__tx_valid;
    __Vdly__uart_controller__DOT__tx_valid = 0;
    // Body
    __Vdly__uart_controller__DOT__byte_count = vlSelfRef.uart_controller__DOT__byte_count;
    __Vdly__uart_controller__DOT__weight_buffer = vlSelfRef.uart_controller__DOT__weight_buffer;
    __Vdly__uart_controller__DOT__act_buffer = vlSelfRef.uart_controller__DOT__act_buffer;
    __Vdly__uart_controller__DOT__result_buffer = vlSelfRef.uart_controller__DOT__result_buffer;
    __Vdly__uart_controller__DOT__tx_valid = vlSelfRef.uart_controller__DOT__tx_valid;
    __Vdly__uart_controller__DOT__cmd_state = vlSelfRef.uart_controller__DOT__cmd_state;
    if (vlSelfRef.uart_controller__DOT__rst) {
        __Vdly__uart_controller__DOT__cmd_state = 0U;
        vlSelfRef.uart_controller__DOT__command = 0U;
        __Vdly__uart_controller__DOT__byte_count = 0U;
        __Vdly__uart_controller__DOT__weight_buffer = 0U;
        __Vdly__uart_controller__DOT__act_buffer = 0U;
        __Vdly__uart_controller__DOT__result_buffer = 0ULL;
        vlSelfRef.uart_controller__DOT__wf_push_col0 = 0U;
        vlSelfRef.uart_controller__DOT__wf_push_col1 = 0U;
        vlSelfRef.uart_controller__DOT__wf_data_in = 0U;
        vlSelfRef.uart_controller__DOT__wf_reset = 0U;
        vlSelfRef.uart_controller__DOT__init_act_valid = 0U;
        vlSelfRef.uart_controller__DOT__init_act_data = 0U;
        vlSelfRef.uart_controller__DOT__start_mlp = 0U;
        vlSelfRef.uart_controller__DOT__weights_ready = 0U;
        __Vdly__uart_controller__DOT__tx_valid = 0U;
        vlSelfRef.uart_controller__DOT__tx_data = 0U;
    } else {
        vlSelfRef.uart_controller__DOT__wf_push_col0 = 0U;
        vlSelfRef.uart_controller__DOT__wf_push_col1 = 0U;
        vlSelfRef.uart_controller__DOT__init_act_valid = 0U;
        vlSelfRef.uart_controller__DOT__start_mlp = 0U;
        vlSelfRef.uart_controller__DOT__weights_ready = 0U;
        vlSelfRef.uart_controller__DOT__wf_reset = 0U;
        if ((8U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
            __Vdly__uart_controller__DOT__cmd_state = 0U;
        } else if ((4U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
            if ((2U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
                if ((1U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
                    __Vdly__uart_controller__DOT__cmd_state = 0U;
                } else {
                    vlSelfRef.uart_controller__DOT__weights_ready = 1U;
                    if (vlSelfRef.uart_controller__DOT__tx_ready) {
                        __Vdly__uart_controller__DOT__tx_valid = 1U;
                        vlSelfRef.uart_controller__DOT__tx_data = 0xaaU;
                    }
                    __Vdly__uart_controller__DOT__cmd_state = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
                if (vlSelfRef.uart_controller__DOT__tx_ready) {
                    if (vlSelfRef.uart_controller__DOT__tx_valid) {
                        __Vdly__uart_controller__DOT__result_buffer 
                            = (vlSelfRef.uart_controller__DOT__result_buffer 
                               >> 8U);
                        __Vdly__uart_controller__DOT__byte_count 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__byte_count)));
                        __Vdly__uart_controller__DOT__tx_valid = 0U;
                        if ((7U == (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                            __Vdly__uart_controller__DOT__cmd_state = 0U;
                        }
                    } else {
                        __Vdly__uart_controller__DOT__tx_valid = 1U;
                        vlSelfRef.uart_controller__DOT__tx_data 
                            = (0x000000ffU & (IData)(vlSelfRef.uart_controller__DOT__result_buffer));
                    }
                }
            } else if (((IData)(vlSelfRef.uart_controller__DOT__tx_ready) 
                        & (~ (IData)(vlSelfRef.uart_controller__DOT__tx_valid)))) {
                __Vdly__uart_controller__DOT__tx_valid = 1U;
                vlSelfRef.uart_controller__DOT__tx_data 
                    = (((IData)(vlSelfRef.uart_controller__DOT__layer_complete) 
                        << 4U) | (IData)(vlSelfRef.uart_controller__DOT__state_in));
                __Vdly__uart_controller__DOT__cmd_state = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
            if ((1U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
                vlSelfRef.uart_controller__DOT__start_mlp = 1U;
                if (vlSelfRef.uart_controller__DOT__tx_ready) {
                    __Vdly__uart_controller__DOT__tx_valid = 1U;
                    vlSelfRef.uart_controller__DOT__tx_data = 0xaaU;
                }
                __Vdly__uart_controller__DOT__cmd_state = 0U;
            } else if (((IData)(vlSelfRef.uart_controller__DOT__rx_valid) 
                        & (~ (IData)(vlSelfRef.uart_controller__DOT__rx_valid_prev)))) {
                __Vdly__uart_controller__DOT__act_buffer 
                    = (((IData)(vlSelfRef.uart_controller__DOT__rx_data) 
                        << 0x00000018U) | (vlSelfRef.uart_controller__DOT__act_buffer 
                                           >> 8U));
                __Vdly__uart_controller__DOT__byte_count 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__byte_count)));
                if ((1U != (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    if ((3U == (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                        vlSelfRef.uart_controller__DOT__init_act_valid = 1U;
                        vlSelfRef.uart_controller__DOT__init_act_data 
                            = (0x0000ffffU & vlSelfRef.uart_controller__DOT__act_buffer);
                    }
                }
                if ((3U == (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    if (vlSelfRef.uart_controller__DOT__tx_ready) {
                        __Vdly__uart_controller__DOT__tx_valid = 1U;
                        vlSelfRef.uart_controller__DOT__tx_data = 0xaaU;
                    }
                    __Vdly__uart_controller__DOT__cmd_state = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__cmd_state))) {
            if (((IData)(vlSelfRef.uart_controller__DOT__rx_valid) 
                 & (~ (IData)(vlSelfRef.uart_controller__DOT__rx_valid_prev)))) {
                __Vdly__uart_controller__DOT__weight_buffer 
                    = (((IData)(vlSelfRef.uart_controller__DOT__rx_data) 
                        << 0x00000018U) | (vlSelfRef.uart_controller__DOT__weight_buffer 
                                           >> 8U));
                __Vdly__uart_controller__DOT__byte_count 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_controller__DOT__byte_count)));
                if ((4U & (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    __Vdly__uart_controller__DOT__cmd_state = 0U;
                } else if ((2U & (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    if ((1U & (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                        vlSelfRef.uart_controller__DOT__wf_push_col1 = 1U;
                        vlSelfRef.uart_controller__DOT__wf_data_in 
                            = vlSelfRef.uart_controller__DOT__rx_data;
                        if (vlSelfRef.uart_controller__DOT__tx_ready) {
                            __Vdly__uart_controller__DOT__tx_valid = 1U;
                            vlSelfRef.uart_controller__DOT__tx_data = 0xaaU;
                        }
                        __Vdly__uart_controller__DOT__cmd_state = 0U;
                    } else {
                        vlSelfRef.uart_controller__DOT__wf_push_col1 = 1U;
                        vlSelfRef.uart_controller__DOT__wf_data_in 
                            = vlSelfRef.uart_controller__DOT__rx_data;
                    }
                } else if ((1U & (IData)(vlSelfRef.uart_controller__DOT__byte_count))) {
                    vlSelfRef.uart_controller__DOT__wf_push_col0 = 1U;
                    vlSelfRef.uart_controller__DOT__wf_data_in 
                        = vlSelfRef.uart_controller__DOT__rx_data;
                } else {
                    vlSelfRef.uart_controller__DOT__wf_push_col0 = 1U;
                    vlSelfRef.uart_controller__DOT__wf_data_in 
                        = vlSelfRef.uart_controller__DOT__rx_data;
                }
            }
        } else {
            __Vdly__uart_controller__DOT__tx_valid = 0U;
            __Vdly__uart_controller__DOT__byte_count = 0U;
            if (((IData)(vlSelfRef.uart_controller__DOT__rx_valid) 
                 & (~ (IData)(vlSelfRef.uart_controller__DOT__rx_valid_prev)))) {
                vlSelfRef.uart_controller__DOT__command 
                    = vlSelfRef.uart_controller__DOT__rx_data;
                if ((1U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) {
                    __Vdly__uart_controller__DOT__cmd_state = 1U;
                    vlSelfRef.uart_controller__DOT__wf_reset = 1U;
                } else if ((2U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) {
                    __Vdly__uart_controller__DOT__cmd_state = 2U;
                } else if ((3U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) {
                    __Vdly__uart_controller__DOT__cmd_state = 3U;
                } else if ((4U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) {
                    __Vdly__uart_controller__DOT__cmd_state = 4U;
                } else if ((5U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))) {
                    __Vdly__uart_controller__DOT__cmd_state = 5U;
                    __Vdly__uart_controller__DOT__result_buffer 
                        = (((QData)((IData)(vlSelfRef.uart_controller__DOT__acc1)) 
                            << 0x00000020U) | (QData)((IData)(vlSelfRef.uart_controller__DOT__acc0)));
                } else {
                    __Vdly__uart_controller__DOT__cmd_state 
                        = ((6U == (IData)(vlSelfRef.uart_controller__DOT__rx_data))
                            ? 6U : 0U);
                }
            }
        }
    }
    vlSelfRef.uart_controller__DOT__byte_count = __Vdly__uart_controller__DOT__byte_count;
    vlSelfRef.uart_controller__DOT__weight_buffer = __Vdly__uart_controller__DOT__weight_buffer;
    vlSelfRef.uart_controller__DOT__act_buffer = __Vdly__uart_controller__DOT__act_buffer;
    vlSelfRef.uart_controller__DOT__result_buffer = __Vdly__uart_controller__DOT__result_buffer;
    vlSelfRef.uart_controller__DOT__tx_valid = __Vdly__uart_controller__DOT__tx_valid;
    vlSelfRef.uart_controller__DOT__cmd_state = __Vdly__uart_controller__DOT__cmd_state;
    vlSelfRef.wf_push_col0 = vlSelfRef.uart_controller__DOT__wf_push_col0;
    vlSelfRef.wf_push_col1 = vlSelfRef.uart_controller__DOT__wf_push_col1;
    vlSelfRef.wf_data_in = vlSelfRef.uart_controller__DOT__wf_data_in;
    vlSelfRef.wf_reset = vlSelfRef.uart_controller__DOT__wf_reset;
    vlSelfRef.init_act_valid = vlSelfRef.uart_controller__DOT__init_act_valid;
    vlSelfRef.init_act_data = vlSelfRef.uart_controller__DOT__init_act_data;
    vlSelfRef.start_mlp = vlSelfRef.uart_controller__DOT__start_mlp;
    vlSelfRef.weights_ready = vlSelfRef.uart_controller__DOT__weights_ready;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_valid 
        = vlSelfRef.uart_controller__DOT__tx_valid;
    vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_data 
        = vlSelfRef.uart_controller__DOT__tx_data;
    vlSelfRef.uart_controller__DOT__debug_state = vlSelfRef.uart_controller__DOT__cmd_state;
    vlSelfRef.uart_controller__DOT__debug_cmd = vlSelfRef.uart_controller__DOT__command;
    vlSelfRef.uart_controller__DOT__rx_valid_prev = 
        ((1U & (~ (IData)(vlSelfRef.uart_controller__DOT__rst))) 
         && (IData)(vlSelfRef.uart_controller__DOT__rx_valid));
    vlSelfRef.debug_state = vlSelfRef.uart_controller__DOT__debug_state;
    vlSelfRef.debug_cmd = vlSelfRef.uart_controller__DOT__debug_cmd;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1;
    vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1 
        = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__tx_ready = vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_ready;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_controller__DOT__rx_data = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_data;
    vlSelfRef.uart_controller__DOT__rx_valid = vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid;
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/uart_controller.sv", 14, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/uart_controller.sv", 14, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/uart_controller.sv", 14, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.uart_rx_pin & 0xfeU)))) {
        Verilated::overWidthError("uart_rx_pin");
    }
    if (VL_UNLIKELY(((vlSelfRef.state_in & 0xf0U)))) {
        Verilated::overWidthError("state_in");
    }
    if (VL_UNLIKELY(((vlSelfRef.layer_complete & 0xfeU)))) {
        Verilated::overWidthError("layer_complete");
    }
}
#endif  // VL_DEBUG
