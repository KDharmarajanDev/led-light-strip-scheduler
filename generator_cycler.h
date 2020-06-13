/*
 * generator_cycler.h
 *
 *  Created on: Jun 12, 2020
 *      Author: karthikdharmarajan
 */

#ifndef GENERATOR_CYCLER_H_
#define GENERATOR_CYCLER_H_

#include "advanced_button.h"
#include "SMD5050LEDStrip.h"

class GeneratorCycler {

private:
	AdvancedButton button;
	SMD5050LEDStrip **strips;
	int numStrips;
	int selectedStrip;

public:
	GeneratorCycler(int buttonPin, SMD5050LEDStrip **strips, int numStrips);
	void update();
};



#endif /* GENERATOR_CYCLER_H_ */
