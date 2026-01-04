# TinyTinyTPU

A minimal 2×2 systolic-array TPU-style matrix-multiply unit, implemented in SystemVerilog and deployed on FPGA.

<img width="1900" height="1244" alt="image" src="https://github.com/user-attachments/assets/0fa29f4b-eec1-4c61-814c-23a8cc3b80ba" />


This project implements a complete TPU architecture including:
- 2×2 systolic array (4 processing elements)
- Full post-MAC pipeline (accumulator, activation, normalization, quantization)
- UART-based host interface
- Multi-layer MLP inference capability
- FPGA deployment on Basys3 (Xilinx Artix-7)

**Resource Usage (Basys3 XC7A35T):**
<img width="4032" height="3024" alt="image" src="https://github.com/user-attachments/assets/4df73d8c-6068-4ba8-a65d-c223d89de3aa" />

- LUTs: ~1,000 (5% utilization)
- Flip-Flops: ~1,000 (3% utilization)
- DSP48E1: 8 slices
- BRAM: ~10-15 blocks
- Estimated Gate Count: ~25,000 gates

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Quick Start](#quick-start)
3. [Simulation & Testing](#simulation--testing)
4. [FPGA Build & Deployment](#fpga-build--deployment)
5. [Running Inference](#running-inference)
6. [Project Structure](#project-structure)
7. [Architecture Details](#architecture-details)
8. [Open Source Tooling (Yosys/nextpnr)](#open-source-tooling-yosysnextpnr)

---

## Project Overview

TinyTinyTPU is an educational implementation of Google's TPU architecture, scaled down to a 2×2 systolic array. It demonstrates:

- **Systolic Array Architecture**: Data flows horizontally (activations) and vertically (partial sums)
- **Diagonal Wavefront Weight Loading**: Staggered weight capture for proper systolic timing
- **Full MLP Pipeline**: Weight FIFO → MMU → Accumulator → Activation → Normalization → Quantization
- **Multi-Layer Inference**: Supports sequential layer processing with double-buffered activations

### Design Philosophy

This is a **minimal, educational-scale TPU** designed for:
- Learning TPU architecture principles
- Understanding systolic array dataflow
- FPGA prototyping and experimentation
- Small-scale ML inference (2×2 matrices)

For production workloads, scale up the array size (e.g., 256×256 like Google TPU v1).

---

## Quick Start

### Prerequisites

**For Simulation:**
- Verilator 5.022 or later
- Python 3.8+
- cocotb
- GTKWave or Surfer (for waveform viewing)

**For FPGA Build:**
- Xilinx Vivado 2020.1 or later (for Basys3)
- OR Yosys + nextpnr (open source alternative, see [Open Source Tooling](#open-source-tooling-yosysnextpnr))

**For Running Inference:**
- Basys3 FPGA board
- USB cable for programming
- Python 3.8+ with pyserial

### Installation

```bash
# Clone the repository
git clone <repository-url>
cd tinytinyTPU-co

# Set up simulation environment
cd sim
python3 -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate
pip install -r requirements.txt
```

---

## Simulation & Testing

### Running Tests

All simulation commands must be run from the `sim/` directory:

```bash
cd sim

# Run all tests
make test

# Run all tests with waveform generation
make test WAVES=1

# Run specific module tests
make test_pe
make test_mmu
make test_mlp
make test_uart
make test_tpu_system

# Run with waveforms
make test_pe WAVES=1
```

### Test Coverage

| Test File | Module | Coverage |
|-----------|--------|----------|
| `test_pe.py` | Processing Element | Reset, MAC operations, weight capture |
| `test_mmu.py` | 2×2 Systolic Array | Weight loading, matrix multiply |
| `test_weight_fifo.py` | Weight FIFO | Push/pop, wraparound |
| `test_dual_weight_fifo.py` | Dual Weight FIFO | Column independence, skew timing |
| `test_accumulator.py` | Accumulator | Alignment, buffering, accumulate/overwrite modes |
| `test_activation_func.py` | Activation Function | ReLU positive/negative/zero cases |
| `test_normalizer.py` | Normalizer | Gain, bias, shift operations |
| `test_activation_pipeline.py` | Activation Pipeline | Full pipeline, saturation handling |
| `test_mlp_integration.py` | MLP Top | Multi-layer MLP inference |
| `test_uart_controller.py` | UART Controller | Command parsing, response generation |
| `test_tpu_system.py` | TPU Top | End-to-end system integration |

### Viewing Waveforms

```bash
# List available waveforms
make waves

# Open specific waveform
make waves MODULE=pe
make waves MODULE=mmu
make waves MODULE=mlp_top
```

---

## FPGA Build & Deployment

### Hardware Connections

**Basys3 Pinout:**
- **UART RX** (B18): Receives commands from PC
- **UART TX** (A18): Sends responses to PC
- **Clock**: 100 MHz (onboard oscillator)
- **Reset**: Center button (BTNC, U18)
- **LEDs**: Status display (see `fpga/README.md` for LED modes)

**UART Settings:**
- Baud Rate: 115200
- Data Bits: 8
- Parity: None
- Stop Bits: 1

---

## Running Inference

### Python Host Interface

The project includes a Python driver for communicating with the FPGA:

```bash
cd host

# Basic inference demo
python3 inference_demo.py

# Gesture recognition demo (requires trained model)
python3 gesture_demo.py

# Interactive test
python3 test_tpu_driver.py
```

### Inference Demo

The `inference_demo.py` script demonstrates:
1. Loading weights into the TPU
2. Loading input activations
3. Executing inference
4. Reading results

**Example Usage:**
```python
from tpu_driver import TPUDriver

# Connect to FPGA (adjust port as needed)
tpu = TPUDriver('/dev/ttyUSB0')  # Linux
# tpu = TPUDriver('COM3')         # Windows

# Load 2×2 weight matrix
weights = [[1, 2], [3, 4]]
tpu.write_weights(weights)

# Load 2×2 activation matrix
activations = [[5, 6], [7, 8]]
tpu.write_activations(activations)

# Execute inference
tpu.execute()

# Read results
result = tpu.read_result()
print(f"Result: {result}")
```

### Gesture Recognition Demo

The `gesture_demo.py` script implements a simple gesture classifier:
- Trains a 2-layer MLP on mouse movement data
- Classifies gestures as "Horizontal" or "Vertical"
- Real-time inference on FPGA

**Running the Demo:**
```bash
cd host
python3 gesture_demo.py
```

**Model Training:**
```bash
cd model
python3 train.py
# Generates: gesture_model.json
```

### UART Protocol

The TPU uses a simple byte-based UART protocol:

**Commands:**
- `0x01`: Write Weight (4 bytes: W00, W01, W10, W11)
- `0x02`: Write Activation (4 bytes: A00, A01, A10, A11)
- `0x03`: Execute (start inference)
- `0x04`: Read Result (returns 4 bytes: acc0[31:0])
- `0x05`: Read Result Column 1 (returns 4 bytes: acc1[31:0])
- `0x06`: Read Status (returns 1 byte: state[3:0] | cycle_cnt[3:0])

See `host/tpu_driver.py` for full protocol implementation.

---

## Project Structure

```
tinytinyTPU-co/
├── rtl/                          # SystemVerilog RTL source files
│   ├── pe.sv                     # Processing Element (MAC unit)
│   ├── mmu.sv                    # 2×2 Matrix Multiply Unit (systolic array)
│   ├── weight_fifo.sv            # Single-column weight FIFO
│   ├── dual_weight_fifo.sv       # Dual-column weight FIFO with skew
│   ├── accumulator.sv            # Top-level accumulator
│   ├── accumulator_align.sv      # Column alignment logic
│   ├── accumulator_mem.sv        # Double-buffered accumulator memory
│   ├── activation_func.sv        # ReLU/ReLU6 activation
│   ├── normalizer.sv             # Gain/bias/shift normalization
│   ├── loss_block.sv             # L1 loss computation
│   ├── activation_pipeline.sv    # Full post-accumulator pipeline
│   ├── unified_buffer.sv          # Ready/valid output FIFO
│   ├── mlp_top.sv                # Top-level MLP integration
│   ├── tpu_bridge.sv              # UART-to-MLP bridge
│   ├── uart_controller.sv         # UART command processor
│   ├── uart_rx.sv                # UART receiver
│   ├── uart_tx.sv                # UART transmitter
│   └── tpu_top.sv                # Complete TPU system
│
├── sim/                          # Simulation environment
│   ├── Makefile                  # Build and test automation
│   ├── requirements.txt          # Python dependencies
│   ├── tests/                    # cocotb Python testbenches
│   │   ├── test_pe.py
│   │   ├── test_mmu.py
│   │   ├── test_weight_fifo.py
│   │   ├── test_dual_weight_fifo.py
│   │   ├── test_accumulator.py
│   │   ├── test_activation_func.py
│   │   ├── test_normalizer.py
│   │   ├── test_activation_pipeline.py
│   │   ├── test_mlp_integration.py
│   │   ├── test_uart_controller.py
│   │   └── test_tpu_system.py
│   └── waves/                    # Generated VCD waveforms
│
├── fpga/                         # FPGA deployment files
│   ├── basys3_top.sv             # Top-level FPGA wrapper
│   ├── basys3.xdc                # Pin constraints
│   ├── build_vivado.tcl          # Automated build script
│   ├── basys3_top.bit            # Generated bitstream
│   └── README.md                 # FPGA-specific documentation
│
├── host/                         # Python host interface
│   ├── tpu_driver.py             # TPU communication driver
│   ├── tpu_compiler.py           # Model compilation utilities
│   ├── inference_demo.py          # Basic inference demo
│   ├── gesture_demo.py           # Gesture recognition demo
│   └── test_tpu_driver.py        # Driver unit tests
│
├── model/                        # ML model training
│   ├── train.py                  # Model training script
│   └── gesture_model.json        # Trained model (JSON format)
│
└── README.md                     # This file
```

---

## Architecture Details

### Systolic Array Dataflow

```
PE00 -> PE01    Activations flow horizontally (right)
  |       |     
PE10 -> PE11    Partial sums flow vertically (down)
  |       |
acc0    acc1    Outputs to accumulator
```

**Weight Loading (Diagonal Wavefront):**
- Cycle 0: W10 → col0, no capture
- Cycle 1: W00 → col0 (capture), W11 → col1 (no capture)
- Cycle 2: W01 → col1 (capture)

**Activation Flow:**
- Row 0: A00 → PE00 → PE01
- Row 1: A10 → PE10 → PE11 (with 1-cycle skew)

### Pipeline Stages

1. **Weight FIFO**: Stores weights, outputs with column skew
2. **MMU (Systolic Array)**: Matrix multiply-accumulate
3. **Accumulator**: Aligns columns, double-buffered storage
4. **Activation Pipeline**:
   - Activation function (ReLU/ReLU6)
   - Normalization (gain × bias + shift)
   - Quantization (int8 with saturation)
5. **Unified Buffer**: Output FIFO with ready/valid handshaking

### Multi-Layer MLP

The MLP controller manages sequential layer processing:

```
State Machine:
IDLE → LOAD_WEIGHT → LOAD_ACT → COMPUTE → DRAIN → TRANSFER → NEXT_LAYER → WAIT_WEIGHTS → ...
```

- **Double Buffering**: Activations ping-pong between buffers for layer-to-layer transfer
- **Weight Loading**: Weights loaded per layer via UART
- **Pipeline Overlap**: While layer N drains, layer N+1 weights can be loaded

---

## Open Source Tooling (Yosys/nextpnr)

### Overview

While Vivado is the standard toolchain for Xilinx FPGAs, open-source alternatives exist:
- **Yosys**: Synthesis (RTL → netlist)
- **nextpnr**: Place & Route (netlist → bitstream)

### Setup

**Installation (Ubuntu/Debian):**
```bash
# Install Yosys
sudo apt-get install yosys

# Install nextpnr (for Xilinx 7-series)
# Requires building from source - see nextpnr documentation
git clone https://github.com/YosysHQ/nextpnr.git
cd nextpnr
cmake . -DARCH=xilinx
make -j$(nproc)
sudo make install
```

**Installation (macOS):**
```bash
brew install yosys
# nextpnr requires manual build
```

### Building with Yosys/nextpnr

**Step 1: Synthesis (Yosys)**
```bash
cd fpga

# Create synthesis script
cat > synth.ys << 'EOF'
# Read RTL files
read_verilog -sv ../rtl/pe.sv
read_verilog -sv ../rtl/mmu.sv
read_verilog -sv ../rtl/weight_fifo.sv
read_verilog -sv ../rtl/dual_weight_fifo.sv
read_verilog -sv ../rtl/accumulator_align.sv
read_verilog -sv ../rtl/accumulator_mem.sv
read_verilog -sv ../rtl/accumulator.sv
read_verilog -sv ../rtl/activation_func.sv
read_verilog -sv ../rtl/normalizer.sv
read_verilog -sv ../rtl/loss_block.sv
read_verilog -sv ../rtl/activation_pipeline.sv
read_verilog -sv ../rtl/unified_buffer.sv
read_verilog -sv ../rtl/mlp_top.sv
read_verilog -sv ../rtl/uart_rx.sv
read_verilog -sv ../rtl/uart_tx.sv
read_verilog -sv ../rtl/uart_controller.sv
read_verilog -sv ../rtl/tpu_bridge.sv
read_verilog -sv ../rtl/tpu_top.sv
read_verilog -sv basys3_top.sv

# Set top module
hierarchy -top basys3_top

# Synthesize
synth_xilinx -top basys3_top -family xc7

# Write netlist
write_verilog basys3_top_synth.v
write_json basys3_top.json
EOF

# Run synthesis
yosys synth.ys
```

**Step 2: Place & Route (nextpnr)**
```bash
# Generate bitstream
nextpnr-xilinx \
    --xdc basys3.xdc \
    --json basys3_top.json \
    --write basys3_top_routed.json \
    --fasm basys3_top.fasm

# Generate bitstream (requires Xilinx tools or open-source fasm2bit)
# Note: fasm2bit conversion may require Xilinx tools or open-source alternatives
```
---


### Building with Vivado

The project includes a TCL script for automated Vivado builds:

```bash
cd fpga

# Build bitstream (synthesis + implementation + bitgen)
vivado -mode batch -source build_vivado.tcl

# Expected build time: 5-10 minutes
# Output: basys3_top.bit
```

**Build Script Details:**
- Creates Vivado project: `vivado_project/tinytinyTPU_basys3`
- Synthesizes all RTL files from `../rtl/`
- Implements design with timing constraints
- Generates bitstream: `basys3_top.bit`
- Creates reports: utilization, timing, DRC

**Resource Utilization (Post-Implementation):**
- Check `vivado_project/tinytinyTPU_basys3.runs/impl_1/utilization_post_impl.rpt`
- Check `vivado_project/tinytinyTPU_basys3.runs/impl_1/timing_summary_post_impl.rpt`

### Programming the FPGA

**Via Vivado Hardware Manager (GUI):**
1. Connect Basys3 board via USB
2. Open Vivado
3. Open Hardware Manager
4. Auto-connect to target
5. Program with `basys3_top.bit`

**Via Command Line:**
```bash
vivado -mode tcl
open_hw_manager
connect_hw_server
open_hw_target
set_property PROGRAM.FILE {basys3_top.bit} [get_hw_devices xc7a35t_0]
program_hw_devices [get_hw_devices xc7a35t_0]
```

**Via OpenOCD (Alternative):**
```bash
# If using OpenOCD with Digilent cable
openocd -f interface/ftdi/digilent_jtag_hs3.cfg -f target/xc7a35t.cfg
# Then use GDB or other tools to program
```
---
### Limitations & Considerations

**Current Status:**
- Yosys synthesis works well for most SystemVerilog constructs
- nextpnr supports Xilinx 7-series but may have timing/routing challenges
- Bitstream generation (fasm2bit) may require Xilinx tools or open-source alternatives

**Recommendations:**
- For development: Use Vivado for reliable builds
- For open-source exploration: Use Yosys for synthesis, verify with Vivado
- For production: Stick with Vivado until open-source toolchain matures

**Future Work:**
- Create automated Yosys/nextpnr build script
- Document fasm2bit conversion process
- Benchmark open-source vs. Vivado results

---

## Troubleshooting

### Simulation Issues

**Verilator Errors:**
- Ensure Verilator 5.022+ is installed
- Check SystemVerilog syntax (use `make lint`)

**Test Failures:**
- Run with `WAVES=1` to generate waveforms for debugging
- Check `sim/test_output.log` for detailed error messages

### FPGA Build Issues

**Synthesis Errors:**
- Check RTL files are in `rtl/` directory
- Verify SystemVerilog syntax (Vivado may be stricter than Verilator)

**Timing Violations:**
- Check `timing_summary_post_impl.rpt`
- May need to add pipeline stages or reduce clock frequency

**Place & Route Failures:**
- Check utilization reports
- Verify constraints in `basys3.xdc`

### Hardware Issues

**UART Not Working:**
- Verify COM port: `ls /dev/ttyUSB*` (Linux) or Device Manager (Windows)
- Check baud rate: 115200
- Verify TX/RX pins in constraints file

**LEDs Not Responding:**
- Check bitstream programmed correctly
- Verify reset button (center button)
- Check switch settings for LED modes (see `fpga/README.md`)

---

## Contributing

Contributions welcome! Areas for improvement:
- Additional test coverage
- Performance optimizations
- Documentation improvements
- Open-source toolchain support
- Larger array sizes


---

## License
MIT License

Copyright (c) 2026 
Alan Ma, Abiral Shakya

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


---

## References

- [Google TPU Paper](https://arxiv.org/abs/1704.04760)
- [TPU Architecture Blog](https://chewingonchips.substack.com/)
- [Systolic Arrays](https://en.wikipedia.org/wiki/Systolic_array)
- [Basys3 Reference Manual](https://digilent.com/reference/programmable-logic/basys-3/reference-manual)

---

## Acknowledgments

- Inspired by Google's TPU architecture (thank you Cliff and Richard for your time!)
- The boys from the TinyTPU team!!
- Edmund and the Yosys / Symbiotic EDA crew
- Stanford FAF for the support, funding, and community!
- Princeton ECE Dept for the Basys 3 to play around with :)
