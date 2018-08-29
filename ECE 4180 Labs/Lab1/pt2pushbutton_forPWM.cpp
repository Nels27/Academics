#include "mbed.h"
#include "DebounceIn.h"

// Booker and Nelson 


DigitalOut myDimled(LED1);

DebounceIn pb(p8);
DebounceIn pb2(p7); //Debounced the pushbuttons so it would account for mechanical failure

PwmOut led(LED1); //setup PWM output
int main() {

	pb.mode(PullUp);
	pb2.mode(PullUp);
	float p = 0.0f;
	led = p;
	while (1) {
		if (p == 0.0f) { //brighten

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				wait(0.1);
			}


			else {
				p = 0.0f;
				led = p;
				wait(0.1);
			}

		}

		else if (p == 1.0f) {

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
			}

			else {
				p = 1.0f;
				led = p;
				wait(0.1);
			}
		}

		else if (p>0.0f && p != 1.0f && p != 0.0f && p < 1.0f) { //Brighten or Dim

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				wait(0.1);
			}

			else if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
			}

		}

		else if (p<0.0f) {
			p = 0.0f;

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				wait(0.1);
			}

		}

		else if (p>1.0f) {
			p = 1.0f;

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
			}
		}

	}


}

