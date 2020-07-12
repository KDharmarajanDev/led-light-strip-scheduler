/*
 * led_state.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "led_state.h"
#include <Arduino.h>

LEDState::LEDState() : color(), duration(0){

}

LEDState::LEDState(Color inputColor, unsigned long durationInput) : color(inputColor), duration(durationInput){
}

LEDState::~LEDState(){

}

String LEDState::serialize(){
	String answer = "[";
	answer+=duration;
	answer+=",";
	answer+=color.serialize();
	answer+="]";
	return answer;
}

