#include <iostream>
using namespace std;

#include "LinkedList.h"

void menu(){
	cout << "--- Zoológico de Guadalajara ---\n\n";

	LinkedList ll;

	string menu_name;
	string menu_breed;
	bool empty = false;

	unsigned int option;

	while(option != 14){
		cout << "1.- Insertar" << endl;
		cout << "2.- Eliminar" << endl;
		cout << "3.- Eliminar todo" << endl;
		cout << "4.- Buscar" << endl;
		cout << "5.- Inicializa" << endl;
		cout << "6.- Vacía" << endl;
		cout << "7.- Primero" << endl;
		cout << "8.- Último" << endl;
		cout << "9.- Tamaño" << endl;
		cout << "10.- Siguiente" << endl;
		cout << "11.- Anterior" << endl;
		cout << "12.- Imprimir" << endl;
		cout << "13.- Imprimir al revés" << endl;
		cout << "14.- Salir" << endl; cout << ": ";
		cin >> option;

		switch(option){
			case 1:{
				if(empty == true){
					ll.initialize();
					empty = false;
				}
				cout << "\nInserte nombre\n: ";
				cin >> menu_name;
				cout << "Raza\n: ";
				cin >> menu_breed;

				Animal specimen(menu_name, menu_breed);
				if(ll.isEmpty()){
					ll.addFront(specimen);
				}else{
					unsigned int pos;
					ll.printForward();
					cout << "En qué posición: ";
					cin >> pos;
					int tam = ll.size();
					if(pos > 0 && pos <= tam){
						ll.addNode(specimen, pos);
					}else{
						cout << "\nPosición fuera de rango" << endl;
					}
				}
				cout << "\n";
				break;
			}
			case 2:{
				if(!ll.isEmpty()){
					cout << "\nInserte nombre\n: ";
					cin >> menu_name;
					cout << "Inserte edad\n: ";
					cin >> menu_breed;
					cout << "\n";
					ll.deleteThis(menu_name, menu_breed);
				}else{
					cout << "\n¡Ni siquiera hay lista!\n" << endl;
				}
				break;
			}
			case 3:{
				int decision;
				cout << "\n¿Segur@?\n1. Sí\n2. No\n: ";
				cin >> decision;
				if(decision != 1){
					cout << "\nOperación cancelada\n" << endl;
				}else{
					cout << "\n";
					ll.deleteAll();
					empty = true;
				}
				break;
			}
			case 4:{
				cout << "\nNombre del animal a buscar\n: ";
				cin >> menu_name;
				cout << "Raza del dicho\n: ";
				cin >> menu_breed;
				Node* addr = ll.find(menu_name, menu_breed);
				if(addr != nullptr){
					cout << "\nAnimal encontrado en " << addr << "\n" << endl;
				}else{
					cout << "\nAnimal no encontrado\n" << endl;
				}
				break;
			}
			case 5:{
				ll.initialize();
				break;
			}
			case 6:{
				if(ll.isEmpty()){
					cout << empty << endl;

					cout << "\nLista vacía\n" << endl;
				}else{
					cout << "\nLista no vacía\n" << endl;
				}
				break;
			}
			case 7:{
				ll.getFront();
				break;
			}
			case 8:{
				ll.getBack();
				break;
			}
			case 9:{
				unsigned int cant = ll.size();
				cout << "\nHay " << cant << " elemento(s) en la lista\n" << endl;
				break;
			}
			case 10:{
				cout << "\nNombre del animal para saber el siguiente\n: ";
				cin >> menu_name;
				cout << "Raza\n: ";
				cin >> menu_breed;
				ll.nextNode(menu_name, menu_breed);
				break;
			}
			case 11:{
				cout << "\nNombre del animal para saber el anterior\n: ";
				cin >> menu_name;
				cout << "Raza\n: ";
				cin >> menu_breed;
				ll.prevNode(menu_name, menu_breed);
				break;
			}
			case 12:{
				if(!ll.isEmpty()){
					ll.printForward();
				}else{
					cout << "\n¡Lista vacía!\n" << endl;
				}
				break;
			}
			case 13:{
				if(!ll.isEmpty()){
					ll.printReverse();
				}else{
					cout << "\n¡Lista vacía!\n" << endl;
				}
				break;
			}
			case 14:{
				cout << "\nHasta luego\n" << endl;
				break;
			}
			default:{
				cout << "\nOpción inválida\n" << endl;
			}
		}
	}
}

int main(){
	menu();
	return 0;
}
