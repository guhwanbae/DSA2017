/*
 * PrintAllPairsShortestPaths.cpp
 *
 *  Created on: 2017. 6. 12.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::printAllPairsShortestPaths() {
	Stack<int>* stack = new Stack<int>(vertexSize);

	for (int sourceID=0; sourceID < vertexSize; ++sourceID) {
		fprintf(fp,"\tSOURCE VERTEX %2d\n",vertex[sourceID]->getVertexID());
		for(int destinationID=0; destinationID< vertexSize; ++destinationID) {
			fprintf(fp,"\t\tVERTEX %2d DIST(%2.1f): ",vertex[destinationID]->getVertexID(),dist[vertex[sourceID]->getVertexID()][vertex[destinationID]->getVertexID()]);
			int curID = destinationID;
			while (true) {
				stack->push(vertex[curID]->getVertexID());
				curID = prev[vertex[sourceID]->getVertexID()][vertex[curID]->getVertexID()];
				if(curID == NOT_A_VERTEX) {
					break;
				}
			}

			while(!stack->isEmpty()) {
				fprintf(fp,"%2d",stack->pop());
				if(!stack->isEmpty()) {
					fprintf(fp," -> ");
				}
				else {
					fprintf(fp,"\n"); break;
				}
			}
			stack->clearStack();
		}
	}
	delete stack;		stack = NULL;
}

