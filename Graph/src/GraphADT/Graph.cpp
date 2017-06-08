/*
 * Graph.c
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include <iostream>
#include <stdio.h>
#include "GraphADT.h"

Graph::Graph(int vSize, int eSize) {
	//Build Graph -> Vertex**
	vertex = new Vertex*[vSize];
	vertexSize = vSize;
	edgeSize = eSize;
	initVertexKeys();
}
Graph::~Graph() {
	deleteVertexKeys();
	delete[] vertex;
	vertex = NULL;
}


void Graph::initVertexKeys() {
	for(int index=0; index<vertexSize; ++index) {
		vertex[index] = new Vertex(index);
	}
}
void Graph::deleteVertexKeys() {
	for(int index=0; index<vertexSize; ++index) {
		delete vertex[index];
	}
	clearVertex();
}
void Graph::clearVertex() {
	for(int index=0; index<vertexSize; ++index) {
		vertex[index] = NULL;
	}
}

void Graph::insertEdge(int curVertex, int nextVertex, double newCost) {
	if(vertex[curVertex] == NULL) {
		vertex[curVertex] = new Vertex(curVertex);
	}
	vertex[curVertex]->insertEdge(nextVertex,newCost);
	vertex[nextVertex]->incInDegree();
}
void Graph::insertEdge(int curVertex, int nextVertex) {
	if(vertex[curVertex] == NULL) {
		vertex[curVertex] = new Vertex(curVertex);
	}
	vertex[curVertex]->insertEdge(nextVertex);
	vertex[nextVertex]->incInDegree();
}

void Graph::printGraph() {
	if(vertex[0]->getEdgeHead()->getCost() == NON_WEIGHT) {
		printNonWeightedGraph();
	}
	else {
		printWeightedGraph();
	}
}
void Graph::printNonWeightedGraph() {
	for(int index=0; index<vertexSize; ++index) {
		if(vertex[index] != NULL) {
			printf("\tVERTEX %2d (%d): ",vertex[index]->getVertexID(),vertex[index]->getDegree());
			Edge* e = vertex[index]->getEdgeHead();
			while(e != NULL) {
				printf("(%2d)",e->getVertexID());
				if( e->getNext() != NULL) {	printf(" -> ");		}
				e = e->getNext();
			}
		}
		else {
			printf("\tVERTEX %2d (%d): ",index,0);
		}	printf("\n");
	}
	for(int index=0; index<vertexSize; ++index) {
		printf("\tVERTEX (%2d) : INDEGREE(%2d)\n",vertex[index]->getVertexID(),vertex[index]->getInDegree());
	}
}
void Graph::printWeightedGraph() {
	for(int index=0; index<vertexSize; ++index) {
		if(vertex[index] != NULL) {
			printf("\tVERTEX %2d (%d): ",vertex[index]->getVertexID(),vertex[index]->getDegree());
			Edge* e = vertex[index]->getEdgeHead();
			while(e != NULL) {
				printf("(%2d,%3.1f)",e->getVertexID(),e->getCost());
				if( e->getNext() != NULL) {	printf(" -> ");		}
				e = e->getNext();
			}
		}
		else {
			printf("\tVERTEX %2d (%d): ",index,0);
		}	printf("\n");
	}
}

void Graph::topologicalSort() {
	Queue<Vertex>* queue = new Queue<Vertex>(vertexSize);
	Queue<Vertex>* order = new Queue<Vertex>(vertexSize);

	for(int i=0; i<vertexSize; ++i) {
		if(vertex[i]->getInDegree() == 0) {
			queue->enQueue(vertex[i]);
			order->enQueue(vertex[i]);
		}
	}

	while( !queue->isEmpty() ) { //If Queue is not empty, DAG case.
		Vertex* v = queue->deQueue();
		cout << "Vertex " << v->getVertexID() << endl;

		Edge* e = v->getEdgeHead();

		while(e != NULL) {
			if( vertex[e->getVertexID()]->decInDegree() == 0 ) {
				queue->enQueue(vertex[e->getVertexID()]);
				order->enQueue(vertex[e->getVertexID()]);
			}
			e = e->getNext();
		}
	}

	printSortedOrder(order);
	delete queue;		queue = NULL;
	delete order;		order = NULL;
}

void Graph::printSortedOrder(Queue<Vertex>* sortedQueue) {
	for(int order=1; order<=vertexSize; ++order) {
		printf("\tORDER(%2d) -- VERTEX %2d\n",order,(sortedQueue->deQueue())->getVertexID());
	}
}

void Graph::resetSPRMetrics() {
	for(int index=0; index<vertexSize; ++index) {
		vertex[index]->setKnown(false);
		vertex[index]->setDist(INFINITY);
		vertex[index]->setPrev(0);
	}
}

void Graph::edgeSort() {
	for(int index=0; index<vertexSize; ++index) {
		vertex[index]->edgeSort();
	}
}
