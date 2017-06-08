/*
 * DepthFirstSearch.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::depthFirstSearch(int sourceID) {
	resetSPRMetrics();
	printf("DEPTH-FIRST SEARCH (SRC: %2d)\n",sourceID);
	depthFirstSearch(vertex[sourceID]);
	printf("\n");
}

void Graph::depthFirstSearch(Vertex* source) {
	source->setKnown(true); //source or root

	printf("%2d -> ",source->getVertexID());

	Edge* e = source->getEdgeHead();
	//Need stack or recursion.
	while (e != NULL) { //Visit every edges in this vertex.
		if (!vertex[e->getVertexID()]->getKnown()) {
			depthFirstSearch(vertex[e->getVertexID()]);
		}
		e = e->getNext();
		if (e == NULL) {
			printf("back <- "); return;
		}
	} printf("back <- ");
}
