#include "plc.h"

uint8_t plc_addr;

// PLC::PLC(uint8_t address, HardwareSerial *serial)
// {
// 	this->serial = serial;
// 	this->address = address;
// }

void plc_begin(uint8_t addr)
{
	// serial->begin(9600, SERIAL_8O1);
	plc_addr = addr;
}

uint16_t ModRTU_CRC(uint8_t *buf, int len)
{
	uint16_t crc = 0xFFFF;

	for (int pos = 0; pos < len; pos++)
	{
		crc ^= (uint16_t)buf[pos]; // XOR uint8_t into least sig. uint8_t of crc
		for (int i = 8; i != 0; i--)
		{ // Loop over each bit
			if ((crc & 0x0001) != 0)
			{						 // If the LSB is set
				crc >>= 1; // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else				 // Else LSB is not set
				crc >>= 1; // Just shift right
		}
	}
	// Note, this number has low and high uint8_ts swapped, so use it accordingly (or swap uint8_ts)
	return crc;
}

void plc_relay(uint8_t pos, uint8_t value)
{
	uint8_t plc_buffer[8];
	plc_buffer[0] = plc_addr;
	plc_buffer[1] = 0x05;
	plc_buffer[2] = 0x00;
	plc_buffer[3] = pos;
	plc_buffer[4] = value == 0 ? 0x00 : 0xFF;
	plc_buffer[5] = 0x00;
	uint16_t crc = ModRTU_CRC(plc_buffer, 6);
	plc_buffer[6] = crc & 0xFF;
	plc_buffer[7] = (crc >> 8) & 0xFF;
	plc_send(plc_buffer, 8);
	delay(50);
}
