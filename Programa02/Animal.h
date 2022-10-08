#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal{
	private:
		std::string nombre;
		std::string raza;
		int ID;
	public:
		Animal();
		Animal(std::string, std::string, int id);

	friend class Nodo;
	friend class ListaDoble;
};
#endif
