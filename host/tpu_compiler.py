#!/usr/bin/env python3
"""
tiny²TPU Model Compiler

Trains a tiny neural network and compiles it to run on the TPU hardware.

This demonstrates the full flow:
1. Define a model that fits the 2x2 systolic array
2. Train on synthetic or real data
3. Quantize weights to uint8
4. Generate TPU-compatible weight format
5. Run inference on actual hardware

Usage:
    python3 tpu_compiler.py train          # Train a new model
    python3 tpu_compiler.py run <port>     # Run trained model on TPU
    python3 tpu_compiler.py test           # Test with simulation

Requirements:
    pip install numpy torch pyserial
"""

import os
import sys
import json
import numpy as np

# Add script directory to path
script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir not in sys.path:
    sys.path.insert(0, script_dir)

# Optional PyTorch import
try:
    import torch
    import torch.nn as nn
    import torch.optim as optim
    TORCH_AVAILABLE = True
except ImportError:
    TORCH_AVAILABLE = False
    print("Note: PyTorch not available, using numpy-only mode")

# TPU Driver
try:
    from tpu_driver import TPUDriver
except ImportError:
    TPUDriver = None


# ============================================================================
# Model Definition
# ============================================================================

class TinyModel(nn.Module):
    """
    Tiny neural network that fits on 2x2 TPU.

    Architecture:
        Input:  2 values
        Hidden: 2 neurons (2x2 weight matrix)
        Output: 2 values (2x2 weight matrix)

    This maps directly to two TPU inferences.
    """

    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(2, 2, bias=False)
        self.fc2 = nn.Linear(2, 2, bias=False)
        self.relu = nn.ReLU()

    def forward(self, x):
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x


# ============================================================================
# Quantization
# ============================================================================

class Quantizer:
    """Handles float32 -> uint8 quantization for TPU."""

    def __init__(self):
        self.scale = 1.0
        self.zero_point = 0

    def fit(self, weights: np.ndarray):
        """Compute quantization parameters from weights."""
        w_min = weights.min()
        w_max = weights.max()

        # Symmetric quantization around 0
        # Map [-max_abs, +max_abs] to [0, 255]
        max_abs = max(abs(w_min), abs(w_max))
        if max_abs < 1e-8:
            max_abs = 1.0

        self.scale = 127.0 / max_abs
        self.zero_point = 128  # 128 represents 0

        return self

    def quantize(self, weights: np.ndarray) -> np.ndarray:
        """Quantize float weights to uint8."""
        q = np.round(weights * self.scale + self.zero_point)
        return np.clip(q, 0, 255).astype(np.uint8)

    def dequantize(self, q_weights: np.ndarray) -> np.ndarray:
        """Dequantize uint8 back to float (for verification)."""
        return (q_weights.astype(np.float32) - self.zero_point) / self.scale


# ============================================================================
# TPU Compiler
# ============================================================================

class TPUCompiler:
    """Compiles trained models for tiny²TPU execution."""

    def __init__(self):
        self.layers = []
        self.quantizers = []

    def compile(self, model: nn.Module) -> dict:
        """
        Compile a PyTorch model to TPU format.

        Returns dict with:
            - layers: list of quantized 2x2 weight matrices
            - quantizers: quantization parameters for each layer
            - metadata: model info
        """
        self.layers = []
        self.quantizers = []

        # Extract weights from each Linear layer
        for name, module in model.named_modules():
            if isinstance(module, nn.Linear):
                weights = module.weight.detach().numpy()

                # Verify 2x2
                if weights.shape != (2, 2):
                    raise ValueError(f"Layer {name} has shape {weights.shape}, expected (2, 2)")

                # Quantize
                quantizer = Quantizer().fit(weights)
                q_weights = quantizer.quantize(weights)

                self.layers.append(q_weights.tolist())
                self.quantizers.append({
                    'scale': quantizer.scale,
                    'zero_point': quantizer.zero_point
                })

                print(f"Layer {name}:")
                print(f"  Float weights:\n{weights}")
                print(f"  Quantized (uint8):\n{q_weights}")
                print(f"  Scale: {quantizer.scale:.4f}, Zero: {quantizer.zero_point}")
                print()

        return {
            'layers': self.layers,
            'quantizers': self.quantizers,
            'num_layers': len(self.layers),
            'input_size': 2,
            'output_size': 2,
        }

    def save(self, compiled: dict, path: str):
        """Save compiled model to JSON file."""
        with open(path, 'w') as f:
            json.dump(compiled, f, indent=2)
        print(f"Saved compiled model to {path}")

    def load(self, path: str) -> dict:
        """Load compiled model from JSON file."""
        with open(path, 'r') as f:
            return json.load(f)


# ============================================================================
# TPU Runtime
# ============================================================================

class TPURuntime:
    """Runs compiled models on tiny²TPU hardware."""

    def __init__(self, tpu: TPUDriver = None):
        self.tpu = tpu
        self.sim_mode = (tpu is None)

    def inference(self, compiled: dict, inputs: list) -> list:
        """
        Run inference with compiled model.

        Args:
            compiled: Output from TPUCompiler.compile()
            inputs: List of 2 input values (float, will be quantized)

        Returns:
            List of 2 output values
        """
        if len(inputs) != 2:
            raise ValueError("Input must have exactly 2 values")

        # Quantize inputs (assume 0-1 range -> 0-255)
        x = [int(np.clip(v * 255, 0, 255)) for v in inputs]

        # Process each layer
        for i, layer_weights in enumerate(compiled['layers']):
            # Format as 2x2 activation matrix (broadcast input to both rows)
            activations = [
                [x[0], x[1]],
                [x[0], x[1]]
            ]

            if self.sim_mode:
                # Simulate matrix multiply
                result = self._simulate_inference(layer_weights, activations)
            else:
                # Run on real TPU
                result = self.tpu.inference(layer_weights, activations)

            # Extract outputs from accumulator
            # acc0 = sum of column 0, acc1 = sum of column 1
            # Each column sum = 2 * (weighted sum) due to broadcast
            out0 = (result & 0xFFFF) // 2
            out1 = ((result >> 16) & 0xFFFF) // 2

            # Apply ReLU (except last layer)
            if i < len(compiled['layers']) - 1:
                out0 = max(0, out0 - 128)  # Subtract zero point, then ReLU
                out1 = max(0, out1 - 128)

            # Prepare for next layer
            x = [out0 & 0xFF, out1 & 0xFF]

        return x

    def _simulate_inference(self, weights: list, activations: list) -> int:
        """Simulate TPU inference for testing."""
        W = np.array(weights)
        A = np.array(activations)

        # Matrix multiply
        C = A @ W

        # Accumulate columns (what TPU does)
        acc0 = int(C[0, 0] + C[1, 0])
        acc1 = int(C[0, 1] + C[1, 1])

        # Pack as 32-bit result
        return (acc1 << 16) | (acc0 & 0xFFFF)


# ============================================================================
# Training
# ============================================================================

def generate_gesture_data(n_samples=1000):
    """Generate synthetic gesture training data."""
    X = []
    y = []

    for _ in range(n_samples):
        # Random direction
        direction = np.random.randint(0, 4)

        # Generate motion vector with noise
        base_magnitude = np.random.uniform(0.5, 1.0)
        noise = np.random.normal(0, 0.1, 2)

        if direction == 0:    # Right
            dx, dy = base_magnitude, 0
        elif direction == 1:  # Left
            dx, dy = -base_magnitude, 0
        elif direction == 2:  # Up
            dx, dy = 0, base_magnitude
        else:                 # Down
            dx, dy = 0, -base_magnitude

        dx += noise[0]
        dy += noise[1]

        # Normalize to [0, 1] range (0.5 = center)
        X.append([dx * 0.5 + 0.5, dy * 0.5 + 0.5])

        # One-hot encode direction (simplified to 2 outputs)
        # Output 0 = horizontal dominance, Output 1 = vertical dominance
        if direction in [0, 1]:  # Horizontal
            y.append([1.0, 0.0])
        else:  # Vertical
            y.append([0.0, 1.0])

    return np.array(X, dtype=np.float32), np.array(y, dtype=np.float32)


def train_model(epochs=100, lr=0.01):
    """Train a tiny gesture classifier."""
    if not TORCH_AVAILABLE:
        print("PyTorch required for training. Install with: pip install torch")
        return None

    print("Generating training data...")
    X, y = generate_gesture_data(1000)

    X_tensor = torch.from_numpy(X)
    y_tensor = torch.from_numpy(y)

    print(f"Training data: {X.shape[0]} samples")
    print(f"Input shape: {X.shape[1]}, Output shape: {y.shape[1]}")
    print()

    # Create model
    model = TinyModel()
    criterion = nn.MSELoss()
    optimizer = optim.Adam(model.parameters(), lr=lr)

    # Training loop
    print("Training...")
    for epoch in range(epochs):
        optimizer.zero_grad()
        outputs = model(X_tensor)
        loss = criterion(outputs, y_tensor)
        loss.backward()
        optimizer.step()

        if (epoch + 1) % 20 == 0:
            print(f"  Epoch {epoch+1}/{epochs}, Loss: {loss.item():.4f}")

    print()

    # Evaluate
    with torch.no_grad():
        predictions = model(X_tensor)
        pred_class = predictions.argmax(dim=1)
        true_class = y_tensor.argmax(dim=1)
        accuracy = (pred_class == true_class).float().mean()
        print(f"Training accuracy: {accuracy:.1%}")

    return model


# ============================================================================
# Main
# ============================================================================

def main():
    print("tiny²TPU Model Compiler")
    print("=" * 50)
    print()

    if len(sys.argv) < 2:
        print("Usage:")
        print("  python3 tpu_compiler.py train            # Train model")
        print("  python3 tpu_compiler.py run <port>       # Run on hardware")
        print("  python3 tpu_compiler.py test             # Test in simulation")
        return

    command = sys.argv[1]
    model_path = os.path.join(script_dir, "compiled_model.json")

    if command == "train":
        # Train model
        model = train_model(epochs=100)
        if model is None:
            return

        # Compile
        print("\nCompiling for TPU...")
        compiler = TPUCompiler()
        compiled = compiler.compile(model)
        compiler.save(compiled, model_path)

        print("\nModel ready! Run with:")
        print(f"  python3 tpu_compiler.py test")
        print(f"  python3 tpu_compiler.py run /dev/tty.usbserial-XXX")

    elif command == "test":
        # Test in simulation
        if not os.path.exists(model_path):
            print(f"No compiled model found at {model_path}")
            print("Run 'python3 tpu_compiler.py train' first")
            return

        compiler = TPUCompiler()
        compiled = compiler.load(model_path)

        print(f"Loaded model with {compiled['num_layers']} layers")
        print()

        runtime = TPURuntime(tpu=None)  # Simulation mode

        # Test cases
        test_inputs = [
            ([0.9, 0.5], "RIGHT"),   # dx positive
            ([0.1, 0.5], "LEFT"),    # dx negative
            ([0.5, 0.9], "UP"),      # dy positive
            ([0.5, 0.1], "DOWN"),    # dy negative
        ]

        print("Testing gesture classification:")
        for inputs, expected in test_inputs:
            outputs = runtime.inference(compiled, inputs)
            predicted = "HORIZONTAL" if outputs[0] > outputs[1] else "VERTICAL"
            expected_type = "HORIZONTAL" if expected in ["LEFT", "RIGHT"] else "VERTICAL"
            status = "OK" if predicted == expected_type else "WRONG"
            print(f"  {inputs} -> {outputs} -> {predicted} (expected {expected_type}) [{status}]")

    elif command == "run":
        if len(sys.argv) < 3:
            print("Usage: python3 tpu_compiler.py run <serial_port>")
            return

        port = sys.argv[2]

        if not os.path.exists(model_path):
            print(f"No compiled model found at {model_path}")
            print("Run 'python3 tpu_compiler.py train' first")
            return

        if not TPUDriver:
            print("TPU driver not found!")
            return

        compiler = TPUCompiler()
        compiled = compiler.load(model_path)

        print(f"Loaded model with {compiled['num_layers']} layers")
        print(f"Connecting to TPU on {port}...")

        with TPUDriver(port) as tpu:
            state, cycle = tpu.read_status()
            print(f"TPU connected! State: {state}")

            runtime = TPURuntime(tpu=tpu)

            # Interactive test
            print("\nInteractive mode - enter 'dx dy' values (0-1 range, 0.5=center)")
            print("Examples: '0.9 0.5' (right), '0.5 0.1' (down)")
            print("Enter 'q' to quit\n")

            while True:
                try:
                    line = input("Input> ").strip()
                    if line.lower() == 'q':
                        break

                    parts = line.split()
                    if len(parts) != 2:
                        print("  Enter two values: dx dy")
                        continue

                    inputs = [float(parts[0]), float(parts[1])]
                    outputs = runtime.inference(compiled, inputs)

                    direction = "HORIZONTAL" if outputs[0] > outputs[1] else "VERTICAL"
                    print(f"  Output: {outputs} -> {direction}")

                except ValueError:
                    print("  Invalid input")
                except KeyboardInterrupt:
                    break

        print("\nDone!")

    else:
        print(f"Unknown command: {command}")


if __name__ == "__main__":
    main()
