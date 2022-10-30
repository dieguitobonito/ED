#include "Lista.h"

/*
----- Constructores -----
*/

Lista::Lista(){
	h = nullptr;
	t = nullptr;
}

Lista::Lista(Nodo* h, Nodo* t){
	this->h = h;
	this->t = t;
}

/*
----- Métodos -----
*/

void Lista::insertar(Datos a){
	Nodo* aux = new Nodo(a, nullptr);
	Nodo* tmp = t;
	if(vacia()){
		Nodo* primis = new Nodo(a, nullptr);
		h = aux;
		t = aux;
	}
	else{
		while(tmp){
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
		Nodo* aux = t;
		while(aux->sig != h){
			aux = aux->sig;
		}
		delete h;
		aux->sig = nullptr;
		h = aux;
	}
}

Nodo* Lista::buscar(string n, unsigned int e){
	Nodo* aux = t;
	bool encontrado = false;
	if(vacia()){
		cout << "No hay pila" << endl;
		return nullptr;
	}
	else{

		while(!aux && !encontrado){
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

void Lista::top(void){
	if(vacia())
		cout << "Pila vacía" << endl;
	else
		cout << "El tope es: " << h->A.nombre << ", " <<
			h->A.edad << endl;
}

bool Lista::vacia(void){
	if(h->sig = t)
		return true;
	else
		return false;
}

void Lista::inicializa(void){
	h = new Nodo();
	t = new Nodo();
	
	h->sig = t;
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
										
void Lista::mostrarPila(void){
	if(vacia())
		cout << "No hay elementos que mostrar" << endl;
	else{
		Nodo* aux = t;
		while(t){
			cout << aux->A.nombre << ", " <<
				aux->A.edad << endl;
			aux = aux->sig;
		}
	}
}
