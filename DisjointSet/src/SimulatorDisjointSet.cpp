/*
 * SimulatorDisjointSet.cpp

 *
 *  Created on: 2017. 5. 29.
 *      Author: ghbae
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include "SimulatorDisjointSet.h"

using namespace std;

SDS::SDS(int setType) {
	type = setType;
	ifp = NULL; ofp = NULL;
	myDisjointSet = NULL;
}

SDS::~SDS() {
	if(myDisjointSet != NULL) {
		delete myDisjointSet;	myDisjointSet = NULL;
	}
	if(ifp != NULL) {
		fclose(ifp);	ifp = NULL;
	}
	if(ofp != NULL) {
		fclose(ofp);	ofp = NULL;
	}
}

void SDS::SimulatingBasic() {
	if ((ifp = fopen("input_disjoint_set.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
	}
	if (type == DISJOINT_SET_BASIC) {
		if ((ofp = fopen("output_disjoint_set_basic.txt", "w")) == NULL) {
			printf("File Open Error(%s)\n", strerror(errno));
		}
	}
}

void SDS::SimulatingSize() {
	if ((ifp = fopen("input_disjoint_set.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
	}
	if (type == DISJOINT_SET_SIZE) {
		if ((ofp = fopen("output_disjoint_set_size.txt", "w")) == NULL) {
			printf("File Open Error(%s)\n", strerror(errno));
		}
	}
}

void SDS::SimulatingComp() {
	if ((ifp = fopen("input_disjoint_set.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
	}
	if (type == DISJOINT_SET_COMP) {
		if ((ofp = fopen("output_disjoint_set_comp.txt", "w")) == NULL) {
			printf("File Open Error(%s)\n", strerror(errno));
		}
	}
}

void SDS::SimulatingBasic() {
	char buffer[MAX_LINE];
	char *token;
	int keyVal1, keyVal2;

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");
		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "SET_SIZE")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet = new DisjointSet(keyVal1, ofp);
			} else if (!strcmp(token, "UNION")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));		keyVal2 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->unionSets(keyVal1, keyVal2);
			} else if (!strcmp(token, "FIND")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->Find(keyVal1);
			} else if (!strcmp(token, "PRINT")) {
				myDisjointSet->print();
			}
		}
	}
}

void SDS::SimulatingSize() {
	char buffer[MAX_LINE];
	char *token;
	int keyVal1, keyVal2;

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");
		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "SET_SIZE")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet = new DisjointSet(keyVal1, ofp);
			} else if (!strcmp(token, "UNION")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));		keyVal2 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->unionBySize(keyVal1, keyVal2);
			} else if (!strcmp(token, "FIND")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->Find(keyVal1);
			} else if (!strcmp(token, "PRINT")) {
				myDisjointSet->print();
			}
		}
	}
}

void SDS::SimulatingComp() {
	char buffer[MAX_LINE];
	char *token;
	int keyVal1, keyVal2;

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");
		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "SET_SIZE")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet = new DisjointSet(keyVal1, ofp);
			} else if (!strcmp(token, "UNION")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));		keyVal2 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->unionBySizeWithComp(keyVal1, keyVal2);
			} else if (!strcmp(token, "FIND")) {
				keyVal1 = atoi(strtok(NULL, " \t\n"));
				myDisjointSet->FindAndCompress(keyVal1);
			} else if (!strcmp(token, "PRINT")) {
				myDisjointSet->print();
			}
		}
	}
}
