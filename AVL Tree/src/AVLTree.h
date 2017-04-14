/*
 * AVLTree.h
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */

#ifndef SRC_AVLTREE_H_
#define SRC_AVLTREE_H_

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

#ifndef LEAF_HEIGHT
#define LEAF_HEIGHT -1
#endif

#ifndef ALLOWED_IMBALANCE
#define ALLOWED_IMBALANCE 1
#endif

#include <stdio.h>
extern FILE *ofp;
extern int printTrigger;

typedef int dataType;
typedef int callType;

class AVL {
private :
	dataType data;
	int height;
	AVL* left;
	AVL* right;
public :
	AVL(dataType, AVL*, AVL*, int H); //keyVal, left pointer, right pointer and height

	AVL* insert(dataType);
	AVL* remove(dataType,callType);
	AVL* contains(dataType);
	AVL* findMax(); //complete
	AVL* findMin(); //complete

	int getHeight();
	AVL* balance();
	AVL* singleRotationLeft();
	AVL* singleRotationRight();
	AVL* doubleRotationLeft();
	AVL* doubleRotationRight();

	void preOrderTraversal(int); //root->left->right //complete
	void inOrderTraversal(int); //left->root->right //complete
	void postOrderTraversal(int); //left->right->root //complete

	void PrintDots(int); //complete
	int maxHeight(int, int); //compare heights

	void MakeEmpty(); //complete
};

extern AVL* root;

#endif /* SRC_AVLTREE_H_ */
