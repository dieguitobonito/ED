#include "Nodo.h"

// Constructor predeterminado
Nodo::Nodo(){
	Datos();
	sig = nullptr;
}

Nodo::Nodo(Datos A, Nodo* sig){
	this->A = A;
	this->sig = sig;
}
