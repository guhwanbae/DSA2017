/*
 * main.cpp
 *
 *  Created on: 2017. 5. 18.
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
#include "Sorting.h"
using namespace std;

FILE* ifp; FILE* ofp;

#ifndef CLOCK_BEGIN
#define CLOCK_BEGIN 0
#endif

#ifndef CLOCK_END
#define CLOCK_END 1
#endif

#ifndef CLOCK_CONSOLE_ONLY
#define CLOCK_CONSOLE_ONLY 1
#endif

/****************************************************************************
 * FUNCTIONS OF MEASURE OF TIME                                   *
 ****************************************************************************/
clock_t t;
void clockRun(int argu) {
	if(argu == CLOCK_BEGIN) {
		t = clock();
	}
	else if(argu == CLOCK_END) {
		t = clock() - t;
		fprintf(ofp, "EXECUTION TIME: %8.6f\n",(((float)t)/CLOCKS_PER_SEC));
		printf("EXECUTION TIME: %f\n",(((float)t)/CLOCKS_PER_SEC));
	}
}
void clockRun(int argu1, int argu2) {
	if(argu1 == CLOCK_BEGIN) {
		t = clock();
	}
	else if(argu1 == CLOCK_END && argu2 == CLOCK_CONSOLE_ONLY) {
		t = clock() - t;
		printf("EXECUTION TIME: %f\n",(((float)t)/CLOCKS_PER_SEC));
	}
}

void clearArr(int* arr, int size) {
	for(int index=0; index<size; ++index) {
		arr[index] = 0;
	}
}

/****************************************************************************
 * MAIN FUNCTION                                                  *
 ****************************************************************************/
int main(int argc, char* argv[]) {
	cout << "This program is the Simulating of Sorting Algorithm.." << endl;

	char buffer[MAX_LINE];
	char *token;

	int inputBuffer[MAX_SIZE] = { 0, };
	int inputBufferSize = 0;

	if ((ifp = fopen("input_sorting.txt", "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if ((ofp = fopen("output_sorting.txt", "w")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	sortingADT* Sorting;

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");
		if (token != NULL) {
			if (token[0] == '#')
				continue;
			else if (!strcmp(token, "INPUT")) {
				inputBufferSize = atoi(strtok(NULL, " \t\n"));
				for (int index = 0; index < inputBufferSize; ++index) {
					inputBuffer[index] = atoi(strtok(NULL, " \t\n"));
				}
				fprintf(ofp, "INPUT(%d):\t", inputBufferSize);
				printf("INPUT(%d):\n", inputBufferSize);
				printf("Initializing..\t");	clockRun(CLOCK_BEGIN, CLOCK_CONSOLE_ONLY);
				Sorting = new sortingADT(inputBuffer, inputBufferSize);
				Sorting->print(ofp);	clockRun(CLOCK_END, CLOCK_CONSOLE_ONLY);
				inputBufferSize = 0;
			} else if (!strcmp(token, "INSERTION_SORT")) {
				fprintf(ofp, "INSERTION_SORT:");
				printf("INSERTION_SORT:\t");
				//Sorting->copyBuffer();
				clockRun(CLOCK_BEGIN);
				Sorting->insertionSort();
				Sorting->print(ofp);
				clockRun(CLOCK_END);
			} else if (!strcmp(token, "HEAPSORT")) {
				fprintf(ofp, "HEAPSORT:\t");
				printf("HEAPSORT:\t\t");
				Sorting->copyBuffer();
				clockRun(CLOCK_BEGIN);
				Sorting->heapSort();
				Sorting->print(ofp);
				clockRun(CLOCK_END);
			} else if (!strcmp(token, "QUICKSORT")) {
				fprintf(ofp, "QUICKSORT:\t");
				printf("QUICKSORT\t\t");
				Sorting->copyBuffer();
				clockRun(CLOCK_BEGIN);
				Sorting->quickSort();
				Sorting->print(ofp);
				clockRun(CLOCK_END);
			} else if (!strcmp(token, "RADIX_SORT")) {
				fprintf(ofp, "RADIX_SORT:\t");
				printf("RADIX_SORT:\t\t");
				Sorting->copyBuffer();
				clockRun(CLOCK_BEGIN);
				Sorting->radixSort(ofp);
				Sorting->print(ofp);
				clockRun(CLOCK_END);

				printf("Set Clear..\t\t");
				clockRun(CLOCK_BEGIN,CLOCK_CONSOLE_ONLY);
				clearArr(inputBuffer,inputBufferSize);
				delete Sorting;
				Sorting = NULL;
				clockRun(CLOCK_END,CLOCK_CONSOLE_ONLY);
			}
		}
	}

	cout << "Complete Simulating.." << endl;

	fclose (ifp);
	fclose (ofp);

	delete Sorting;
	Sorting = NULL;

	return true;
}

