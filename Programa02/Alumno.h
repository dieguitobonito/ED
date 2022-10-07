#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
using namespace std;

class Alumno{
	public:
		Alumno();
		Alumno(string, unsigned int);
	private:
		string name;
		unsigned int age;

	friend class Node;
	friend class LinkedList;
};
#endif
