#include "Node.h"

Node::Node(){
	Animal();
	next = nullptr;
	prev = nullptr;
}

Node::Node(Animal data, Node* next, Node* prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
}
