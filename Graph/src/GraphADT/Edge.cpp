/*
 * Edge.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

Edge::Edge(int newVertexID, double newCost, Edge* newNext) {
	vertexID = newVertexID;
	cost = newCost;
	next = newNext;
}
Edge::~Edge() {

}

Edge* Edge::insertEdge(int newVertexID) {
	if (this == NULL) {
		return new Edge(newVertexID,NON_WEIGHT,NULL);
	}
	else {
		next = next->insertEdge(newVertexID);
		return this;
	}
}
Edge* Edge::insertEdge(int newVertexID, double newCost) {
	if (this == NULL) {
		return new Edge(newVertexID,newCost,NULL);
	}
	else {
		next = next->insertEdge(newVertexID,newCost);
		return this;
	}
}

int Edge::getVertexID() {
	return vertexID;
}
double Edge::getCost() {
	return cost;
}
Edge* Edge::getNext() {
	return next;
}

