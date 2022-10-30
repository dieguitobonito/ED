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
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
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
