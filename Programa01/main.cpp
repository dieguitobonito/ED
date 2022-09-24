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
			case 1:{
				cout << "Inserta cadena\n: ";
				cin >> cad;
				principal.insertar(cad);
				break;
			}
			case 2:{	
				cout << "¿Qué dato tiene el nodo a eliminar?\n: ";
				cin >> cad;
				principal.insertarFinal(cad);
				break;
			}
			case 3:{
				principal.mostrarTodo();
				cout << "¿En qué posición quieres insertar?" << endl;
				cin >> posicion;
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;

				Alumno niño(name, age);
				principal.insertarPos(niño, posicion);
				break;
			}
			case 4:{
				cout << "¿Cómo se llama el alumno a dar de baja?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;

				Alumno niño(name, age);
				principal.eliminar(niño);
				break;
			}
			case 5:{
				int decision;
				cout << "Esta acción no puede revertirse, ¿continuar?" << endl;
				cout << "1.- Sí\n2.- No\n: ";
				cin >> decision;
				if(decision == 1){
					principal.eliminarTodo();
				}
				else{
					cout << "No se eliminará la lista" << endl;
				}
				break;
			}
			case 6:{
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;

				Alumno niño(name, age);
				principal.buscar(niño);
				break;
			}
			case 7:{
				principal.inicializa();
				break;
			}
			case 8:{
				principal.vacia();
				break;
			}
			case 9:{
				principal.primero();
				break;
			}
			case 10:{
				principal.ultimo();
				break;
			}
			case 11:{
				principal.tamaño();
				break;
			}
			case 12:{
				cout << "Dame el nombre del alumno que quieras saber quién sigue de él\n: ";
				cin >> name;
				cout << "La edad de dicho\n: ";
				cin >> age;
				Alumno niño(name, age);
				principal.siguiente(niño);
				break;
			}
			case 13:{
				cout << "Dame el nombre del alumno que quieras saber quién sigue antes de él\n: ";
				cin >> name;
				cout << "La edad de dicho\n: ";
				cin >> age;
				Alumno niño(name, age);
				principal.anterior(niño);
				break;
			}

			case 14:{
				principal.mostrarTodo();
			}
				break;
			// Salir
			case 15:{
				cout << "¡Ciao!" << endl;
				opc = 15;
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
