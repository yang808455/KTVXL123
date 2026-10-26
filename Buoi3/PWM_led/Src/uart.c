#include "uart.h"
#include "stm32f10x.h"

void ConFigUart(void)
{
	RCC -> APB2ENR |= (1 << 2) | (1 << 14);  // cap xung cho GPIOA va UART1
	
	// chon che do chan PA9
	GPIOA -> CRH &= ~(0xFU << 4);
	GPIOA -> CRH |= (0xBU << 4); // Tx 
	
	// chon che do chan PA10
	GPIOA->CRH &= ~(0xFU << 8);
	GPIOA->CRH |= (0x8U << 8);  // Rx pull up
	GPIOA->ODR |= (1 << 10); // kich hoat pull up
	
	USART1->BRR = 7500U; //baud = 9600 -> BRR = fclk / baud = 72M / 9600 = 7600
	
	USART1->CR1 |= (1 << 2) | (1 << 3); // cho phep Rx Tx
	USART1->CR1 |= (1 << 13); 					// cho phep UART
}

void sendUart(uint8_t data)
{
	while((USART1->SR & (1 << 7)) == 0) // kiem tra thanh ghi trang thai cua Tx
		{
			USART1->DR = data;
		}
}

uint8_t readUART(void)
{
	if((USART1->SR & (1 << 5)))  // kiem tra co 
		{
			return USART1->DR;
		}
	return 0;
}

uint16_t readfullUART(void)
{
    uint16_t number = 0;
    
    while (1)
    {
        while (!(USART1->SR & (1 << 5)));							// kiem tra co
        uint8_t data = (uint8_t)(USART1->DR & 0xFF);	// co co thi doc data
        if (data == '\r' || data == '\n')							// kiem tra dieu kien ket thuc
        {
            break;
        }
        if (data >= '0' && data <= '9')								// ASICII to number
        {
            number = number * 10 + (data - '0');
        }
    }
    
    return number;
}
