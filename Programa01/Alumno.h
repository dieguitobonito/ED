#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

class Alumno{
	public:
		string nombre;
		int edad;

		// Constructores
		Alumno();
		Alumno(string, int);
};

#endif // ALUMNO_H
