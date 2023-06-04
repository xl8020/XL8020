def calculate_crc(data):
    crc_register = 0xFFFF

    for byte in data:
        crc_register ^= byte

        for _ in range(8):
            if crc_register & 0x0001:
                crc_register = (crc_register >> 1) ^ 0xA001
            else:
                crc_register >>= 1

    return crc_register & 0xFFFF

# Example usage

#Example 1
data = [0x01, 0x03, 0x00, 0x02, 0x00, 0x02]

#Example 2
#data = [0x01, 0x06, 0x00, 0x00, 0x09, 0x60]

#Example 3
#data = [0x01, 0x10, 0x00, 0x00, 0x00, 0x02, 0x04, 0x09, 0x60, 0x05, 0xDC]

crc = calculate_crc(data)
crc_swapped = ((crc & 0xFF) << 8) | ((crc >> 8) & 0xFF)

print(f"CRC: {crc_swapped:04X}")

