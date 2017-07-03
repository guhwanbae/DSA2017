/*
 * DisjointSet.h
 *
 *  Created on: 2017. 6. 4.
 *      Author: ghbae
 */

#ifndef SRC_DISJOINTSETADT_DISJOINTSET_H_
#define SRC_DISJOINTSETADT_DISJOINTSET_H_

#ifndef SIZE_ROOT
#define SIZE_ROOT -1
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef COUNT_ZERO
#define COUNT_ZERO 0
#endif

/* Generic Type Disjoint Set ADT */
template<typename T>
class DisjointSet {
private :
	T* s;
	int size;
	void initDisjointSet();
public :
	DisjointSet(int);
	~DisjointSet();

	T findAndCompress(int);
	void unionSet(int, int);
};

template<typename T>
DisjointSet<T>::DisjointSet(int newSize) {
	size = newSize;
	s = new T[size];
	initDisjointSet();
}

template<typename T>
DisjointSet<T>::~DisjointSet() {
	delete[] s;
	s = NULL;
}
template<typename T>
void DisjointSet<T>::initDisjointSet() {
	for(int index=0; index < size; ++index) {
		s[index] = SIZE_ROOT;
	}
}
template<typename T>
T DisjointSet<T>::findAndCompress(int element) {
	if (s[element] < 0) {
		return element;
	}
	else {
		return (s[element] = findAndCompress(s[element]));
		//Call recursion with parent's link.
	}
}
/* This implementation, called find(path) compression, is a way of flattening the structure of the tree whenever Find is used on it. */
template<typename T>
void DisjointSet<T>::unionSet(int root1, int root2) {
	T parent1 = findAndCompress(root1), parent2 = findAndCompress(root2);

	if (parent1 == parent2) {
		return; //SAME ROOT!
	}
	else {
		if (s[parent2] < s[parent1]) {
			s[parent2] += s[parent1];
			s[parent1] = parent2;
			parent1 = parent2;
		}
		else {
			s[parent1] += s[parent2];
			s[parent2] = parent1;
		}
	}
}

#endif /* SRC_DISJOINTSETADT_DISJOINTSET_H_ */
