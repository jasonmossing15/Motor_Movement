/*
 * MotorMovement.h
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Jason.Mossing
 */
#include <msp430.h>

#ifndef MOTORMOVEMENT_H_
#define MOTORMOVEMENT_H_

void initializePWM();

void moveLeftMotorForward();

void moveRightMotorForward();

void stopLeftMotor();

void stopRightMotor();

void moveMotorsBackward();


#endif /* MOTORMOVEMENT_H_ */
