#include <mbed.h>
#include <target.h>
#include <Motor.h>
#include <RC_PWM.h>

DigitalOut ActivityLed(PA_5);
Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);
Serial Computer(USBTX, USBRX);
RcPwm pwmrc(PC_5);

//specify period duration

int main() {

  Computer.baud(115200);
  Computer.printf("Starting communication...");
TIM_HandleTypeDef TIM_2;


    while(1)
    {
      ActivityLed = 1; // LED is ON
      MainMotor.TurnRight(0.5);
      Computer.printf("period %f ",pwmrc.period());
      Computer.printf("pulse : %f \n",pwmrc.pulsewidth());

      wait(2);
      MainMotor.TurnRight(0.8);
      Computer.printf("period %f ",pwmrc.period());
      Computer.printf("pulse : %f \n",pwmrc.pulsewidth());
      wait(2);
    }
}
