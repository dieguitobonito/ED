#include "Nodo.h"

// Constructor predeterminado
Nodo::Nodo(){
    cadena = "";
    sig = nullptr;

}

Nodo::Nodo(string cadena, Nodo* sig){
    this->cadena = nombre;
    this->sig = sig;
}
