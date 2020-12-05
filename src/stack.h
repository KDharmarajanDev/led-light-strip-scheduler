/*
 * stack.h
 *
 *  Created on: Jul 11, 2020
 *      Author: karthikdharmarajan
 */

#ifndef STACK_H_
#define STACK_H_

template <typename T>
class Stack {

private:
	T* array;
	int sizeArray;
	int numElements;

public:
	Stack(){
		array = new T[1];
		numElements=0;
		sizeArray = 1;
	}

	void push(T item){
		if(numElements+1 >= sizeArray){
			T* temp = array;
			array = new T[sizeArray * 2];
			for(int i = 0; i < numElements; i++){
				array[i] = temp[i];
			}
			delete[] temp;
			sizeArray *= 2;
		}
		array[numElements] = item;
		numElements++;
	}

	T& peek(){
		return array[numElements-1];
	}

	T pop(){
		T answer = array[numElements-1];
		if(numElements-1 < sizeArray/2){
			T* temp = array;
			array = new T[sizeArray/2];
			for(int i = 0; i < sizeArray/2 - 1; i++){
				array[i] = temp[i];
			}
			delete[] temp;
			sizeArray /= 2;
		}
		numElements--;
		return answer;
	}

	int size(){
		return numElements;
	}

	~Stack(){
		delete[] array;
	}
};



#endif /* STACK_H_ */
