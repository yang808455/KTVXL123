#ifndef UART_H
#define UART_H

#include "stm32f10x.h"
#include "stdint.h"

void ConFigUart(void);
void sendUart(uint8_t data);
uint8_t readUART(void);
uint16_t readfullUART(void);

#endif
