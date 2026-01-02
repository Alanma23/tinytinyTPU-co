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
    bufp->chgBit(oldp+2,(vlSelfRef.uart_rx));
    bufp->chgBit(oldp+3,(vlSelfRef.uart_tx));
    bufp->chgBit(oldp+4,(vlSelfRef.wf_push_col0));
    bufp->chgBit(oldp+5,(vlSelfRef.wf_push_col1));
    bufp->chgCData(oldp+6,(vlSelfRef.wf_data_in),8);
    bufp->chgBit(oldp+7,(vlSelfRef.wf_reset));
    bufp->chgBit(oldp+8,(vlSelfRef.init_act_valid));
    bufp->chgSData(oldp+9,(vlSelfRef.init_act_data),16);
    bufp->chgBit(oldp+10,(vlSelfRef.start_mlp));
    bufp->chgBit(oldp+11,(vlSelfRef.weights_ready));
    bufp->chgCData(oldp+12,(vlSelfRef.mlp_state),4);
    bufp->chgCData(oldp+13,(vlSelfRef.mlp_cycle_cnt),5);
    bufp->chgIData(oldp+14,(vlSelfRef.mlp_acc0),32);
    bufp->chgIData(oldp+15,(vlSelfRef.mlp_acc1),32);
    bufp->chgCData(oldp+16,(vlSelfRef.dbg_state),4);
    bufp->chgCData(oldp+17,(vlSelfRef.dbg_cmd_reg),8);
    bufp->chgCData(oldp+18,(vlSelfRef.dbg_byte_count),3);
    bufp->chgCData(oldp+19,(vlSelfRef.dbg_resp_byte_idx),2);
    bufp->chgBit(oldp+20,(vlSelfRef.dbg_tx_valid));
    bufp->chgBit(oldp+21,(vlSelfRef.dbg_tx_ready));
    bufp->chgBit(oldp+22,(vlSelfRef.dbg_rx_valid));
    bufp->chgCData(oldp+23,(vlSelfRef.dbg_rx_data),8);
    bufp->chgBit(oldp+24,(vlSelfRef.dbg_weights_ready));
    bufp->chgBit(oldp+25,(vlSelfRef.dbg_start_mlp));
    bufp->chgBit(oldp+26,(vlSelfRef.uart_controller__DOT__clk));
    bufp->chgBit(oldp+27,(vlSelfRef.uart_controller__DOT__rst));
    bufp->chgBit(oldp+28,(vlSelfRef.uart_controller__DOT__uart_rx));
    bufp->chgBit(oldp+29,(vlSelfRef.uart_controller__DOT__uart_tx));
    bufp->chgBit(oldp+30,(vlSelfRef.uart_controller__DOT__wf_push_col0));
    bufp->chgBit(oldp+31,(vlSelfRef.uart_controller__DOT__wf_push_col1));
    bufp->chgCData(oldp+32,(vlSelfRef.uart_controller__DOT__wf_data_in),8);
    bufp->chgBit(oldp+33,(vlSelfRef.uart_controller__DOT__wf_reset));
    bufp->chgBit(oldp+34,(vlSelfRef.uart_controller__DOT__init_act_valid));
    bufp->chgSData(oldp+35,(vlSelfRef.uart_controller__DOT__init_act_data),16);
    bufp->chgBit(oldp+36,(vlSelfRef.uart_controller__DOT__start_mlp));
    bufp->chgBit(oldp+37,(vlSelfRef.uart_controller__DOT__weights_ready));
    bufp->chgCData(oldp+38,(vlSelfRef.uart_controller__DOT__mlp_state),4);
    bufp->chgCData(oldp+39,(vlSelfRef.uart_controller__DOT__mlp_cycle_cnt),5);
    bufp->chgIData(oldp+40,(vlSelfRef.uart_controller__DOT__mlp_acc0),32);
    bufp->chgIData(oldp+41,(vlSelfRef.uart_controller__DOT__mlp_acc1),32);
    bufp->chgCData(oldp+42,(vlSelfRef.uart_controller__DOT__dbg_state),4);
    bufp->chgCData(oldp+43,(vlSelfRef.uart_controller__DOT__dbg_cmd_reg),8);
    bufp->chgCData(oldp+44,(vlSelfRef.uart_controller__DOT__dbg_byte_count),3);
    bufp->chgCData(oldp+45,(vlSelfRef.uart_controller__DOT__dbg_resp_byte_idx),2);
    bufp->chgBit(oldp+46,(vlSelfRef.uart_controller__DOT__dbg_tx_valid));
    bufp->chgBit(oldp+47,(vlSelfRef.uart_controller__DOT__dbg_tx_ready));
    bufp->chgBit(oldp+48,(vlSelfRef.uart_controller__DOT__dbg_rx_valid));
    bufp->chgCData(oldp+49,(vlSelfRef.uart_controller__DOT__dbg_rx_data),8);
    bufp->chgBit(oldp+50,(vlSelfRef.uart_controller__DOT__dbg_weights_ready));
    bufp->chgBit(oldp+51,(vlSelfRef.uart_controller__DOT__dbg_start_mlp));
    bufp->chgCData(oldp+52,(vlSelfRef.uart_controller__DOT__rx_data),8);
    bufp->chgBit(oldp+53,(vlSelfRef.uart_controller__DOT__rx_valid));
    bufp->chgBit(oldp+54,(vlSelfRef.uart_controller__DOT__rx_ready));
    bufp->chgCData(oldp+55,(vlSelfRef.uart_controller__DOT__tx_data),8);
    bufp->chgBit(oldp+56,(vlSelfRef.uart_controller__DOT__tx_valid));
    bufp->chgBit(oldp+57,(vlSelfRef.uart_controller__DOT__tx_ready));
    bufp->chgCData(oldp+58,(vlSelfRef.uart_controller__DOT__state),4);
    bufp->chgCData(oldp+59,(vlSelfRef.uart_controller__DOT__cmd_reg),8);
    bufp->chgCData(oldp+60,(vlSelfRef.uart_controller__DOT__byte_count),3);
    bufp->chgCData(oldp+61,(vlSelfRef.uart_controller__DOT__data_buffer[0]),8);
    bufp->chgCData(oldp+62,(vlSelfRef.uart_controller__DOT__data_buffer[1]),8);
    bufp->chgCData(oldp+63,(vlSelfRef.uart_controller__DOT__data_buffer[2]),8);
    bufp->chgCData(oldp+64,(vlSelfRef.uart_controller__DOT__data_buffer[3]),8);
    bufp->chgCData(oldp+65,(vlSelfRef.uart_controller__DOT__resp_byte_idx),2);
    bufp->chgCData(oldp+66,(vlSelfRef.uart_controller__DOT__resp_buffer[0]),8);
    bufp->chgCData(oldp+67,(vlSelfRef.uart_controller__DOT__resp_buffer[1]),8);
    bufp->chgCData(oldp+68,(vlSelfRef.uart_controller__DOT__resp_buffer[2]),8);
    bufp->chgCData(oldp+69,(vlSelfRef.uart_controller__DOT__resp_buffer[3]),8);
    bufp->chgCData(oldp+70,(vlSelfRef.uart_controller__DOT__weight_seq_idx),3);
    bufp->chgCData(oldp+71,(vlSelfRef.uart_controller__DOT__act_seq_idx),2);
    bufp->chgBit(oldp+72,(vlSelfRef.uart_controller__DOT__byte_sent));
    bufp->chgCData(oldp+73,(vlSelfRef.uart_controller__DOT__resp_delay_count),8);
    bufp->chgBit(oldp+74,(vlSelfRef.uart_controller__DOT__wf_reset_reg));
    bufp->chgBit(oldp+75,(vlSelfRef.uart_controller__DOT__weights_ready_reg));
    bufp->chgCData(oldp+76,(vlSelfRef.uart_controller__DOT__mlp_state_prev),4);
    bufp->chgBit(oldp+77,(vlSelfRef.uart_controller__DOT__wf_push_col0_reg));
    bufp->chgBit(oldp+78,(vlSelfRef.uart_controller__DOT__wf_push_col1_reg));
    bufp->chgCData(oldp+79,(vlSelfRef.uart_controller__DOT__wf_data_in_reg),8);
    bufp->chgBit(oldp+80,(vlSelfRef.uart_controller__DOT__init_act_valid_reg));
    bufp->chgSData(oldp+81,(vlSelfRef.uart_controller__DOT__init_act_data_reg),16);
    bufp->chgBit(oldp+82,(vlSelfRef.uart_controller__DOT__start_mlp_reg));
    bufp->chgBit(oldp+83,(vlSelfRef.uart_controller__DOT__tx_valid_reg));
    bufp->chgCData(oldp+84,(vlSelfRef.uart_controller__DOT__tx_data_reg),8);
    bufp->chgBit(oldp+85,(vlSelfRef.uart_controller__DOT__start_mlp_sticky));
    bufp->chgCData(oldp+86,(vlSelfRef.uart_controller__DOT__rx_data_captured),8);
    bufp->chgBit(oldp+87,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk));
    bufp->chgBit(oldp+88,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rst));
    bufp->chgBit(oldp+89,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx));
    bufp->chgCData(oldp+90,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_data),8);
    bufp->chgBit(oldp+91,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_valid));
    bufp->chgBit(oldp+92,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_ready));
    bufp->chgCData(oldp+93,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__state),2);
    bufp->chgSData(oldp+94,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__clk_count),16);
    bufp->chgCData(oldp+95,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__bit_index),3);
    bufp->chgCData(oldp+96,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_byte),8);
    bufp->chgBit(oldp+97,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_1));
    bufp->chgBit(oldp+98,(vlSelfRef.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2));
    bufp->chgBit(oldp+99,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk));
    bufp->chgBit(oldp+100,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__rst));
    bufp->chgBit(oldp+101,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx));
    bufp->chgCData(oldp+102,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_data),8);
    bufp->chgBit(oldp+103,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_valid));
    bufp->chgBit(oldp+104,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_ready));
    bufp->chgCData(oldp+105,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__state),2);
    bufp->chgSData(oldp+106,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__clk_count),16);
    bufp->chgCData(oldp+107,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__bit_index),3);
    bufp->chgCData(oldp+108,(vlSelfRef.uart_controller__DOT__uart_tx_u__DOT__tx_byte),8);
    bufp->chgIData(oldp+109,(vlSelfRef.uart_controller__DOT__unnamedblk1__DOT__i),32);
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
