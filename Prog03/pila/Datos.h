#ifndef DATOS_H
#define DATOS_H

#include <string>
using namespace std;

class Datos{
	private:
		string nombre;
		unsigned int edad;
	public:
		Datos();
		Datos(string, unsigned int);

		friend class Lista;
};
#endif
