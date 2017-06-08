/*
 * BinaryHeap.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_HEAPADT_BINARYHEAP_H_
#define SRC_HEAPADT_BINARYHEAP_H_

#include <math.h>
#include <limits.h>

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
 * THE FUNTIONAL DECLARATIONS OF BINARY HEAP                      *
 ****************************************************************************/
#ifndef ROOT_INDEX
#define ROOT_INDEX 1
#endif

#ifndef SENTINEL_INDEX
#define SENTINEL_INDEX 0
#endif

#ifndef SENTINEL
#define SENTINEL NULL
#endif

#define HEAP_SIZE 1000

#include "../GraphADT/GraphADT.h"

/* Generic Type Heap ADT */
template<typename T>
class BinaryHeap{
private :
	T** keys;
	int curSize;
	T** maps;

	void percolateDown(int);
	void percolateUp(int);

	int isFull();
	int isEmpty();
public :
	BinaryHeap(int);
	~BinaryHeap();

	void buildHeap(T** ,int);
	void insert(T*);
	T* deleteMin();
	T* deleteMax();

	void decreaseKey(T*);

	T* getMin();
	int getCurSize();
};

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF BINARY HEAP                     *
 ****************************************************************************/
template<typename T>
BinaryHeap<T>::BinaryHeap(int newHeapSize) {
	curSize = SENTINEL_INDEX;
	keys = new T*[newHeapSize];
	keys[curSize] = SENTINEL;

	maps = new T*[newHeapSize];
}
template<typename T>
BinaryHeap<T>::~BinaryHeap() {
	delete[] keys;
	keys = NULL;
}
template<typename T>
void BinaryHeap<T>::buildHeap(T** arr, int size) {
	curSize = size;
	for(int i=0; i<size; ++i) {
		keys[i+1] = arr[i];
	}
	for(int j=curSize/2; j>0; --j) {
		percolateDown(j);
	}
}
template<typename T>
void BinaryHeap<T>::percolateDown(int index) {
	T* refKey = keys[index];
	int child;
	for(; (index*2) <= curSize; index=child) {
		child = index * 2;
		if(child != curSize && keys[child] > keys[child+1]) {
			++child;
		}
		if(refKey > keys[child]) {
			keys[index] = keys[child];
		}
		else
			break;
	}
	keys[index] = refKey;
}
template<typename T>
void BinaryHeap<T>::percolateUp(int index) {
	T* refKey = keys[index];
	int child;
	for(; (index*2) <= curSize; index=child) {
		child = index * 2;
		if(child != curSize && keys[child] < keys[child+1]) {
			++child;
		}
		if(refKey < keys[child]) {
			keys[index] = keys[child];
		}
		else
			break;
	}
	keys[index] = refKey;
}
template<typename T>
void BinaryHeap<T>::insert(T* keyVal) {
	if(isFull()) {
		return; //HEAP FULL!
	}
	else {
		int index = ++curSize;
		while(keys[index/2] > keyVal) {
			keys[index] = keys[index/2];
			index = index/2;
		}
		keys[index] = keyVal;
	}
}
template<typename T>
T* BinaryHeap<T>::deleteMin() {
	if(isEmpty()) {
		return SENTINEL; //HEAP EMPTY!
	}
	T* rootKey = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateDown(ROOT_INDEX);

	return rootKey;
}
template<typename T>
T* BinaryHeap<T>::deleteMax() {
	if(isEmpty()) {
		return; //HEAP EMPTY!
	}

	T* rootKey = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateUp(ROOT_INDEX);

	keys[curSize+1] = rootKey;
	return rootKey;
}
template<typename T>
int BinaryHeap<T>::isFull() {
	return (curSize >= HEAP_SIZE);
}
template<typename T>
int BinaryHeap<T>::isEmpty() {
	return (curSize == SENTINEL_INDEX);
}
template<typename T>
T* BinaryHeap<T>::getMin() {
	if(!isEmpty()) {
		return keys[ROOT_INDEX];
	}
	else
		return SENTINEL;
}
template<typename T>
int BinaryHeap<T>::getCurSize() {
	return curSize;
}
/*
template<typename T>
void decreaseKey(T key) {
	if (maps[key->getVertexID()] == NOT_A_VERTEX) {

	}
}
*/
#endif /* SRC_HEAPADT_BINARYHEAP_H_ */
