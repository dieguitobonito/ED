#ifndef NODE_H
#define NODE_H

#include "Animal.h"

class Node{
	public:
		Node();
		Node(Animal, Node*, Node*);
	private:
		Animal data;
		Node* next;
		Node* prev;

	// Para que lista pueda acceder
	// a los datos
	friend class LinkedList;
};
#endif
