#ifndef __MOTOR_H
#define __MOTOR_H

#include <mbed.h>
#include <target.h>

class Motor
{
  private:

    PwmOut* MotorLF;
    PwmOut* MotorLB;
    PwmOut* MotorRF;
    PwmOut* MotorRB;

  public:

    Motor(PinName LF,PinName LB,PinName RF, PinName RB);
    void TurnLeft(float speed);
    void TurnRight(float speed);
    void MoveFront(float speed);
    void MoveBack(float speed);

};


#endif
