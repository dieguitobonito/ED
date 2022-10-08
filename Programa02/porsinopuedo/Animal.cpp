#include "Animal.h"

Alumno::Alumno(){
	name = "Fulanito";
	breed = "Unknown";
	id = 0;
}

Alumno::Alumno(string name, string breed, int id){
	this->name = name;
	this->breed = breed;
	this->id = id;
}
