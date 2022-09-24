#include "Alumno.h"
#include <string>

using namespace std;

// Constructor predeterminado
Alumno::Alumno(){
    	nombre = "";
    	edad = 0;

}

Alumno::Alumno(string nombre, int edad){
	this->nombre = nombre;
    	this->edad = edad;
}
