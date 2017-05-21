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
BinaryHeap::BinaryHeap() {
	curSize = 0;
	keys = new int[HEAP_SIZE];
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
		percolateDown(j);
	}
}

void BinaryHeap::percolateDown(int index) {
	int i = index;
	int refKey = keys[index];
	int child;
	for(; (i*2) <= curSize; i=child) {
		child = i * 2;
		if(child != curSize && keys[child] > keys[child+1]) {
			++child;
		}
		if(refKey > keys[child]) {
			keys[i] = keys[child];
		}
		else
			break;
	}
	keys[i] = refKey;
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

void BinaryHeap::insert(int keyVal, FILE* fp) {
	if(isFull()) {
		cout << "Heap is full.." << endl;
		fprintf(fp, "Heap is full\n");
	}
	else {
		int index = ++curSize;
		while(keys[index/2] > keyVal) {
			keys[index] = keys[index/2];
			index = index/2;
		}
		keys[index] = keyVal;
		fprintf(fp, "SUCCESS\n");
	}
}

int BinaryHeap::deleteMin(FILE* fp) {
	if(isEmpty()) {
		cout << "Empty Heap.." << endl;
		fprintf(fp, "Empty Heap\n");
		return SENTINEL;
	}
	int rootKey = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateDown(ROOT_INDEX);
	fprintf(fp, "SUCCESS\n");

	return rootKey;
}

void BinaryHeap::deleteMax(FILE* fp) {
	if(isEmpty()) {
		cout << "Empty Heap.." << endl;
		return;
	}

	int rootKey = keys[ROOT_INDEX];
	keys[ROOT_INDEX] = keys[curSize--];
	percolateUp(ROOT_INDEX);

	keys[curSize+1] = rootKey;
}

void BinaryHeap::traverse(FILE* fp) {
	for(int index=ROOT_INDEX; index <= curSize; ++index) {
		if(index != ROOT_INDEX) fprintf(fp, "\t");
		fprintf(fp, "%d", keys[index]);
	}
	fprintf(fp,"\n");
}

int BinaryHeap::isFull() {
	return (curSize >= HEAP_SIZE);
}

int BinaryHeap::isEmpty() {
	return (curSize == SENTINEL_INDEX);
}

int BinaryHeap::getMin() {
	if(!isEmpty()) {
		return keys[ROOT_INDEX];
	}
	else
		return SENTINEL;
}

int BinaryHeap::getCurSize() {
	return curSize;
}

void BinaryHeap::copy(int* arr, int size) {
	for(int index=0; index < size; ++index) {
		keys[index+1] = arr[index];
		curSize++;
	}
}

void BinaryHeap::testHeapOrder(int index) {
	if((keys[index*2] == 0 && keys[(index*2)+1] == 0) != 1 && (keys[index*2] != 0 && keys[(index*2)+1] != 0) != 1) {
		cout << "[PROPERTY ERROR], Not Complete Binary Tree.." << endl;
	}
	else {
		int max = (keys[index*2]>keys[(index*2)+1])?keys[index*2]:keys[(index*2)+1];
		if(max < keys[index])
			cout << "[HEAP ORDER ERROR], Parent : " << keys[index] << "  Child : " << max << endl;
		testHeapOrder(index*2);
		testHeapOrder((index*2)+1);
	}
}
