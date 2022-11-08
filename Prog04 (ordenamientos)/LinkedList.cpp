// El orden de los headers importa?
#include "Node.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
using namespace std;


LinkedList::LinkedList(){
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = nullptr;
	trailer->next = nullptr;
}

void LinkedList::addNode(Producto a){
	// Primer nodo
	if(!header->next && !trailer->prev){
		Node* tmp = new Node(a);
		header->next = tmp;
		trailer->prev = tmp;
	}
	// Resto de nodos
	else{
		Node* tmp = new Node(a);
		Node* tmpTrailer = trailer->prev;
		tmpTrailer->next = tmp;
		tmp->prev = tmpTrailer;
		trailer->prev = tmp;
	}
}

void LinkedList::remove(){
	Node* tmp = header->next;
	tmp->prev = nullptr;
	header = tmp;
	delete tmp;

}

void LinkedList::printForward(){
	// Referencia al verdadero
	// primer dato
	if(!header && !trailer)
		cout << "Lista vacia" << endl;
	else{
		Node* tmp = header->next;

		cout << "\n";
		cout << "Id, nombre de producto y precio\n" << endl;
		unsigned int count = 0;
		while(tmp){
			count++;
			cout << count << ".- ";
			cout << tmp->data.id << ", " << tmp->data.name <<
				", " << tmp->data.price << endl;
			tmp = tmp->next;
		}
	}
	
	cout << "\n";
}

void LinkedList::deleteAll(void){


}

// Ordenar id
void LinkedList::quickSort(LinkedList* l){
	Node* piv;
	Node* pivSave;
	Node* aux;

	LinkedList* upper = new LinkedList;
	LinkedList* lower = new LinkedList;

	if(l->header){
		piv = l->header;
		pivSave = new Node(l->header->data);
		aux = l->header->next;

		while(aux){
			if(aux->data.id < piv->data.id){
				lower->addNode(aux->data);
			}
			else{
				upper->addNode(aux->data);
			}
			aux = aux->next;
		}
	}

	quickSort(lower);
	quickSort(upper);

	aux = l->header;
	Node* low = lower->header;
	while(low){
		aux->data = low->data;
		aux = aux->next;
		low = low->next;
	}
	{
		aux->data = pivSave->data;
		aux = aux->next;
	}

	Node* up = upper->header;
	while(up){
		aux->data = up->data;
		aux = aux->next;
		up = up->next;
	}
}


void LinkedList::mergeSort(void){
	cout << "mergeSort" << endl;
}

void LinkedList::insertSort(void){
	cout << "insertSort" << endl;
}

void LinkedList::selectSort(void){
	cout << "selectSort" << endl;
}

void LinkedList::bogoSort(void){
	cout << "JAJAJAJJAJAJAJAJAJJAJAJA" << endl;
}

// void LinkedList::insert(Producto a){
// 	Node* tmp = new Node(a);
// 	if(header && trailer){
// 		tmp->next = header;
// 		header->prev = tmp;
// 		header = tmp;
// 	}
// 	else{
// 		header = tmp;
// 		trailer = tmp;
// 	}
// }
