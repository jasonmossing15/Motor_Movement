/*
 * MotorMovement.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Jason.Mossing
 */

#include "MotorMovement.h"

void initializePWM(){
	P1DIR |= (BIT2);
	P1SEL |= (BIT2);
	P2DIR |= (BIT1|BIT4);
	P2SEL |= (BIT1|BIT4);

	TA0CTL &= MC1|MC0;
	TA1CTL &= MC1|MC0;

	TA0CTL |= TACLR;
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;
	TA1CTL |= TASSEL1;

	TA1CCR0 = 100;
	TA0CCR0 = 100;
	TA0CCR1 = 0;  //FRONT LEFT TA0.1
	TA1CCR1 = 0;  //FRONT RIGHT TA1.1
	TA1CCR2 = 0;  //BACK WHEELS	TA1.2

	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0;
	TA1CTL |= MC0;
}

void moveLeftMotorForward(){
	TA0CCR1 = 63;
	TA1CCR2 = 0;
}

void moveRightMotorForward(){
	TA1CCR1 = 63;
	TA1CCR2 = 0;
}

void stopLeftMotor(){
	TA0CCR1 = 0;
	TA1CCR2 = 0;
}

void stopRightMotor(){
	TA1CCR1 = 0;
	TA1CCR2 = 0;
}

void moveMotorsBackward(){
	stopLeftMotor();
	stopRightMotor();
	TA1CCR2 = 63;
}
