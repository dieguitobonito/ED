#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
	public:
		LinkedList();
		void removeFront(void);

		void addFront(Animal);
		void addNode(Animal, int);

		void deleteThisID(int);
		void deleteThisName(string, string);
		void deleteAll(void);
		Node* find(string, int);
		void initialize(void);
		bool isEmpty(void);
		void getFront(void);
		void getBack(void);
		int size(void);
		void nextNode(string, int);
		void prevNode(string, int);
		void printForward(void);
		void printReverse(void);
	private:
		// Sentinels
		Node* header;
		Node* trailer;
};
#endif
