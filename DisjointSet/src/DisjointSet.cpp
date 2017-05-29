/*
 * DisjointSet.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: ghbae
 */
#include <iostream>
#include <stdio.h>
#include "DisjointSet.h"

using namespace std;

DisjointSet::DisjointSet(int newSize, FILE* ofp) {
	size = newSize;
	s = new int[size];
	for(int index=0; index < size; ++index) {
		s[index] = SIZE_ROOT;
	}
	fp = ofp;
	fprintf(fp, "INIT DISJOINT SET(SIZE: %3d)\n", size);
	cout << "INIT DISJOINT SET(SIZE: " << size << ")" << endl;
}

DisjointSet::~DisjointSet() {
	delete[] s;
	s = NULL;
}

void DisjointSet::Find(int element) {
	int count = find(element,COUNT_ZERO);
	fprintf(fp, "FIND(KEY: %d): COUNT(%d)\n",element,count);
	printf("FIND(KEY: %d): COUNT(%d)\n",element,count);
}
int DisjointSet::find(int element) {
	if (s[element] < 0) {
		return element;
	}
	else {
		return find(s[element]);
	}
}
int DisjointSet::find(int element, int count) {
	++count;
	if (s[element] < 0) {
		return count;
	}
	else {
		return find(s[element],count);
	}
}

void DisjointSet::FindAndCompress(int element) {
	int count = findAndCompress(element,COUNT_ZERO);
	fprintf(fp, "FIND(KEY: %d): COUNT(%d)\n",element,count);
	printf("FIND(KEY: %d): COUNT(%d)\n",element,count);
}
int DisjointSet::findAndCompress(int element) {
	if (s[element] < 0) {
		return element;
	}
	else {
		return (s[element] = findAndCompress(s[element])); //Call recursion with parent's link.
	}
}
int DisjointSet::findAndCompress(int element, int count) {
	++count;
	if (s[element] < 0) {
		return count;
	}
	else {
		return (s[element] = findAndCompress(s[element])); //Call recursion with parent's link.
	}
}

void DisjointSet::unionSets(int root1, int root2) {
	int parent1 = find(root1), parent2 = find(root2);

	if (parent1 == parent2) {
		printf("UNION(KEY1: %3d, KEY2: %3d): SAME SET\n", root1, root2);
		fprintf(fp, "UNION(KEY1: %3d, KEY2: %3d): SAME SET\n", root1, root2);
	}
	else {
		s[parent2] = parent1;
		printf("UNION(KEY1: %3d, KEY2: %3d): NEW ROOT %3d\n", root1, root2, parent1);
		fprintf(fp, "UNION(KEY1: %3d, KEY2: %3d): NEW ROOT %3d\n", root1, root2, parent1);
	}
}

void DisjointSet::unionBySize(int root1, int root2) {
	int parent1 = find(root1), parent2 = find(root2);

	if (parent1 == parent2) {
		printf("UNION BY SIZE(KEY1: %3d, KEY2: %3d): SAME SET\n", root1, root2);
	}
	else {
		if (s[parent2] < s[parent1]) {
			s[parent2] += s[parent1];
			s[parent1] = parent2;
		}
		else {
			s[parent1] += s[parent2];
			s[parent2] = parent1;
		}
	}
}
void DisjointSet::unionBySizeWithComp(int root1, int root2) {
	int parent1 = findAndCompress(root1), parent2 = findAndCompress(root2);

	if (parent1 == parent2) {
		printf("UNION BY SIZE(KEY1: %3d, KEY2: %3d): SAME SET\n", root1, root2);
	}
	else {
		if (s[parent2] < s[parent1]) {
			s[parent2] += s[parent1];
			s[parent1] = parent2;
		}
		else {
			s[parent1] += s[parent2];
			s[parent2] = parent1;
		}
	}
}

void DisjointSet::unionByHeight(int root1, int root2) {
	int parent1 = find(root1), parent2 = find(root2);

	if (parent1 == parent2) {
		cout << "The Same Set!" << endl;
	}
	else {
		if (s[parent1] == s[parent2]) {
			s[parent2] = parent1;
			--s[parent1];
		}
		else {
			if (s[parent1] < s[parent2]) {
				s[parent2] = parent1;
			}
			else {
				s[parent1] = parent2;
			}
		}
	}
}

void DisjointSet::print() {
	cout << "PRINT DISJOINT SET" << endl;
	fprintf(fp,"PRINT DISJOINT SET\n");
	for(int index=0; index < size; ++index) {
		printf("\ts[%03d] = %3d\n",index,s[index]);
		fprintf(fp, "\ts[%03d] = %3d\n",index,s[index]);
	}
}
