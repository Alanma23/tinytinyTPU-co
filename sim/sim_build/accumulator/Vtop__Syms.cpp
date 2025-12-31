// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_accumulator);
    __Vhier.remove(&__Vscope_accumulator, &__Vscope_accumulator__u_align);
    __Vhier.remove(&__Vscope_accumulator, &__Vscope_accumulator__u_mem);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(288);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_accumulator.configure(this, name(), "accumulator", "accumulator", "accumulator", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_accumulator__u_align.configure(this, name(), "accumulator.u_align", "u_align", "accumulator_align", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_accumulator__u_mem.configure(this, name(), "accumulator.u_mem", "u_mem", "accumulator_mem", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_accumulator);
    __Vhier.add(&__Vscope_accumulator, &__Vscope_accumulator__u_align);
    __Vhier.add(&__Vscope_accumulator, &__Vscope_accumulator__u_mem);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"acc_col0_out", &(TOP.acc_col0_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"acc_col1_out", &(TOP.acc_col1_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"accumulator_enable", &(TOP.accumulator_enable), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"addr_sel", &(TOP.addr_sel), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"mmu_col0_in", &(TOP.mmu_col0_in), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"mmu_col1_in", &(TOP.mmu_col1_in), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_in", &(TOP.valid_in), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_out", &(TOP.valid_out), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"acc_col0_out", &(TOP.accumulator__DOT__acc_col0_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator.varInsert(__Vfinal,"acc_col1_out", &(TOP.accumulator__DOT__acc_col1_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator.varInsert(__Vfinal,"accumulator_enable", &(TOP.accumulator__DOT__accumulator_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"addr_sel", &(TOP.accumulator__DOT__addr_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"aligned_c0", &(TOP.accumulator__DOT__aligned_c0), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator.varInsert(__Vfinal,"aligned_c1", &(TOP.accumulator__DOT__aligned_c1), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator.varInsert(__Vfinal,"aligned_valid", &(TOP.accumulator__DOT__aligned_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"clk", &(TOP.accumulator__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"mmu_col0_in", &(TOP.accumulator__DOT__mmu_col0_in), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator.varInsert(__Vfinal,"mmu_col1_in", &(TOP.accumulator__DOT__mmu_col1_in), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator.varInsert(__Vfinal,"reset", &(TOP.accumulator__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"valid_in", &(TOP.accumulator__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator.varInsert(__Vfinal,"valid_out", &(TOP.accumulator__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"align_col0", &(TOP.accumulator__DOT__u_align__DOT__align_col0), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"align_col1", &(TOP.accumulator__DOT__u_align__DOT__align_col1), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"aligned_valid", &(TOP.accumulator__DOT__u_align__DOT__aligned_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"clk", &(TOP.accumulator__DOT__u_align__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"col0_delay_reg", &(TOP.accumulator__DOT__u_align__DOT__col0_delay_reg), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"pending", &(TOP.accumulator__DOT__u_align__DOT__pending), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"raw_col0", &(TOP.accumulator__DOT__u_align__DOT__raw_col0), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"raw_col1", &(TOP.accumulator__DOT__u_align__DOT__raw_col1), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"reset", &(TOP.accumulator__DOT__u_align__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_align.varInsert(__Vfinal,"valid_in", &(TOP.accumulator__DOT__u_align__DOT__valid_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"BYPASS_READ_NEW", const_cast<void*>(static_cast<const void*>(&(TOP.accumulator__DOT__u_mem__DOT__BYPASS_READ_NEW))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"accumulator_mode", &(TOP.accumulator__DOT__u_mem__DOT__accumulator_mode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"buffer_select", &(TOP.accumulator__DOT__u_mem__DOT__buffer_select), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"clk", &(TOP.accumulator__DOT__u_mem__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"enable", &(TOP.accumulator__DOT__u_mem__DOT__enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"in_col0", &(TOP.accumulator__DOT__u_mem__DOT__in_col0), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"in_col1", &(TOP.accumulator__DOT__u_mem__DOT__in_col1), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"mem_buff0_col0", &(TOP.accumulator__DOT__u_mem__DOT__mem_buff0_col0), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"mem_buff0_col1", &(TOP.accumulator__DOT__u_mem__DOT__mem_buff0_col1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"mem_buff1_col0", &(TOP.accumulator__DOT__u_mem__DOT__mem_buff1_col0), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"mem_buff1_col1", &(TOP.accumulator__DOT__u_mem__DOT__mem_buff1_col1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"out_col0", &(TOP.accumulator__DOT__u_mem__DOT__out_col0), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"out_col1", &(TOP.accumulator__DOT__u_mem__DOT__out_col1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"reset", &(TOP.accumulator__DOT__u_mem__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_accumulator__u_mem.varInsert(__Vfinal,"valid_out", &(TOP.accumulator__DOT__u_mem__DOT__valid_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
