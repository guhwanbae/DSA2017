/*
 * BinaryTree.h
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#define MAX_SIZE	1000
#define MAX_LINE	2048
#define MAX_VALUE	10000

#ifndef REMOVE_NOTFOUND
#define REMOVE_NOTFOUND 2
#endif

#ifndef REMOVE_REPLACED
#define REMOVE_REPLACED 1
#endif

#ifndef REMOVE_DELETED
#define REMOVE_DELETED 0 //default set printing trigger..
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

typedef int dataType;

#include <stdio.h>
extern FILE* ofp;
extern int printTrigger;

class BinaryTree {
private :
	dataType data;
	BinaryTree* left;
	BinaryTree* right;
public :
	BinaryTree(dataType, BinaryTree*, BinaryTree*);

	BinaryTree* insert(dataType);
	BinaryTree* remove_L(dataType);
	BinaryTree* remove_R(dataType);
	BinaryTree* contains(dataType);
	BinaryTree* findMax();
	BinaryTree* findMin();

	void preOrderTraversal(int);
	void inOrderTraversal(int);
	void postOrderTraversal(int);

	void PrintDots(int);

	void MakeEmpty();
};

extern BinaryTree* root;

#endif /* BINARYTREE_H_ */
