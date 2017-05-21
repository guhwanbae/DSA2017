/*
 * Sorting.h
 *
 *  Created on: 2017. 5. 18.
 *      Author: ghbae
 */

#ifndef SRC_SORTING_H_
#define SRC_SORTING_H_


#ifndef NULL
#define NULL 0
#endif

#ifndef MIN_QUICKSORT_SIZE
#define MIN_QUICKSORT_SIZE 10
#endif

#ifndef BUCKET_SIZE
#define BUCKET_SIZE 10
#endif

#ifndef MAX_ORDER
#define MAX_ORDER 100000 //10^5
#endif

#include <stdio.h>
#include "BinaryHeap.h"

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF SORTING ADT                       *
 ****************************************************************************/
class sortingADT {
private :
	int* arr; int* buffer;
	int size;
public :
	sortingADT(int*, int);
	~sortingADT();

	void insertionSort();
	void insertionSort(int,int);
	void heapSort();
	void quickSort();
	void quickSort(int, int);
	void radixSort(FILE*); //Count Radix Sort

	void print(FILE*);
	void print(int, int);
	void copyBuffer();

	int median(int, int);
	void swap(int, int);
};



#endif /* SRC_SORTING_H_ */
