#include "Animal.h"

Animal::Animal(){
	nombre = "";
	raza = "";
	ID = 0;
}

Animal::Animal(string nombre, string raza, int ID){
	this->nombre = nombre;
	this->raza = raza;
	this->ID = ID;
}
