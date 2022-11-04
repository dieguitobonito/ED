#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
	public:
		LinkedList();
		void addFront(Producto);
		void removeFront(void);
		void printForward(void);
		void deleteAll(void);
		void addNode(Producto, unsigned int);


	private:
		// Sentinels
		Node* header;
		Node* trailer;
};
#endif
