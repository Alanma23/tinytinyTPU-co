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
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__loss_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__loss_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_comb 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_comb 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr];
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_01_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_10_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01_11_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10_11_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__accumulator_enable 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__addr_sel 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__addr_sel;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_data_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_q_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_data_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_q_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_raw 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1];
    vlSelfRef.tpu_top__DOT__uart_rx = vlSelfRef.uart_rx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx;
    vlSelfRef.tpu_top__DOT__mlp_layer_complete_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__target_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_d1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__target_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_d1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_state 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_cmd_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_byte_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_resp_byte_idx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data_captured;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_weights_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_start_mlp 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky;
    vlSelfRef.tpu_top__DOT__mlp_q_inv_scale = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_q_inv_scale;
    vlSelfRef.tpu_top__DOT__mlp_q_zero_point = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_q_zero_point;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__full 
        = (0x10U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__full 
        = (0x10U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count));
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state));
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg;
    vlSelfRef.tpu_top__DOT__mlp_norm_gain = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_norm_bias = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_norm_shift = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__state = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt = vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__transfer_phase 
        = (5U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase 
        = (3U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase 
        = (4U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight 
        = (1U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.tpu_top__DOT__rst = vlSelfRef.rst;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_01_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_10_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01_11_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10_11_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__accumulator_enable;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__addr_sel;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__enable 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_valid = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_raw 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_raw;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx 
        = vlSelfRef.tpu_top__DOT__uart_rx;
    vlSelfRef.tpu_top__DOT__uart_tx = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx;
    vlSelfRef.tpu_top__DOT__mlp_layer_complete_dbg 
        = vlSelfRef.tpu_top__DOT__mlp_layer_complete_out;
    vlSelfRef.tpu_top__DOT__mlp_current_layer_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer;
    vlSelfRef.tpu_top__DOT__uart_state_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_state;
    vlSelfRef.tpu_top__DOT__uart_cmd_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_cmd_reg;
    vlSelfRef.tpu_top__DOT__uart_byte_cnt_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_byte_count;
    vlSelfRef.tpu_top__DOT__uart_resp_idx_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_resp_byte_idx;
    vlSelfRef.tpu_top__DOT__uart_tx_valid_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_valid;
    vlSelfRef.tpu_top__DOT__uart_rx_data_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_data;
    vlSelfRef.tpu_top__DOT__uart_weights_ready_int 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_weights_ready;
    vlSelfRef.tpu_top__DOT__uart_start_mlp_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_inv_scale 
        = vlSelfRef.tpu_top__DOT__mlp_q_inv_scale;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_zero_point 
        = vlSelfRef.tpu_top__DOT__mlp_q_zero_point;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__full)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__full)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_empty 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_empty 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_ready;
    vlSelfRef.tpu_top__DOT__weights_ready = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready;
    vlSelfRef.tpu_top__DOT__start_mlp = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_gain = vlSelfRef.tpu_top__DOT__mlp_norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_bias = vlSelfRef.tpu_top__DOT__mlp_norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_shift 
        = vlSelfRef.tpu_top__DOT__mlp_norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1 = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col1_out;
    vlSelfRef.tpu_top__DOT__wf_push_col0 = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__wf_push_col1 = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__wf_data_in = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid;
    vlSelfRef.tpu_top__DOT__wf_reset = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset;
    vlSelfRef.tpu_top__DOT__mlp_state_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data;
    vlSelfRef.tpu_top__DOT__init_act_data = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0 = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready = 0U;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__row1_skew_reg;
        if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select)))) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready = 1U;
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready = 1U;
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in = 0U;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_valid = 
        (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase) 
          & (2U <= (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) 
         | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase) 
           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__transfer_phase));
    vlSelfRef.tpu_top__DOT__init_act_valid = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__pop = 1U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_out;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col0_out;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col0 
            = (1U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col1 
            = (2U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass = 1U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__pop = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass = 0U;
    }
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__clk = vlSelfRef.tpu_top__DOT__clk;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk = vlSelfRef.tpu_top__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk = vlSelfRef.tpu_top__DOT__clk;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rst = vlSelfRef.tpu_top__DOT__rst;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset = vlSelfRef.tpu_top__DOT__rst;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx;
    vlSelfRef.uart_tx = vlSelfRef.tpu_top__DOT__uart_tx;
    vlSelfRef.mlp_layer_complete_dbg = vlSelfRef.tpu_top__DOT__mlp_layer_complete_dbg;
    vlSelfRef.tpu_top__DOT__mlp_layer_dbg = vlSelfRef.tpu_top__DOT__mlp_current_layer_out;
    vlSelfRef.tpu_top__DOT__uart_state_dbg = vlSelfRef.tpu_top__DOT__uart_state_int;
    vlSelfRef.tpu_top__DOT__uart_cmd_dbg = vlSelfRef.tpu_top__DOT__uart_cmd_int;
    vlSelfRef.tpu_top__DOT__uart_byte_count_dbg = vlSelfRef.tpu_top__DOT__uart_byte_cnt_int;
    vlSelfRef.tpu_top__DOT__uart_resp_idx_dbg = vlSelfRef.tpu_top__DOT__uart_resp_idx_int;
    vlSelfRef.tpu_top__DOT__uart_tx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_tx_valid_int;
    vlSelfRef.tpu_top__DOT__uart_rx_data_dbg = vlSelfRef.tpu_top__DOT__uart_rx_data_int;
    vlSelfRef.tpu_top__DOT__uart_weights_ready_dbg 
        = vlSelfRef.tpu_top__DOT__uart_weights_ready_int;
    vlSelfRef.tpu_top__DOT__uart_start_mlp_dbg = vlSelfRef.tpu_top__DOT__uart_start_mlp_int;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_inv_scale;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_inv_scale;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_zero_point;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__q_zero_point;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff 
        = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__data_in 
           - vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__target_in);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff 
        = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__data_in 
           - vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__target_in);
    vlSelfRef.tpu_top__DOT__uart_rx_valid_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_valid;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_empty 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_empty;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_valid;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_data;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_empty 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_empty;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_valid;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_data;
    }
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_weights_ready 
        = vlSelfRef.tpu_top__DOT__weights_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp 
        = vlSelfRef.tpu_top__DOT__start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_gain 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_gain 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_bias 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_bias 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_shift 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_shift 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__acc_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1;
    vlSelfRef.tpu_top__DOT__mlp_acc1_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col0 
        = vlSelfRef.tpu_top__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col1 
        = vlSelfRef.tpu_top__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_data_in 
        = vlSelfRef.tpu_top__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_reset 
        = vlSelfRef.tpu_top__DOT__wf_reset;
    vlSelfRef.tpu_top__DOT__mlp_state_dbg = vlSelfRef.tpu_top__DOT__mlp_state_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state_in 
        = vlSelfRef.tpu_top__DOT__mlp_state_out;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_dbg = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt_in 
        = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__mlp_acc_valid_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_data 
        = vlSelfRef.tpu_top__DOT__init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__acc_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0;
    vlSelfRef.tpu_top__DOT__mlp_acc0_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_valid;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_valid 
        = vlSelfRef.tpu_top__DOT__init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rst 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rst;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__rst 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rst;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_reset = 
        ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_clear) 
         | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset;
    vlSelfRef.mlp_layer_dbg = vlSelfRef.tpu_top__DOT__mlp_layer_dbg;
    vlSelfRef.uart_state_dbg = vlSelfRef.tpu_top__DOT__uart_state_dbg;
    vlSelfRef.uart_cmd_dbg = vlSelfRef.tpu_top__DOT__uart_cmd_dbg;
    vlSelfRef.uart_byte_count_dbg = vlSelfRef.tpu_top__DOT__uart_byte_count_dbg;
    vlSelfRef.uart_resp_idx_dbg = vlSelfRef.tpu_top__DOT__uart_resp_idx_dbg;
    vlSelfRef.uart_tx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_tx_valid_dbg;
    vlSelfRef.uart_rx_data_dbg = vlSelfRef.tpu_top__DOT__uart_rx_data_dbg;
    vlSelfRef.uart_weights_ready_dbg = vlSelfRef.tpu_top__DOT__uart_weights_ready_dbg;
    vlSelfRef.uart_start_mlp_dbg = vlSelfRef.tpu_top__DOT__uart_start_mlp_dbg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col0_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff)
            : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff)
            : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff);
    vlSelfRef.tpu_top__DOT__uart_rx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_rx_valid_int;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in;
    vlSelfRef.tpu_top__DOT__uart_tx_ready_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_weights_ready 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_weights_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_start_mlp 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_gain;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_bias;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_shift;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__acc_in;
    vlSelfRef.tpu_top__DOT__mlp_acc1_dbg = vlSelfRef.tpu_top__DOT__mlp_acc1_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col0;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col1 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col1;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_data_in 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_data_in;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_reset 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_reset;
    vlSelfRef.mlp_state_dbg = vlSelfRef.tpu_top__DOT__mlp_state_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state_in;
    vlSelfRef.mlp_cycle_cnt_dbg = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__mlp_acc_valid_dbg = vlSelfRef.tpu_top__DOT__mlp_acc_valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row1_data 
        = (0x000000ffU & ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data) 
                          >> 8U));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row0_data 
        = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data));
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_data 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__acc_in;
    vlSelfRef.tpu_top__DOT__mlp_acc0_dbg = vlSelfRef.tpu_top__DOT__mlp_acc0_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0_in 
        = vlSelfRef.tpu_top__DOT__mlp_acc0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_valid 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__clk;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__reset;
    vlSelfRef.uart_rx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_rx_valid_dbg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col0_in;
    vlSelfRef.tpu_top__DOT__uart_tx_ready_dbg = vlSelfRef.tpu_top__DOT__uart_tx_ready_int;
    vlSelfRef.tpu_top__DOT__mlp_weights_ready = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_weights_ready;
    vlSelfRef.tpu_top__DOT__mlp_start_mlp = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_start_mlp;
    vlSelfRef.mlp_acc1_dbg = vlSelfRef.tpu_top__DOT__mlp_acc1_dbg;
    vlSelfRef.tpu_top__DOT__mlp_wf_push_col0 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_wf_push_col1 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_wf_data_in = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_wf_reset = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_reset;
    vlSelfRef.tpu_top__DOT__mlp_state_ctrl = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt;
    vlSelfRef.mlp_acc_valid_dbg = vlSelfRef.tpu_top__DOT__mlp_acc_valid_dbg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row0_in 
        = (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid) 
            & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase))
            ? (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row0_data)
            : 0U);
    vlSelfRef.tpu_top__DOT__mlp_init_act_data = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_data;
    vlSelfRef.mlp_acc0_dbg = vlSelfRef.tpu_top__DOT__mlp_acc0_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0_in;
    vlSelfRef.tpu_top__DOT__mlp_init_act_valid = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset;
    vlSelfRef.uart_tx_ready_dbg = vlSelfRef.tpu_top__DOT__uart_tx_ready_dbg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready 
        = vlSelfRef.tpu_top__DOT__mlp_weights_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__start_mlp = vlSelfRef.tpu_top__DOT__mlp_start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col0 
        = vlSelfRef.tpu_top__DOT__mlp_wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col1 
        = vlSelfRef.tpu_top__DOT__mlp_wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_data_in 
        = vlSelfRef.tpu_top__DOT__mlp_wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_reset = vlSelfRef.tpu_top__DOT__mlp_wf_reset;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state 
        = vlSelfRef.tpu_top__DOT__mlp_state_ctrl;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt 
        = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row0_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_data 
        = vlSelfRef.tpu_top__DOT__mlp_init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_acc0 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid 
        = vlSelfRef.tpu_top__DOT__mlp_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__reset 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset) 
           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_reset));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row0_in;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
        = vlSelfRef.tpu_top__DOT__mlp_acc0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid = 0U;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_data;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid = 1U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0) {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid;
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid)))) {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0) {
            if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select)))) {
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid;
            }
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_valid));
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
                                                    (((((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk__0))) 
                                                         << 6U) 
                                                        | ((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk__0))) 
                                                            << 5U) 
                                                           | (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk__0))) 
                                                              << 4U))) 
                                                       | (((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk__0))) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk__0))) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk__0))) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk__0)))))) 
                                                      << 0x00000010U) 
                                                     | ((((((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk__0))) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk__0))) 
                                                               << 2U)) 
                                                           | ((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk__0))) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk__0))))) 
                                                          << 0x0000000cU) 
                                                         | ((((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk__0))) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk__0))) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk__0))) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk__0))))) 
                                                            << 8U)) 
                                                        | (((((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk__0))) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk__0))) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__clk__0))) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.tpu_top__DOT__bridge_u__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__bridge_u__DOT__clk__0))))) 
                                                            << 4U) 
                                                           | (((((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk__0))) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk__0))) 
                                                                  << 2U)) 
                                                              | ((((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__clk__0))) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.tpu_top__DOT__clk) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__clk__0))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__bridge_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__clk;
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
    // Body
    if (VL_UNLIKELY((vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp))) {
        VL_WRITEF_NX("[TPU_BRIDGE] ctrl_start_mlp=1, passing to mlp_start_mlp=%b, mlp_state_in=%2#\n",0,
                     1,vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_start_mlp,
                     4,(IData)(vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state_in));
    }
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr = 0;
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr = 0;
    CData/*4:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count = 0;
    SData/*15:0*/ __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0;
    __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0;
    __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 = 0;
    // Body
    __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 = 0U;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) {
        __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_data;
        __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr;
        __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__reset) {
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr)));
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr)));
        }
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count 
            = (0x0000001fU & ((2U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                       << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read)))
                               ? ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count))
                               : ((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                           << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read)))
                                   ? ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count) 
                                      - (IData)(1U))
                                   : (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count))));
        if ((1U & (~ VL_ONEHOT_I((((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read))) 
                                   << 1U) | (2U == 
                                             (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read)))))))) {
            if ((0U != (((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                  << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read))) 
                         << 1U) | (2U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                           << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: unified_buffer.sv:92: Assertion failed in %Ntpu_top.mlp_u.ub_a: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write) 
                                     << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read)));
                    VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/unified_buffer.sv", 92, "");
                }
            }
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_reg 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__reset)
            ? 0U : (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_comb));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb));
    if (__VdlySet__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem[__VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0] 
            = __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem__v0;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ptr;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_comb 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__mem
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ptr];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__full 
        = (0x10U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__full)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_empty 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__empty;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr = 0;
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr = 0;
    CData/*4:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count = 0;
    SData/*15:0*/ __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0;
    __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0;
    __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 = 0;
    // Body
    __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 = 0U;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr;
    __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) {
        __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_data;
        __VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr;
        __VdlySet__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__reset) {
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr)));
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr)));
        }
        __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count 
            = (0x0000001fU & ((2U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                       << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read)))
                               ? ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count))
                               : ((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                           << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read)))
                                   ? ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count) 
                                      - (IData)(1U))
                                   : (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count))));
        if ((1U & (~ VL_ONEHOT_I((((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read))) 
                                   << 1U) | (2U == 
                                             (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read)))))))) {
            if ((0U != (((1U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                  << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read))) 
                         << 1U) | (2U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                           << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: unified_buffer.sv:92: Assertion failed in %Ntpu_top.mlp_u.ub_b: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write) 
                                     << 1U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read)));
                    VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/unified_buffer.sv", 92, "");
                }
            }
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_reg 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__reset)
            ? 0U : (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_comb));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb));
    if (__VdlySet__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem[__VdlyDim0__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0] 
            = __VdlyVal__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem__v0;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ptr;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_comb 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__mem
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ptr];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__full 
        = (0x10U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__count));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__full)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb 
        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_empty 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__empty;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 = 0;
    CData/*1:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 = 0;
    CData/*1:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 = 0;
    CData/*1:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0;
    __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0;
    __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 = 0;
    CData/*0:0*/ __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0;
    __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0;
    __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 = 0;
    CData/*0:0*/ __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 = 0;
    // Body
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 = 0U;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0;
    __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 = 0U;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__reset) {
        __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_out = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__pop) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0)));
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_out 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1
                [vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1];
            __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1)));
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col1) {
            __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__data_in;
            __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1;
            __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0 = 1U;
            __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1)));
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col0) {
            __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__data_in;
            __VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0;
            __VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0 = 1U;
            __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0)));
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__wr_ptr0;
    if (__VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0[__VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0] 
            = __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0__v0;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1;
    if (__VdlySet__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1[__VdlyDim0__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0] 
            = __VdlyVal__tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1__v0;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue0
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr0];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_raw 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__queue1
        [vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__rd_ptr1];
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_raw 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__col1_raw;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending = 0;
    // Body
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__reset) {
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col1 = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 0U;
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__valid_in) {
            if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending) {
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 1U;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col0 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col1 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col1;
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col0;
            } else {
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col0;
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending = 1U;
            }
        } else {
            __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending = 0U;
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__pending;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__align_col1;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 0;
    SData/*15:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte = 0;
    // Body
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state;
    if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__rst) {
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx = 1U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte = 0U;
    } else if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state))) {
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx = 1U;
            if ((0x0363U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count))) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0U;
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 0U;
            } else {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count)));
            }
        } else {
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx 
                = (1U & ((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte) 
                         >> (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index)));
            if ((0x0363U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count))) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0U;
                if ((7U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index))) {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 3U;
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index)));
                }
            } else {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count)));
            }
        }
    } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state))) {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx = 0U;
        if ((0x0363U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count))) {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 2U;
        } else {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count 
                = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count)));
        }
    } else {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx = 1U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index = 0U;
        if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_valid) {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte 
                = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_data;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state = 1U;
        }
    }
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__clk_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__bit_index;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_byte;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_ready 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__state));
    vlSelfRef.tpu_top__DOT__uart_tx = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx;
    vlSelfRef.uart_tx = vlSelfRef.tpu_top__DOT__uart_tx;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 0;
    SData/*15:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0;
    CData/*2:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index = 0;
    CData/*7:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte = 0;
    // Body
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state;
    if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rst) {
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_data = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid = 0U;
        if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state))) {
                if ((0x0363U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count))) {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0U;
                    if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2) {
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_data 
                            = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte;
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid = 1U;
                    }
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 0U;
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count)));
                }
            } else if ((0x0363U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count))) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0U;
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index))) 
                        & (IData)(__Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte)) 
                       | (0x00ffU & ((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2) 
                                     << (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index))));
                if ((7U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index))) {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 3U;
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index)));
                }
            } else {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count)));
            }
        } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state))) {
            if ((0x01b1U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count))) {
                if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2) {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 0U;
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 2U;
                }
            } else {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count)));
            }
        } else {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index = 0U;
            if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2)))) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state = 1U;
            }
        }
    }
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__clk_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__bit_index;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_byte;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_ready 
        = (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__state));
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_2 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_1;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_sync_1 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx;
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_state_out_prev;
    __Vdly__tpu_top__DOT__mlp_state_out_prev = 0;
    // Body
    __Vdly__tpu_top__DOT__mlp_state_out_prev = vlSelfRef.tpu_top__DOT__mlp_state_out_prev;
    if (vlSelfRef.tpu_top__DOT__rst) {
        __Vdly__tpu_top__DOT__mlp_state_out_prev = 0U;
    } else {
        if (VL_UNLIKELY((((IData)(vlSelfRef.tpu_top__DOT__mlp_state_out) 
                          != (IData)(vlSelfRef.tpu_top__DOT__mlp_state_out_prev))))) {
            VL_WRITEF_NX("[TPU_TOP] State change: mlp_state_out=%2#->%2#, mlp_cycle_cnt_out=%2#, mlp_acc0_out=0x%08x\n",0,
                         4,vlSelfRef.tpu_top__DOT__mlp_state_out_prev,
                         4,(IData)(vlSelfRef.tpu_top__DOT__mlp_state_out),
                         5,vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out,
                         32,vlSelfRef.tpu_top__DOT__mlp_acc0_out);
        }
        __Vdly__tpu_top__DOT__mlp_state_out_prev = vlSelfRef.tpu_top__DOT__mlp_state_out;
    }
    vlSelfRef.tpu_top__DOT__mlp_state_out_prev = __Vdly__tpu_top__DOT__mlp_state_out_prev;
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = 0;
    IData/*31:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = 0;
    IData/*31:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = 0;
    IData/*31:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = 0;
    // Body
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = 0U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__enable) {
        if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select) 
                                   << 1U) | (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select)))))))) {
            if ((0U == (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select) 
                         << 1U) | (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Ntpu_top.mlp_u.accum_u.u_mem: unique case, but none matched for '1'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 1,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select));
                    VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/accumulator_mem.sv", 39, "");
                }
            } else if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Ntpu_top.mlp_u.accum_u.u_mem: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select));
                VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/accumulator_mem.sv", 39, "");
            }
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select) {
            if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                    = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0));
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                    = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1));
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                    = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0));
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                    = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1));
            } else {
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0;
                __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1;
            }
        } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0));
            __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1));
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0));
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1));
        } else {
            __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0;
            __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1;
        }
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out = 1U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out = 0U;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__out_col0;
}

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0;
    CData/*7:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg = 0;
    CData/*2:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count = 0;
    CData/*2:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 0;
    CData/*1:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = 0;
    CData/*1:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0;
    CData/*7:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg = 0;
    CData/*3:0*/ __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev = 0;
    CData/*1:0*/ __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v0;
    __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v0;
    __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v0 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v1;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v1 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v2;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v2 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v3;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v3 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v4;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v4 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v5;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v5 = 0;
    CData/*7:0*/ __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1;
    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1 = 0;
    CData/*1:0*/ __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1;
    __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1 = 0;
    // Body
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_sent;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rst) {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data_captured = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid) {
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data_captured 
                = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data;
        }
        if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg) {
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky = 1U;
        }
        if (((0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state)) 
             & (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count)))) {
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky = 0U;
        }
    }
    if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rst) {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = 0U;
        while (VL_GTS_III(32, 4U, vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v0 
                = (3U & vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__data_buffer.enqueue(0U, (IData)(__VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v0));
            __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v0 
                = (3U & vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(0U, (IData)(__VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v0));
            vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__unnamedblk1__DOT__i);
        }
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg = 0U;
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg = 0U;
        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg = 0U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg) 
                           & (0U != (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state))) 
                          & (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev)))))) {
            VL_WRITEF_NX("[UART_CTRL] MLP started! Clearing start_mlp_reg and weights_ready_reg (state %2# -> %2#)\n",0,
                         4,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev,
                         4,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state));
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg = 0U;
        } else if (((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg) 
                    & (0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state)))) {
            if (VL_UNLIKELY(((0U == (0x0000007fU & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count)))))) {
                VL_WRITEF_NX("[UART_CTRL] start_mlp_reg still set, MLP still in IDLE (state=%2#)\n",0,
                             4,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state);
            }
        }
        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev 
            = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state;
        if ((8U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
        } else if ((4U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                } else if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx))))) {
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg 
                        = ((vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                            [2U] << 8U) | vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                           [0U]);
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg = 1U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = 1U;
                    VL_WRITEF_NX("[UART_CTRL] WRITE_ACT_SEQ[0]: Writing col0=0x%04x (A10=%02x, A00=%02x), init_act_valid=1\n",0,
                                 16,((vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                      [2U] << 8U) | 
                                     vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [0U]),8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                 [2U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                 [0U]);
                } else if (VL_UNLIKELY(((1U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx))))) {
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg 
                        = ((vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                            [3U] << 8U) | vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                           [1U]);
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg = 1U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                    VL_WRITEF_NX("[UART_CTRL] WRITE_ACT_SEQ[1]: Writing col1=0x%04x (A11=%02x, A01=%02x), init_act_valid=1, going to IDLE\n",0,
                                 16,((vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                      [3U] << 8U) | 
                                     vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [1U]),8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                 [3U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                 [1U]);
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))) {
                    if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))) {
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                    } else if (VL_LIKELY(((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))))) {
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                    } else {
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg 
                            = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                            [3U];
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg = 1U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg = 1U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                        VL_WRITEF_NX("[UART_CTRL] WRITE_WEIGHT_SEQ[4]: Completed, weights=[%02x,%02x,%02x,%02x]\n",0,
                                     8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [0U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [1U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [2U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [3U]);
                    }
                } else if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))) {
                    if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))) {
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg 
                            = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                            [2U];
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg = 1U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 4U;
                    } else {
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg 
                            = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                            [1U];
                        vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg = 1U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 3U;
                    }
                } else if (VL_LIKELY(((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx))))) {
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg 
                        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                        [0U];
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg = 1U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 2U;
                } else {
                    VL_WRITEF_NX("[UART_CTRL] WRITE_WEIGHT_SEQ[0]: Resetting weight FIFO\n",0);
                    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg = 1U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 1U;
                }
            } else if ((0x0aU > (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count))) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count)));
            } else if (VL_UNLIKELY(((((~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg)) 
                                      & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready)) 
                                     & (~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_sent)))))) {
                vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data_reg 
                    = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                    [vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx];
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg = 1U;
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 1U;
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Sending byte[%0#]=0x%02x (from resp_buffer[%0#]=0x%02x), cmd=0x%02x, tx_ready=%b, total_bytes=%0d\n",0,
                             2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx,
                             8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                             [vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx],
                             2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx,
                             8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                             [vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx],
                             8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg,
                             1,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready),
                             32,((4U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))
                                  ? 4U : 1U));
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg) 
                                     & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready))))) {
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] waiting for UART TX to accept\n",0,
                             2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx);
            } else if (VL_UNLIKELY((((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg) 
                                     & (~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready)))))) {
                VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] accepted by UART TX, clearing tx_valid\n",0,
                             2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx);
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg = 0U;
            } else if ((1U & (~ ((~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg)) 
                                 & (~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready)))))) {
                if ((((~ (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg)) 
                      & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready)) 
                     & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_sent))) {
                    VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Byte[%0#] transmission complete, cmd=0x%02x\n",0,
                                 2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx,
                                 8,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg));
                    if (VL_UNLIKELY(((5U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                        VL_WRITEF_NX("[UART_CTRL] SEND_RESP: STATUS done, going to IDLE\n",0);
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                    } else if (VL_LIKELY(((4U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                        if ((3U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx))) {
                            VL_WRITEF_NX("[UART_CTRL] SEND_RESP: All 4 bytes sent (0,1,2,3), going to IDLE\n",0);
                            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                        } else {
                            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx 
                                = (3U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx)));
                            VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Moving to next byte, resp_byte_idx=%0#->%0#\n",0,
                                         2,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx,
                                         32,((IData)(1U) 
                                             + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx)));
                            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0U;
                            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count = 0x0aU;
                        }
                    } else {
                        VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Unknown command, going to IDLE\n",0);
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                    }
                } else {
                    VL_WRITEF_NX("[UART_CTRL] SEND_RESP: Unexpected state - tx_valid=%b, tx_ready=%b, byte_sent=%b\n",0,
                                 1,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg,
                                 1,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready),
                                 1,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_sent);
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
                if (VL_UNLIKELY(((3U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_EXECUTE - setting start_mlp_reg=1, weights_ready_reg=%b, mlp_state=%2#\n",0,
                                 1,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg,
                                 4,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state));
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg = 1U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                } else if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_READ_RESULT - acc0=0x%08x, packing bytes: [7:0]=0x%02x, [15:8]=0x%02x, [23:16]=0x%02x, [31:24]=0x%02x, resp_buffer current=[0x%02x,0x%02x,0x%02x,0x%02x]\n",0,
                                 32,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0,
                                 8,(0x000000ffU & vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0),
                                 8,(0x000000ffU & (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                                                   >> 8U)),
                                 8,(0x000000ffU & (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                                                   >> 0x10U)),
                                 8,(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                                    >> 0x18U),8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                                 [0U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                                 [1U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                                 [2U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                                 [3U]);
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 4U;
                    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v1 
                        = (0x000000ffU & vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0);
                    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v1, 0U);
                    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v2 
                        = (0x000000ffU & (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                                          >> 8U));
                    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v2, 1U);
                    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v3 
                        = (0x000000ffU & (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                                          >> 0x10U));
                    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v3, 2U);
                    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v4 
                        = (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
                           >> 0x18U);
                    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v4, 3U);
                } else if (VL_UNLIKELY(((5U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                    VL_WRITEF_NX("[UART_CTRL] EXEC_CMD: CMD_STATUS - mlp_state=0x%x[3:0], mlp_cycle_cnt=0x%x[4:0], packed_value=0x%02x (packed: state[3:0]=0x%x, cycle[3:0]=0x%x), resp_buffer[0] current=0x%02x\n",0,
                                 4,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state,
                                 5,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt),
                                 8,(((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state) 
                                     << 4U) | (0x0000000fU 
                                               & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt))),
                                 4,(IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state),
                                 4,(0x0000000fU & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt)),
                                 8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer
                                 [0U]);
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0U;
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 4U;
                    __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v5 
                        = (((IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state) 
                            << 4U) | (0x0000000fU & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt)));
                    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer__v5, 0U);
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 0U;
                }
            } else if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid) {
                __VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1 
                    = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data;
                __VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1 
                    = (3U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count));
                vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__data_buffer.enqueue(__VdlyVal__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1, (IData)(__VdlyDim0__tpu_top__DOT__uart_ctrl_u__DOT__data_buffer__v1));
                if ((3U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count))) {
                    if (VL_UNLIKELY(((1U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                        VL_WRITEF_NX("[UART_CTRL] RECV_DATA: Got 4 bytes for CMD_WRITE_WEIGHT, going to WRITE_WEIGHT_SEQ. Data=[%02x,%02x,%02x,%02x]\n",0,
                                     8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [0U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [1U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [2U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data);
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 0U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 5U;
                    } else if (VL_UNLIKELY(((2U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg))))) {
                        VL_WRITEF_NX("[UART_CTRL] RECV_DATA: Got 4 bytes for CMD_WRITE_ACT, going to WRITE_ACT_SEQ. Data=[%02x,%02x,%02x,%02x]\n",0,
                                     8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [0U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [1U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer
                                     [2U],8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data);
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = 0U;
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 6U;
                    } else {
                        __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 3U;
                    }
                } else {
                    __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state))) {
            if (VL_UNLIKELY((vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid))) {
                VL_WRITEF_NX("[UART_CTRL] WAIT_CMD: Received cmd=0x%02x\n",0,
                             8,vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data);
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg 
                    = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data;
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count = 0U;
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state 
                    = (((1U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data)) 
                        | (2U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data)))
                        ? 2U : ((((3U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data)) 
                                  | (4U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data))) 
                                 | (5U == (IData)(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data)))
                                 ? 3U : 0U));
            }
        } else {
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx = 0U;
            __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx = 0U;
            if (vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_ready) {
                __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state = 1U;
            }
        }
    }
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weight_seq_idx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__act_seq_idx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_sent 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_sent;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_delay_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__mlp_state_prev;
    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__data_buffer.commit(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__data_buffer);
    vlSelfRef.__VdlyCommitQueuetpu_top__DOT__uart_ctrl_u__DOT__resp_buffer.commit(vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_buffer);
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__byte_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg 
        = __Vdly__tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data_captured;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_start_mlp 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_sticky;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_cmd_reg 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__cmd_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_resp_byte_idx 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__resp_byte_idx;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_state 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_byte_count 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__byte_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_weights_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready_reg;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid_reg;
    vlSelfRef.tpu_top__DOT__uart_rx_data_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_data;
    vlSelfRef.tpu_top__DOT__uart_start_mlp_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_start_mlp;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_data;
    vlSelfRef.tpu_top__DOT__uart_cmd_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_cmd_reg;
    vlSelfRef.tpu_top__DOT__uart_resp_idx_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_resp_byte_idx;
    vlSelfRef.tpu_top__DOT__uart_state_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_state;
    vlSelfRef.tpu_top__DOT__uart_byte_cnt_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_byte_count;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_valid;
    vlSelfRef.tpu_top__DOT__uart_tx_valid_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_valid;
    vlSelfRef.tpu_top__DOT__start_mlp = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__start_mlp;
    vlSelfRef.tpu_top__DOT__wf_push_col0 = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__wf_push_col1 = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__wf_data_in = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__wf_reset = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__wf_reset;
    vlSelfRef.tpu_top__DOT__init_act_data = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_data;
    vlSelfRef.tpu_top__DOT__uart_weights_ready_int 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_weights_ready;
    vlSelfRef.tpu_top__DOT__weights_ready = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__weights_ready;
    vlSelfRef.tpu_top__DOT__init_act_valid = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__init_act_valid;
    vlSelfRef.tpu_top__DOT__uart_rx_data_dbg = vlSelfRef.tpu_top__DOT__uart_rx_data_int;
    vlSelfRef.tpu_top__DOT__uart_start_mlp_dbg = vlSelfRef.tpu_top__DOT__uart_start_mlp_int;
    vlSelfRef.tpu_top__DOT__uart_cmd_dbg = vlSelfRef.tpu_top__DOT__uart_cmd_int;
    vlSelfRef.tpu_top__DOT__uart_resp_idx_dbg = vlSelfRef.tpu_top__DOT__uart_resp_idx_int;
    vlSelfRef.tpu_top__DOT__uart_state_dbg = vlSelfRef.tpu_top__DOT__uart_state_int;
    vlSelfRef.tpu_top__DOT__uart_byte_count_dbg = vlSelfRef.tpu_top__DOT__uart_byte_cnt_int;
    vlSelfRef.tpu_top__DOT__uart_tx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_tx_valid_int;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp 
        = vlSelfRef.tpu_top__DOT__start_mlp;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col0 
        = vlSelfRef.tpu_top__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col1 
        = vlSelfRef.tpu_top__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_data_in 
        = vlSelfRef.tpu_top__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_reset 
        = vlSelfRef.tpu_top__DOT__wf_reset;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_data 
        = vlSelfRef.tpu_top__DOT__init_act_data;
    vlSelfRef.tpu_top__DOT__uart_weights_ready_dbg 
        = vlSelfRef.tpu_top__DOT__uart_weights_ready_int;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_weights_ready 
        = vlSelfRef.tpu_top__DOT__weights_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_valid 
        = vlSelfRef.tpu_top__DOT__init_act_valid;
    vlSelfRef.uart_rx_data_dbg = vlSelfRef.tpu_top__DOT__uart_rx_data_dbg;
    vlSelfRef.uart_start_mlp_dbg = vlSelfRef.tpu_top__DOT__uart_start_mlp_dbg;
    vlSelfRef.uart_cmd_dbg = vlSelfRef.tpu_top__DOT__uart_cmd_dbg;
    vlSelfRef.uart_resp_idx_dbg = vlSelfRef.tpu_top__DOT__uart_resp_idx_dbg;
    vlSelfRef.uart_state_dbg = vlSelfRef.tpu_top__DOT__uart_state_dbg;
    vlSelfRef.uart_byte_count_dbg = vlSelfRef.tpu_top__DOT__uart_byte_count_dbg;
    vlSelfRef.uart_tx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_tx_valid_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_start_mlp 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_start_mlp;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col0;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col1 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_push_col1;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_data_in 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_data_in;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_reset 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_wf_reset;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_data 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_data;
    vlSelfRef.uart_weights_ready_dbg = vlSelfRef.tpu_top__DOT__uart_weights_ready_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_weights_ready 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_weights_ready;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_valid 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__ctrl_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_start_mlp = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_wf_push_col0 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_wf_push_col1 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_wf_data_in = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_wf_reset = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_wf_reset;
    vlSelfRef.tpu_top__DOT__mlp_init_act_data = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_weights_ready = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_weights_ready;
    vlSelfRef.tpu_top__DOT__mlp_init_act_valid = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col0 
        = vlSelfRef.tpu_top__DOT__mlp_wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col1 
        = vlSelfRef.tpu_top__DOT__mlp_wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_data_in 
        = vlSelfRef.tpu_top__DOT__mlp_wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_reset = vlSelfRef.tpu_top__DOT__mlp_wf_reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_data 
        = vlSelfRef.tpu_top__DOT__mlp_init_act_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid 
        = vlSelfRef.tpu_top__DOT__mlp_init_act_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__push_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_push_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_data_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__reset 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset) 
           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_reset));
}

void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0;
    CData/*4:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0;
    CData/*2:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select;
    __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select = 0;
    CData/*0:0*/ __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded;
    __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 0;
    // Body
    __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_loaded;
    __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg;
    __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select;
    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg;
    if (VL_UNLIKELY((((~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset)) 
                      & ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg) 
                         != (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg_prev)))))) {
        VL_WRITEF_NX("[MLP] State transition: %2# -> %2# (cycle_cnt=%2#, weights_ready=%b, weights_loaded=%b, state output=%2#)\n",0,
                     4,vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg_prev,
                     4,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg),
                     5,vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg,
                     1,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready),
                     1,vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_loaded,
                     4,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state));
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg_prev 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__row1_skew_reg = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid = 0U;
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_valid) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data 
                = (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col1) 
                    << 8U) | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col0));
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid = 1U;
        }
        if (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase) 
             & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid))) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__row1_skew_reg 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row1_data;
        }
    }
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset) {
        __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select = 0U;
        __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__addr_sel = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_clear = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_clear = 0U;
        if (VL_UNLIKELY((((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__start_mlp) 
                          & (0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg)))))) {
            VL_WRITEF_NX("[MLP] start_mlp=1 detected in IDLE, weights_ready=%b\n",0,
                         1,vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready);
        }
        if ((8U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
            if ((4U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0U;
            } else if ((2U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0U;
            } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0U;
            } else {
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete = 1U;
                if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                    VL_WRITEF_NX("[MLP] DONE state reached. acc0=0x%08x, acc1=0x%08x, acc_valid=%b, cycle_cnt=%2#\n",0,
                                 32,vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0,
                                 32,vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1,
                                 1,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid),
                                 5,vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg);
                }
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                if (VL_UNLIKELY(((8U <= (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                    VL_WRITEF_NX("[MLP] DONE: Returning to IDLE after 8 cycles\n",0);
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 0U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                    vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete = 0U;
                    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en = 0U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 0U;
                }
            }
        } else if ((4U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
            if ((2U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                if ((1U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                    if (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready) 
                         & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_loaded)))) {
                        __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 1U;
                        __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                    }
                } else {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select 
                        = (1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select)));
                    __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg)));
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 7U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                if ((3U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 6U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                }
            } else {
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en = 1U;
                if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                    VL_WRITEF_NX("[MLP] DRAIN started. mmu_valid=1 throughout DRAIN. mmu_acc0=%04x, mmu_acc1=%04x\n",0,
                                 16,vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc0_out,
                                 16,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc1_out));
                }
                if (VL_UNLIKELY(((6U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                    VL_WRITEF_NX("[MLP] DRAIN ending. acc0=0x%08x, acc1=0x%08x, acc_valid=%b\n",0,
                                 32,vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0,
                                 32,vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1,
                                 1,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid));
                }
                if ((6U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 8U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
            if ((1U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                    VL_WRITEF_NX("[MLP] COMPUTE started. mmu_valid will be high when cycle_cnt>=2\n",0);
                }
                if ((2U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 4U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                }
            } else {
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
                if ((3U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) {
                    __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 3U;
                    __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg))) {
            __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
            if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                VL_WRITEF_NX("[MLP] LOAD_WEIGHT: cycle_cnt=%2#, current_layer=%1#\n",0,
                             5,vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg,
                             3,(IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg));
            }
            if (VL_UNLIKELY(((2U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))))) {
                VL_WRITEF_NX("[MLP] LOAD_WEIGHT: Completed, transitioning to %s\n",0,
                             64,((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg))
                                  ? 0x4c4f41445f414354ULL
                                  : 0x00434f4d50555445ULL));
                __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg 
                    = ((0U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg))
                        ? 2U : 3U);
                __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
                __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 1U;
            }
        } else {
            if (VL_UNLIKELY((vlSelfRef.tpu_top__DOT__mlp_u__DOT__start_mlp))) {
                VL_WRITEF_NX("[MLP] IDLE: start_mlp=1, weights_ready=%b, transitioning to LOAD_WEIGHT\n",0,
                             1,vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready);
            }
            if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__start_mlp) {
                __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg = 1U;
                __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg = 0U;
                __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select = 0U;
                __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded = 0U;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_clear = 1U;
            }
            __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg = 0U;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete = 0U;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en = 0U;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__addr_sel = 0U;
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_loaded 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__weights_loaded;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__current_layer_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select 
        = __Vdly__tpu_top__DOT__mlp_u__DOT__buffer_select;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg = __Vdly__tpu_top__DOT__mlp_u__DOT__state_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__accumulator_enable 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_en;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__addr_sel 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__addr_sel;
    vlSelfRef.tpu_top__DOT__mlp_layer_complete_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__layer_complete;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_reset = 
        ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_clear) 
         | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__reset));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt = vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__state = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__transfer_phase 
        = (5U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase 
        = (3U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase 
        = (4U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight 
        = (1U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__state_reg));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__accumulator_enable;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__buffer_select 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__addr_sel;
    vlSelfRef.tpu_top__DOT__mlp_layer_complete_dbg 
        = vlSelfRef.tpu_top__DOT__mlp_layer_complete_out;
    vlSelfRef.tpu_top__DOT__mlp_current_layer_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__current_layer;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_reset;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt;
    vlSelfRef.tpu_top__DOT__mlp_state_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__state;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready = 0U;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__row1_skew_reg;
        if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select)))) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready = 1U;
        }
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready = 1U;
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in = 0U;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_valid = 
        (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase) 
          & (2U <= (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg))) 
         | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__drain_phase) 
           | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__transfer_phase));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weight_fifo_u__DOT__pop 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col0 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight) 
           & (1U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col1 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight) 
           & (2U == (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__cycle_cnt_reg)));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight;
    vlSelfRef.mlp_layer_complete_dbg = vlSelfRef.tpu_top__DOT__mlp_layer_complete_dbg;
    vlSelfRef.tpu_top__DOT__mlp_layer_dbg = vlSelfRef.tpu_top__DOT__mlp_current_layer_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__reset 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__reset;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_dbg = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt_in 
        = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_out;
    vlSelfRef.tpu_top__DOT__mlp_state_dbg = vlSelfRef.tpu_top__DOT__mlp_state_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state_in 
        = vlSelfRef.tpu_top__DOT__mlp_state_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ready 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_ready;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_capture_col1;
    vlSelfRef.mlp_layer_dbg = vlSelfRef.tpu_top__DOT__mlp_layer_dbg;
    vlSelfRef.mlp_cycle_cnt_dbg = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt_in;
    vlSelfRef.mlp_state_dbg = vlSelfRef.tpu_top__DOT__mlp_state_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__mlp_cycle_cnt = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_cycle_cnt;
    vlSelfRef.tpu_top__DOT__mlp_state_ctrl = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_state;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_cycle_cnt 
        = vlSelfRef.tpu_top__DOT__mlp_cycle_cnt;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_state 
        = vlSelfRef.tpu_top__DOT__mlp_state_ctrl;
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__loss_out 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__reset)
            ? 0U : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__abs_diff);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__loss_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__loss_out 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__reset)
            ? 0U : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__abs_diff);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__loss_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_out 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__reset)
            ? 0U : ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_in 
                     >> 0x1fU) ? 0U : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_out 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__reset)
            ? 0U : ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_in 
                     >> 0x1fU) ? 0U : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_in));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__weight = 0U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum));
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum));
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_act 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_act;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_act) 
                               * (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__weight)) 
                              + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum)));
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01_11_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__out_psum;
}

void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__weight = 0U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum));
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum));
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_act 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_act;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_act) 
                               * (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__weight)) 
                              + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum)));
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc1_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col1_in;
}

void Vtop___024root___nba_sequent__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__weight = 0U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum));
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum));
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_act;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_act) 
                               * (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__weight)) 
                              + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum)));
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_01_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_10_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_01_act;
}

void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__weight = 0U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum));
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum));
        }
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_act;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_act) 
                               * (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__weight)) 
                              + (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum)));
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10_11_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__out_psum;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10_11_act;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc0_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__acc0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_acc0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_align__DOT__raw_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__mmu_col0_in;
}

void Vtop___024root___nba_sequent__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__Vfuncout;
    __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val;
    __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val = 0;
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_q_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__biased_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d2 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__scaled_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_reg = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_raw = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale_d0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_data = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_d1 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_in;
        }
        __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__biased_reg;
        __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__Vfuncout 
            = (VL_LTS_III(32, 0x0000007fU, __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val)
                ? 0x0000007fU : (VL_GTS_III(32, 0xffffff80U, __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val)
                                  ? 0x00000080U : (0x000000ffU 
                                                   & __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__val)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_q_reg 
            = __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__sat_int8__0__Vfuncout;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__biased_reg 
            = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__scaled_reg 
               + (((- (IData)((1U & ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d2) 
                                     >> 7U)))) << 8U) 
                  | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d2)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d2 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d1;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__unnamedblk1__DOT__mult_rounded 
            = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                        + vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_reg));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__scaled_reg 
            = (IData)((0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__unnamedblk1__DOT__mult_rounded, 8U)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d0;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_reg 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_raw;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point_d0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_zero_point;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__mult_raw 
            = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_data)), 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale_d0)))));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale_d0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_inv_scale;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s4_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__target_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__target_d1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s4_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s3_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_data_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_q_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_valid = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__ub_data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s3_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s2_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s2_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__q_s1_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid));
}

void Vtop___024root___nba_sequent__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__Vfuncout;
    __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val;
    __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val = 0;
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_q_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__biased_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d2 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__scaled_reg = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_reg = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_raw = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale_d0 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_data = 0U;
    } else {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_d1 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_in;
        }
        __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__biased_reg;
        __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__Vfuncout 
            = (VL_LTS_III(32, 0x0000007fU, __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val)
                ? 0x0000007fU : (VL_GTS_III(32, 0xffffff80U, __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val)
                                  ? 0x00000080U : (0x000000ffU 
                                                   & __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__val)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_q_reg 
            = __Vfunc_tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__sat_int8__1__Vfuncout;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__biased_reg 
            = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__scaled_reg 
               + (((- (IData)((1U & ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d2) 
                                     >> 7U)))) << 8U) 
                  | (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d2)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d2 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d1;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__unnamedblk1__DOT__mult_rounded 
            = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                        + vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_reg));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__scaled_reg 
            = (IData)((0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__unnamedblk1__DOT__mult_rounded, 8U)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d0;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_reg 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_raw;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point_d0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_zero_point;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__mult_raw 
            = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_data)), 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale_d0)))));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale_d0 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_inv_scale;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s4_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__target_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__target_d1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s4_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s3_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_data_out 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_q_reg;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_data_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__ub_data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s3_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s2_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s2_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__q_s1_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid));
}

void Vtop___024root___nba_sequent__TOP__21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s3_valid));
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_out = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d2 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shifted_res = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_res = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_raw = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain_d = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_out 
            = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shifted_res) 
               + vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d2);
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d2 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d1;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shifted_res 
            = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_res, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d1)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_res 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_raw;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__bias;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__shift;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__mult_raw 
            = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in_d)), 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain_d)))));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__gain;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s3_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s2_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s2_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s2_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s1_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__s1_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_in));
}

void Vtop___024root___nba_sequent__TOP__22(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s3_valid));
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_out = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d2 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shifted_res = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d1 = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_res = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_raw = 0ULL;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in_d = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain_d = 0U;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_out 
            = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shifted_res) 
               + vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d2);
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d2 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d1;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shifted_res 
            = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_res, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d1)));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d1 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_res 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_raw;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__bias;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__shift;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__mult_raw 
            = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,32, vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in_d)), 
                                                   (0x0000ffffffffffffULL 
                                                    & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain_d)))));
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain_d 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__gain;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s3_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s2_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s2_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s2_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s1_valid));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__s1_valid 
        = ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_in));
}

void Vtop___024root___nba_sequent__TOP__23(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__23\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__enable 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__aligned_c1;
}

void Vtop___024root___nba_sequent__TOP__24(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_ready;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_data 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_data;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__rx_valid;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_valid 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__rx_valid;
    vlSelfRef.tpu_top__DOT__uart_rx_valid_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_rx_valid;
    vlSelfRef.tpu_top__DOT__uart_rx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_rx_valid_int;
    vlSelfRef.uart_rx_valid_dbg = vlSelfRef.tpu_top__DOT__uart_rx_valid_dbg;
}

void Vtop___024root___nba_sequent__TOP__25(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__25\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__tx_ready;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_ready 
        = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__tx_ready;
    vlSelfRef.tpu_top__DOT__uart_tx_ready_int = vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__dbg_tx_ready;
    vlSelfRef.tpu_top__DOT__uart_tx_ready_dbg = vlSelfRef.tpu_top__DOT__uart_tx_ready_int;
    vlSelfRef.uart_tx_ready_dbg = vlSelfRef.tpu_top__DOT__uart_tx_ready_dbg;
}

void Vtop___024root___nba_sequent__TOP__26(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__26\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__start_mlp = vlSelfRef.tpu_top__DOT__mlp_start_mlp;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__weights_ready 
        = vlSelfRef.tpu_top__DOT__mlp_weights_ready;
}

void Vtop___024root___nba_sequent__TOP__27(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__27\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1 = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0 = vlSelfRef.tpu_top__DOT__mlp_u__DOT__accum_u__DOT__acc_col0_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__acc_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1;
    vlSelfRef.tpu_top__DOT__mlp_acc1_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__mlp_acc_valid_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__acc_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0;
    vlSelfRef.tpu_top__DOT__mlp_acc0_out = vlSelfRef.tpu_top__DOT__mlp_u__DOT__acc0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__acc_in;
    vlSelfRef.tpu_top__DOT__mlp_acc1_dbg = vlSelfRef.tpu_top__DOT__mlp_acc1_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__valid_in;
    vlSelfRef.tpu_top__DOT__mlp_acc_valid_dbg = vlSelfRef.tpu_top__DOT__mlp_acc_valid_out;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__acc_in;
    vlSelfRef.tpu_top__DOT__mlp_acc0_dbg = vlSelfRef.tpu_top__DOT__mlp_acc0_out;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0_in 
        = vlSelfRef.tpu_top__DOT__mlp_acc0_out;
    vlSelfRef.mlp_acc1_dbg = vlSelfRef.tpu_top__DOT__mlp_acc1_dbg;
    vlSelfRef.mlp_acc_valid_dbg = vlSelfRef.tpu_top__DOT__mlp_acc_valid_dbg;
    vlSelfRef.mlp_acc0_dbg = vlSelfRef.tpu_top__DOT__mlp_acc0_dbg;
    vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0 
        = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0_in;
    vlSelfRef.tpu_top__DOT__mlp_acc0 = vlSelfRef.tpu_top__DOT__bridge_u__DOT__mlp_acc0;
    vlSelfRef.tpu_top__DOT__uart_ctrl_u__DOT__mlp_acc0 
        = vlSelfRef.tpu_top__DOT__mlp_acc0;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_empty 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_empty;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_valid;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_rd_data;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_empty 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_empty;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_valid;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_rd_data;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row1_data 
        = (0x000000ffU & ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data) 
                          >> 8U));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row0_data 
        = (0x000000ffU & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_data));
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row0_in 
        = (((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_ub_rd_valid) 
            & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__compute_phase))
            ? (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__act_row0_data)
            : 0U);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_row0_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row0_in;
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__en_load_weight) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col0_out;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__wf_col1_out;
    } else {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in = 0U;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in = 0U;
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col0_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col0_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col1_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_col1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col0_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__col1_in;
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data = 0U;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid = 0U;
    if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid) {
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data 
            = vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_data;
        vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid = 1U;
    } else if (vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0) {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select) {
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data;
            vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid 
                = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid;
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__init_act_valid)))) {
        if (vlSelfRef.tpu_top__DOT__mlp_u__DOT____VdfgExtracted_hc1fd8ce0__0) {
            if ((1U & (~ (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__buffer_select)))) {
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_data;
                vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid 
                    = vlSelfRef.tpu_top__DOT__mlp_u__DOT__refill_valid;
            }
        }
    }
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_data 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_data;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a_wr_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_valid 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b_wr_valid;
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_read 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__rd_valid_comb));
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_read 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__rd_valid_comb));
}

void Vtop___024root___nba_sequent__TOP__28(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__28\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_act 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__row1_in;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__en_weight_pass;
}

void Vtop___024root___nba_sequent__TOP__29(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__29\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe11__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe01_11_psum;
}

void Vtop___024root___nba_sequent__TOP__30(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__30\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe10__DOT__in_psum 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__mmu_u__DOT__pe00_10_psum;
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff 
        = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__data_in 
           - vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__target_in);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff)
            : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__loss_u__DOT__diff);
}

void Vtop___024root___nba_sequent__TOP__31(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__31\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__norm_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__s1_data;
}

void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff 
        = (vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__data_in 
           - vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__target_in);
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff)
            : vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__loss_u__DOT__diff);
}

void Vtop___024root___nba_sequent__TOP__32(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__32\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_valid;
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__norm_u__DOT__data_in 
        = vlSelfRef.tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__s1_data;
}

void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__do_write 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_a__DOT__wr_valid));
}

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__do_write 
        = ((IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_ready) 
           & (IData)(vlSelfRef.tpu_top__DOT__mlp_u__DOT__ub_b__DOT__wr_valid));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__14(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__17(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__22(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__23(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__24(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__26(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__27(vlSelf);
    }
    if ((0x00000000000001a0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x0000000000000022ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x00000000000000a0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x0000000000000120ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__28(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__29(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__30(vlSelf);
    }
    if ((0x0000000000028000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__31(vlSelf);
    }
    if ((0x0000000000280000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__32(vlSelf);
    }
    if ((0x00000000000000a2ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x0000000000000122ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__8(vlSelf);
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/tpu_top.sv", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/tpu_top.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU-co/rtl/tpu_top.sv", 6, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.uart_rx & 0xfeU)))) {
        Verilated::overWidthError("uart_rx");
    }
}
#endif  // VL_DEBUG
