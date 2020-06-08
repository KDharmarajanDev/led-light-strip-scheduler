/*
 * led_state.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "led_state.h"

LEDState::LEDState(Color& inputColor, unsigned long durationInput){
	color = &inputColor;
	duration = durationInput;
	startTime = 0;
}

void LEDState::setStartTime(unsigned long startTimeInput){
	startTime = startTimeInput;
}


