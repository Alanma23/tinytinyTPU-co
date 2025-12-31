// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_rx_inst__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_rx_inst__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_rx_inst__DOT__CLKS_PER_BIT;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_rx_inst__DOT__HALF_BIT;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_tx_inst__DOT__CLOCK_FREQ;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_tx_inst__DOT__BAUD_RATE;
constexpr IData/*31:0*/ Vtop___024root::uart_controller__DOT__uart_tx_inst__DOT__CLKS_PER_BIT;


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
