/*
 * SMD5050LEDStrip.h
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */

#ifndef LED_STRIPS_AND_COLORS_SMD5050LEDSTRIP_H_
#define LED_STRIPS_AND_COLORS_SMD5050LEDSTRIP_H_

#include "color.h"
#include "led_state.h"
#include "sequential_generator.h"

class SMD5050LEDStrip {

private:
	int redPin;
	int bluePin;
	int greenPin;
	SequentialGenerator *generator;


public:
	SMD5050LEDStrip(int redPinInput = 0, int bluePinInput = 0, int greenPinInput = 0);
	void changeColor(Color& color);
	SequentialGenerator *getSequentialGenerator();
	void setSequentialGenerator(SequentialGenerator *generatorInput);
};


#endif /* LED_STRIPS_AND_COLORS_SMD5050LEDSTRIP_H_ */
