#include "Alumno.h"

Alumno::Alumno(){
	name = "Fulanito";
	age = 0;
}

Alumno::Alumno(string name, unsigned int age){
	this->name = name;
	this->age = age;
}
