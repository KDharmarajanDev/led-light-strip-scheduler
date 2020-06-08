/*
 * transition_led_statee.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */
#include "transition_led_state.h"
#include "color.h"
#include <math.h>

Color TransitionLEDState::getColor(unsigned long currentTime){
	double multiplierRatio = currentTime / LEDState::getDuration();
	return Color(multiplierRatio * changeColor.getRed()
			,multiplierRatio * changeColor.getBlue()
			,multiplierRatio  * changeColor.getGreen());
}



