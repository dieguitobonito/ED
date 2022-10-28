#include <iostream>
using namespace std;

void menu(){
	int op = 0;
	cout << "--- Pila ---" << endl; 
	while(op != 10){
		cout << "1.- insertar (push)" << endl;
		cout << "2.- eliminar (pop)" << endl;
		cout << "3.- buscar ???" << endl;
		cout << "4.- top" << endl;
		cout << "5.- vacia" << endl;
		cout << "6.- inicializa" << endl;
		cout << "7.- tamaño" << endl;
		cout << "8.- vaciar (eliminarTodo)" << endl;
		cout << "9.- mostrarPila" << endl;
		cout << "10.- salir" << endl;
		cout << ": ";
		cin >> op;

		switch(op){
			case 1:{
				cout <<
				break;
			}
			case 2:{
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				break;
			}
			case 7:{
				break;
			}
			case 8:{
				break;
			}
			case 9:{
				break;
			}
			case 10:{
				break;
			}
			default:
				cout << "Opción inválida" << endl;
		}
	}
}

int main(){
	menu();
	return 0;
}
