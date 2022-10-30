#include "Nodo.h"

// Constructor predeterminado
Nodo::Nodo(){
	Datos();
	sig = nullptr;
}

Nodo::Nodo(string cadena, Nodo* sig){
	this->cadena = cadena;
	this->sig = sig;
}
