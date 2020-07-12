/*
 * deserializer_handler.h
 *
 *  Created on: Jul 11, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_
#define ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_

#include <Arduino.h>

class DeserializerHandler {

private:
	String &serializedRepresentation;
	int currentIndex;

public:
	DeserializerHandler(String input) : serializedRepresentation(input), currentIndex(0){
	}

	int getNextInteger();
	String getNextItemInBrackets();

};



#endif /* ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_ */
