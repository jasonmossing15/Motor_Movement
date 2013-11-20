/*
 * MotorMovement.c
 *
 *  Created on: Nov 18, 2013
 *      Author: C15Jason.Mossing
 */

#include "MotorMovement.h"

void moveLeftMotorForward();

void moveRightMotorForward();

void stopLeftMotor();

void stopRightMotor();


void initializePWM(){
	P1DIR |= BIT2;
	P1SEL |= BIT2;
	P2DIR |= BIT1|BIT4|BIT5;
	P2SEL |= BIT1|BIT4|BIT5;

	TA0CTL &= ~(MC1|MC0);
	TA1CTL &= ~(MC1|MC0);

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
	TA1CCTL2 |= OUTMOD_7;


	TA0CTL |= MC0;
	TA1CTL |= MC0;
}

void moveLeftMotorForward(){
	TA0CCR1 = 58;
	TA1CCR2 = 0;
}

void moveRightMotorForward(){
	TA1CCR1 = 58;
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
	TA1CCR2 = 58;
}
void smallLeftTurn(){
	stopLeftMotor();
	__delay_cycles(500000);
	moveLeftMotorForward();

}

void smallRightTurn(){
	stopRightMotor();
	__delay_cycles(500000);
	moveRightMotorForward();
}

void largeLeftTurn(){
	stopLeftMotor();
	__delay_cycles(1500000);
	moveLeftMotorForward();
}

void largeRightTurn(){
	stopRightMotor();
	__delay_cycles(1500000);
	moveRightMotorForward();
}

void moveForward(){
	moveLeftMotorForward();
	moveRightMotorForward();
}
