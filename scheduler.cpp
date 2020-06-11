/*
 * scheduler.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(SMD5050LEDStrip **ledStrips, unsigned int numStripsInput) : strips(ledStrips), numStrips(numStripsInput){
}

void Scheduler::update(){
	unsigned long currentTime = millis();
	for(unsigned int i = 0; i < numStrips;i++){
		LEDState *currState = strips[i]->getSequentialGenerator()->currState();
		if(strips[i]->getSequentialGenerator()->getStartTime() + currState->getDuration() < currentTime){
			currState = strips[i]->getSequentialGenerator()->nextState();
		}
		Color color = currState->getColor(currentTime - strips[i]->getSequentialGenerator()->getStartTime());
		strips[i]->changeColor(color);
	}
}
