/*
 * sequential_generator.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "sequential_generator.h"
#include "random_generator.h"
#include "led_state.h"
#include <Arduino.h>
#include "deserializer_handler.h"

typedef struct indicies indicies;

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

String SequentialGenerator::serialize(){
	String answer = "[0";
	for(int i = 0; i <= endStateIndex; i++){
		answer+=",";
		answer+=states[i]->serialize();
	}
	answer+="]";
	return answer;
}

SequentialGenerator::SequentialGenerator(const SequentialGenerator& other){
	lastStateStartTime = other.lastStateStartTime;
	currentStateIndex = other.currentStateIndex;
	endStateIndex = other.endStateIndex;
	states = new LEDState*[endStateIndex+1];
	for(int i = 0; i < endStateIndex+1; i++){
		*states[i] = *other.states[i];
	}
}

SequentialGenerator& SequentialGenerator::operator=(const SequentialGenerator& other){
	if(this != &other){
		lastStateStartTime = other.lastStateStartTime;
		currentStateIndex = other.currentStateIndex;
		endStateIndex = other.endStateIndex;
		destroy();
		states = new LEDState*[endStateIndex+1];
		for(int i = 0; i < endStateIndex+1; i++){
			states[i] = new LEDState();
			*states[i] = *other.states[i];
		}
	}
	return *this;
}

void SequentialGenerator::destroy(){
	for(int i = 0; i < endStateIndex+1; i++){
		if(states[i] != nullptr){
			delete states[i];
		}
	}
	delete[] states;
}

static SequentialGenerator* SequentialGenerator::deserialize(String &input, struct indices &bounds){
    if(input.length() >= 3){
        DeserializerHandler handler(input, bounds);
        int type = handler.getNextInteger();
        int counter = 0;
        struct indices newBracketBounds = handler.getNextItemInBrackets();
        while(newBracketBounds.end != newBracketBounds.start){
            counter++;
            newBracketBounds = handler.getNextItemInBrackets();
        }
        LEDState **ledStates = new LEDState*[counter];
        handler = DeserializerHandler(input, bounds);
        handler.getNextInteger();
        for(int i = 0; i < counter; i++){
        	struct indices bracketBounds = handler.getNextItemInBrackets();
        	ledStates[i] = LEDState::deserialize(input,bracketBounds);
        }
        if(type == 0){
            return new SequentialGenerator(ledStates, counter);
        } else {
            return new RandomGenerator(ledStates, counter);
        }
    }
    return new SequentialGenerator();
}

SequentialGenerator::~SequentialGenerator(){
	destroy();
}



