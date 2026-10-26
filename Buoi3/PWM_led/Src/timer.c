#include "timer.h"

void TimerConFig(void)
{
	RCC -> APB2ENR |= (1 << 11);
	
	TIM1->ARR = 99;
	TIM1->PSC = 35;
	
	//CH1
	TIM1->CCMR1 &= ~(0xFF); //xoa ve 0
	TIM1->CCMR1 |= (0b110 << 4); // PWM mode 1
	TIM1->CCMR1 |= (1 << 3); 			//cho phep cap nhat duty
	
	
	TIM1->CCER |= (1<<0); //cho phep xuat ra chan GPIO PA8
	
	TIM1->BDTR |= (1 << 15);     // MOE = 1
	
	TIM1->CR1 |= (1 << 0);
	TIM1->CR1 |= (1 << 7);
}


void PWM_duty(uint16_t duty)
{
	TIM1->CCR1 = duty;			//duty = (CRR / (ARR + 1)) * 100% 
	
}



