/*
 * SMD5050LEDStrip.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include <Arduino.h>
#include "deserializer_handler.h"
#include "SMD5050LEDStrip.h"


SMD5050LEDStrip::SMD5050LEDStrip(int redPinInput, int greenPinInput, int bluePinInput, SequentialGenerator **generators, int numGenerators)
	: redPin(redPinInput), greenPin(greenPinInput), bluePin(bluePinInput), generators(generators)
	, currentGeneratorIndex(0), endGeneratorIndex(numGenerators-1){
	pinMode(redPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
}

void SMD5050LEDStrip::changeColor (const Color& color){
	analogWrite(redPin, color.getRed());
	analogWrite(bluePin, color.getBlue());
	analogWrite(greenPin, color.getGreen());
}

SequentialGenerator *SMD5050LEDStrip::getSequentialGenerator(){
	return generators[currentGeneratorIndex];
}

void SMD5050LEDStrip::moveAlongSequentialGenerator(int amount){
	if(currentGeneratorIndex+amount > endGeneratorIndex){
		currentGeneratorIndex = (amount - (endGeneratorIndex - currentGeneratorIndex) - 1) % (endGeneratorIndex + 1);
	} else {
		currentGeneratorIndex+=amount;
	}
}

int SMD5050LEDStrip::getRedPin(){
	return redPin;
}

int SMD5050LEDStrip::getBluePin(){
	return bluePin;
}

int SMD5050LEDStrip::getGreenPin(){
	return greenPin;
}

String SMD5050LEDStrip::serialize(){
	String answer = "[";
	answer+= redPin;
	answer+= ",";
	answer+= greenPin;
	answer+= ",";
	answer+= bluePin;
	for(int i = 0; i <= endGeneratorIndex; i++){
		answer+=",";
	    answer+=generators[i]->serialize();
	}
	answer+="]";
	return answer;
}

static SMD5050LEDStrip* SMD5050LEDStrip::deserialize(String &input, struct indices &bounds){
    if(input.length() >= 7){
        DeserializerHandler handler(input, bounds);
        int redPin = handler.getNextInteger();
        int greenPin = handler.getNextInteger();
        int bluePin = handler.getNextInteger();
        int counter = 0;
        struct indices newBounds = handler.getNextItemInBrackets();
        while(newBounds.start != newBounds.end){
            counter++;
            newBounds = handler.getNextItemInBrackets();
        }
        SequentialGenerator **generators = new SequentialGenerator*[counter];
        handler = DeserializerHandler(input, bounds);
        for(int i = 0; i < 3; i++){
        	handler.getNextInteger();
        }
        for(int i = 0; i < counter; i++){
        	struct indices internalBounds = handler.getNextItemInBrackets();
        	generators[i] = SequentialGenerator::deserialize(input, internalBounds);
        }
        return new SMD5050LEDStrip(redPin, greenPin, bluePin, generators, counter);
    }
    return new SMD5050LEDStrip(0,0,0,new SequentialGenerator*[1], 1);
}

SMD5050LEDStrip::~SMD5050LEDStrip(){
	for(int i = 0; i <= endGeneratorIndex; i++){
		if(generators[i] != nullptr){
			delete generators[i];
		}
	}
	delete[] generators;
}
