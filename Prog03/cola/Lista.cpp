#include "Lista.h"

/*
----- Constructores -----
*/

Lista::Lista(){
	h = nullptr; t = nullptr;
}

Lista::Lista(Nodo* h, Nodo* t){
	this->h = h;
	this->t = t;
}

/*
----- Métodos -----
*/

void Lista::insertar(Datos a){
	if(vacia()){
		Nodo* primis = new Nodo(a, nullptr);
		h = primis;
		t = primis;
	}
	else{
		Nodo* aux = new Nodo(a, nullptr);
		Nodo* tmp = t;
		while(tmp->sig){
			tmp = tmp->sig;
		}
		tmp->sig = aux; 
		t = aux;
	}
}

void Lista::eliminar(void){
	if(vacia()){
		cout << "No hay elemento para eliminar" << endl;	
	}
	else{
		Nodo* aux = h;
		if(h == t){
			h = nullptr;
			t = nullptr;
			delete aux;
		}
		else{
			aux = h->sig;
			delete h;
			h = aux;
		}
	}
}

Nodo* Lista::buscar(string n, unsigned int e){
	Nodo* aux = h;
	bool encontrado = false;
	if(vacia()){
		cout << "No hay cola" << endl;
		return nullptr;
	}
	else{
		while(aux != nullptr && encontrado == false){
			if(aux->A.nombre == n && aux->A.edad == e)
				encontrado = true;
			else
				aux = aux->sig;
		}
	}
	if(encontrado)
		return aux;
	else
		return nullptr;
}

void Lista::first(void){
	if(vacia())
		cout << "Cola vacía" << endl;
	else
		cout << "El primero en salir es "
			<< h->A.nombre << ", "
			<< h->A.edad << endl;
}

void Lista::last(void){
	if(vacia())
		cout << "Cola vacía" << endl;
	else
		cout << "El último en salir es "
			<< t->A.nombre << ", "
			<< t->A.edad << endl;
}

bool Lista::vacia(void){
	if(h == nullptr && t == nullptr)
		return true;
	else
		return false;
}

void Lista::inicializa(void){
	if(vacia()){
		Lista();
		cout << "Lista inicializada" << endl;
	}
	else
		cout << "Ya se inicializó" << endl;
}

unsigned int Lista::tamaño(void){
	Nodo* aux = h;
	unsigned int cantidad = 0;

	while(aux){
		++cantidad;
		aux = aux->sig;
	}
	return cantidad;
}

void Lista::vaciar(void){
	while(!vacia()){
		eliminar();
	}
	delete h;
	delete t;
}
										
void Lista::mostrarCola(void){
	if(vacia()){
		cout << "No hay elementos que mostrar" << endl;
	}
	else{
		Nodo* aux = h;
		while(aux){
			cout << aux->A.nombre << ", " <<
				aux->A.edad << endl;
			aux = aux->sig;
		}
	}
}
