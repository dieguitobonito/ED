#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"

class ListaDoble{
	private:
		Nodo* cabecera;
		Nodo* cola;
	public:
		ListaDoble();
		ListaDoble(Nodo*, Nodo*);

		void insertar(Animal, unsigned int); 
		void eliminar(std::string, std::string);
		Nodo* buscar(std::string, std::string);
		bool vacia(void);
		bool inicializa(void);
		Nodo* primero(void);
		Nodo* ultimo(void);
		Nodo* anterior(std::string, std::string);
		Nodo* siguiente(std::string, std::string);
		unsigned int tamaño(void);
		bool eliminarTodo(void);
		void mostrarLista(void);
};
#endif
