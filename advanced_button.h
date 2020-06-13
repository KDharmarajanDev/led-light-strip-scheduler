/*
 * advanced_button.h
 *
 *  Created on: Jun 11, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ADVANCED_BUTTON_H_
#define ADVANCED_BUTTON_H_

class AdvancedButton {

private:
	int buttonPin;
	int consecutivePressCount;
	int prevConsecutivePressCount;
	unsigned long lastButtonPressTime;
	bool finishedLastButtonPress;
	static const long maxConsecutiveButtonDelay = 1000;

public:
	AdvancedButton(int buttonPin=0);
	int getNumPresses();
	void update();
};



#endif /* ADVANCED_BUTTON_H_ */
