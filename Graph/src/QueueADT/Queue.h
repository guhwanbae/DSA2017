/*
 * queue.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#ifndef NULL
#define NULL 0
#endif

#include <iostream>
using namespace std;

#ifndef Q_DUMMY_SIZE
#define Q_DUMMY_SIZE 1
#endif

template<typename T>
class Queue {
private :
	int rear;
	int front;
	int qSize;
	T** Q;
public :
	Queue(int);
	~Queue();

	bool isEmpty();
	bool isFull();

	bool enQueue(T*);
	T* deQueue();

	void printQueue();
};

template <typename T>
Queue<T>::Queue(int newSize) {
	rear = 0;
	front = 0;
	qSize = newSize+Q_DUMMY_SIZE;

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
	else {
		front = (front+1) % (qSize);
		return Q[front]; //return not max_value+1 -> success!
	}
}

template <typename T>
bool Queue<T>::enQueue(T* element) {
	if(isFull()) {
		return false;
	}
	else {
		rear = (rear+1) % (qSize);
		Q[rear] = element;
		return true;
	}
}

template <typename T>
bool Queue<T>::isEmpty() {
	return (front == rear);
}

template <typename T>
bool Queue<T>::isFull() {
	return ((rear+1)%(qSize) == front);
}

template <typename T>
void Queue<T>::printQueue() {
	//print from front to rear
	for(int i = front;i != rear; ((i++) % (qSize))) {
		cout << Q[i] << " -> ";
	}
	cout << endl;
}

#endif /* SRC_QUEUE_H_ */
