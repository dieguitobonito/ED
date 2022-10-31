#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
using namespace std;
#include "Nodo.h"

class Lista{
    public:
	Nodo* h;
	Nodo* t;

	// Constructores
	Lista();
	Lista(Nodo*, Nodo*);

	// Métodos pila
	void insertar(Datos);
	void eliminar(void);
	Nodo* buscar(string, unsigned int);
	void first(void);
	void last(void);
	bool vacia(void);
	void inicializa(void);
	unsigned int tamaño(void);
	void vaciar(void);
	void mostrarCola(void);
};

#endif // LISTA_H
