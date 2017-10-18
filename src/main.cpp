#include <mbed.h>
#include <target.h>

DigitalOut ActivityLed(PA_5);

//specify period duration

int main() {

ActivityLed.write(0.5f);
    while(1) {
       ActivityLed = 1; // LED is ON
        wait(10); // 200 ms
      ActivityLed = 0;

        wait(10); // 1 sec
    }
}
