#include <stm32f401xe.h>


#define IN1_AN			(GPIOA -> BSRR = (1<<0))
#define IN1_AUS			(GPIOA -> BSRR = (1<<16))
#define IN2_AN			(GPIOA -> BSRR = (1<<1))
#define IN2_AUS			(GPIOA -> BSRR = (1<<17))
#define IN3_AN			(GPIOA -> BSRR = (1<<4))
#define IN3_AUS			(GPIOA -> BSRR = (1<<20))
#define IN4_AN			(GPIOB -> BSRR = (1<<0))
#define IN4_AUS			(GPIOB -> BSRR = (1<<16))

static int stepIndex = 0;


static void speedDelay(void){
	for(int i=0; i<2000; i++){}
}



uint8_t phase[8][4] = {
	  {1, 0, 0, 0},  // Schritt 1
	  {1, 1, 0, 0},  // Schritt 2
	  {0, 1, 0, 0},  // Schritt 3
	  {0, 1, 1, 0},  // Schritt 4
	  {0, 0, 1, 0},  // Schritt 5
	  {0, 0, 1, 1},  // Schritt 6
	  {0, 0, 0, 1},  // Schritt 7
	  {1, 0, 0, 1}   // Schritt 8
};

static void step_Output(int stepIndex){

	    if(phase[stepIndex][0]) IN1_AN;
	    else               		IN1_AUS;

	    if(phase[stepIndex][1]) IN2_AN;
	    else               		IN2_AUS;

	    if(phase[stepIndex][2]) IN3_AN;
	    else               		IN3_AUS;

	    if(phase[stepIndex][3]) IN4_AN;
	    else               		IN4_AUS;

}

void StepperInit(void){

	RCC -> AHB1ENR |= (1<<0);
	RCC -> AHB1ENR |= (1<<1);

	GPIOA -> MODER &= ~(3U << (0*2));
	GPIOA -> MODER |=  (1U <<(0*2));

	GPIOA -> MODER &= ~(3U << (1*2));
	GPIOA -> MODER |=  (1U <<(1*2));

	GPIOA -> MODER &= ~(3U << (4*2));
	GPIOA -> MODER |=  (1U <<(4*2));

	GPIOB -> MODER &= ~(3U << (0*2));
	GPIOB -> MODER |=  (1U <<(0*2));

	stepIndex = 0;
	step_Output(stepIndex);

}


static void stepForward(void){
	stepIndex++;
	if(stepIndex >= 8){

		stepIndex = 0;
	}

	step_Output(stepIndex);
	speedDelay();

}

static void stepBackward(void){
	stepIndex--;
	if(stepIndex < 0){

		stepIndex = 7;
	}

	step_Output(stepIndex);
	speedDelay();

}


void moveForward(uint16_t steps){
  for(uint16_t i = 0; i < steps; i++){
	    stepForward();
     }

}

void moveBackward(uint16_t steps){
	for(uint16_t i = 0; i < steps; i++){
		stepBackward();
	  }
}
