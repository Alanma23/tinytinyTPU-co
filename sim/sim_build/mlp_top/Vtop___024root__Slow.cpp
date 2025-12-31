// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__IDLE;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__LOAD_WEIGHT;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__LOAD_ACT;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__COMPUTE;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__DRAIN;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__TRANSFER;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__NEXT_LAYER;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__WAIT_WEIGHTS;
constexpr CData/*3:0*/ Vtop___024root::mlp_top__DOT__DONE;
constexpr CData/*0:0*/ Vtop___024root::mlp_top__DOT__accum_u__DOT__u_mem__DOT__BYPASS_READ_NEW;
constexpr CData/*1:0*/ Vtop___024root::mlp_top__DOT__ap_col0__DOT__act_u__DOT__DEFAULT_ACT;
constexpr CData/*1:0*/ Vtop___024root::mlp_top__DOT__ap_col1__DOT__act_u__DOT__DEFAULT_ACT;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__NUM_LAYERS;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_a__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_a__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_a__DOT__ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_b__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_b__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::mlp_top__DOT__ub_b__DOT__ADDR_W;


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
