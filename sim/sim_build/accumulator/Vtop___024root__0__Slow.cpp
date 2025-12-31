// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__clk__0 
        = vlSelfRef.accumulator__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__reset__0 
        = vlSelfRef.accumulator__DOT__u_align__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__reset__0 
        = vlSelfRef.accumulator__DOT__u_mem__DOT__reset;
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator.sv", 3, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge accumulator.u_align.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge accumulator.u_align.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge accumulator.u_mem.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge accumulator.u_mem.reset)\n");
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
    vlSelf->accumulator_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18169724705561643961ull);
    vlSelf->addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3716668187679048237ull);
    vlSelf->mmu_col0_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18442836150499141851ull);
    vlSelf->mmu_col1_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2898323492639485052ull);
    vlSelf->acc_col0_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6950295488610104446ull);
    vlSelf->acc_col1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 979590136068759007ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->accumulator__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15930394022981458994ull);
    vlSelf->accumulator__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12433369497547623144ull);
    vlSelf->accumulator__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3037482597952132398ull);
    vlSelf->accumulator__DOT__accumulator_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9451625031778794680ull);
    vlSelf->accumulator__DOT__addr_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10282846681558777972ull);
    vlSelf->accumulator__DOT__mmu_col0_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11727485664926096313ull);
    vlSelf->accumulator__DOT__mmu_col1_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11965939697537610046ull);
    vlSelf->accumulator__DOT__acc_col0_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15799051983082039523ull);
    vlSelf->accumulator__DOT__acc_col1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3117833990944736353ull);
    vlSelf->accumulator__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5922111488862174350ull);
    vlSelf->accumulator__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14680889091134721717ull);
    vlSelf->accumulator__DOT__aligned_c0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5057845496950756345ull);
    vlSelf->accumulator__DOT__aligned_c1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13525747608188977109ull);
    vlSelf->accumulator__DOT__u_align__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8347890527751062026ull);
    vlSelf->accumulator__DOT__u_align__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11101625803384849966ull);
    vlSelf->accumulator__DOT__u_align__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1005296519193817164ull);
    vlSelf->accumulator__DOT__u_align__DOT__raw_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4745430685318261137ull);
    vlSelf->accumulator__DOT__u_align__DOT__raw_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4948757088538835124ull);
    vlSelf->accumulator__DOT__u_align__DOT__aligned_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10023139321949387033ull);
    vlSelf->accumulator__DOT__u_align__DOT__align_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12811669356508130383ull);
    vlSelf->accumulator__DOT__u_align__DOT__align_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3134059625460914810ull);
    vlSelf->accumulator__DOT__u_align__DOT__col0_delay_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4592891177786862798ull);
    vlSelf->accumulator__DOT__u_align__DOT__pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16667869851762554878ull);
    vlSelf->accumulator__DOT__u_mem__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16028648462483752251ull);
    vlSelf->accumulator__DOT__u_mem__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8174671234341661029ull);
    vlSelf->accumulator__DOT__u_mem__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2060469991216574222ull);
    vlSelf->accumulator__DOT__u_mem__DOT__accumulator_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10377650388032888860ull);
    vlSelf->accumulator__DOT__u_mem__DOT__buffer_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12636015819473909245ull);
    vlSelf->accumulator__DOT__u_mem__DOT__in_col0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1459761024165244141ull);
    vlSelf->accumulator__DOT__u_mem__DOT__in_col1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3725341218165414197ull);
    vlSelf->accumulator__DOT__u_mem__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17979455410998978581ull);
    vlSelf->accumulator__DOT__u_mem__DOT__out_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9076810669399599434ull);
    vlSelf->accumulator__DOT__u_mem__DOT__out_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3729114973630401065ull);
    vlSelf->accumulator__DOT__u_mem__DOT__mem_buff0_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2242391770343501627ull);
    vlSelf->accumulator__DOT__u_mem__DOT__mem_buff0_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7726518514754267980ull);
    vlSelf->accumulator__DOT__u_mem__DOT__mem_buff1_col0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6472500646044427164ull);
    vlSelf->accumulator__DOT__u_mem__DOT__mem_buff1_col1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3187577023274029584ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9818290877479658070ull);
    vlSelf->__Vtrigprevexpr___TOP__accumulator__DOT__u_align__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6710015594603795378ull);
    vlSelf->__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1337482853446784504ull);
    vlSelf->__Vtrigprevexpr___TOP__accumulator__DOT__u_mem__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4907833570553399665ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
