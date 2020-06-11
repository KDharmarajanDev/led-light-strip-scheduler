// Do not remove the include below
#include "led_strip_scheduler.h"
#include "scheduler.h"
#include "SMD5050LEDStrip.h"
#include "random_generator.h"
#include "led_state.h"
#include "transition_led_state.h"

Scheduler *scheduler;

void setup() {
	Serial.begin(9600);
	Serial.println("Starting LED Scheduler!");
	//First strip
	Color *redColor = new Color(255,0,0);
	LEDState *redState = new LEDState(*redColor, 5000);
	Color *blueColor = new Color(0,0,255);
	LEDState *blueState = new LEDState(*blueColor,5000);
	Color *whiteColor = new Color(255,255,255);
	LEDState *whiteState = new LEDState(*whiteColor,5000);
	LEDState **redWhiteBlueStates = new LEDState*[3];
	redWhiteBlueStates[0] = redState;
	redWhiteBlueStates[1] = blueState;
	redWhiteBlueStates[2] = whiteState;
	RandomGenerator *randomGen1 = new RandomGenerator(&redWhiteBlueStates[0], 3, 0);
	SMD5050LEDStrip *stripOne = new SMD5050LEDStrip(11,10,9);
	stripOne->setSequentialGenerator(randomGen1);

	//Second strip
	TransitionLEDState *transitionFromWhiteToBlue = new TransitionLEDState(*whiteColor, *blueColor, 5000);
	LEDState **redWhiteTransitionBlue = new LEDState*[3];
	redWhiteTransitionBlue[0] = redState;
	redWhiteTransitionBlue[1] = whiteState;
	redWhiteTransitionBlue[2] = transitionFromWhiteToBlue;
	RandomGenerator *randomGen2 = new RandomGenerator(&redWhiteTransitionBlue[0], 3, 0);
	SMD5050LEDStrip *stripTwo = new SMD5050LEDStrip(6, 5, 3);
	stripTwo->setSequentialGenerator(randomGen2);

	SMD5050LEDStrip **strips = new SMD5050LEDStrip*[2];
	strips[0] = stripOne;
	strips[1] = stripTwo;
	scheduler = new Scheduler(strips, 2);
}

void loop() {
	scheduler->update();
}
