/*
 * OutputCheck.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: hyjeong
 */


#include	<iostream>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<time.h>
#include	"OutputCheck.h"

using namespace std;

FILE *fp1, *fp2;

//--------------------------------------------------------------//
//						Main Function							//
//==============================================================//
int	main(int argc, char* argv[])	{
	srand((unsigned) time(NULL));

	int		counter = 0;

	const char *fileName1 = argv[1], *fileName2 = argv[2];
	char	line1[MAX_LINE], line2[MAX_LINE];

	if((fp1 = fopen(fileName1, "r")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));

		return false;
	}

	if((fp2 = fopen(fileName2, "r")) == NULL)
	{
		printf("File Open Error(%s)\n", strerror(errno));

		return false;
	}

	while(fgets(line1, MAX_LINE, fp1) != NULL && fgets(line2, MAX_LINE, fp2) != NULL)
	{
		++counter;
		if(strcmp(line1, line2))
		{
			printf("Mismatch in line %d\n", counter);
			printf("\t%s:\t%s", fileName1, line1);
			printf("\t%s:\t%s", fileName2, line2);

			return false;
		}
	}

	printf("Success!\n");

	fclose(fp1);
	fclose(fp2);

	return true;
}
