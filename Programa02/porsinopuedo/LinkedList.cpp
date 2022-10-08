#include "Node.h"
#include "LinkedList.h"

#include <iostream>
using namespace std;

LinkedList::LinkedList(){
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = nullptr;
	trailer->next = nullptr;
}

// Return data instead of pointer
void LinkedList::getFront(){
	if(isEmpty()){
		cout << "\nNo hay primero\n" << endl;
	}else{
		cout << "\nEl primero es: ";
		cout << header->next->data.name << ", ";
		cout << header->next->data.breed << "\n" << endl;
	}
}

// Same as getfront
void LinkedList::getBack(){
	if(isEmpty()){
		cout << "\nNo hay último\n" << endl;
	}else{
		cout << "El último es: ";
		cout << trailer->prev->data.name << ", ";
		cout << trailer->prev->data.breed << endl;
	}
}

void LinkedList::addFront(Animal a){
	Node* nd = new Node(a, nullptr, nullptr);

	nd->prev = header;
	nd->next = header->next;

	header->next->prev = nd;
	header->next = nd;
}

void LinkedList::removeFront(){
	Node* nd = header->next->next;
	delete header->next;
	header->next = nd;
	nd->prev = header;
}

void LinkedList::printReverse(){
	// Referencia al verdadero
	// último dato
	Node* tmp = trailer->prev;

	int count = size();
	cout << "\n";
	while(tmp != header){
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.breed << endl;
		tmp = tmp->prev;
		count--;
	}
	cout << "\n";
}

void LinkedList::printForward(){
	// Referencia al verdadero
	// primer dato
	Node* tmp = header->next;

	cout << "\n";
	int count = 0;
	while(tmp != trailer){
		count++;
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.breed << endl;
		tmp = tmp->next;
	}
	cout << "\n";
}

bool LinkedList::isEmpty(void){
	return (header->next == trailer);
}

Node* LinkedList::find(string n, string a){
	Node* aux;
	aux = header;
	bool found = false;
	if(isEmpty()){
		cout << "\nNo hay lista para comenzar\n" << endl;
		return nullptr;
	}else{
		while(aux != nullptr && found == false){
			if(aux->data.name == n && aux->data.breed == a){
				found = true;
			}else{
				aux = aux->next;
			}
		}
	}
	return aux;
}

void LinkedList::deleteThis(string n, string b){
	Node* aux = find(n, a);
	if(aux){
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		delete aux;
		cout << "Animal eliminado\n" << endl;
	}else{
		cout << "Animal no encontrado\n" << endl;
	}
}

void LinkedList::deleteAll(void){
	while(header->next != trailer)
		removeFront();

	delete header;
	delete trailer;
}

void LinkedList::initialize(void){
	if(isEmpty()){
		header = new Node();
		trailer = new Node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = nullptr;
		trailer->next = nullptr;
		cout << "\nLista inicializada\n" << endl;
	}else{
		cout << "\nLa lista está inicializada\n" << endl;
	}
}

int LinkedList::size(void){
	int cant = 0;
	if(!isEmpty()){
		Node* aux = header->next;
		while(aux != trailer){
			cant++;
			aux = aux->next;
		}
	}
	return cant;	
}

void LinkedList::nextNode(string n, string b){
	Node* tmp = find(n, a);

	// Para no acceder ilegalmente
	if(tmp == nullptr){
		cout << "\nAnimal no encontrado\n" << endl;
	}else if(tmp->next == trailer){
		cout << "\nNo hay animal siguiente\n" << endl;
	}else{
		cout << "\nEl animal siguiente es " << tmp->next->data.name;
		cout << ", " << tmp->next->data.breed << endl;
		cout << "\n";
	}
}

void LinkedList::prevNode(string n, string b){
	Node* tmp = find(n, a);

	if(tmp->prev == header){
		cout << "\nNo hay animal anterior\n" << endl;
	}else{
		cout << "\nEl animal anterior es " << tmp->prev->data.name;
		cout << ", " << tmp->prev->data.breed << "\n" << endl;
	}
}

void LinkedList::addNode(Animal a, int pos){
	int rang = pos;
	
	Node* nxt = header;
	Node* nd = new Node(a, nullptr, nullptr);
	nd->data.id = pos;

	while(pos - 1 > 0){
		pos--;
		nxt = nxt->next;
	}

	nd->prev = nxt;
	nd->next = nxt->next;

	nxt->next->prev = nd;
	nxt->next = nd;
}
