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
	LEDState **states;
	int currentStateIndex;
	int endStateIndex;
	unsigned long lastStateStartTime;

public:
	SequentialGenerator();
	SequentialGenerator(LEDState **states, int numLEDStates, int startTime = 0);
	virtual LEDState *nextState();
	LEDState *currState();
	void addState(LEDState & state);
	LEDState *getState(int index);
	int getEndStateIndex();
	void setCurrentIndex(int index = 0);
	void setStartTime(unsigned long startTime);
	unsigned long getStartTime();
	virtual ~SequentialGenerator();
};



#endif /* SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_ */
