/*
 * sequential_generator.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "sequential_generator.h"
#include "led_state.h"
#include <Arduino.h>

SequentialGenerator::SequentialGenerator() : currentStateIndex(0), endStateIndex(0), states(), lastStateStartTime(0){
}

SequentialGenerator::SequentialGenerator(LEDState **statesInput, int numLEDStates, int startTime) : currentStateIndex(0), endStateIndex(numLEDStates-1), states(statesInput), lastStateStartTime(startTime){
}

LEDState *SequentialGenerator::currState(){
	return states[currentStateIndex];
}

LEDState *SequentialGenerator::nextState(){
	if(currentStateIndex < endStateIndex){
		currentStateIndex++;
	} else {
		currentStateIndex = 0;
	}
	setStartTime((unsigned long)millis());
	return states[currentStateIndex];
}

void SequentialGenerator::addState(LEDState & stateInput){
	if(endStateIndex + 1 < maxStates){
		endStateIndex++;
		states[endStateIndex] = &stateInput;
	}
}

LEDState *SequentialGenerator::getState(int index){
	return states[index];
}

int SequentialGenerator::getEndStateIndex(){
	return endStateIndex;
}

void SequentialGenerator::setCurrentIndex(int index){
	currentStateIndex = index;
}

void SequentialGenerator::setStartTime(unsigned long startTime){
	lastStateStartTime = startTime;
}

unsigned long SequentialGenerator::getStartTime(){
	return lastStateStartTime;
}

SequentialGenerator::~SequentialGenerator(){
}


