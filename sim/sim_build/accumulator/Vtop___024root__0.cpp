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
    vlSelfRef.accumulator__DOT__valid_in = vlSelfRef.valid_in;
    vlSelfRef.accumulator__DOT__accumulator_enable 
        = vlSelfRef.accumulator_enable;
    vlSelfRef.accumulator__DOT__addr_sel = vlSelfRef.addr_sel;
    vlSelfRef.accumulator__DOT__mmu_col0_in = vlSelfRef.mmu_col0_in;
    vlSelfRef.accumulator__DOT__mmu_col1_in = vlSelfRef.mmu_col1_in;
    vlSelfRef.accumulator__DOT__acc_col0_out = vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0;
    vlSelfRef.accumulator__DOT__acc_col1_out = vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1;
    vlSelfRef.accumulator__DOT__valid_out = vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out;
    vlSelfRef.accumulator__DOT__aligned_valid = vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.accumulator__DOT__aligned_c0 = vlSelfRef.accumulator__DOT__u_align__DOT__align_col0;
    vlSelfRef.accumulator__DOT__aligned_c1 = vlSelfRef.accumulator__DOT__u_align__DOT__align_col1;
    vlSelfRef.accumulator__DOT__clk = vlSelfRef.clk;
    vlSelfRef.accumulator__DOT__reset = vlSelfRef.reset;
    vlSelfRef.accumulator__DOT__u_align__DOT__valid_in 
        = vlSelfRef.accumulator__DOT__valid_in;
    vlSelfRef.accumulator__DOT__u_mem__DOT__accumulator_mode 
        = vlSelfRef.accumulator__DOT__accumulator_enable;
    vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select 
        = vlSelfRef.accumulator__DOT__addr_sel;
    vlSelfRef.accumulator__DOT__u_align__DOT__raw_col0 
        = vlSelfRef.accumulator__DOT__mmu_col0_in;
    vlSelfRef.accumulator__DOT__u_align__DOT__raw_col1 
        = vlSelfRef.accumulator__DOT__mmu_col1_in;
    vlSelfRef.acc_col0_out = vlSelfRef.accumulator__DOT__acc_col0_out;
    vlSelfRef.acc_col1_out = vlSelfRef.accumulator__DOT__acc_col1_out;
    vlSelfRef.valid_out = vlSelfRef.accumulator__DOT__valid_out;
    vlSelfRef.accumulator__DOT__u_mem__DOT__enable 
        = vlSelfRef.accumulator__DOT__aligned_valid;
    vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.accumulator__DOT__aligned_c0;
    vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.accumulator__DOT__aligned_c1;
    vlSelfRef.accumulator__DOT__u_align__DOT__clk = vlSelfRef.accumulator__DOT__clk;
    vlSelfRef.accumulator__DOT__u_mem__DOT__clk = vlSelfRef.accumulator__DOT__clk;
    vlSelfRef.accumulator__DOT__u_align__DOT__reset 
        = vlSelfRef.accumulator__DOT__reset;
    vlSelfRef.accumulator__DOT__u_mem__DOT__reset = vlSelfRef.accumulator__DOT__reset;
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
                                                    (((((IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__reset) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__reset__0))) 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__clk__0))) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.accumulator__DOT__u_align__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__reset__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.accumulator__DOT__u_align__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__clk__0 
        = vlSelfRef.accumulator__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__reset__0 
        = vlSelfRef.accumulator__DOT__u_align__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__reset__0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__reset;
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
    SData/*15:0*/ __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg = 0;
    CData/*0:0*/ __Vdly__accumulator__DOT__u_align__DOT__pending;
    __Vdly__accumulator__DOT__u_align__DOT__pending = 0;
    // Body
    __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg 
        = vlSelfRef.accumulator__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__accumulator__DOT__u_align__DOT__pending 
        = vlSelfRef.accumulator__DOT__u_align__DOT__pending;
    if (vlSelfRef.accumulator__DOT__u_align__DOT__reset) {
        __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg = 0U;
        __Vdly__accumulator__DOT__u_align__DOT__pending = 0U;
        vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid = 0U;
        vlSelfRef.accumulator__DOT__u_align__DOT__align_col0 = 0U;
        vlSelfRef.accumulator__DOT__u_align__DOT__align_col1 = 0U;
    } else {
        vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid = 0U;
        if (vlSelfRef.accumulator__DOT__u_align__DOT__valid_in) {
            if (vlSelfRef.accumulator__DOT__u_align__DOT__pending) {
                vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid = 1U;
                vlSelfRef.accumulator__DOT__u_align__DOT__align_col0 
                    = vlSelfRef.accumulator__DOT__u_align__DOT__col0_delay_reg;
                vlSelfRef.accumulator__DOT__u_align__DOT__align_col1 
                    = vlSelfRef.accumulator__DOT__u_align__DOT__raw_col1;
                __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.accumulator__DOT__u_align__DOT__raw_col0;
            } else {
                __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.accumulator__DOT__u_align__DOT__raw_col0;
                __Vdly__accumulator__DOT__u_align__DOT__pending = 1U;
            }
        } else {
            __Vdly__accumulator__DOT__u_align__DOT__pending = 0U;
        }
    }
    vlSelfRef.accumulator__DOT__u_align__DOT__col0_delay_reg 
        = __Vdly__accumulator__DOT__u_align__DOT__col0_delay_reg;
    vlSelfRef.accumulator__DOT__u_align__DOT__pending 
        = __Vdly__accumulator__DOT__u_align__DOT__pending;
    vlSelfRef.accumulator__DOT__aligned_valid = vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.accumulator__DOT__aligned_c0 = vlSelfRef.accumulator__DOT__u_align__DOT__align_col0;
    vlSelfRef.accumulator__DOT__aligned_c1 = vlSelfRef.accumulator__DOT__u_align__DOT__align_col1;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0 = 0;
    IData/*31:0*/ __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1 = 0;
    IData/*31:0*/ __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0 = 0;
    IData/*31:0*/ __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1 = 0;
    // Body
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col1;
    if (vlSelfRef.accumulator__DOT__u_mem__DOT__reset) {
        vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out = 0U;
        vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0 = 0U;
        vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1 = 0U;
        __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0 = 0U;
        __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1 = 0U;
        __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0 = 0U;
        __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1 = 0U;
    } else if (vlSelfRef.accumulator__DOT__u_mem__DOT__enable) {
        if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select) 
                                   << 1U) | (1U & (~ (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select)))))))) {
            if ((0U == (((IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select) 
                         << 1U) | (1U & (~ (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Naccumulator.u_mem: unique case, but none matched for '1'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 1,(IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select));
                    VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator_mem.sv", 39, "");
                }
            } else if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Naccumulator.u_mem: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select));
                VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator_mem.sv", 39, "");
            }
        }
        if (vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select) {
            if (vlSelfRef.accumulator__DOT__u_mem__DOT__accumulator_mode) {
                __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0 
                    = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0));
                __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1 
                    = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1));
                vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0 
                    = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0));
                vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1 
                    = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1));
            } else {
                __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0 
                    = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0;
                __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1 
                    = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1;
                vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0 
                    = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0;
                vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1 
                    = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1;
            }
        } else if (vlSelfRef.accumulator__DOT__u_mem__DOT__accumulator_mode) {
            __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0 
                = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0));
            __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1 
                = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1));
            vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0 
                = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0));
            vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1 
                = (vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1));
        } else {
            __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0 
                = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0;
            __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1 
                = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1;
            vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0 
                = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0;
            vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1 
                = vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1;
        }
        vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out = 1U;
    } else {
        vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out = 0U;
    }
    vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col0 
        = __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col0;
    vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col1 
        = __Vdly__accumulator__DOT__u_mem__DOT__mem_buff0_col1;
    vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col0 
        = __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col0;
    vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col1 
        = __Vdly__accumulator__DOT__u_mem__DOT__mem_buff1_col1;
    vlSelfRef.accumulator__DOT__valid_out = vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out;
    vlSelfRef.accumulator__DOT__acc_col0_out = vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0;
    vlSelfRef.accumulator__DOT__acc_col1_out = vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1;
    vlSelfRef.valid_out = vlSelfRef.accumulator__DOT__valid_out;
    vlSelfRef.acc_col0_out = vlSelfRef.accumulator__DOT__acc_col0_out;
    vlSelfRef.acc_col1_out = vlSelfRef.accumulator__DOT__acc_col1_out;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.accumulator__DOT__u_mem__DOT__enable 
        = vlSelfRef.accumulator__DOT__aligned_valid;
    vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.accumulator__DOT__aligned_c0;
    vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.accumulator__DOT__aligned_c1;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator.sv", 3, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator.sv", 3, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.accumulator_enable 
                      & 0xfeU)))) {
        Verilated::overWidthError("accumulator_enable");
    }
    if (VL_UNLIKELY(((vlSelfRef.addr_sel & 0xfeU)))) {
        Verilated::overWidthError("addr_sel");
    }
}
#endif  // VL_DEBUG
