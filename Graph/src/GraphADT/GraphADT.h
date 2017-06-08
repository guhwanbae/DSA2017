/*
 * GraphADT.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_GRAPHADT_GRAPHADT_H_
#define SRC_GRAPHADT_GRAPHADT_H_

#include "../QueueADT/Queue.h"
#include "../HeapADT/BinaryHeap.h"
#include "../DisjointSetADT/DisjointSet.h"
#include "../ListADT/SortedLinkedList.h"
#include <limits.h>
#include <float.h>

class Edge {
private :
	//Basic Graph ADT
	int vertexID;
	double cost;
	Edge* next;
public :
	//Basic Graph ADT
	Edge(int, double, Edge*);
	~Edge();

	Edge* insertEdge(int); Edge* insertEdge(int,double);
	//Encapsulation
	//get
	int getVertexID();
	double getCost();
	Edge* getNext();
	//set
	void setNext(Edge*);
};

class Vertex {
private :
	//For Graph Traversals
	bool known;	int dist;	int prev;
	//For Topological Sort
	int indegree;
	//Basic Graph ADT
	int vertexID;	int degree;	Edge* head;

	void deleteEdgeKeys();
public :
	//Basic Graph ADT
	Vertex(int);
	~Vertex();

	void insertEdge(int);
	void insertEdge(int, double);
	Edge* findEdge(int);
	//For Topological Sort
	int decInDegree();
	void incInDegree();
	//For Traversals
	void edgeSort();
		//void resetSPRMetrics();
	//Encapsulation
	//get
	int getVertexID();
	int getInDegree();
	int getDegree();
	Edge* getEdgeHead();
	int getDist();
	bool getKnown();
	//set
	void setKnown(bool);
	void setDist(int);
	void setPrev(int);
};

class Graph {
private :
	//Basic Graph ADT
	Vertex** vertex;
	int vertexSize;
	int edgeSize;

	void initVertexKeys();	void deleteVertexKeys();	void clearVertex();
	void resetSPRMetrics();
	void printNonWeightedGraph();	void printWeightedGraph();
	void printSortedOrder(Queue<Vertex>*);
	void edgeSort();
public :
	//Basic Graph ADT
	Graph(int, int);
	~Graph();

	void insertEdge(int,int);	void insertEdge(int, int, double);

	void printGraph();
	//For Topological Sort
	void topologicalSort();
	//For Traversals
	void breathFirstSearch(int); //BFS
	void depthFirstSearch(Vertex*); //DFS
	void printSingleSourceShortestPaths();
	//For Shortest Path Algorithms(SPA)
	void dijkstra(int);
	void floydWarshall();
};

#ifndef INFINITY
#define INFINITY INT_MAX
#endif

#ifndef NON_WEIGHT
#define NON_WEIGHT DBL_MAX
#endif

#ifndef NOT_A_VERTEX
#define NOT_A_VERTEX -1
#endif

#ifndef INIT_VERTEX_DEGREE
#define INIT_VERTEX_DEGREE 1
#endif

#endif /* SRC_GRAPHADT_GRAPHADT_H_ */
