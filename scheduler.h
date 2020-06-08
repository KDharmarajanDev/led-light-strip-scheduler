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
	SMD5050LEDStrip * strips;
public:
	Scheduler(SMD5050LEDStrip * ledStrips);
	void update();
};


#endif /* SCHEDULER_SCHEDULER_H_ */
