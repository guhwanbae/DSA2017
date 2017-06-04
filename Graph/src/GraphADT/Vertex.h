/*
 * Vertex.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_GRAPHADT_VERTEX_H_
#define SRC_GRAPHADT_VERTEX_H_

#include "Graph.h"
#include "Edge.h"

class Vertex {
private :
	int vertexID;
	int indegree;
	int degree;
	Edge* head;
public :
	Vertex();
	~Vertex();

	void insertEdge(int, double);
	Edge* findEdge(int);

	int decInDegree();

	int getVertexID();
	int getInDegree();
	int getDegree();
	Edge* getEdgeHead();
};

#endif /* SRC_GRAPHADT_VERTEX_H_ */
