/*
 * main.cpp
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */

#include <iostream>
#include "BinaryTree.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
using namespace std;

FILE *ifp, *ofp;

int printTrigger = REMOVE_DELETED;

int main(int argc, char* argv[]) {

	char buffer[MAX_LINE];
	char *token, *str = NULL;
	dataType keyVal;

	cout << "This program is Simulator of Binary search tree.." << endl;

	if ((ifp = fopen("input_BST.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_BST.txt", "w")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");

		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "INSERT")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "INSERT(%d): ", keyVal);
				root = root->insert(keyVal);
			}
			else if (!strcmp(token, "REMOVE")) {
				token = strtok(NULL, " \t\n");
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "REMOVE(%d): ", keyVal);
				if(!strcmp(token,"L")) {
					root = root->remove_L(keyVal);
				}
				else if(!strcmp(token,"R")) {
					root = root->remove_R(keyVal);
				}
				if(printTrigger == REMOVE_DELETED) {
					fprintf(ofp, "Node Deleted\n");
				}
				else {
					printTrigger = REMOVE_DELETED; //set default..
				}
			}
			else if (!strcmp(token, "CONTAINS")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "CONTAINS(%d): ", keyVal);
				root->contains(keyVal);
			}
			else if (!strcmp(token, "PREORDER")) {
				fprintf(ofp, "\n");
				fprintf(ofp, "Pre-order Traversal:\n");
				root->preOrderTraversal(0);
				fprintf(ofp, "\n");
			}
			else if (!strcmp(token, "INORDER")) {
				fprintf(ofp, "In-order Traversal:\n");
				root->inOrderTraversal(0);
			}
			else if (!strcmp(token, "POSTORDER")) {
				fprintf(ofp, "\n");
				fprintf(ofp, "Post-order Traversal:\n");
				root->postOrderTraversal(0);
			}
			else if (!strcmp(token, "EMPTY")) {
				fprintf(ofp, "MAKE_EMPTY: \n");
				root->MakeEmpty();
				root = NULL;
			}
		}
	}

	cout << "Simulating complete.." << endl;

	fclose(ifp);
	fclose(ofp);

	if(root != NULL) {
		root->MakeEmpty();
		root = NULL;
	}

	return true;
}

