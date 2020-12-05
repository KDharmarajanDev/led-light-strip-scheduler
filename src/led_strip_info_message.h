/*
 * led_strip_info_message.h
 *
 *  Created on: Jul 10, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_
#define ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_

#include "android_message.h"
#include "SMD5050LEDStrip.h"

class LEDStripInfoMessage : public AndroidMessage {

	SMD5050LEDStrip** strips;
	int numStrips;

public:
	LEDStripInfoMessage(SMD5050LEDStrip** strips, int numStrips) : strips(strips), numStrips(numStrips){
	}
	LEDStripInfoMessage(){
		strips = nullptr;
		numStrips = 0;
	}
	AndroidMessage* deserialize(String &other) override;
	void handle() override;
	SMD5050LEDStrip** getStrips();
	String serialize() override;

};



#endif /* ANDROID_MESSAGES_LED_STRIP_INFO_MESSAGE_H_ */
