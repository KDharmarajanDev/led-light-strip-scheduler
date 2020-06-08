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
    int getRed() { return red; }
    int getBlue() { return blue; }
    int getGreen()  { return green; }
};


#endif /* COLOR_H_ */
