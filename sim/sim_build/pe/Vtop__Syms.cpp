// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_pe);

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
    __Vscope_pe.configure(this, name(), "pe", "pe", "pe", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_pe);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"en_weight_capture", &(TOP.en_weight_capture), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"en_weight_pass", &(TOP.en_weight_pass), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"in_act", &(TOP.in_act), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"in_psum", &(TOP.in_psum), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"out_act", &(TOP.out_act), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"out_psum", &(TOP.out_psum), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_pe.varInsert(__Vfinal,"clk", &(TOP.pe__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_pe.varInsert(__Vfinal,"en_weight_capture", &(TOP.pe__DOT__en_weight_capture), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_pe.varInsert(__Vfinal,"en_weight_pass", &(TOP.pe__DOT__en_weight_pass), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_pe.varInsert(__Vfinal,"in_act", &(TOP.pe__DOT__in_act), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_pe.varInsert(__Vfinal,"in_psum", &(TOP.pe__DOT__in_psum), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_pe.varInsert(__Vfinal,"out_act", &(TOP.pe__DOT__out_act), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_pe.varInsert(__Vfinal,"out_psum", &(TOP.pe__DOT__out_psum), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_pe.varInsert(__Vfinal,"reset", &(TOP.pe__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_pe.varInsert(__Vfinal,"weight", &(TOP.pe__DOT__weight), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
    }
}
