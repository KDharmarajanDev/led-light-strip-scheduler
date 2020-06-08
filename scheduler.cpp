/*
 * scheduler.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(SMD5050LEDStrip * ledStrips){
	strips = ledStrips;
}

void Scheduler::update(){
	unsigned long currentTime = millis();
	for(int i = 0; i < (signed) sizeof(strips)/(signed) sizeof(strips[0]);i++){
		LEDState& currState = strips[i].getSequentialGenerator().currState();
		if(currState.getStartTime() + currState.getDuration() > currentTime){
			currState = strips[i].getSequentialGenerator().nextState();
		}
		Color color = currState.getColor(currentTime - currState.getStartTime());
		strips[i].changeColor(color);
	}
}
