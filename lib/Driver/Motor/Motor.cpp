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
      MotorLF.write(0);
      MotorLB.write(speed);
      MotorRL.write(speed);
      MotorRB.write(0);

    }
    void TurnRight(float speed)
    {
        MotorLF.write(speed);
        MotorLB.write(0);
        MotorRL.write(0);
        MotorRB.write(speed);
    }
    void Movefront(float speed)
    {
      MotorLF.write(speed);
      MotorLB.write(0);
      MotorRL.write(speed);
      MotorRB.write(0);
    }
    void MoveBack(float speed)
    {
      MotorLF.write(0);
      MotorLB.write(speed);
      MotorRL.write(0);
      MotorRB.write(speed);
    }
