/*
 * pwm.c
 *
 *  Created on: Apr 25, 2026
 *      Author: Morel
 */
// PA8 for PWM


#include "stm32f401xe.h"
#include "pwm.h"

void pwm_init(){

	RCC -> AHB1ENR |= (1U<<0); // clock für GPIOA
	RCC -> APB2ENR |= (1<<0); // clock für TIM1

	GPIOA -> MODER &= ~(3U << (8*2));
	GPIOA -> MODER |= (2U << (8*2));

	GPIOA -> AFR[1] &= ~(15U<<(0*4));
	GPIOA -> AFR[1]	|= (1U<<0);


	TIM1 -> PSC = 1600 - 1;
	TIM1 -> ARR = 10 - 1; // 1KHz

	TIM1 -> CCMR1 |= (6U << 4);    // OC1M = 110 (PWM Mode 1), capture bei
	TIM1 -> CCMR1 |= (1U << 3);    // OC1PE = 1 (Preload aktiv)

	TIM1 -> CCER |= (1<<0); // campture compare enable

	TIM1 -> CR1 |= (1U<<0); // Timer starten

	TIM1 -> BDTR |= (1U<<15);
}


void pwm_SetDuty(uint16_t duty) {

    if(duty > 100){
    	duty = 100;
    }
    TIM1->CCR1 = (TIM1->ARR * duty) / 100;
}
