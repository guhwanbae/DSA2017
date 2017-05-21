/*
 * Sorting.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: ghbae
 */
#include <iostream>
#include "Sorting.h"
using namespace std;

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF SORTING ADT                     *
 ****************************************************************************/
sortingADT::sortingADT(int* arrname, int arrsize) {
	buffer = arrname;
	size = arrsize;
	arr = new int[size];
	for(int index=0; index<size; ++index) {
		arr[index] = buffer[index];
	}
}

sortingADT::~sortingADT() {
	delete[] arr;
	arr = NULL;
	buffer = NULL;
}

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF IMSERTION SORT                  *
 ****************************************************************************/
void sortingADT::insertionSort() {
	int i,j,temp;
	for(i=1;i<size;++i) {
		temp = arr[i];
		for(j=i;j>0 && temp<arr[j-1];--j) {
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}
void sortingADT::insertionSort(int left, int right) {
	int i,j,temp;
	for(i=left;i<=right;++i) {
		temp = arr[i];
		for(j=i;j>0 && temp<arr[j-1];--j) {
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF HEAP SORT                       *
 ****************************************************************************/
void sortingADT::heapSort() {
	BinaryHeap* Heap;
	Heap = new BinaryHeap(size);
	Heap->buildHeap(arr,size);
	for(int i=0; i<size; ++i) {
		Heap->deleteMax();
	}
	Heap->getKeys(arr,size);
	delete Heap;
	Heap = NULL;
}

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF QUICK SORT                      *
 ****************************************************************************/
void sortingADT::quickSort() {
	quickSort(0,size-1);
}
void sortingADT::quickSort(int left, int right) {
	if(left + MIN_QUICKSORT_SIZE <= right) {
		int pivot = median(left,right);
		int i=left; int j=right-1;

		for(;;) {
			while(arr[++i] < pivot);
			while(arr[--j] > pivot);

			if(i < j)
				swap(i,j);
			else
				break;
		}
		swap(i,right-1);

		quickSort(left,i-1);
		quickSort(i+1,right);
	}
	else {
		if(left < right) {
			insertionSort(left,right);
		}
	}
}

int sortingADT::median(int left, int right) {
	int center = (left+right)/2;

	if(arr[left] > arr[center])
		swap(left,center);
	if(arr[left] > arr[right])
		swap(left,right);
	if(arr[center] > arr[right])
		swap(center,right);

	swap(center,right-1);

	return arr[right-1];
}
void sortingADT::swap(int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}



/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF COUNT RADIX SORT                *
 ****************************************************************************/
void sortingADT::radixSort(FILE* fp) {
	int *input = arr;
	int *output = new int[size];
	int *temp = NULL;
	int count[BUCKET_SIZE+1];

	for(int order=1; order != MAX_ORDER; order *= BUCKET_SIZE) {
		for(int i=0; i<BUCKET_SIZE+1; ++i) {
			count[i] = 0;
		}

		for(int i=0; i<size; ++i) {
			++count[((input[i]/order)%BUCKET_SIZE) + 1];
		}

		for(int b=1; b <= BUCKET_SIZE; ++b) {
			count[b] += count[b-1];
		}

		for(int i=0; i<size; ++i) {
			output[count[(input[i]/order)%BUCKET_SIZE]++] = input[i];
		}
		temp = input; input = output; output = temp;
	}
	arr = input;

	delete[] output;
	output = NULL;
}

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF PRINTING ARRAY                  *
 ****************************************************************************/
void sortingADT::print(FILE* fp) {
	for(int index=0; index<size; ++index) {
		fprintf(fp, "\t%d",arr[index]);
	}
	fprintf(fp, "\n");
}

void sortingADT::copyBuffer() {
	for(int index=0; index<size; ++index) {
		arr[index] = buffer[index];
	}
}
