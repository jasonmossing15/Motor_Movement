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

void smallLeftTurn();

void smallRightTurn();

void largeLeftTurn();

void largeRightTurn();

void moveForward();

void moveMotorsBackward();


#endif /* MOTORMOVEMENT_H_ */
