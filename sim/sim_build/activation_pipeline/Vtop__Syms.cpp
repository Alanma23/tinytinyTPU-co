// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_activation_pipeline);
    __Vhier.remove(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__act_u);
    __Vhier.remove(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__loss_u);
    __Vhier.remove(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__norm_u);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(260);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_activation_pipeline.configure(this, name(), "activation_pipeline", "activation_pipeline", "activation_pipeline", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_activation_pipeline__act_u.configure(this, name(), "activation_pipeline.act_u", "act_u", "activation_func", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_activation_pipeline__loss_u.configure(this, name(), "activation_pipeline.loss_u", "loss_u", "loss_block", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_activation_pipeline__norm_u.configure(this, name(), "activation_pipeline.norm_u", "norm_u", "normalizer", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_activation_pipeline);
    __Vhier.add(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__act_u);
    __Vhier.add(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__loss_u);
    __Vhier.add(&__Vscope_activation_pipeline, &__Vscope_activation_pipeline__norm_u);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"acc_in", &(TOP.acc_in), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"loss_out", &(TOP.loss_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"loss_valid", &(TOP.loss_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"norm_bias", &(TOP.norm_bias), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"norm_gain", &(TOP.norm_gain), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"norm_shift", &(TOP.norm_shift), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_TOP.varInsert(__Vfinal,"q_inv_scale", &(TOP.q_inv_scale), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"q_zero_point", &(TOP.q_zero_point), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"target_in", &(TOP.target_in), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"ub_data_out", &(TOP.ub_data_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_in", &(TOP.valid_in), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_out", &(TOP.valid_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"acc_in", &(TOP.activation_pipeline__DOT__acc_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"biased", &(TOP.activation_pipeline__DOT__biased), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"clk", &(TOP.activation_pipeline__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"loss_out", &(TOP.activation_pipeline__DOT__loss_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"loss_valid", &(TOP.activation_pipeline__DOT__loss_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"mult", &(TOP.activation_pipeline__DOT__mult), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"mult_rounded", &(TOP.activation_pipeline__DOT__mult_rounded), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"norm_bias", &(TOP.activation_pipeline__DOT__norm_bias), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"norm_gain", &(TOP.activation_pipeline__DOT__norm_gain), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"norm_shift", &(TOP.activation_pipeline__DOT__norm_shift), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"q_inv_scale", &(TOP.activation_pipeline__DOT__q_inv_scale), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"q_zero_point", &(TOP.activation_pipeline__DOT__q_zero_point), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"reset", &(TOP.activation_pipeline__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"s1_data", &(TOP.activation_pipeline__DOT__s1_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"s1_valid", &(TOP.activation_pipeline__DOT__s1_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"s2_data", &(TOP.activation_pipeline__DOT__s2_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"s2_valid", &(TOP.activation_pipeline__DOT__s2_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"scaled", &(TOP.activation_pipeline__DOT__scaled), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"target_d1", &(TOP.activation_pipeline__DOT__target_d1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"target_in", &(TOP.activation_pipeline__DOT__target_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"ub_data_out", &(TOP.activation_pipeline__DOT__ub_data_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"ub_q_reg", &(TOP.activation_pipeline__DOT__ub_q_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"valid_in", &(TOP.activation_pipeline__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"valid_out", &(TOP.activation_pipeline__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline.varInsert(__Vfinal,"valid_reg", &(TOP.activation_pipeline__DOT__valid_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"DEFAULT_ACT", const_cast<void*>(static_cast<const void*>(&(TOP.activation_pipeline__DOT__act_u__DOT__DEFAULT_ACT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"clk", &(TOP.activation_pipeline__DOT__act_u__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"data_in", &(TOP.activation_pipeline__DOT__act_u__DOT__data_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"data_out", &(TOP.activation_pipeline__DOT__act_u__DOT__data_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"reset", &(TOP.activation_pipeline__DOT__act_u__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"valid_in", &(TOP.activation_pipeline__DOT__act_u__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__act_u.varInsert(__Vfinal,"valid_out", &(TOP.activation_pipeline__DOT__act_u__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"abs_diff", &(TOP.activation_pipeline__DOT__loss_u__DOT__abs_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"clk", &(TOP.activation_pipeline__DOT__loss_u__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"data_in", &(TOP.activation_pipeline__DOT__loss_u__DOT__data_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"diff", &(TOP.activation_pipeline__DOT__loss_u__DOT__diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"loss_out", &(TOP.activation_pipeline__DOT__loss_u__DOT__loss_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"reset", &(TOP.activation_pipeline__DOT__loss_u__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"target_in", &(TOP.activation_pipeline__DOT__loss_u__DOT__target_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"valid_in", &(TOP.activation_pipeline__DOT__loss_u__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__loss_u.varInsert(__Vfinal,"valid_out", &(TOP.activation_pipeline__DOT__loss_u__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"bias", &(TOP.activation_pipeline__DOT__norm_u__DOT__bias), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"clk", &(TOP.activation_pipeline__DOT__norm_u__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"data_in", &(TOP.activation_pipeline__DOT__norm_u__DOT__data_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"data_out", &(TOP.activation_pipeline__DOT__norm_u__DOT__data_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"gain", &(TOP.activation_pipeline__DOT__norm_u__DOT__gain), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"mult", &(TOP.activation_pipeline__DOT__norm_u__DOT__mult), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"reset", &(TOP.activation_pipeline__DOT__norm_u__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"shift", &(TOP.activation_pipeline__DOT__norm_u__DOT__shift), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"shifted", &(TOP.activation_pipeline__DOT__norm_u__DOT__shifted), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"valid_in", &(TOP.activation_pipeline__DOT__norm_u__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_activation_pipeline__norm_u.varInsert(__Vfinal,"valid_out", &(TOP.activation_pipeline__DOT__norm_u__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
