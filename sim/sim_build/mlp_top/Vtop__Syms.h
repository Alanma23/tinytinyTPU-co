// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_mlp_top;
    VerilatedScope __Vscope_mlp_top__accum_u;
    VerilatedScope __Vscope_mlp_top__accum_u__u_align;
    VerilatedScope __Vscope_mlp_top__accum_u__u_mem;
    VerilatedScope __Vscope_mlp_top__ap_col0;
    VerilatedScope __Vscope_mlp_top__ap_col0__act_u;
    VerilatedScope __Vscope_mlp_top__ap_col0__loss_u;
    VerilatedScope __Vscope_mlp_top__ap_col0__norm_u;
    VerilatedScope __Vscope_mlp_top__ap_col1;
    VerilatedScope __Vscope_mlp_top__ap_col1__act_u;
    VerilatedScope __Vscope_mlp_top__ap_col1__loss_u;
    VerilatedScope __Vscope_mlp_top__ap_col1__norm_u;
    VerilatedScope __Vscope_mlp_top__mmu_u;
    VerilatedScope __Vscope_mlp_top__mmu_u__pe00;
    VerilatedScope __Vscope_mlp_top__mmu_u__pe01;
    VerilatedScope __Vscope_mlp_top__mmu_u__pe10;
    VerilatedScope __Vscope_mlp_top__mmu_u__pe11;
    VerilatedScope __Vscope_mlp_top__ub_a;
    VerilatedScope __Vscope_mlp_top__ub_b;
    VerilatedScope __Vscope_mlp_top__weight_fifo_u;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
