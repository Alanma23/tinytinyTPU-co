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
    vlSelfRef.mmu__DOT__row0_in = vlSelfRef.row0_in;
    vlSelfRef.mmu__DOT__row1_in = vlSelfRef.row1_in;
    vlSelfRef.mmu__DOT__col0_in = vlSelfRef.col0_in;
    vlSelfRef.mmu__DOT__col1_in = vlSelfRef.col1_in;
    vlSelfRef.mmu__DOT__acc0_out = vlSelfRef.mmu__DOT__pe10__DOT__out_psum;
    vlSelfRef.mmu__DOT__acc1_out = vlSelfRef.mmu__DOT__pe11__DOT__out_psum;
    vlSelfRef.mmu__DOT__pe00_01_act = vlSelfRef.mmu__DOT__pe00__DOT__out_act;
    vlSelfRef.mmu__DOT__pe00_10_psum = vlSelfRef.mmu__DOT__pe00__DOT__out_psum;
    vlSelfRef.mmu__DOT__pe01_11_psum = vlSelfRef.mmu__DOT__pe01__DOT__out_psum;
    vlSelfRef.mmu__DOT__pe10_11_act = vlSelfRef.mmu__DOT__pe10__DOT__out_act;
    vlSelfRef.mmu__DOT__en_capture_col0 = vlSelfRef.en_capture_col0;
    vlSelfRef.mmu__DOT__en_capture_col1 = vlSelfRef.en_capture_col1;
    vlSelfRef.mmu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.mmu__DOT__reset = vlSelfRef.reset;
    vlSelfRef.mmu__DOT__en_weight_pass = vlSelfRef.en_weight_pass;
    vlSelfRef.mmu__DOT__pe00__DOT__in_act = vlSelfRef.mmu__DOT__row0_in;
    vlSelfRef.mmu__DOT__pe10__DOT__in_act = vlSelfRef.mmu__DOT__row1_in;
    vlSelfRef.mmu__DOT__pe00__DOT__in_psum = vlSelfRef.mmu__DOT__col0_in;
    vlSelfRef.mmu__DOT__pe01__DOT__in_psum = vlSelfRef.mmu__DOT__col1_in;
    vlSelfRef.acc0_out = vlSelfRef.mmu__DOT__acc0_out;
    vlSelfRef.acc1_out = vlSelfRef.mmu__DOT__acc1_out;
    vlSelfRef.mmu__DOT__pe01__DOT__in_act = vlSelfRef.mmu__DOT__pe00_01_act;
    vlSelfRef.mmu__DOT__pe10__DOT__in_psum = vlSelfRef.mmu__DOT__pe00_10_psum;
    vlSelfRef.mmu__DOT__pe11__DOT__in_psum = vlSelfRef.mmu__DOT__pe01_11_psum;
    vlSelfRef.mmu__DOT__pe11__DOT__in_act = vlSelfRef.mmu__DOT__pe10_11_act;
    vlSelfRef.mmu__DOT__pe00__DOT__en_weight_capture 
        = vlSelfRef.mmu__DOT__en_capture_col0;
    vlSelfRef.mmu__DOT__pe10__DOT__en_weight_capture 
        = vlSelfRef.mmu__DOT__en_capture_col0;
    vlSelfRef.mmu__DOT__pe01__DOT__en_weight_capture 
        = vlSelfRef.mmu__DOT__en_capture_col1;
    vlSelfRef.mmu__DOT__pe11__DOT__en_weight_capture 
        = vlSelfRef.mmu__DOT__en_capture_col1;
    vlSelfRef.mmu__DOT__pe00__DOT__clk = vlSelfRef.mmu__DOT__clk;
    vlSelfRef.mmu__DOT__pe01__DOT__clk = vlSelfRef.mmu__DOT__clk;
    vlSelfRef.mmu__DOT__pe10__DOT__clk = vlSelfRef.mmu__DOT__clk;
    vlSelfRef.mmu__DOT__pe11__DOT__clk = vlSelfRef.mmu__DOT__clk;
    vlSelfRef.mmu__DOT__pe00__DOT__reset = vlSelfRef.mmu__DOT__reset;
    vlSelfRef.mmu__DOT__pe01__DOT__reset = vlSelfRef.mmu__DOT__reset;
    vlSelfRef.mmu__DOT__pe10__DOT__reset = vlSelfRef.mmu__DOT__reset;
    vlSelfRef.mmu__DOT__pe11__DOT__reset = vlSelfRef.mmu__DOT__reset;
    vlSelfRef.mmu__DOT__pe00__DOT__en_weight_pass = vlSelfRef.mmu__DOT__en_weight_pass;
    vlSelfRef.mmu__DOT__pe01__DOT__en_weight_pass = vlSelfRef.mmu__DOT__en_weight_pass;
    vlSelfRef.mmu__DOT__pe10__DOT__en_weight_pass = vlSelfRef.mmu__DOT__en_weight_pass;
    vlSelfRef.mmu__DOT__pe11__DOT__en_weight_pass = vlSelfRef.mmu__DOT__en_weight_pass;
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
                                                    (((((((IData)(vlSelfRef.mmu__DOT__pe11__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__reset__0))) 
                                                         << 3U) 
                                                        | (((IData)(vlSelfRef.mmu__DOT__pe11__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__clk__0))) 
                                                           << 2U)) 
                                                       | ((((IData)(vlSelfRef.mmu__DOT__pe10__DOT__reset) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__reset__0))) 
                                                           << 1U) 
                                                          | ((IData)(vlSelfRef.mmu__DOT__pe10__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__clk__0))))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.mmu__DOT__pe01__DOT__reset) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__reset__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.mmu__DOT__pe01__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.mmu__DOT__pe00__DOT__reset) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__reset__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.mmu__DOT__pe00__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__clk__0 
        = vlSelfRef.mmu__DOT__pe00__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__reset__0 
        = vlSelfRef.mmu__DOT__pe00__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__clk__0 
        = vlSelfRef.mmu__DOT__pe01__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__reset__0 
        = vlSelfRef.mmu__DOT__pe01__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__clk__0 
        = vlSelfRef.mmu__DOT__pe10__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__reset__0 
        = vlSelfRef.mmu__DOT__pe10__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__clk__0 
        = vlSelfRef.mmu__DOT__pe11__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__reset__0 
        = vlSelfRef.mmu__DOT__pe11__DOT__reset;
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
    // Body
    if (vlSelfRef.mmu__DOT__pe01__DOT__reset) {
        vlSelfRef.mmu__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe01__DOT__out_psum = 0U;
        vlSelfRef.mmu__DOT__pe01__DOT__weight = 0U;
    } else if (vlSelfRef.mmu__DOT__pe01__DOT__en_weight_pass) {
        vlSelfRef.mmu__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe01__DOT__out_psum = (0x0000ffffU 
                                                   & (IData)(vlSelfRef.mmu__DOT__pe01__DOT__in_psum));
        if (vlSelfRef.mmu__DOT__pe01__DOT__en_weight_capture) {
            vlSelfRef.mmu__DOT__pe01__DOT__weight = 
                (0x000000ffU & (IData)(vlSelfRef.mmu__DOT__pe01__DOT__in_psum));
        }
    } else {
        vlSelfRef.mmu__DOT__pe01__DOT__out_act = vlSelfRef.mmu__DOT__pe01__DOT__in_act;
        vlSelfRef.mmu__DOT__pe01__DOT__out_psum = (0x0000ffffU 
                                                   & (((IData)(vlSelfRef.mmu__DOT__pe01__DOT__in_act) 
                                                       * (IData)(vlSelfRef.mmu__DOT__pe01__DOT__weight)) 
                                                      + (IData)(vlSelfRef.mmu__DOT__pe01__DOT__in_psum)));
    }
    vlSelfRef.mmu__DOT__pe01_11_psum = vlSelfRef.mmu__DOT__pe01__DOT__out_psum;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mmu__DOT__pe11__DOT__reset) {
        vlSelfRef.mmu__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe11__DOT__out_psum = 0U;
        vlSelfRef.mmu__DOT__pe11__DOT__weight = 0U;
    } else if (vlSelfRef.mmu__DOT__pe11__DOT__en_weight_pass) {
        vlSelfRef.mmu__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe11__DOT__out_psum = (0x0000ffffU 
                                                   & (IData)(vlSelfRef.mmu__DOT__pe11__DOT__in_psum));
        if (vlSelfRef.mmu__DOT__pe11__DOT__en_weight_capture) {
            vlSelfRef.mmu__DOT__pe11__DOT__weight = 
                (0x000000ffU & (IData)(vlSelfRef.mmu__DOT__pe11__DOT__in_psum));
        }
    } else {
        vlSelfRef.mmu__DOT__pe11__DOT__out_act = vlSelfRef.mmu__DOT__pe11__DOT__in_act;
        vlSelfRef.mmu__DOT__pe11__DOT__out_psum = (0x0000ffffU 
                                                   & (((IData)(vlSelfRef.mmu__DOT__pe11__DOT__in_act) 
                                                       * (IData)(vlSelfRef.mmu__DOT__pe11__DOT__weight)) 
                                                      + (IData)(vlSelfRef.mmu__DOT__pe11__DOT__in_psum)));
    }
    vlSelfRef.mmu__DOT__acc1_out = vlSelfRef.mmu__DOT__pe11__DOT__out_psum;
    vlSelfRef.acc1_out = vlSelfRef.mmu__DOT__acc1_out;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mmu__DOT__pe00__DOT__reset) {
        vlSelfRef.mmu__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe00__DOT__out_psum = 0U;
        vlSelfRef.mmu__DOT__pe00__DOT__weight = 0U;
    } else if (vlSelfRef.mmu__DOT__pe00__DOT__en_weight_pass) {
        vlSelfRef.mmu__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe00__DOT__out_psum = (0x0000ffffU 
                                                   & (IData)(vlSelfRef.mmu__DOT__pe00__DOT__in_psum));
        if (vlSelfRef.mmu__DOT__pe00__DOT__en_weight_capture) {
            vlSelfRef.mmu__DOT__pe00__DOT__weight = 
                (0x000000ffU & (IData)(vlSelfRef.mmu__DOT__pe00__DOT__in_psum));
        }
    } else {
        vlSelfRef.mmu__DOT__pe00__DOT__out_act = vlSelfRef.mmu__DOT__pe00__DOT__in_act;
        vlSelfRef.mmu__DOT__pe00__DOT__out_psum = (0x0000ffffU 
                                                   & (((IData)(vlSelfRef.mmu__DOT__pe00__DOT__in_act) 
                                                       * (IData)(vlSelfRef.mmu__DOT__pe00__DOT__weight)) 
                                                      + (IData)(vlSelfRef.mmu__DOT__pe00__DOT__in_psum)));
    }
    vlSelfRef.mmu__DOT__pe00_01_act = vlSelfRef.mmu__DOT__pe00__DOT__out_act;
    vlSelfRef.mmu__DOT__pe00_10_psum = vlSelfRef.mmu__DOT__pe00__DOT__out_psum;
    vlSelfRef.mmu__DOT__pe01__DOT__in_act = vlSelfRef.mmu__DOT__pe00_01_act;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mmu__DOT__pe10__DOT__reset) {
        vlSelfRef.mmu__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe10__DOT__out_psum = 0U;
        vlSelfRef.mmu__DOT__pe10__DOT__weight = 0U;
    } else if (vlSelfRef.mmu__DOT__pe10__DOT__en_weight_pass) {
        vlSelfRef.mmu__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.mmu__DOT__pe10__DOT__out_psum = (0x0000ffffU 
                                                   & (IData)(vlSelfRef.mmu__DOT__pe10__DOT__in_psum));
        if (vlSelfRef.mmu__DOT__pe10__DOT__en_weight_capture) {
            vlSelfRef.mmu__DOT__pe10__DOT__weight = 
                (0x000000ffU & (IData)(vlSelfRef.mmu__DOT__pe10__DOT__in_psum));
        }
    } else {
        vlSelfRef.mmu__DOT__pe10__DOT__out_act = vlSelfRef.mmu__DOT__pe10__DOT__in_act;
        vlSelfRef.mmu__DOT__pe10__DOT__out_psum = (0x0000ffffU 
                                                   & (((IData)(vlSelfRef.mmu__DOT__pe10__DOT__in_act) 
                                                       * (IData)(vlSelfRef.mmu__DOT__pe10__DOT__weight)) 
                                                      + (IData)(vlSelfRef.mmu__DOT__pe10__DOT__in_psum)));
    }
    vlSelfRef.mmu__DOT__pe10_11_act = vlSelfRef.mmu__DOT__pe10__DOT__out_act;
    vlSelfRef.mmu__DOT__acc0_out = vlSelfRef.mmu__DOT__pe10__DOT__out_psum;
    vlSelfRef.mmu__DOT__pe11__DOT__in_act = vlSelfRef.mmu__DOT__pe10_11_act;
    vlSelfRef.acc0_out = vlSelfRef.mmu__DOT__acc0_out;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mmu__DOT__pe11__DOT__in_psum = vlSelfRef.mmu__DOT__pe01_11_psum;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mmu__DOT__pe10__DOT__in_psum = vlSelfRef.mmu__DOT__pe00_10_psum;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mmu.sv", 3, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mmu.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mmu.sv", 3, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.en_weight_pass & 0xfeU)))) {
        Verilated::overWidthError("en_weight_pass");
    }
    if (VL_UNLIKELY(((vlSelfRef.en_capture_col0 & 0xfeU)))) {
        Verilated::overWidthError("en_capture_col0");
    }
    if (VL_UNLIKELY(((vlSelfRef.en_capture_col1 & 0xfeU)))) {
        Verilated::overWidthError("en_capture_col1");
    }
}
#endif  // VL_DEBUG
