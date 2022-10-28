#include "Nodo.h"

// Constructor predeterminado
Nodo::Nodo(){
    cadena = "-";
    sig = nullptr;
}

Nodo::Nodo(string cadena, Nodo* sig){
    this->cadena = cadena;
    this->sig = sig;
}
