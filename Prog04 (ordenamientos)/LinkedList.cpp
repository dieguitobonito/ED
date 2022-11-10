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

void LinkedList::swapNodes(Node* a, Node* b){
	Node* savedData;

	savedData->data.id = b->data.id;
	savedData->data.name = b->data.name;
	savedData->data.price = b->data.price;

	b->data.id = a->data.id;
	b->data.name = a->data.name;
	b->data.price = a->data.price;

	a->data.id = savedData->data.id;
	a->data.name = savedData->data.name;
	a->data.price = savedData->data.price;
}

void LinkedList::deleteAll(void){


}

int LinkedList::size(LinkedList* l){
	int quantity = 0;
	Node* tmp = l->header;
	while(tmp->next){
		++quantity;
		tmp = tmp->next;
	}
	return quantity;
}

void LinkedList::bubbleSort(LinkedList* l){
	Node* tmp = l->header->next;

	int nodes = size(l);
	int i = 0;

	while(i < nodes - 1){
		while(tmp->next){
			if(tmp->data.id > tmp->next->data.id){
				swapNodes(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
		tmp = l->header->next;
		i++;
	}
}

// Ordenar id
void LinkedList::quickSort(LinkedList* l){

}


void LinkedList::mergeSort(unsigned int size, LinkedList* l){
	cout << "mergeSort" << endl;
}

void LinkedList::insertSort(void){
	cout << "insertSort" << endl;
}

void LinkedList::selectSort(LinkedList* l){
	Node* aux = l->header->next;
	Node* menor = l->header->next;
	Node* pos = l->header->next;

	while(pos->next){
		aux = pos;
		menor = pos;
		while(aux->next){
			if(menor->data.price < aux->data.price){
				menor = aux;
			}
			aux = aux->next;
		}
		swapNodes(menor, pos);
		pos = pos->next;
	}
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
