// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , uart_rx{vlSymsp->TOP.uart_rx}
    , uart_tx{vlSymsp->TOP.uart_tx}
    , mlp_state_dbg{vlSymsp->TOP.mlp_state_dbg}
    , mlp_cycle_cnt_dbg{vlSymsp->TOP.mlp_cycle_cnt_dbg}
    , mlp_layer_dbg{vlSymsp->TOP.mlp_layer_dbg}
    , mlp_layer_complete_dbg{vlSymsp->TOP.mlp_layer_complete_dbg}
    , mlp_acc_valid_dbg{vlSymsp->TOP.mlp_acc_valid_dbg}
    , uart_state_dbg{vlSymsp->TOP.uart_state_dbg}
    , uart_cmd_dbg{vlSymsp->TOP.uart_cmd_dbg}
    , uart_byte_count_dbg{vlSymsp->TOP.uart_byte_count_dbg}
    , uart_resp_idx_dbg{vlSymsp->TOP.uart_resp_idx_dbg}
    , uart_tx_valid_dbg{vlSymsp->TOP.uart_tx_valid_dbg}
    , uart_tx_ready_dbg{vlSymsp->TOP.uart_tx_ready_dbg}
    , uart_rx_valid_dbg{vlSymsp->TOP.uart_rx_valid_dbg}
    , uart_rx_data_dbg{vlSymsp->TOP.uart_rx_data_dbg}
    , uart_weights_ready_dbg{vlSymsp->TOP.uart_weights_ready_dbg}
    , uart_start_mlp_dbg{vlSymsp->TOP.uart_start_mlp_dbg}
    , mlp_acc0_dbg{vlSymsp->TOP.mlp_acc0_dbg}
    , mlp_acc1_dbg{vlSymsp->TOP.mlp_acc1_dbg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_static(Vtop___024root* vlSelf);
void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
void Vtop___024root___eval_settle(Vtop___024root* vlSelf);
void Vtop___024root___eval(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop___024root___eval_static(&(vlSymsp->TOP));
        Vtop___024root___eval_initial(&(vlSymsp->TOP));
        Vtop___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop___024root___eval_final(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop::final() {
    Vtop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
void Vtop::prepareClone() const { contextp()->prepareClone(); }
void Vtop::atClone() const {
    contextp()->threadPoolpOnClone();
}
