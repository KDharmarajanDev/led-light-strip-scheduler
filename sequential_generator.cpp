/*
 * sequential_generator.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "sequential_generator.h"
#include "led_state.h"
#include <Arduino.h>

SequentialGenerator::SequentialGenerator(){
	currentStateIndex = 0;
	endStateIndex = 0;
	states = {};
}

SequentialGenerator::SequentialGenerator(LEDState * statesInput){
	currentStateIndex = 0;
	endStateIndex = sizeof(statesInput)/sizeof(statesInput[0]);
	states = statesInput;
}

LEDState & SequentialGenerator::currState(){
	return states[currentStateIndex];
}

LEDState & SequentialGenerator::nextState(){
	if(currentStateIndex < endStateIndex){
		currentStateIndex++;
	} else {
		currentStateIndex = 0;
	}
	states[currentStateIndex].setStartTime(millis());
	return states[currentStateIndex];
}

void SequentialGenerator::addState(LEDState & stateInput){
	if(endStateIndex + 1 < maxStates){
		endStateIndex++;
		states[endStateIndex] = stateInput;
	}
}

LEDState * SequentialGenerator::getState(int index){
	return &states[index];
}

int SequentialGenerator::getEndStateIndex(){
	return endStateIndex;
}


