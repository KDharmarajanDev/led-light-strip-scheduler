/*
 * sequential_generator.h
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_
#define SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_

#define maxStates 20
#include "led_state.h"
#include <Arduino.h>
#include "deserializer_handler.h"

class SequentialGenerator {
private:
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
	SequentialGenerator(const SequentialGenerator& other);
	SequentialGenerator& operator=(const SequentialGenerator& other);
	void destroy();
	static SequentialGenerator* deserialize(String &input, struct indices &bounds);
	virtual ~SequentialGenerator();
	virtual String serialize();
};



#endif /* SCHEDULER_LED_STATE_GENERATORS_SEQUENTIAL_GENERATOR_H_ */
