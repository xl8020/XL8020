#include <stdio.h>
#include <stdint.h>

uint16_t calculate_crc(uint8_t *data, uint8_t length) {
    uint16_t crc_register = 0xFFFF;

    for (uint8_t i = 0; i < length; i++) {
        crc_register ^= data[i];

        for (uint8_t j = 0; j < 8; j++) {
            if (crc_register & 0x0001) {
                crc_register = (crc_register >> 1) ^ 0xA001;
            } else {
                crc_register >>= 1;
            }
        }
    }

    return crc_register & 0xFFFF;
}

int main() {
    uint8_t data[] = {0x01, 0x03, 0x04, 0x01, 0xF4, 0x05, 0xDC};
    uint8_t length = sizeof(data) / sizeof(data[0]);

    uint16_t crc = calculate_crc(data, length);
    uint8_t crc_high = (crc >> 8) & 0xFF;
    uint8_t crc_low = crc & 0xFF;

    printf("CRC High: 0x%02X\n", crc_high);
    printf("CRC Low: 0x%02X\n", crc_low);

    return 0;
}