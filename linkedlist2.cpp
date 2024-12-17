#include <iostream>
using namespace std;

class List {

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;

public:
    List() { //como la lista esat vacia no hay ni primer ni ultimo elemento
        first = nullptr;
        last = nullptr;
        num_elems = 0;
    }

    ~List() {
        while (first != nullptr) { //si hay elementos en la lista (si hay un numero en la primera pos)
            Node* temp = first;
            first = first->next; //no entiendo
            delete temp;
        }
    }

    void push_back(const int& value) {
        Node* newNode = new Node(value);  /*se crea un nuevo nodo con el valor ingresado en el main,  
        next y prev se inicializan a nullptr en el constructor.*/
        if (last == nullptr) { //si el ultimo elemento esta vacio,
            first = last = newNode; //se establece como unico elemento el que ha ingresado
        }
        else { //si la lista no esta vacia
            last->next = newNode; // no entiendo
            newNode->prev = last;
            last = newNode;
        }
        num_elems++; //se suma un elemento a al lista
    }

    void push_front(const int& value) {
        Node* newNode = new Node(value); /*se crea un nuevo nodo con el valor ingresado en el main,  
        next y prev se inicializan a nullptr en el constructor.*/
        if (first == nullptr) {//si el primer elemento esta vacio,
            first = last = newNode;//se establece como unico elemento el que ha ingresado
        }
        else {//si la lista no esta vacia
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        num_elems++; //se suma un elemento a al lista
    }

    void insert(unsigned int position, const int& value) {
        if (position == 0) {
            push_front(value);
        }
        else if (position >= num_elems) {
            push_back(value);
        }
        else { //no entiendo
            Node* current = first;
            unsigned int index = 0;
            while (index < position) {
                current = current->next;
                index++;
            }
            Node* newNode = new Node(value);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
            num_elems++;
        }
    }

    void erase(unsigned int position) {
        if (position >= num_elems || first == nullptr) { //si la psoicion que quiere no es posible muestra el mensaje
            cerr << "Invalid position or list is empty." << endl;
            return;
        }

        Node* current = first; // qu eno entiendoe l current 

        
        if (position == 0) {
            first = first->next;
            if (first != nullptr) {
                first->prev = nullptr;
            }
            else {
                last = nullptr; 
            }
            delete current;
        }
        
        else {
            unsigned int index = 0;
            while (index < position) {
                current = current->next;
                index++;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                last = current->prev; 
            }

            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            delete current;
        }

        num_elems--;
    }

    void print() const {
        Node* current = first;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    List myList;

    cout << "Push back 1, 2, 3:" << endl;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.print(); // Salida: 1 2 3

    cout << "Push front 0:" << endl;
    myList.push_front(0);
    myList.print(); // Salida: 0 1 2 3

    cout << "Insert 99 at position 2:" << endl;
    myList.insert(2, 99);
    myList.print(); // Salida: 0 1 99 2 3

    cout << "Insert 88 at position 0:" << endl;
    myList.insert(0, 88);
    myList.print(); // Salida: 88 0 1 99 2 3

    cout << "Insert 77 at position 6:" << endl;
    myList.insert(6, 77);
    myList.print(); // Salida: 88 0 1 99 2 3 77

    cout << "Erase position 0:" << endl;
    myList.erase(0);
    myList.print(); // Salida: 0 1 99 2 3 77

    cout << "Erase position 2:" << endl;
    myList.erase(2);
    myList.print(); // Salida: 0 1 2 3 77

    cout << "Erase position 4:" << endl;
    myList.erase(4);
    myList.print(); // Salida: 0 1 2 3

}

