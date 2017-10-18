#include <mbed.h>
#include <Motor.h>

    Motor::Motor(PinName LF,PinName LB,PinName RF, PinName RB)
    {
      MotorLF = new PwmOut(LF);
      MotorLB = new PwmOut(LB);
      MotorRF = new PwmOut(RF);
      MotorRB = new PwmOut(RB);
      MotorLF->period_ms(PWMPeriodMs);
      MotorLB->period_ms(PWMPeriodMs);
      MotorRF->period_ms(PWMPeriodMs);
      MotorRB->period_ms(PWMPeriodMs);
    }
    void Motor::TurnLeft(float speed)
    {
      MotorLF->write(0);
      MotorLB->write(speed);
      MotorRF->write(speed);
      MotorRB->write(0);

    }
    void Motor::TurnRight(float speed)
    {
        MotorLF->write(speed);
        MotorLB->write(0);
        MotorRF->write(0);
        MotorRB->write(speed);
    }
    void Motor::MoveFront(float speed)
    {
      MotorLF->write(speed);
      MotorLB->write(0);
      MotorRF->write(speed);
      MotorRB->write(0);
    }
    void Motor::MoveBack(float speed)
    {
      MotorLF->write(0);
      MotorLB->write(speed);
      MotorRF->write(0);
      MotorRB->write(speed);
    }
