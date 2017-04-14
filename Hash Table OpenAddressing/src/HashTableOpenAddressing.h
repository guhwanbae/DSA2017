/*
 * HashTableOpenAddressing.h
 *
 *  Created on: 2017. 4. 14.
 *      Author: guhwan
 */

#ifndef SRC_HASHTABLEOPENADDRESSING_H_
#define SRC_HASHTABLEOPENADDRESSING_H_

/****************************************************************************
 * MACROS FOR FILE I/O RULES                                       *
 ****************************************************************************/
#define MAX_SIZE	1000
#define MAX_LINE	2048
#define MAX_VALUE	10000

/****************************************************************************
 * MACROS TO SHOW THE STATE OF CELL                               *
 ****************************************************************************/
#ifndef EMPTY
#define EMPTY 10001
#endif

#ifndef ACTIVE
#define ACTIVE 10002
#endif

#ifndef DELETED
#define DELETED 10003
#endif

/****************************************************************************
 * MACROS TO SHOW THE TYPE OF PRINTING                            *
 ****************************************************************************/
#ifndef REMOVE_NOTFOUND
#define REMOVE_NOTFOUND 2
#endif

#ifndef REMOVE_REPLACED
#define REMOVE_REPLACED 1
#endif

#ifndef REMOVE_DELETED
#define REMOVE_DELETED 0 //default set printing trigger..
#endif

/****************************************************************************
 * MACROS FOR THE RULES OF LOGICAL DECISIONS                      *
 ****************************************************************************/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL	0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef FAILURE
#define FAILURE 0
#endif

#ifndef INIT_PRIME
#define INIT_PRIME 101
#endif

#ifndef INIT_R
#define INIT_R 7
#endif

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF HASH TABLE(WITH OPEN ADDRESSING)  *
 ****************************************************************************/
#include "Prime.h"

struct HashEntry {
	int key;
	int state;
}; typedef struct HashEntry HashEntry;

class HashTable {
private :
	HashEntry** cells; //size of cells = tableSize * size of pointer.
	int tableSize; //a prime number
	int numCells;
	int R; //the prime number smaller than tableSize to use double hashing
	PrimeTable* prime;
public :
	HashTable(int, int);
	~HashTable();

	int hash(int);
	int hash2(int, int);
	void rehash(FILE* );

	void insert(int);
	void insert(int, FILE*);
	HashEntry* find(int, FILE*);
	void remove(int, FILE*);

	void traverse(FILE*);
};

#endif /* SRC_HASHTABLEOPENADDRESSING_H_ */
