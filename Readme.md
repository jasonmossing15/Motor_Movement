# Robot Movement

This library is used to move the DFEC Robot.


## Description

The robot has six basic movements. Forward, backward, small left, small right, large left, and large right. The terms small and large refer to the degree of turning. Small turns are those less than 45 degrees. Large turns are those greater than 45 degrees. The motion of the robot is one like a tank, which means in order to turn one wheel stops and the other keeps moving. 

### Pulse Width Modulation (PWM)

PWMs are a huge key in this lab. The duty cycle on the PWM refers to the percentage of voltage the motors will see. The max duty cycle used in order to keep the robot moving with out resetting the chip. The max voltage the motors can see before reseting the chip is 8 Volts, according to Capt Branchflower. I used a max voltage of 7.5 Volts just to be safe. The amount of voltage the motor can see is 12 Volts. Therefore we need a duty cycle of 63% to be the max.
```
7.5/12 * 100% = 62.5% = 63%
```
There are 3 PWMs used. They are TA0.1, TA1.1, and TA0.2. Each hold a specific purpose and output on their own pin. 
 - TA0.1 is used to control the left motor for the forward direction, shown on Pin 1.2. 
 - TA1.1 is used to control the right motor for the forward direction, shown in Pin 2.1.
 - TA1.2 is used to control the backward direction for both the right and left motor. This is shown on Pins 2.4 and 2.5.

### The Code
