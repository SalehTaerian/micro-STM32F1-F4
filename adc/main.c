#include<stm32f10x.h>
void delay()
{
	int i= 10000;
	while(i)
	{
		i--;
	}
}
void ADC_Init()
{
	RCC->APB2ENR|=1<<2;
	RCC->APB2ENR |=1<<9;
	GPIOA->CRL &= ~(0xF<<0);
	RCC->CFGR |= 1<<15;
	ADC1->SMPR2 |= 3<<0;
	ADC1->SQR1 =0;	
	ADC1->SQR3 =0;
	ADC1->CR2 |= 1<<0;
	delay();
	ADC1->CR2 |= 1<<3;
	ADC1->CR2 |= 1<<2;
}
uint16_t ADC_Read()
{
	ADC1->CR2 |= 1<<22;
	return (uint16_t)ADC1->DR;
}
float ADC_ToVolatage(uint16_t value)
{
	return (float)value/4095 *3.3;
}
int main()
{
	ADC_Init();
	
	while(1)
	{
		float voltage = ADC_ToVolatage(ADC_Read());
	}
}