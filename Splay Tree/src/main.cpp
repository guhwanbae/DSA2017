/*
 * main.cpp
 *
 *  Created on: 2017. 4. 9.
 *      Author: guhwan
 */
#include <iostream>
#include "SplayTree.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
using namespace std;

FILE *ifp, *ofp;
int printTrigger = 0;

int main(int argc, char* argv[]) {
	cout << "This program is simulator of Splay Tree..." << endl;

	char buffer[MAX_LINE];
	char *token, *str = NULL;
	dataType keyVal;

	if ((ifp = fopen("input_Splay.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_Splay.txt", "w")) == NULL) {
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
				printTrigger = REMOVE_INIT;
				fprintf(ofp, "REMOVE(%d): ", keyVal);
				if (!strcmp(token, "L")) {
					root->remove(keyVal, REMOVE_L);
				}
				else if (!strcmp(token, "R")) {
					root->remove(keyVal, REMOVE_R);
				}
				root->printKeywords(PRINT, printTrigger);
			}
			else if (!strcmp(token, "CONTAINS")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "CONTAINS(%d): ", keyVal);
				printTrigger = CONTAINS_INIT;
				root = root->contains(keyVal);
				root->printKeywords(PRINT, printTrigger);
			}
			else if (!strcmp(token, "PREORDER")) {
				fprintf(ofp, "\nPre-order Traversal:\n");
				root->preOrderTraversal(0);	fprintf(ofp, "\n");
			}
			else if (!strcmp(token, "INORDER")) {
				fprintf(ofp, "In-order Traversal:\n");
				root->inOrderTraversal(0);
			}
			else if (!strcmp(token, "POSTORDER")) {
				fprintf(ofp, "\nPost-order Traversal:\n");
				root->postOrderTraversal(0);
			}
			else if (!strcmp(token, "EMPTY")) {
				fprintf(ofp, "MAKE_EMPTY: \n");
				root->makeEmpty();	root = NULL;
			}
		}
	}

	cout << "Simulating complete.." << endl;

	fclose(ifp);
	fclose(ofp);

	if (root != NULL) {
		root->makeEmpty();		root = NULL;
	}

	return true;
}

