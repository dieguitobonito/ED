#include "Lista.h"

// Constructor por defecto
Lista::Lista(){
	h = nullptr;
}

Lista::Lista(Nodo* sigPos){
	this->h = sigPos;
}

/*
----- Métodos -----
*/

void Lista::insertar(string s, int d){
	Nodo* aux = h;
	Nodo* insertable = new Nodo(s, nullptr);
	Nodo* ant = nullptr;
	int posible = 0;
	int cantidad = tamaño();
	bool inicializada = true;

	if(h == nullptr){
		cout << "No hay lista aún, créala desde el menú principal" << endl;
		inicializada = false;
	}
	else{
		if(inicializada == true){
			if(d > 0 && d <= cantidad){
				aux = h;
				// El - 1 para ajustarlo a la forma en que insertarías en la vida real, supongo...
				while(d - 1 > 0){
					ant = aux;
					aux = aux->sig;
					d--;
				}
				// Está al principio
				if(aux == h){
					insertable->sig = h;
					h = insertable;
				}
				// Está en otra posición, aplica para
				// el final
				else{
					insertable->sig = ant->sig;
					ant->sig = insertable;
				}
				cout << "Nodo insertado" << endl;
			}
			else{
				cout << "Valor fuera del rango de la lista" << endl;
			}
		}
	}
}

void Lista::eliminar(string s){
	if(h == nullptr){
		cout << "Lista inexistente" << endl;
	}
	else{
		Nodo* aux = h;
		Nodo* auxAnt = nullptr;
		// Necesitamos una variable dinámica
		// para borrar correctamente
		Nodo* auxEliminable = new Nodo();

		bool valoresEncontrados = false;

		while(aux && !valoresEncontrados){
			if(aux->cadena == s){
				valoresEncontrados = true;
			}
			else{
				auxAnt = aux;
				aux = aux->sig;
			}
		}
		if(!aux && !valoresEncontrados){
			cout << "No se encontró el nodo" << endl;
		}
		// Está al inicio de la lista
		else if(aux == h){
			auxEliminable = aux;
			h = aux->sig;
			delete auxEliminable;
		}
		// Al final de la lista
		else if(!aux->sig){
			auxEliminable = aux;
			auxAnt->sig = nullptr;
			delete auxEliminable;
		}
		// En medio
		else{
			auxEliminable = aux;
			auxAnt->sig = aux->sig;
			delete auxEliminable;
		}
	}
}

void Lista::buscar(string s){
	Nodo* comp = new Nodo(s, nullptr);
	Nodo* aux = h;
	bool encontrado = false;	

	if(h == nullptr){
		cout << "¡No hay lista por la cual buscar!" << endl;
	}
	else{
		while(aux && !encontrado){
			if(aux->cadena == s){
				encontrado = true;
			}
			aux = aux->sig;
		}
		if(aux && encontrado){
			cout << "Nodo encontrado en dirección: " << aux << endl;
		}
		else{
			cout << "No se encontró nodo" << endl;
		}
	}
}

void Lista::vacía(void){
	if(h == nullptr){
		cout << "La lista está vacía" << endl;
	}
	else{
		cout << "Lista no vacía" << endl;
	}
}

void Lista::inicializa(void){
	h = new Nodo();
	cout << "Lista inicializada" << endl;
}

void Lista::primero(void){
	if(!h){
		cout << "¡Ni siquiera existe lista!" << endl;
	}
	else{
		cout << "El primer nodo es: ";
		cout << h->cadena << endl;
	}
}

void Lista::ultimo(void){
	if(!h){
		cout << "Lista inexistente" << endl;
	}
	else{
		Nodo* aux = h;
		while(aux->sig){
			aux = aux->sig;
		}

		cout << "El último nodo es: ";
		cout << aux->cadena << endl;
	}
}

void Lista::anterior(string s){
	Nodo* comp = new Nodo(s, nullptr);
	Nodo* aux = h;
	Nodo* auxAnt = nullptr;
	bool encontrado = false;	

	if(h == nullptr){
		cout << "¡No hay lista por la cual buscar!" << endl;
	}
	else{
		while(aux && !encontrado){
			if(aux->cadena == s){
				encontrado = true;
			}
			else{
				auxAnt = aux;
				aux = aux->sig;
			}
		}
		if(!auxAnt && encontrado){
			comp = aux->sig;
			cout << "Del nodo con el dato " << aux->cadena << " no hay nodo anterior" << endl;
		}
		else if(auxAnt->sig && encontrado){
			cout << "Antes del nodo con el dato " << aux->cadena << " está el nodo con el dato " << auxAnt->cadena << endl;
		}
		else{
			cout << "Nodo no encontrado" << endl;
		}
	}
}

void Lista::siguiente(string s){
	Nodo* comp = new Nodo(s, nullptr);
	Nodo* aux = h;
	bool encontrado = false;	

	if(h == nullptr){
		cout << "¡No hay lista por la cual buscar!" << endl;
	}
	else{
		while(aux && !encontrado){
			if(aux->cadena == s){
				encontrado = true;
			}
			else{
				aux = aux->sig;
			}
		}
		if(aux->sig && encontrado){
			comp = aux->sig;
			cout << "Del nodo con el dato:  " << aux->cadena << " está el nodo con el dato " << comp->cadena << endl;
		}
		else if(!aux->sig && encontrado){
			cout << "Del nodo con el dato " << aux->cadena << " no hay siguiente nodo" << endl;
		}
		else{
			cout << "Nodo no encontrado" << endl;
		}
	}
}

int Lista::tamaño(void){
	Nodo* aux = h;
	int cantidad = 0;
	if(h == nullptr){
		cout << "Lista inexistente" << endl;
	}
	else{
		while(aux != nullptr){
			aux = aux->sig;
			cantidad++;
		}
	
	}
	return cantidad;
}

void Lista::vaciar(void){
	if(h == nullptr){
		cout << "No hay lista que eliminar" << endl;
	}
	else{
		Nodo* aux = h;
		Nodo* auxAnt = new Nodo();
		while(aux){
			auxAnt = aux;
			aux = aux->sig;
			delete auxAnt;
		}
		h = nullptr;
		cout << "Lista eliminada" << endl;
	}
}

void Lista::mostrarTodo(void){
	Nodo* aux = h;

	// Puede representarse como 'aux == nullptr'
	if(!aux){
		cout<< "¡No hay lista!" << endl;
	}
	else{
		// Mientras aux tenga un valor
		int contador = 1;
		while(aux != nullptr){
			cout << contador << ".- ";
			cout << aux->cadena << endl;
			aux = aux->sig;
			contador++;
		}
	}
}
