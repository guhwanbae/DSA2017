/*
 * Prime.cpp
 *
 *  Created on: 2017. 4. 14.
 *      Author: guhwan
 */
#include <iostream>
#include <math.h>
#include "Prime.h"
using namespace std;

PrimeTable::PrimeTable(int newSize) {
	curPrimeIndex = 0;
	maxSize = newSize;
	primeTable = new int[maxSize];
	for(int index=0; index<maxSize; ++index) {
		primeTable[index] = 0;
	}
	Eratosthenes();
}

PrimeTable::~PrimeTable() {
	delete[] primeTable;
	primeTable = NULL;
}

int PrimeTable::findPrimeNumber(int keyVal) {
	if(keyVal < 0 || keyVal < primeTable[curPrimeIndex]) {
		cout << "ERROR::findPrimeNumber : Wrong Input.." << endl;
		return primeTable[curPrimeIndex];
	}
	while(primeTable[curPrimeIndex] < keyVal && curPrimeIndex < maxSize) {
		curPrimeIndex++;
	}
	return primeTable[curPrimeIndex];
}

void PrimeTable::Eratosthenes() {
	int i,j;
	int naturalTable[maxSize];
	for(i=0;i<maxSize;++i)
		naturalTable[i] = (i+2);
	for(i=2; i<=sqrt(maxSize); ++i) {
		if(naturalTable[i] == 0)
			continue;
		for (j=2*i; j<=maxSize; j= +j) {
			naturalTable[j] = 0;
		}
	}
	for(i=0,j=0;i<maxSize;++i) {
		if(naturalTable[i] != 0) {
			primeTable[j++] = naturalTable[i];
		}
	}
}

void PrimeTable::resetCurPrimeIndex() {
	curPrimeIndex = 0;
}
