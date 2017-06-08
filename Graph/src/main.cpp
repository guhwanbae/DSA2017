/*
 * main.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT/GraphADT.h"
#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {
	cout << "This program is the Simulating of Graph ADT and Path Algorithms.." << endl << endl;

	Graph* simulGraph = new Graph(7,12);
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

	cout << endl <<  "Complete Simulating..." << endl;

	return true;
}
