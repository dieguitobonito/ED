// El orden de los headers importa?
#include "Node.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
using namespace std;


LinkedList::LinkedList(){
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = nullptr;
	trailer->next = nullptr;
}

void LinkedList::addFront(Producto a){
	if(header == nullptr && trailer == nullptr){
		Node* first = new Node(a, nullptr, nullptr);
		header = first;
		trailer = first;
	}
	else{
		Node* aux = new Node(a, nullptr, nullptr);
		Node* tmp = trailer;
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = aux; 
		trailer = aux;
	}
}

void LinkedList::removeFront(){
	Node* nd = header->next->next;
	delete header->next;
	header->next = nd;
	nd->prev = header;
}

void LinkedList::printForward(){
	// Referencia al verdadero
	// primer dato
	if(!header && !trailer)
		cout << "Lista vacia" << endl;
	else{
		Node* tmp = header->next->next;

		cout << "\n";
		cout << "Id, nombre de producto y precio\n" << endl;
		unsigned int count = 0;
		while(tmp != trailer){
			count++;
			cout << count << ".- ";
			cout << tmp->data.id << ", " << tmp->data.name <<
				", " << tmp->data.price << endl;
			tmp = tmp->next;
		}
	}
	
	cout << "\n";
}

void LinkedList::deleteAll(void){
	while(header->next != trailer)
		removeFront();

	delete header;
	delete trailer;
}
