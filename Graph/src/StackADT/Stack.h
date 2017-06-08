/*
 * stack.h
 *
 * Created on: 2017. 4. 4.
 * Author: guhwan
 */

#ifndef HEADER_STACK_H_
#define HEADER_STACK_H_

#ifndef MAX_VALUE
#define MAX_VALUE 1000000
#endif

#ifndef NIL
#define NIL -1
#endif

#include <stdio.h>
using namespace std;

//This class is GenericType Stack.
template<typename T>
class Stack {
private:
	T* s;
	int size;
	int cur;
public:
	Stack(int);
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(T);
	T pop();
	T getTop();
	void clearStack();
};

template<typename T>
Stack<T>::Stack(int newSize) {
	cur = NIL;
	size = newSize;
	s = new T[size];
	for (int index = 0; index < size; index++) {
		s[index] = 0;
	}
}

template<typename T>
Stack<T>::~Stack() {
	delete[] s;
	s = NULL;
}

template<typename T>
bool Stack<T>::isEmpty() {
	return (cur == NIL);
}

template<typename T>
bool Stack<T>::isFull() {
	return (cur == size - 1);
}

template<typename T>
T Stack<T>::getTop() {
	return s[cur];
}

template<typename T>
T Stack<T>::pop() {
	if (isEmpty() == false) {
		return s[cur--];
	} else {
		printf("Error:Stack:This Stack is Empty!\n");
		return (MAX_VALUE + 1);
	}
}

template<typename T>
void Stack<T>::push(T keyVal) {
	if (isFull() == false) {
		s[++cur] = keyVal;
	} else {
		printf("Error:Stack:This Stack is Full!\n");
	}
}

template<typename T>
void Stack<T>::clearStack() {
	cur = NIL;
	for(int index=0; index<size; ++index) {
		s[index] = 0;
	}
}

#endif /* HEADER_STACK_H_ */
