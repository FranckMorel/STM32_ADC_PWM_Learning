/*
NOTES:
APB -> Advanced Peripheral Bus
AHB -> Advanced High Performance Bus ( schnellere Clock Zyklen )
Locating Ports -> Block diagramm ( Datasheet ) , Memory mapping

Formula für GPIO Port Bits setzen
pin n:

clear -> &= ~(3 << (n*2))
set   -> |= value << (n*2)

*/

/* STEPPER_TEST


#include <stm32f401xe.h>
#include <stdio.h>

int main(void){
	RCC -> AHB1ENR |= (1U<<0);
	RCC -> AHB1ENR |= (1U<<1);

	GPIOA -> MODER &= ~(3U << (0*2));
	GPIOA -> MODER |=  (1U <<(0*2));

	GPIOA -> MODER &= ~(3U << (1*2));
	GPIOA -> MODER |=  (1U <<(1*2));

	GPIOA -> MODER &= ~(3U << (4*2));
	GPIOA -> MODER |=  (1U <<(4*2));

	GPIOB -> MODER &= ~(3U << (0*2));
	GPIOB -> MODER |=  (1U <<(0*2));

	/*
	 	Profi Version für Ports A0 bis A3 als output setzen
	   	GPIOA->MODER &= ~0x000000FF;
		GPIOA->MODER |=  0x00000055;

		PA0 PA1 PA2 PA3
		01  01  01  01  ->  010101
	*/
/*
	void Vorwaerts_R(){
		for(volatile int y=0; y<4; y++){

		GPIOA->BSRR = (1<<16) | (1<<17) | (1<<20);
		GPIOB->BSRR = (1<<16);

		if(y==0) GPIOA->BSRR = (1<<0);
		if(y==1) GPIOA->BSRR = (1<<1);
		if(y==2) GPIOA->BSRR = (1<<4);
		if(y==3) GPIOB->BSRR = (1<<0);

		for(volatile int a=0; a<1000000; a++){}
    }
  }

   void Rueckwaerts_R(){
	   for(volatile int x=3; x>=0; x--){

	   GPIOA->BSRR = (1<<16) | (1<<17) | (1<<20);
	   GPIOB->BSRR = (1<<16);

	   if(x==0) GPIOA->BSRR = (1<<0);
	   if(x==1) GPIOA->BSRR = (1<<1);
	   if(x==2) GPIOA->BSRR = (1<<4);
	   if(x==3) GPIOB->BSRR = (1<<0);

	   for(volatile int b=0; b<1000000; b++){}
	}

   }

	while(1){
		Vorwaerts_R();
		for(volatile int c=0; c<1000000; c++){}
		Rueckwaerts_R();
	}

}

*/


#include <stepper.h>
#include <timer.h>


int main(void)
{
    StepperInit();
    tim2_Init();


    while(1)
    {
    	moveForward(2048);
    	motionDelay_ms(1000);
        //for(volatile int i=0; i<1500000; i++){} // vorhin Delay mit Schleife

        moveBackward(2048);
        motionDelay_ms(1000);
        //for(volatile int i=0; i<1500000; i++){}


    }
}



/* MINIMAL TEST LED
#include "stm32f401xe.h"

int main(void)
{
    RCC->AHB1ENR |= (1U << 0);          // GPIOA clock
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));   // PA5 output

    RCC->APB1ENR |= (1U << 0);          // TIM2 clock
    TIM2->PSC = 16000 - 1;              // 1 kHz
    TIM2->ARR = 500 - 1;                // 500 ms
    TIM2->CNT = 0;
    TIM2->SR  = 0;
    TIM2->EGR = (1U << 0);
    TIM2->CR1 |= (1U << 0);             // CEN

    while(1)
    {
        if(TIM2->SR & (1U << 0))
        {
            TIM2->SR &= ~(1U << 0);
            GPIOA->ODR ^= (1U << 5);
        }
    }
}
*/

