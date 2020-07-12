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
	Color endColor;
	Color changeColor;
	Color currentColor;

public:
	TransitionLEDState(Color startColor, Color endColor, long durationTime) :
		LEDState(startColor, durationTime), endColor(endColor), currentColor(startColor){
			changeColor = Color(endColor.getRed() - startColor.getRed(),
				endColor.getGreen() - startColor.getGreen(),
				endColor.getBlue() - startColor.getBlue());
		};
	Color getColor(long currentTime = 0) override;
	String serialize() override;
};



#endif /* SCHEDULER_TRANSITION_LED_STATE_H_ */
