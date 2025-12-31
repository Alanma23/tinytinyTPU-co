"""
Unit tests for TPU Driver

Tests serial communication protocol without requiring hardware.
Uses mocking to simulate serial port behavior.
"""

import unittest
from unittest.mock import Mock, MagicMock, patch, call
import struct
from tpu_driver import TPUDriver, TPUCommand


class TestTPUDriver(unittest.TestCase):
    """Test cases for TPU driver"""

    def setUp(self):
        """Set up test fixtures"""
        self.mock_serial_patcher = patch('tpu_driver.serial.Serial')
        self.mock_serial_class = self.mock_serial_patcher.start()
        self.mock_serial = MagicMock()
        self.mock_serial_class.return_value = self.mock_serial
        self.mock_serial.is_open = True

    def tearDown(self):
        """Clean up"""
        self.mock_serial_patcher.stop()

    def test_open_serial(self):
        """Test opening serial port"""
        driver = TPUDriver('/dev/ttyUSB0', baud_rate=115200, timeout=1.0)
        driver.open()

        # Verify serial port was opened with correct parameters
        self.mock_serial_class.assert_called_once()
        call_kwargs = self.mock_serial_class.call_args[1]
        self.assertEqual(call_kwargs['port'], '/dev/ttyUSB0')
        self.assertEqual(call_kwargs['baudrate'], 115200)
        self.assertEqual(call_kwargs['timeout'], 1.0)

    def test_close_serial(self):
        """Test closing serial port"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()
        driver.close()

        self.mock_serial.close.assert_called_once()

    def test_context_manager(self):
        """Test using driver as context manager"""
        with TPUDriver('/dev/ttyUSB0') as driver:
            self.assertIsNotNone(driver.serial)

        self.mock_serial.close.assert_called_once()

    def test_write_weights(self):
        """Test writing weight matrix"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        weights = [[1, 2], [3, 4]]
        driver.write_weights(weights)

        # Verify command and data bytes were sent
        expected_calls = [
            call(bytes([TPUCommand.WRITE_WEIGHT])),
            call(bytes([1])),  # W00
            call(bytes([2])),  # W01
            call(bytes([3])),  # W10
            call(bytes([4]))   # W11
        ]
        self.mock_serial.write.assert_has_calls(expected_calls)

    def test_write_weights_invalid_size(self):
        """Test writing invalid weight matrix raises error"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        with self.assertRaises(ValueError):
            driver.write_weights([[1, 2, 3], [4, 5, 6]])  # 2x3 instead of 2x2

    def test_write_activations(self):
        """Test writing activation matrix"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        activations = [[10, 20], [30, 40]]
        driver.write_activations(activations)

        # Verify command and data bytes were sent
        expected_calls = [
            call(bytes([TPUCommand.WRITE_ACT])),
            call(bytes([10])),  # A00
            call(bytes([20])),  # A01
            call(bytes([30])),  # A10
            call(bytes([40]))   # A11
        ]
        self.mock_serial.write.assert_has_calls(expected_calls)

    def test_execute(self):
        """Test execute command"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        driver.execute()

        self.mock_serial.write.assert_called_with(bytes([TPUCommand.EXECUTE]))

    def test_read_result(self):
        """Test reading 32-bit result"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock receiving result bytes (little-endian: 0x12345678)
        result_bytes = struct.pack('<i', 0x12345678)
        self.mock_serial.read.return_value = result_bytes

        result = driver.read_result()

        # Verify command was sent
        self.mock_serial.write.assert_called_with(bytes([TPUCommand.READ_RESULT]))

        # Verify 4 bytes were requested
        self.mock_serial.read.assert_called_with(4)

        # Verify result was unpacked correctly
        self.assertEqual(result, 0x12345678)

    def test_read_result_negative(self):
        """Test reading negative (signed) result"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock receiving negative result
        result_bytes = struct.pack('<i', -100)
        self.mock_serial.read.return_value = result_bytes

        result = driver.read_result()
        self.assertEqual(result, -100)

    def test_read_status(self):
        """Test reading status"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock status byte: state=3 (COMPUTE), cycle_count=5
        # Packed as: {state[2:0], cycle[4:0]} = 0b011_00101 = 0x65
        status_byte = (3 << 5) | 5
        self.mock_serial.read.return_value = bytes([status_byte])

        state, cycle_count = driver.read_status()

        # Verify command was sent
        self.mock_serial.write.assert_called_with(bytes([TPUCommand.STATUS]))

        # Verify 1 byte was requested
        self.mock_serial.read.assert_called_with(1)

        # Verify status was unpacked correctly
        self.assertEqual(state, 3)
        self.assertEqual(cycle_count, 5)

    def test_wait_for_done_success(self):
        """Test waiting for completion successfully"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock status progression: COMPUTE -> DRAIN -> DONE (appears as IDLE=0)
        # Note: DONE state (8) appears as 0 because only state[2:0] is transmitted
        status_sequence = [
            bytes([(3 << 5) | 0]),  # COMPUTE (state=3), cycle=0
            bytes([(4 << 5) | 0]),  # DRAIN (state=4), cycle=0
            bytes([(0 << 5) | 0])   # DONE (state=8, transmitted as 0), cycle=0
        ]
        self.mock_serial.read.side_effect = status_sequence

        result = driver.wait_for_done(timeout=5.0, poll_interval=0.01)

        self.assertTrue(result)

    def test_wait_for_done_timeout(self):
        """Test waiting for completion times out"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock status always in COMPUTE state
        self.mock_serial.read.return_value = bytes([(3 << 5) | 0])

        result = driver.wait_for_done(timeout=0.1, poll_interval=0.05)

        self.assertFalse(result)

    def test_inference_complete(self):
        """Test complete inference flow"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock status progression and result
        # Status sequence: non-IDLE (to detect start) then IDLE (DONE appears as 0)
        self.mock_serial.read.side_effect = [
            bytes([(3 << 5) | 0]),   # COMPUTE state (computation started)
            bytes([(0 << 5) | 0]),   # DONE (appears as IDLE=0)
            struct.pack('<i', 42)     # Result = 42
        ]

        weights = [[1, 0], [0, 1]]
        activations = [[10, 20], [10, 20]]

        result = driver.inference(weights, activations, timeout=1.0)

        # Verify result
        self.assertEqual(result, 42)

        # Verify all commands were sent in order
        write_calls = self.mock_serial.write.call_args_list
        self.assertEqual(write_calls[0][0][0], bytes([TPUCommand.WRITE_WEIGHT]))
        # WRITE_ACT starts at index 5 (after WRITE_WEIGHT + 4 data bytes)
        self.assertEqual(write_calls[5][0][0], bytes([TPUCommand.WRITE_ACT]))
        # EXECUTE is after WRITE_ACT + 4 data bytes
        self.assertEqual(write_calls[10][0][0], bytes([TPUCommand.EXECUTE]))

    def test_receive_bytes_timeout(self):
        """Test timeout when receiving bytes"""
        driver = TPUDriver('/dev/ttyUSB0')
        driver.open()

        # Mock incomplete read (timeout)
        self.mock_serial.read.return_value = bytes([0x00])  # Only 1 byte instead of 4

        with self.assertRaises(RuntimeError):
            driver.read_result()

    def test_command_without_open_port(self):
        """Test sending command without opening port raises error"""
        driver = TPUDriver('/dev/ttyUSB0')
        # Don't call open()

        with self.assertRaises(RuntimeError):
            driver.write_weights([[1, 0], [0, 1]])


if __name__ == '__main__':
    unittest.main()
