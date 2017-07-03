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
#include "../StackADT/Stack.h"
#include <limits.h>
#include <float.h>

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF THE EDGE                         *
 ****************************************************************************/
class Edge {
private :
	//Basic Graph ADT
	int vertexID; //vertexID = destinationID
	int sourceID;
	double cost; //Weight
	Edge* next;
public :
	//Basic Graph ADT
	Edge(int, int, double, Edge*);
	~Edge();

	//Encapsulation
	//get member
	int getVertexID();
	int getSourceID();
	double getCost();
	double getDistance();
	Edge* getNext();
	//set member
	void setNext(Edge*);
};

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF THE VERTEX                        *
 ****************************************************************************/
class Vertex {
private :
	//For Graph Traversals
	bool known;		//If known value is false, meaning that it has not yet been visited.
	int dist;			//If dist value is infinite, it means an unknown path.
	int prev;			//The prev value shows the index of the Vertex that previously visited.
	//For Topological Sort
	int indegree;		//The indegree value means to the number of Edges that this Vertex has.
	//Basic Graph ADT
	int vertexID;
	int degree;		//The degree value means to the number of Edges that this Vertex has.
	Edge* head;		//The haed means the head pointer of the Edges expressed as a Linked List.
	//For Shortest Path Algorithms
	double distance;	//The distance value means to a path(from a certain source Vertex to this Vertex) cost.

public :
	//Basic Graph ADT
	Vertex(int);
	~Vertex();

	void insertEdge(int,int);			//None Weighted Graph
	void insertEdge(int, int, double);	//Weighted Graph
	Edge* findEdge(int);
	//For Topological Sort
	int decInDegree();					//Decrease Indegree
	void incInDegree();					//Increase Indegree
	//For Traversals
	void edgeSort();						//Arrange edges in ascending order in order of Vertex ID(Destination ID).

	//Encapsulation
	//get member
	int getVertexID();
	int getInDegree();
	int getDegree();
	Edge* getEdgeHead();
	int getDist();
	bool getKnown();
	int getPrev();
	double getDistance();
	//set member
	void setKnown(bool);
	void setDist(int);
	void setPrev(int);
	void setDistance(double);
private :
	void deleteEdgeKeys();				//Remove all edges of the called Vertex.
};

/****************************************************************************
 * THE FUNTIONAL DECLARATIONS OF THE GRAPH ADT and ALGORITHMS     *
 ****************************************************************************/
class Graph {
private :
	FILE* fp;								//The fp is the ouput file's pointer.
	//Basic Graph ADT
	Vertex** vertex;						//Array of Vertex's pointers.
	int vertexSize;						//The size of the Vertex initially assigned.
	int edgeSize;							//The size of the Edge initially assigned.

	int curVertexSize;					//The size of the Vertex currently assigned.
	int curEdgeSize;						//The size of the Edge currently assigned.
private : //For Floyd Warshall Algorithm
	double** dist;						//In the Floyd Warshall Algorithm, the Graph is represented by the Adjacency Matrix.
	int** prev;
public :
	//Basic Graph ADT
	Graph(int, int,FILE*);
	~Graph();

	void insertEdge(int,int);						//None Weighted Graph
	void insertEdge(int, int, double);				//Weighted Graph

	void printGraph();								//Shows all the Vertices and Edges of the Graph.
	//For Topological Sort
	void topologicalSort();
	//For Traversals
	void breadthFirstSearch(int); //BFS
	void depthFirstSearch(int); //DFS
	//For Shortest Path Algorithms(SPA)
	void dijkstra(int);
	void floydWarshall();
	//Minimal Spanning Tree
	void kruskal();

	//get
	void showGraphComplexity();

private :
	void initVertexKeys();	void deleteVertexKeys();	void clearVertex();
	void deleteDistPrevMat();
	void printNonWeightedGraph();	void printWeightedGraph();
	void printSortedOrder(Queue<Vertex>*);		void printIndegree();

private :
	void breadthFirstSearch(Vertex*); //BFS
	void depthFirstSearch(Vertex*); //DFS
	void edgeSort();	void resetSPRMetrics();
	void printSingleSourceShortestPaths(int);

private :
	void dijkstra(Vertex*); //Dijkstra Algorithm
	void floydWarshall(int);	void setDistPrevMat();
	void printSingleSourceShortestPaths(int,int);
	void printAllPairsShortestPaths();

private :
	void kruskal(int);
	void printMinimumSpanningTree(Edge**, int);
};

#ifndef DIST_INFINITY
#define DIST_INFINITY INT_MAX
#endif

#ifndef NON_WEIGHT
#define NON_WEIGHT DBL_MAX
#endif

#ifndef COST_INFINITY
#define COST_INFINITY DBL_MAX
#endif

#ifndef NOT_A_VERTEX
#define NOT_A_VERTEX -1
#endif

#ifndef INIT_VERTEX_DEGREE
#define INIT_VERTEX_DEGREE 1
#endif

#ifndef COST_TYPE_DOUBLE
#define COST_TYPE_DOUBLE 1
#endif

#endif /* SRC_GRAPHADT_GRAPHADT_H_ */
