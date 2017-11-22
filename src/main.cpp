#include <mbed.h>
#include <target.h>
#include <Motor.h>
#include <RC_PWM.h>

DigitalOut ActivityLed(PA_5);
Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);
Serial Computer(USBTX, USBRX);
RcPwm pwmrc(PC_5);

TIM_HandleTypeDef * TIM_2;
//specify period duration

int main() {

  Computer.baud(115200);
  Computer.printf("Starting communication...");

  __HAL_RCC_TIM2_CLK_ENABLE();
  TIM_2->Instance=TIM2;
  TIM_2->Instance->CCR1  = 0x01;
  TIM_2->Instance->CCR2  = 0;
  TIM_2->Instance->CR2   = 0;
  TIM_2->Instance->SMCR  = 0;
  TIM_2->Instance->DIER  = 0x01 | 0x02 | 0x03 | 0x04;
  TIM_2->Instance->EGR   = 0;
  TIM_2->Instance->CCMR1 = 0b100000001; //Register is set like this due to a bug in the define table (30-09-2017)
  TIM_2->Instance->CCMR2 = 0b100000001; //Register is set like this due to a bug in the define table (30-09-2017)
  TIM_2->Instance->CCER  = 0x00 | 0x04 | 0x08 | 0x0C;
  TIM_2->Instance->PSC   = 71;
  TIM_2->Instance->ARR   = 0xFFFF;
  TIM_2->Instance->DCR   = 0;


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
