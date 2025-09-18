//use f4 package I didn't download it
#include "stm32f4xx.h"    
void EXTI0_IRQHandler()
{
    if(EXTI->PR & 1<<0)
    {
        GPIOC->BSRR |= 1<<13;
        EXTI0_IRQHandler->PR |= 1<<0;
    }
}
int main()
{
    RCC->AHB1ENR |= 1<<2;
    RCC->AHB1ENR |= 1<<4;
    RCC->AHB1ENR |= 1<<14;
    GPIOC->MODER |= 1<<26;
    GPIOC->OTYPER &= ~(1<<13);
    GPIOC->OSPEEDR |= 2<<26;
    GPIOA->MODER &= ~(3<<0);
    GPIOA->PUPDR |= 1<<0;
    SYSCFG->EXTICR[0] &= ~(0xF<<0);
    EXTI->IMR |= 1<<0;
    EXTI->FTSR |= 1<<0;
    EXTI->RTSR |= ~(1<<0);
    NVIC_EnableIRQ(EXTI0_IRQn);
    while(1)
    {
    }
    
}
