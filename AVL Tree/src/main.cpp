/*
 * main.cpp
 *
 *  Created on: 2017. 4. 8.
 *      Author: guhwan
 */

#include <iostream>
#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
using namespace std;

FILE *ifp, *ofp;
int printTrigger = REMOVE_DELETED;

int main(int argc, char* argv[]) {
	cout << "This program is simulator of AVL Tree..." << endl;

	char buffer[MAX_LINE];
	char *token, *str = NULL;
	dataType keyVal;

	if ((ifp = fopen("input_AVL.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_AVL.txt", "w")) == NULL) {
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
				cout << "INSERT(" << keyVal << "): " ;
				root = root->insert(keyVal);
			}
			else if (!strcmp(token, "REMOVE")) {
				token = strtok(NULL, " \t\n");
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "REMOVE(%d): ", keyVal);
				cout << "REMOVE(" << keyVal << "): " ;
				if (!strcmp(token, "L")) {
					root = root->remove(keyVal, REMOVE_L);
				}
				else if (!strcmp(token, "R")) {
					root = root->remove(keyVal, REMOVE_R);
				}
				if (printTrigger == REMOVE_DELETED) {
					fprintf(ofp, "Node Deleted\n");
					cout << "Node Deleted" << endl;
				}
				else {
					printTrigger = REMOVE_DELETED; //set default..
				}
			}
			else if (!strcmp(token, "CONTAINS")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "CONTAINS(%d): ", keyVal);
				cout << "CONTAINS(" << keyVal << "): ";
				root->contains(keyVal);
			}
			else if (!strcmp(token, "PREORDER")) {
				fprintf(ofp, "\n");
				fprintf(ofp, "Pre-order Traversal:\n");
				cout << "Pre-order Traversal:" << endl;
				root->preOrderTraversal(0);
				fprintf(ofp, "\n");
			}
			else if (!strcmp(token, "INORDER")) {
				fprintf(ofp, "In-order Traversal:\n");
				cout << "In-order Traversal:" << endl;
				root->inOrderTraversal(0);
			}
			else if (!strcmp(token, "POSTORDER")) {
				fprintf(ofp, "\n");
				fprintf(ofp, "Post-order Traversal:\n");
				cout << "Post-order Traversal:" << endl;
				root->postOrderTraversal(0);
			}
			else if (!strcmp(token, "EMPTY")) {
				fprintf(ofp, "MAKE_EMPTY: \n");
				cout << "MAKE_EMPTY: " << endl;
				root->MakeEmpty();
				root = NULL;
			}
		}
	}

	cout << "Simulating complete.." << endl;

	fclose(ifp);
	fclose(ofp);

	if (root != NULL) {
		root->MakeEmpty();
		root = NULL;
	}

	return true;
}

