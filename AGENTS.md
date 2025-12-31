# Repository Guidelines

## Project Structure & Module Organization
- RTL lives in `rtl/` with one SystemVerilog module per file (`pe.sv`, `mmu.sv`, etc.); synthesis-friendly submodules should stay isolated so they can be reused in other arrays.
- Simulation assets are under `sim/` with the `Makefile`, cocotb tests in `tests/`, and generated VCDs in `waves/`.
- Legacy Vivado collateral remains in `archive/` for reference; do not edit it except when mining constraint or IP configuration examples.
- Favor a top-down flow: update `rtl/mlp_top.sv` first, then push new interfaces down into pipeline, accumulator, FIFO, and PE modules.

## Build, Test, and Development Commands
- `cd sim && make test` – run the full Verilator+cocotb regression; add `WAVES=1` for VCD dumps in `waves/`.
- `make test_<module>` – execute targeted tests such as `make test_mmu` or `make test_activation_pipeline`.
- `make lint` – Verilator lint with the repository default flags; keep this clean before opening a PR.
- `make waves MODULE=pe` – launch the configured waveform viewer for a specific module.

## Coding Style & Naming Conventions
- SystemVerilog modules use `lower_snake_case`, signals use `lower_snake_case`, parameters stay `UPPER_SNAKE_CASE`.
- Keep logic synchronous to `clk`; prefer synchronous resets and `always_ff`/`always_comb`.
- Interface boundaries should use explicit ready/valid or FIFO semantics; when multiple modules share a bus, wrap signals in an `interface`.
- Pipeline depth adjustments should be expressed with short comments or parameter names (`PIPE_LATENCY`, `SKEW_CYCLES`) to aid timing reviews.

## Testing Guidelines
- All verification uses cocotb with pytest discovery; add new scenarios in `sim/tests/test_<module>.py`.
- Name tests after the behavior under test (e.g., `test_weight_fifo_wraparound`); ensure self-checking asserts and waveform-friendly debug prints.
- When introducing new modules, add both unit tests and an integration hook (often via `test_mlp_integration.py`) to exercise end-to-end flow.
- Expectations: smoke tests must pass locally (`make test`), and targeted module tests should include edge cases (reset, overflow, CDC boundaries).

## Commit & Pull Request Guidelines
- Follow the existing short, imperative commit style seen in `git log` (`"Add UART DMA module for Basys3"`). Squash noisy WIP commits before sharing.
- PRs should include: summary of motivation, key RTL or sim touchpoints, verification evidence (`make test` output, waveform snapshots if timing fix), and any linked issues.
- Mention timing, CDC, or resource implications explicitly; attach updated XDC snippets or STA highlights when relevant.
- Keep diffs focused—new modules belong in their own commits/PRs, and regenerated Vivado artifacts stay out of version control.

## Design & Timing Practices
- Stay in a single clock domain unless unavoidable; document any CDC paths and provide synchronizers/FIFOs.
- Define XDC constraints early, track STA violations, and use pipelining to relieve critical paths; note LUT/FF/BRAM impacts in PR descriptions.
- Use assertion-based checks (SystemVerilog `assert` or cocotb `assert`) to detect protocol violations and to guard diagonal weight-loading assumptions.
