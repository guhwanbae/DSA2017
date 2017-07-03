/*
 * BreathFirstSearch.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::breadthFirstSearch(int sourceID) {
	edgeSort();
	resetSPRMetrics();
	fprintf(fp,"BREATH-FIRST SEARCH (SRC: %2d)\n",sourceID);
	breadthFirstSearch(vertex[sourceID]);
	printSingleSourceShortestPaths(sourceID);
}

void Graph::breadthFirstSearch(Vertex* source) {
	int sourceID = source->getVertexID();

	Queue<Vertex>* queue = new Queue<Vertex>(vertexSize);
	//Queue(Q) => buffer -> T** type, KeyVal -> T* type..

	vertex[sourceID]->setDist(0);
	queue->enQueue(vertex[sourceID]);

	while(!queue->isEmpty()) {
		Vertex* v = queue->deQueue();
		v->setKnown(true);

		Edge* e = v->getEdgeHead();

		while(e != NULL) {
			if (vertex[e->getVertexID()]->getDist() == DIST_INFINITY) {
				vertex[e->getVertexID()]->setDist(v->getDist()+1);
				vertex[e->getVertexID()]->setPrev(v->getVertexID());
				queue->enQueue(vertex[e->getVertexID()]);
			}
			e = e->getNext();
		}
	}

	delete queue;
	queue = NULL;
}
