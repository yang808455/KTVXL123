#include "timer.h"

uint32_t timer_cnt = 0;

void TIM1_UP_IRQHandler(void)
{
	if(TIM1 -> SR & (1 << 0)) //kiem tra co
	{
		TIM1 -> SR &= ~(1 << 0); //xoa co
		timer_cnt++;
	}
}

void TimerConfig(void)
{
	RCC -> APB2ENR |= (1 << 11);
	
	TIM1 -> PSC = 35;
	TIM1 -> ARR = 1;
	
	TIM1 -> CR1 |= (1 << 7); //luat chi cap nhat psc arr khi het chu ki
	TIM1 -> EGR |= (1 << 0); //cap nhat psc arr
	
	TIM1 -> DIER |= (1 << 0); //cho phep cap nhat interrupt
	TIM1 -> SR &= ~(1 << 0);	//cho gia tri co = 0
	
	NVIC_EnableIRQ(TIM1_UP_IRQn);
	
	TIM1 -> CR1 |= (1 << 0);
}

void delay_us(uint32_t time_us)
{
	uint32_t start = timer_cnt;
	while((timer_cnt - start) < time_us)
		{
		
		}
}
