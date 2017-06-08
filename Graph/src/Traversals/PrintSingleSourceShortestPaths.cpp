/*
 * PrintSingleSourceShortestPaths.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "../GraphADT/GraphADT.h"

void Graph::printSingleSourceShortestPaths(int sourceID) {
	Stack<int>* stack = new Stack<int>(vertexSize);

	for(int index=0; index<vertexSize; ++index) {
		printf("\tVERTEX %2d DIST(%d): ", vertex[index]->getVertexID(),vertex[index]->getDist());
		int curID = index;
		while(true) {
			stack->push(vertex[curID]->getVertexID());
			curID = vertex[curID]->getPrev();
			if(curID == NOT_A_VERTEX) {
				break;
			}
		}
		while(!stack->isEmpty()) {
			printf("%2d",(vertex[stack->pop()])->getVertexID());
			if(!stack->isEmpty()) {
				printf(" -> ");
			}
		}
		stack->clearStack();
		printf("\n");
	}

	delete stack; stack = NULL;
}

void Graph::printSingleSourceShortestPaths(int sourceID,int type) {
	Stack<int>* stack = new Stack<int>(vertexSize);

	for(int index=0; index<vertexSize; ++index) {
		printf("\tVERTEX %2d DIST(%3.1f): ", vertex[index]->getVertexID(),vertex[index]->getDistance());
		int curID = index;
		while(true) {
			stack->push(vertex[curID]->getVertexID());
			curID = vertex[curID]->getPrev();
			if(curID == NOT_A_VERTEX) {
				break;
			}
		}
		while(!stack->isEmpty()) {
			printf("%2d",(vertex[stack->pop()])->getVertexID());
			if(!stack->isEmpty()) {
				printf(" -> ");
			}
		}
		stack->clearStack();
		printf("\n");
	}

	delete stack; stack = NULL;
}

