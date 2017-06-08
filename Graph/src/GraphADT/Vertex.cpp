/*
 * Vertex.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

Vertex::Vertex(int newVertexID) {
	vertexID = newVertexID;	degree = 0;	head = NULL;
	indegree = 0;
}
Vertex::~Vertex() {
	deleteEdgeKeys();
}

void Vertex::deleteEdgeKeys() {
	Edge* curEdge = head;	Edge* ToBeDeleted = NULL;
	while(curEdge != NULL) {
		ToBeDeleted = curEdge;
		curEdge = curEdge->getNext();
		delete ToBeDeleted;		ToBeDeleted = NULL;
	}
}

void Vertex::insertEdge(int newVertexID) {
	if(head == NULL) {
		head = new Edge(newVertexID,NON_WEIGHT,NULL);
	}
	else {
		head->insertEdge(newVertexID);
	}
	degree++;
}
void Vertex::insertEdge(int newVertexID, double newCost) {
	if(head == NULL) {
		head = new Edge(newVertexID,newCost,NULL);
	}
	else {
		head->insertEdge(newVertexID,newCost);
	}
	degree++;
}

/* Decrease Indegree */
int Vertex::decInDegree() {
	return --indegree;
}
void Vertex::incInDegree() {
	++indegree;
}

//Encapsulation
//get
int Vertex::getVertexID() {
	return vertexID;
}
int Vertex::getInDegree() {
	return indegree;
}
int Vertex::getDegree() {
	return degree;
}
Edge* Vertex::getEdgeHead() {
	return head;
}
int Vertex::getDist() {
	return dist;
}
bool Vertex::getKnown() {
	return known;
}
//set
void Vertex::setKnown(bool newKnown) {
	known = newKnown;
}
void Vertex::setDist(int newDist) {
	dist = newDist;
}
void Vertex::setPrev(int newPrev) {
	prev = newPrev;
}

/* For Traversals */
void Vertex::edgeSort() {
	SLL<Edge>* sortedEdgeHead = new SLL<Edge> (head,degree);
	head = sortedEdgeHead->sortEdge();
	delete sortedEdgeHead; sortedEdgeHead = NULL;
}
