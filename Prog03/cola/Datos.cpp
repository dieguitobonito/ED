#include "Datos.h"

Datos::Datos(){
	nombre = "";
	edad = 0;
}

Datos::Datos(string nombre, unsigned int edad){
	this->nombre = nombre;
	this->edad = edad;
}
