/*
 * Edge.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_GRAPHADT_EDGE_H_
#define SRC_GRAPHADT_EDGE_H_

#include "Graph.h"
#include "Vertex.h"

class Edge {
private :
	int vertexID;
	double cost;
	Edge* next;
public :
	Edge(int, double, Edge*);
	~Edge();

	int getVertexID();
	double getCost();
	Edge* getNext();
};



#endif /* SRC_GRAPHADT_EDGE_H_ */
