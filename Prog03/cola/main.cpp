#include <iostream>
#include "Lista.h"
#include "Nodo.h"
#include "Datos.h"

#include <string>
using namespace std;

void menu(){
	int opcion = 0;
	string menuNombre = "";
	unsigned int menuEdad = 0;
	Lista cola;

	cout << "--- Cola ---" << endl;
	while(opcion != 11){
		cout << "1. insertar (queue )\n"
			"2. eliminar (dequeue)\n"
			"3. buscar ???\n"
			"4. first\n"
			"5. last\n"
			"6. vacia\n"
			"7. inicializa\n"
			"8. tamaño\n"
			"9. vaciar (eliminarTodo)\n"
			"10. mostrarPila\n"
			"11. salir\n"
			": ";
		cin >> opcion;

		switch(opcion){
			case 1:{
				cout << "Inserte nombre: ";
				cin >> menuNombre;
				cout << "Inserte edad: ";
				cin >> menuEdad;
				Datos data(menuNombre, menuEdad);
				cola.insertar(data);
				break;
			}
			case 2:{
				cola.eliminar();
				break;
			}
			case 3:{
				cout << "Nombre a buscar: ";
				cin >> menuNombre;
				cout << "Edad: ";
				cin >> menuEdad;
				Nodo* direccion = cola.buscar(menuNombre, menuEdad);
				if(direccion != nullptr)
					cout << "Datos en " << direccion << endl;
				else
					cout << "No se encontró nada" << endl;
				break;
			}
			case 4:{
				cola.first();
				break;
			}
			case 5:{
				cola.last();
				break;
			}
			case 6:{
				if(cola.vacia())
					cout << "Lista vacía" << endl;
				else
					cout << "Lista no vacía" << endl;
				break;
			}
			case 7:{
				cola.inicializa();
				break;
			}
			case 8:{
				unsigned int cant = cola.tamaño();
				cout << "Tamaño: " << cant << endl;
				break;
			}
			case 9:{
				cola.vaciar();
				break;
			}
			case 10:{
				cola.mostrarCola();
				break;
			}
			case 11:
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
