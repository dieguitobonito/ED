#include <iostream>
using namespace std;

#include "LinkedList.h"

void menu(){
	cout << "--- Lista doblemente ligada ---\n\n";
	LinkedList ld;

	string menu_name;
	unsigned int menu_age;
	bool vaxio = false;

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
				if(vaxio == true){
					ld.initialize();
					vaxio = false;
				}
				cout << "\nInserte nombre\n: ";
				cin >> menu_name;
				cout << "Inserte edad\n: ";
				cin >> menu_age;

				Alumno kid(menu_name, menu_age);
				if(ld.isEmpty()){
					ld.addFront(kid);
				}else{
					unsigned int pos;
					ld.printForward();
					cout << "En qué posición: ";
					cin >> pos;
					int tam = ld.size();
					if(pos > 0 && pos <= tam){
						ld.addNode(kid, pos);
					}else{
						cout << "\nPosición fuera de rango" << endl;
					}
				}
				cout << "\n";
				break;
			}
			case 2:{
				if(!ld.isEmpty()){
					cout << "\nInserte nombre\n: ";
					cin >> menu_name;
					cout << "Inserte edad\n: ";
					cin >> menu_age;
					cout << "\n";
					ld.deleteThis(menu_name, menu_age);
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
					ld.deleteAll();
					vaxio = true;
				}
				break;
			}
			case 4:{
				cout << "\nNombre del alumno a buscar\n: ";
				cin >> menu_name;
				cout << "Edad del dicho\n: ";
				cin >> menu_age;
				Node* addr = ld.find(menu_name, menu_age);
				if(addr != nullptr){
					cout << "\nAlumno encontrado en " << addr << "\n" << endl;
				}else{
					cout << "\nAlumno no encontrado\n" << endl;
				}
				break;
			}
			case 5:{
				ld.initialize();
				break;
			}
			case 6:{
				if(ld.isEmpty()){
					cout << vaxio << endl;

					cout << "\nLista vacía\n" << endl;
				}else{
					cout << "\nLista no vacía\n" << endl;
				}
				break;
			}
			case 7:{
				ld.getFront();
				break;
			}
			case 8:{
				ld.getBack();
				break;
			}
			case 9:{
				unsigned int cant = ld.size();
				cout << "\nHay " << cant << " elemento(s) en la lista\n" << endl;
				break;
			}
			case 10:{
				cout << "\nNombre del alumno para saber el siguiente\n: ";
				cin >> menu_name;
				cout << "Edad\n: ";
				cin >> menu_age;
				ld.nextNode(menu_name, menu_age);
				break;
			}
			case 11:{
				cout << "\nNombre del alumno para saber el anterior\n: ";
				cin >> menu_name;
				cout << "Edad\n: ";
				cin >> menu_age;
				ld.prevNode(menu_name, menu_age);
				break;
			}
			case 12:{
				if(!ld.isEmpty()){
					ld.printForward();
				}else{
					cout << "\n¡Lista vacía!\n" << endl;
				}
				break;
			}
			case 13:{
				if(!ld.isEmpty()){
					ld.printReverse();
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
