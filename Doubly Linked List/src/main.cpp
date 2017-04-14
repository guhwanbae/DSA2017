/*
 * main.cpp
 *
 *  Created on: 2017. 3. 29.
 *      Author: guhwan
 */

#include	<iostream>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<time.h>
#include "DLL.h"

using namespace std;
FILE *ifp, *ofp;

int main(void) {
	srand((unsigned) time(NULL));

	char buffer[MAX_LINE];
	char *token, *str = NULL;
	int keyVal;
	int state = 0;

	head = NULL;
	tail = NULL;
	cout << "This Program is simulator of DLL(Doubly Linked List)..." << endl;

	if ((ifp = fopen("input_DLL.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_DLL.txt", "w")) == NULL) {
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
				if (head == NULL && tail == NULL) {
					head = new DLL(keyVal, NULL, NULL);
					tail = head;
					head->traverse(ofp);
				}
				else {
					state = head->insert(keyVal, ofp);
					if(state == FAILURE) ;
					else head->traverse(ofp);
				}
			}
			else if (!strcmp(token, "FIND")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "FIND(%d): ", keyVal);
				head->search(keyVal, ofp);
			}
			else if (!strcmp(token, "REMOVE")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "REMOVE(%d): ", keyVal);
				state = head->remove(keyVal, ofp);
				if(state == FAILURE) ;
				else head->traverse(ofp);
			}
		}
	}

	fclose(ifp);
	fclose(ofp);

	return SUCCESS;
}

