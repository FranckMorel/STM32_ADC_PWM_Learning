#include "stm32f401xe.h"
#include "adc.h"


void adc_Init(void){

	RCC -> APB2ENR |= ADC1_EN; 		// ADC clock  EN
	RCC -> AHB1ENR |= GPIOC_EN; 	// GPIOC clock EN

	GPIOC->MODER |= (3U << (1*2)); 	// PC1 analog MODE

	/* ADC Config
	 * use sequence register to define the order of the channels
	 * if working with 2 or more channels you have to determine the order of the channels by writting the number
	 * in binary form in the SQR you need
	 * for Example: CH1,CH2 and CH3 with SQ1, SQ2 and SQ3 in the order 2;3;1 then SQ1->00010 , SQ2->00011 , SQ3->00001
	 * In this Code we are working with one channel (CH11) so we can simply put CH11 at SQ1 by writing 01011 (binary 11)
	 * Use SQR1 Bits 20 to 23 to define the length of the seqeunce ( i.e number of channels used )
	 * for Example: 0000 for 1 channel , 0001 for 2, .... 1111 for 16 channels
	 * */
	ADC1 -> SQR3 = ADC1_CH11; 		// set cause no need other register bits
	ADC1 -> SQR1 = ADC1_SEQ_Length;	// 0000 for 1 as length
	ADC1 -> CR2 |= AD_ON;

}

void start_conversion(void){

	ADC1 -> CR2 |= ADC_SWSTART;
}


uint32_t adc_read(void){

	/*wait till conversion is commplete
	 *A flag is raised when this is done
	 */
	while(!(ADC1 -> SR & ADC_EOC)){}

	/*read the converted result*/
	return (ADC1 -> DR);

}
