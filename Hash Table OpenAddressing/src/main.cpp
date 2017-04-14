/*
 * main.cpp
 *
 *  Created on: 2017. 4. 14.
 *      Author: guhwan
 */
#include <iostream>
#include <stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<limits.h>
#include "HashTableOpenAddressing.h"

using namespace std;

FILE *ifp, *ofp;

/****************************************************************************
 * MAIN FUNCTION                                                  *
 ****************************************************************************/

int main(int argc, char* argv[]) {

	cout << "This program is the Simulating of Hash Table with Open Addressing.." << endl;

	char		buffer[MAX_LINE];
	char		*token;
	int			keyVal;

	HashTable	*openAddressing = new HashTable(INIT_PRIME,INIT_R);

	if((ifp = fopen("input_Hash.txt", "r")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	if((ofp = fopen("output_Hash.txt", "w")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));
		return false;
	}

	while(fgets(buffer, MAX_LINE, ifp) != NULL)
	{
		token = strtok(buffer, " \t\n");

		if(token != NULL)
		{
			if(token[0] == '#')	continue;
			else if(!strcmp(token, "INSERT"))
			{
				keyVal = atoi(strtok(NULL, " \t\n"));
				openAddressing->insert(keyVal, ofp);
			}
			else if(!strcmp(token, "FIND"))
			{
				keyVal = atoi(strtok(NULL, " \t\n"));
				openAddressing->find(keyVal, ofp);
			}
			else if(!strcmp(token, "REMOVE"))
			{
				keyVal = atoi(strtok(NULL, " \t\n"));
				openAddressing->remove(keyVal, ofp);
			}
		}
	}

	openAddressing->traverse(ofp);

	cout << "Complete Simulating.." << endl;

	fclose(ifp);
	fclose(ofp);

	return true;
}
