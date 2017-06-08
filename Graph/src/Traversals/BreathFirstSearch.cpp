/*
 * BreathFirstSearch.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::breathFirstSearch(int sourceID) {
	Queue<Vertex>* queue = new Queue<Vertex>(vertexSize);
	//Queue(Q) is T** type..
	resetSPRMetrics(); //Sorted Linked List

	vertex[sourceID]->setDist(0);
	queue->enQueue(vertex[sourceID]);

	while(!queue->isEmpty()) {
		Vertex* v = queue->deQueue();
		v->setKnown(true);

		Edge* e = v->getEdgeHead();

		while(e != NULL) {
			if (vertex[e->getVertexID()]->getDist() == INFINITY) {
				vertex[e->getVertexID()]->setDist(v->getDist()+1);
				vertex[e->getVertexID()]->setPrev(v->getVertexID());
				queue->enQueue(vertex[e->getVertexID()]);
			}
			e = e->getNext();
		}

		printSingleSourceShortestPaths();
	}
	delete queue;
	queue = NULL;
}
