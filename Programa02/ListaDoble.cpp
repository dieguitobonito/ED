#include <iostream>
#include "ListaDoble.h"

ListaDoble::ListaDoble(){
	cabecera = nullptr;
	cola = nullptr;
}

void ListaDoble::insertar(Animal e, unsigned int pos){
	Nodo* nd = new Nodo(e, nullptr, nullptr);
	Nodo* aux = cabecera;	

	// Para que se inserte antes
	while(pos - 1 > 0){
		aux = aux->sig;
		pos--;
	}

	nd->ant = aux;
	nd->sig = aux->sig;
	aux->sig->ant = nd;
	aux->sig = nd;
}

void ListaDoble::eliminar(std::string n, std::string r){
	Nodo* aux = buscar(n, r);
	// Conectando los nodos
	if(aux){
		aux->ant->sig = aux->sig; 
		aux->sig->ant = aux->ant;
		delete aux;
		std::cout << "Animal removido";
	}else{
		std::cout << "Animal no encontrado";
	}
}

Nodo* ListaDoble::buscar(std::string n, std::string r){
	Nodo* aux;
	bool encontrado = false;

	while(aux && !encontrado){
		if(aux->dato.nombre == n || aux->dato.raza == n){
			encontrado = true;
		}else{
			aux = aux->sig;
		}
	}
	return aux;
}

bool ListaDoble::vacia(void){
	if(cabecera->sig == cola){
		return true;
	}else{
		return false;
	}
}
bool ListaDoble::inicializa(void){
	if(vacia()){
		cabecera = new Nodo();
		cola = new Nodo();
		cabecera->sig = cola;
		cola->ant = cabecera;
		cabecera->ant = nullptr;
		cola->sig = nullptr;
		return true;
	}else{
		return false;
	}
}

Nodo* ListaDoble::primero(void){
	return cabecera->sig;
}

Nodo* ListaDoble::ultimo(void){
	return cola->ant;
}

Nodo* ListaDoble::anterior(std::string n, std::string r){
	Nodo* aux = buscar(n, r);
	if(aux){
		return aux->ant;
	}else{
		return aux;
	}
}

Nodo* ListaDoble::siguiente(std::string n, std::string r){
	Nodo* aux = buscar(n, r);
	if(aux){
		return aux->sig;
	}else{
		return aux;
	}
}

unsigned int ListaDoble::tamaño(void){
	unsigned int cant = 0;
	if(!vacia()){
		Nodo* aux = cabecera;
		while(aux){
			cant++;
			aux = aux->sig;
		}
	}
	return cant;
}

bool ListaDoble::eliminarTodo(void){
	if(!vacia()){
		Nodo* aux = cola->ant;
		while(aux != cabecera){
			aux = aux->ant;
			delete aux->sig;
		}
	}
	delete cabecera;
	delete cola;
	return true;
}

void ListaDoble::mostrarLista(void){
	if(vacia()){
		std::cout << "Lista vacía\n";
	}else{
		Nodo* aux = cabecera;
		while(aux != cola){
			std::cout << aux->dato.ID << ".- ";
			std::cout << aux->dato.nombre << ", ";
			std::cout << aux->dato.raza << "\n";
		}
		std::cout << "\n";
	}
}
