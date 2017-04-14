/*
 * DLL.h
 *
 *  Created on: 2017. 3. 23.
 *      Author: guhwan
 */

#ifndef SRC_DLL_H_
#define SRC_DLL_H_

#include <stdio.h>

#ifndef NULL
#define NULL	0
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef FAILURE
#define FAILURE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef MAX_SIZE
#define MAX_SIZE	1000
#endif

#ifndef MAX_LINE
#define MAX_LINE	2048
#endif

#ifndef MAX_VALUE
#define MAX_VALUE	10000
#endif

class DLL {
private :
	int data;
	DLL* next;
	DLL* prev;
public :
	DLL(int Val=0, DLL* next_node=NULL, DLL* previous_node=NULL) : data(Val), next(next_node), prev(previous_node) {}
//	~DLL();

	int insert(int Val, FILE* fp);
	int insertkth(int index, int Val);
	DLL* search(int Val, FILE* fp);
	int remove(int Val, FILE* fp);

	void traverse(FILE* fp);
	void traverse_backword(void);
};

extern DLL* head;
extern DLL* tail;

#endif /* SRC_DLL_H_ */
