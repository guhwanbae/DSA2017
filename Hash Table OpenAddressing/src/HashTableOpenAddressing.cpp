/*
 * HashTableOpenAddressing.cpp
 *
 *  Created on: 2017. 4. 14.
 *      Author: guhwan
 */
#include <iostream>
#include <stdio.h>
#include "HashTableOpenAddressing.h"

using namespace std;
int REHASH_THRESHOLD = INIT_PRIME/2;

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF HASH TABLE(WITH OPEN ADDRESSING)*
 ****************************************************************************/
HashTable::HashTable(int newSize, int newR) {
	tableSize = newSize;
	numCells = 0;
	R = newR;
	prime = new PrimeTable(MAX_SIZE);

	cells = new HashEntry* [tableSize];
	for(int index=0; index<tableSize; ++index) {
		cells[index] = new HashEntry;
		cells[index]->state = EMPTY;
		cells[index]->key = 0;
	}
}

HashTable::~HashTable() {
	for(int index=0; index<tableSize; ++index) {
		if(cells[index] != NULL) {
			delete cells[index];
			cells[index] = NULL;
		}
	}
	delete[] cells;	cells = NULL;
	delete prime;	prime = NULL;
}

int HashTable::hash(int keyVal) {
	return (keyVal%tableSize);
}

int HashTable::hash2(int keyVal, int i) {
	return (R - (keyVal%R));
}

void HashTable::rehash() {
	int oldTableSize = tableSize;
	HashEntry** oldCells = cells;

	tableSize = prime->findPrimeNumber(2*tableSize);
	cells = new HashEntry* [tableSize];
	int index;
	for(index=0;index<tableSize;++index) {
		cells[index] = new HashEntry;
		cells[index]->state = EMPTY;
		cells[index]->key = 0;
	}
	numCells = 0;

	for(index=0; index<oldTableSize; ++index) {
		if(oldCells[index]->state == ACTIVE)
			insert(oldCells[index]->key);
		delete oldCells[index];
	}

	delete[] oldCells;
}

HashEntry* HashTable::find(int keyVal) {
	int i, index;
	for(i=0; i<(tableSize/2); ++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state == EMPTY) {
			cout << "Key Not Found" << endl;
			return NULL;
		}
		else if(cells[index]->key == keyVal && cells[index]->state == ACTIVE) {
			return cells[index];
		}
	}
	return NULL;
}

void HashTable::insert(int keyVal) {
	int i, index;
	for(i=0;i<(tableSize/2);++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state != ACTIVE) {
			cells[index]->key = keyVal;
			cells[index]->state = ACTIVE;
			++numCells;
			break;
		}
		else if(cells[index]->key == keyVal && cells[index]->state == ACTIVE) {
			cout << "Duplicated Key" << endl;
			return;
		}
	}

	if(numCells/tableSize >= REHASH_THRESHOLD)
		rehash();
}

void HashTable::remove(int keyVal) {
	int i,index;
	for(i=0;i<(tableSize/2);++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state == EMPTY) {
			cout << "Key Not Found" << endl;
			return;
		}
		else if(cells[index]->key == keyVal && cells[index]->state == ACTIVE) {
			cells[index]->state = DELETED;
			--numCells;
			return;
		}
	}
}

void HashTable::traverse() {

}
