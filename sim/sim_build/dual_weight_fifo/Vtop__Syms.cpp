// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_dual_weight_fifo);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(274);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_dual_weight_fifo.configure(this, name(), "dual_weight_fifo", "dual_weight_fifo", "dual_weight_fifo", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_dual_weight_fifo);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"col0_out", &(TOP.col0_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"col1_out", &(TOP.col1_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"col1_raw", &(TOP.col1_raw), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"data_in", &(TOP.data_in), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"pop", &(TOP.pop), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"push_col0", &(TOP.push_col0), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"push_col1", &(TOP.push_col1), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"clk", &(TOP.dual_weight_fifo__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"col0_out", &(TOP.dual_weight_fifo__DOT__col0_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"col1_out", &(TOP.dual_weight_fifo__DOT__col1_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"col1_raw", &(TOP.dual_weight_fifo__DOT__col1_raw), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"data_in", &(TOP.dual_weight_fifo__DOT__data_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"pop", &(TOP.dual_weight_fifo__DOT__pop), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"push_col0", &(TOP.dual_weight_fifo__DOT__push_col0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"push_col1", &(TOP.dual_weight_fifo__DOT__push_col1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"queue0", &(TOP.dual_weight_fifo__DOT__queue0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,3 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"queue1", &(TOP.dual_weight_fifo__DOT__queue1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,3 ,7,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"rd_ptr0", &(TOP.dual_weight_fifo__DOT__rd_ptr0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"rd_ptr1", &(TOP.dual_weight_fifo__DOT__rd_ptr1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"reset", &(TOP.dual_weight_fifo__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"wr_ptr0", &(TOP.dual_weight_fifo__DOT__wr_ptr0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_dual_weight_fifo.varInsert(__Vfinal,"wr_ptr1", &(TOP.dual_weight_fifo__DOT__wr_ptr1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
    }
}
