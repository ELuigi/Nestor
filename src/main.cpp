#include <mbed.h>
#include <target.h>
#include <Motor.h>

DigitalOut ActivityLed(PA_5);
Motor MainMotor(MotorLeftForward,MotorLeftBackward,MotorRightForward,MotorRightBackward);
Serial Computer(USBTX, USBRX);

//specify period duration

int main() {
  Computer.baud(9600);
  Computer.printf("Starting communication...");
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
