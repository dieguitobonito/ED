#ifndef NODE_H
#define NODE_H

#include "Alumno.h"

class Node{
	public:
		Node();
		Node(Alumno, Node*, Node*);
	private:
		Alumno data;
		Node* next;
		Node* prev;

	// Para que lista pueda acceder
	// a los datos
	friend class LinkedList;
};
#endif
