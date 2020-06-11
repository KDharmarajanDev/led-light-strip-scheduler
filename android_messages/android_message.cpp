/*
 * android_message.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: karthikdharmarajan
 */
#include "android_message.h"

AndroidMessage::AndroidMessage(String inputMessage) : message(inputMessage){
}

String & AndroidMessage::getMessage(){
	return message;
}
