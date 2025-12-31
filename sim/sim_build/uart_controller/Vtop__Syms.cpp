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
    __Vhier.remove(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_rx_inst);
    __Vhier.remove(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_tx_inst);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(308);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_uart_controller.configure(this, name(), "uart_controller", "uart_controller", "uart_controller", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_uart_controller__uart_rx_inst.configure(this, name(), "uart_controller.uart_rx_inst", "uart_rx_inst", "uart_rx", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_uart_controller__uart_tx_inst.configure(this, name(), "uart_controller.uart_tx_inst", "uart_tx_inst", "uart_tx", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_uart_controller);
    __Vhier.add(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_rx_inst);
    __Vhier.add(&__Vscope_uart_controller, &__Vscope_uart_controller__uart_tx_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"acc0", &(TOP.acc0), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"acc1", &(TOP.acc1), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"debug_cmd", &(TOP.debug_cmd), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"debug_state", &(TOP.debug_state), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"init_act_data", &(TOP.init_act_data), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"init_act_valid", &(TOP.init_act_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"layer_complete", &(TOP.layer_complete), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"start_mlp", &(TOP.start_mlp), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"state_in", &(TOP.state_in), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"uart_rx_pin", &(TOP.uart_rx_pin), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"uart_tx_pin", &(TOP.uart_tx_pin), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"weights_ready", &(TOP.weights_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_data_in", &(TOP.wf_data_in), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_push_col0", &(TOP.wf_push_col0), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_push_col1", &(TOP.wf_push_col1), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"wf_reset", &(TOP.wf_reset), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"acc0", &(TOP.uart_controller__DOT__acc0), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"acc1", &(TOP.uart_controller__DOT__acc1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"act_buffer", &(TOP.uart_controller__DOT__act_buffer), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"byte_count", &(TOP.uart_controller__DOT__byte_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"cmd_state", &(TOP.uart_controller__DOT__cmd_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"command", &(TOP.uart_controller__DOT__command), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"debug_cmd", &(TOP.uart_controller__DOT__debug_cmd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"debug_state", &(TOP.uart_controller__DOT__debug_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_data", &(TOP.uart_controller__DOT__init_act_data), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"init_act_valid", &(TOP.uart_controller__DOT__init_act_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"layer_complete", &(TOP.uart_controller__DOT__layer_complete), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"result_buffer", &(TOP.uart_controller__DOT__result_buffer), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_data", &(TOP.uart_controller__DOT__rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_ready", &(TOP.uart_controller__DOT__rx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_valid", &(TOP.uart_controller__DOT__rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"rx_valid_prev", &(TOP.uart_controller__DOT__rx_valid_prev), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"start_mlp", &(TOP.uart_controller__DOT__start_mlp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"state_in", &(TOP.uart_controller__DOT__state_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_data", &(TOP.uart_controller__DOT__tx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_ready", &(TOP.uart_controller__DOT__tx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"tx_valid", &(TOP.uart_controller__DOT__tx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"uart_rx_pin", &(TOP.uart_controller__DOT__uart_rx_pin), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"uart_tx_pin", &(TOP.uart_controller__DOT__uart_tx_pin), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"weight_buffer", &(TOP.uart_controller__DOT__weight_buffer), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"weights_ready", &(TOP.uart_controller__DOT__weights_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_data_in", &(TOP.uart_controller__DOT__wf_data_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col0", &(TOP.uart_controller__DOT__wf_push_col0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_push_col1", &(TOP.uart_controller__DOT__wf_push_col1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller.varInsert(__Vfinal,"wf_reset", &(TOP.uart_controller__DOT__wf_reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_inst__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"CLKS_PER_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_inst__DOT__CLKS_PER_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_inst__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"HALF_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_rx_inst__DOT__HALF_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"bit_index", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__bit_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"clk_count", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__clk_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_byte", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_data", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_ready", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_sync_1", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_sync_2", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_sync_2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"rx_valid", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_rx_inst.varInsert(__Vfinal,"state", &(TOP.uart_controller__DOT__uart_rx_inst__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_inst__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"CLKS_PER_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_inst__DOT__CLKS_PER_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_controller__DOT__uart_tx_inst__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"bit_index", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__bit_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"clk", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"clk_count", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__clk_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"rst", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"state", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"tx", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__tx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"tx_byte", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__tx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"tx_data", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__tx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"tx_ready", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__tx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_controller__uart_tx_inst.varInsert(__Vfinal,"tx_valid", &(TOP.uart_controller__DOT__uart_tx_inst__DOT__tx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
