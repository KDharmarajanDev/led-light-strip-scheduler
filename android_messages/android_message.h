/*
 * android_message.h
 *
 *  Created on: Jun 8, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_ANDROID_MESSAGE_H_
#define ANDROID_MESSAGES_ANDROID_MESSAGE_H_

#include "Arduino.h"

class AndroidMessage {

private:
	String message;

public:
	AndroidMessage(String inputMessage);
	String & getMessage();
	virtual void deserialize(AndroidMessage &other) = 0;
	virtual ~AndroidMessage();
	enum MessageType {
		ADD, DELETE, SWITCH, GET_GENERATORS, GET_LED_STRIPS
	};
};

#endif /* ANDROID_MESSAGES_ANDROID_MESSAGE_H_ */
