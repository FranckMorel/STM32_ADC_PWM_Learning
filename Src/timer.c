#include <stm32f401xe.h>


void tim2_Init(void){
	RCC -> APB1ENR |= (1U<<0);

	TIM2 -> PSC = 1600 - 1; // 16MHz
	TIM2 -> ARR = 100 - 1 ; // 1ms
	TIM2 -> CNT = 0;
	TIM2 -> SR  = 0;
	//TIM2 -> EGR = (1U << 0); // Update Event

	TIM2 -> CR1 |= (1U<<0);

}


void delay_ms(uint32_t delayTime){
	for(uint32_t i=0; i<delayTime; i++)
		{

		while(!(TIM2 -> SR & (1U<<0))){}
		   TIM2 -> SR &= ~(1U<<0);
		}
}

