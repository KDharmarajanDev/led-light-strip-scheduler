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
	int numStrips;
public:
	Scheduler(SMD5050LEDStrip **ledStrips, int numStripsInput = 1);
	void update();
	SMD5050LEDStrip *getStrip(int index);
	SMD5050LEDStrip **getStrips();
	int getNumStrips();
	Scheduler(const Scheduler& other);
	Scheduler& operator=(const Scheduler& other);
	void setStrips(SMD5050LEDStrip **strips, int numberStrips);
	void destroy();
	~Scheduler();
};


#endif /* SCHEDULER_SCHEDULER_H_ */
