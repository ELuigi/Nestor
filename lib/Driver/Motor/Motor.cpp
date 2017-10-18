#include <Motor.h>

    Motor()
    {
      MotorLF.period_ms(PWMPeriodMs);
      MotorLB.period_ms(PWMPeriodMs);
      MotorRF.period_ms(PWMPeriodMs);
      MotorRB.period_ms(PWMPeriodMs);
    }
    void TurnLeft(float speed)
    {

    }
    void TurnRight(float speed)
    {
        MotorLF.write(speed);
    }
    void Movefront(float speed)
    {

    }
    void MoveBack(float speed)
    {

    }
