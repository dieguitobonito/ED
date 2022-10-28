#include <iostream>
#include "Lista.h"
#include "Nodo.h"

#include <string>

using namespace std;
void menu(){
	cout << "--- Lista ---" << endl;
	int opc = 0;
	int valor;
	Lista principal;

	string cad;
	int posicion;

	while(opc != 13){
		cout << "1. Insertar" << endl;
		cout << "2. Eliminar" << endl;
		cout << "3. Buscar" << endl;
		cout << "4. Verificar si la lista está vacía" << endl;
		cout << "5. Inicializar la lista" << endl;
		cout << "6. Imprimir el primer nodo" << endl;
		cout << "7. Imprimir el último nodo" << endl;
		cout << "8. Imprimir el nodo anterior" << endl;
		cout << "9. Imprimir el nodo siguiente" << endl;
		cout << "10. Tamaño de la lista" << endl;
		cout << "11. Eliminar toda la lista" << endl;
		cout << "12. Mostrar toda la lista" << endl;
		cout << "13. Salir" << endl;
		cout << ": ";
		cin >> opc;
		cout << endl;
	
		switch(opc){
			// Insertar
			case 1:{
				principal.mostrarTodo();
				cout << "¿En qué posición quieres insertar?\n: " << endl;
				cin >> posicion;
				cout << "Inserta cadena\n: ";
				cin >> cad;
				principal.insertar(cad, posicion);
				break;
			}
			// Eliminar
			case 2:{	
				cout << "¿Qué dato tiene el nodo a eliminar?\n: ";
				cin >> cad;
				principal.eliminar(cad);
				break;
			}
			// Buscar
			case 3:{
				cout << "Dato a buscar\n: ";
				cin >> cad;
				principal.buscar(cad);
				break;
			}
			case 4:{
				principal.vacía();
				break;
			}
			// Inicializar
			case 5:{
				principal.inicializa();
			}
			case 6:{
				principal.primero();
				break;
			}
			case 7:{
				principal.ultimo();
				break;
			}
			case 8:{
				cout << "Insertar dato para imprimir el nodo anterior" << endl;
				cin >> cad;
				principal.anterior(cad);
				break;
			}
			case 9:{
				cout << "Insertar dato para imprimir el siguiente nodo" << endl;
				cin >> cad;
				principal.siguiente(cad);
				break;
			}
			case 10:{
				cout << "Hay " << principal.tamaño() << " nodos en la lista" << endl;
				break;
			}
			case 11:{
				int decision;
				cout << "Esta acción no puede revertirse, ¿continuar?" << endl;
				cout << "1.- Sí\n2.- No\n: ";
				cin >> decision;
				if(decision == 1){
					principal.vaciar();
				}
				else{
					cout << "No se eliminará la lista" << endl;
				}
				break;
			}
			case 12:{
				principal.mostrarTodo();
				break;
			}
			case 13:{
				cout << "Programa terminado" << endl;
				opc = 13;
			}
				break;
			default:
				cout << "Opción no válida" << endl;
		}
	}
}

int main(){
	menu();
	return 0;
}
