# Open-Source FPGA Build (Yosys + nextpnr)

Build TinyTinyTPU for Basys3 using the open-source toolchain.

## Prerequisites

- Yosys (synthesis): `brew install yosys`
- nextpnr-himbaechel with Xilinx support (place & route)
- prjxray database and tools (bitstream generation)

## Quick Build

Run the automated build script:

```bash
cd fpga
bash build_yosys.sh
```

## Manual Build Steps

### 1. Synthesis (Yosys)

```bash
cd fpga
yosys synth_yosys.ys
```

Output: `basys3_top.json`

### 2. Place and Route (nextpnr)

```bash
~/tools/nextpnr/build/nextpnr-himbaechel \
    --device xc7a35tcpg236-1 \
    --chipdb ~/tools/nextpnr/build/share/himbaechel/xilinx/chipdb-xc7a50t.bin \
    --json basys3_top.json \
    -o xdc=basys3_nextpnr.xdc \
    -o fasm=basys3_top_nextpnr.fasm \
    --router router2
```

Output: `basys3_top_nextpnr.fasm`

### 3. Generate Bitstream (prjxray)

```bash
# Convert FASM to frames
~/tools/prjxray-venv/bin/python3 ~/tools/prjxray/utils/fasm2frames.py \
    --db-root ~/tools/prjxray/database/artix7 \
    --part xc7a35tcpg236-1 \
    basys3_top_nextpnr.fasm basys3_top.frames

# Convert frames to bitstream
~/tools/prjxray/build/tools/xc7frames2bit \
    --part_name xc7a35tcpg236-1 \
    --part_file ~/tools/prjxray/database/artix7/xc7a35tcpg236-1/part.yaml \
    --frm_file basys3_top.frames \
    --output_file basys3_top_yosys.bit
```

Output: `basys3_top_yosys.bit`

### 4. Program FPGA

```bash
openFPGALoader -b basys3 basys3_top_yosys.bit
```

## Tool Installation

### nextpnr-himbaechel

```bash
cd ~/tools
git clone https://github.com/YosysHQ/nextpnr.git
cd nextpnr && git submodule update --init --recursive

git clone https://github.com/f4pga/prjxray.git ~/tools/prjxray
cd ~/tools/prjxray && bash download-latest-db.sh

mkdir -p ~/tools/nextpnr/build && cd ~/tools/nextpnr/build
cmake .. -DARCH=himbaechel -DHIMBAECHEL_UARCH=xilinx \
         -DHIMBAECHEL_XILINX_DEVICES=xc7a50t \
         -DHIMBAECHEL_PRJXRAY_DB=~/tools/prjxray/database \
         -DBUILD_PYTHON=OFF
make -j$(nproc)
```

### prjxray tools

```bash
cd ~/tools/prjxray
git submodule update --init --recursive

python3 -m venv ~/tools/prjxray-venv
~/tools/prjxray-venv/bin/pip install fasm
cd ~/tools/prjxray && ~/tools/prjxray-venv/bin/pip install -e .

mkdir -p build && cd build
cmake .. -DCMAKE_POLICY_VERSION_MINIMUM=3.5
make xc7frames2bit -j$(nproc)
```

## Notes

- The xc7a35t and xc7a50t share the same silicon die, so xc7a50t chipdb works for Basys3
- Use `basys3_nextpnr.xdc` for constraints (uses LOC instead of PACKAGE_PIN)
- nextpnr-himbaechel for Xilinx is experimental but functional
