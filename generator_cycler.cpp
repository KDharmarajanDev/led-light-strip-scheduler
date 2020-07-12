/*
 * generator_cycler.cpp
 *
 *  Created on: Jun 12, 2020
 *      Author: karthikdharmarajan
 */
#include "generator_cycler.h"
#include "advanced_button.h"
#include <Arduino.h>

GeneratorCycler::GeneratorCycler(int buttonPin, SMD5050LEDStrip **strips, int numStrips) : strips(strips)
	, numStrips(numStrips), selectedStrip(0), button(buttonPin){
}

void GeneratorCycler::update(){
	button.update();
	int buttonRead = button.getNumPresses();
	if(buttonRead != 0){
		if(selectedStrip >= 0){
			strips[selectedStrip]->moveAlongSequentialGenerator(buttonRead);
			selectedStrip = -1;
		} else {
			if(buttonRead > numStrips){
				selectedStrip = numStrips-1;
			} else {
				selectedStrip = buttonRead-1;
			}
		}
	}
}

GeneratorCycler::~GeneratorCycler(){
	if(strips != nullptr){
		for(int i = 0; i < numStrips; i++){
			if(strips[i] != nullptr){
				delete strips[i];
			}
		}
		delete[] strips;
	}
}


