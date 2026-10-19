#include "stm32f10x.h"
#include "timer.h"

int main(){
	TimerConfig();
	RCC->APB2ENR|=(1<<4);
	GPIOC->CRH|=(0b0000<<20);
	GPIOC->CRH|=(0b0011<<20);
	while(1)
	{
		GPIOC->BSRR|=(1<<13);
		delay_us(1000000);
		GPIOC->BSRR|=(1<<29);
		delay_us(1000000);
	}

}
