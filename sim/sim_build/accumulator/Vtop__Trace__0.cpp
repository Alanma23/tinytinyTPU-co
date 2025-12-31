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
    bufp->chgBit(oldp+2,(vlSelfRef.valid_in));
    bufp->chgBit(oldp+3,(vlSelfRef.accumulator_enable));
    bufp->chgBit(oldp+4,(vlSelfRef.addr_sel));
    bufp->chgSData(oldp+5,(vlSelfRef.mmu_col0_in),16);
    bufp->chgSData(oldp+6,(vlSelfRef.mmu_col1_in),16);
    bufp->chgIData(oldp+7,(vlSelfRef.acc_col0_out),32);
    bufp->chgIData(oldp+8,(vlSelfRef.acc_col1_out),32);
    bufp->chgBit(oldp+9,(vlSelfRef.valid_out));
    bufp->chgBit(oldp+10,(vlSelfRef.accumulator__DOT__clk));
    bufp->chgBit(oldp+11,(vlSelfRef.accumulator__DOT__reset));
    bufp->chgBit(oldp+12,(vlSelfRef.accumulator__DOT__valid_in));
    bufp->chgBit(oldp+13,(vlSelfRef.accumulator__DOT__accumulator_enable));
    bufp->chgBit(oldp+14,(vlSelfRef.accumulator__DOT__addr_sel));
    bufp->chgSData(oldp+15,(vlSelfRef.accumulator__DOT__mmu_col0_in),16);
    bufp->chgSData(oldp+16,(vlSelfRef.accumulator__DOT__mmu_col1_in),16);
    bufp->chgIData(oldp+17,(vlSelfRef.accumulator__DOT__acc_col0_out),32);
    bufp->chgIData(oldp+18,(vlSelfRef.accumulator__DOT__acc_col1_out),32);
    bufp->chgBit(oldp+19,(vlSelfRef.accumulator__DOT__valid_out));
    bufp->chgBit(oldp+20,(vlSelfRef.accumulator__DOT__aligned_valid));
    bufp->chgSData(oldp+21,(vlSelfRef.accumulator__DOT__aligned_c0),16);
    bufp->chgSData(oldp+22,(vlSelfRef.accumulator__DOT__aligned_c1),16);
    bufp->chgBit(oldp+23,(vlSelfRef.accumulator__DOT__u_align__DOT__clk));
    bufp->chgBit(oldp+24,(vlSelfRef.accumulator__DOT__u_align__DOT__reset));
    bufp->chgBit(oldp+25,(vlSelfRef.accumulator__DOT__u_align__DOT__valid_in));
    bufp->chgSData(oldp+26,(vlSelfRef.accumulator__DOT__u_align__DOT__raw_col0),16);
    bufp->chgSData(oldp+27,(vlSelfRef.accumulator__DOT__u_align__DOT__raw_col1),16);
    bufp->chgBit(oldp+28,(vlSelfRef.accumulator__DOT__u_align__DOT__aligned_valid));
    bufp->chgSData(oldp+29,(vlSelfRef.accumulator__DOT__u_align__DOT__align_col0),16);
    bufp->chgSData(oldp+30,(vlSelfRef.accumulator__DOT__u_align__DOT__align_col1),16);
    bufp->chgSData(oldp+31,(vlSelfRef.accumulator__DOT__u_align__DOT__col0_delay_reg),16);
    bufp->chgBit(oldp+32,(vlSelfRef.accumulator__DOT__u_align__DOT__pending));
    bufp->chgBit(oldp+33,(vlSelfRef.accumulator__DOT__u_mem__DOT__clk));
    bufp->chgBit(oldp+34,(vlSelfRef.accumulator__DOT__u_mem__DOT__reset));
    bufp->chgBit(oldp+35,(vlSelfRef.accumulator__DOT__u_mem__DOT__enable));
    bufp->chgBit(oldp+36,(vlSelfRef.accumulator__DOT__u_mem__DOT__accumulator_mode));
    bufp->chgBit(oldp+37,(vlSelfRef.accumulator__DOT__u_mem__DOT__buffer_select));
    bufp->chgSData(oldp+38,(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col0),16);
    bufp->chgSData(oldp+39,(vlSelfRef.accumulator__DOT__u_mem__DOT__in_col1),16);
    bufp->chgBit(oldp+40,(vlSelfRef.accumulator__DOT__u_mem__DOT__valid_out));
    bufp->chgIData(oldp+41,(vlSelfRef.accumulator__DOT__u_mem__DOT__out_col0),32);
    bufp->chgIData(oldp+42,(vlSelfRef.accumulator__DOT__u_mem__DOT__out_col1),32);
    bufp->chgIData(oldp+43,(vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col0),32);
    bufp->chgIData(oldp+44,(vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff0_col1),32);
    bufp->chgIData(oldp+45,(vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col0),32);
    bufp->chgIData(oldp+46,(vlSelfRef.accumulator__DOT__u_mem__DOT__mem_buff1_col1),32);
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
