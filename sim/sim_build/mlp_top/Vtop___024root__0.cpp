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
    // Locals
    CData/*0:0*/ mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0;
    mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0 = 0;
    // Body
    vlSelfRef.mlp_top__DOT__start_mlp = vlSelfRef.start_mlp;
    vlSelfRef.mlp_top__DOT__weights_ready = vlSelfRef.weights_ready;
    vlSelfRef.layer_complete = vlSelfRef.mlp_top__DOT__layer_complete;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__loss_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_reg;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__loss_out;
    vlSelfRef.mlp_top__DOT__state = vlSelfRef.mlp_top__DOT__state_reg;
    vlSelfRef.mlp_top__DOT__cycle_cnt = vlSelfRef.mlp_top__DOT__cycle_cnt_reg;
    vlSelfRef.mlp_top__DOT__wf_push_col0 = vlSelfRef.wf_push_col0;
    vlSelfRef.mlp_top__DOT__wf_push_col1 = vlSelfRef.wf_push_col1;
    vlSelfRef.mlp_top__DOT__wf_data_in = vlSelfRef.wf_data_in;
    vlSelfRef.mlp_top__DOT__current_layer = vlSelfRef.mlp_top__DOT__current_layer_reg;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_01_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_10_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01_11_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10_11_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__accumulator_enable 
        = vlSelfRef.mlp_top__DOT__accum_en;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__addr_sel 
        = vlSelfRef.mlp_top__DOT__addr_sel;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_valid 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col1;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_reg;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_data_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_q_reg;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_data_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_q_reg;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__wf_reset = vlSelfRef.wf_reset;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_raw 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1
        [vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1];
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__target_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_d1;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__target_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_d1;
    vlSelfRef.mlp_top__DOT__wf_col1_out = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_out;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__full = (0x10U 
                                               == (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__full = (0x10U 
                                               == (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count));
    vlSelfRef.mlp_top__DOT__init_act_data = vlSelfRef.init_act_data;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_data = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_data = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__norm_bias = vlSelfRef.norm_bias;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc0_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc1_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col0_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col1_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col0_out 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0
        [vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0];
    vlSelfRef.mlp_top__DOT__q_zero_point = vlSelfRef.q_zero_point;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__norm_shift = vlSelfRef.norm_shift;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_data = vlSelfRef.mlp_top__DOT__ub_b__DOT__mem
        [vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ptr];
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_data = vlSelfRef.mlp_top__DOT__ub_a__DOT__mem
        [vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ptr];
    vlSelfRef.mlp_top__DOT__norm_gain = vlSelfRef.norm_gain;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__empty = (0U 
                                                == (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__empty = (0U 
                                                == (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count));
    vlSelfRef.mlp_top__DOT__q_inv_scale = vlSelfRef.q_inv_scale;
    vlSelfRef.mlp_top__DOT__init_act_valid = vlSelfRef.init_act_valid;
    vlSelfRef.mlp_top__DOT__transfer_phase = (5U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.mlp_top__DOT__reset = vlSelfRef.reset;
    vlSelfRef.mlp_top__DOT__drain_phase = (4U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__en_load_weight = (1U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__compute_phase = (3U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.state = vlSelfRef.mlp_top__DOT__state;
    vlSelfRef.cycle_cnt = vlSelfRef.mlp_top__DOT__cycle_cnt;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__push_col0 
        = vlSelfRef.mlp_top__DOT__wf_push_col0;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__push_col1 
        = vlSelfRef.mlp_top__DOT__wf_push_col1;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__wf_data_in;
    vlSelfRef.current_layer = vlSelfRef.mlp_top__DOT__current_layer;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_01_act;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_10_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01_11_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10_11_act;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__accumulator_enable;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__addr_sel;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__enable 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_valid;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c1;
    vlSelfRef.mlp_top__DOT__ap_valid = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_data_col0 = vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_data_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_valid;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_valid;
    vlSelfRef.mlp_top__DOT__ap_data_col1 = vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_data_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_valid;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_valid;
    vlSelfRef.mlp_top__DOT__wf_col1_raw = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_raw;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready = (1U 
                                                   & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__full)));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready = (1U 
                                                   & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__full)));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_data;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_data;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_bias 
        = vlSelfRef.mlp_top__DOT__norm_bias;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_bias 
        = vlSelfRef.mlp_top__DOT__norm_bias;
    vlSelfRef.mlp_top__DOT__mmu_acc0_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc0_out;
    vlSelfRef.mlp_top__DOT__mmu_acc1_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc1_out;
    vlSelfRef.mlp_top__DOT__acc0 = vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col0_out;
    vlSelfRef.mlp_top__DOT__acc1 = vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col1_out;
    vlSelfRef.mlp_top__DOT__wf_col0_out = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col0_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_zero_point 
        = vlSelfRef.mlp_top__DOT__q_zero_point;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_zero_point 
        = vlSelfRef.mlp_top__DOT__q_zero_point;
    vlSelfRef.mlp_top__DOT__acc_valid = vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_shift 
        = vlSelfRef.mlp_top__DOT__norm_shift;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_shift 
        = vlSelfRef.mlp_top__DOT__norm_shift;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data;
    vlSelfRef.mlp_top__DOT__ub_b_rd_data = vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_data;
    vlSelfRef.mlp_top__DOT__ub_a_rd_data = vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_data;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_gain 
        = vlSelfRef.mlp_top__DOT__norm_gain;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_gain 
        = vlSelfRef.mlp_top__DOT__norm_gain;
    vlSelfRef.mlp_top__DOT__ub_b_empty = vlSelfRef.mlp_top__DOT__ub_b__DOT__empty;
    vlSelfRef.mlp_top__DOT__ub_a_empty = vlSelfRef.mlp_top__DOT__ub_a__DOT__empty;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_inv_scale 
        = vlSelfRef.mlp_top__DOT__q_inv_scale;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_inv_scale 
        = vlSelfRef.mlp_top__DOT__q_inv_scale;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__clk = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__reset 
        = ((IData)(vlSelfRef.mlp_top__DOT__reset) | (IData)(vlSelfRef.mlp_top__DOT__wf_reset));
    vlSelfRef.mlp_top__DOT__accum_u__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__reset = vlSelfRef.mlp_top__DOT__reset;
    mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0 = ((IData)(vlSelfRef.mlp_top__DOT__drain_phase) 
                                                  | (IData)(vlSelfRef.mlp_top__DOT__transfer_phase));
    if (vlSelfRef.mlp_top__DOT__en_load_weight) {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__pop = 1U;
        vlSelfRef.mlp_top__DOT__mmu_col1_in = vlSelfRef.mlp_top__DOT__wf_col1_out;
        vlSelfRef.mlp_top__DOT__mmu_col0_in = vlSelfRef.mlp_top__DOT__wf_col0_out;
        vlSelfRef.mlp_top__DOT__en_capture_col0 = (1U 
                                                   == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg));
        vlSelfRef.mlp_top__DOT__en_capture_col1 = (2U 
                                                   == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg));
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass = 1U;
    } else {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__pop = 0U;
        vlSelfRef.mlp_top__DOT__mmu_col1_in = 0U;
        vlSelfRef.mlp_top__DOT__mmu_col0_in = 0U;
        vlSelfRef.mlp_top__DOT__en_capture_col0 = 0U;
        vlSelfRef.mlp_top__DOT__en_capture_col1 = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass = 0U;
    }
    vlSelfRef.mlp_top__DOT__mmu_valid = (((IData)(vlSelfRef.mlp_top__DOT__compute_phase) 
                                          & (2U <= (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) 
                                         | (IData)(vlSelfRef.mlp_top__DOT__drain_phase));
    vlSelfRef.mlp_top__DOT__ub_a_rd_ready = 0U;
    vlSelfRef.mlp_top__DOT__ub_b_rd_ready = 0U;
    if (vlSelfRef.mlp_top__DOT__compute_phase) {
        vlSelfRef.mlp_top__DOT__mmu_row1_in = vlSelfRef.mlp_top__DOT__row1_skew_reg;
        if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__buffer_select)))) {
            vlSelfRef.mlp_top__DOT__ub_a_rd_ready = 1U;
        }
        if (vlSelfRef.mlp_top__DOT__buffer_select) {
            vlSelfRef.mlp_top__DOT__ub_b_rd_ready = 1U;
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_row1_in = 0U;
    }
    vlSelfRef.mlp_top__DOT__ub_a_wr_ready = vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready;
    vlSelfRef.mlp_top__DOT__ub_b_wr_ready = vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_bias;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_bias;
    vlSelfRef.mmu_acc0_out = vlSelfRef.mlp_top__DOT__mmu_acc0_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col0_in 
        = vlSelfRef.mlp_top__DOT__mmu_acc0_out;
    vlSelfRef.mmu_acc1_out = vlSelfRef.mlp_top__DOT__mmu_acc1_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col1_in 
        = vlSelfRef.mlp_top__DOT__mmu_acc1_out;
    vlSelfRef.acc0 = vlSelfRef.mlp_top__DOT__acc0;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__acc_in = vlSelfRef.mlp_top__DOT__acc0;
    vlSelfRef.acc1 = vlSelfRef.mlp_top__DOT__acc1;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__acc_in = vlSelfRef.mlp_top__DOT__acc1;
    vlSelfRef.acc_valid = vlSelfRef.mlp_top__DOT__acc_valid;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__acc_valid;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__acc_valid;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_shift;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_shift;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff 
        = (vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__data_in 
           - vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__target_in);
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff 
        = (vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__data_in 
           - vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__target_in);
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__gain 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_gain;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__gain 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_gain;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult = (0x0000ffffffffffffULL 
                                                  & VL_MULS_QQQ(48, 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data)), 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_inv_scale)))));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult = (0x0000ffffffffffffULL 
                                                  & VL_MULS_QQQ(48, 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data)), 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_inv_scale)))));
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__clk 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__clk;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__reset 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__reset;
    vlSelfRef.mlp_top__DOT__ub_b_wr_data = 0U;
    vlSelfRef.mlp_top__DOT__ub_a_wr_data = 0U;
    vlSelfRef.mlp_top__DOT__ub_a_wr_valid = 0U;
    if (vlSelfRef.mlp_top__DOT__init_act_valid) {
        vlSelfRef.mlp_top__DOT__ub_a_wr_data = vlSelfRef.mlp_top__DOT__init_act_data;
        vlSelfRef.mlp_top__DOT__ub_a_wr_valid = 1U;
    } else if (mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0) {
        if (vlSelfRef.mlp_top__DOT__buffer_select) {
            vlSelfRef.mlp_top__DOT__ub_a_wr_data = vlSelfRef.mlp_top__DOT__refill_data;
            vlSelfRef.mlp_top__DOT__ub_a_wr_valid = vlSelfRef.mlp_top__DOT__refill_valid;
        }
    }
    vlSelfRef.mlp_top__DOT__ub_b_wr_valid = 0U;
    if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__init_act_valid)))) {
        if (mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0) {
            if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__buffer_select)))) {
                vlSelfRef.mlp_top__DOT__ub_b_wr_data 
                    = vlSelfRef.mlp_top__DOT__refill_data;
                vlSelfRef.mlp_top__DOT__ub_b_wr_valid 
                    = vlSelfRef.mlp_top__DOT__refill_valid;
            }
        }
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__col1_in = vlSelfRef.mlp_top__DOT__mmu_col1_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0 
        = vlSelfRef.mlp_top__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1 
        = vlSelfRef.mlp_top__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__row1_in = vlSelfRef.mlp_top__DOT__mmu_row1_in;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__mmu_valid;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ready = vlSelfRef.mlp_top__DOT__ub_a_rd_ready;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ready = vlSelfRef.mlp_top__DOT__ub_b_rd_ready;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col0_in;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col1_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__acc_in;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__acc_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__col0_in = vlSelfRef.mlp_top__DOT__mmu_col0_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_in;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff)
            : vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff);
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff)
            : vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff);
    vlSelfRef.mlp_top__DOT__act_ub_rd_data = ((IData)(vlSelfRef.mlp_top__DOT__buffer_select)
                                               ? (IData)(vlSelfRef.mlp_top__DOT__ub_b_rd_data)
                                               : (IData)(vlSelfRef.mlp_top__DOT__ub_a_rd_data));
    vlSelfRef.mlp_top__DOT__act_row1_data = (0x000000ffU 
                                             & ((IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_data) 
                                                >> 8U));
    vlSelfRef.mlp_top__DOT__act_row0_data = (0x000000ffU 
                                             & (IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_data));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__gain)))));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__gain)))));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_data = vlSelfRef.mlp_top__DOT__ub_b_wr_data;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_data = vlSelfRef.mlp_top__DOT__ub_a_wr_data;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_valid = vlSelfRef.mlp_top__DOT__ub_a_wr_valid;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_valid = vlSelfRef.mlp_top__DOT__ub_b_wr_valid;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__col1_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__row1_in;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_in;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read = ((~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__empty)) 
                                                  & (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ready));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read = ((~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__empty)) 
                                                  & (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ready));
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__col0_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift)));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift)));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__scaled = (IData)(
                                                           (0x0000ffffffffffffULL 
                                                            & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult_rounded, 8U)));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__scaled = (IData)(
                                                           (0x0000ffffffffffffULL 
                                                            & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult_rounded, 8U)));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__do_write = ((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready) 
                                                   & (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_valid));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__do_write = ((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready) 
                                                   & (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_valid));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_valid = vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_valid = vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__biased = 
        (vlSelfRef.mlp_top__DOT__ap_col0__DOT__scaled 
         + (((- (IData)((1U & ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_zero_point) 
                               >> 7U)))) << 8U) | (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_zero_point)));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__biased = 
        (vlSelfRef.mlp_top__DOT__ap_col1__DOT__scaled 
         + (((- (IData)((1U & ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_zero_point) 
                               >> 7U)))) << 8U) | (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_zero_point)));
    vlSelfRef.mlp_top__DOT__ub_a_rd_valid = vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_valid;
    vlSelfRef.mlp_top__DOT__ub_b_rd_valid = vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_valid;
    if (vlSelfRef.mlp_top__DOT__buffer_select) {
        vlSelfRef.mlp_top__DOT__act_ub_empty = vlSelfRef.mlp_top__DOT__ub_b_empty;
        vlSelfRef.mlp_top__DOT__act_ub_rd_valid = vlSelfRef.mlp_top__DOT__ub_b_rd_valid;
    } else {
        vlSelfRef.mlp_top__DOT__act_ub_empty = vlSelfRef.mlp_top__DOT__ub_a_empty;
        vlSelfRef.mlp_top__DOT__act_ub_rd_valid = vlSelfRef.mlp_top__DOT__ub_a_rd_valid;
    }
    vlSelfRef.mlp_top__DOT__mmu_row0_in = (((IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_valid) 
                                            & (IData)(vlSelfRef.mlp_top__DOT__compute_phase))
                                            ? (IData)(vlSelfRef.mlp_top__DOT__act_row0_data)
                                            : 0U);
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__row0_in = vlSelfRef.mlp_top__DOT__mmu_row0_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__row0_in;
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
    vlSelfRef.__VactTriggered[0U] = (((QData)((IData)(
                                                      (((((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset__0))) 
                                                         << 3U) 
                                                        | (((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk__0))) 
                                                           << 2U)) 
                                                       | ((((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset__0))) 
                                                           << 1U) 
                                                          | ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk__0))))))) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(
                                                       ((((((((((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset__0))) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk__0))) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__reset__0))) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__clk__0))))) 
                                                            << 0x0000000cU) 
                                                           | ((((((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset__0))) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk__0))) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset__0))) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk__0))))) 
                                                              << 8U)) 
                                                          | (((((((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset__0))) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk__0))) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__reset__0))) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__clk__0))))) 
                                                              << 4U) 
                                                             | (((((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset__0))) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk__0))) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__reset) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__reset__0))) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__clk) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__clk__0))))))) 
                                                         << 0x00000010U) 
                                                        | ((((((((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset__0))) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk__0))) 
                                                                  << 2U)) 
                                                              | ((((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset__0))) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk__0))))) 
                                                             << 0x0000000cU) 
                                                            | ((((((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset__0))) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk__0))) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset__0))) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk__0))))) 
                                                               << 8U)) 
                                                           | (((((((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__reset) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__reset__0))) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__clk) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__clk__0))) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__reset) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__reset__0))) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__clk) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__clk__0))))) 
                                                               << 4U) 
                                                              | (((((IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__reset) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__reset__0))) 
                                                                   << 3U) 
                                                                  | (((IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__clk) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__clk__0))) 
                                                                     << 2U)) 
                                                                 | ((((IData)(vlSelfRef.mlp_top__DOT__reset) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__reset__0))) 
                                                                     << 1U) 
                                                                    | ((IData)(vlSelfRef.mlp_top__DOT__clk) 
                                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__clk__0)))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__weight_fifo_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ub_a__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_a__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ub_a__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ub_b__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ub_b__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ub_b__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_align__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset__0 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset;
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
    // Locals
    SData/*15:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = 0;
    CData/*0:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending = 0;
    // Body
    __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__pending;
    if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__reset) {
        __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg = 0U;
        __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending = 0U;
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 0U;
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col0 = 0U;
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col1 = 0U;
    } else {
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 0U;
        if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__valid_in) {
            if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__pending) {
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid = 1U;
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col0 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col1 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col1;
                __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col0;
            } else {
                __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col0;
                __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending = 1U;
            }
        } else {
            __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending = 0U;
        }
    }
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__col0_delay_reg;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__pending 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_align__DOT__pending;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_valid 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__aligned_valid;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__align_col1;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 = 0;
    CData/*1:0*/ __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 = 0;
    CData/*1:0*/ __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 = 0;
    CData/*1:0*/ __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v0;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v0 = 0;
    CData/*7:0*/ __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4;
    __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 = 0;
    CData/*1:0*/ __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4;
    __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v0;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v0 = 0;
    CData/*7:0*/ __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4;
    __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 = 0;
    CData/*1:0*/ __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4;
    __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 = 0;
    // Body
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v0 = 0U;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 = 0U;
    __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v0 = 0U;
    __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 = 0U;
    if (vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__reset) {
        __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 = 0U;
        __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 = 0U;
        __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v0 = 1U;
        __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 = 0U;
        __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v0 = 1U;
        __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_out = 0U;
    } else {
        if (vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__pop) {
            __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0)));
            vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_out 
                = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1
                [vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1];
            __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1)));
        }
        if (vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__push_col1) {
            __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 
                = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__data_in;
            __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 
                = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1;
            __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4 = 1U;
            __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1)));
        }
        if (vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__push_col0) {
            __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 
                = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__data_in;
            __VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 
                = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0;
            __VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4 = 1U;
            __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0)));
        }
    }
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0 
        = __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1 
        = __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr1;
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0 
        = __Vdly__mlp_top__DOT__weight_fifo_u__DOT__wr_ptr0;
    if (__VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v0) {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[0U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[1U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[2U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[3U] = 0U;
    }
    if (__VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4) {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0[__VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4] 
            = __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue0__v4;
    }
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1 
        = __Vdly__mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1;
    if (__VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v0) {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[0U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[1U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[2U] = 0U;
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[3U] = 0U;
    }
    if (__VdlySet__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4) {
        vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1[__VdlyDim0__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4] 
            = __VdlyVal__mlp_top__DOT__weight_fifo_u__DOT__queue1__v4;
    }
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col0_out 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue0
        [vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr0];
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_raw 
        = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__queue1
        [vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__rd_ptr1];
    vlSelfRef.mlp_top__DOT__wf_col1_out = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_out;
    vlSelfRef.mlp_top__DOT__wf_col0_out = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col0_out;
    vlSelfRef.mlp_top__DOT__wf_col1_raw = vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__col1_raw;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr;
    __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr = 0;
    CData/*3:0*/ __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr;
    __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr = 0;
    CData/*4:0*/ __Vdly__mlp_top__DOT__ub_a__DOT__count;
    __Vdly__mlp_top__DOT__ub_a__DOT__count = 0;
    SData/*15:0*/ __VdlyVal__mlp_top__DOT__ub_a__DOT__mem__v0;
    __VdlyVal__mlp_top__DOT__ub_a__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__mlp_top__DOT__ub_a__DOT__mem__v0;
    __VdlyDim0__mlp_top__DOT__ub_a__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__ub_a__DOT__mem__v0;
    __VdlySet__mlp_top__DOT__ub_a__DOT__mem__v0 = 0;
    // Body
    __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr = vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ptr;
    __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr = vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ptr;
    __VdlySet__mlp_top__DOT__ub_a__DOT__mem__v0 = 0U;
    __Vdly__mlp_top__DOT__ub_a__DOT__count = vlSelfRef.mlp_top__DOT__ub_a__DOT__count;
    if (vlSelfRef.mlp_top__DOT__ub_a__DOT__reset) {
        __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr = 0U;
        __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr = 0U;
        __Vdly__mlp_top__DOT__ub_a__DOT__count = 0U;
    } else {
        if (vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read) {
            __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ptr)));
        }
        if (vlSelfRef.mlp_top__DOT__ub_a__DOT__do_write) {
            __VdlyVal__mlp_top__DOT__ub_a__DOT__mem__v0 
                = vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_data;
            __VdlyDim0__mlp_top__DOT__ub_a__DOT__mem__v0 
                = vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ptr;
            __VdlySet__mlp_top__DOT__ub_a__DOT__mem__v0 = 1U;
            __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ptr)));
        }
        if (((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__do_write) 
             & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read)))) {
            __Vdly__mlp_top__DOT__ub_a__DOT__count 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count)));
        } else if (((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read) 
                    & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__do_write)))) {
            __Vdly__mlp_top__DOT__ub_a__DOT__count 
                = (0x0000001fU & ((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count) 
                                  - (IData)(1U)));
        }
    }
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ptr = __Vdly__mlp_top__DOT__ub_a__DOT__rd_ptr;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ptr = __Vdly__mlp_top__DOT__ub_a__DOT__wr_ptr;
    if (__VdlySet__mlp_top__DOT__ub_a__DOT__mem__v0) {
        vlSelfRef.mlp_top__DOT__ub_a__DOT__mem[__VdlyDim0__mlp_top__DOT__ub_a__DOT__mem__v0] 
            = __VdlyVal__mlp_top__DOT__ub_a__DOT__mem__v0;
    }
    vlSelfRef.mlp_top__DOT__ub_a__DOT__count = __Vdly__mlp_top__DOT__ub_a__DOT__count;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_data = vlSelfRef.mlp_top__DOT__ub_a__DOT__mem
        [vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ptr];
    vlSelfRef.mlp_top__DOT__ub_a__DOT__full = (0x10U 
                                               == (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__empty = (0U 
                                                == (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_a_rd_data = vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_data;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready = (1U 
                                                   & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__full)));
    vlSelfRef.mlp_top__DOT__ub_a_empty = vlSelfRef.mlp_top__DOT__ub_a__DOT__empty;
    vlSelfRef.mlp_top__DOT__ub_a_wr_ready = vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr;
    __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr = 0;
    CData/*3:0*/ __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr;
    __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr = 0;
    CData/*4:0*/ __Vdly__mlp_top__DOT__ub_b__DOT__count;
    __Vdly__mlp_top__DOT__ub_b__DOT__count = 0;
    SData/*15:0*/ __VdlyVal__mlp_top__DOT__ub_b__DOT__mem__v0;
    __VdlyVal__mlp_top__DOT__ub_b__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__mlp_top__DOT__ub_b__DOT__mem__v0;
    __VdlyDim0__mlp_top__DOT__ub_b__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__mlp_top__DOT__ub_b__DOT__mem__v0;
    __VdlySet__mlp_top__DOT__ub_b__DOT__mem__v0 = 0;
    // Body
    __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr = vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ptr;
    __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr = vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ptr;
    __VdlySet__mlp_top__DOT__ub_b__DOT__mem__v0 = 0U;
    __Vdly__mlp_top__DOT__ub_b__DOT__count = vlSelfRef.mlp_top__DOT__ub_b__DOT__count;
    if (vlSelfRef.mlp_top__DOT__ub_b__DOT__reset) {
        __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr = 0U;
        __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr = 0U;
        __Vdly__mlp_top__DOT__ub_b__DOT__count = 0U;
    } else {
        if (vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read) {
            __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ptr)));
        }
        if (vlSelfRef.mlp_top__DOT__ub_b__DOT__do_write) {
            __VdlyVal__mlp_top__DOT__ub_b__DOT__mem__v0 
                = vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_data;
            __VdlyDim0__mlp_top__DOT__ub_b__DOT__mem__v0 
                = vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ptr;
            __VdlySet__mlp_top__DOT__ub_b__DOT__mem__v0 = 1U;
            __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ptr)));
        }
        if (((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__do_write) 
             & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read)))) {
            __Vdly__mlp_top__DOT__ub_b__DOT__count 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count)));
        } else if (((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read) 
                    & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__do_write)))) {
            __Vdly__mlp_top__DOT__ub_b__DOT__count 
                = (0x0000001fU & ((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count) 
                                  - (IData)(1U)));
        }
    }
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ptr = __Vdly__mlp_top__DOT__ub_b__DOT__rd_ptr;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ptr = __Vdly__mlp_top__DOT__ub_b__DOT__wr_ptr;
    if (__VdlySet__mlp_top__DOT__ub_b__DOT__mem__v0) {
        vlSelfRef.mlp_top__DOT__ub_b__DOT__mem[__VdlyDim0__mlp_top__DOT__ub_b__DOT__mem__v0] 
            = __VdlyVal__mlp_top__DOT__ub_b__DOT__mem__v0;
    }
    vlSelfRef.mlp_top__DOT__ub_b__DOT__count = __Vdly__mlp_top__DOT__ub_b__DOT__count;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_data = vlSelfRef.mlp_top__DOT__ub_b__DOT__mem
        [vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ptr];
    vlSelfRef.mlp_top__DOT__ub_b__DOT__full = (0x10U 
                                               == (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__empty = (0U 
                                                == (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__count));
    vlSelfRef.mlp_top__DOT__ub_b_rd_data = vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_data;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready = (1U 
                                                   & (~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__full)));
    vlSelfRef.mlp_top__DOT__ub_b_empty = vlSelfRef.mlp_top__DOT__ub_b__DOT__empty;
    vlSelfRef.mlp_top__DOT__ub_b_wr_ready = vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = 0;
    IData/*31:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = 0;
    IData/*31:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = 0;
    IData/*31:0*/ __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = 0;
    // Body
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__reset) {
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out = 0U;
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 = 0U;
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 = 0U;
        __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 = 0U;
        __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 = 0U;
        __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 = 0U;
        __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 = 0U;
    } else if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__enable) {
        if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select) 
                                   << 1U) | (1U & (~ (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select)))))))) {
            if ((0U == (((IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select) 
                         << 1U) | (1U & (~ (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Nmlp_top.accum_u.u_mem: unique case, but none matched for '1'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 1,(IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select));
                    VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator_mem.sv", 39, "");
                }
            } else if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: accumulator_mem.sv:39: Assertion failed in %Nmlp_top.accum_u.u_mem: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select));
                VL_STOP_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/accumulator_mem.sv", 39, "");
            }
        }
        if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select) {
            if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode) {
                __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                    = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0));
                __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                    = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1));
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                    = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                       + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0));
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                    = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                       + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1));
            } else {
                __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0;
                __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1;
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0;
                vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                    = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1;
            }
        } else if (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode) {
            __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0));
            __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1));
            vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                   + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0));
            vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                = (vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                   + (IData)(vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1));
        } else {
            __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
                = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0;
            __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
                = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1;
            vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0 
                = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0;
            vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1 
                = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1;
        }
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out = 1U;
    } else {
        vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out = 0U;
    }
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff0_col1;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1 
        = __Vdly__mlp_top__DOT__accum_u__DOT__u_mem__DOT__mem_buff1_col1;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col0_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col1_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__out_col1;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__acc0 = vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col0_out;
    vlSelfRef.mlp_top__DOT__acc1 = vlSelfRef.mlp_top__DOT__accum_u__DOT__acc_col1_out;
    vlSelfRef.mlp_top__DOT__acc_valid = vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_out;
    vlSelfRef.acc0 = vlSelfRef.mlp_top__DOT__acc0;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__acc_in = vlSelfRef.mlp_top__DOT__acc0;
    vlSelfRef.acc1 = vlSelfRef.mlp_top__DOT__acc1;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__acc_in = vlSelfRef.mlp_top__DOT__acc1;
    vlSelfRef.acc_valid = vlSelfRef.mlp_top__DOT__acc_valid;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0;
    mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0 = 0;
    CData/*3:0*/ __Vdly__mlp_top__DOT__state_reg;
    __Vdly__mlp_top__DOT__state_reg = 0;
    CData/*4:0*/ __Vdly__mlp_top__DOT__cycle_cnt_reg;
    __Vdly__mlp_top__DOT__cycle_cnt_reg = 0;
    CData/*2:0*/ __Vdly__mlp_top__DOT__current_layer_reg;
    __Vdly__mlp_top__DOT__current_layer_reg = 0;
    CData/*0:0*/ __Vdly__mlp_top__DOT__buffer_select;
    __Vdly__mlp_top__DOT__buffer_select = 0;
    // Body
    __Vdly__mlp_top__DOT__current_layer_reg = vlSelfRef.mlp_top__DOT__current_layer_reg;
    __Vdly__mlp_top__DOT__cycle_cnt_reg = vlSelfRef.mlp_top__DOT__cycle_cnt_reg;
    __Vdly__mlp_top__DOT__buffer_select = vlSelfRef.mlp_top__DOT__buffer_select;
    __Vdly__mlp_top__DOT__state_reg = vlSelfRef.mlp_top__DOT__state_reg;
    if (vlSelfRef.mlp_top__DOT__reset) {
        vlSelfRef.mlp_top__DOT__accum_en = 0U;
        vlSelfRef.mlp_top__DOT__addr_sel = 0U;
        vlSelfRef.mlp_top__DOT__refill_data = 0U;
        vlSelfRef.mlp_top__DOT__refill_valid = 0U;
        vlSelfRef.mlp_top__DOT__row1_skew_reg = 0U;
        __Vdly__mlp_top__DOT__state_reg = 0U;
        __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
        __Vdly__mlp_top__DOT__current_layer_reg = 0U;
        __Vdly__mlp_top__DOT__buffer_select = 0U;
        vlSelfRef.mlp_top__DOT__weights_loaded = 0U;
        vlSelfRef.mlp_top__DOT__layer_complete = 0U;
    } else {
        vlSelfRef.mlp_top__DOT__refill_valid = 0U;
        if (vlSelfRef.mlp_top__DOT__ap_valid) {
            vlSelfRef.mlp_top__DOT__refill_data = (
                                                   ((IData)(vlSelfRef.mlp_top__DOT__ap_data_col1) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.mlp_top__DOT__ap_data_col0));
            vlSelfRef.mlp_top__DOT__refill_valid = 1U;
        }
        if (((IData)(vlSelfRef.mlp_top__DOT__compute_phase) 
             & (IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_valid))) {
            vlSelfRef.mlp_top__DOT__row1_skew_reg = vlSelfRef.mlp_top__DOT__act_row1_data;
        }
        if ((8U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
            if ((4U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                __Vdly__mlp_top__DOT__state_reg = 0U;
            } else if ((2U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                __Vdly__mlp_top__DOT__state_reg = 0U;
            } else if ((1U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                __Vdly__mlp_top__DOT__state_reg = 0U;
            } else {
                vlSelfRef.mlp_top__DOT__layer_complete = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
            if ((2U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                if ((1U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                    __Vdly__mlp_top__DOT__cycle_cnt_reg 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
                    if (vlSelfRef.mlp_top__DOT__weights_ready) {
                        __Vdly__mlp_top__DOT__state_reg = 1U;
                        __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                    }
                } else {
                    __Vdly__mlp_top__DOT__buffer_select 
                        = (1U & (~ (IData)(vlSelfRef.mlp_top__DOT__buffer_select)));
                    __Vdly__mlp_top__DOT__current_layer_reg 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__current_layer_reg)));
                    __Vdly__mlp_top__DOT__state_reg = 7U;
                    __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                    vlSelfRef.mlp_top__DOT__weights_loaded = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                __Vdly__mlp_top__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
                if ((3U == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) {
                    __Vdly__mlp_top__DOT__state_reg = 6U;
                    __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                }
            } else {
                __Vdly__mlp_top__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
                if ((6U == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) {
                    if ((1U > (IData)(vlSelfRef.mlp_top__DOT__current_layer_reg))) {
                        __Vdly__mlp_top__DOT__state_reg = 5U;
                        __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                    } else {
                        __Vdly__mlp_top__DOT__state_reg = 8U;
                        __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
            if ((1U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
                __Vdly__mlp_top__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
                if ((2U == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) {
                    __Vdly__mlp_top__DOT__state_reg = 4U;
                    __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                }
            } else {
                __Vdly__mlp_top__DOT__cycle_cnt_reg 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
                if ((3U == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) {
                    __Vdly__mlp_top__DOT__state_reg = 3U;
                    __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.mlp_top__DOT__state_reg))) {
            __Vdly__mlp_top__DOT__cycle_cnt_reg = (0x0000001fU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
            if ((2U == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) {
                __Vdly__mlp_top__DOT__state_reg = (
                                                   (0U 
                                                    == (IData)(vlSelfRef.mlp_top__DOT__current_layer_reg))
                                                    ? 2U
                                                    : 3U);
                __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
                vlSelfRef.mlp_top__DOT__weights_loaded = 1U;
            }
        } else {
            __Vdly__mlp_top__DOT__cycle_cnt_reg = 0U;
            if (vlSelfRef.mlp_top__DOT__start_mlp) {
                __Vdly__mlp_top__DOT__state_reg = 1U;
                __Vdly__mlp_top__DOT__current_layer_reg = 0U;
                __Vdly__mlp_top__DOT__buffer_select = 0U;
            }
        }
    }
    vlSelfRef.mlp_top__DOT__current_layer_reg = __Vdly__mlp_top__DOT__current_layer_reg;
    vlSelfRef.mlp_top__DOT__cycle_cnt_reg = __Vdly__mlp_top__DOT__cycle_cnt_reg;
    vlSelfRef.mlp_top__DOT__buffer_select = __Vdly__mlp_top__DOT__buffer_select;
    vlSelfRef.mlp_top__DOT__state_reg = __Vdly__mlp_top__DOT__state_reg;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__accumulator_enable 
        = vlSelfRef.mlp_top__DOT__accum_en;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__addr_sel 
        = vlSelfRef.mlp_top__DOT__addr_sel;
    vlSelfRef.layer_complete = vlSelfRef.mlp_top__DOT__layer_complete;
    vlSelfRef.mlp_top__DOT__current_layer = vlSelfRef.mlp_top__DOT__current_layer_reg;
    vlSelfRef.mlp_top__DOT__cycle_cnt = vlSelfRef.mlp_top__DOT__cycle_cnt_reg;
    vlSelfRef.mlp_top__DOT__state = vlSelfRef.mlp_top__DOT__state_reg;
    vlSelfRef.mlp_top__DOT__transfer_phase = (5U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__drain_phase = (4U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__en_load_weight = (1U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__compute_phase = (3U == (IData)(vlSelfRef.mlp_top__DOT__state_reg));
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__accumulator_mode 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__accumulator_enable;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__buffer_select 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__addr_sel;
    vlSelfRef.current_layer = vlSelfRef.mlp_top__DOT__current_layer;
    vlSelfRef.cycle_cnt = vlSelfRef.mlp_top__DOT__cycle_cnt;
    vlSelfRef.state = vlSelfRef.mlp_top__DOT__state;
    mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0 = ((IData)(vlSelfRef.mlp_top__DOT__drain_phase) 
                                                  | (IData)(vlSelfRef.mlp_top__DOT__transfer_phase));
    vlSelfRef.mlp_top__DOT__weight_fifo_u__DOT__pop 
        = vlSelfRef.mlp_top__DOT__en_load_weight;
    vlSelfRef.mlp_top__DOT__en_capture_col0 = ((IData)(vlSelfRef.mlp_top__DOT__en_load_weight) 
                                               & (1U 
                                                  == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
    vlSelfRef.mlp_top__DOT__en_capture_col1 = ((IData)(vlSelfRef.mlp_top__DOT__en_load_weight) 
                                               & (2U 
                                                  == (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg)));
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__en_load_weight;
    vlSelfRef.mlp_top__DOT__mmu_valid = (((IData)(vlSelfRef.mlp_top__DOT__compute_phase) 
                                          & (2U <= (IData)(vlSelfRef.mlp_top__DOT__cycle_cnt_reg))) 
                                         | (IData)(vlSelfRef.mlp_top__DOT__drain_phase));
    vlSelfRef.mlp_top__DOT__ub_a_rd_ready = 0U;
    vlSelfRef.mlp_top__DOT__ub_b_rd_ready = 0U;
    if (vlSelfRef.mlp_top__DOT__compute_phase) {
        vlSelfRef.mlp_top__DOT__mmu_row1_in = vlSelfRef.mlp_top__DOT__row1_skew_reg;
        if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__buffer_select)))) {
            vlSelfRef.mlp_top__DOT__ub_a_rd_ready = 1U;
        }
        if (vlSelfRef.mlp_top__DOT__buffer_select) {
            vlSelfRef.mlp_top__DOT__ub_b_rd_ready = 1U;
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_row1_in = 0U;
    }
    vlSelfRef.mlp_top__DOT__ub_b_wr_data = 0U;
    vlSelfRef.mlp_top__DOT__ub_a_wr_data = 0U;
    vlSelfRef.mlp_top__DOT__ub_a_wr_valid = 0U;
    if (vlSelfRef.mlp_top__DOT__init_act_valid) {
        vlSelfRef.mlp_top__DOT__ub_a_wr_data = vlSelfRef.mlp_top__DOT__init_act_data;
        vlSelfRef.mlp_top__DOT__ub_a_wr_valid = 1U;
    } else if (mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0) {
        if (vlSelfRef.mlp_top__DOT__buffer_select) {
            vlSelfRef.mlp_top__DOT__ub_a_wr_data = vlSelfRef.mlp_top__DOT__refill_data;
            vlSelfRef.mlp_top__DOT__ub_a_wr_valid = vlSelfRef.mlp_top__DOT__refill_valid;
        }
    }
    vlSelfRef.mlp_top__DOT__ub_b_wr_valid = 0U;
    if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__init_act_valid)))) {
        if (mlp_top__DOT____VdfgExtracted_hc1fd8ce0__0) {
            if ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__buffer_select)))) {
                vlSelfRef.mlp_top__DOT__ub_b_wr_data 
                    = vlSelfRef.mlp_top__DOT__refill_data;
                vlSelfRef.mlp_top__DOT__ub_b_wr_valid 
                    = vlSelfRef.mlp_top__DOT__refill_valid;
            }
        }
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0 
        = vlSelfRef.mlp_top__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1 
        = vlSelfRef.mlp_top__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__row1_in = vlSelfRef.mlp_top__DOT__mmu_row1_in;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__mmu_valid;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ready = vlSelfRef.mlp_top__DOT__ub_a_rd_ready;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ready = vlSelfRef.mlp_top__DOT__ub_b_rd_ready;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_data = vlSelfRef.mlp_top__DOT__ub_b_wr_data;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_data = vlSelfRef.mlp_top__DOT__ub_a_wr_data;
    vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_valid = vlSelfRef.mlp_top__DOT__ub_a_wr_valid;
    vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_valid = vlSelfRef.mlp_top__DOT__ub_b_wr_valid;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__valid_in;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__loss_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset)
            ? 0U : vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__abs_diff);
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__loss_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__loss_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset)
            ? 0U : vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__abs_diff);
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__loss_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_out;
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__Vfuncout;
    __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val;
    __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val = 0;
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_valid));
    if (vlSelfRef.mlp_top__DOT__ap_col1__DOT__reset) {
        vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_q_reg = 0U;
        vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_d1 = 0U;
    } else {
        __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val 
            = vlSelfRef.mlp_top__DOT__ap_col1__DOT__biased;
        __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__Vfuncout 
            = (VL_LTS_III(32, 0x0000007fU, __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val)
                ? 0x0000007fU : (VL_GTS_III(32, 0xffffff80U, __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val)
                                  ? 0x00000080U : (0x000000ffU 
                                                   & __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__val)));
        vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_q_reg 
            = __Vfunc_mlp_top__DOT__ap_col1__DOT__sat_int8__1__Vfuncout;
        if (vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_in) {
            vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_d1 
                = vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_in;
        }
    }
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_reg;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_data_out 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_q_reg;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__target_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__target_d1;
    vlSelfRef.mlp_top__DOT__ap_data_col1 = vlSelfRef.mlp_top__DOT__ap_col1__DOT__ub_data_out;
}

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__reset)
            ? 0U : ((vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_in 
                     >> 0x1fU) ? 0U : vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_in));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_data = vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_data;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__gain)))));
}

void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__reset)
            ? 0U : ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shifted) 
                    + vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__bias));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult = (0x0000ffffffffffffULL 
                                                  & VL_MULS_QQQ(48, 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_data)), 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_inv_scale)))));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__scaled = (IData)(
                                                           (0x0000ffffffffffffULL 
                                                            & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.mlp_top__DOT__ap_col0__DOT__mult_rounded, 8U)));
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__reset)
            ? 0U : ((vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_in 
                     >> 0x1fU) ? 0U : vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_in));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_data = vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_data;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult 
        = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_in)), 
                                               (0x0000ffffffffffffULL 
                                                & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__gain)))));
}

void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_out 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_in));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_out 
        = ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__reset)
            ? 0U : ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shifted) 
                    + vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__bias));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_valid 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data = vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__data_out;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_valid;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult = (0x0000ffffffffffffULL 
                                                  & VL_MULS_QQQ(48, 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__s2_data)), 
                                                                (0x0000ffffffffffffULL 
                                                                 & VL_EXTENDS_QI(48,16, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_inv_scale)))));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult_rounded 
        = (0x0000ffffffffffffULL & (0x0000000000000080ULL 
                                    + vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__scaled = (IData)(
                                                           (0x0000ffffffffffffULL 
                                                            & VL_SHIFTRS_QQI(48,48,32, vlSelfRef.mlp_top__DOT__ap_col1__DOT__mult_rounded, 8U)));
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__biased = 
        (vlSelfRef.mlp_top__DOT__ap_col1__DOT__scaled 
         + (((- (IData)((1U & ((IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_zero_point) 
                               >> 7U)))) << 8U) | (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__q_zero_point)));
}

void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__reset) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__weight = 0U;
    } else if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum));
        if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture) {
            vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum));
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_act 
            = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_act;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_act) 
                               * (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__weight)) 
                              + (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum)));
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01_11_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__out_psum;
}

void Vtop___024root___nba_sequent__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__reset) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__weight = 0U;
    } else if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum));
        if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture) {
            vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum));
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_act 
            = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_act;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_act) 
                               * (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__weight)) 
                              + (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum)));
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc1_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_acc1_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc1_out;
    vlSelfRef.mmu_acc1_out = vlSelfRef.mlp_top__DOT__mmu_acc1_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col1_in 
        = vlSelfRef.mlp_top__DOT__mmu_acc1_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col1_in;
}

void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__Vfuncout;
    __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val;
    __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val = 0;
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset))) 
           && (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_valid));
    if (vlSelfRef.mlp_top__DOT__ap_col0__DOT__reset) {
        vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_q_reg = 0U;
        vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_d1 = 0U;
    } else {
        __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val 
            = vlSelfRef.mlp_top__DOT__ap_col0__DOT__biased;
        __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__Vfuncout 
            = (VL_LTS_III(32, 0x0000007fU, __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val)
                ? 0x0000007fU : (VL_GTS_III(32, 0xffffff80U, __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val)
                                  ? 0x00000080U : (0x000000ffU 
                                                   & __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__val)));
        vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_q_reg 
            = __Vfunc_mlp_top__DOT__ap_col0__DOT__sat_int8__0__Vfuncout;
        if (vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_in) {
            vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_d1 
                = vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_in;
        }
    }
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_reg;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_data_out 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_q_reg;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__target_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__target_d1;
    vlSelfRef.mlp_top__DOT__ap_valid = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_data_col0 = vlSelfRef.mlp_top__DOT__ap_col0__DOT__ub_data_out;
}

void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__reset) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__weight = 0U;
    } else if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum));
        if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture) {
            vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum));
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act 
            = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_act;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_act) 
                               * (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__weight)) 
                              + (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum)));
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_01_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_act;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_10_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_01_act;
}

void Vtop___024root___nba_sequent__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__reset) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__weight = 0U;
    } else if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass) {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act = 0U;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum 
            = (0x0000ffffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum));
        if (vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture) {
            vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__weight 
                = (0x000000ffU & (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum));
        }
    } else {
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act 
            = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_act;
        vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum 
            = (0x0000ffffU & (((IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_act) 
                               * (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__weight)) 
                              + (IData)(vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum)));
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10_11_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_act;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc0_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__out_psum;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10_11_act;
    vlSelfRef.mlp_top__DOT__mmu_acc0_out = vlSelfRef.mlp_top__DOT__mmu_u__DOT__acc0_out;
    vlSelfRef.mmu_acc0_out = vlSelfRef.mlp_top__DOT__mmu_acc0_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col0_in 
        = vlSelfRef.mlp_top__DOT__mmu_acc0_out;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_align__DOT__raw_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__mmu_col0_in;
}

void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__enable 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_valid;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col0 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c0;
    vlSelfRef.mlp_top__DOT__accum_u__DOT__u_mem__DOT__in_col1 
        = vlSelfRef.mlp_top__DOT__accum_u__DOT__aligned_c1;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__buffer_select) {
        vlSelfRef.mlp_top__DOT__act_ub_empty = vlSelfRef.mlp_top__DOT__ub_b_empty;
        vlSelfRef.mlp_top__DOT__act_ub_rd_data = vlSelfRef.mlp_top__DOT__ub_b_rd_data;
    } else {
        vlSelfRef.mlp_top__DOT__act_ub_empty = vlSelfRef.mlp_top__DOT__ub_a_empty;
        vlSelfRef.mlp_top__DOT__act_ub_rd_data = vlSelfRef.mlp_top__DOT__ub_a_rd_data;
    }
    vlSelfRef.mlp_top__DOT__act_row1_data = (0x000000ffU 
                                             & ((IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_data) 
                                                >> 8U));
    vlSelfRef.mlp_top__DOT__act_row0_data = (0x000000ffU 
                                             & (IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_data));
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.mlp_top__DOT__en_load_weight) {
        vlSelfRef.mlp_top__DOT__mmu_col1_in = vlSelfRef.mlp_top__DOT__wf_col1_out;
        vlSelfRef.mlp_top__DOT__mmu_col0_in = vlSelfRef.mlp_top__DOT__wf_col0_out;
    } else {
        vlSelfRef.mlp_top__DOT__mmu_col1_in = 0U;
        vlSelfRef.mlp_top__DOT__mmu_col0_in = 0U;
    }
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__col1_in = vlSelfRef.mlp_top__DOT__mmu_col1_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__col0_in = vlSelfRef.mlp_top__DOT__mmu_col0_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__col1_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__col0_in;
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read = ((~ (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__empty)) 
                                                  & (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_ready));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__do_write = ((IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_ready) 
                                                   & (IData)(vlSelfRef.mlp_top__DOT__ub_a__DOT__wr_valid));
    vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_valid = vlSelfRef.mlp_top__DOT__ub_a__DOT__do_read;
    vlSelfRef.mlp_top__DOT__ub_a_rd_valid = vlSelfRef.mlp_top__DOT__ub_a__DOT__rd_valid;
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read = ((~ (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__empty)) 
                                                  & (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_ready));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__do_write = ((IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_ready) 
                                                   & (IData)(vlSelfRef.mlp_top__DOT__ub_b__DOT__wr_valid));
    vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_valid = vlSelfRef.mlp_top__DOT__ub_b__DOT__do_read;
    vlSelfRef.mlp_top__DOT__ub_b_rd_valid = vlSelfRef.mlp_top__DOT__ub_b__DOT__rd_valid;
}

void Vtop___024root___nba_sequent__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__acc_valid;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__acc_in;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__data_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__acc_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__acc_valid;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__act_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__valid_in;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__act_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__valid_in;
}

void Vtop___024root___nba_sequent__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s1_valid;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__shift)));
}

void Vtop___024root___nba_sequent__TOP__21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col1__DOT__s1_valid;
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shifted 
        = (0x0000ffffffffffffULL & VL_SHIFTRS_QQI(48,48,5, vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__mult, (IData)(vlSelfRef.mlp_top__DOT__ap_col1__DOT__norm_u__DOT__shift)));
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff 
        = (vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__data_in 
           - vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__target_in);
    vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff)
            : vlSelfRef.mlp_top__DOT__ap_col1__DOT__loss_u__DOT__diff);
}

void Vtop___024root___nba_sequent__TOP__22(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col1;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__row1_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_capture 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_capture_col0;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__en_weight_pass 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__en_weight_pass;
}

void Vtop___024root___nba_sequent__TOP__23(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__23\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe11__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe01_11_psum;
}

void Vtop___024root___nba_sequent__TOP__24(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_valid 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__norm_u__DOT__valid_out;
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__biased = 
        (vlSelfRef.mlp_top__DOT__ap_col0__DOT__scaled 
         + (((- (IData)((1U & ((IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_zero_point) 
                               >> 7U)))) << 8U) | (IData)(vlSelfRef.mlp_top__DOT__ap_col0__DOT__q_zero_point)));
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__valid_in 
        = vlSelfRef.mlp_top__DOT__ap_col0__DOT__s2_valid;
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff 
        = (vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__data_in 
           - vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__target_in);
    vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__abs_diff 
        = ((vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff 
            >> 0x0000001fU) ? (- vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff)
            : vlSelfRef.mlp_top__DOT__ap_col0__DOT__loss_u__DOT__diff);
}

void Vtop___024root___nba_sequent__TOP__25(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__25\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe10__DOT__in_psum 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00_10_psum;
}

void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mlp_top__DOT__act_ub_rd_valid = ((IData)(vlSelfRef.mlp_top__DOT__buffer_select)
                                                ? (IData)(vlSelfRef.mlp_top__DOT__ub_b_rd_valid)
                                                : (IData)(vlSelfRef.mlp_top__DOT__ub_a_rd_valid));
    vlSelfRef.mlp_top__DOT__mmu_row0_in = (((IData)(vlSelfRef.mlp_top__DOT__act_ub_rd_valid) 
                                            & (IData)(vlSelfRef.mlp_top__DOT__compute_phase))
                                            ? (IData)(vlSelfRef.mlp_top__DOT__act_row0_data)
                                            : 0U);
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__row0_in = vlSelfRef.mlp_top__DOT__mmu_row0_in;
    vlSelfRef.mlp_top__DOT__mmu_u__DOT__pe00__DOT__in_act 
        = vlSelfRef.mlp_top__DOT__mmu_u__DOT__row0_in;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x000000000c000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0000000c00000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000030000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x00000000c0000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000300000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x000000000000c000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__14(vlSelf);
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__17(vlSelf);
    }
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x00000000000000f3ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x0000000000000033ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x00000000000000c3ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((0x00000000c0000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0x0000000330000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__22(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__23(vlSelf);
    }
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__24(vlSelf);
    }
    if ((0x0000000003300000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((0x00000000000000f3ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__6(vlSelf);
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
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mlp_top.sv", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mlp_top.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/alanma/Downloads/tinytinyTPU/rtl/mlp_top.sv", 6, "", "Active region did not converge after 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.wf_push_col0 & 0xfeU)))) {
        Verilated::overWidthError("wf_push_col0");
    }
    if (VL_UNLIKELY(((vlSelfRef.wf_push_col1 & 0xfeU)))) {
        Verilated::overWidthError("wf_push_col1");
    }
    if (VL_UNLIKELY(((vlSelfRef.wf_reset & 0xfeU)))) {
        Verilated::overWidthError("wf_reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.init_act_valid & 0xfeU)))) {
        Verilated::overWidthError("init_act_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.start_mlp & 0xfeU)))) {
        Verilated::overWidthError("start_mlp");
    }
    if (VL_UNLIKELY(((vlSelfRef.weights_ready & 0xfeU)))) {
        Verilated::overWidthError("weights_ready");
    }
    if (VL_UNLIKELY(((vlSelfRef.norm_shift & 0xe0U)))) {
        Verilated::overWidthError("norm_shift");
    }
}
#endif  // VL_DEBUG
