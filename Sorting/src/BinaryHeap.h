/*
 * BinaryHeap.h
 *
 *  Created on: 2017. 4. 15.
 *      Author: guhwan
 */

#ifndef SRC_BINARYHEAP_H_
#define SRC_BINARYHEAP_H_

/****************************************************************************
 * MACROS FOR FILE I/O RULES                                       *
 ****************************************************************************/
#define MAX_SIZE	10000
#define MAX_LINE	100000
#define MAX_VALUE	10000

/****************************************************************************
 * MACROS FOR THE RULES OF LOGICAL DECISIONS                      *
 ****************************************************************************/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL	0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef FAILURE
#define FAILURE 0
#endif

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF BINARY HEAP                       *
 ****************************************************************************/
#ifndef ROOT_INDEX
#define ROOT_INDEX 1
#endif

#ifndef SENTINEL_INDEX
#define SENTINEL_INDEX 0
#endif

#define SENTINEL -sizeof(int)
#define HEAP_SIZE 1000

#include <math.h>

class BinaryHeap{
private :
	int* keys;
	int curSize;
public :
	BinaryHeap(int);
	~BinaryHeap();

	void buildHeap(int* ,int);

	void percolateUp(int);

	void deleteMax();

	int isFull();
	int isEmpty();

	void getKeys(int*,int);
};

#endif /* SRC_BINARYHEAP_H_ */
