/*
 * random_generator.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "random_generator.h"
#include "sequential_generator.h"
#include <Arduino.h>

LEDState *RandomGenerator::nextState(){
	int desiredIndex = random(0, SequentialGenerator::getEndStateIndex()+1);
	SequentialGenerator::setStartTime((unsigned long)millis());
	SequentialGenerator::setCurrentIndex(desiredIndex);
	return SequentialGenerator::getState(desiredIndex);
}

String RandomGenerator::serialize(){
	String answer = "[1";
	for(int i = 0; i <= SequentialGenerator::getEndStateIndex(); i++){
		answer+=",";
		answer+=SequentialGenerator::getState(i)->serialize();
	}
	answer+="]";
	return answer;
}

