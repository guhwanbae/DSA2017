/*
 * SortedLinkedList.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_LISTADT_SORTEDLINKEDLIST_H_
#define SRC_LISTADT_SORTEDLINKEDLIST_H_

#include <stdio.h>
#include "../GraphADT/GraphADT.h"

typedef int keyValType;

/* Sort Edges -> Sorted Linked List */
/* The SLL Class is a method for arranging a Linked List.
 * Sort the Nodes in the Linked List in a specific order,
 * and Linking the sorted Nodes again to return their head-pointer(head-Node).
 * !If you want to sort the Linked List with a different Reference value,
 * change the getRef() function and the type of Reference value(typedef keyValType)!*/

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF SORTED LINKED LIST              *
 ****************************************************************************/
template<typename T>
class SLL {
private :
	T** keys;
	T* head;
	int size;
public :
	SLL(T*,int);
	~SLL();

	T* sortEdge();
private :
	void initKeys();

	keyValType getRef(T*);

	void insertionSort(int, int);
	void quickSort(int,int);
	keyValType median(int,int);
	void swap(int,int);
	void linking();
};


#ifndef MIN_QUICKSORT_SIZE
#define MIN_QUICKSORT_SIZE 10
#endif

template<typename T>
SLL<T>::SLL(T* keyHead, int newSize) {
	size = newSize;
	head = keyHead;
	keys = new T*[size];
	initKeys();
}
template<typename T>
SLL<T>::~SLL() {
	delete[] keys;
	keys = NULL;
}
template<typename T>
void SLL<T>::initKeys() {
	T* cur=head; int index=0;
	while(cur != NULL) {
		keys[index++] = cur;
		cur = cur->getNext();
	}
}

template<typename T>
T* SLL<T>::sortEdge(){
	quickSort(0,size-1); //Sort the Nodes in the Linked List in a specific order.
	head = keys[0];

	linking(); //Linking the sorted Nodes again.

	return head; //Return their head-pointer(head-Node).
}

template<typename T>
keyValType SLL<T>::getRef(T* element) { //Set the reference value for the sorting.
	if(element == NULL) {
		return 0;
	}
	else {
		return element->getVertexID(); //In this case, it is sorted by the Vertex ID. VertexID = elemente->getVertexID().
	}
}

template<typename T>
void SLL<T>::insertionSort(int left, int right) {
	int i,j;	T* temp;

	for(i=left;i<=right;++i) {
		temp = keys[i];
		for(j=i;j>0 && getRef(temp) < getRef(keys[j-1]); --j) {
			keys[j] = keys[j-1];
		}
		keys[j] = temp;
	}
}

template<typename T>
void SLL<T>::quickSort(int left, int right) {
	if(left + MIN_QUICKSORT_SIZE <= right) { //If the size of the alignment is less than 10, the Insertion Sort is faster than Quick Sort.
		keyValType pivot = median(left,right);
		int i=left; int j=right-1;

		for(;;) {
			while(getRef(keys[++i]) < pivot);
			while(getRef(keys[--j]) > pivot);

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

template<typename T>
keyValType SLL<T>::median(int left, int right) {
	int center = (left+right)/2;

	if( getRef(keys[left]) > getRef(keys[center]) )
		swap(left,center);
	if( getRef(keys[left]) > getRef(keys[right]) )
		swap(left,right);
	if( getRef(keys[center]) > getRef(keys[right]) )
		swap(center,right);

	swap(center,right-1);

	return getRef(keys[right-1]);
}

template<typename T>
void SLL<T>::swap(int x, int y) {
	T* temp;
	temp = keys[x];
	keys[x] = keys[y];
	keys[y] = temp;
}

template<typename T>
void SLL<T>::linking() { //Reconnect the Sorted Nodes to one Linked List.
	for(int index=0; index<size; ++index){
			if(index == size-1) {
			keys[index]->setNext(NULL); //Set tail
			break;
		}
		else { //Linking the next.
			keys[index]->setNext(keys[index+1]);
		}
	}
}

#endif /* SRC_LISTADT_SORTEDLINKEDLIST_H_ */
