#include "Nodo.h"

Nodo::Nodo(){
	dato = Animal();
	sig = nullptr;
	ant = nullptr;
}

Nodo::Nodo(Animal dato, Nodo* sig, Nodo* ant){
	this->dato = dato;
	this->sig = sig;
	this->ant = ant;
}
