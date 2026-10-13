#include "stm32f10x.h"

// ham delay
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

int main(){
  // PA0
	RCC -> APB2ENR |= (1 << 2); 			// cap xung
	GPIOA -> CRL &= ~(0xF << 0);  		// dat lai gia tri ve 0
	GPIOA -> CRL |= (0b1000 << 0);		// dat che do 
	GPIOA -> ODR &= ~(1 << 0);				// dat che do pull down
	
	// PC13
	RCC -> APB2ENR |= (1 << 4);			//cap xung 
	GPIOC -> CRH &= ~(0xF << 20);		// dat lai gia tri ve 0
	GPIOC -> CRH |= (0b0011 << 20); // dat che do
	GPIOC -> BSRR |= 1 << 13;				// tat den led pc13
	
	while(1){
		if ((GPIOA->IDR & (1 << 0)) != 0) {    		// dieu kien neu nhan duoc tin hieu tu nut nhan     
				if ((GPIOC->IDR & (1 << 13)) != 0) {  // kiem tra chan 13 co dang bat led khong
					GPIOC->BSRR = 1 << 29;							// neu led dang bat thi tat
				} else {                              
					GPIOC->BSRR = 1 << 13;							// neu led tat thi bat
				}   
				delay(50);														// chung bounding
		}
	}
}