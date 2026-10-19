#ifndef TIMER_H
#define TIMER_H

#include "stm32f10x.h"
#include "stdint.h"

void TimerConfig(void);
void delay_us(uint32_t time_us);
	
#endif
