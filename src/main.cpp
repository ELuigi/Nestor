#include <mbed.h>
#include <target.h>

DigitalOut ActivityLed(PA_5);
PwmOut PwmLeft(MotorLeft);
PwmOut PwmRight(MotorRight);

//specify period duration

int main() {

PwmLeft.period_ms(20); //50Hz
PwmRight.period_ms(10); //100Hz
ActivityLed.write(0.5f);
    while(1) {
      PwmLeft.pulsewidth_ms(1);
      PwmRight.pulsewidth_ms(5);
       ActivityLed = 1; // LED is ON
        wait(10); // 200 ms
      ActivityLed = 0;
          PwmLeft.pulsewidth_ms(10); // LED is OFF
        PwmRight.pulsewidth_ms(15);

        wait(10); // 1 sec
    }
}
