/*
 * Kruskal.cpp
 *
 *  Created on: 2017. 6. 14.
 *      Author: ghbae
 */

#include"../GraphADT/GraphADT.h"

void Graph::kruskal() {
	edgeSort();
	kruskal(0);
}

void Graph::kruskal(int dummy) {
	BinaryHeap<Edge>* heap = new BinaryHeap<Edge> (edgeSize);
	DisjointSet<int>* ds = new DisjointSet<int>(vertexSize);
	Edge** kruskal = new Edge*[vertexSize-1];

	for(int i=0; i<vertexSize; ++i) {
		Edge* e = vertex[i]->getEdgeHead();

		while (e != NULL) {
			heap->insert(e);
			e = e->getNext();
		}
	}


	int index=0;	double totalCost=0;
	while (index != (vertexSize - 1)) {
		Edge* e = heap->deleteMin();
		//Make sure that the Graph doesn't have any Cycles.
		//Compare the parents of subtrees using Disjoint Set.
		if (ds->findAndCompress(e->getSourceID()) != ds->findAndCompress(e->getVertexID()) ) {
			totalCost += e->getCost();
			kruskal[index++] = e;
			//If Subtree has a different parent, union.
			ds->unionSet(e->getSourceID(), e->getVertexID());
		}
	}

	fprintf(fp,"KRUSKAL - TOTAL COST(%3.1f)\n",totalCost);
	printMinimumSpanningTree(kruskal,index);

	delete heap;	heap = NULL;
	delete ds;		ds = NULL;
	delete[] kruskal;	kruskal = NULL;
}

void Graph::printMinimumSpanningTree(Edge** e,int size) {
	for(int index=0; index<size; ++index) {
		fprintf(fp,"\tEDGE(%2d, %2d) - DIST(%2.1f)\n",e[index]->getSourceID(),e[index]->getVertexID(),e[index]->getCost());
	}
}

