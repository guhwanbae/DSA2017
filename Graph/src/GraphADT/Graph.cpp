/*
 * Graph.c
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include <iostream>
#include "GraphADT.h"

Graph::Graph(int vSize, int eSize) {
	//Build Graph -> Vertex**

	vertexSize = vSize;
	edgeSize = eSize;
}

void Graph::topologicalSort() {
	Queue<Vertex>* queue = new Queue<Vertex>(vertexSize);

	for(int i=0; i<vertexSize; ++i) {
		if(vertex[i]->getInDegree() == 0) {
			queue->enQueue(vertex[i]);
		}
	}

	while( !queue->isEmpty() ) { //If Queue is not empty, DAG case.
		Vertex* v = queue->deQueue();
		cout << "Vertex " << v->getVertexID() << endl;

		Edge* e = v->getEdgeHead();

		while(e != NULL) {
			if( vertex[e->getVertexID()]->decInDegree() == 0 ) {
				queue->enQueue(vertex[e->getVertexID()]);
			}
			e = e->getNext();
		}
	}
	delete queue;
	queue = NULL;
}
