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
    void TurnLeft(int speed);
    void TurnRight(int speed);
    void Movefront(int speed);
    void MoveBack(int speed);

};


#endif
