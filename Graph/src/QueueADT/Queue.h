/*
 * queue.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FAIL
#define FAIL 0
#endif

#ifndef NULL
#define NULL 0
#endif

#define MAX_VALUE	10000

#include <iostream>
using namespace std;

template<typename T>
class Queue {
private :
	int rare;
	int front;
	int qSize;
	T** Q;
public :
	Queue(int);
	~Queue();

	int isEmpty();
	int isFull();

	int enQueue(T*);
	T* deQueue();

	void printQueue();
};

template <typename T>
Queue<T>::Queue(int newSize) {
	rare = 0;
	front = 0;
	qSize = newSize;

	Q = new T*[qSize];

	for(int i=0; i<qSize; ++i) {
		Q[i]=0;
	}
}

template <typename T>
Queue<T>::~Queue() {
	delete[] Q;
	Q = NULL;
}

template <typename T>
T* Queue<T>::deQueue() {
	if(isEmpty()) {
		cout << "Error:Queue:Dequeue:Queue is Empty!" << endl;
		return Q[0]; //return error value
	}

	T* temp = Q[front];
	front = (front+1) % qSize;
	return temp; //return not max_value+1 -> success!
}

template <typename T>
int Queue<T>::enQueue(T* element) {
	if(isFull()) {
		return FAIL;
	}

	Q[(rare++) % (qSize)] = element;
	return TRUE;
}

template <typename T>
int Queue<T>::isEmpty() {
	if(front == rare)
		return true;

	return false;
}

template <typename T>
int Queue<T>::isFull() {
	int state = (qSize+1) - front + rare;
	if(state == qSize)
		return true;

	return false;
}

template <typename T>
void Queue<T>::printQueue() {
	//print from front to rare
	for(int i = front;i != rare; ((i++) % (qSize))) {
		cout << Q[i] << " -> ";
	}
	cout << endl;
}

#endif /* SRC_QUEUE_H_ */
