/*
 * main.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT/GraphADT.h"
#include "SimulatorGraph.h"

int main(int argc, char** argv) {
	GraphSimulator* simGraph = new GraphSimulator();

	simGraph->openFileIO("input_graph.txt","output_graph.txt");
	simGraph->SimulatingGraph();
	simGraph->closeFileIO();

	delete simGraph;
	simGraph = NULL;

	return true;
}
