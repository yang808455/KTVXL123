#include "stm32f10x.h"

void delay(uint32_t time)
{
	while(time)
		{
			SysTick -> CTRL = 5;
			SysTick -> VAL = 0;
			SysTick -> LOAD = 72000 - 1;
			while(!(SysTick -> CTRL & (1<<16)));
			time--;
		}
}

int main()
{
	RCC -> APB2ENR |=1 << 4; 			// |=1: dat bit la 1, <<: dich trai
	GPIOC -> CRH &= ~(0b1111 << 20); 		// dua gia tri tu 20-23 ve 0 
	GPIOC -> CRH |= 0b0011 << 20;				// tra bang
	while(1)
		{
			GPIOC -> BSRR |= 1 << 13;
			delay(500);
			GPIOC -> BSRR |= 1 << 29;
			delay(500);
		}
	return 0;
}
	