/*
 * Prime.h
 *
 *  Created on: 2017. 4. 14.
 *      Author: guhwan
 */

#ifndef SRC_PRIME_H_
#define SRC_PRIME_H_

#ifndef MAX_NATURAL_NUMBER
#define MAX_NATURAL_NUMBER 10000
#endif

class PrimeTable {
private :
	int* primeTable;
	int curPrimeIndex;
	int maxSize;
public :
	PrimeTable(int);
	~PrimeTable();
	int findPrimeNumber(int);
	void Eratosthenes();
	int getPrime(int);
	int getCurPrimeIndex();
	void resetCurPrimeIndex();
};

#endif /* SRC_PRIME_H_ */
