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

		void quickSort(LinkedList*);
		void mergeSort(void);
		void insertSort(void);
		void selectSort(void);
		void bogoSort(void);


	private:
		// Sentinels
		Node* header;
		Node* trailer;
};
#endif
