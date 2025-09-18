#include<stm32f10x.h>
    void timer_basic_setup()
    {
        TIM2->PSC  =71;
        TIM2->ARR = 999;
        TIM2->CCR1 = 500;
    }
    void pwm_mode_setup()
    {
        TIM2->CCMR1 &= ~(0xFF<<0);
        TIM2->CCMR1 |= (6<<4);
        TIM2->CCMR1 |= (1<<3);
    }
    void set_gpio()
    {
        RCC->APB2ENR |= 1<<2;
        GPIOA->CRL &= ~(0xF<<0);
        GPIOA->CRL |= (0xB<<0);
    }
    void output_enable()
    {
        TIM2->CCER |= 1<<0;
    }
    void timer_start()
    {
        TIM2->CR1 |= 1<<7;
        TIM2->CR1 &= ~(1<<4);
        TIM2->EGR |= 1<<0;
        TIM2->CR1  |= (1<<0);
    }
    int main()
    {
        RCC->APB1ENR |= 1<<0;
        set_gpio();
        timer_basic_setup();
        pwm_mode_setup();
        output_enable();
        timer_start();
        while(1)
        {
        }
    }
