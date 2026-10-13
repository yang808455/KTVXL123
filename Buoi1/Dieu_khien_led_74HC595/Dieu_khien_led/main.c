#include "stm32f10x.h"

// ham delay
void delay(uint32_t ms)
{
    while (ms--)
    {
        for (volatile uint32_t i = 0; i < 12000; i++);
    }
}

int main(void)
{
    //PA0
    RCC->APB2ENR |= (1 << 2);           //cap xung
    GPIOA->CRL &= ~(0b1111 << 0);        //xoa trang thai cu
    GPIOA->CRL |=  (0b0011 << 0);        //dat trang thai

    //PA1
    GPIOA->CRL &= ~(0b1111 << 4);       //xoa trang thai cu
    GPIOA->CRL |=  (0b0011 << 4);       //dat trang thai moi

    //PA2
    GPIOA->CRL &= ~(0b1111 << 8);       //xoa trang thai cu
    GPIOA->CRL |=  (0b0011 << 8);       //dat trang thai moi

    GPIOA->BSRR = (1 << 16);
    GPIOA->BSRR = (1 << 17);
    GPIOA->BSRR = (1 << 18);

    while (1)
    {
        //bat led
        //PA1 = 1
        GPIOA->BSRR = (1 << 1);

        for (int i = 0; i < 8; i++)
        {
            //tao xung len PA0
            GPIOA->BSRR = (1 << 16);

            GPIOA->BSRR = (1 << 0);

        }

        GPIOA->BSRR = (1 << 18);
        delay(1);
        GPIOA->BSRR = (1 << 2);
        delay(1);
        GPIOA->BSRR = (1 << 18);

        delay(1);

        //tat led
        //PA1 = 0
        GPIOA->BSRR = (1 << 17);

        for (int i = 0; i < 8; i++)
        {
            //tao xung len PA0
            GPIOA->BSRR = (1 << 16);

            GPIOA->BSRR = (1 << 0);

        }

        GPIOA->BSRR = (1 << 18);
        delay(1);
        GPIOA->BSRR = (1 << 2);
        delay(1);
        GPIOA->BSRR = (1 << 18);

        delay(1);
    }
}