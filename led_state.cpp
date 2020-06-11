/*
 * led_state.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "led_state.h"

LEDState::LEDState() : color(nullptr), duration(0){

}

LEDState::LEDState(Color& inputColor, unsigned long durationInput) : color(&inputColor), duration(durationInput){
}

LEDState::~LEDState(){

}


