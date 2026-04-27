
#include "stm32f401xe.h"
#include "adc.h"
#include "pwm.h"
#include "timer.h"


int main(void){

	adc_init();
	pwm_init();
	tim2_Init();

	while(1){
		  start_conversion();
		  uint16_t poti_wert = adc_read();   // 0 - 4095
		  uint8_t helligkeit = poti_wert / 41;  // 0 - 100


		  pwm_SetDuty(helligkeit);
		  //delay_ms(20);

	start_conversion();
	pwm_init();

	while(1){

		  uint16_t poti_wert = adc_read();   // 0 - 4095
		  uint8_t helligkeit = poti_wert / 41;  // 0 - 1000

		  pwm_SetDuty(helligkeit);
		  delay_ms(20);
	}

 }

}

