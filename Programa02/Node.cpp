#include "Node.h"

Node::Node(){
	Alumno();
	next = nullptr;
	prev = nullptr;
}

Node::Node(Alumno data, Node* next, Node* prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
}
