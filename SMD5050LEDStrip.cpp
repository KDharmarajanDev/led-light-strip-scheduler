/*
 * SMD5050LEDStrip.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "SMD5050LEDStrip.h"
#include <Arduino.h>
#include "sequential_generator.h"

SMD5050LEDStrip::SMD5050LEDStrip(int redPinInput, int bluePinInput, int greenPinInput){
	redPin = redPinInput;
	bluePin = bluePinInput;
	greenPin = greenPinInput;
	pinMode(redPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	generator = SequentialGenerator();
}

void SMD5050LEDStrip::changeColor (Color& color){
	analogWrite(redPin, color.getRed());
	analogWrite(bluePin, color.getBlue());
	analogWrite(greenPin, color.getGreen());
}

SequentialGenerator & SMD5050LEDStrip::getSequentialGenerator(){
	return generator;
}

void SMD5050LEDStrip::setSequentialGenerator(SequentialGenerator & generatorInput){
	generator = generatorInput;
}
