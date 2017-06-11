/*
 * main.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT/GraphADT.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#ifndef CLOCK_BEGIN
#define CLOCK_BEGIN 0
#endif

#ifndef CLOCK_END
#define CLOCK_END 1
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
		printf("EXECUTION TIME: %f\n",(((float)t)/CLOCKS_PER_SEC));
	}
}

int main(int argc, char** argv) {
	cout << "This program is the Simulating of Graph ADT and Path Algorithms.." << endl << endl;

	clockRun(CLOCK_BEGIN);
	Graph* simulGraph = new Graph(7,12);
	simulGraph->showGraphComplexity();
	cout << "PROCESS : Init Graph ADT\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->insertEdge(0,1);
	simulGraph->insertEdge(0,2);
	simulGraph->insertEdge(0,3);
	simulGraph->insertEdge(1,3);
	simulGraph->insertEdge(1,4);
	simulGraph->insertEdge(2,5);
	simulGraph->insertEdge(3,2);
	simulGraph->insertEdge(3,5);
	simulGraph->insertEdge(3,6);
	simulGraph->insertEdge(4,3);
	simulGraph->insertEdge(4,6);
	simulGraph->insertEdge(6,5);
	simulGraph->printGraph();
	cout << "PROCESS : Insert Edges\t";	clockRun(CLOCK_END);
	cout << endl;


	clockRun(CLOCK_BEGIN);
	simulGraph->topologicalSort();
	cout << "PROCESS : Topological Sorting\t";	clockRun(CLOCK_END);
	cout << endl;

	simulGraph->showGraphComplexity();
	delete simulGraph; simulGraph = NULL;

	Graph* simulGraph2 = new Graph(7,12);
	/*
	simulGraph2->insertEdge(0,1,5.0);
	simulGraph2->insertEdge(0,2,10.0);
	simulGraph2->insertEdge(0,3,9.0);
	simulGraph2->insertEdge(1,2,3.0);
	simulGraph2->insertEdge(1,5,11.0);
	simulGraph2->insertEdge(2,3,7.0);
	simulGraph2->insertEdge(2,4,3.0);
	simulGraph2->insertEdge(2,5,10.0);
	simulGraph2->insertEdge(3,5,7.0);
	simulGraph2->insertEdge(3,6,12.0);
	simulGraph2->insertEdge(4,5,4.0);
	simulGraph2->insertEdge(5,6,2.0);

	simulGraph2->dijkstra(0);
	*/

	simulGraph = new Graph(15,50);
	simulGraph->showGraphComplexity();

	simulGraph->insertEdge(0,1,1.6);
	simulGraph->insertEdge(0,9,1);
	simulGraph->insertEdge(1,0,1.3);
	simulGraph->insertEdge(1,3,1);
	simulGraph->insertEdge(1,8,2.8);
	simulGraph->insertEdge(1,13,0.9);
	simulGraph->insertEdge(2,5,0.6);
	simulGraph->insertEdge(2,6,1.5);
	simulGraph->insertEdge(2,9,1.5);
	simulGraph->insertEdge(2,14,1.1);
	simulGraph->insertEdge(3,1,1);
	simulGraph->insertEdge(3,13,0.4);
	simulGraph->insertEdge(4,8,1.5);
	simulGraph->insertEdge(4,10,1.5);
	simulGraph->insertEdge(4,13,0.7);
	simulGraph->insertEdge(5,2,1.2);
	simulGraph->insertEdge(5,6,0.5);
	simulGraph->insertEdge(5,8,1.1);
	simulGraph->insertEdge(5,9,0.4);
	simulGraph->insertEdge(6,2,1.2);
	simulGraph->insertEdge(6,5,0.5);
	simulGraph->insertEdge(6,8,1.6);
	simulGraph->insertEdge(6,10,1.1);
	simulGraph->insertEdge(6,11,1);
	simulGraph->insertEdge(6,12,0.8);
	simulGraph->insertEdge(7,10,1.1);
	simulGraph->insertEdge(7,12,0.3);
	simulGraph->insertEdge(8,1,2.4);
	simulGraph->insertEdge(8,4,1.7);
	simulGraph->insertEdge(8,5,1.6);
	simulGraph->insertEdge(8,6,1.3);
	simulGraph->insertEdge(9,0,1.3);
	simulGraph->insertEdge(9,2,1.2);
	simulGraph->insertEdge(9,5,0.4);
	simulGraph->insertEdge(10,4,1.7);
	simulGraph->insertEdge(10,6,1);
	simulGraph->insertEdge(10,7,0.8);
	simulGraph->insertEdge(10,12,0.3);
	simulGraph->insertEdge(11,6,1.1);
	simulGraph->insertEdge(11,12,0.4);
	simulGraph->insertEdge(11,14,0.3);
	simulGraph->insertEdge(12,6,0.8);
	simulGraph->insertEdge(12,7,0.3);
	simulGraph->insertEdge(12,10,0.3);
	simulGraph->insertEdge(12,11,0.4);
	simulGraph->insertEdge(13,1,1);
	simulGraph->insertEdge(13,3,0.4);
	simulGraph->insertEdge(13,4,0.6);
	simulGraph->insertEdge(14,2,1.1);
	simulGraph->insertEdge(14,11,0.3);


	simulGraph->showGraphComplexity();
	simulGraph->printGraph();

	clockRun(CLOCK_BEGIN);
	simulGraph->breadthFirstSearch(8);
	cout << "PROCESS : Breath First Search\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->breadthFirstSearch(14);
	cout << "PROCESS : Breath First Search\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->depthFirstSearch(8);
	cout << "PROCESS : Depth First Search\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->depthFirstSearch(14);
	cout << "PROCESS : Depth First Search\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->dijkstra(8);
	cout << "PROCESS : Dijkstra Algorithm(Shortest Path Algorithm\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->dijkstra(14);
	cout << "PROCESS : Dijkstra Algorithm(Shortest Path Algorithm\t";	clockRun(CLOCK_END);
	cout << endl;

	clockRun(CLOCK_BEGIN);
	simulGraph->floydWarshall();
	cout << "PROCESS : Floyd Warshall Algorithm(Shortest Path Algorithm\t";	clockRun(CLOCK_END);
	cout << endl;


	delete simulGraph2; simulGraph2 = NULL;


	delete simulGraph; simulGraph = NULL;

	cout << endl <<  "Complete Simulating..." << endl;

	return true;
}
