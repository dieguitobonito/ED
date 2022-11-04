#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto{
	public:
		Producto();
		Producto(string, float, unsigned int);
	private:
		string name;
		float price;
		unsigned int id;

	friend class Node;
	friend class LinkedList;
};
#endif
