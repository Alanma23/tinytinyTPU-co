// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.reset));
    bufp->chgBit(oldp+2,(vlSelfRef.en_weight_pass));
    bufp->chgBit(oldp+3,(vlSelfRef.en_weight_capture));
    bufp->chgCData(oldp+4,(vlSelfRef.in_act),8);
    bufp->chgSData(oldp+5,(vlSelfRef.in_psum),16);
    bufp->chgCData(oldp+6,(vlSelfRef.out_act),8);
    bufp->chgSData(oldp+7,(vlSelfRef.out_psum),16);
    bufp->chgBit(oldp+8,(vlSelfRef.pe__DOT__clk));
    bufp->chgBit(oldp+9,(vlSelfRef.pe__DOT__reset));
    bufp->chgBit(oldp+10,(vlSelfRef.pe__DOT__en_weight_pass));
    bufp->chgBit(oldp+11,(vlSelfRef.pe__DOT__en_weight_capture));
    bufp->chgCData(oldp+12,(vlSelfRef.pe__DOT__in_act),8);
    bufp->chgSData(oldp+13,(vlSelfRef.pe__DOT__in_psum),16);
    bufp->chgCData(oldp+14,(vlSelfRef.pe__DOT__out_act),8);
    bufp->chgSData(oldp+15,(vlSelfRef.pe__DOT__out_psum),16);
    bufp->chgCData(oldp+16,(vlSelfRef.pe__DOT__weight),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
