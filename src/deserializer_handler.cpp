/*
 * deserializer_handler.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: karthikdharmarajan
 */
#include "deserializer_handler.h"
#include "stack.h"



int DeserializerHandler::getNextInteger(){
    boolean hasStarted = false;
    String stringRepresentation = "";
    while(currentIndex <= bounds.end){
        char currentChar = serializedRepresentation.charAt(currentIndex);
        if(currentChar != '[' && currentChar != ']' && currentChar != ','){
            if(!hasStarted){
                hasStarted=true;
            }
            stringRepresentation+=currentChar;
        } else if(hasStarted){
            break;
        }
        currentIndex++;
    }
    return stringRepresentation.length() != 0 ? stringRepresentation.toInt() : 0;
}

struct indices DeserializerHandler::getNextItemInBrackets(){
	struct indices answer;
	answer.start = currentIndex;
	answer.end = currentIndex;
    Stack<char> brackets;
    bool firstOne = true;
    while(currentIndex <= bounds.end){
        if(serializedRepresentation.charAt(currentIndex) == '['){
            brackets.push('[');
            if(firstOne){
            	answer.start = currentIndex;
            	firstOne = false;
            } else {
            	answer.end++;
            }
        } else if(serializedRepresentation.charAt(currentIndex) == ']' && brackets.size() > 0 && brackets.peek() == '['){
            brackets.pop();
            answer.end++;
            if(brackets.size() == 0){
                currentIndex++;
                break;
            }
        } else if (brackets.size() > 0){
        	answer.end++;
        }
        currentIndex++;
    }

    return answer;
}

bool DeserializerHandler::isAtEnd(){
	return currentIndex >= serializedRepresentation.length()-1;
}
