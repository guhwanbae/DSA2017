/*
 * SplayTree.h
 *
 *  Created on: 2017. 4. 9.
 *      Author: guhwan
 */

#ifndef SRC_SPLAYTREE_H_
#define SRC_SPLAYTREE_H_

#define MAX_SIZE	1000
#define MAX_LINE	2048
#define MAX_VALUE	10000

#ifndef PRINT
#define PRINT 1001
#endif

#ifndef REMOVE_INIT
#define REMOVE_INIT 1 //default set printing trigger..
#endif

#ifndef REMOVE_NOTFOUND
#define REMOVE_NOTFOUND 2
#endif

#ifndef REMOVE_DELETED
#define REMOVE_DELETED 3
#endif

#ifndef CONTAINS_INIT
#define CONTAINS_INIT -1 //default set printing trigger..
#endif

#ifndef CONTAINS_SUCCESS
#define CONTAINS_SUCCESS -2
#endif

#ifndef CONTAINS_NOTFOUND
#define CONTAINS_NOTFOUND -3
#endif

#ifndef REMOVE_R
#define REMOVE_R 1
#endif

#ifndef REMOVE_L
#define REMOVE_L -1
#endif

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

#ifndef SPT
#define SPT SplayTree
#endif

#include <stdio.h>
extern FILE *ofp;
extern int printTrigger;

typedef int dataType;
typedef int callType;

class SplayTree {
private :
	SPT* parent;
	SPT* left;
	SPT* right;

	dataType key;

public :
	SplayTree(dataType, SPT*, SPT*, SPT*);

	SPT* insert(dataType);
	void remove(dataType, callType);
	void replaceLeft(dataType);
	void replaceRight(dataType);
	SPT* contains(dataType);

	dataType findMin();
	dataType findMax();

	void splaying();
	void zigLeft();
	void zigRight();
	void zigZigLeft();
	void zigZigRight();
	void zigLeftZagRight();
	void zigRightZagLeft();

	void preOrderTraversal(int);
	void inOrderTraversal(int);
	void postOrderTraversal(int);

	void makeEmpty();
	void printDots(int);
	void printKeywords(int, int);

	void paternityTest(SPT*, SPT*);

};

extern SPT* root;

#endif /* SRC_SPLAYTREE_H_ */
