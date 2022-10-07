#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
	public:
		LinkedList();
		void removeFront(void);

		void addFront(Alumno);
		void addNode(Alumno, unsigned int);

		void deleteThis(string, unsigned int);
		void deleteAll(void);
		Node* find(string, unsigned int);
		void initialize(void);
		bool isEmpty(void);
		void getFront(void);
		void getBack(void);
		unsigned int size(void);
		void nextNode(string, unsigned int);
		void prevNode(string, unsigned int);
		void printForward(void);
		void printReverse(void);
	private:
		// Sentinels
		Node* header;
		Node* trailer;
};
#endif
