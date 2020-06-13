/*
 * color.h
 *
 *  Created on: Jun 3, 2020
 *      Author: karthikdharmarajan
 */
#ifndef COLOR_H_
#define COLOR_H_

class Color {
private:
    int red;
    int green;
    int blue;
public:
    Color(int red = 0, int green = 0, int blue = 0);
    const int getRed() const { return red; }
    const int getBlue() const { return blue; }
    const int getGreen() const  { return green; }
};


#endif /* COLOR_H_ */
