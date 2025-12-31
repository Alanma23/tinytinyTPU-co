// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_uart_rx);

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
    __Vscope_uart_rx.configure(this, name(), "uart_rx", "uart_rx", "uart_rx", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_uart_rx);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rx", &(TOP.rx), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rx_data", &(TOP.rx_data), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"rx_ready", &(TOP.rx_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rx_valid", &(TOP.rx_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.uart_rx__DOT__BAUD_RATE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"CLKS_PER_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_rx__DOT__CLKS_PER_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"CLOCK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.uart_rx__DOT__CLOCK_FREQ))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"HALF_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.uart_rx__DOT__HALF_BIT))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"bit_index", &(TOP.uart_rx__DOT__bit_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"clk", &(TOP.uart_rx__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"clk_count", &(TOP.uart_rx__DOT__clk_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rst", &(TOP.uart_rx__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx", &(TOP.uart_rx__DOT__rx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_byte", &(TOP.uart_rx__DOT__rx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_data", &(TOP.uart_rx__DOT__rx_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_ready", &(TOP.uart_rx__DOT__rx_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_sync_1", &(TOP.uart_rx__DOT__rx_sync_1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_sync_2", &(TOP.uart_rx__DOT__rx_sync_2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"rx_valid", &(TOP.uart_rx__DOT__rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_uart_rx.varInsert(__Vfinal,"state", &(TOP.uart_rx__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
    }
}
