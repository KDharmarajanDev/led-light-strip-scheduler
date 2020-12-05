/*
 * transition_led_statee.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "transition_led_state.h"
#include "color.h"
#include <math.h>
#include <Arduino.h>

Color TransitionLEDState::getColor(long currentTime){
	double multiplierRatio = ((double) currentTime)/LEDState::getDuration();
	currentColor = Color(floor(LEDState::getColor().getRed() + multiplierRatio * changeColor.getRed())
			,floor(LEDState::getColor().getGreen() + multiplierRatio * changeColor.getGreen())
			,floor(LEDState::getColor().getBlue() +multiplierRatio  * changeColor.getBlue()));
	return currentColor;
}

String TransitionLEDState::serialize(){
	String answer = "[";
	answer+=LEDState::getDuration();
	answer+=",";
	answer+=LEDState::getColor(0).serialize();
	answer+=",";
	answer+=endColor.serialize();
	answer+="]";
    return answer;
}


