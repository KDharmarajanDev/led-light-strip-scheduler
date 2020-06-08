// Do not remove the include below
#include "led_strip_scheduler.h"
#include "scheduler.h"
#include "SMD5050LEDStrip.h"
#include "random_generator.h"
#include "led_state.h"

Scheduler scheduler({});

//The setup function is called once at startup of the sketch
void setup() {
	Color redColor(255,0,0);
	LEDState redState(redColor, 1000);
	Color blueColor(0,0,255);
	LEDState blueState(blueColor,1000);
	Color whiteColor(255,255,255);
	LEDState whiteState(whiteColor,1000);
	LEDState * redWhiteBlueStates[] = {
				&redState,
				&blueState,
				&whiteState
		};
	RandomGenerator randomGen1(redWhiteBlueStates[0]);
	RandomGenerator randomGen2(redWhiteBlueStates[0]);
	SMD5050LEDStrip stripOne (11,10,9);
	stripOne.setSequentialGenerator(randomGen1);
	SMD5050LEDStrip stripTwo (6, 5, 3);
	stripOne.setSequentialGenerator(randomGen2);
	SMD5050LEDStrip * strips[] = {&stripOne, &stripTwo};
	scheduler = Scheduler(*strips);
}

// The loop function is called in an endless loop
void loop() {
	scheduler.update();
}
