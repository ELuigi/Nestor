#ifndef __MOTOR_H
#define __MOTOR_H

#include <mbed.h>
#include <target.h>

class Motor
{
  private:
    PwmOut MotorLF(MotorLeftForward);
    PwmOut MotorLB(MotorLeftBackward);
    PwmOut MotorRF(MotorRightForward);
    PwmOut MotorRB(MotorRightBackward);

  public:
    Motor();
    void TurnLeft();
    void TurnRight();
    void Movefront();
    void MoveBack();

};


#endif
