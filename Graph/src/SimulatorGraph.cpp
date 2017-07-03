/*
 * SimulatorGraph.cpp
 *
 *  Created on: 2017. 6. 17.
 *      Author: ghbae
 */

#include "SimulatorGraph.h"
#include "GraphADT/GraphADT.h"

GraphSimulator::GraphSimulator() {
	cout << "# This program is the Simulating of Graph ADT and Algorithms.." << endl << endl;

	simGraph = NULL;	graphMode = 0;
	ifp = NULL;	ofp = NULL;
	t = clock();
}
GraphSimulator::~GraphSimulator() {
	closeFileIO();
	clearGraph();

	cout << "# Delete Graph ADT.." << endl;
	cout << "# Complete Graph Simulating.." << endl << endl;
}

void GraphSimulator::clearGraph() {
	if (simGraph != NULL) {
		delete simGraph;
		simGraph = NULL;
	}
}

void GraphSimulator::openFileIO(char* fileNameInput,char* fileNameOutput) {
	if ((ifp = fopen(fileNameInput, "r")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
	}
	if ((ofp = fopen(fileNameOutput, "w")) == NULL) {
		printf("File Open Error(%s)\n", strerror(errno));
	}
}

void GraphSimulator::closeFileIO() {
	if (ifp != NULL) {
		fclose(ifp);		ifp = NULL;
	}
	if (ofp != NULL) {
		fclose(ofp);		ofp = NULL;
	}
}

void GraphSimulator::clockRun() {
	t = clock();
}
void GraphSimulator::clockStop(char* nameProcess) {
	t = clock() - t;
	printf("PROCESS : %s\t", nameProcess);
	printf("EXECUTION TIME: %f\n", (((float) t) / CLOCKS_PER_SEC));
}

void GraphSimulator::makeNewGraph(int mode, int vertexSize, int edgeSize) {
	clearGraph();
	graphMode = mode;
	simGraph = new Graph(vertexSize, edgeSize,ofp);
	printf("# Make a new Graph : G(V,E) = G(%2d,%2d)\n",vertexSize,edgeSize);
}

void GraphSimulator::SimulatingGraph() {
	char buffer[MAX_LINE];
	char *token;

	while (fgets(buffer, MAX_LINE, ifp) != NULL) {
		token = strtok(buffer, " \t\n");
		if (token != NULL) {
			if (token[0] == '#') {
				continue;
			} else if (!strcmp(token, "GRAPH")) {
				int mode = atoi(strtok(NULL, " \t\n"));
				int vertexSize = atoi(strtok(NULL, " \t\n"));
				int edgeSize = atoi(strtok(NULL, " \t\n"));

				makeNewGraph(mode, vertexSize, edgeSize);
			} else if (!strcmp(token, "EDGE")) {
				int srcID = atoi(strtok(NULL, " \t\n"));
				int destID = atoi(strtok(NULL, " \t\n"));
				if (graphMode != NONE_WEIGHTED_GRAPH) {
					double cost = atof(strtok(NULL, " \t\n"));
					simGraph->insertEdge(srcID, destID, cost);
				} else {
					simGraph->insertEdge(srcID, destID);
				}
			} else if (!strcmp(token, "PRINT")) {
				clockRun();
				simGraph->printGraph();
				clockStop("Print Graph\t\t\t\t\t");
			} else if (!strcmp(token, "TOPOLOGICAL_SORT")) {
				clockRun();
				simGraph->topologicalSort();
				clockStop("Topological Sort\t\t\t\t\t");
			} else if (!strcmp(token, "BREATH-FIRST_SEARCH")) {
				int srcID = atoi(strtok(NULL, " \t\n"));

				clockRun();
				simGraph->breadthFirstSearch(srcID);
				clockStop("Breath First Search - Graph Traversal\t\t");
			} else if (!strcmp(token, "DEPTH-FIRST_SEARCH")) {
				int srcID = atoi(strtok(NULL, " \t\n"));

				clockRun();
				simGraph->depthFirstSearch(srcID);
				clockStop("Depht First Search  - Graph Traversal\t\t");
			} else if (!strcmp(token, "DIJKSTRA")) {
				int srcID = atoi(strtok(NULL, " \t\n"));

				clockRun();
				simGraph->dijkstra(srcID);
				clockStop("Dijkstra Algorithm - Shortest Path Algorithm\t");
			} else if (!strcmp(token, "FLOYD-WARSHALL")) {
				clockRun();
				simGraph->floydWarshall();
				clockStop("Floyd Warshall Algorithm - Shortest Path Algorithm");
			} else if (!strcmp(token, "KRUSKAL")) {
				clockRun();
				simGraph->kruskal();
				clockStop("Kruskal Algorithm - Minimal Spanning Tree\t");
			}
		}
	}
}

