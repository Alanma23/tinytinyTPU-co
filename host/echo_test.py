#!/usr/bin/env python3
"""
Simple UART echo test - Send bytes and watch LEDs change on FPGA

Usage:
    python3 echo_test.py /dev/tty.usbserial-210183A27BE01
"""

import sys
import time
import serial

def echo_test(port: str):
    """Send bytes via UART and display what should appear on LEDs."""
    
    print("UART Echo Test")
    print("=" * 60)
    print(f"Port: {port}\n")
    print("Instructions:")
    print("  1. Set SW[15:14] = 10 (SW15=1, SW14=0)")
    print("  2. Set SW[13] = 1 (SW13=1) to enable echo mode")
    print("  3. LEDs[7:0] will show the last received byte")
    print("  4. LED[8] will flash when a byte is received")
    print("\nPress Enter to start...")
    input()
    
    try:
        ser = serial.Serial(port, 115200, timeout=1.0)
        print(f"✓ Connected to {port}\n")
        
        # Test bytes to send
        test_bytes = [
            (0x00, "0x00 - All LEDs off"),
            (0x01, "0x01 - LED[0] on"),
            (0x03, "0x03 - LEDs[1:0] on"),
            (0x0F, "0x0F - LEDs[3:0] on"),
            (0xFF, "0xFF - All LEDs[7:0] on"),
            (0xAA, "0xAA - Alternating pattern"),
            (0x55, "0x55 - Alternating pattern (inverted)"),
            (0x80, "0x80 - LED[7] on"),
            (0xC0, "0xC0 - LEDs[7:6] on"),
        ]
        
        print("Sending test bytes...")
        print("-" * 60)
        
        for byte_val, description in test_bytes:
            print(f"Sending {description}")
            ser.write(bytes([byte_val]))
            time.sleep(0.2)  # Wait for byte to be received
            
            # Check if we got an echo back (if implemented)
            if ser.in_waiting > 0:
                echo = ser.read(1)
                print(f"  → Echo received: 0x{echo[0]:02X}")
            else:
                print(f"  → Check LEDs[7:0] - should show 0x{byte_val:02X}")
                print(f"  → LED[8] should flash briefly")
            
            time.sleep(0.5)  # Pause between bytes
        
        print("\n" + "-" * 60)
        print("Interactive mode - Enter byte values (0-255) or 'q' to quit")
        print("Example: 42, 0xFF, 0xAA")
        
        while True:
            try:
                user_input = input("\nByte value: ").strip()
                if user_input.lower() == 'q':
                    break
                
                # Parse input (hex or decimal)
                if user_input.startswith('0x') or user_input.startswith('0X'):
                    byte_val = int(user_input, 16)
                else:
                    byte_val = int(user_input)
                
                if byte_val < 0 or byte_val > 255:
                    print("  ✗ Invalid: must be 0-255")
                    continue
                
                print(f"  → Sending 0x{byte_val:02X} ({byte_val})")
                ser.write(bytes([byte_val]))
                time.sleep(0.2)
                
                if ser.in_waiting > 0:
                    echo = ser.read(1)
                    print(f"  → Echo: 0x{echo[0]:02X}")
                else:
                    print(f"  → Check LEDs[7:0] - should show 0x{byte_val:02X}")
                
            except ValueError:
                print("  ✗ Invalid input - enter a number (0-255) or 'q' to quit")
            except KeyboardInterrupt:
                break
        
        ser.close()
        print("\n✓ Test complete")
        
    except serial.SerialException as e:
        print(f"✗ Serial error: {e}")
        sys.exit(1)
    except KeyboardInterrupt:
        print("\n\nTest interrupted")
        sys.exit(0)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 echo_test.py <serial_port>")
        print("Example: python3 echo_test.py /dev/tty.usbserial-210183A27BE01")
        sys.exit(1)
    
    echo_test(sys.argv[1])

