/*
 * scheduler.h
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */

#ifndef SCHEDULER_SCHEDULER_H_
#define SCHEDULER_SCHEDULER_H_

#include "SMD5050LEDStrip.h"

class Scheduler {
private:
	SMD5050LEDStrip **strips;
	unsigned int numStrips;
public:
	Scheduler(SMD5050LEDStrip **ledStrips, unsigned int numStripsInput = 1);
	void update();
};


#endif /* SCHEDULER_SCHEDULER_H_ */
