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
	//initialize the outputs for the capture
	P1DIR |= BIT2;
	P1SEL |= BIT2;
	P2DIR |= BIT1;
	P2DIR |= BIT4;
	P2DIR |= BIT5;
	P2SEL |= BIT1;
	P2SEL |= BIT4;
	P2SEL |= BIT5;

	//stop the timers
	TA0CTL &= ~(MC1|MC0);
	TA1CTL &= ~(MC1|MC0);

	//clear the timers
	TA0CTL |= TACLR;
	TA1CTL |= TACLR;

	//configure for SMCLK
	TA0CTL |= TASSEL1;
	TA1CTL |= TASSEL1;

	TA1CCR0 = 100;
	TA0CCR0 = 100;
	TA0CCR1 = 0;  //FRONT LEFT TA0.1
	TA1CCR1 = 0;  //FRONT RIGHT TA1.1
	TA1CCR2 = 0;  //BACK WHEELS	TA1.2

	//set output to Reset/Set
	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_7;

	//Start the timers
	TA0CTL |= MC0;
	TA1CTL |= MC0;
}

void moveLeftMotorForward(){
	TA0CCR1 = 60;
	TA1CCR2 = 0;
}

void moveRightMotorForward(){
	TA1CCR1 = 60;
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
	TA1CCR2 = 60;
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

void stopMotors(){
	stopLeftMotor();
	stopRightMotor();
}
