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
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_tpu_top;
    VerilatedScope __Vscope_tpu_top__bridge_u;
    VerilatedScope __Vscope_tpu_top__mlp_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__accum_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__accum_u__u_align;
    VerilatedScope __Vscope_tpu_top__mlp_u__accum_u__u_mem;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col0;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col0__act_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col0__loss_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col0__norm_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col0__unnamedblk1;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col1;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col1__act_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col1__loss_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col1__norm_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__ap_col1__unnamedblk1;
    VerilatedScope __Vscope_tpu_top__mlp_u__mmu_u;
    VerilatedScope __Vscope_tpu_top__mlp_u__mmu_u__pe00;
    VerilatedScope __Vscope_tpu_top__mlp_u__mmu_u__pe01;
    VerilatedScope __Vscope_tpu_top__mlp_u__mmu_u__pe10;
    VerilatedScope __Vscope_tpu_top__mlp_u__mmu_u__pe11;
    VerilatedScope __Vscope_tpu_top__mlp_u__ub_a;
    VerilatedScope __Vscope_tpu_top__mlp_u__ub_b;
    VerilatedScope __Vscope_tpu_top__mlp_u__weight_fifo_u;
    VerilatedScope __Vscope_tpu_top__uart_ctrl_u;
    VerilatedScope __Vscope_tpu_top__uart_ctrl_u__uart_rx_u;
    VerilatedScope __Vscope_tpu_top__uart_ctrl_u__uart_tx_u;
    VerilatedScope __Vscope_tpu_top__uart_ctrl_u__unnamedblk1;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
