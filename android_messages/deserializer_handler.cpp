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
    while(currentIndex < serializedRepresentation.length()){
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

String DeserializerHandler::getNextItemInBrackets(){
    String answer = "";
    Stack<char> brackets;
    while(currentIndex < serializedRepresentation.length()){
        if(serializedRepresentation.charAt(currentIndex) == '['){
            answer +='[';
            brackets.push('[');
        } else if(serializedRepresentation.charAt(currentIndex) == ']' && brackets.size() > 0 && brackets.peek() == '['){
            brackets.pop();
            answer+=']';
            if(brackets.size() == 0){
                currentIndex++;
                break;
            }
        } else if (brackets.size() > 0){
            answer+=serializedRepresentation.charAt(currentIndex);
        }
        currentIndex++;
    }
    return answer;
}
