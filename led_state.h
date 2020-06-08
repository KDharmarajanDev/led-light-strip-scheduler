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
	unsigned long startTime;

public:
	LEDState(Color& inputColor, unsigned long durationInput = 0);
	unsigned long getDuration(){
		return duration;
	}

	Color getColor(unsigned long currentTime){
		return *color;
	}

	void setStartTime(unsigned long startTimeInput);

	unsigned long getStartTime(){
		return startTime;
	}
};



#endif /* SCHEDULER_LED_STATE_H_ */
