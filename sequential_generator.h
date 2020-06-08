/*
 * sequential_generator.h
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_
#define SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_

#include "led_state.h"

class SequentialGenerator {
private:
	static const int maxStates = 20;
	LEDState * states;
	int currentStateIndex;
	int endStateIndex;

public:
	SequentialGenerator();
	SequentialGenerator(LEDState * states);
	LEDState & nextState();
	LEDState & currState();
	void addState(LEDState & state);
	LEDState * getState(int index);
	int getEndStateIndex();
};



#endif /* SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_ */
