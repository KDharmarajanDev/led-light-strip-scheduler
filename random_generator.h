/*
 * random_generator.h
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_LED_STATE_GENERATORS_RANDOM_GENERATOR_H_
#define SCHEDULER_LED_STATE_GENERATORS_RANDOM_GENERATOR_H_

#include "sequential_generator.h"
class RandomGenerator : public SequentialGenerator {
public:
	RandomGenerator() : SequentialGenerator{} {
	}
	RandomGenerator(LEDState **statesInput, int numLEDStates, int startTime = 0) : SequentialGenerator(statesInput, numLEDStates, startTime) {
	}
	LEDState *nextState() override;
};



#endif /* SCHEDULER_LED_STATE_GENERATORS_RANDOM_GENERATOR_H_ */
