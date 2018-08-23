#include "mbed.h"

//Nelson and Booker

DigitalOut myled(LED1);
DigitalOut bookerLED(LED2);
DigitalOut lolaLED(LED3);
DigitalOut ryanLED(LED4);

DigitalIn pb(p9);

int main() {

	pb.mode(PullUp);

	while (1) {
		myled = pb;
		/*
		wait(0.2);
		myled = 0;
		wait(0.2);

		bookerLED = 1;
		wait(0.4);
		bookerLED = 0;
		wait(0.4);

		lolaLED = 1;
		wait(0.6);
		lolaLED = 0;
		wait(0.6);

		ryanLED = 1;
		wait(0.8);
		ryanLED = 0;
		*/

	}
}