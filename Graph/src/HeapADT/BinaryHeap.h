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

#ifndef NOT_A_VERTEX
#define NOT_A_VERTEX -1
#endif

#include "../GraphADT/GraphADT.h"
#include <stdio.h>

typedef double refType;

/* Generic Type Heap ADT */
template<typename T>
class BinaryHeap{
/* Reference of compare !! => keys[index]->getDistance()
 * getDistance return double type key!!
 * !If you want to change heap-order with a different Reference value,
 * change the getRef() function and the type of Reference value(typedef keyValType)!*/
private :
	T** keys;
	int heapSize;
	int curSize;

	refType getRefKey(T*);
	void percolateDown(int);
	void percolateUp(int);
	bool isFull();
	bool isEmpty();
	void initKeys();
	int findIndex(T*);
private :
	void swap(T*&,T*&);

public :
	BinaryHeap(int);
	~BinaryHeap();

	void Traverse();

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
	heapSize = newHeapSize + 1;
	curSize = SENTINEL_INDEX;
	keys = new T*[heapSize];
	keys[SENTINEL_INDEX] = SENTINEL;
	initKeys();
}
template<typename T>
BinaryHeap<T>::~BinaryHeap() {
	delete[] keys;
	keys = NULL;
}

template<typename T>
void BinaryHeap<T>::initKeys() {
	for(int index=0; index<heapSize; ++index) {
		keys[index] = NULL;
	}
}

template<typename T>
refType BinaryHeap<T>::getRefKey(T* element) {
	if(element == NULL) {
		return 0;
	}
	else {
		return element->getDistance();
	}
}

template<typename T>
int BinaryHeap<T>::findIndex(T* element) {
	for(int index=ROOT_INDEX; index<heapSize && keys[index]!=NULL; ++index) {
		if(element == keys[index]) {
			return index;
		}
	}
	return SENTINEL_INDEX;
}

template<typename T>
void BinaryHeap<T>::swap(T*& key1, T*& key2) {
	T* temp = key2;
	key2 = key1;
	key1 = temp;
}

template<typename T>
void BinaryHeap<T>::Traverse()  {
	printf("cur Size : %d\t",curSize);
	for(int index=ROOT_INDEX; index<=curSize; ++index) {
		printf("INDEX(%2d) RefKey : %2.1f -> ",index, getRefKey(keys[index]));
		printf("E(%2d,%2d)\n",keys[index]->getSourceID(),keys[index]->getVertexID());
	}
	printf("\n");
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
	int i = index;
	refType refKey = getRefKey(keys[index]);
	T* rootElement = keys[index];

	int child;
	for(; (i*2) <= curSize; i=child) {
		child = i * 2;
		if(child != curSize && getRefKey(keys[child]) > getRefKey(keys[child+1])) {
			++child;
		}
		if(refKey > getRefKey(keys[child])) {
			keys[i] = keys[child];
		}
		else
			break;
	}
	keys[i] = rootElement;
}
template<typename T>
void BinaryHeap<T>::percolateUp(int index) {
	int i = index;
	refType refKey = getRefKey(keys[index]);
	int parent;
	for(; (i/2) >= ROOT_INDEX; i=parent) {
		parent = i / 2;
		if(refKey < getRefKey(keys[parent])) {
			swap(keys[i],keys[parent]);
		}
		else
			break;
	}
}
template<typename T>
void BinaryHeap<T>::insert(T* element) {
	if(isFull()) {
		printf("#Error:Heap:HEAP is Full!\n");
		return; //HEAP FULL!
	}
	else {
		int index = ++curSize;
		while(getRefKey(keys[index/2]) > getRefKey(element)) {
			keys[index] = keys[index/2];
			index = index/2;
		}
		keys[index] = element;
	}
	//this->Traverse();
}
template<typename T>
T* BinaryHeap<T>::deleteMin() {
	if(isEmpty()) {
		//printf("#Error:Heap:HEAP is Empty!\n");
		return SENTINEL; //HEAP EMPTY!
	}
	T* rootElement = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateDown(ROOT_INDEX);

	return rootElement;
}
template<typename T>
T* BinaryHeap<T>::deleteMax() {
	if(isEmpty()) {
		return; //HEAP EMPTY!
	}

	T* rootElement = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateUp(ROOT_INDEX);

	keys[curSize+1] = rootElement;
	return rootElement;
}
template<typename T>
bool BinaryHeap<T>::isFull() {
	return (curSize >= (heapSize-1));
}
template<typename T>
bool BinaryHeap<T>::isEmpty() {
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

template<typename T>
void BinaryHeap<T>::decreaseKey(T* element) {
	int index = findIndex(element);
	if(index != SENTINEL_INDEX) {
		percolateUp(index);
	}
	else {
		insert(element);
	}
}

#endif /* SRC_HEAPADT_BINARYHEAP_H_ */
