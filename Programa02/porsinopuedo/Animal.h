#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal{
	public:
		Animal();
		Animal(string, string, int);
	private:
		string name;
		string breed;
		int id;

	friend class Node;
	friend class LinkedList;
};
#endif
