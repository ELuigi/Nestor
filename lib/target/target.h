#ifndef __TARGET_H
#define __TARGET_H

/*###################### Activity led ###################################*/

#define LED_PIN     PC_0

/*###################### PWM output ###################################*/

//signal port of pwm output of motors
#define MotorLeftForward        PB_0
#define MotorLeftBackward       PA_1
#define MotorRightForward       PC_8
#define MotorRightBackward      PC_6
//Period of PWM signal 
#define PWMPeriodMs 20

#endif
