#include<stm32f10x.h>
void USART1_Init()
{
    RCC->APB2ENR |= 1<<2;
    RCC->APB2ENR |= 1<<14;
    GPIOA->CRH &= ~((0xF<<4)|(0xF<<8));
    GPIOA->CRH |= (0xB<<4);
    GPIOA->CRH |= (0x4<<8);
    USART1->BRR =7500;
    USART1->CR1 |= 1<<3;
    USART1->CR1 |= 1<<2;
    USART1->CR1 |= 1<<13;
}
void USART1_sendchar(char c)
{
    USART1->DR = c;
}
void USART1_sendstring(char *s)
{
    while(*s)
    {
        USART1_sendchar(*s);
        s++;
    }
}
int main()
{
    USART1_Init();
    USART1_sendstring("hello world!");
    while(1)
    {
    } }
