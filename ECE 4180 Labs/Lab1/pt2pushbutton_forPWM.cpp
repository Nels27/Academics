#include "mbed.h"
#include "PinDetect.h"
#include "DebounceIn.h"

// Booker and Nelson 
// with extra credit oscilliscope pin dedication

PwmOut probe(p21);

PinDetect pb(p8);
PinDetect pb2(p7); //Debounced the pushbuttons so it would account for mechanical failure

PwmOut led(LED1); //setup PWM output
float p = 0.0f;

void pb_hit_callback(void) {
	p -= 0.01;
}

void pb2_hit_callback(void) {
	p += 0.01;

}


int main() {

	// Use internal pullups for pushbutton
	pb.mode(PullUp);
	pb2.mode(PullUp);
	//Delay for initial pullup to take effect
	wait(0.01);
	// Setting up the callback functions
	pb.attach_deasserted(&pb_hit_callback);
	pb2.attach_deasserted(&pb2_hit_callback);
	led = p;
	while (1) {
		if (p == 0.0f) { //brighten

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				probe = led;
				wait(0.1);

			}


			else {
				p = 0.0f;
				led = p;
				probe = led;
				wait(0.1);
			}

		}

		else if (p == 1.0f) {

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				probe = led;
				wait(0.1);
			}

			else {
				p = 1.0f;
				led = p;
				probe = led;
				wait(0.1);
			}
		}

		else if (p>0.0f && p != 1.0f && p != 0.0f && p < 1.0f) { //Brighten or Dim

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				probe = led;
				wait(0.1);
			}

			else if (!pb == 1) {
				p -= 0.1f;
				led = p;
				probe = led;
				wait(0.1);
			}

		}

		else if (p<0.0f) {
			p = 0.0f;

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				probe = led;
				wait(0.1);
			}

		}

		else if (p>1.0f) {
			p = 1.0f;

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				probe = led;
				wait(0.1);
			}
		}

	}


}

