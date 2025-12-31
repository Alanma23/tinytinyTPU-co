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
    bufp->chgBit(oldp+1,(vlSelfRef.rst));
    bufp->chgBit(oldp+2,(vlSelfRef.uart_rx_pin));
    bufp->chgBit(oldp+3,(vlSelfRef.uart_tx_pin));
    bufp->chgBit(oldp+4,(vlSelfRef.wf_push_col0));
    bufp->chgBit(oldp+5,(vlSelfRef.wf_push_col1));
    bufp->chgCData(oldp+6,(vlSelfRef.wf_data_in),8);
    bufp->chgBit(oldp+7,(vlSelfRef.wf_reset));
    bufp->chgBit(oldp+8,(vlSelfRef.init_act_valid));
    bufp->chgSData(oldp+9,(vlSelfRef.init_act_data),16);
    bufp->chgBit(oldp+10,(vlSelfRef.start_mlp));
    bufp->chgBit(oldp+11,(vlSelfRef.weights_ready));
    bufp->chgCData(oldp+12,(vlSelfRef.state_in),4);
    bufp->chgBit(oldp+13,(vlSelfRef.layer_complete));
    bufp->chgIData(oldp+14,(vlSelfRef.acc0),32);
    bufp->chgIData(oldp+15,(vlSelfRef.acc1),32);
    bufp->chgCData(oldp+16,(vlSelfRef.debug_state),8);
    bufp->chgCData(oldp+17,(vlSelfRef.debug_cmd),8);
    bufp->chgBit(oldp+18,(vlSelfRef.uart_controller__DOT__clk));
    bufp->chgBit(oldp+19,(vlSelfRef.uart_controller__DOT__rst));
    bufp->chgBit(oldp+20,(vlSelfRef.uart_controller__DOT__uart_rx_pin));
    bufp->chgBit(oldp+21,(vlSelfRef.uart_controller__DOT__uart_tx_pin));
    bufp->chgBit(oldp+22,(vlSelfRef.uart_controller__DOT__wf_push_col0));
    bufp->chgBit(oldp+23,(vlSelfRef.uart_controller__DOT__wf_push_col1));
    bufp->chgCData(oldp+24,(vlSelfRef.uart_controller__DOT__wf_data_in),8);
    bufp->chgBit(oldp+25,(vlSelfRef.uart_controller__DOT__wf_reset));
    bufp->chgBit(oldp+26,(vlSelfRef.uart_controller__DOT__init_act_valid));
    bufp->chgSData(oldp+27,(vlSelfRef.uart_controller__DOT__init_act_data),16);
    bufp->chgBit(oldp+28,(vlSelfRef.uart_controller__DOT__start_mlp));
    bufp->chgBit(oldp+29,(vlSelfRef.uart_controller__DOT__weights_ready));
    bufp->chgCData(oldp+30,(vlSelfRef.uart_controller__DOT__state_in),4);
    bufp->chgBit(oldp+31,(vlSelfRef.uart_controller__DOT__layer_complete));
    bufp->chgIData(oldp+32,(vlSelfRef.uart_controller__DOT__acc0),32);
    bufp->chgIData(oldp+33,(vlSelfRef.uart_controller__DOT__acc1),32);
    bufp->chgCData(oldp+34,(vlSelfRef.uart_controller__DOT__debug_state),8);
    bufp->chgCData(oldp+35,(vlSelfRef.uart_controller__DOT__debug_cmd),8);
    bufp->chgCData(oldp+36,(vlSelfRef.uart_controller__DOT__rx_data),8);
    bufp->chgBit(oldp+37,(vlSelfRef.uart_controller__DOT__rx_valid));
    bufp->chgBit(oldp+38,(vlSelfRef.uart_controller__DOT__rx_ready));
    bufp->chgCData(oldp+39,(vlSelfRef.uart_controller__DOT__tx_data),8);
    bufp->chgBit(oldp+40,(vlSelfRef.uart_controller__DOT__tx_valid));
    bufp->chgBit(oldp+41,(vlSelfRef.uart_controller__DOT__tx_ready));
    bufp->chgCData(oldp+42,(vlSelfRef.uart_controller__DOT__cmd_state),4);
    bufp->chgCData(oldp+43,(vlSelfRef.uart_controller__DOT__command),8);
    bufp->chgCData(oldp+44,(vlSelfRef.uart_controller__DOT__byte_count),3);
    bufp->chgIData(oldp+45,(vlSelfRef.uart_controller__DOT__weight_buffer),32);
    bufp->chgIData(oldp+46,(vlSelfRef.uart_controller__DOT__act_buffer),32);
    bufp->chgQData(oldp+47,(vlSelfRef.uart_controller__DOT__result_buffer),64);
    bufp->chgBit(oldp+49,(vlSelfRef.uart_controller__DOT__rx_valid_prev));
    bufp->chgBit(oldp+50,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk));
    bufp->chgBit(oldp+51,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rst));
    bufp->chgBit(oldp+52,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx));
    bufp->chgCData(oldp+53,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_data),8);
    bufp->chgBit(oldp+54,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_valid));
    bufp->chgBit(oldp+55,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_ready));
    bufp->chgCData(oldp+56,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__state),2);
    bufp->chgSData(oldp+57,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__clk_count),16);
    bufp->chgCData(oldp+58,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__bit_index),3);
    bufp->chgCData(oldp+59,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_byte),8);
    bufp->chgBit(oldp+60,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1));
    bufp->chgBit(oldp+61,(vlSelfRef.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2));
    bufp->chgBit(oldp+62,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk));
    bufp->chgBit(oldp+63,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__rst));
    bufp->chgBit(oldp+64,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx));
    bufp->chgCData(oldp+65,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_data),8);
    bufp->chgBit(oldp+66,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_valid));
    bufp->chgBit(oldp+67,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_ready));
    bufp->chgCData(oldp+68,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__state),2);
    bufp->chgSData(oldp+69,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__clk_count),16);
    bufp->chgCData(oldp+70,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__bit_index),3);
    bufp->chgCData(oldp+71,(vlSelfRef.uart_controller__DOT__uart_tx_inst__DOT__tx_byte),8);
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
