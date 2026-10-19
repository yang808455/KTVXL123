#include "timer.h"

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
	RCC->APB2ENR |= (1 << 2);
	GPIOA->CRH &= ~(0xF << 0);
	GPIOA->CRH |=(0b1011 << 0);
	
	TimerConFig();
	while(1)
		{
			for(int i = 0; i < 1000; i++)
				{
					PWM_duty(i);
					delay(3);
				}
			for(int i = 999; i >= 0; i--)
				{
					PWM_duty(i);
					delay(3);
				}
		}
}
