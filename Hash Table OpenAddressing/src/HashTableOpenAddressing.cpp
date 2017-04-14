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

void HashTable::rehash(FILE* fp) {
	int oldTableSize = tableSize;
	HashEntry** oldCells = cells;

	tableSize = prime->findPrimeNumber(2*tableSize);

	fprintf(fp, " - NUM_ELE(%d), TABLE_SIZE(%d) - REHASH(%d)\n", numCells, oldTableSize, tableSize);

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

HashEntry* HashTable::find(int keyVal, FILE* fp) {
	int i, index;
	fprintf(fp, "FIND(%d): ", keyVal);
	for(i=0; i<(tableSize/2); ++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state == EMPTY) {
			fprintf(fp, "Key Not Found\n");
			cout << "Key Not Found" << endl;
			return NULL;
		}
		else if(cells[index]->key == keyVal && cells[index]->state == ACTIVE) {
			fprintf(fp, "SUCCESS\n");
			return cells[index];
		}
	}
	return NULL;
}

void HashTable::insert(int keyVal, FILE* fp) {
	int i, index;
	fprintf(fp, "INSERT(%d): ", keyVal);
	for(i=0;i<(tableSize/2);++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state != ACTIVE) {
			fprintf(fp, "SUCCESS\n");
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
		rehash(fp);
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
	}
}

void HashTable::remove(int keyVal, FILE* fp) {
	int i,index;
	fprintf(fp, "REMOVE(%d): ", keyVal);
	for(i=0;i<(tableSize/2);++i) {
		index = hash(keyVal + i*hash2(keyVal,i));

		if(cells[index]->state == EMPTY) {
			fprintf(fp, "Key Not Found\n");
			cout << "Key Not Found" << endl;
			return;
		}
		else if(cells[index]->key == keyVal && cells[index]->state == ACTIVE) {
			fprintf(fp, "SUCCESS\n");
			cells[index]->state = DELETED;
			--numCells;
			return;
		}
	}
}

void HashTable::traverse(FILE* fp) {
	int numProbing=0;
	fprintf(fp, "TRAVERSE - NUM_ELE(%d), TABLE_SIZE(%d)\n", numCells, tableSize);
	fprintf(fp, "TOTAL NUMBER OF PROBING: %d\n", numProbing);
	for(int index=0; index<tableSize; ++index) {
		fprintf(fp, "[Index (%d)] ", index);
		if(cells[index]->state == EMPTY)
			fprintf(fp, "EMPTY\n");
		else if(cells[index]->state == DELETED)
			fprintf(fp, "DELETED\n");
		else if(cells[index]->state == ACTIVE) {
			fprintf(fp, "ACTIVE(%d)\n", cells[index]->key);
		}
	}
}
