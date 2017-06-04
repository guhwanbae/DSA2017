/*
 * Edge.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"



int Edge::getVertexID() {
	return vertexID;
}
double Edge::getCost() {
	return cost;
}
Edge* Edge::getNext() {
	return next;
}


