/*
 * get_info_message.h
 *
 *  Created on: Jul 12, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_GET_INFO_MESSAGE_H_
#define ANDROID_MESSAGES_GET_INFO_MESSAGE_H_

#include "android_message.h"

class GetInfoMessage : public AndroidMessage {

public:
	GetInfoMessage();
	AndroidMessage* deserialize(String &input) override;
	String serialize() override;
	void handle() override;
};


#endif /* ANDROID_MESSAGES_GET_INFO_MESSAGE_H_ */
