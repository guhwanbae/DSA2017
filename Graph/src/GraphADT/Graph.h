/*
 * Graph.h
 *
 *  Created on: 2017. 5. 29.
 *      Author: ghbae
 */

#ifndef SRC_GRAPHADT_GRAPH_H_
#define SRC_GRAPHADT_GRAPH_H_

#include "Vertex.h"
#include "Edge.h"

class Graph {
private :
	Vertex** vertex;
	int vertexSize;
	int edgeSize;
public :
	Graph(int, int);
	~Graph();

	void insertEdge(int, int, double);

	void topologicalSort();

	void printGraph();
};

#endif /* SRC_GRAPHADT_GRAPH_H_ */
