/*
 * deserializer_handler.h
 *
 *  Created on: Jul 11, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_
#define ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_

#include <Arduino.h>

struct indices {
	int start;
	int end;
};

extern struct indices example;

class DeserializerHandler {

private:
	String serializedRepresentation;
	int currentIndex;
	struct indices bounds;

public:
	DeserializerHandler(String &input, indices& bounds) : serializedRepresentation(input), currentIndex(bounds.start), bounds(bounds){
	}
	int getNextInteger();
	struct indices getNextItemInBrackets();
	bool isAtEnd();
};



#endif /* ANDROID_MESSAGES_DESERIALIZER_HANDLER_H_ */
