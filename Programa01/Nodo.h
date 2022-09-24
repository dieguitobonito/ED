#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo{
	public:
		string cadena;
		Nodo* sig;

		// Constructores
		Nodo();
		Nodo(string, Nodo*);
};

#endif // NODO_H
