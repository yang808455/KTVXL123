#include "uart.h"
#include "stm32f10x.h"
#include "timer.h"

int main()
{
	ConFigUart();
	TimerConFig();
	
	RCC->APB2ENR |= (1 << 2);
	GPIOA->CRH &= ~(0xF << 0);
	GPIOA->CRH |=(0b1011 << 0);
	
		while(1)
    {
        if (USART1->SR & (1 << 5))
        {
            uint16_t data = readfullUART(); // duty tu 0 -> 100
            PWM_duty(data);
        }
    }
}

