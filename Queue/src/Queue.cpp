/*
 * Queue.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: guhwan
 */

#include "Queue.h"
#include <iostream>
#include <stdio.h>

using namespace std;

Queue::Queue() {
	rare = 0;
	front = 0;
	Q = new int[QUEUE_SIZE];
	for(int i=0; i<QUEUE_SIZE; ++i)	Q[i]=0;
}

Queue::~Queue() {
	delete[] Q;
}

int Queue::deQueue(FILE* fp) {
	if(isEmpty() == TRUE) {
		fprintf(fp, "Queue EMPTY\n");
		return (MAX_VALUE + 1); //return error value
	}

	int temp = front;
	front = (front+1) % (QUEUE_SIZE);
	return Q[temp]; //return not max_value+1 -> success!
}

int Queue::enQueue(int data, FILE* fp) {
	if(isFull() == TRUE) {
		fprintf(fp, "Queue FULL\n");
		return FAIL;
	}
	Q[(rare++) % (QUEUE_SIZE)] = data;
	return TRUE;
}

int Queue::isEmpty() {
	if(front == rare)
		return true;

	return false;
}

int Queue::isFull() {
	int state = (QUEUE_SIZE+1) - front + rare;
	if(state == QUEUE_SIZE)
		return true;

	return false;
}

void Queue::printQueue(FILE* fp) {
	//print from front to rare
	for(int i = front;i != rare; ((i++) % (QUEUE_SIZE))) {
		fprintf(fp, "%d", Q[i]);
		if(((i+1) % (QUEUE_SIZE)) != rare)
			fprintf(fp," ");
	}
	fprintf(fp,"\n");
	/*
	//print from rare to front(backward)
	for(int i = rare ;i != front; --i) {
		if(i < 1)
			i = QUEUE_SIZE;
		cout << Q[i-1] << "->";
	}
	cout << endl;
	*/
}
