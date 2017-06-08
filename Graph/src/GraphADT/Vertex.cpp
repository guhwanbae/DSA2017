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
		Edge* temp1 = head, *temp2;
		while(temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->getNext();
		}
		temp2->setNext(new Edge(newVertexID,NON_WEIGHT,NULL));
	}
	degree++;
}
void Vertex::insertEdge(int newVertexID, double newCost) {
	if(head == NULL) {
		head = new Edge(newVertexID,newCost,NULL);
	}
	else {
		Edge* temp1 = head, *temp2;
		while(temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->getNext();
		}
		temp2->setNext(new Edge(newVertexID,newCost,NULL));
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
int Vertex::getPrev(){
	return prev;
}
double Vertex::getDistance() {
	return distance;
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
void Vertex::setDistance(double newDistance) {
	distance = newDistance;
}

/* For Traversals */
void Vertex::edgeSort() {
	SLL<Edge>* sortedEdgeHead = new SLL<Edge> (head,degree);
	head = sortedEdgeHead->sortEdge();
	delete sortedEdgeHead; sortedEdgeHead = NULL;
}
