/*
 * scheduler.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(SMD5050LEDStrip **ledStrips, int numStripsInput) : strips(ledStrips), numStrips(numStripsInput){
}

void Scheduler::update(){
	unsigned long currentTime = millis();
	for(int i = 0; i < numStrips;i++){
		LEDState *currState = strips[i]->getSequentialGenerator()->currState();
		if(strips[i]->getSequentialGenerator()->getStartTime() + currState->getDuration() < currentTime){
			currState = strips[i]->getSequentialGenerator()->nextState();
		}
		Color color = currState->getColor(currentTime - strips[i]->getSequentialGenerator()->getStartTime());
		strips[i]->changeColor(color);
	}
}

SMD5050LEDStrip** Scheduler::getStrips(){
	return strips;
}

SMD5050LEDStrip* Scheduler::getStrip(int index){
	return strips[index];
}

int Scheduler::getNumStrips(){
	return numStrips;
}

Scheduler::Scheduler(const Scheduler& other){
	numStrips = other.numStrips;
	strips = new SMD5050LEDStrip*[numStrips];
	for(int i = 0; i < numStrips; i++){
		*strips[i] = *other.strips[i];
	}
}

void Scheduler::setStrips(SMD5050LEDStrip **stripsInput, int numberStrips){
	strips = stripsInput;
	numStrips = numberStrips;
}

Scheduler& Scheduler::operator=(const Scheduler& other){
	if(this != &other){
		destroy();
		numStrips = other.numStrips;
		strips = new SMD5050LEDStrip*[numStrips];
		for(int i = 0; i < numStrips; i++){
			*strips[i] = *other.strips[i];
		}
	}
	return *this;
}

void Scheduler::destroy(){
	for(int i = 0; i < numStrips; i++){
		delete strips[i];
	}
	delete[] strips;
}

Scheduler::~Scheduler(){
	destroy();
}
