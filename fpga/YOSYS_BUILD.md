# Yosys/nextpnr Build Guide

This guide explains how to build the TinyTinyTPU FPGA bitstream using open-source tools (Yosys + nextpnr) instead of Xilinx Vivado.

## Prerequisites

### 1. Install Yosys

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install yosys
```

**macOS:**
```bash
brew install yosys
```

**From Source:**
```bash
git clone https://github.com/YosysHQ/yosys.git
cd yosys
make -j$(nproc)
sudo make install
```

### 2. Install nextpnr-xilinx

nextpnr-xilinx requires building from source:

```bash
# Install dependencies
sudo apt-get install cmake libboost-all-dev libeigen3-dev

# Clone nextpnr
git clone https://github.com/YosysHQ/nextpnr.git
cd nextpnr

# Build for Xilinx architecture
cmake . -DARCH=xilinx -DTRELLIS_INSTALL_PREFIX=/usr
make -j$(nproc)
sudo make install
```

### 3. Install prjtrellis (for bitstream generation)

prjtrellis provides tools to convert FASM to bitstream:

```bash
# Install dependencies
sudo apt-get install python3-dev libboost-python-dev

# Clone prjtrellis
git clone https://github.com/Yowlings/prjtrellis.git
cd prjtrellis/libtrellis

# Build
cmake .
make -j$(nproc)
sudo make install
```

## Building the Bitstream

### Quick Build

```bash
cd fpga
./build_yosys.sh
```

This script will:
1. Run Yosys synthesis (RTL → netlist)
2. Run nextpnr place & route (netlist → FASM)
3. Convert FASM to bitstream (if prjtrellis is installed)

### Manual Build Steps

#### Step 1: Synthesis with Yosys

```bash
cd fpga
yosys synth_yosys.ys
```

This generates:
- `basys3_top_yosys.v` - Synthesized Verilog netlist
- `basys3_top.json` - JSON netlist for nextpnr
- `basys3_top.edif` - EDIF netlist (alternative format)

#### Step 2: Place & Route with nextpnr

```bash
nextpnr-xilinx \
    --xdc basys3.xdc \
    --json basys3_top.json \
    --write basys3_top_routed.json \
    --fasm basys3_top.fasm
```

This generates:
- `basys3_top.fasm` - FPGA Assembly (FASM) file
- `basys3_top_routed.json` - Routed netlist

#### Step 3: Generate Bitstream

**Option A: Using prjtrellis (recommended)**

```bash
# Convert FASM to frames
fasm2frames --db $(prjtrellis-config --sharedir)/database \
            --part xc7a35tcpg236-1 \
            basys3_top.fasm \
            basys3_top.frames

# Convert frames to bitstream
xc7frames2bit --part xc7a35tcpg236-1 \
              --frm_file basys3_top.frames \
              --output_file basys3_top_yosys.bit
```

**Option B: Using Vivado (fallback)**

If prjtrellis is not available, you can use Vivado to convert FASM:

```bash
vivado -mode tcl
read_fasm basys3_top.fasm
write_bitstream basys3_top.bit
```

## Output Files

After successful build:

- `basys3_top_yosys.v` - Synthesized netlist
- `basys3_top.json` - JSON netlist
- `basys3_top.fasm` - FPGA assembly file
- `basys3_top_yosys.bit` - FPGA bitstream (if prjtrellis installed)

## Comparison: Yosys/nextpnr vs Vivado

| Feature | Yosys/nextpnr | Vivado |
|---------|---------------|--------|
| License | Open Source (ISC) | Proprietary |
| Cost | Free | Requires license |
| Synthesis Quality | Good | Excellent |
| Timing Analysis | Basic | Advanced |
| Routing Quality | Good | Excellent |
| Bitstream Generation | Requires prjtrellis | Built-in |
| Ease of Use | Moderate | Easy |

## Troubleshooting

### Yosys Synthesis Errors

**Error: "Unknown module"**
- Check that all RTL files are listed in `synth_yosys.ys`
- Verify file paths are correct

**Error: "Unsupported SystemVerilog feature"**
- Yosys has limited SystemVerilog support
- May need to modify RTL to be more Verilog-compatible

### nextpnr Place & Route Errors

**Error: "Failed to route"**
- Design may be too complex for nextpnr
- Try with Vivado for comparison
- Check timing constraints in `basys3.xdc`

**Error: "Missing XDC constraints"**
- Ensure `basys3.xdc` exists and has proper pin constraints
- Verify clock constraints are defined

### Bitstream Generation Errors

**Error: "fasm2frames not found"**
- Install prjtrellis (see Prerequisites)
- Ensure database files are available

**Error: "Invalid FASM format"**
- Verify nextpnr completed successfully
- Check FASM file is not empty

## Limitations

1. **SystemVerilog Support**: Yosys has limited SystemVerilog support compared to Vivado
2. **Timing Analysis**: nextpnr provides basic timing analysis, not as comprehensive as Vivado
3. **Optimization**: Vivado may produce better area/timing results
4. **Debug Tools**: No equivalent to Vivado's ILA/ChipScope

## Recommendations

- **For Development**: Use Yosys/nextpnr for quick iterations
- **For Production**: Use Vivado for best results and timing closure
- **For Learning**: Yosys/nextpnr is excellent for understanding the toolchain

## Additional Resources

- [Yosys Manual](https://yosyshq.readthedocs.io/)
- [nextpnr Documentation](https://github.com/YosysHQ/nextpnr)
- [prjtrellis Documentation](https://github.com/Yowlings/prjtrellis)
- [Project Trellis](https://github.com/SymbiFlow/prjtrellis) - Xilinx bitstream documentation

