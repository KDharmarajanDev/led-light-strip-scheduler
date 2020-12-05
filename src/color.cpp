/*
 * color.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#include "color.h"
#include "deserializer_handler.h"

Color::Color (int redInput, int greenInput, int blueInput) : red(redInput), green(greenInput), blue(blueInput){
}

bool Color::operator==(const Color& other){
	return other.red == red && other.blue == blue && other.green == green;
}

static Color Color::deserialize(String &input, struct indices &bounds){
	DeserializerHandler handler(input, bounds);
	int redOutput = handler.getNextInteger();
	int greenOutput = handler.getNextInteger();
	int blueOutput = handler.getNextInteger();
	return Color(redOutput,greenOutput,blueOutput);
}

String Color::serialize(){
	String answer = "[";
	answer+=red;
	answer+=",";
	answer+=green;
	answer+=",";
	answer+=blue;
	answer+="]";
	return answer;
}


