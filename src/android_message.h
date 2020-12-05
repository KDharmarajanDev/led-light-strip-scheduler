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
public:
	AndroidMessage();
	virtual AndroidMessage* deserialize(String &other) = 0;
	virtual void handle() = 0;
	virtual String serialize() = 0;
	virtual ~AndroidMessage();
};

#endif /* ANDROID_MESSAGES_ANDROID_MESSAGE_H_ */
