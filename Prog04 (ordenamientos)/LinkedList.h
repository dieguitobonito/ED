#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
	public:
		LinkedList();
		void addNode(Producto);
		void remove(void);
		void printForward(void);
		void deleteAll(void);

		unsigned int size(LinkedList*);
		void bubbleSort(LinkedList*);
		void quickSort(LinkedList*);
		void mergeSort(unsigned int, LinkedList*);
		void insertSort(LinkedList*);
		void selectSort(LinkedList*);
		void bogoSort(LinkedList*);
		void swapNodes(Node*, Node*);


	private:
		// Sentinels
		Node* header;
		Node* trailer;
};
#endif
