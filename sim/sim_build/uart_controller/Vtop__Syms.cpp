// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_uart_controller);
    __Vhier.remove(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_rx_u);
    __Vhier.remove(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_tx_u);
    __Vhier.remove(&__Vscope_uart_controller, &__Vscope_uart_controller__unnamedblk1);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(320);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_uart_controller.configure(this, name(), "uart_controller", "uart_controller", "uart_controller", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_uart_controller__uart_rx_u.configure(this, name(), "uart_controller.uart_rx_u", "uart_rx_u", "uart_rx", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_uart_controller__uart_tx_u.configure(this, name(), "uart_controller.uart_tx_u", "uart_tx_u", "uart_tx", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_uart_controller__unnamedblk1.configure(this, name(), "uart_controller.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_uart_controller);
    __Vhier.add(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_rx_u);
    __Vhier.add(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_tx_u);
    __Vhier.add(&__Vscope_uart_controller, &__Vscope_uart_controller__unnamedblk1);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_byte_count", &(TOP.dbg_byte_count), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_cmd_reg", &(TOP.dbg_cmd_reg), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_resp_byte_idx", &(TOP.dbg_resp_byte_idx), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_rx_data", &(TOP.dbg_rx_data), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_rx_valid", &(TOP.dbg_rx_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_start_mlp", &(TOP.dbg_start_mlp), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_state", &(TOP.dbg_state), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_tx_ready", &(TOP.dbg_tx_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_tx_valid", &(TOP.dbg_tx_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"dbg_weights_ready", &(TOP.dbg_weights_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"init_act_data", &(TOP.init_act_data), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"init_act_valid", &(TOP.init_act_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"mlp_acc0", &(TOP.mlp_acc0), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"mlp_acc1", &(TOP.mlp_acc1), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"mlp_cycle_cnt", &(TOP.mlp_cycle_cnt), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_TOP.varInsert(__Vfinal,"mlp_state", &(TOP.mlp_state), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"start_mlp", &(TOP.start_mlp), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"uart_rx", &(TOP.uart_rx), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"uart_tx", &(TOP.uart_tx), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"weights_ready", &(TOP.weights_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_data_in", &(TOP.wf_data_in), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_push_col0", &(TOP.wf_push_col0), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_push_col1", &(TOP.wf_push_col1), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_reset", &(TOP.wf_reset), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_EXECUTE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_EXECUTE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_READ_RESULT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_READ_RESULT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_READ_RESULT_COL1", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_READ_RESULT_COL1))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_STATUS", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_STATUS))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_WRITE_ACT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_WRITE_ACT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CMD_WRITE_WEIGHT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CMD_WRITE_WEIGHT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"MLP_STATE_LOAD_WEIGHT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__MLP_STATE_LOAD_WEIGHT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"act_seq_idx", &(TOP.uart_controller__DOT__act_seq_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"byte_count", &(TOP.uart_controller__DOT__byte_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"byte_sent", &(TOP.uart_controller__DOT__byte_sent), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"cmd_reg", &(TOP.uart_controller__DOT__cmd_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"data_buffer", &(TOP.uart_controller__DOT__data_buffer), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,3 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_byte_count", &(TOP.uart_controller__DOT__dbg_byte_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_cmd_reg", &(TOP.uart_controller__DOT__dbg_cmd_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_resp_byte_idx", &(TOP.uart_controller__DOT__dbg_resp_byte_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_rx_data", &(TOP.uart_controller__DOT__dbg_rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_rx_valid", &(TOP.uart_controller__DOT__dbg_rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_start_mlp", &(TOP.uart_controller__DOT__dbg_start_mlp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_state", &(TOP.uart_controller__DOT__dbg_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_tx_ready", &(TOP.uart_controller__DOT__dbg_tx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_tx_valid", &(TOP.uart_controller__DOT__dbg_tx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"dbg_weights_ready", &(TOP.uart_controller__DOT__dbg_weights_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_data", &(TOP.uart_controller__DOT__init_act_data), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_data_reg", &(TOP.uart_controller__DOT__init_act_data_reg), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_valid", &(TOP.uart_controller__DOT__init_act_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_valid_reg", &(TOP.uart_controller__DOT__init_act_valid_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"mlp_acc0", &(TOP.uart_controller__DOT__mlp_acc0), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"mlp_acc1", &(TOP.uart_controller__DOT__mlp_acc1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"mlp_cycle_cnt", &(TOP.uart_controller__DOT__mlp_cycle_cnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"mlp_state", &(TOP.uart_controller__DOT__mlp_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"mlp_state_prev", &(TOP.uart_controller__DOT__mlp_state_prev), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"resp_buffer", &(TOP.uart_controller__DOT__resp_buffer), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,3 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"resp_byte_idx", &(TOP.uart_controller__DOT__resp_byte_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"resp_delay_count", &(TOP.uart_controller__DOT__resp_delay_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_data", &(TOP.uart_controller__DOT__rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_data_captured", &(TOP.uart_controller__DOT__rx_data_captured), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_ready", &(TOP.uart_controller__DOT__rx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_valid", &(TOP.uart_controller__DOT__rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"start_mlp", &(TOP.uart_controller__DOT__start_mlp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"start_mlp_reg", &(TOP.uart_controller__DOT__start_mlp_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"start_mlp_sticky", &(TOP.uart_controller__DOT__start_mlp_sticky), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"state", &(TOP.uart_controller__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_data", &(TOP.uart_controller__DOT__tx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_data_reg", &(TOP.uart_controller__DOT__tx_data_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_ready", &(TOP.uart_controller__DOT__tx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_valid", &(TOP.uart_controller__DOT__tx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_valid_reg", &(TOP.uart_controller__DOT__tx_valid_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"uart_rx", &(TOP.uart_controller__DOT__uart_rx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"uart_tx", &(TOP.uart_controller__DOT__uart_tx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"weight_seq_idx", &(TOP.uart_controller__DOT__weight_seq_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"weights_ready", &(TOP.uart_controller__DOT__weights_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"weights_ready_reg", &(TOP.uart_controller__DOT__weights_ready_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_data_in", &(TOP.uart_controller__DOT__wf_data_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_data_in_reg", &(TOP.uart_controller__DOT__wf_data_in_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col0", &(TOP.uart_controller__DOT__wf_push_col0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col0_reg", &(TOP.uart_controller__DOT__wf_push_col0_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col1", &(TOP.uart_controller__DOT__wf_push_col1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col1_reg", &(TOP.uart_controller__DOT__wf_push_col1_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_reset", &(TOP.uart_controller__DOT__wf_reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_reset_reg", &(TOP.uart_controller__DOT__wf_reset_reg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_u__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"CLKS_PER_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_u__DOT__CLKS_PER_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_u__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"HALF_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_u__DOT__HALF_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"bit_index", &(TOP.uart_controller__DOT__uart_rx_u__DOT__bit_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__uart_rx_u__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"clk_count", &(TOP.uart_controller__DOT__uart_rx_u__DOT__clk_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_byte", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_data", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_ready", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_sync_1", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_sync_1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_sync_2", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_sync_2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"rx_valid", &(TOP.uart_controller__DOT__uart_rx_u__DOT__rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_u.varInsert(__Vfinal,"state", &(TOP.uart_controller__DOT__uart_rx_u__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_u__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"CLKS_PER_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_u__DOT__CLKS_PER_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_u__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"bit_index", &(TOP.uart_controller__DOT__uart_tx_u__DOT__bit_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__uart_tx_u__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"clk_count", &(TOP.uart_controller__DOT__uart_tx_u__DOT__clk_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__uart_tx_u__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"state", &(TOP.uart_controller__DOT__uart_tx_u__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"tx", &(TOP.uart_controller__DOT__uart_tx_u__DOT__tx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"tx_byte", &(TOP.uart_controller__DOT__uart_tx_u__DOT__tx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"tx_data", &(TOP.uart_controller__DOT__uart_tx_u__DOT__tx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"tx_ready", &(TOP.uart_controller__DOT__uart_tx_u__DOT__tx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_u.varInsert(__Vfinal,"tx_valid", &(TOP.uart_controller__DOT__uart_tx_u__DOT__tx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__unnamedblk1.varInsert(__Vfinal,"i", &(TOP.uart_controller__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
    }
}
