// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_WRITE_WEIGHT;
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_WRITE_ACT;
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_EXECUTE;
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_READ_RESULT;
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_STATUS;
constexpr CData/*7:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CMD_READ_RESULT_COL1;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__MLP_STATE_LOAD_WEIGHT;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__IDLE;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__LOAD_WEIGHT;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__LOAD_ACT;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__COMPUTE;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__DRAIN;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__TRANSFER;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__NEXT_LAYER;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__WAIT_WEIGHTS;
constexpr CData/*3:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__DONE;
constexpr CData/*0:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__accum_u__DOT__u_mem__DOT__BYPASS_READ_NEW;
constexpr CData/*1:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ap_col0__DOT__act_u__DOT__DEFAULT_ACT;
constexpr CData/*1:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ap_col1__DOT__act_u__DOT__DEFAULT_ACT;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__CLKS_PER_BIT;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_rx_u__DOT__HALF_BIT;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__uart_ctrl_u__DOT__uart_tx_u__DOT__CLKS_PER_BIT;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__NUM_LAYERS;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_a__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_a__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_a__DOT__ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_b__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_b__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::tpu_top__DOT__mlp_u__DOT__ub_b__DOT__ADDR_W;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
