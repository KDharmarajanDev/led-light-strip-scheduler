/*
 * android_message_handler.h
 *
 *  Created on: Jun 8, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGE_HANDLER_H_
#define ANDROID_MESSAGE_HANDLER_H_

#include "Arduino.h"
#include "android_message.h"

class AndroidMessageHandler{

public:
	AndroidMessageHandler();
	static void handleMessage(String &message);
};



#endif /* ANDROID_MESSAGE_HANDLER_H_ */
