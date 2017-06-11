/*
 * Dijkstra.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

/* Single Source and Single Destination Shortest Path Problem */
void Graph::dijkstra(int sourceID) {
	printf("DIJKSTRA (SRC: %2d)\n",sourceID);
	resetSPRMetrics(); //v->distance = COST_INFINITY
	dijkstra(vertex[sourceID]);
	printSingleSourceShortestPaths(sourceID,COST_TYPE_DOUBLE);
}

void Graph::dijkstra(Vertex* source) {
	BinaryHeap<Vertex> *heap = new BinaryHeap<Vertex>(vertexSize);

	source->setDistance(0);
	heap->insert(source);

	Vertex* v = NULL;
	while ((v = heap->deleteMin()) != NULL) {
		v->setKnown(true);
		Edge* e = v->getEdgeHead();

		while (e != NULL) {
			if (vertex[e->getVertexID()]->getKnown() == false) {
				if (v->getDistance() + e->getCost() < vertex[e->getVertexID()]->getDistance()) {
					vertex[e->getVertexID()]->setDistance(	v->getDistance() + e->getCost());
					vertex[e->getVertexID()]->setPrev(v->getVertexID());

					heap->decreaseKey(vertex[e->getVertexID()]);
				}
			}
			e = e->getNext();
		}
	}

	delete heap;	heap = NULL;
}
