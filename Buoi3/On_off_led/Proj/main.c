#include "uart.h"
#include "stm32f10x.h"

int main()
{
	ConFigUart();
	
	RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0b0011 << 20);
	
	while(1)
		{
			uint8_t data = readUART();
			if (data == '1')
			{
					GPIOC->BSRR = (1 << 29);
			}
			else if (data == '0')
			{
					GPIOC->BSRR = (1 << 13);
			}
		}
}
