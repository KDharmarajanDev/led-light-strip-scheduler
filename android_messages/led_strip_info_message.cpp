/*
 * led_strip_info_message.cpp
 *
 *  Created on: Jul 10, 2020
 *      Author: karthikdharmarajan
 */
#include "led_strip_info_message.h"
#include "SMD5050LEDStrip.h"
#include "deserializer_handler.h"
#include "led_strip_scheduler.h"

AndroidMessage* LEDStripInfoMessage::deserialize(String &other) {
	struct indices bounds;
	bounds.start = 0;
	bounds.end = other.length()-1;
	DeserializerHandler handler(other, bounds);
	int counter = 0;
	struct indices ledStripString = handler.getNextItemInBrackets();
	while (ledStripString.start != ledStripString.end) {
		counter++;
		ledStripString = handler.getNextItemInBrackets();
	}
	SMD5050LEDStrip **strips = new SMD5050LEDStrip*[counter];
	handler = DeserializerHandler(other,bounds);
	for (int i = 0; i < counter; i++) {
		struct indices item = handler.getNextItemInBrackets();
		strips[i] = SMD5050LEDStrip::deserialize(other,item);
	}
	return new LEDStripInfoMessage(strips, counter);
}

void LEDStripInfoMessage::handle(){
	scheduler->setStrips(strips, numStrips);
	cycler->setStrips(strips, numStrips);
}

SMD5050LEDStrip** LEDStripInfoMessage::getStrips() {
	return strips;
}

String LEDStripInfoMessage::serialize(){
	String returnString = "SET ";
	for(int i = 0; i < numStrips; i++){
		returnString += strips[i]->serialize();
		if(i < numStrips-1){
			returnString +=",";
		}
	}
	return returnString;
}

