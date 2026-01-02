#!/usr/bin/env python3
"""
tiny²TPU Gesture Demo - Mouse-based direction classifier

Loads trained model from ../model/gesture_model.json and runs inference
on the TPU hardware (or simulation).

Usage:
    python3 gesture_demo.py --sim                    # Simulation mode
    python3 gesture_demo.py /dev/tty.usbserial-XXX   # Real TPU

Requirements:
    pip install pygame pyserial
"""

import sys
import os
import time
import math
import json

# Add script directory to path
script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir not in sys.path:
    sys.path.insert(0, script_dir)

# Model directory
model_dir = os.path.join(os.path.dirname(script_dir), 'model')

# Check for pygame
try:
    import pygame
    PYGAME_AVAILABLE = True
except ImportError:
    PYGAME_AVAILABLE = False
    print("pygame not installed. Install with: pip install pygame")

# TPU Driver
try:
    from tpu_driver import TPUDriver
except ImportError:
    print(f"Warning: tpu_driver.py not found in {script_dir}")
    TPUDriver = None


# ============================================================================
# Model Loading
# ============================================================================

def load_model(path):
    """Load trained model from JSON."""
    with open(path, 'r') as f:
        return json.load(f)


def find_model():
    """Find gesture_model.json."""
    candidates = [
        os.path.join(model_dir, 'gesture_model.json'),
        os.path.join(script_dir, 'gesture_model.json'),
        os.path.join(script_dir, '..', 'model', 'gesture_model.json'),
    ]
    for path in candidates:
        if os.path.exists(path):
            return path
    return None


# ============================================================================
# Gesture Classifier
# ============================================================================

class GestureClassifier:
    """Classifies gestures using trained model on TPU."""

    DIRECTIONS = {
        'right': ('RIGHT', '→', (0, 255, 100)),
        'left':  ('LEFT',  '←', (255, 100, 100)),
        'up':    ('UP',    '↑', (100, 200, 255)),
        'down':  ('DOWN',  '↓', (255, 200, 100)),
        'none':  ('',      '·', (100, 100, 100)),
    }

    def __init__(self, tpu=None, model_data=None, sim_mode=False):
        self.tpu = tpu
        self.sim_mode = sim_mode or (tpu is None)
        self.inference_count = 0
        self.last_inference_time = 0

        # Load model weights
        if model_data and 'weights' in model_data:
            self.weights = model_data['weights']
            self.weights_float = model_data.get('weights_float', None)
            self.has_model = True
            print(f"  Loaded trained weights: {self.weights}")
        else:
            # Fallback identity weights
            self.weights = [[255, 1], [1, 255]]
            self.weights_float = None
            self.has_model = False
            print("  Using default weights (no trained model)")

        # Pre-load weights to TPU
        if self.tpu and not self.sim_mode:
            try:
                self.tpu.write_weights(self.weights)
                print(f"  Weights loaded to TPU")
            except Exception as e:
                print(f"  Failed to load weights to TPU: {e}")

    def classify(self, dx: int, dy: int, threshold: int = 15) -> dict:
        """
        Classify motion vector into direction.

        Args:
            dx: Horizontal motion (can be negative)
            dy: Vertical motion (can be negative)
            threshold: Minimum motion magnitude

        Returns:
            dict with direction info
        """
        magnitude = math.sqrt(dx*dx + dy*dy)

        if magnitude < threshold:
            return {
                'direction': 'none',
                'name': '',
                'arrow': '·',
                'color': (100, 100, 100),
                'confidence': 0,
                'dx': dx,
                'dy': dy,
                'tpu_result': None,
            }

        start_time = time.time()

        # Normalize input to [0, 255] for TPU
        # Map motion to 0-255 range where 128 = no motion
        max_motion = 100
        dx_norm = int(128 + (dx / max_motion) * 127)
        dy_norm = int(128 + (dy / max_motion) * 127)
        dx_u8 = max(0, min(255, dx_norm))
        dy_u8 = max(0, min(255, dy_norm))

        # Format as 2x2 activation matrix
        activations = [[dx_u8, dy_u8],
                       [dx_u8, dy_u8]]

        tpu_result = None

        if self.sim_mode:
            # Simulate matrix multiply using trained weights
            if self.weights_float:
                import numpy as np
                W = np.array(self.weights_float)
                A = np.array([[dx_u8, dy_u8], [dx_u8, dy_u8]])
                C = A @ W.T  # Note: weights are [out, in] so transpose
                horiz_score = float(C[0, 0] + C[1, 0])
                vert_score = float(C[0, 1] + C[1, 1])
            else:
                # Use quantized weights
                W = self.weights
                horiz_score = dx_u8 * W[0][0] + dy_u8 * W[0][1]
                vert_score = dx_u8 * W[1][0] + dy_u8 * W[1][1]
                horiz_score *= 2  # Broadcast doubling
                vert_score *= 2
        else:
            # Real TPU inference
            try:
                self.tpu.write_activations(activations)
                self.tpu.execute()

                if not self.tpu.wait_for_done(timeout=1.0):
                    print("TPU timeout!")
                    horiz_score = abs(dx)
                    vert_score = abs(dy)
                else:
                    result = self.tpu.read_result()
                    tpu_result = result

                    # Decode: acc0 in lower 16 bits, acc1 in upper
                    horiz_score = result & 0xFFFF
                    vert_score = (result >> 16) & 0xFFFF

            except Exception as e:
                print(f"TPU error: {e}")
                horiz_score = abs(dx)
                vert_score = abs(dy)

        self.last_inference_time = time.time() - start_time
        self.inference_count += 1

        # Determine direction from TPU scores
        # The trained model outputs: horiz_score high if horizontal, vert_score high if vertical
        if horiz_score > vert_score:
            direction = 'right' if dx > 0 else 'left'
            confidence = horiz_score / (horiz_score + vert_score + 1)
        else:
            direction = 'up' if dy > 0 else 'down'
            confidence = vert_score / (horiz_score + vert_score + 1)

        info = self.DIRECTIONS[direction]
        return {
            'direction': direction,
            'name': info[0],
            'arrow': info[1],
            'color': info[2],
            'confidence': confidence,
            'dx': dx,
            'dy': dy,
            'tpu_result': tpu_result,
            'scores': (horiz_score, vert_score),
        }


# ============================================================================
# Pygame Demo
# ============================================================================

class GestureDemo:
    """Pygame visual demo."""

    def __init__(self, classifier, width=600, height=500):
        self.classifier = classifier
        self.width = width
        self.height = height
        self.screen = None
        self.font_large = None
        self.font_medium = None
        self.font_small = None
        self.last_pos = None
        self.motion_buffer = []
        self.current_result = None
        self.trail = []
        self.arrow_scale = 1.0
        self.clock = None

    def init(self):
        pygame.init()
        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("tiny²TPU Gesture Demo")
        self.font_large = pygame.font.Font(None, 200)
        self.font_medium = pygame.font.Font(None, 48)
        self.font_small = pygame.font.Font(None, 28)
        self.clock = pygame.time.Clock()

    def run(self):
        self.init()
        running = True

        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key in (pygame.K_ESCAPE, pygame.K_q):
                        running = False
                    elif event.key == pygame.K_r:
                        self.classifier.inference_count = 0
                elif event.type == pygame.MOUSEMOTION:
                    self.handle_motion(event.pos)

            self.update()
            self.draw()
            self.clock.tick(60)

        pygame.quit()

    def handle_motion(self, pos):
        x, y = pos
        self.trail.append((x, y, time.time()))
        self.trail = self.trail[-20:]

        if self.last_pos is not None:
            dx = x - self.last_pos[0]
            dy = -(y - self.last_pos[1])  # Invert Y

            self.motion_buffer.append((dx, dy))
            self.motion_buffer = self.motion_buffer[-5:]

            if len(self.motion_buffer) >= 2:
                avg_dx = sum(m[0] for m in self.motion_buffer) / len(self.motion_buffer)
                avg_dy = sum(m[1] for m in self.motion_buffer) / len(self.motion_buffer)
                scaled_dx = int(avg_dx * 3)
                scaled_dy = int(avg_dy * 3)

                self.current_result = self.classifier.classify(scaled_dx, scaled_dy)

                if self.current_result['direction'] != 'none':
                    self.arrow_scale = 1.2

        self.last_pos = (x, y)

    def update(self):
        self.arrow_scale += (1.0 - self.arrow_scale) * 0.2
        now = time.time()
        self.trail = [(x, y, t) for x, y, t in self.trail if now - t < 0.5]

    def draw(self):
        self.screen.fill((25, 25, 35))

        # Trail
        if len(self.trail) > 1:
            for i in range(1, len(self.trail)):
                x1, y1, t1 = self.trail[i-1]
                x2, y2, t2 = self.trail[i]
                age = time.time() - t2
                alpha = max(0, 1 - age * 2)
                color = (int(100*alpha), int(150*alpha), int(200*alpha))
                pygame.draw.line(self.screen, color, (x1, y1), (x2, y2), 2)

        center_x, center_y = self.width // 2, self.height // 2 - 30

        # Arrow
        if self.current_result and self.current_result['direction'] != 'none':
            arrow = self.current_result['arrow']
            color = self.current_result['color']

            text = self.font_large.render(arrow, True, color)
            w = int(text.get_width() * self.arrow_scale)
            h = int(text.get_height() * self.arrow_scale)
            scaled = pygame.transform.scale(text, (w, h))
            rect = scaled.get_rect(center=(center_x, center_y))
            self.screen.blit(scaled, rect)

            name = self.font_medium.render(self.current_result['name'], True, color)
            self.screen.blit(name, name.get_rect(center=(center_x, center_y + 100)))
        else:
            text = self.font_medium.render("Move mouse to detect gesture", True, (100, 100, 120))
            self.screen.blit(text, text.get_rect(center=(center_x, center_y)))

        # Stats panel
        panel_y = self.height - 80
        pygame.draw.rect(self.screen, (35, 35, 45), (0, panel_y, self.width, 80))

        stats = [
            f"Inferences: {self.classifier.inference_count}",
            f"Latency: {self.classifier.last_inference_time*1000:.1f}ms",
        ]
        if self.current_result and self.current_result.get('scores'):
            h, v = self.current_result['scores']
            stats.append(f"H:{h:.0f} V:{v:.0f}")

        x = 20
        for stat in stats:
            text = self.font_small.render(stat, True, (150, 150, 170))
            self.screen.blit(text, (x, panel_y + 30))
            x += text.get_width() + 40

        # Title
        title = self.font_medium.render("tiny²TPU", True, (200, 200, 220))
        self.screen.blit(title, (20, 15))

        # Mode
        mode = "SIMULATION" if self.classifier.sim_mode else "HARDWARE"
        mode_color = (255, 180, 80) if self.classifier.sim_mode else (80, 255, 120)
        mode_text = self.font_small.render(mode, True, mode_color)
        self.screen.blit(mode_text, (self.width - mode_text.get_width() - 20, 20))

        # Model status
        model_status = "MODEL LOADED" if self.classifier.has_model else "NO MODEL"
        model_color = (80, 200, 255) if self.classifier.has_model else (255, 100, 100)
        model_text = self.font_small.render(model_status, True, model_color)
        self.screen.blit(model_text, (self.width - model_text.get_width() - 20, 45))

        pygame.display.flip()


# ============================================================================
# Main
# ============================================================================

def find_serial_port():
    import glob
    patterns = ['/dev/tty.usbserial-*', '/dev/ttyUSB*', '/dev/ttyACM*']
    for pattern in patterns:
        ports = glob.glob(pattern)
        if ports:
            return ports[0]
    return None


def main():
    print("tiny²TPU Gesture Demo")
    print("=" * 50)

    sim_mode = False
    port = None

    for arg in sys.argv[1:]:
        if arg in ('--sim', '-s'):
            sim_mode = True
        elif arg in ('--help', '-h'):
            print(__doc__)
            sys.exit(0)
        elif arg.startswith('/dev') or arg.startswith('COM'):
            port = arg

    # Load trained model
    model_path = find_model()
    model_data = None

    if model_path:
        print(f"Loading model from {model_path}")
        try:
            model_data = load_model(model_path)
        except Exception as e:
            print(f"  Failed to load model: {e}")
    else:
        print("No trained model found!")
        print("  Train one with: cd model && python3 train.py")

    # Setup TPU
    tpu = None
    if not sim_mode:
        if port is None:
            port = find_serial_port()
            if port:
                print(f"Auto-detected port: {port}")

        if port and TPUDriver:
            try:
                print(f"Connecting to TPU on {port}...")
                tpu = TPUDriver(port)
                tpu.open()
                state, cycle = tpu.read_status()
                print(f"TPU connected! State: {state}, Cycle: {cycle}")
            except Exception as e:
                print(f"Connection failed: {e}")
                tpu = None

    if sim_mode or tpu is None:
        print("\nRunning in SIMULATION mode")

    # Create classifier with trained model
    classifier = GestureClassifier(
        tpu=tpu,
        model_data=model_data,
        sim_mode=(tpu is None)
    )

    # Run demo
    if PYGAME_AVAILABLE:
        print("\nStarting demo - move mouse to classify gestures!")
        demo = GestureDemo(classifier)
        demo.run()
    else:
        print("pygame not available")

    if tpu:
        tpu.close()

    print(f"\nTotal inferences: {classifier.inference_count}")


if __name__ == "__main__":
    main()
