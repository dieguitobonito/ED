#include <iostream>
#include "Lista.h"
#include "Nodo.h"

#include <string>
using namespace std;

void menu(){
	int opcion = 0;
	string menuNombre = "";
	unsigned int menuEdad = 0;
	Lista pila;

	cout << "--- Pila ---" << endl;
	while(opcion != 10){
		cout << "1. insertar (push)\n"
			"2. eliminar (pop)\n"
			"3. buscar ???\n"
			"4. top\n"
			"5. vacia\n"
			"6. inicializa\n"
			"7. tamaño\n"
			"8. vaciar (eliminarTodo)\n"
			"9. mostrarPila\n"
			"10. salir\n"
			": ";
		cin >> opcion;

		switch(opcion){
			case 1:{
				cout << "Inserte nombre: ";
				cin >> menuNombre;
				cout << "Inserte edad: ";
				cin >> menuEdad;
				Datos data(menuNombre, menuEdad);
				pila.insertar(data);
				break;
			}
			case 2:{
				pila.eliminar();
				break;
			}
			case 3:{
				cout << "Nombre a buscar: ";
				cin >> menuNombre;
				cout << "Edad: ";
				cin >> menuEdad;
				Nodo* direccion = pila.buscar(menuNombre, menuEdad);
				if(direccion != nullptr)
					cout << "Datos en " << direccion << endl;
				else
					cout << "No se encontró nada" << endl;
				break;
			}
			case 4:{
				pila.top();
				break;
			}
			case 5:{
				if(pila.vacia())
					cout << "Lista vacía" << endl;
				else
					cout << "Lista no vacía" << endl;
				break;
			}
			case 6:{
				pila.inicializa();
				break;
			}
			case 7:{
				unsigned int cant = pila.tamaño();
				cout << "Tamaño: " << cant << endl;
				break;
			}
			case 8:{
				pila.vaciar();
				break;
			}
			case 9:{
				pila.mostrarPila();
				break;
			}
			case 10:
				cout << "Adiós" << endl;
				break;
			default:
			cout << "Opción incorrecta" << endl;
		}
	}
}

int main(){
	menu();
	return 0;
}
