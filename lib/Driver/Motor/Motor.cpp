#include <Motor.h>

    Motor()
    {
      MotorLF.period_ms(PWMPeriodMs);
      MotorLB.period_ms(PWMPeriodMs);
      MotorRF.period_ms(PWMPeriodMs);
      MotorRB.period_ms(PWMPeriodMs);
    }
    void TurnLeft();
    void TurnRight();
    void Movefront();
    void MoveBack();
