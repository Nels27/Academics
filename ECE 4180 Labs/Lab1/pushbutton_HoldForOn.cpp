#include "mbed.h"

//Nelson and Booker

DigitalOut myled(LED1);
DigitalIn pb(p9);

int main() {

	pb.mode(PullUp);

	while (1) {
		//inverted the value so it causes the led to come on when pressed
		myled = !pb;


	}
}