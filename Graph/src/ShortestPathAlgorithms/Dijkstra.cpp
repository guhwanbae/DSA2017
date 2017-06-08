/*
 * Dijkstra.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::dijkstra(int source) {
	BinaryHeap<Vertex> *heap = new BinaryHeap<Vertex>(vertexSize);
	resetSPRMetrics(); //v->dist = INFINITY

	vertex[source]->setDist(0);
	heap->insert(vertex[source]);

	Vertex* v = NULL;
	while ( (v = heap->deleteMin()) != NULL ) {
		v->setKnown(true);
		Edge* e = v->getEdgeHead();

		while ( e != NULL ) {
			if ( vertex[e->getVertexID()]->getKnown() == false ) {
				/*
				if ( v->getDist() + e->getDist() < vertex[e->getVertexID()]->getDist() ) {
					vertex[e->getVertexID()]->setDist(v->getDist() + e->getDist());
					vertex[e->getVertexID()]->setPrev(v->getVertexID());

					heap->decreaseKey(vertex[e->getVertexID()]);
				}
				*/
			}
			e = e->getNext();
		}
	}
	printSingleSourceShortestPaths();
	delete heap;	heap = NULL;
}
