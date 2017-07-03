/*
 * FloydWarshall.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

/* All pairs Shortest Path Problem */
void Graph::floydWarshall() {
	fprintf(fp,"FLOYD-WARSHALL\n");
	floydWarshall(0);
	printAllPairsShortestPaths();
}

void Graph::setDistPrevMat() {
	//memory allocate dist, prev Mat.
	dist = new double*[vertexSize]; //dist Type <- Double Pointer of double type
	prev = new int*[vertexSize]; //prev Type <- Double Pointer of int type
	for(int index=0; index<vertexSize; ++index) {
		dist[index] = new double[vertexSize];
		prev[index] = new int[vertexSize];
	}

	for (int i = 0; i < vertexSize; ++i) {
		for (int j = 0; j < vertexSize; ++j) {
			dist[i][j] = INFINITY;
			prev[i][j] = NOT_A_VERTEX;
		}
		dist[i][i] = 0;

		Edge* e = vertex[i]->getEdgeHead();
		while (e != NULL) {
			dist[i][e->getVertexID()] = e->getCost();
			prev[i][e->getVertexID()] = i;
			e = e->getNext();
		}
	}
}

void Graph::floydWarshall(int dummy) {
	setDistPrevMat();

	for(int k=0; k<vertexSize; ++k) { // Vertex k = Pass Point via Path
		for(int i=0; i<vertexSize; ++i) { //Vertex i = Start Point
			for(int j=0; j<vertexSize; ++j) { //Vertex j = Destination Point
				if(dist[i][j] > dist[i][k] + dist[k][j]) { // Compare PATH_old(i->j)Cost and PATH_new(i->k->j)Cost
					dist[i][j] = dist[i][k] + dist[k][j];
					prev[i][j] = k;
				}
			}
		}
	}
}
