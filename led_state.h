/*
 * led_state.h
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_LED_STATE_H_
#define SCHEDULER_LED_STATE_H_

#include "color.h"

class LEDState {
private:
	Color* color;
	unsigned long duration;

public:
	LEDState();

	LEDState(Color& inputColor, unsigned long durationInput = 0);
	unsigned long getDuration(){
		return duration;
	}

	virtual Color getColor(long currentTime=0){
		return *color;
	}

	virtual ~LEDState();
};



#endif /* SCHEDULER_LED_STATE_H_ */
