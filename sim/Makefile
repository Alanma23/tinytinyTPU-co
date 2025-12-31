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
    $(RTL_DIR)/activation_pipeline.sv \
    $(RTL_DIR)/normalizer.sv \
    $(RTL_DIR)/loss_block.sv \
    $(RTL_DIR)/unified_buffer.sv \
    $(RTL_DIR)/mlp_top.sv

# Default WAVES to 0 if not set
WAVES ?= 0

.PHONY: test test_pe test_mmu test_weight_fifo test_dual_fifo test_accumulator \
        test_activation_func test_normalizer test_activation_pipeline test_mlp \
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
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR) -v

test_pe:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_pe.py -v

test_mmu:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_mmu.py -v

test_weight_fifo:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_weight_fifo.py -v

test_dual_fifo:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_dual_weight_fifo.py -v

test_accumulator:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_accumulator.py -v

test_activation_func:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_activation_func.py -v

test_normalizer:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_normalizer.py -v

test_activation_pipeline:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_activation_pipeline.py -v

test_mlp:
	WAVES=$(WAVES) python3 -m pytest $(TEST_DIR)/test_mlp_integration.py -v

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
