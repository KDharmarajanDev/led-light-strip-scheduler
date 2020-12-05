/*
 * android_message_handler.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: karthikdharmarajan
 */
#include "android_message_handler.h"
#include "android_message.h"
#include "led_strip_info_message.h"
#include "led_strip_scheduler.h"
#include "get_info_message.h"
#include <Arduino.h>

AndroidMessageHandler::AndroidMessageHandler(){
}

static void AndroidMessageHandler::handleMessage(String &message){
	int index = message.indexOf(' ');
	if(index == -1){
		index = message.length();
	}
	String typeMessage = message.substring(0,index);
	AndroidMessage *androidMessage;
	if(typeMessage.equals("SET")){
		scheduler->destroy();
		androidMessage = LEDStripInfoMessage().deserialize(message);
	} else if(typeMessage.equals("GET")){
		androidMessage = new GetInfoMessage();
	} else {
		return;
	}
	androidMessage->handle();
	delete androidMessage;
}

void AndroidMessageHandler::sendMessage(AndroidMessage *message){
	Serial.println(message->serialize());
}

