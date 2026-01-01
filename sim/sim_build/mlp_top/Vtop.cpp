// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , wf_push_col0{vlSymsp->TOP.wf_push_col0}
    , wf_push_col1{vlSymsp->TOP.wf_push_col1}
    , wf_data_in{vlSymsp->TOP.wf_data_in}
    , wf_reset{vlSymsp->TOP.wf_reset}
    , init_act_valid{vlSymsp->TOP.init_act_valid}
    , start_mlp{vlSymsp->TOP.start_mlp}
    , weights_ready{vlSymsp->TOP.weights_ready}
    , norm_shift{vlSymsp->TOP.norm_shift}
    , q_zero_point{vlSymsp->TOP.q_zero_point}
    , state{vlSymsp->TOP.state}
    , cycle_cnt{vlSymsp->TOP.cycle_cnt}
    , current_layer{vlSymsp->TOP.current_layer}
    , layer_complete{vlSymsp->TOP.layer_complete}
    , acc_valid{vlSymsp->TOP.acc_valid}
    , init_act_data{vlSymsp->TOP.init_act_data}
    , norm_gain{vlSymsp->TOP.norm_gain}
    , q_inv_scale{vlSymsp->TOP.q_inv_scale}
    , mmu_acc0_out{vlSymsp->TOP.mmu_acc0_out}
    , mmu_acc1_out{vlSymsp->TOP.mmu_acc1_out}
    , norm_bias{vlSymsp->TOP.norm_bias}
    , acc0{vlSymsp->TOP.acc0}
    , acc1{vlSymsp->TOP.acc1}
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
