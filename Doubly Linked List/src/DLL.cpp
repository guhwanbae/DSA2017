/*
 * DLL.cpp
 *
 *  Created on: 2017. 3. 23.
 *      Author: guhwan
 */

#include <iostream>
#include "DLL.h"

using namespace std;

DLL* head;
DLL* tail;

int DLL::insert(int Val, FILE* fp) {
	DLL* temp = head;

	while(temp != NULL) {
		if(temp->data == Val) {
			fprintf(fp, "Duplicate Key\n");
			return FAILURE;
		}
		temp = temp->next;
	}

	temp = new DLL(Val, head, NULL);
	head->prev = temp;
	head = temp;

	return SUCCESS;
}

int DLL::insertkth(int index, int Val) {
	if(index == 0) {
		head = new DLL(Val, head, NULL);
		return SUCCESS;
	}
	else {
		DLL* temp = head;
		DLL* ToBePrev = head;
		int i;

		for(i=0;i<index && temp != NULL;i++) {
			ToBePrev = temp;
			temp = temp->next;
		}

		if(i != index)	{
			cout<<"Invalid position("<<index<<"): The current size of stack is "<<i<<endl;
			return FAILURE;
		}
		else {
			if(temp == NULL) {
				ToBePrev->next = new DLL(Val,NULL,ToBePrev);
				tail = ToBePrev->next;
			}
			else {
				ToBePrev->next = new DLL(Val,temp,ToBePrev);
				temp->prev = ToBePrev->next;
			}
			return SUCCESS;
		}
	}
}

DLL* DLL::search(int Val, FILE* fp) {
	DLL* cur = head;
	while(cur != NULL) {
		if(cur->data == Val) {
			fprintf(fp, "Success\n");
			return cur;
		}
		cur = cur->next;
	}
	fprintf(fp, "No Entry Found\n");
	return NULL;
}

int DLL::remove(int Val, FILE* fp) {
	DLL* ToBeDeleted = head;
	while(ToBeDeleted != NULL && ToBeDeleted->data != Val) {
		ToBeDeleted = ToBeDeleted->next;
	}

	if(ToBeDeleted == NULL) {
		fprintf(fp, "No Entry Found\n");
		return FAILURE;
	}
	else {
		if(ToBeDeleted == head && ToBeDeleted == tail) {
			head = NULL; tail = NULL;
		}
		else if(ToBeDeleted == head) {
			head = ToBeDeleted->next;
			head->prev = NULL;
		}
		else if(ToBeDeleted == tail) {
			tail = ToBeDeleted->prev;
			tail->next = NULL;
		}
		else {
			DLL* temp_prev = ToBeDeleted->prev;
			DLL* temp_next = ToBeDeleted->next;
			temp_prev->next = temp_next;
			temp_next->prev = temp_prev;
		}
		delete ToBeDeleted;
	}

	return SUCCESS;
}

void DLL::traverse(FILE *fp) {
	DLL* temp = head;
	while(temp != NULL)	{
		if(temp->next == NULL) fprintf(fp, "%d\n", temp->data);
		else fprintf(fp, "%d <-> ", temp->data);
		temp = temp->next;
	}
}

void DLL::traverse_backword(void) {
	DLL* temp = tail;
	//if(tail == head == NULL) cout<<"Traverse : Empty!"<<endl;
	while(temp != NULL) {
		cout<<temp->data<<"<->";
		temp = temp->prev;
	}
	cout<<endl;
}
