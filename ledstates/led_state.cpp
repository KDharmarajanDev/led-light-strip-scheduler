/*
 * led_state.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "led_state.h"
#include <Arduino.h>
#include "deserializer_handler.h"
#include "transition_led_state.h"

LEDState::LEDState() : color(), duration(0){

}

LEDState::LEDState(Color inputColor, unsigned long durationInput) : color(inputColor), duration(durationInput){
}

LEDState::~LEDState(){
}

static LEDState* LEDState::deserialize(String &input, struct indices &bounds){
    if(input.length() >= 11){
        DeserializerHandler handler(input, bounds);
        long duration = handler.getNextInteger();
        struct indices startBounds = handler.getNextItemInBrackets();
        Color startColor = Color::deserialize(input, startBounds);
        struct indices possibleEndColor = handler.getNextItemInBrackets();
        if(possibleEndColor.start != possibleEndColor.end){
            return new TransitionLEDState(startColor, Color::deserialize(input, possibleEndColor), duration);
        } else {
            return new LEDState(startColor, duration);
        }
    }
    return new LEDState();
}

String LEDState::serialize(){
	String answer = "[";
	answer+=duration;
	answer+=",";
	answer+=color.serialize();
	answer+="]";
	return answer;
}

