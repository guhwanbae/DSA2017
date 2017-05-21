/*
 * BinaryHeap.cpp
 *
 *  Created on: 2017. 4. 15.
 *      Author: guhwan
 */

#include <iostream>
#include <stdio.h>
#include "BinaryHeap.h"
using namespace std;

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF BINARY HEAP                     *
 ****************************************************************************/
BinaryHeap::BinaryHeap(int heapSize) {
	curSize = 0;
	keys = new int[heapSize];
	keys[curSize] = SENTINEL;
}

BinaryHeap::~BinaryHeap() {
	delete[] keys;
	keys = NULL;
}

void BinaryHeap::buildHeap(int* arr, int size) {
	curSize = size;
	for(int i=0; i<size; ++i) {
		keys[i+1] = arr[i];
	}
	for(int j=curSize/2; j>0; --j) {
		percolateUp(j);
	}
}

void BinaryHeap::percolateUp(int index) {
	int i = index;
	int refKey = keys[index];
	int child;
	for(; (i*2) <= curSize; i=child) {
		child = i * 2;
		if(child != curSize && keys[child] < keys[child+1]) {
			++child;
		}
		if(refKey < keys[child]) {
			keys[i] = keys[child];
		}
		else
			break;
	}
	keys[i] = refKey;
}

void BinaryHeap::deleteMax() {
	if(isEmpty()) {
		cout << "Empty Heap.." << endl;
		return;
	}

	int rootKey = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateUp(ROOT_INDEX);

	keys[curSize+1] = rootKey;
}

void BinaryHeap::getKeys(int* arr, int size) {
	for(int index=0;index < size; ++index) {

		arr[index] = keys[index+1];
	}
}

int BinaryHeap::isFull() {
	return (curSize >= HEAP_SIZE);
}

int BinaryHeap::isEmpty() {
	return (curSize == SENTINEL_INDEX);
}
