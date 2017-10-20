#include <mbed.h>
#include <target.h>
#include <Motor.h>
#include <RC_PWM.h>

DigitalOut ActivityLed(PA_5);
Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);
Serial Computer(USBTX, USBRX);
RcPwm pwmrc(PB_10);

//specify period duration

int main() {
  Computer.baud(9600);
  Computer.printf("Starting communication...");
    while(1)
    {
      ActivityLed = 1; // LED is ON
      MainMotor.TurnRight(0.5);
      Computer.printf("period %f",pwmrc.period());
      Computer.printf("pulse : %f",pwmrc.pulsewidth());
      
    }
}
