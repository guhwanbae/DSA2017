/*
 * BinaryTree.cpp
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree* root;

BinaryTree::BinaryTree(dataType keyVal, BinaryTree* L, BinaryTree* R) {
	this->data = keyVal;
	this->left = L;
	this->right = R;
}

BinaryTree* BinaryTree::findMin() {
	if(this != NULL) {
		if(this->left != NULL) {
			return this->left->findMin();
		}
		else {
			return this;
		}
	}
	return NULL;
}

BinaryTree* BinaryTree::findMax() {
	if(this != NULL) {
		if(this->right != NULL) {
			return this->right->findMax();
		}
		else {
			return this;
		}
	}
	return NULL;
}

BinaryTree* BinaryTree::contains(dataType keyVal) {
	if(this == NULL) {
		fprintf(ofp, "Node Not Found\n");
		return this;
	}
	else {
		if(this->data > keyVal) {
			left->contains(keyVal);
		}
		else if(this->data < keyVal) {
			right->contains(keyVal);
		}
		else {
			fprintf(ofp, "Node Found\n");
			return this;
		}
	}
	return this;
}


BinaryTree* BinaryTree::insert(dataType keyVal) {
	if(this == NULL) {
		fprintf(ofp, "Node Inserted\n");
		return new BinaryTree(keyVal, NULL, NULL);
	}
	else {
		if(this->data > keyVal) {
			this->left = this->left->insert(keyVal);
		}
		else if(this->data < keyVal) {
			this->right = this->right->insert(keyVal);
		}
		else {
			fprintf(ofp, "Duplicated Node\n");
		}
	}
	return this;
}

BinaryTree* BinaryTree::remove_L(dataType keyVal) {
	if(this != NULL) {
		if(this->data > keyVal) {
			this->left = this->left->remove_L(keyVal);
		}
		else if(this->data < keyVal) {
			this->right = this->right->remove_L(keyVal);
		}
		else if(this->left != NULL && this->right != NULL) {
			this->data = this->left->findMax()->data;
			this->left = this->left->remove_L(this->data);
			fprintf(ofp, "Node Replaced with Key(%d)\n", this->data);
			printTrigger = REMOVE_REPLACED;
		}
		else {
			if(this->left == NULL && this->right == NULL) {
				delete this;
				return NULL;
			}
			else if(left == NULL) {
				delete this;
				return this->right;
			}
			else if(right == NULL) {
				delete this;
				return this->left;
			}
		}
	}
	else {
		fprintf(ofp, "Node Not Found\n");
		printTrigger = REMOVE_NOTFOUND;
		return NULL;
	}
	return this;
}

BinaryTree* BinaryTree::remove_R(dataType keyVal) {
	if(this != NULL) {
		if(this->data > keyVal) {
			this->left = this->left->remove_R(keyVal);
		}
		else if(this->data < keyVal) {
			this->right = this->right->remove_R(keyVal);
		}
		else if(this->left != NULL && this->right != NULL) {
			this->data = this->right->findMin()->data;
			this->right = this->right->remove_R(this->data);
			fprintf(ofp, "Node Replaced with Key(%d)\n", this->data);
			printTrigger = REMOVE_REPLACED;
		}
		else {
			if(this->left == NULL && this->right == NULL) {
				delete this;
				return NULL;
			}
			else if(left == NULL) {
				delete this;
				return this->right;
			}
			else if(right == NULL) {
				delete this;
				return this->left;
			}
		}
	}
	else {
		fprintf(ofp, "Node Not Found\n");
		printTrigger = REMOVE_NOTFOUND;
		return NULL;
	}
	return this;
}

//PreOrder : root -> left -> right
void BinaryTree::preOrderTraversal(int depth) {
	if(this != NULL) {
		this->PrintDots(depth);
		if(this->left != NULL) {
			this->left->preOrderTraversal(depth+1);
		}
		if(this->right != NULL) {
			this->right->preOrderTraversal(depth+1);
		}
	}
}

//InOrder : left -> root -> right
void BinaryTree::inOrderTraversal(int depth) {
	if(this != NULL) {
		if(this->left != NULL) {
			this->left->inOrderTraversal(depth+1);
		}
		this->PrintDots(depth);
		if(this->right != NULL) {
			this->right->inOrderTraversal(depth+1);
		}
	}
}

//PostOrder : left -> right -> root
void BinaryTree::postOrderTraversal(int depth) {
	if(this != NULL) {
		if(this->left != NULL) {
			this->left->postOrderTraversal(depth+1);
		}
		if(this->right != NULL) {
			this->right->postOrderTraversal(depth+1);
		}
		this->PrintDots(depth);
	}
}

void BinaryTree::PrintDots(int depth) {
	for(int i=0;i<depth;i++) {
		fprintf(ofp, "..");
	}
	fprintf(ofp, "%d\n", this->data);
}

void BinaryTree::MakeEmpty() {
	if(this != NULL) {
		this->left->MakeEmpty();
		this->right->MakeEmpty();
		delete this;
	}
}
