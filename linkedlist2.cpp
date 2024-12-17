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
    List() {
        first = nullptr;
        last = nullptr;
        num_elems = 0;
    }

    ~List() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

    void push_back(const int& value) {
        Node* newNode = new Node(value);
        if (last == nullptr) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        num_elems++;
    }

    void push_front(const int& value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        num_elems++;
    }

    void insert(unsigned int position, const int& value) {
        if (position == 0) {
            push_front(value);
        }
        else if (position >= num_elems) {
            push_back(value);
        }
        else {
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
        if (position >= num_elems || first == nullptr) {
            cerr << "Invalid position or list is empty." << endl;
            return;
        }

        Node* current = first;

        
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

