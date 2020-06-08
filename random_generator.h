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
	RandomGenerator(LEDState * statesInput) : SequentialGenerator(statesInput) {
	}
	LEDState * nextState();
};



#endif /* SCHEDULER_LED_STATE_GENERATORS_RANDOM_GENERATOR_H_ */
