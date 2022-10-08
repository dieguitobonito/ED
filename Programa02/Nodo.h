#ifndef NODO_H
#define NODO_H

class Nodo{
	private:
		Animal dato;
		Nodo* sig;
		Nodo* ant;
	public:
		Nodo();
		Nodo(Animal, Nodo*, Nodo*)

	friend class ListaDoble;
};
