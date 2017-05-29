/*
 * SimulatorDisjointSet.h
 *
 *  Created on: 2017. 5. 29.
 *      Author: ghbae
 */

#ifndef SRC_SIMULATORDISJOINTSET_H_
#define SRC_SIMULATORDISJOINTSET_H_

#define DISJOINT_SET_BASIC 1
#define DISJOINT_SET_SIZE 2
#define DISJOINT_SET_COMP 3

#include "DisjointSet.h"

class SDS {
private :
	int type;
	FILE *ifp, *ofp;
	DisjointSet* myDisjointSet;
public :
	SDS(int);
	~SDS();

	void FileIO_Basic();
	void FileIO_Size();
	void FileIO_Comp();

	void SimulatingBasic();
	void SimulatingSize();
	void SimulatingComp();
};

#endif /* SRC_SIMULATORDISJOINTSET_H_ */
