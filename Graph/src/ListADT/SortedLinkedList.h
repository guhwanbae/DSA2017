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
	/*
	 * Ref of Sorting = KeyVal!!
	 * VertexID of Edge(Type int) = KeyVal
	 */
private :
	void initKeys();

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
	quickSort(0,size-1);
	head = keys[0];

	linking();

	return head;
}

template<typename T>
void SLL<T>::insertionSort(int left, int right) {
	int i,j;	T* temp;

	for(i=left;i<=right;++i) {
		temp = keys[i];
		for(j=i;j>0 && temp->getVertexID()<keys[j-1]->getVertexID();--j) {
			keys[j] = keys[j-1];
		}
		keys[j] = temp;
	}
}

template<typename T>
void SLL<T>::quickSort(int left, int right) {
	if(left + MIN_QUICKSORT_SIZE <= right) {
		keyValType pivot = median(left,right);
		int i=left; int j=right-1;

		for(;;) {
			while(keys[++i]->getVertexID() < pivot);
			while(keys[--j]->getVertexID() > pivot);

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

	if(keys[left]->getVertexID() > keys[center]->getVertexID())
		swap(left,center);
	if(keys[left]->getVertexID() > keys[right]->getVertexID())
		swap(left,right);
	if(keys[center]->getVertexID() > keys[right]->getVertexID())
		swap(center,right);

	swap(center,right-1);

	return keys[right-1]->getVertexID();
}

template<typename T>
void SLL<T>::swap(int x, int y) {
	T* temp;
	temp = keys[x];
	keys[x] = keys[y];
	keys[y] = temp;
}

template<typename T>
void SLL<T>::linking() {
	printf("Edge : ");
	for(int index=0; index<size; ++index){
		printf(" (%2d) -> ",keys[index]->getVertexID());
		if(index == size-1) {
			keys[index]->setNext(NULL); //Set tail
			break;
		}
		else {
			keys[index]->setNext(keys[index+1]);
		}
	}
	printf("\n");
}

#endif /* SRC_LISTADT_SORTEDLINKEDLIST_H_ */
