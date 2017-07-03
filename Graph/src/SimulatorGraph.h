/*
 * SimulatorGraph.h
 *
 *  Created on: 2017. 6. 17.
 *      Author: ghbae
 */

#ifndef SRC_SIMULATORGRAPH_H_
#define SRC_SIMULATORGRAPH_H_

#include "GraphADT/GraphADT.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <math.h>

/****************************************************************************
 * MACROS FOR FILE I/O RULES                                       *
 ****************************************************************************/
#define MAX_LINE	2048

#ifndef NONE_WEIGHTED_GRAPH
#define NONE_WEIGHTED_GRAPH 0
#endif
#ifndef WEIGHTED_DAG
#define WEIGHTED_DAG 1
#endif
#ifndef MULTI_GRAPH
#define MULTI_GRAPH 2
#endif

class GraphSimulator {
private :
	FILE *ifp, *ofp;
	clock_t t;

	Graph* simGraph;
	int graphMode;
public :
	GraphSimulator();
	~GraphSimulator();

	void openFileIO(char*,char*);
	void closeFileIO();

	void SimulatingGraph();
private :
	void clockRun();
	void clockStop(char*);

	void makeNewGraph(int,int,int);

	void clearGraph();
};

#endif /* SRC_SIMULATORGRAPH_H_ */
