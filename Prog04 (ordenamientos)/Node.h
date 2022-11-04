#ifndef NODE_H
#define NODE_H

#include "Producto.h"

class Node{
	public:
		Node();
		Node(Producto, Node*, Node*);
	private:
		Producto data;
		Node* next;
		Node* prev;

	// Para que lista pueda acceder
	// a los datos
	friend class LinkedList;
};
#endif
