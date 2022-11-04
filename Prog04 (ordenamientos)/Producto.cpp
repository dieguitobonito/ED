#include "Producto.h"

Producto::Producto(){
	name = "";
	price = 0;
	id = 0;
}

Producto::Producto(string name, float price, unsigned int id){
	this->name = name;
	this->price = price;
	this->id = id;
}
