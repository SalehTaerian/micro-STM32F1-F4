#include<stm32f10x.h>
void EXTI0_IRQHandler()
{
    if(EXTI->PR & 1<<0)
    {
        GPIOC->BSRR |= 1<<13;
        EXTI->PR |= 1<<0;
    }
}
int main()
{
    RCC->APB2ENR |= 1<<0;
    RCC->APB2ENR |= 1<<4;
    RCC->APB2ENR |= 1<<2;
    GPIOC->CRH |= 2<<20;
    GPIOC->CRH &= ~(3<<22);
    GPIOA->CRL &= ~(3<<0);
    GPIOA->CRL  |= 1<<3;
    GPIOA->BSRR |= 1<<0;
    AFIO->EXTICR[0] |= 0<<0;
    // AFIO->EXTICR[0] &= ~(0xF<<0);
    EXTI->IMR |= 1<<0;
    EXTI->FTSR |= 1<<0;
    EXTI->RTSR &= 1<<0;
    NVIC_EnableIRQ(EXTI0_IRQn);
    while (1)
    {
    }
}
