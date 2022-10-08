#include <iostream>
#include <string>

#include "ListaDoble.h"

// Variables globales
// utilizadas por menu()
std::string mNombre = "";
std::string mRaza = "";
int mID = 0;
int opcion = 0;
ListaDoble ld();


void menu(void){
	std::cout << "--- Zoológico de Guadalajara ---\n\n";

	while(opcion != 13){
		std::cout << "\n1. insertar\n";
		std::cout << "2. eliminar\n";
		std::cout << "3. buscar\n";
		std::cout << "4. vacia\n";
		std::cout << "5. inicializa\n";
		std::cout << "6. primero\n";
		std::cout << "7. ultimo\n";
		std::cout << "8. anterior\n";
		std::cout << "9. siguiente\n";
		std::cout << "10. tamaño\n";
		std::cout << "11. vaciar (eliminarTodo)\n";
		std::cout << "12. mostrarLista\n";
		std::cout << "13. salir\n";
		std::cout << ": ";
		std::cin >> opcion;

		switch(opcion){
			case 1:
				std::cout << "Hola2";
				break;
			default:
				std::cout << "Opción inválida\n";
		}
	}
	std::cout << "Hola" << std::endl;
}

int main(){
	menu();
	return 0;
}
