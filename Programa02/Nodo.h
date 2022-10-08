#ifndef NODO_H
#define NODO_H

#include "Animal.h"

class Nodo{
	private:
		Animal dato;
		Nodo* sig;
		Nodo* ant;
	public:
		Nodo();
		Nodo(Animal, Nodo*, Nodo*);

		friend class ListaDoble;
};
#endif
