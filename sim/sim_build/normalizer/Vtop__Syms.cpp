// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_normalizer);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(250);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_normalizer.configure(this, name(), "normalizer", "normalizer", "normalizer", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_normalizer);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"bias", &(TOP.bias), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_in", &(TOP.data_in), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_out", &(TOP.data_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"gain", &(TOP.gain), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"shift", &(TOP.shift), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_in", &(TOP.valid_in), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_out", &(TOP.valid_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_normalizer.varInsert(__Vfinal,"bias", &(TOP.normalizer__DOT__bias), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_normalizer.varInsert(__Vfinal,"clk", &(TOP.normalizer__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_normalizer.varInsert(__Vfinal,"data_in", &(TOP.normalizer__DOT__data_in), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_normalizer.varInsert(__Vfinal,"data_out", &(TOP.normalizer__DOT__data_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_normalizer.varInsert(__Vfinal,"gain", &(TOP.normalizer__DOT__gain), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_normalizer.varInsert(__Vfinal,"mult", &(TOP.normalizer__DOT__mult), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_normalizer.varInsert(__Vfinal,"reset", &(TOP.normalizer__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_normalizer.varInsert(__Vfinal,"shift", &(TOP.normalizer__DOT__shift), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_normalizer.varInsert(__Vfinal,"shifted", &(TOP.normalizer__DOT__shifted), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,47,0);
        __Vscope_normalizer.varInsert(__Vfinal,"valid_in", &(TOP.normalizer__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_normalizer.varInsert(__Vfinal,"valid_out", &(TOP.normalizer__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
