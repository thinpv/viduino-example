#ifndef _PLC_H__
#define _PLC_H__

#include "stdint.h"

void plc_begin(uint8_t addr);
void plc_relay(uint8_t pos, uint8_t value);
void plc_send(uint8_t *buff, uint8_t len);

#endif
