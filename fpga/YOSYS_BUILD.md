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

**Note:** nextpnr-xilinx is experimental and complex to set up. For production builds, **Vivado is strongly recommended**.

nextpnr-xilinx requires several dependencies:

#### Prerequisites

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install cmake libboost-all-dev libeigen3-dev openjdk-11-jdk

# macOS
brew install cmake boost eigen openjdk@11
```

#### Install RapidWright

RapidWright is required for Xilinx device support:

```bash
# Download RapidWright
wget https://github.com/Xilinx/RapidWright/releases/download/v2023.1.1/rapidwright-2023.1.1-standalone-lin64.tgz
tar -xzf rapidwright-2023.1.1-standalone-lin64.tgz
export RAPIDWRIGHT_PATH=$(pwd)/rapidwright-2023.1.1-standalone-lin64
```

#### Install Project X-Ray

Project X-Ray provides the Xilinx 7-series bitstream database:

```bash
# Clone Project X-Ray
git clone --recursive https://github.com/SymbiFlow/prjxray.git
cd prjxray
# Follow installation instructions in their README
```

#### Build nextpnr-xilinx

```bash
# Clone nextpnr-xilinx (separate repository from main nextpnr)
git clone --recursive https://github.com/gatecat/nextpnr-xilinx.git
cd nextpnr-xilinx

# Create build directory (out-of-tree build required)
mkdir build
cd build

# Configure with RapidWright path
cmake .. -DARCH=xilinx -DRAPIDWRIGHT_PATH=$RAPIDWRIGHT_PATH

# Build (use sysctl -n hw.ncpu on macOS instead of nproc)
make -j$(nproc)  # Linux
# make -j$(sysctl -n hw.ncpu)  # macOS

# Install
sudo make install
```

**Alternative (Linux only):** The openXC7 toolchain installer can automate this:

```bash
wget -qO - https://raw.githubusercontent.com/openXC7/toolchain-installer/main/toolchain-installer.sh | bash
```

### 3. Bitstream Generation

For Xilinx 7-series, bitstream generation from FASM requires additional tools. The openXC7 toolchain includes these, or you can use Vivado's `write_bitstream` command on the EDIF file.

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

## Yosys Compatibility Notes

The RTL has been modified for Yosys compatibility:

1. **Array Initialization**: Replaced SystemVerilog `'{...}` syntax with reset-based initialization
2. **Signed Constants**: Replaced `'sd` syntax with standard decimal constants
3. **Function Returns**: Replaced function `return` statements with `always_comb` blocks

These changes maintain Vivado compatibility while enabling Yosys synthesis.

## Platform Support

- **Linux**: Full support for Yosys + nextpnr-xilinx (with RapidWright setup)
- **macOS**: Yosys works, but nextpnr-xilinx setup is complex and may have issues
- **Windows**: Use WSL or Vivado directly

**Recommendation**: For Xilinx FPGAs, use Vivado for production builds. The open-source toolchain is best for:
- Learning and experimentation
- Lattice FPGAs (where nextpnr has mature support)
- CI/CD environments where licensing is an issue

## Limitations

1. **SystemVerilog Support**: Yosys has limited SystemVerilog support compared to Vivado
2. **Timing Analysis**: nextpnr provides basic timing analysis, not as comprehensive as Vivado
3. **Optimization**: Vivado may produce better area/timing results
4. **Debug Tools**: No equivalent to Vivado's ILA/ChipScope
5. **Xilinx Support**: nextpnr-xilinx is experimental and requires complex setup (RapidWright, Project X-Ray)

## Recommendations

- **For Development**: Use Yosys/nextpnr for quick iterations
- **For Production**: Use Vivado for best results and timing closure
- **For Learning**: Yosys/nextpnr is excellent for understanding the toolchain

## Additional Resources

- [Yosys Manual](https://yosyshq.readthedocs.io/)
- [nextpnr Documentation](https://github.com/YosysHQ/nextpnr)
- [prjtrellis Documentation](https://github.com/Yowlings/prjtrellis)
- [Project Trellis](https://github.com/SymbiFlow/prjtrellis) - Xilinx bitstream documentation

