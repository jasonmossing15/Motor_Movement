#include "MotorMovement.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initializePWM();

    while(1){
    	moveLeftMotorForward();
		moveRightMotorForward();
    }

	return 0;
}
