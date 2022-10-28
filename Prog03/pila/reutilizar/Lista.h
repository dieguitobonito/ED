#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;

class Lista{
    public:
        Nodo* h;

	// Constructores
	Lista();
        Lista(Nodo*);

        // Métodos
	void insertar(string, int);
	void eliminar(string);
	void buscar(string);
	void vacía(void);
	void inicializa(void);
	void primero(void);
	void ultimo(void);
	void anterior(string);
	void siguiente(string);
	int tamaño(void);
	void vaciar(void);
	void mostrarTodo(void);
};

#endif // LISTA_H
