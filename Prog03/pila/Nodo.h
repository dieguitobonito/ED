#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

#include "Datos.h"

class Nodo{
	private:
		Datos A;
		Nodo* sig;
	public:
		// Constructores
		Nodo();
		Nodo(Datos, Nodo*);

		friend class Lista;
};

#endif // NODO_H
