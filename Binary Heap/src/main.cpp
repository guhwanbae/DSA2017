/*
 * main.cpp
 *
 *  Created on: 2017. 4. 15.
 *      Author: guhwan
 */

#include <iostream>
#include <stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<limits.h>
#include "BinaryHeap.h"

using namespace std;

FILE *ifp, *ofp;

/****************************************************************************
 * MAIN FUNCTION                                                  *
 ****************************************************************************/

int main(int argc, char* argv[]) {

	cout << "This program is the Simulating of Binary Heap.." << endl;

	char		buffer[MAX_LINE];
	char		*token;
	int			keyVal;

	int			buildBuffer[HEAP_SIZE] = {0,};
	int			buildBufferSize = 0;
	char*		buildToken = NULL;

	int 		minVal = 0;

	if((ifp = fopen("input_Heap.txt", "r")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if((ofp = fopen("output_heap.txt", "w")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	BinaryHeap* heap = new BinaryHeap();

	while(fgets(buffer, MAX_LINE, ifp) != NULL)
	{
		token = strtok(buffer, " \t\n");
		if(token != NULL)
		{
			if(token[0] == '#')	continue;
			else if(!strcmp(token, "BUILD_HEAP"))
			{
				while((buildToken = strtok(NULL, "\t\n")) != NULL) {
					buildBuffer[buildBufferSize++] = atoi(buildToken);
				}
				cout << "Success : Catch the Keys" << endl;
				for(int index=0;index<buildBufferSize;++index) {
					cout << "BuildBuffer[" << index << "] : " << buildBuffer[index] << endl;
				}
				fprintf(ofp, "BUILD_HEAP(%d): ",buildBuffer[0]);
				heap->buildHeap(buildBuffer+1, buildBufferSize-1);
				heap->traverse(ofp);		fprintf(ofp,"\n");
				buildBufferSize = 0;
			}
			else if(!strcmp(token, "INSERT"))
			{
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "INSERT(%d): ", keyVal);
				heap->insert(keyVal,ofp);
			}
			else if(!strcmp(token, "DELETE_MIN"))
			{
				keyVal = atoi(strtok(NULL, " \t\n"));
				fprintf(ofp, "DELETE_MIN(%d): ", keyVal);
				minVal = heap->deleteMin(ofp);
			}
			else if(!strcmp(token, "PRINT"))
			{
				fprintf(ofp, "PRINT(%d): ", heap->getMin());
				heap->traverse(ofp);
			}
		}
	}

	cout << "Complete Simulating.." << endl;

	fclose(ifp);
	fclose(ofp);

	delete heap;
	heap = NULL;

	return true;
}




