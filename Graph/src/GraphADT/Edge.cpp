/*
 * Edge.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

/* Edge -> Adjacently Sorted Linked List */

Edge::Edge(int newVertexID, double newCost, Edge* newNext) {
	vertexID = newVertexID;
	cost = newCost;
	next = newNext;
}
Edge::~Edge() {

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

void Edge::setNext(Edge* newNext) {
	next = newNext;
}
