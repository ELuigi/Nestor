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
    void TurnLeft(float speed);
    void TurnRight(float speed);
    void Movefront(float speed);
    void MoveBack(float speed);

};


#endif
