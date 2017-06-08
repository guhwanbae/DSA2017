/*
 * DepthFirstSearch.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::depthFirstSearch(Vertex* source) {
	source->setKnown(true); //source or root

	Edge* e = source->getEdgeHead();
	//Need stack or recursion.
	while (e != NULL) {
		if (!vertex[e->getVertexID()]->getKnown()) {
			depthFirstSearch(vertex[e->getVertexID()]);
		}
		e = e->getNext();
	}
}
