#include <mbed.h>
#include <target.h>
#include <Motor.h>

DigitalOut ActivityLed(PA_5);
Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);


//specify period duration

int main() {
    while(1)
    {
      ActivityLed = 1; // LED is ON
      MainMotor.TurnLeft(0.5);
      wait(10); // 200 ms
      ActivityLed = 0;
      MainMotor.TurnRight(0.5);
      wait(10); // 1 sec
      ActivityLed = 1;
      MainMotor.MoveFront(0.5);
      wait(10); // 1 sec
      ActivityLed = 0;
      MainMotor.MoveBack(0.5);
      wait(10); // 1 se
    }
}
