#include <mbed.h>
#include <target.h>

DigitalOut ActivityLed(LED_PIN);
PwmOut PwmLeft(MotorLeft);
PwmOut PwmRight(MotorRight);

int main() {
    while(1) {
        ActivityLed = 1; // LED is ON

        wait(0.2); // 200 ms
        ActivityLed = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}
