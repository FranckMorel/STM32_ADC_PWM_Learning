/*
 * timer.h
 *
 *  Created on: Apr 17, 2026
 *      Author: Morel
 */

#include "stdint.h"


#ifndef ADC_H_
#define ADC_H_

// PC1 -> ADC_IN11

#define ADC1_EN				(1U<<8)
#define GPIOC_EN			(1U<<2)
#define ADC1_CH11			(11U<<0)
#define ADC1_SEQ_Length		(0U<<20)
#define AD_ON				(1U<<0)
#define ADC_SWSTART			(1U<<30)
#define ADC_EOC				(1U<<1)

void adc_Init(void);
void start_conversion(void);
uint32_t adc_read(void);


#endif /* ADC_H_ */
