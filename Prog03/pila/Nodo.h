#ifndef NODO_H
#define NODO_H

class Nodo{
	private:
		Datos A;
		Nodo* sig;
	public:
		Nodo(Datos, Nodo*);
		Nodo();
};

#endif
