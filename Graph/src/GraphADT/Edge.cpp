/*
 * Edge.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

/* Edge -> Adjacently Sorted Linked List
 * "..ListADT/SortedLinkedList.h"
 * Class SLL */
/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF THE EDGE                        *
 ****************************************************************************/
Edge::Edge(int newSourceID, int newVertexID, double newCost, Edge* newNext) {
	vertexID = newVertexID;
	sourceID = newSourceID;
	cost = newCost;
	next = newNext;
}
Edge::~Edge() {

}

int Edge::getVertexID() {
	return vertexID;
}
int Edge::getSourceID() {
	return sourceID;
}
double Edge::getCost() {
	return cost;
}
double Edge::getDistance() {
	return cost;
}
Edge* Edge::getNext() {
	return next;
}

void Edge::setNext(Edge* newNext) {
	next = newNext;
}
