// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mmu.sv", 3, "", "Settle region did not converge after 100 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge mmu.pe00.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge mmu.pe00.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge mmu.pe01.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge mmu.pe01.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge mmu.pe10.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge mmu.pe10.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge mmu.pe11.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge mmu.pe11.reset)\n");
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
    vlSelf->en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4058547300855773645ull);
    vlSelf->en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 435648995567775539ull);
    vlSelf->en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2777436732398333328ull);
    vlSelf->row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17481424823900279498ull);
    vlSelf->row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1902891028439639270ull);
    vlSelf->col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4572270913093757873ull);
    vlSelf->col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1055792873781590932ull);
    vlSelf->acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9631158962045323767ull);
    vlSelf->acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18149839520284977093ull);
    vlSelf->mmu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9307487973309690441ull);
    vlSelf->mmu__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12322198349327877887ull);
    vlSelf->mmu__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9679756560684278863ull);
    vlSelf->mmu__DOT__en_capture_col0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4371489246623641976ull);
    vlSelf->mmu__DOT__en_capture_col1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2324646789615929814ull);
    vlSelf->mmu__DOT__row0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2097595642268806088ull);
    vlSelf->mmu__DOT__row1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13391032839502590732ull);
    vlSelf->mmu__DOT__col0_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15295987841654640391ull);
    vlSelf->mmu__DOT__col1_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18294998458322453892ull);
    vlSelf->mmu__DOT__acc0_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3001300825703735265ull);
    vlSelf->mmu__DOT__acc1_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4166569768276887305ull);
    vlSelf->mmu__DOT__pe00_01_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3351663070374158762ull);
    vlSelf->mmu__DOT__pe10_11_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7212268438957971294ull);
    vlSelf->mmu__DOT__pe00_10_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1189112959098348660ull);
    vlSelf->mmu__DOT__pe01_11_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14750394988487822107ull);
    vlSelf->mmu__DOT__pe00__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7307010303595510900ull);
    vlSelf->mmu__DOT__pe00__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5553644271235537845ull);
    vlSelf->mmu__DOT__pe00__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10213255335616848034ull);
    vlSelf->mmu__DOT__pe00__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17768726869164234906ull);
    vlSelf->mmu__DOT__pe00__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14228981802546309460ull);
    vlSelf->mmu__DOT__pe00__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4309592053473070727ull);
    vlSelf->mmu__DOT__pe00__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17719615501241650469ull);
    vlSelf->mmu__DOT__pe00__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14157666291681475214ull);
    vlSelf->mmu__DOT__pe00__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11960278579618453331ull);
    vlSelf->mmu__DOT__pe01__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16699127152239296561ull);
    vlSelf->mmu__DOT__pe01__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9731109409206606700ull);
    vlSelf->mmu__DOT__pe01__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10259558468439925651ull);
    vlSelf->mmu__DOT__pe01__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17794101834013594525ull);
    vlSelf->mmu__DOT__pe01__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6283732292551074099ull);
    vlSelf->mmu__DOT__pe01__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 121565851302549878ull);
    vlSelf->mmu__DOT__pe01__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12797489805808396855ull);
    vlSelf->mmu__DOT__pe01__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6912199932000050130ull);
    vlSelf->mmu__DOT__pe01__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5968994036229514809ull);
    vlSelf->mmu__DOT__pe10__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5162690589738205168ull);
    vlSelf->mmu__DOT__pe10__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12455774404634327113ull);
    vlSelf->mmu__DOT__pe10__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14276906745813997854ull);
    vlSelf->mmu__DOT__pe10__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7217806210888462621ull);
    vlSelf->mmu__DOT__pe10__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7233081647280751909ull);
    vlSelf->mmu__DOT__pe10__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14898088232138882942ull);
    vlSelf->mmu__DOT__pe10__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8590917921035294630ull);
    vlSelf->mmu__DOT__pe10__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7772971234179280339ull);
    vlSelf->mmu__DOT__pe10__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17112898092624449132ull);
    vlSelf->mmu__DOT__pe11__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2832512282073340460ull);
    vlSelf->mmu__DOT__pe11__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4603636951607835984ull);
    vlSelf->mmu__DOT__pe11__DOT__en_weight_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18417859586386988121ull);
    vlSelf->mmu__DOT__pe11__DOT__en_weight_capture = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6366322250622896683ull);
    vlSelf->mmu__DOT__pe11__DOT__in_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 982680975688007179ull);
    vlSelf->mmu__DOT__pe11__DOT__in_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 506041793413800081ull);
    vlSelf->mmu__DOT__pe11__DOT__out_act = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 329244109347287237ull);
    vlSelf->mmu__DOT__pe11__DOT__out_psum = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8624366804848735528ull);
    vlSelf->mmu__DOT__pe11__DOT__weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1103668751699258648ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1657930251689640951ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe00__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2807767516655372517ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17892344623498519598ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe01__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6480024467384458693ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4650777484318689277ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe10__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12330237985345658876ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12150863043649418022ull);
    vlSelf->__Vtrigprevexpr___TOP__mmu__DOT__pe11__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16299268060402453218ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
