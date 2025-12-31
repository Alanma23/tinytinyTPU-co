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
    vlSelfRef.activation_pipeline__DOT__target_in = vlSelfRef.target_in;
    vlSelfRef.activation_pipeline__DOT__valid_in = vlSelfRef.valid_in;
    vlSelfRef.activation_pipeline__DOT__acc_in = vlSelfRef.acc_in;
    vlSelfRef.activation_pipeline__DOT__norm_bias = vlSelfRef.norm_bias;
    vlSelfRef.activation_pipeline__DOT__valid_out = vlSelfRef.activation_pipeline__DOT__valid_reg;
    vlSelfRef.activation_pipeline__DOT__ub_data_out 
        = vlSelfRef.activation_pipeline__DOT__ub_q_reg;
    vlSelfRef.activation_pipeline__DOT__loss_valid 
        = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_out;
    vlSelfRef.activation_pipeline__DOT__loss_out = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__loss_out;
    vlSelfRef.activation_pipeline__DOT__s1_valid = vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_out;
    vlSelfRef.activation_pipeline__DOT__s2_valid = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_out;
    vlSelfRef.activation_pipeline__DOT__q_zero_point 
        = vlSelfRef.q_zero_point;
    vlSelfRef.activation_pipeline__DOT__norm_shift 
        = vlSelfRef.norm_shift;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__target_in 
        = vlSelfRef.activation_pipeline__DOT__target_d1;
    vlSelfRef.activation_pipeline__DOT__clk = vlSelfRef.clk;
    vlSelfRef.activation_pipeline__DOT__reset = vlSelfRef.reset;
    vlSelfRef.activation_pipeline__DOT__norm_gain = vlSelfRef.norm_gain;
    vlSelfRef.activation_pipeline__DOT__s1_data = vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_out;
    vlSelfRef.activation_pipeline__DOT__q_inv_scale 
        = vlSelfRef.q_inv_scale;
    vlSelfRef.activation_pipeline__DOT__s2_data = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_out;
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_in 
        = vlSelfRef.activation_pipeline__DOT__valid_in;
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_in 
        = vlSelfRef.activation_pipeline__DOT__acc_in;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__bias 
        = vlSelfRef.activation_pipeline__DOT__norm_bias;
    vlSelfRef.valid_out = vlSelfRef.activation_pipeline__DOT__valid_out;
    vlSelfRef.ub_data_out = vlSelfRef.activation_pipeline__DOT__ub_data_out;
    vlSelfRef.loss_valid = vlSelfRef.activation_pipeline__DOT__loss_valid;
    vlSelfRef.loss_out = vlSelfRef.activation_pipeline__DOT__loss_out;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.activation_pipeline__DOT__s1_valid;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.activation_pipeline__DOT__s2_valid;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shift 
        = vlSelfRef.activation_pipeline__DOT__norm_shift;
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__clk 
        = vlSelfRef.activation_pipeline__DOT__clk;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__clk 
        = vlSelfRef.activation_pipeline__DOT__clk;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__clk 
        = vlSelfRef.activation_pipeline__DOT__clk;
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset 
        = vlSelfRef.activation_pipeline__DOT__reset;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset 
        = vlSelfRef.activation_pipeline__DOT__reset;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset 
        = vlSelfRef.activation_pipeline__DOT__reset;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__gain 
        = vlSelfRef.activation_pipeline__DOT__norm_gain;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_in 
        = vlSelfRef.activation_pipeline__DOT__s1_data;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__data_in 
        = vlSelfRef.activation_pipeline__DOT__s2_data;
    vlSelfRef.activation_pipeline__DOT__mult = (0x0000ffffffffffffULL 
                                                & VL_MULS_QQQ(48, 
                                                              (0x0000ffffffffffffULL 
                                                               & VL_EXTENDS_QI(48,32, vlSelfRef.activation_pipeline__DOT__s2_data)), 
                                                              (0x0000ffffffffffffULL 
                                                               & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.activation_pipeline__DOT__q_inv_scale)))));
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__gain)))));
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff 
        = (vlSelfRef.activation_pipeline__DOT__loss_u__DOT__data_in 
           - vlSelfRef.activation_pipeline__DOT__loss_u__DOT__target_in);
    vlSelfRef.activation_pipeline__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.activation_pipeline__DOT__mult));
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.activation_pipeline__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shift)));
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff)
            : vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff);
    vlSelfRef.activation_pipeline__DOT__scaled = (IData)(
                                                         (0x0000ffffffffffffULL 
                                                          & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.activation_pipeline__DOT__mult_rounded, 8U)));
    vlSelfRef.activation_pipeline__DOT__biased = (vlSelfRef.activation_pipeline__DOT__scaled 
                                                  + 
                                                  (((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlSelfRef.activation_pipeline__DOT__q_zero_point) 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.activation_pipeline__DOT__q_zero_point)));
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
                                                    (((((((IData)(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__reset__0))) 
                                                         << 3U) 
                                                        | (((IData)(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__loss_u__DOT__clk__0))) 
                                                           << 2U)) 
                                                       | ((((IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__reset__0))) 
                                                           << 1U) 
                                                          | ((IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__norm_u__DOT__clk__0))))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__reset__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.activation_pipeline__DOT__act_u__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__act_u__DOT__clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.activation_pipeline__DOT__reset) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__reset__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.activation_pipeline__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__activation_pipeline__DOT__clk__0))))))));
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
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset))) 
           && (IData)(vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_in));
    vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_out 
        = ((IData)(vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset)
            ? 0U : ((vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_in 
                     >> 0x1fU) ? 0U : vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_in));
    vlSelfRef.activation_pipeline__DOT__s1_valid = vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_out;
    vlSelfRef.activation_pipeline__DOT__s1_data = vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_out;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_in 
        = vlSelfRef.activation_pipeline__DOT__s1_data;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__gain)))));
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_in));
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_out 
        = ((IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset)
            ? 0U : ((IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shifted) 
                    + vlSelfRef.activation_pipeline__DOT__norm_u__DOT__bias));
    vlSelfRef.activation_pipeline__DOT__s2_data = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_out;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__data_in 
        = vlSelfRef.activation_pipeline__DOT__s2_data;
    vlSelfRef.activation_pipeline__DOT__mult = (0x0000ffffffffffffULL 
                                                & VL_MULS_QQQ(48, 
                                                              (0x0000ffffffffffffULL 
                                                               & VL_EXTENDS_QI(48,32, vlSelfRef.activation_pipeline__DOT__s2_data)), 
                                                              (0x0000ffffffffffffULL 
                                                               & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.activation_pipeline__DOT__q_inv_scale)))));
    vlSelfRef.activation_pipeline__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.activation_pipeline__DOT__mult));
    vlSelfRef.activation_pipeline__DOT__scaled = (IData)(
                                                         (0x0000ffffffffffffULL 
                                                          & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.activation_pipeline__DOT__mult_rounded, 8U)));
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__loss_out 
        = ((IData)(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset)
            ? 0U : vlSelfRef.activation_pipeline__DOT__loss_u__DOT__abs_diff);
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset))) 
           && (IData)(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_in));
    vlSelfRef.activation_pipeline__DOT__loss_out = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__loss_out;
    vlSelfRef.activation_pipeline__DOT__loss_valid 
        = vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_out;
    vlSelfRef.loss_out = vlSelfRef.activation_pipeline__DOT__loss_out;
    vlSelfRef.loss_valid = vlSelfRef.activation_pipeline__DOT__loss_valid;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_activation_pipeline__DOT__sat_int8__0__Vfuncout;
    __Vfunc_activation_pipeline__DOT__sat_int8__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_activation_pipeline__DOT__sat_int8__0__val;
    __Vfunc_activation_pipeline__DOT__sat_int8__0__val = 0;
    // Body
    vlSelfRef.activation_pipeline__DOT__valid_reg = 
        ((1U & (~ (IData)(vlSelfRef.activation_pipeline__DOT__reset))) 
         && (IData)(vlSelfRef.activation_pipeline__DOT__s2_valid));
    if (vlSelfRef.activation_pipeline__DOT__reset) {
        vlSelfRef.activation_pipeline__DOT__ub_q_reg = 0U;
        vlSelfRef.activation_pipeline__DOT__target_d1 = 0U;
    } else {
        __Vfunc_activation_pipeline__DOT__sat_int8__0__val 
            = vlSelfRef.activation_pipeline__DOT__biased;
        __Vfunc_activation_pipeline__DOT__sat_int8__0__Vfuncout 
            = (VL_LTS_III(32, 0x0000007fU, __Vfunc_activation_pipeline__DOT__sat_int8__0__val)
                ? 0x0000007fU : (VL_GTS_III(32, 0xffffff80U, __Vfunc_activation_pipeline__DOT__sat_int8__0__val)
                                  ? 0x00000080U : (0x000000ffU 
                                                   & __Vfunc_activation_pipeline__DOT__sat_int8__0__val)));
        vlSelfRef.activation_pipeline__DOT__ub_q_reg 
            = __Vfunc_activation_pipeline__DOT__sat_int8__0__Vfuncout;
        if (vlSelfRef.activation_pipeline__DOT__valid_in) {
            vlSelfRef.activation_pipeline__DOT__target_d1 
                = vlSelfRef.activation_pipeline__DOT__target_in;
        }
    }
    vlSelfRef.activation_pipeline__DOT__valid_out = vlSelfRef.activation_pipeline__DOT__valid_reg;
    vlSelfRef.activation_pipeline__DOT__ub_data_out 
        = vlSelfRef.activation_pipeline__DOT__ub_q_reg;
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__target_in 
        = vlSelfRef.activation_pipeline__DOT__target_d1;
    vlSelfRef.valid_out = vlSelfRef.activation_pipeline__DOT__valid_out;
    vlSelfRef.ub_data_out = vlSelfRef.activation_pipeline__DOT__ub_data_out;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.activation_pipeline__DOT__s1_valid;
    vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.activation_pipeline__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shift)));
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.activation_pipeline__DOT__s2_valid = vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_out;
    vlSelfRef.activation_pipeline__DOT__biased = (vlSelfRef.activation_pipeline__DOT__scaled 
                                                  + 
                                                  (((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlSelfRef.activation_pipeline__DOT__q_zero_point) 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.activation_pipeline__DOT__q_zero_point)));
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.activation_pipeline__DOT__s2_valid;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff 
        = (vlSelfRef.activation_pipeline__DOT__loss_u__DOT__data_in 
           - vlSelfRef.activation_pipeline__DOT__loss_u__DOT__target_in);
    vlSelfRef.activation_pipeline__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff)
            : vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff);
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
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000000033ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/activation_pipeline.sv", 4, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/activation_pipeline.sv", 4, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/activation_pipeline.sv", 4, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.valid_in & 0xfeU)))) {
        Verilated::overWidthError("valid_in");
    }
    if (VL_UNLIKELY(((vlSelfRef.norm_shift & 0xe0U)))) {
        Verilated::overWidthError("norm_shift");
    }
}
#endif  // VL_DEBUG
