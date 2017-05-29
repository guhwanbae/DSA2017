/*
 * DisjointSet.h
 *
 *  Created on: 2017. 5. 26.
 *      Author: ghbae
 */

#ifndef SRC_DISJOINTSET_H_
#define SRC_DISJOINTSET_H_

/****************************************************************************
 * MACROS FOR FILE I/O RULES                                       *
 ****************************************************************************/
#define MAX_SIZE	1000
#define MAX_LINE	2048
#define MAX_VALUE	10000

#ifndef NULL
#define NULL 0
#endif

#ifndef SIZE_ROOT
#define SIZE_ROOT -1
#endif

#ifndef COUNT_ZERO
#define COUNT_ZERO 0
#endif

#include <stdio.h>

class DisjointSet {
private :
	int* s;
	int size;
	FILE* fp;
public :
	DisjointSet(int,FILE*);
	~DisjointSet();

	void unionSets(int, int);
	void unionBySize(int, int);
	void unionByHeight(int, int);
	void unionBySizeWithComp(int, int);

	void Find(int);
	int find(int);
	int find(int, int);
	void FindAndCompress(int);
	int findAndCompress(int);
	int findAndCompress(int, int);

	void print();
};

#endif /* SRC_DISJOINTSET_H_ */
