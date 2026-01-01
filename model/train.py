#!/usr/bin/env python3
"""
Gesture classifier training for tiny²TPU.

Trains a simple linear classifier to distinguish horizontal vs vertical motion.
The model learns: if dx > dy -> horizontal, else -> vertical

Usage:
    python3 train.py
    python3 train.py --epochs 300
"""

import os
import sys
import argparse
import json
import numpy as np
import random

model_dir = os.path.dirname(os.path.abspath(__file__))

# PyTorch
try:
    import torch
    import torch.nn as nn
    import torch.optim as optim
except ImportError:
    print("PyTorch required: pip install torch")
    sys.exit(1)


# ============================================================================
# Data Generation
# ============================================================================

def generate_data(n_samples=5000):
    """
    Generate gesture data with LINEAR decision boundary.

    Input: (dx, dy) in range [0, 1]
    Label: 0 = horizontal (dx > dy), 1 = vertical (dx <= dy)
    """
    X = []
    y = []

    for _ in range(n_samples):
        dx = random.uniform(0, 1)
        dy = random.uniform(0, 1)
        X.append([dx, dy])

        # Linear decision boundary
        if dx > dy:
            y.append(0)  # Horizontal
        else:
            y.append(1)  # Vertical

    return np.array(X, dtype=np.float32), np.array(y, dtype=np.int64)


# ============================================================================
# Model
# ============================================================================

class GestureNet(nn.Module):
    """Simple 1-layer classifier: 2 inputs -> 2 outputs."""

    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(2, 2, bias=True)

    def forward(self, x):
        return self.fc(x)


# ============================================================================
# Training
# ============================================================================

def train_model(epochs=200, verbose=True):
    """Train the gesture classifier."""

    if verbose:
        print("Generating training data...")

    X, y = generate_data(5000)

    if verbose:
        print(f"  Samples: {len(X)}")
        print(f"  Class 0 (horiz): {(y == 0).sum()}")
        print(f"  Class 1 (vert): {(y == 1).sum()}")

    # Split 80/20
    split = int(0.8 * len(X))
    X_train = torch.from_numpy(X[:split])
    y_train = torch.from_numpy(y[:split])
    X_val = torch.from_numpy(X[split:])
    y_val = torch.from_numpy(y[split:])

    # Model, loss, optimizer
    model = GestureNet()
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=0.5, momentum=0.9)

    if verbose:
        print(f"\nTraining for {epochs} epochs...")

    best_acc = 0
    best_weights = None

    for epoch in range(epochs):
        # Train step
        model.train()
        optimizer.zero_grad()
        outputs = model(X_train)
        loss = criterion(outputs, y_train)
        loss.backward()
        optimizer.step()

        # Validation
        model.eval()
        with torch.no_grad():
            val_out = model(X_val)
            val_pred = val_out.argmax(dim=1)
            val_acc = (val_pred == y_val).float().mean().item()

        if val_acc > best_acc:
            best_acc = val_acc
            best_weights = {k: v.clone() for k, v in model.state_dict().items()}

        if verbose and (epoch + 1) % 25 == 0:
            print(f"  Epoch {epoch+1:3d}: loss={loss.item():.4f}, val_acc={val_acc:.1%}")

    # Restore best weights
    if best_weights:
        model.load_state_dict(best_weights)

    if verbose:
        print(f"\nBest accuracy: {best_acc:.1%}")

    return model, best_acc


def evaluate(model):
    """Test on known cases."""
    # dx > dy -> class 0 (horiz), dx <= dy -> class 1 (vert)
    test_cases = [
        ([0.9, 0.1], "RIGHT", 0),
        ([0.1, 0.9], "UP", 1),
        ([0.8, 0.2], "right", 0),
        ([0.2, 0.8], "up", 1),
        ([0.7, 0.3], "horiz", 0),
        ([0.3, 0.7], "vert", 1),
        ([0.6, 0.4], "h", 0),
        ([0.4, 0.6], "v", 1),
        ([0.55, 0.45], "slight-h", 0),
        ([0.45, 0.55], "slight-v", 1),
    ]

    print("\nTest cases:")
    correct = 0
    model.eval()

    for inputs, desc, expected in test_cases:
        with torch.no_grad():
            out = model(torch.tensor([inputs]))
            pred = out.argmax().item()

        ok = pred == expected
        correct += ok
        status = "OK" if ok else "WRONG"
        label = "HORIZ" if pred == 0 else "VERT"
        print(f"  {desc:10s}: {inputs} -> {label} [{status}]")

    acc = correct / len(test_cases)
    print(f"\nTest accuracy: {correct}/{len(test_cases)} = {acc:.0%}")
    return acc


def save_model(model, path):
    """Save model weights for TPU."""
    weights = model.fc.weight.detach().numpy()
    bias = model.fc.bias.detach().numpy()

    # Quantize to uint8: map weights to [0, 255] with 128 = 0
    w_max = max(abs(weights.min()), abs(weights.max()))
    scale = 127.0 / (w_max + 1e-8)
    weights_q = np.clip(np.round(weights * scale + 128), 0, 255).astype(np.uint8)

    data = {
        'weights': weights_q.tolist(),
        'weights_float': weights.tolist(),
        'bias': bias.tolist(),
        'scale': float(scale),
        'zero_point': 128,
        'description': 'Gesture classifier for tiny²TPU'
    }

    with open(path, 'w') as f:
        json.dump(data, f, indent=2)

    print(f"\nSaved to {path}")
    print(f"  Float weights:\n{weights}")
    print(f"  Quantized:\n{weights_q}")


def main():
    parser = argparse.ArgumentParser(description='Train gesture classifier')
    parser.add_argument('--epochs', type=int, default=200)
    parser.add_argument('--output', type=str, default='gesture_model.json')
    args = parser.parse_args()

    print("=" * 50)
    print("tiny²TPU Gesture Classifier Training")
    print("=" * 50)

    model, acc = train_model(epochs=args.epochs)

    if acc < 0.9:
        print("\nWARNING: Accuracy below 90%, check training")

    evaluate(model)

    output_path = os.path.join(model_dir, args.output)
    save_model(model, output_path)

    print("\n" + "=" * 50)
    print("Done! Run demo with:")
    print("  python3 ../host/gesture_demo.py --sim")


if __name__ == "__main__":
    main()
