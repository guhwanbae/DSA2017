/*
 * Vertex.cpp
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#include "GraphADT.h"

/****************************************************************************
 * THE FUNTIONAL IMPLEMENTAIONS OF THE VERTEX                      *
 ****************************************************************************/
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

void Vertex::insertEdge(int curVertexID, int newVertexID) {
	if(head == NULL) { //Assign a new memory space if there is no head Edge.
		head = new Edge(curVertexID,newVertexID,NON_WEIGHT,NULL);
	}
	else { //Insert a new Node(Edge) into the Linked List.
		Edge* temp1 = head, *temp2;
		while(temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->getNext();
		}
		temp2->setNext(new Edge(curVertexID,newVertexID,NON_WEIGHT,NULL)); //Assign a new Node(Edge) to the next.
	}
	degree++;
}
void Vertex::insertEdge(int curVertexID, int newVertexID, double newCost) {
	if(head == NULL) { //Assign a new memory space if there is no head Edge.
		head = new Edge(curVertexID,newVertexID,newCost,NULL);
	}
	else { //Insert a new Node(Edge) into the Linked List.
		Edge* temp1 = head, *temp2;
		while(temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->getNext();
		}
		temp2->setNext(new Edge(curVertexID,newVertexID,newCost,NULL)); //Assign a new Node(Edge) to the next.
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
	SLL<Edge>* sortedEdgeHead = new SLL<Edge> (head,degree); //Creates a SLL Class, which is a sorting method.
	head = sortedEdgeHead->sortEdge(); //Sort the Nodes in the Linked List in a specific order, and Linking the sorted Nodes again to return their head-pointer(head-Node).
	delete sortedEdgeHead; sortedEdgeHead = NULL;
}
