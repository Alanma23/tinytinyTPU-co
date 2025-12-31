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
    bufp->chgIData(oldp+3,(vlSelfRef.acc_in),32);
    bufp->chgIData(oldp+4,(vlSelfRef.target_in),32);
    bufp->chgSData(oldp+5,(vlSelfRef.norm_gain),16);
    bufp->chgIData(oldp+6,(vlSelfRef.norm_bias),32);
    bufp->chgCData(oldp+7,(vlSelfRef.norm_shift),5);
    bufp->chgSData(oldp+8,(vlSelfRef.q_inv_scale),16);
    bufp->chgCData(oldp+9,(vlSelfRef.q_zero_point),8);
    bufp->chgBit(oldp+10,(vlSelfRef.valid_out));
    bufp->chgCData(oldp+11,(vlSelfRef.ub_data_out),8);
    bufp->chgBit(oldp+12,(vlSelfRef.loss_valid));
    bufp->chgIData(oldp+13,(vlSelfRef.loss_out),32);
    bufp->chgBit(oldp+14,(vlSelfRef.activation_pipeline__DOT__clk));
    bufp->chgBit(oldp+15,(vlSelfRef.activation_pipeline__DOT__reset));
    bufp->chgBit(oldp+16,(vlSelfRef.activation_pipeline__DOT__valid_in));
    bufp->chgIData(oldp+17,(vlSelfRef.activation_pipeline__DOT__acc_in),32);
    bufp->chgIData(oldp+18,(vlSelfRef.activation_pipeline__DOT__target_in),32);
    bufp->chgSData(oldp+19,(vlSelfRef.activation_pipeline__DOT__norm_gain),16);
    bufp->chgIData(oldp+20,(vlSelfRef.activation_pipeline__DOT__norm_bias),32);
    bufp->chgCData(oldp+21,(vlSelfRef.activation_pipeline__DOT__norm_shift),5);
    bufp->chgSData(oldp+22,(vlSelfRef.activation_pipeline__DOT__q_inv_scale),16);
    bufp->chgCData(oldp+23,(vlSelfRef.activation_pipeline__DOT__q_zero_point),8);
    bufp->chgBit(oldp+24,(vlSelfRef.activation_pipeline__DOT__valid_out));
    bufp->chgCData(oldp+25,(vlSelfRef.activation_pipeline__DOT__ub_data_out),8);
    bufp->chgBit(oldp+26,(vlSelfRef.activation_pipeline__DOT__loss_valid));
    bufp->chgIData(oldp+27,(vlSelfRef.activation_pipeline__DOT__loss_out),32);
    bufp->chgBit(oldp+28,(vlSelfRef.activation_pipeline__DOT__s1_valid));
    bufp->chgIData(oldp+29,(vlSelfRef.activation_pipeline__DOT__s1_data),32);
    bufp->chgIData(oldp+30,(vlSelfRef.activation_pipeline__DOT__target_d1),32);
    bufp->chgBit(oldp+31,(vlSelfRef.activation_pipeline__DOT__s2_valid));
    bufp->chgIData(oldp+32,(vlSelfRef.activation_pipeline__DOT__s2_data),32);
    bufp->chgCData(oldp+33,(vlSelfRef.activation_pipeline__DOT__ub_q_reg),8);
    bufp->chgBit(oldp+34,(vlSelfRef.activation_pipeline__DOT__valid_reg));
    bufp->chgQData(oldp+35,(vlSelfRef.activation_pipeline__DOT__mult),48);
    bufp->chgQData(oldp+37,(vlSelfRef.activation_pipeline__DOT__mult_rounded),48);
    bufp->chgIData(oldp+39,(vlSelfRef.activation_pipeline__DOT__scaled),32);
    bufp->chgIData(oldp+40,(vlSelfRef.activation_pipeline__DOT__biased),32);
    bufp->chgBit(oldp+41,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__clk));
    bufp->chgBit(oldp+42,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__reset));
    bufp->chgBit(oldp+43,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_in));
    bufp->chgIData(oldp+44,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_in),32);
    bufp->chgBit(oldp+45,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__valid_out));
    bufp->chgIData(oldp+46,(vlSelfRef.activation_pipeline__DOT__act_u__DOT__data_out),32);
    bufp->chgBit(oldp+47,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__clk));
    bufp->chgBit(oldp+48,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__reset));
    bufp->chgBit(oldp+49,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_in));
    bufp->chgIData(oldp+50,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__data_in),32);
    bufp->chgIData(oldp+51,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__target_in),32);
    bufp->chgBit(oldp+52,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__valid_out));
    bufp->chgIData(oldp+53,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__loss_out),32);
    bufp->chgIData(oldp+54,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__diff),32);
    bufp->chgIData(oldp+55,(vlSelfRef.activation_pipeline__DOT__loss_u__DOT__abs_diff),32);
    bufp->chgBit(oldp+56,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__clk));
    bufp->chgBit(oldp+57,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__reset));
    bufp->chgBit(oldp+58,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_in));
    bufp->chgIData(oldp+59,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_in),32);
    bufp->chgSData(oldp+60,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__gain),16);
    bufp->chgIData(oldp+61,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__bias),32);
    bufp->chgCData(oldp+62,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shift),5);
    bufp->chgBit(oldp+63,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__valid_out));
    bufp->chgIData(oldp+64,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__data_out),32);
    bufp->chgQData(oldp+65,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__mult),48);
    bufp->chgQData(oldp+67,(vlSelfRef.activation_pipeline__DOT__norm_u__DOT__shifted),48);
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
