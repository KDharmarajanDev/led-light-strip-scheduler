/*
 * color.h
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#ifndef COLOR_H_
#define COLOR_H_

#include <Arduino.h>
#include "deserializer_handler.h"

class Color {
private:
    int red;
    int green;
    int blue;
public:
    Color(int red = 0, int green = 0, int blue = 0);
    int getRed() const { return red; }
    int getBlue() const { return blue; }
    int getGreen() const  { return green; }
    bool operator==(const Color& other);
    static Color deserialize(String &input, struct indices &bounds);
    String serialize();
};


#endif /* COLOR_H_ */
