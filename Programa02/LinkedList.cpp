// El orden de los headers importa?
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
		cout << header->next->data.age << "\n" << endl;
	}
}

// Same as getfront
void LinkedList::getBack(){
	if(isEmpty()){
		cout << "\nNo hay último\n" << endl;
	}else{
		cout << "El último es: ";
		cout << trailer->prev->data.name << ", ";
		cout << trailer->prev->data.age << endl;
	}
}

void LinkedList::addFront(Alumno a){
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

	unsigned int count = size();
	cout << "\n";
	while(tmp != header){
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.age << endl;
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
	unsigned int count = 0;
	while(tmp != trailer){
		count++;
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.age << endl;
		tmp = tmp->next;
	}
	cout << "\n";
}

bool LinkedList::isEmpty(void){
	return (header->next == trailer);
}

Node* LinkedList::find(string n, unsigned int a){
	Node* aux;
	aux = header;
	bool found = false;
	if(isEmpty()){
		cout << "\nNo hay lista para comenzar\n" << endl;
		return nullptr;
	}else{
		while(aux != nullptr && found == false){
			if(aux->data.name == n && aux->data.age == a){
				found = true;
			}else{
				aux = aux->next;
			}
		}
	}
	return aux;
}

void LinkedList::deleteThis(string n, unsigned int a){
	Node* aux = find(n, a);
	if(aux){
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		delete aux;
		cout << "Alumno eliminado\n" << endl;
	}else{
		cout << "Alumno no encontrado\n" << endl;
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

unsigned int LinkedList::size(void){
	unsigned int cant = 0;
	if(!isEmpty()){
		Node* aux = header->next;
		while(aux != trailer){
			cant++;
			aux = aux->next;
		}
	}
	return cant;	
}

void LinkedList::nextNode(string n, unsigned int a){
	Node* tmp = find(n, a);

	// Para no acceder ilegalmente
	if(tmp == nullptr){
		cout << "\nAlumno no encontrado\n" << endl;
	}else if(tmp->next == trailer){
		cout << "\nNo hay alumno siguiente\n" << endl;
	}else{
		cout << "\nEl alumno siguiente es " << tmp->next->data.name;
		cout << ", " << tmp->next->data.age << endl;
		cout << "\n";
	}
}

void LinkedList::prevNode(string n, unsigned int a){
	Node* tmp = find(n, a);

	if(tmp->prev == header){
		cout << "\nNo hay alumno anterior\n" << endl;
	}else{
		cout << "\nEl alumno anterior es " << tmp->prev->data.name;
		cout << ", " << tmp->prev->data.age << "\n" << endl;
	}
}

void LinkedList::addNode(Alumno a, unsigned int pos){
	unsigned int rang = pos;
	
	Node* nxt = header;

	while(pos - 1 > 0){
		pos--;
		nxt = nxt->next;
	}
	
	Node* nd = new Node(a, nullptr, nullptr);

	nd->prev = nxt;
	nd->next = nxt->next;

	nxt->next->prev = nd;
	nxt->next = nd;
}
