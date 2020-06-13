/*
 * advanced_button.cpp
 *
 *  Created on: Jun 11, 2020
 *      Author: karthikdharmarajan
 */

#include "advanced_button.h"
#include <Arduino.h>

AdvancedButton::AdvancedButton(int buttonPin) : buttonPin(buttonPin), consecutivePressCount(0), prevConsecutivePressCount(0),
	lastButtonPressTime(millis()), finishedLastButtonPress(true){
	pinMode(buttonPin, INPUT);
}

int AdvancedButton::getNumPresses(){
	int temp = prevConsecutivePressCount;
	prevConsecutivePressCount = 0;
	return temp;
}

void AdvancedButton::update(){
	int buttonRead = digitalRead(buttonPin);
	if(buttonRead == HIGH){
		if(finishedLastButtonPress){
			finishedLastButtonPress = false;
			consecutivePressCount++;
		}
	} else {
		unsigned long currentTime = millis();
		if(!finishedLastButtonPress){
			lastButtonPressTime = currentTime;
			finishedLastButtonPress = true;
		}
		if(currentTime > lastButtonPressTime + maxConsecutiveButtonDelay){
			if(consecutivePressCount != 0){
				prevConsecutivePressCount = consecutivePressCount;
			}
			consecutivePressCount = 0;
		}
	}
}
