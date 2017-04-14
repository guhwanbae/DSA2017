/*
 * main.cpp
 *
 *  Created on: 2017. 4. 4.
 *      Author: guhwan
 */

#include <iostream>
#include "stack.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "This program is GenericType Stack simulator..." << endl;

	Stack<int>* stack;
	stack = new Stack<int>();
	//Stack<int> stack;

	int keyVal, type;

	while (1) {
		cout << "Type type : 1(Push), 2(Pop)...";
		cin >> type;
		if (type == 1) {
			cout << "Type a key value...";
			cin >> keyVal;
			//stack.push(keyVal);
			//stack.traverse();
			stack->push(keyVal);
			stack->traverse();
		}
		else if (type == 2) {
			//stack.pop();
			//stack.traverse();
			stack->pop();
			stack->traverse();
		}
	}

	delete stack;

	return true;
}
