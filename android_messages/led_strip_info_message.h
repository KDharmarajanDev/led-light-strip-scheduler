/*
 * led_strip_info_message.h
 *
 *  Created on: Jul 10, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_
#define ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_

#include "android_message.h"

class LEDStripInfoMessage : public AndroidMessage {

public:
	LEDStripInfoMessage(String &message) : AndroidMessage(message){
	}

	LEDStripInfoMessage* deserialize(String& other) override;
	void handle() override;

};



#endif /* ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_ */
