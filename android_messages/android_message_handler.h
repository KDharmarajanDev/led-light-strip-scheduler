/*
 * android_message_handler.h
 *
 *  Created on: Jun 8, 2020
 *      Author: karthikdharmarajan
 */

#ifndef ANDROID_MESSAGE_HANDLER_H_
#define ANDROID_MESSAGE_HANDLER_H_

#include "Arduino.h"

class AndroidMessageHandler{

private:
	int bluetoothRXPin;

public:
	AndroidMessageHandler(int bluetoothPin = 0);
};



#endif /* ANDROID_MESSAGE_HANDLER_H_ */
