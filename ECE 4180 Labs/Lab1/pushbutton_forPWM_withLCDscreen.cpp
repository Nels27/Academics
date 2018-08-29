#include "mbed.h"
#include "uLCD_4DGL.h"
#include "DebounceIn.h"

// Booker and Nelson 

uLCD_4DGL uLCD(p9, p10, p11);

DigitalOut myDimled(LED1);
//DigitalIn pb(p8); // Dims the light
//DigitalIn pb2(p7); // Brightens light

DebounceIn pb(p8);
DebounceIn pb2(p7); //Debounced the pushbuttons so it would account for mechanical failure

PwmOut led(LED1); //setup PWM output
int main() {
	uLCD.printf("\nTesting Screen for light status\n"); //Default Green on black text
	uLCD.printf("\n  Starting...\n");
	uLCD.text_width(4); //4X size text
	uLCD.text_height(4);
	uLCD.color(RED);

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
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}


			else {
				p = 0.0f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}

		}

		else if (p == 1.0f) {

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}

			else {
				p = 1.0f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}
		}

		else if (p>0.0f && p != 1.0f && p != 0.0f && p < 1.0f) { //Brighten or Dim

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}

			else if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}

		}

		else if (p<0.0f) {
			p = 0.0f;

			if (!pb2 == 1) {
				p += 0.1f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}

		}

		else if (p>1.0f) {
			p = 1.0f;

			if (!pb == 1) {
				p -= 0.1f;
				led = p;
				wait(0.1);
				uLCD.cls();
				uLCD.printf("%2f", p);
				wait(0.1);
			}
		}

	}


}

