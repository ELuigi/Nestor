#ifndef __TARGET_H
#define __TARGET_H

/*###################### Activity led ###################################*/

#define LED_PIN                 PC_0

/*###################### PWM output ###################################*/

//signal port of pwm output of motors
#define MotorLeftForward        PC_9
#define MotorLeftBackward       PA_1
#define MotorRightForward       PC_8
#define MotorRightBackward      PC_6
//Period of PWM signal
#define PWMPeriodMs             20

/*###################### SPI MPU9250 ###################################*/

//SPI port for communication with MPU
#define SpiClk                  PB_13
#define SpiMosi                 PB_15
#define SpiMiso                 PB_14

/*###################### PWM input ###################################*/

#define PWMIn1                  PC13 //Nucleo user button

//Period of PWM read signal

#define PWMPeriodReadMs         20

#endif
