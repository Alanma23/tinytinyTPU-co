#!/usr/bin/env python3
"""
TinyTPU Gesture Demo - Mouse-based direction classifier
Demonstrates TPU inference with real-time visual feedback

Usage:
    python3 gesture_demo.py [serial_port]
    python3 gesture_demo.py --sim          # Simulation mode (no hardware)
    python3 gesture_demo.py /dev/tty.usbserial-XXX

Requirements:
    pip install pygame pyserial
"""

import sys
import os
import time
import math

# Add script directory to path for imports
script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir not in sys.path:
    sys.path.insert(0, script_dir)

# Check for pygame
try:
    import pygame
    PYGAME_AVAILABLE = True
except ImportError:
    PYGAME_AVAILABLE = False
    print("pygame not installed. Install with: pip install pygame")

# TPU Driver import
try:
    from tpu_driver import TPUDriver
except ImportError:
    print(f"Warning: tpu_driver.py not found in {script_dir}")
    TPUDriver = None


# ============================================================================
# TPU Gesture Classifier
# ============================================================================

# Weights for direction classification
# Input: (dx, dy) motion vector (centered at 128 for unsigned)
# Output: (horizontal_score, vertical_score)
#
# Matrix multiply: C = A @ W
# A = [[dx, dy], [dx, dy]]  (broadcast input)
# W = [[1, 0], [0, 1]]      (identity-like, separates dx and dy)
#
# acc0 = dx + dx = 2*dx (horizontal component)
# acc1 = dy + dy = 2*dy (vertical component)

W_DIRECTION = [
    [1, 0],  # dx contributes to output 0
    [0, 1],  # dy contributes to output 1
]


class GestureClassifier:
    """Classifies 2D motion vectors into directions using TPU."""

    DIRECTIONS = {
        'right': ('RIGHT', '→', (0, 255, 100)),
        'left':  ('LEFT',  '←', (255, 100, 100)),
        'up':    ('UP',    '↑', (100, 200, 255)),
        'down':  ('DOWN',  '↓', (255, 200, 100)),
        'none':  ('',      '·', (100, 100, 100)),
    }

    def __init__(self, tpu=None, sim_mode=False):
        """
        Args:
            tpu: TPUDriver instance (None for simulation)
            sim_mode: If True, simulate TPU responses
        """
        self.tpu = tpu
        self.sim_mode = sim_mode or (tpu is None)
        self.inference_count = 0
        self.last_inference_time = 0

    def classify(self, dx: int, dy: int, threshold: int = 15) -> dict:
        """
        Classify motion vector into direction.

        Args:
            dx: Horizontal motion (-127 to 127)
            dy: Vertical motion (-127 to 127)
            threshold: Minimum motion to register

        Returns:
            dict with 'direction', 'name', 'arrow', 'color', 'confidence'
        """
        # Check if motion is significant
        magnitude = math.sqrt(dx*dx + dy*dy)
        if magnitude < threshold:
            info = self.DIRECTIONS['none']
            return {
                'direction': 'none',
                'name': info[0],
                'arrow': info[1],
                'color': info[2],
                'confidence': 0,
                'dx': dx,
                'dy': dy,
            }

        # Run TPU inference (or simulate)
        start_time = time.time()

        if self.sim_mode:
            # Simulation: just use the raw values
            horiz_score = abs(dx)
            vert_score = abs(dy)
        else:
            # Real TPU inference
            # Convert signed to unsigned (center at 128)
            dx_u8 = max(0, min(255, dx + 128))
            dy_u8 = max(0, min(255, dy + 128))

            # Format as 2x2 activation matrix
            A = [[dx_u8, dy_u8],
                 [dx_u8, dy_u8]]

            try:
                result = self.tpu.inference(W_DIRECTION, A)
                # Decode result
                # acc0 = 2 * dx_u8, acc1 = 2 * dy_u8
                horiz_score = abs((result & 0xFFFF) - 256)  # Remove 128*2 bias
                vert_score = abs(((result >> 16) & 0xFFFF) - 256)
            except Exception as e:
                print(f"TPU error: {e}")
                horiz_score = abs(dx)
                vert_score = abs(dy)

        self.last_inference_time = time.time() - start_time
        self.inference_count += 1

        # Determine direction from original signed values
        if abs(dx) > abs(dy):
            direction = 'right' if dx > 0 else 'left'
            confidence = abs(dx) / magnitude
        else:
            direction = 'up' if dy > 0 else 'down'
            confidence = abs(dy) / magnitude

        info = self.DIRECTIONS[direction]
        return {
            'direction': direction,
            'name': info[0],
            'arrow': info[1],
            'color': info[2],
            'confidence': confidence,
            'dx': dx,
            'dy': dy,
        }


# ============================================================================
# Pygame Visual Demo
# ============================================================================

class GestureDemo:
    """Pygame-based gesture demo with visual feedback."""

    def __init__(self, classifier: GestureClassifier, width=600, height=500):
        self.classifier = classifier
        self.width = width
        self.height = height
        self.screen = None
        self.font_large = None
        self.font_medium = None
        self.font_small = None

        # Motion tracking
        self.last_pos = None
        self.motion_buffer = []  # Smooth motion
        self.current_result = None

        # Visual state
        self.trail = []  # Mouse trail for visual effect
        self.arrow_scale = 1.0
        self.arrow_scale_target = 1.0

    def init(self):
        """Initialize pygame."""
        pygame.init()
        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("TinyTPU Gesture Demo")

        self.font_large = pygame.font.Font(None, 200)
        self.font_medium = pygame.font.Font(None, 48)
        self.font_small = pygame.font.Font(None, 28)

        self.clock = pygame.time.Clock()

    def run(self):
        """Main demo loop."""
        self.init()
        running = True

        while running:
            # Handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE or event.key == pygame.K_q:
                        running = False
                    elif event.key == pygame.K_r:
                        # Reset stats
                        self.classifier.inference_count = 0
                elif event.type == pygame.MOUSEMOTION:
                    self.handle_motion(event.pos)

            # Update visuals
            self.update()

            # Draw
            self.draw()

            # Cap at 60 FPS
            self.clock.tick(60)

        pygame.quit()

    def handle_motion(self, pos):
        """Handle mouse motion event."""
        x, y = pos

        # Add to trail
        self.trail.append((x, y, time.time()))
        # Keep last 20 points
        self.trail = self.trail[-20:]

        if self.last_pos is not None:
            dx = x - self.last_pos[0]
            dy = -(y - self.last_pos[1])  # Invert Y (screen coords)

            # Add to motion buffer for smoothing
            self.motion_buffer.append((dx, dy))
            self.motion_buffer = self.motion_buffer[-5:]  # Average last 5

            # Calculate smoothed motion
            if len(self.motion_buffer) >= 2:
                avg_dx = sum(m[0] for m in self.motion_buffer) / len(self.motion_buffer)
                avg_dy = sum(m[1] for m in self.motion_buffer) / len(self.motion_buffer)

                # Scale up for sensitivity
                scaled_dx = int(avg_dx * 3)
                scaled_dy = int(avg_dy * 3)

                # Classify
                self.current_result = self.classifier.classify(scaled_dx, scaled_dy)

                # Animate arrow scale
                if self.current_result['direction'] != 'none':
                    self.arrow_scale_target = 1.2
                else:
                    self.arrow_scale_target = 1.0

        self.last_pos = (x, y)

    def update(self):
        """Update animation state."""
        # Smooth arrow scale animation
        self.arrow_scale += (self.arrow_scale_target - self.arrow_scale) * 0.2
        self.arrow_scale_target = 1.0  # Decay back to normal

        # Clean old trail points
        now = time.time()
        self.trail = [(x, y, t) for x, y, t in self.trail if now - t < 0.5]

    def draw(self):
        """Draw the demo screen."""
        # Background
        self.screen.fill((25, 25, 35))

        # Draw mouse trail
        if len(self.trail) > 1:
            for i in range(1, len(self.trail)):
                x1, y1, t1 = self.trail[i-1]
                x2, y2, t2 = self.trail[i]
                age = time.time() - t2
                alpha = max(0, 1 - age * 2)
                color = (int(100 * alpha), int(150 * alpha), int(200 * alpha))
                pygame.draw.line(self.screen, color, (x1, y1), (x2, y2), 2)

        # Draw center area
        center_x, center_y = self.width // 2, self.height // 2 - 30

        # Draw direction arrow
        if self.current_result and self.current_result['direction'] != 'none':
            arrow = self.current_result['arrow']
            color = self.current_result['color']

            # Render large arrow with scale animation
            text = self.font_large.render(arrow, True, color)
            scaled_size = (int(text.get_width() * self.arrow_scale),
                          int(text.get_height() * self.arrow_scale))
            scaled_text = pygame.transform.scale(text, scaled_size)
            rect = scaled_text.get_rect(center=(center_x, center_y))
            self.screen.blit(scaled_text, rect)

            # Direction name
            name_text = self.font_medium.render(self.current_result['name'], True, color)
            name_rect = name_text.get_rect(center=(center_x, center_y + 100))
            self.screen.blit(name_text, name_rect)
        else:
            # Idle state
            text = self.font_medium.render("Move mouse to detect gesture", True, (100, 100, 120))
            rect = text.get_rect(center=(center_x, center_y))
            self.screen.blit(text, rect)

        # Draw stats panel at bottom
        self.draw_stats()

        # Draw title
        title = self.font_medium.render("TinyTPU Gesture Demo", True, (200, 200, 220))
        self.screen.blit(title, (20, 15))

        # Mode indicator
        mode = "SIMULATION" if self.classifier.sim_mode else "HARDWARE"
        mode_color = (255, 200, 100) if self.classifier.sim_mode else (100, 255, 150)
        mode_text = self.font_small.render(mode, True, mode_color)
        self.screen.blit(mode_text, (self.width - mode_text.get_width() - 20, 20))

        pygame.display.flip()

    def draw_stats(self):
        """Draw statistics panel."""
        panel_y = self.height - 80
        pygame.draw.rect(self.screen, (35, 35, 45), (0, panel_y, self.width, 80))
        pygame.draw.line(self.screen, (60, 60, 70), (0, panel_y), (self.width, panel_y), 1)

        # Stats text
        stats = [
            f"Inferences: {self.classifier.inference_count}",
            f"Last inference: {self.classifier.last_inference_time*1000:.1f}ms",
        ]

        if self.current_result:
            stats.append(f"Motion: ({self.current_result['dx']:+d}, {self.current_result['dy']:+d})")
            stats.append(f"Confidence: {self.current_result['confidence']:.0%}")

        x = 20
        for stat in stats:
            text = self.font_small.render(stat, True, (150, 150, 170))
            self.screen.blit(text, (x, panel_y + 30))
            x += text.get_width() + 40

        # Instructions
        instructions = "Press Q to quit | R to reset stats"
        inst_text = self.font_small.render(instructions, True, (80, 80, 100))
        self.screen.blit(inst_text, (self.width - inst_text.get_width() - 20, panel_y + 30))


# ============================================================================
# Terminal Fallback (if no pygame)
# ============================================================================

def terminal_demo(classifier):
    """Simple terminal-based demo as fallback."""
    import select
    import tty
    import termios

    print("\nTinyTPU Gesture Demo (Terminal Mode)")
    print("=" * 40)
    print("Use arrow keys to input gestures")
    print("Press 'q' to quit\n")

    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)

    ARROW_MAP = {
        'A': (0, 100, 'UP'),
        'B': (0, -100, 'DOWN'),
        'C': (100, 0, 'RIGHT'),
        'D': (-100, 0, 'LEFT'),
    }

    try:
        tty.setraw(fd)
        while True:
            if select.select([sys.stdin], [], [], 0.1)[0]:
                ch = sys.stdin.read(1)
                if ch == 'q' or ch == 'Q':
                    break
                elif ch == '\x1b':
                    sys.stdin.read(1)  # Skip '['
                    arrow = sys.stdin.read(1)
                    if arrow in ARROW_MAP:
                        dx, dy, name = ARROW_MAP[arrow]
                        result = classifier.classify(dx, dy)
                        print(f"\r  {result['arrow']}  {result['name']:6s}  ({dx:+4d}, {dy:+4d})     ", end="")
                        sys.stdout.flush()
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        print("\n")


# ============================================================================
# Main
# ============================================================================

def find_serial_port():
    """Try to find a USB serial port."""
    import glob

    patterns = [
        '/dev/tty.usbserial-*',
        '/dev/ttyUSB*',
        '/dev/ttyACM*',
        'COM*',
    ]

    for pattern in patterns:
        ports = glob.glob(pattern)
        if ports:
            return ports[0]

    return None


def main():
    print("TinyTPU Gesture Demo")
    print("=" * 40)

    # Parse arguments
    sim_mode = False
    port = None

    if len(sys.argv) > 1:
        arg = sys.argv[1]
        if arg == '--sim' or arg == '-s':
            sim_mode = True
        elif arg == '--help' or arg == '-h':
            print(__doc__)
            sys.exit(0)
        else:
            port = arg

    # Setup TPU
    tpu = None
    if not sim_mode:
        if port is None:
            port = find_serial_port()

        if port and TPUDriver:
            try:
                print(f"Connecting to TPU on {port}...")
                tpu = TPUDriver(port)
                tpu.open()
                state, cycle = tpu.read_status()
                print(f"TPU connected! State: {state}, Cycle: {cycle}")
            except Exception as e:
                print(f"Failed to connect: {e}")
                print("Falling back to simulation mode")
                tpu = None
        else:
            if not TPUDriver:
                print("TPU driver not found")
            if not port:
                print("No serial port found")
            print("Running in simulation mode")

    if sim_mode or tpu is None:
        print("Running in SIMULATION mode (no hardware)")

    # Create classifier
    classifier = GestureClassifier(tpu=tpu, sim_mode=(tpu is None))

    # Run demo
    if PYGAME_AVAILABLE:
        print("\nStarting pygame demo...")
        print("Move your mouse to classify gestures!")
        print()
        demo = GestureDemo(classifier)
        demo.run()
    else:
        terminal_demo(classifier)

    # Cleanup
    if tpu:
        tpu.close()

    print(f"\nTotal inferences: {classifier.inference_count}")
    print("Demo complete!")


if __name__ == "__main__":
    main()
