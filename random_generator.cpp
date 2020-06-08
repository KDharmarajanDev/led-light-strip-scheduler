/*
 * random_generator.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "random_generator.h"
#include "sequential_generator.h"
#include <Arduino.h>

LEDState * RandomGenerator::nextState(){
	int desiredIndex = random(0, SequentialGenerator::getEndStateIndex()+1);
	SequentialGenerator::getState(desiredIndex)->setStartTime(millis());
	return SequentialGenerator::getState(desiredIndex);
}
