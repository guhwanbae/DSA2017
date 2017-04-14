/*
 * AVLTree.cpp
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */
/*
 * AVL.cpp
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */
#include <iostream>
#include "AVLTree.h"
using namespace std;

AVL* root;

AVL::AVL(dataType keyVal, AVL* L, AVL* R, int H) {
	this->height = H;
	this->data = keyVal;
	this->left = L;
	this->right = R;
}

AVL* AVL::findMin() {
	if (this != NULL) {
		if (this->left != NULL) {
			return this->left->findMin();
		} else {
			return this;
		}
	}
	return NULL;
}

AVL* AVL::findMax() {
	if (this != NULL) {
		if (this->right != NULL) {
			return this->right->findMax();
		} else {
			return this;
		}
	}
	return NULL;
}

AVL* AVL::contains(dataType keyVal) {
	if (this == NULL) {
		fprintf(ofp, "Node Not Found\n");
		cout << "Node Not Found" << endl;
		return this;
	} else {
		if (this->data > keyVal) {
			left->contains(keyVal);
		} else if (this->data < keyVal) {
			right->contains(keyVal);
		} else {
			fprintf(ofp, "Node Found\n");
			cout << "Node Found" << endl;
			return this;
		}
	}
	return this;
}

AVL* AVL::insert(dataType keyVal) {
	if (this == NULL) {
		fprintf(ofp, "Node Inserted\n");
		cout << "Node Inserted" << endl;
		return new AVL(keyVal, NULL, NULL, 0); //leaf node's height is zero
	} else {
		if (this->data > keyVal) {
			this->left = this->left->insert(keyVal);
		} else if (this->data < keyVal) {
			this->right = this->right->insert(keyVal);
		} else {
			fprintf(ofp, "Duplicated Node\n");
			cout << "Duplicated Node" << endl;
			return this;
		}
	}
	return balance();
}

AVL* AVL::remove(dataType keyVal, callType removeType) {
	if(this == NULL) {
		fprintf(ofp, "Node Not Found\n");
		cout << "Node not found!" << endl;
		printTrigger = REMOVE_NOTFOUND;
		return NULL;
	}

	if(data > keyVal)
		left = left->remove(keyVal, removeType);
	else if(data < keyVal)
		right = right->remove(keyVal, removeType);
	else { //found keyVal
		if(left == NULL && right == NULL) {
			delete this;
			return NULL;
		}
		else if(left == NULL) {
			delete this;
			return right;
		}
		else if(right == NULL) {
			delete this;
			return left;
		}
		else {
			if(removeType == REMOVE_L) {
				data = left->findMax()->data; //pull up the max value in left subtree
				left = left->remove(data, removeType);
			}
			else if(removeType == REMOVE_R) {
				data = right->findMin()->data;
				right = right->remove(data, removeType);
			}
			fprintf(ofp, "Node Replaced with Key(%d)\n", data);
			cout << "Node Replaced with Key(" << data << ")" << endl;
			printTrigger = REMOVE_REPLACED;
		}
	}
	return balance();
}

int AVL::getHeight() {
	if(this == NULL)
		return LEAF_HEIGHT;
	else
		return height;
}

AVL* AVL::balance() {
	if (this == NULL)
		return NULL;
	else if (left->getHeight() - right->getHeight() > ALLOWED_IMBALANCE) { //left logner
		if(left->left->getHeight() >= left->right->getHeight())
			return singleRotationLeft(); //single rotate with clockwise , LL case
		else
			return doubleRotationLeft(); //double rotate, LR case, doubly operate = countclockwise(single) -> clockwise(single)
	}
	else if (right->getHeight() - left->getHeight() > ALLOWED_IMBALANCE) { //right longer
		if(right->right->getHeight() >= right->left->getHeight())
			return singleRotationRight(); //single rotate with countclockwise , RR case
		else
			return doubleRotationRight(); //double rotate, RL case, doubly operate = clockwise(single) -> countclockwise(single)
	}
	else {
		height = 1 + maxHeight(left->getHeight(), right->getHeight());
		return this;
	}
	return this;
}

//rotate with clockwise
AVL* AVL::singleRotationLeft() {
	AVL* TobeReplacedNode = left;

	this->left = TobeReplacedNode->right;
	TobeReplacedNode->right = this;

	height = 1 + maxHeight(this->left->getHeight(),this->right->getHeight());
	TobeReplacedNode->height = 1 + maxHeight(TobeReplacedNode->left->getHeight(),TobeReplacedNode->right->getHeight());

	return TobeReplacedNode;
}

//(right)rotate with countclockwise(reference is unbalanced node's left) -> (left)rotate with clockwise(reference is unblanced node)
AVL* AVL::doubleRotationLeft() {
	left = left->singleRotationRight();
	return this->singleRotationLeft();
}

//rotate with countclockwise
AVL* AVL::singleRotationRight() {
	AVL* TobeReplacedNode = right;

	this->right = TobeReplacedNode->left;
	TobeReplacedNode->left = this;

	height = 1 + maxHeight(this->left->getHeight(),this->right->getHeight());
	TobeReplacedNode->height = 1 + maxHeight(TobeReplacedNode->left->getHeight(),TobeReplacedNode->right->getHeight());

	return TobeReplacedNode;
}

//(left)rotate with clockwise(reference is unbalanced node's right) -> (right)rotate with countclockwise(reference is unblanced node)
AVL* AVL::doubleRotationRight() {
	right = right->singleRotationLeft();
	return singleRotationRight();
}

void AVL::preOrderTraversal(int depth) {
	if (this != NULL) {
		this->PrintDots(depth);
		if (this->left != NULL) {
			this->left->preOrderTraversal(depth + 1);
		}
		if (this->right != NULL) {
			this->right->preOrderTraversal(depth + 1);
		}
	}
}

void AVL::inOrderTraversal(int depth) {
	if (this != NULL) {
		if (this->left != NULL) {
			this->left->inOrderTraversal(depth + 1);
		}
		this->PrintDots(depth);
		if (this->right != NULL) {
			this->right->inOrderTraversal(depth + 1);
		}
	}
}

void AVL::postOrderTraversal(int depth) {
	if (this != NULL) {
		if (this->left != NULL) {
			this->left->postOrderTraversal(depth + 1);
		}
		if (this->right != NULL) {
			this->right->postOrderTraversal(depth + 1);
		}
		this->PrintDots(depth);
	}
}

void AVL::PrintDots(int depth) {
	for (int i = 0; i < depth; i++) {
		fprintf(ofp,"..");
		cout << "..";
	}
	fprintf(ofp,"%d\n",this->data);
	cout << this->data << endl;
}

int AVL::maxHeight(int H1, int H2) {
	if(H1 > H2)
		return H1;
	else if(H1 < H2)
		return H2;
	else
		return H1;
}

void AVL::MakeEmpty() {
	if (this != NULL) {
		this->left->MakeEmpty();
		this->right->MakeEmpty();
		delete this;
	}
}

