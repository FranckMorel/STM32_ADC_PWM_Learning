/*
 * stepper.h
 *
 *  Created on: Apr 18, 2026
 *      Author: kzvvftre
 */


#ifndef STEPPER_H_
#define STEPPER_H_

#include <stdint.h>

void StepperInit(void);
void moveForward(uint16_t steps);
void moveBackward(uint16_t steps);



#endif /* STEPPER_H_ */
