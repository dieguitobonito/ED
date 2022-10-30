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
	void top(void);
	bool vacia(void);
	void inicializa(void);
	unsigned int tamaño(void);
	void vaciar(void);
	void mostrarPila(void);
};

#endif // LISTA_H
