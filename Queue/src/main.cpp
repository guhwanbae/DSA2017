/*
 * main.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: guhwan
 */

#include <iostream>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<time.h>
#include "Queue.h"

using namespace std;

FILE *ifp, *ofp;

int main(int argc, char* argv[]) {
	char buffer[MAX_LINE];
	char *token, *str = NULL;
	int keyVal;
	int state = 0;

	Queue *myQ;
	myQ = new Queue();

	cout << "This Program is simulator of Queue(Circular Queue)..." << endl;

	if ((ifp = fopen("input_Queue.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_Queue.txt", "w")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");

		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "ENQUEUE")) {
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "ENQUEUE(%d): ", keyVal);
				state = myQ->enQueue(keyVal,ofp);
				if(state == TRUE)
					myQ->printQueue(ofp);
			}
			else if (!strcmp(token, "DEQUEUE")) {
				fprintf(ofp, "DEQUEUE: ");
				state = myQ->deQueue(ofp);
				if(state != (MAX_VALUE+1))
					myQ->printQueue(ofp);
			}
		}
	}

	fclose(ifp);
	fclose(ofp);

	delete myQ;

	return SUCCESS;
}

