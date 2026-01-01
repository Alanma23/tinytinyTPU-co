"""
TPU Driver - Serial Communication Interface
Provides Python interface to TinyTinyTPU v1 via UART

Commands:
- 0x01: WRITE_WEIGHT - Load 2x2 weight matrix
- 0x02: WRITE_ACT    - Load 2x2 activation matrix
- 0x03: EXECUTE      - Start computation
- 0x04: READ_RESULT  - Read 32-bit result (acc0)
- 0x05: STATUS       - Read MLP state and cycle count
"""

import serial
import struct
import time
from typing import List, Tuple, Optional
from enum import IntEnum


class TPUCommand(IntEnum):
    """TPU UART command codes (legacy - backward compatibility)"""
    WRITE_WEIGHT = 0x01
    WRITE_ACT = 0x02
    EXECUTE = 0x03
    READ_RESULT = 0x04
    STATUS = 0x05


class TPUInstruction(IntEnum):
    """TPU 20-Instruction ISA opcodes"""
    # Memory Operations
    NOP = 0x00
    RD_HOST_MEM = 0x01
    WR_HOST_MEM = 0x02
    RD_WEIGHT = 0x03
    LD_UB = 0x04
    ST_UB = 0x05
    # Matrix Operations
    MATMUL = 0x10
    CONV2D = 0x11
    MATMUL_ACC = 0x12
    # Activation Operations
    RELU = 0x18
    RELU6 = 0x19
    SIGMOID = 0x1A
    TANH = 0x1B
    # Pooling Operations
    MAXPOOL = 0x20
    AVGPOOL = 0x21
    # Normalization Operations
    ADD_BIAS = 0x22
    BATCH_NORM = 0x23
    # Control Operations
    SYNC = 0x30
    CFG_REG = 0x31
    HALT = 0x3F


class TPUDriver:
    """Driver for TinyTinyTPU v1 hardware via UART"""

    def __init__(self, port: str, baud_rate: int = 115200, timeout: float = 1.0):
        """
        Initialize TPU driver

        Args:
            port: Serial port name (e.g., '/dev/ttyUSB0', 'COM3')
            baud_rate: UART baud rate (default: 115200)
            timeout: Serial timeout in seconds (default: 1.0)
        """
        self.port = port
        self.baud_rate = baud_rate
        self.timeout = timeout
        self.serial = None

    def open(self):
        """Open serial connection to TPU"""
        try:
            self.serial = serial.Serial(
                port=self.port,
                baudrate=self.baud_rate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=self.timeout
            )
            # Wait for hardware to stabilize
            time.sleep(0.1)
            # Flush any stale data
            self.serial.reset_input_buffer()
            self.serial.reset_output_buffer()
        except serial.SerialException as e:
            raise RuntimeError(f"Failed to open serial port {self.port}: {e}")

    def close(self):
        """Close serial connection"""
        if self.serial and self.serial.is_open:
            self.serial.close()

    def __enter__(self):
        """Context manager entry"""
        self.open()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        """Context manager exit"""
        self.close()

    def _send_command(self, cmd: int, data: Optional[List[int]] = None):
        """
        Send command to TPU

        Args:
            cmd: Command byte
            data: Optional data bytes to send after command
        """
        if not self.serial or not self.serial.is_open:
            raise RuntimeError("Serial port not open")

        # Send command byte
        self.serial.write(bytes([cmd]))

        # Send data bytes if provided
        if data:
            for byte in data:
                self.serial.write(bytes([byte & 0xFF]))

        # Small delay for UART transmission
        time.sleep(0.01)

    def _receive_bytes(self, num_bytes: int, timeout: float = None) -> bytes:
        """
        Receive bytes from TPU

        Args:
            num_bytes: Number of bytes to receive
            timeout: Optional timeout override (default: uses serial timeout)

        Returns:
            Received bytes
        """
        if not self.serial or not self.serial.is_open:
            raise RuntimeError("Serial port not open")

        # Use provided timeout or default
        old_timeout = self.serial.timeout
        if timeout is not None:
            self.serial.timeout = timeout

        try:
            data = self.serial.read(num_bytes)
            if len(data) != num_bytes:
                raise RuntimeError(f"Expected {num_bytes} bytes, received {len(data)} (timeout: {self.serial.timeout}s)")
        finally:
            if timeout is not None:
                self.serial.timeout = old_timeout

        return data

    def write_weights(self, weights: List[List[int]]):
        """
        Load 2x2 weight matrix to TPU

        Args:
            weights: 2x2 matrix as [[W00, W01], [W10, W11]]

        Example:
            tpu.write_weights([[1, 0], [0, 1]])  # Identity matrix
        """
        if len(weights) != 2 or len(weights[0]) != 2 or len(weights[1]) != 2:
            raise ValueError("Weights must be 2x2 matrix")

        # Flatten to [W00, W01, W10, W11]
        weight_bytes = [
            weights[0][0] & 0xFF,  # W00
            weights[0][1] & 0xFF,  # W01
            weights[1][0] & 0xFF,  # W10
            weights[1][1] & 0xFF   # W11
        ]

        self._send_command(TPUCommand.WRITE_WEIGHT, weight_bytes)

    def write_activations(self, activations: List[List[int]]):
        """
        Load 2x2 activation matrix to TPU

        Args:
            activations: 2x2 matrix as [[A00, A01], [A10, A11]]

        Example:
            tpu.write_activations([[10, 20], [30, 40]])
        """
        if len(activations) != 2 or len(activations[0]) != 2 or len(activations[1]) != 2:
            raise ValueError("Activations must be 2x2 matrix")

        # Flatten to [A00, A01, A10, A11]
        act_bytes = [
            activations[0][0] & 0xFF,  # A00
            activations[0][1] & 0xFF,  # A01
            activations[1][0] & 0xFF,  # A10
            activations[1][1] & 0xFF   # A11
        ]

        self._send_command(TPUCommand.WRITE_ACT, act_bytes)

    def execute(self):
        """Start TPU computation"""
        self._send_command(TPUCommand.EXECUTE)

    def read_result(self, timeout: float = 0.5) -> int:
        """
        Read 32-bit computation result

        Args:
            timeout: Timeout in seconds (default: 0.5s)

        Returns:
            32-bit signed result (acc0)
        """
        self._send_command(TPUCommand.READ_RESULT)
        
        # Small delay to allow FPGA to process
        time.sleep(0.01)

        # Receive 4 bytes: [7:0], [15:8], [23:16], [31:24]
        data = self._receive_bytes(4, timeout=timeout)

        # Unpack as little-endian signed 32-bit integer
        result = struct.unpack('<i', data)[0]

        return result

    def read_status(self, timeout: float = 0.5) -> Tuple[int, int]:
        """
        Read TPU status

        Args:
            timeout: Timeout in seconds (default: 0.5s)

        Returns:
            Tuple of (state, cycle_count)
            - state: MLP FSM state (4 bits, 0-8)
            - cycle_count: Current cycle count (4 bits, 0-15)
        """
        self._send_command(TPUCommand.STATUS)
        
        # Small delay to allow FPGA to process
        time.sleep(0.01)

        # Receive 1 byte: {state[3:0], cycle_cnt[3:0]}
        data = self._receive_bytes(1, timeout=timeout)
        status_byte = data[0]

        state = (status_byte >> 4) & 0x0F
        cycle_count = status_byte & 0x0F

        return (state, cycle_count)

    def wait_for_done(self, timeout: float = 5.0, poll_interval: float = 0.01) -> bool:
        """
        Poll status until computation is complete

        Args:
            timeout: Maximum time to wait in seconds
            poll_interval: Time between status checks (default 10ms for fast polling)

        Returns:
            True if done, False if timeout
        """
        # MLP FSM states (from mlp_top.sv)
        # IDLE=0, LOAD_WEIGHT=1, LOAD_ACT=2, COMPUTE=3, DRAIN=4,
        # TRANSFER=5, NEXT_LAYER=6, WAIT_WEIGHTS=7, DONE=8
        IDLE_STATE = 0
        DONE_STATE = 8

        start_time = time.time()

        while (time.time() - start_time) < timeout:
            state, _ = self.read_status()
            # Computation complete when we reach DONE (8) or return to IDLE (0)
            if state == DONE_STATE or state == IDLE_STATE:
                return True
            time.sleep(poll_interval)

        return False

    def inference(self, weights: List[List[int]], activations: List[List[int]],
                  timeout: float = 5.0) -> int:
        """
        Perform complete inference: load weights, load activations, execute, read result

        Args:
            weights: 2x2 weight matrix
            activations: 2x2 activation matrix
            timeout: Computation timeout in seconds

        Returns:
            32-bit computation result

        Example:
            result = tpu.inference([[1, 0], [0, 1]], [[10, 20], [30, 40]])
        """
        self.write_weights(weights)
        self.write_activations(activations)
        self.execute()

        if not self.wait_for_done(timeout):
            raise TimeoutError("TPU computation timeout")

        return self.read_result()
    
    # ========== New ISA Instruction Methods ==========
    
    def instruction_nop(self):
        """NOP - No operation"""
        self._send_command(TPUInstruction.NOP)
    
    def instruction_matmul(self, clear_acc: bool = True):
        """
        MATMUL - Matrix multiply
        
        Args:
            clear_acc: If True, clear accumulator before multiply (default: True)
        """
        if clear_acc:
            self._send_command(TPUInstruction.MATMUL)
        else:
            self._send_command(TPUInstruction.MATMUL_ACC)
    
    def instruction_matmul_acc(self):
        """MATMUL_ACC - Matrix multiply with accumulate"""
        self._send_command(TPUInstruction.MATMUL_ACC)
    
    def instruction_conv2d(self):
        """CONV2D - 2D convolution (stub - same as MATMUL for now)"""
        self._send_command(TPUInstruction.CONV2D)
    
    def instruction_relu(self):
        """RELU - ReLU activation (configures VPU)"""
        self._send_command(TPUInstruction.RELU)
    
    def instruction_relu6(self):
        """RELU6 - ReLU6 activation (configures VPU)"""
        self._send_command(TPUInstruction.RELU6)
    
    def instruction_sigmoid(self):
        """SIGMOID - Sigmoid activation (configures VPU)"""
        self._send_command(TPUInstruction.SIGMOID)
    
    def instruction_tanh(self):
        """TANH - Tanh activation (configures VPU)"""
        self._send_command(TPUInstruction.TANH)
    
    def instruction_maxpool(self):
        """MAXPOOL - Max pooling (stub)"""
        self._send_command(TPUInstruction.MAXPOOL)
    
    def instruction_avgpool(self):
        """AVGPOOL - Average pooling (stub)"""
        self._send_command(TPUInstruction.AVGPOOL)
    
    def instruction_add_bias(self):
        """ADD_BIAS - Add bias (uses normalizer)"""
        self._send_command(TPUInstruction.ADD_BIAS)
    
    def instruction_batch_norm(self):
        """BATCH_NORM - Batch normalization (uses normalizer)"""
        self._send_command(TPUInstruction.BATCH_NORM)
    
    def instruction_sync(self):
        """SYNC - Synchronization barrier (wait for MLP completion)"""
        self._send_command(TPUInstruction.SYNC)
        # Wait for completion
        while True:
            state, _ = self.read_status()
            if state == 0 or state == 8:  # IDLE or DONE
                break
            time.sleep(0.001)
    
    def instruction_cfg_reg(self, reg_addr: int, reg_value: int):
        """
        CFG_REG - Configure register
        
        Args:
            reg_addr: Register address (1 byte)
            reg_value: Register value (3 bytes)
        """
        # Pack: [opcode][reg_addr][reg_value_high][reg_value_mid][reg_value_low]
        data = [
            reg_addr & 0xFF,
            (reg_value >> 16) & 0xFF,
            (reg_value >> 8) & 0xFF,
            reg_value & 0xFF
        ]
        self._send_command(TPUInstruction.CFG_REG, data)
    
    def instruction_halt(self):
        """HALT - Halt execution"""
        self._send_command(TPUInstruction.HALT)
    
    def instruction_rd_weight(self, addr: int):
        """
        RD_WEIGHT - Read weight from memory (stub)
        
        Args:
            addr: Weight memory address
        """
        data = struct.pack('>I', addr & 0xFFFFFFFF)
        self._send_command(TPUInstruction.RD_WEIGHT, list(data))
    
    def instruction_ld_ub(self, count: int):
        """
        LD_UB - Load from unified buffer (stub)
        
        Args:
            count: Number of elements to load
        """
        data = struct.pack('>I', count & 0xFFFFFFFF)
        self._send_command(TPUInstruction.LD_UB, list(data))
    
    def instruction_st_ub(self, count: int):
        """
        ST_UB - Store to unified buffer (stub)
        
        Args:
            count: Number of elements to store
        """
        data = struct.pack('>I', count & 0xFFFFFFFF)
        self._send_command(TPUInstruction.ST_UB, list(data))
    
    def configure_vpu_activation(self, activation_type: int):
        """
        Configure VPU activation function via CFG_REG
        
        Args:
            activation_type: 0=passthrough, 1=ReLU, 2=ReLU6, 3=Sigmoid, 4=Tanh
        """
        self.instruction_cfg_reg(0x00, activation_type & 0x07)


if __name__ == "__main__":
    # Example usage
    print("TPU Driver Example")
    print("==================")
    print()
    print("Usage:")
    print("  from tpu_driver import TPUDriver")
    print()
    print("  with TPUDriver('/dev/ttyUSB0') as tpu:")
    print("      # Identity matrix multiply")
    print("      result = tpu.inference([[1, 0], [0, 1]], [[10, 20], [10, 20]])")
    print("      print(f'Result: {result}')")
