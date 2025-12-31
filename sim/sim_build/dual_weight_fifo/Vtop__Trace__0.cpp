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
    bufp->chgBit(oldp+2,(vlSelfRef.push_col0));
    bufp->chgBit(oldp+3,(vlSelfRef.push_col1));
    bufp->chgCData(oldp+4,(vlSelfRef.data_in),8);
    bufp->chgBit(oldp+5,(vlSelfRef.pop));
    bufp->chgCData(oldp+6,(vlSelfRef.col0_out),8);
    bufp->chgCData(oldp+7,(vlSelfRef.col1_out),8);
    bufp->chgCData(oldp+8,(vlSelfRef.col1_raw),8);
    bufp->chgBit(oldp+9,(vlSelfRef.dual_weight_fifo__DOT__clk));
    bufp->chgBit(oldp+10,(vlSelfRef.dual_weight_fifo__DOT__reset));
    bufp->chgBit(oldp+11,(vlSelfRef.dual_weight_fifo__DOT__push_col0));
    bufp->chgBit(oldp+12,(vlSelfRef.dual_weight_fifo__DOT__push_col1));
    bufp->chgCData(oldp+13,(vlSelfRef.dual_weight_fifo__DOT__data_in),8);
    bufp->chgBit(oldp+14,(vlSelfRef.dual_weight_fifo__DOT__pop));
    bufp->chgCData(oldp+15,(vlSelfRef.dual_weight_fifo__DOT__col0_out),8);
    bufp->chgCData(oldp+16,(vlSelfRef.dual_weight_fifo__DOT__col1_out),8);
    bufp->chgCData(oldp+17,(vlSelfRef.dual_weight_fifo__DOT__col1_raw),8);
    bufp->chgCData(oldp+18,(vlSelfRef.dual_weight_fifo__DOT__queue0[0]),8);
    bufp->chgCData(oldp+19,(vlSelfRef.dual_weight_fifo__DOT__queue0[1]),8);
    bufp->chgCData(oldp+20,(vlSelfRef.dual_weight_fifo__DOT__queue0[2]),8);
    bufp->chgCData(oldp+21,(vlSelfRef.dual_weight_fifo__DOT__queue0[3]),8);
    bufp->chgCData(oldp+22,(vlSelfRef.dual_weight_fifo__DOT__queue1[0]),8);
    bufp->chgCData(oldp+23,(vlSelfRef.dual_weight_fifo__DOT__queue1[1]),8);
    bufp->chgCData(oldp+24,(vlSelfRef.dual_weight_fifo__DOT__queue1[2]),8);
    bufp->chgCData(oldp+25,(vlSelfRef.dual_weight_fifo__DOT__queue1[3]),8);
    bufp->chgCData(oldp+26,(vlSelfRef.dual_weight_fifo__DOT__wr_ptr0),2);
    bufp->chgCData(oldp+27,(vlSelfRef.dual_weight_fifo__DOT__rd_ptr0),2);
    bufp->chgCData(oldp+28,(vlSelfRef.dual_weight_fifo__DOT__wr_ptr1),2);
    bufp->chgCData(oldp+29,(vlSelfRef.dual_weight_fifo__DOT__rd_ptr1),2);
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
