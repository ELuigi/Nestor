#ifndef __MOTOR_H
#define __MOTOR_H

#include <mbed.h>
#include <target.h>

class Motor
{
  private:
    PwmOut MotorL(MotorLeft);
    PwmOut MotorR(MotorRight);

  public:
    Motor();
    void TurnLeft();
    void TurnRight();
    void Movefront();
    void MoveBack();

};


#endif
