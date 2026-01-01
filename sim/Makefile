# TinyTinyTPU Simulation Makefile
# cocotb + Verilator testbench environment

SHELL := /bin/bash

# Directories
SIM_DIR := $(shell pwd)
RTL_DIR := $(SIM_DIR)/../rtl
WAVE_DIR := $(SIM_DIR)/waves
TEST_DIR := tests
BUILD_DIR := sim_build

# Waveform viewer
WAVE_VIEWER ?= surfer
export COCOTB_WAVEFORM_VIEWER := $(WAVE_VIEWER)

# Ensure waves directory exists
$(shell mkdir -p $(WAVE_DIR))

# RTL source files
RTL_SOURCES := \
    $(RTL_DIR)/pe.sv \
    $(RTL_DIR)/mmu.sv \
    $(RTL_DIR)/weight_fifo.sv \
    $(RTL_DIR)/dual_weight_fifo.sv \
    $(RTL_DIR)/accumulator.sv \
    $(RTL_DIR)/accumulator_align.sv \
    $(RTL_DIR)/accumulator_mem.sv \
    $(RTL_DIR)/activation_func.sv \
    $(RTL_DIR)/vpu.sv \
    $(RTL_DIR)/activation_pipeline.sv \
    $(RTL_DIR)/normalizer.sv \
    $(RTL_DIR)/loss_block.sv \
    $(RTL_DIR)/unified_buffer.sv \
    $(RTL_DIR)/config_regs.sv \
    $(RTL_DIR)/instruction_decoder.sv \
    $(RTL_DIR)/execution_unit.sv \
    $(RTL_DIR)/mlp_top.sv \
    $(RTL_DIR)/tpu_bridge.sv \
    $(RTL_DIR)/uart_controller.sv \
    $(RTL_DIR)/uart_rx.sv \
    $(RTL_DIR)/uart_tx.sv \
    $(RTL_DIR)/tpu_top.sv

# Default WAVES to 0 if not set
WAVES ?= 0

# Environment variables for cocotb/verilator
export CXXFLAGS := -std=c++17
SHELL := /bin/bash

.PHONY: test test_pe test_mmu test_weight_fifo test_dual_fifo test_accumulator \
        test_activation_func test_normalizer test_activation_pipeline test_mlp \
        test_uart test_uart_ctrl test_tpu test_signed test_vpu test_isa \
        lint waves clean clean_waves help

help:
	@echo "TinyTinyTPU Simulation"
	@echo "======================"
	@echo ""
	@echo "Test Commands:"
	@echo "  make test              Run all tests"
	@echo "  make test WAVES=1      Run all tests with waveform generation"
	@echo "  make test_pe           Run PE tests"
	@echo "  make test_mmu          Run MMU tests"
	@echo "  make test_mlp          Run MLP integration tests"
	@echo "  make test_uart_ctrl    Run UART controller tests"
	@echo "  make test_tpu          Run TPU system end-to-end tests"
	@echo "  make test_signed       Run signed arithmetic tests"
	@echo "  make test_vpu          Run VPU activation function tests"
	@echo "  make test_isa          Run ISA instruction tests"
	@echo ""
	@echo "Waveform Commands:"
	@echo "  make waves             Select and open a waveform file"
	@echo "  make waves MODULE=pe   Open PE waveform directly"
	@echo ""
	@echo "Other:"
	@echo "  make lint              Verilator lint check"
	@echo "  make clean             Remove build artifacts"
	@echo ""
	@echo "Environment Variables:"
	@echo "  WAVES=1                Enable waveform generation"
	@echo "  WAVE_VIEWER=gtkwave    Use GTKWave instead of Surfer"
	@echo "  MODULE=pe              Specify module for make waves"

# Test targets
test:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR) -v

test_pe:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_pe.py -v

test_mmu:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_mmu.py -v

test_weight_fifo:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_weight_fifo.py -v

test_dual_fifo:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_dual_weight_fifo.py -v

test_accumulator:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_accumulator.py -v

test_activation_func:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_activation_func.py -v

test_normalizer:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_normalizer.py -v

test_activation_pipeline:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_activation_pipeline.py -v

test_mlp:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_mlp_integration.py -v

test_uart:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_uart.py -v

test_uart_ctrl:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_uart_controller.py -v

test_tpu:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_tpu_system.py -v

test_signed:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_signed.py -v

test_vpu:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_vpu.py -v

test_isa:
	source venv/bin/activate && WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_isa.py -v

# Lint
lint:
	verilator --lint-only -Wall -Wno-PINCONNECTEMPTY -Wno-UNUSEDSIGNAL -Wno-MULTITOP $(RTL_SOURCES)

# Waveform viewer
waves:
ifdef MODULE
	@if [ -f $(WAVE_DIR)/$(MODULE).vcd ]; then \
		echo "Opening $(MODULE).vcd"; \
		$(WAVE_VIEWER) $(WAVE_DIR)/$(MODULE).vcd; \
	else \
		echo "Error: $(WAVE_DIR)/$(MODULE).vcd not found"; \
		echo "Generate it with: make test_$(MODULE) WAVES=1"; \
	fi
else
	@echo ""
	@echo "Available waveforms:"
	@echo ""
	@for f in $$(ls $(WAVE_DIR)/*.vcd 2>/dev/null | sort); do \
		name=$$(basename $$f .vcd); \
		echo "  - $$name"; \
	done
	@if [ -z "$$(ls $(WAVE_DIR)/*.vcd 2>/dev/null)" ]; then \
		echo "  No waveforms found."; \
		echo ""; \
		echo "Generate waveforms with: make test WAVES=1"; \
	else \
		echo ""; \
		echo "Usage: make waves MODULE=<name>"; \
		echo "Example: make waves MODULE=pe"; \
	fi
endif

# Clean
clean_waves:
	rm -f $(WAVE_DIR)/*.vcd $(WAVE_DIR)/*.fst

clean:
	rm -rf $(BUILD_DIR) __pycache__ .pytest_cache
	rm -rf $(TEST_DIR)/__pycache__ $(TEST_DIR)/.pytest_cache
	rm -rf obj_dir
	rm -f results.xml dump.fst dump.vcd
