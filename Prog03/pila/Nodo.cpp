#include "Nodo.h"

Nodo::Nodo(Datos A, Nodo* sig){
	A();
	this->sig = sig;
}
