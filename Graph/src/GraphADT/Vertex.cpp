/*
 * Vertex.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

/* Decrease Indegree */
int Vertex::decInDegree() {
	return --indegree;
}

int Vertex::getVertexID() {
	return vertexID;
}
int Vertex::getInDegree() {
	return indegree;
}
int Vertex::getDegree() {
	return degree;
}
Edge* Vertex::getEdgeHead() {
	return head;
}


