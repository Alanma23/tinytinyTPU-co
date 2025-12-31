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
    bufp->chgBit(oldp+3,(vlSelfRef.en_capture_col0));
    bufp->chgBit(oldp+4,(vlSelfRef.en_capture_col1));
    bufp->chgCData(oldp+5,(vlSelfRef.row0_in),8);
    bufp->chgCData(oldp+6,(vlSelfRef.row1_in),8);
    bufp->chgCData(oldp+7,(vlSelfRef.col0_in),8);
    bufp->chgCData(oldp+8,(vlSelfRef.col1_in),8);
    bufp->chgSData(oldp+9,(vlSelfRef.acc0_out),16);
    bufp->chgSData(oldp+10,(vlSelfRef.acc1_out),16);
    bufp->chgBit(oldp+11,(vlSelfRef.mmu__DOT__clk));
    bufp->chgBit(oldp+12,(vlSelfRef.mmu__DOT__reset));
    bufp->chgBit(oldp+13,(vlSelfRef.mmu__DOT__en_weight_pass));
    bufp->chgBit(oldp+14,(vlSelfRef.mmu__DOT__en_capture_col0));
    bufp->chgBit(oldp+15,(vlSelfRef.mmu__DOT__en_capture_col1));
    bufp->chgCData(oldp+16,(vlSelfRef.mmu__DOT__row0_in),8);
    bufp->chgCData(oldp+17,(vlSelfRef.mmu__DOT__row1_in),8);
    bufp->chgCData(oldp+18,(vlSelfRef.mmu__DOT__col0_in),8);
    bufp->chgCData(oldp+19,(vlSelfRef.mmu__DOT__col1_in),8);
    bufp->chgSData(oldp+20,(vlSelfRef.mmu__DOT__acc0_out),16);
    bufp->chgSData(oldp+21,(vlSelfRef.mmu__DOT__acc1_out),16);
    bufp->chgCData(oldp+22,(vlSelfRef.mmu__DOT__pe00_01_act),8);
    bufp->chgCData(oldp+23,(vlSelfRef.mmu__DOT__pe10_11_act),8);
    bufp->chgSData(oldp+24,(vlSelfRef.mmu__DOT__pe00_10_psum),16);
    bufp->chgSData(oldp+25,(vlSelfRef.mmu__DOT__pe01_11_psum),16);
    bufp->chgBit(oldp+26,(vlSelfRef.mmu__DOT__pe00__DOT__clk));
    bufp->chgBit(oldp+27,(vlSelfRef.mmu__DOT__pe00__DOT__reset));
    bufp->chgBit(oldp+28,(vlSelfRef.mmu__DOT__pe00__DOT__en_weight_pass));
    bufp->chgBit(oldp+29,(vlSelfRef.mmu__DOT__pe00__DOT__en_weight_capture));
    bufp->chgCData(oldp+30,(vlSelfRef.mmu__DOT__pe00__DOT__in_act),8);
    bufp->chgSData(oldp+31,(vlSelfRef.mmu__DOT__pe00__DOT__in_psum),16);
    bufp->chgCData(oldp+32,(vlSelfRef.mmu__DOT__pe00__DOT__out_act),8);
    bufp->chgSData(oldp+33,(vlSelfRef.mmu__DOT__pe00__DOT__out_psum),16);
    bufp->chgCData(oldp+34,(vlSelfRef.mmu__DOT__pe00__DOT__weight),8);
    bufp->chgBit(oldp+35,(vlSelfRef.mmu__DOT__pe01__DOT__clk));
    bufp->chgBit(oldp+36,(vlSelfRef.mmu__DOT__pe01__DOT__reset));
    bufp->chgBit(oldp+37,(vlSelfRef.mmu__DOT__pe01__DOT__en_weight_pass));
    bufp->chgBit(oldp+38,(vlSelfRef.mmu__DOT__pe01__DOT__en_weight_capture));
    bufp->chgCData(oldp+39,(vlSelfRef.mmu__DOT__pe01__DOT__in_act),8);
    bufp->chgSData(oldp+40,(vlSelfRef.mmu__DOT__pe01__DOT__in_psum),16);
    bufp->chgCData(oldp+41,(vlSelfRef.mmu__DOT__pe01__DOT__out_act),8);
    bufp->chgSData(oldp+42,(vlSelfRef.mmu__DOT__pe01__DOT__out_psum),16);
    bufp->chgCData(oldp+43,(vlSelfRef.mmu__DOT__pe01__DOT__weight),8);
    bufp->chgBit(oldp+44,(vlSelfRef.mmu__DOT__pe10__DOT__clk));
    bufp->chgBit(oldp+45,(vlSelfRef.mmu__DOT__pe10__DOT__reset));
    bufp->chgBit(oldp+46,(vlSelfRef.mmu__DOT__pe10__DOT__en_weight_pass));
    bufp->chgBit(oldp+47,(vlSelfRef.mmu__DOT__pe10__DOT__en_weight_capture));
    bufp->chgCData(oldp+48,(vlSelfRef.mmu__DOT__pe10__DOT__in_act),8);
    bufp->chgSData(oldp+49,(vlSelfRef.mmu__DOT__pe10__DOT__in_psum),16);
    bufp->chgCData(oldp+50,(vlSelfRef.mmu__DOT__pe10__DOT__out_act),8);
    bufp->chgSData(oldp+51,(vlSelfRef.mmu__DOT__pe10__DOT__out_psum),16);
    bufp->chgCData(oldp+52,(vlSelfRef.mmu__DOT__pe10__DOT__weight),8);
    bufp->chgBit(oldp+53,(vlSelfRef.mmu__DOT__pe11__DOT__clk));
    bufp->chgBit(oldp+54,(vlSelfRef.mmu__DOT__pe11__DOT__reset));
    bufp->chgBit(oldp+55,(vlSelfRef.mmu__DOT__pe11__DOT__en_weight_pass));
    bufp->chgBit(oldp+56,(vlSelfRef.mmu__DOT__pe11__DOT__en_weight_capture));
    bufp->chgCData(oldp+57,(vlSelfRef.mmu__DOT__pe11__DOT__in_act),8);
    bufp->chgSData(oldp+58,(vlSelfRef.mmu__DOT__pe11__DOT__in_psum),16);
    bufp->chgCData(oldp+59,(vlSelfRef.mmu__DOT__pe11__DOT__out_act),8);
    bufp->chgSData(oldp+60,(vlSelfRef.mmu__DOT__pe11__DOT__out_psum),16);
    bufp->chgCData(oldp+61,(vlSelfRef.mmu__DOT__pe11__DOT__weight),8);
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
