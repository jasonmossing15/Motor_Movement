#include "MotorMovement.h"
#include "clkSpeed/clkSpeed.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    setspeed_1MHz();
    initializePWM();

    while(1){
    	moveForward();
    	__delay_cycles(1500000);
    	smallLeftTurn();
    	__delay_cycles(500000);
    	smallRightTurn();
    	__delay_cycles(1500000);
    	moveMotorsBackward();
    	__delay_cycles(2000000);

    	moveForward();
    	__delay_cycles(1500000);
    	largeLeftTurn();
    	__delay_cycles(500000);
    	largeRightTurn();
    	__delay_cycles(1500000);
    	moveMotorsBackward();
    	__delay_cycles(2000000);

    }

	return 0;
}
