/*
 * Queue.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: guhwan
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FAIL
#define FAIL 0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef NULL
#define NULL 0
#endif

#define QUEUE_SIZE	1000
#define MAX_LINE	2048
#define MAX_VALUE	10000

#include <stdio.h>

class Queue {
private :
	int rare;
	int front;
	int* Q;

public :
	Queue();
	~Queue();

	int isEmpty();
	int isFull();

	int enQueue(int, FILE*);
	int deQueue(FILE*);

	void printQueue(FILE*);
};



#endif /* SRC_QUEUE_H_ */
