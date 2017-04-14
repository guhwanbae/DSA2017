/*
 * stack.h
 *
 *  Created on: 2017. 4. 4.
 *      Author: guhwan
 */

#ifndef HEADER_STACK_H_
#define HEADER_STACK_H_

#ifndef MAX_STACK_SIZE
#define MAX_STACK_SIZE 1024
#endif

#ifndef MAX_VALUE
#define MAX_VALUE 1000000
#endif

#ifndef NIL
#define NIL -1
#endif

#include <iostream>
using namespace std;

//This class is GenericType Stack.
template<typename T>
class Stack {
private :
	int cur;
	T* s;
public :
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(T value);
	T pop();
	T getTop();
	void traverse();
};

template<typename T>
Stack<T>::Stack() {
	cur = NIL;
	s = new T[MAX_STACK_SIZE];
	for(int i=0;i<MAX_STACK_SIZE;i++)
		s[i] = 0;
}

template<typename T>
Stack<T>::~Stack() {
	delete[] s;
}

template<typename T>
bool Stack<T>::isEmpty() {
	if(this->cur == NIL)
		return true;
	else
		return false;
}

template<typename T>
bool Stack<T>::isFull() {
	if(this->cur == MAX_STACK_SIZE-1)
		return true;
	else
		return false;
}

template<typename T>
T Stack<T>::getTop() {
	return this->s[cur];
}

template<typename T>
T Stack<T>::pop() {
	if(this->isEmpty() == false) {
		return this->s[cur--];
	}
	else {
		cout << "This Stack is Empty!" << endl;
		return (MAX_VALUE+1);
	}
}

template<typename T>
void Stack<T>::push(T data) {
	if(this->isFull() == false) {
		this->s[++cur] = data;
	}
	else {
		cout << "This Stack is Full!" << endl;
	}
}

template<typename T>
void Stack<T>::traverse() {
	for(int i=0; i<=this->cur; i++) {
		cout<< this->s[i] << "->";
	}
	cout << endl;
}

#endif /* HEADER_STACK_H_ */

