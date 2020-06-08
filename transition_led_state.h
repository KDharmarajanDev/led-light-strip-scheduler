/*
 * transition_led_state.h
 *
 *  Created on: Jun 4, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_TRANSITION_LED_STATE_H_
#define SCHEDULER_TRANSITION_LED_STATE_H_

#include "led_state.h"

class TransitionLEDState : public LEDState {

private:
	Color & endColor;
	Color & changeColor;

public:
	TransitionLEDState(Color & startColor, Color & endColor, unsigned long durationTime) :
		LEDState{startColor, durationTime}, endColor{endColor}{
			changeColor = Color(endColor.getRed() - startColor.getRed(),
				endColor.getBlue() - startColor.getBlue(),
				endColor.getGreen() - startColor.getGreen());
		};
	Color getColor(unsigned long currentTime = 0);
};



#endif /* SCHEDULER_TRANSITION_LED_STATE_H_ */
