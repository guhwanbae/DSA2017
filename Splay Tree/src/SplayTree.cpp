/*
 * SplayTree.cpp
 *
 *  Created on: 2017. 4. 9.
 *      Author: guhwan
 */

#include <iostream>
#include "SplayTree.h"
using namespace std;

SPT* root;

SplayTree::SplayTree(dataType keyVal, SPT* P, SPT* L, SPT* R) {
	key = keyVal;
	parent = P;
	left = L;
	right = R;
}

SPT* SplayTree::insert(dataType keyVal) {
	if(this == NULL) {//empty tree case..
		fprintf(ofp, "Success\n");
		return new SPT(keyVal, NULL, NULL, NULL);
	}

	SPT* pNode; SPT* tNode = this;
	while(tNode != NULL) {
		pNode = tNode;
		//comparing key values..
		if(tNode->key > keyVal)
			tNode = tNode->left;
		else if(tNode->key < keyVal)
			tNode = tNode->right;
		else {
			fprintf(ofp, "Duplicate Node\n");
			tNode->splaying();
			return tNode; //return a new root..
		}
	}

	tNode = new SPT(keyVal, pNode, NULL, NULL);
	fprintf(ofp, "Success\n");

	if(pNode->key < keyVal)
		pNode->right = tNode;
	else
		pNode->left = tNode;

	tNode->splaying();

	return tNode;	//return a new root..
}
void SplayTree::remove(dataType keyVal, callType removeType) {
	if(root == NULL) {
		printKeywords(REMOVE_INIT,REMOVE_NOTFOUND);
	}

	root = root->contains(keyVal);

	if(root->key == keyVal) {
		SPT* toBeDeletedNode = root;

		if(removeType == REMOVE_L) {
			if(root->left != NULL) {
				root->replaceLeft(root->left->findMax());
			}
			else if(root->right != NULL) {
				root->replaceRight(root->right->findMin());
			}
			else
				root = NULL;
		}
		else if(removeType == REMOVE_R) {
			if(root->right != NULL) {
				root->replaceRight(root->right->findMin());
			}
			else if(root->left != NULL) {
				root->replaceLeft(root->left->findMax());
			}
			else
				root = NULL;
		}
		delete toBeDeletedNode;
		toBeDeletedNode = NULL;
		printKeywords(REMOVE_INIT,REMOVE_DELETED);
	}
	else {
		printKeywords(REMOVE_INIT,REMOVE_NOTFOUND);
	}
}

void SplayTree::replaceLeft(dataType keyVal) {
	root->left->parent = NULL; //seperate a root and left subtree..
	root->left = root->left->contains(keyVal); //call contains-> at leaf Node, call splaying..
	root->left->right = root->right; //right of root of left subtree is NULL Node..
	if(root->right != NULL)
		root->right->parent = root->left;
	root = root->left;
}

void SplayTree::replaceRight(dataType keyVal) {
	root->right->parent = NULL; //seperate a root and right subtree..
	root->right = root->right->contains(keyVal);
	root->right->left = root->left;
	if(root->left != NULL)
		root->left->parent = root->right;
	root = root->right;
}

SPT* SplayTree::contains(dataType keyVal) {
	if(this == NULL) {
		printKeywords(CONTAINS_INIT,CONTAINS_NOTFOUND);
		return NULL;
	}

	SPT* pNode; SPT* tNode = this;

	while(tNode != NULL) {
		pNode = tNode;

		if(tNode->key > keyVal)
			tNode = tNode->left;
		else if(tNode->key < keyVal)
			tNode = tNode->right;
		else {
			printKeywords(CONTAINS_INIT,CONTAINS_SUCCESS);
			tNode->splaying();
			return tNode; //return a new root..
		}
	}
	printKeywords(CONTAINS_INIT,CONTAINS_NOTFOUND);

	pNode->splaying();
	return pNode;
}

dataType SplayTree::findMin() {
	if(this != NULL) {
		if(left != NULL)
			return left->findMin();
		else
			return this->key;
	}
	return NULL;
}
dataType SplayTree::findMax() {
	if(this != NULL) {
		if(right != NULL)
			return right->findMax();
		else
			return this->key;
	}
	return NULL;
}

void SplayTree::splaying() {
	if(this == NULL) {
		cout << "Access error!" << endl;
		return; //end this function..
	}

	while(parent != NULL) {
		if(parent->parent == NULL) {
			if(parent->left == this) {
				zigLeft();
			}
			else {
				zigRight();
			}
		}
		else {
			if(parent->left == this) {
				if(parent->parent->left == parent) {
					zigZigLeft();
				}
				else {
					zigRightZagLeft();
				}
			}
			else {
				if(parent->parent->left == parent)
					zigLeftZagRight();
				else
					zigZigRight();
			}
		}
	}
}

//Zig (L case)
void SplayTree::zigLeft() {
	SPT* par = this->parent; SPT* gpar = par->parent;
	SPT* rChild = this->right;
	//save to be a moved subtree.. rChild..

	//link between X(this) Node and grand parent Node..
	this->parent = gpar;
	if(gpar != NULL) {
		this->paternityTest(gpar, par);
	}

	//reverse generation..
	par->parent = this;
	this->right = par;

	//link between parent Node and a moved subtree..
	par->left = rChild;
	if(rChild != NULL)
		rChild->parent = par;
}

//Zig (R case)
void SplayTree::zigRight() {
	SPT* par = this->parent; SPT* gpar = par->parent;
	SPT* lChild = this->left;
	//save to be a moved subtree.. rChild..

	//link between X(this) Node and grand parent Node..
	this->parent = gpar;
	if(gpar != NULL) {
		this->paternityTest(gpar, par);
	}

	//reverse generation..
	this->left = par;
	par->parent = this;

	//link between parent Node and a moved subtree..
	par->right = lChild;
	if(lChild != NULL)
		lChild->parent = par;
}

//ZigZig (LL case)
void SplayTree::zigZigLeft() {
	SPT* par = this->parent; SPT* gpar = par->parent;
	SPT* rChild = this->right; SPT* prChild = par->right;
	//save to be moved subtrees.. rChild and prChild..

	//link between X(this) nod and grand-grand parent Node.
	parent = gpar->parent;
	//judge the direction of grand-grand parent Node to X Node
	if(gpar->parent != NULL) {
		this->paternityTest(gpar->parent, gpar);
	}

	//reverse generation
	par->parent = this;
	gpar->parent = par;
	right = par;
	par->right = gpar;

	//link between P,G nodes and moved subtrees
	if(rChild != NULL)
		rChild->parent = par;
	par->left = rChild;
	if(prChild != NULL)
		prChild->parent = gpar;
	gpar->left = prChild;
}

//ZigZig (RR case)
void SplayTree::zigZigRight() {
	SPT* par = this->parent; SPT* gpar = par->parent;
	SPT* lChild = this->left; SPT* plChild = par->left;
	//save to be moved subtrees.. lChild and plChild..

	//link between X(this) nod and grand-grand parent Node.
	parent = gpar->parent;
	if(gpar->parent != NULL) {
		this->paternityTest(gpar->parent, gpar);
	}

	//reverse generation
	left = par;
	par->parent = this;
	par->left = gpar;
	gpar->parent = par;

	//link between P,G nodes and moved subtrees
	par->right = lChild;
	if(lChild != NULL)
		lChild->parent = par;
	gpar->right = plChild;
	if(plChild != NULL)
		plChild->parent = gpar;
}

//ZigZag (LR case)
void SplayTree::zigLeftZagRight() {
	zigRight();
	zigLeft();
}

//ZigZag (RL case)
void SplayTree::zigRightZagLeft() {
	zigLeft();
	zigRight();
}
void SplayTree::paternityTest(SPT* father, SPT* son) {
	if(father->left == son)
		father->left = this;
	else
		father->right = this;
}

void SplayTree::preOrderTraversal(int depth) {
	if (this != NULL) {
		printDots(depth);
		if (left != NULL) {
			left->preOrderTraversal(depth + 1);
		}
		if (right != NULL) {
			right->preOrderTraversal(depth + 1);
		}
	}
}
void SplayTree::inOrderTraversal(int depth) {
	if (this != NULL) {
		if (left != NULL) {
			left->inOrderTraversal(depth + 1);
		}
		printDots(depth);
		if (right != NULL) {
			right->inOrderTraversal(depth + 1);
		}
	}
}
void SplayTree::postOrderTraversal(int depth) {
	if (this != NULL) {
		if (left != NULL) {
			left->postOrderTraversal(depth + 1);
		}
		if (right != NULL) {
			right->postOrderTraversal(depth + 1);
		}
		printDots(depth);
	}
}

void SplayTree::makeEmpty() {
	if(this != NULL) {
		left->makeEmpty();
		right->makeEmpty();
		delete this;
	}
	root = NULL;
}

void SplayTree::printDots(int depth) {
	for(int i=0; i<depth; ++i) {
		fprintf(ofp, "..");
	}
	fprintf(ofp, "%d\n", key);
}

void SplayTree::printKeywords(int lock, int trigger) {
	if(printTrigger == lock)
		printTrigger = trigger;
	else if(lock == PRINT) {
		if(trigger == REMOVE_DELETED || trigger == CONTAINS_SUCCESS)
			fprintf(ofp, "Success\n");
		else if(trigger == REMOVE_NOTFOUND || trigger == CONTAINS_NOTFOUND)
			fprintf(ofp, "Node Not Found\n");
	}
}
