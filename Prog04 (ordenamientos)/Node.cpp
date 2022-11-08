#include "Node.h"

Node::Node(){
	Producto();
	next = nullptr;
	prev = nullptr;
}

Node::Node(Producto data, Node* next, Node* prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
}

Node::Node(Producto data){
	this->data = data;
	next = nullptr;
	prev = nullptr;
}
