/*
 * get_info_message.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: karthikdharmarajan
 */
#include "get_info_message.h"
#include "led_strip_scheduler.h"
#include "led_strip_info_message.h"

GetInfoMessage::GetInfoMessage(){

}

AndroidMessage* GetInfoMessage::deserialize(String &input){
	return new GetInfoMessage();
}

String GetInfoMessage::serialize(){
	return "GET";
}

void GetInfoMessage::handle(){
	LEDStripInfoMessage *message = new LEDStripInfoMessage(scheduler->getStrips(), scheduler->getNumStrips());
	handler->sendMessage(message);
	delete message;
}



