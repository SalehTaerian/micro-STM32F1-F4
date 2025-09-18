#include<stm32f10x.h>
void TIM2_IRQHandler()
{
    if(TIM2->SR & (1<<0))
    {
        TIM2->SR &= ~(1<<0);
        if(GPIOC->ODR & (1<<13))
        {
            GPIOC->ODR &= 0<<13;
        }
        else
        {
            GPIOC->ODR |= 1<<13;
        }
    }
}
int main()
{
    RCC->APB2ENR |= 1<<4;
    RCC->APB1ENR |= 1<<0;
    GPIOC->CRH |= 2<<20;
    GPIOC->CRH &= ~(3<<22);
    TIM2->PSC = 7199;
    TIM2->ARR = 9999;
    TIM2->DIER |= 1<<0;
    TIM2->CR1 |= 1<<0;
    NVIC_EnableIRQ(TIM2_IRQn);
    while (1)
    {
    }
}
