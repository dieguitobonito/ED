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

// Return data instead of pointer
void LinkedList::getFront(){
	if(isEmpty()){
		cout << "\nNo hay primero\n" << endl;
	}else{
		cout << "\nEl primero es: ";
		cout << header->next->data.name << ", ";
		cout << header->next->data.id << "\n" << endl;
	}
}

// Generación de nodos
void LinkedList::nodeGeneration(){

	const char* names[127] = {
	"Pet Bed",
	"Dog Seat Cover",
	"Multifunction Biting Toys",
	"Dog Toothbrush",
	"Pet Grooming",
	"Pet Painting",
	"Novelty Cat Beds",
	"Dog Jackets",
	"Cat Litter Mat",
	"Personalized Dog Collar",
	"Robot Vacuum",
	"Smart Water Purifier",
	"Smart Tracker",
	"Smart Pet Toys",
	"Smartwatches",
	"Smart 3D Pens",
	"Reusable Smart Notebook",
	"Smart Home Security",
	"Smart Padlock",
	"Microwave Cleaner",
	"Multifunction Bottle Opener",
	"Embossed Rolling Pin",
	"Silicone Cooking Tools",
	"Vegetable Cutter",
	"Mandoline Slicers",
	"Silicone Gloves",
	"Milk Carton Water Bottle",
	"Spin Mop",
	"Reusable Silicone Lids",
	"Animal Socks",
	"Lambswool Coat",
	"Oversized Sweater",
	"Bodycon Dress",
	"Shapewear",
	"Nipple Covers",
	"Cat Hoodie",
	"Leather Jackets",
	"Floral Spring Jacket",
	"TV Blanket",
	"Men’s Plaid Shirt",
	"Hooded Sweatshirt",
	"Wool Coat",
	"Men’s Compression Shirts",
	"Bomber Jacket",
	"Spring Jacket",
	"Tech Gloves",
	"Mandarin Collar Shirts",
	"Men’s Joggers",
	"Bamboo Socks",
	"Orthopedic Pillows",
	"Bath Towel Cap",
	"Terrarium",
	"Pet Grooming Products",
	"Makeup Organizer",
	"Burrito Blanket",
	"Pet Bed",
	"Couch Slipcover",
	"Reversible Umbrella",
	"Reusable Straws",
	"Hip Hop Jewelry",
	"Charm Bracelet",
	"Solar System Bracelet",
	"Pendant Necklace",
	"Initial Necklace",
	"Multilayer Necklace",
	"Magnetic Bracelet",
	"Locket",
	"Hoop Earrings",
	"Personalized Letter Rings",
	"Magnetic Eyelashes",
	"Shimmer Nail Polish",
	"Hair Wigs",
	"Massage Gun",
	"Travel Makeup Brushes",
	"Foot Bath",
	"Beard Straightener",
	"Dental Scaler",
	"Neck Pillow",
	"Face Massage Roller",
	"Smartwatch",
	"Marble Watch",
	"Magnetic Starry Sky Watch",
	"Luminous Watch",
	"Sport Watches",
	"Luxury Watch",
	"Minimalist Watch",
	"Kids’ Smartwatch",
	"Fashion Watches",
	"Pregnancy Brace",
	"Baby Hip Seat",
	"Baby Moccasins",
	"Pacifier Feeder",
	"Mother and Baby Beanie Hats",
	"Baby Glove Teether",
	"Winter Clothing",
	"Spill-Proof Bowl",
	"Swaddle Wrap",
	"Hipseat Carrier",
	"Planetarium Light",
	"Photo Twinkle Lights",
	"Photo Lamp",
	"Night Light Projector",
	"Camping Headlamp",
	"Wall Lights and Sconce",
	"Pendant lamp",
	"Selfie Night Light",
	"Rocket Lamp",
	"Novelty Lights",
	"Measurement Tool",
	"Night Vision Security Camera",
	"Water-Saving Shower Head",
	"Air Diffuser",
	"Fabric Steamer",
	"Plug In Wall Heater",
	"Water Filter",
	"Sponge Paint Roller",
	"Double-Sided Tape",
	"Wedding Evening Dress",
	"Bridal Ball Gown",
	"Wedding Belt Sash",
	"LED Wedding Balloons",
	"Plus Size Evening Dress",
	"Bridal Hairband",
	"Silk Flowers",
	"Silicone Wedding Band",
	"Bridal Robe",
	"Men’s Formalwear Bowtie",
};

	unsigned int quantity = 0;
	cout << "¿Cuántos elementos quieres generar?\n: ";
	cin >> quantity;

	bool sure = true;

	if(quantity > 10000){
		int decision = 0;
		cout << "¿Seguro?\n1. Sí\n2. No\n: ";
		cin >> decision;
		switch(decision){
			case 1:{
				cout << "Tú lo pediste" << endl;
				sure = true;
				break;
			}
			case 2:{
				cout << "Es que sí son muchos" << endl;
				sure = false;
				break;
			}
			default:{
				cout << "Opción inválida" << endl;
				sure = false;
			}
		}
	}

	if(sure){
		srand(time(NULL));
		for(int i = 0; i < quantity; i++){
			string name = names[rand() * 127];
			float price = ((float) rand()) / (float) RAND_MAX * 100;
			unsigned int id = rand();

			Producto product(name, price, id);
			addFront(product);
		}
		cout << "\nListo\n" << endl;
	}
}

// Same as getfront
void LinkedList::getBack(){
	if(isEmpty()){
		cout << "\nNo hay último\n" << endl;
	}else{
		cout << "El último es: ";
		cout << trailer->prev->data.name << ", ";
		cout << trailer->prev->data.id << endl;
	}
}

void LinkedList::addFront(Producto a){
	if(isEmpty()){
		Node* first = new Node(a, nullptr, nullptr);
		header = first;
		trailer = first;
	}
	else{
		Node* aux = new Node(a, nullptr, nullptr);
		Node* tmp = trailer;
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = aux; 
		trailer = aux;
	}
}

void LinkedList::removeFront(){
	Node* nd = header->next->next;
	delete header->next;
	header->next = nd;
	nd->prev = header;
}

void LinkedList::printReverse(){
	// Referencia al verdadero
	// último dato
	Node* tmp = trailer->prev;

	unsigned int count = size();
	cout << "\n";
	while(tmp != header){
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.id << endl;
		tmp = tmp->prev;
		count--;
	}
	cout << "\n";
}

void LinkedList::printForward(){
	// Referencia al verdadero
	// primer dato
	Node* tmp = header->next;

	cout << "\n";
	unsigned int count = 0;
	while(tmp != trailer){
		count++;
		cout << count << ".- ";
		cout << tmp->data.name << ", " << tmp->data.id << endl;
		tmp = tmp->next;
	}
	cout << "\n";
}

bool LinkedList::isEmpty(void){
	return (!header and !trailer);
}

Node* LinkedList::find(string n, unsigned int a){
	Node* aux;
	aux = header;
	bool found = false;
	if(isEmpty()){
		cout << "\nNo hay lista para comenzar\n" << endl;
		return nullptr;
	}else{
		while(aux != nullptr && found == false){
			if(aux->data.name == n && aux->data.id == a){
				found = true;
			}else{
				aux = aux->next;
			}
		}
	}
	return aux;
}

void LinkedList::deleteThis(string n, unsigned int a){
	Node* aux = find(n, a);
	if(aux){
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		delete aux;
		cout << "Producto eliminado\n" << endl;
	}else{
		cout << "Producto no encontrado\n" << endl;
	}
}

void LinkedList::deleteAll(void){
	while(header->next != trailer)
		removeFront();

	delete header;
	delete trailer;
}

void LinkedList::initialize(void){
	if(isEmpty()){
		header = new Node();
		trailer = new Node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = nullptr;
		trailer->next = nullptr;
		cout << "\nLista inicializada\n" << endl;
	}else{
		cout << "\nLa lista está inicializada\n" << endl;
	}
}

unsigned int LinkedList::size(void){
	unsigned int cant = 0;
	if(!isEmpty()){
		Node* aux = header->next;
		while(aux != trailer){
			cant++;
			aux = aux->next;
		}
	}
	return cant;	
}

void LinkedList::nextNode(string n, unsigned int a){
	Node* tmp = find(n, a);

	// Para no acceder ilegalmente
	if(tmp == nullptr){
		cout << "\nProducto no encontrado\n" << endl;
	}else if(tmp->next == trailer){
		cout << "\nNo hay alumno nextuiente\n" << endl;
	}else{
		cout << "\nEl alumno nextuiente es " << tmp->next->data.name;
		cout << ", " << tmp->next->data.id << endl;
		cout << "\n";
	}
}

void LinkedList::prevNode(string n, unsigned int a){
	Node* tmp = find(n, a);

	if(tmp->prev == header){
		cout << "\nNo hay alumno anterior\n" << endl;
	}else{
		cout << "\nEl alumno anterior es " << tmp->prev->data.name;
		cout << ", " << tmp->prev->data.id << "\n" << endl;
	}
}

void LinkedList::addNode(Producto a, unsigned int pos){
	unsigned int rang = pos;
	
	Node* nxt = header;

	while(pos - 1 > 0){
		pos--;
		nxt = nxt->next;
	}
	
	Node* nd = new Node(a, nullptr, nullptr);

	nd->prev = nxt;
	nd->next = nxt->next;

	nxt->next->prev = nd;
	nxt->next = nd;
}
