#include <iostream>
#include <functional>
#include <cmath>
#include "MyHashTable.h"

using namespace std;

// Constructor
// Entradas: NA
// Salidas: NA
// Complejidad: O(1)
MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 5;
    this->tabla = new MyLinkedList[this->sizeA];
}

// Destructor
// Entradas: NA
// Salidas: NA
// Complejidad: O(n*v) n -> elementos en la lista de nodos y v -> elementos en la lista
MyHashTable::~MyHashTable() {
    for (int i = 0; i < this->sizeA; i++)
        this->tabla[i].~MyLinkedList();
}

// isEmpty
// Entradas: NA
// Salidas: bool isEmpty
// Complejidad: O(1)
bool MyHashTable::isEmpty() {
    return this->size == 0;
}

// Get Position
// Entradas: string Key
// Salidas: int position
// Complejidad: O(1)
int MyHashTable::getPos(string key) {
    size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % this->sizeA;
}

// Put
// Entradas: string Key, int value
// Salidas: NA
// Complejidad: O(1)
void MyHashTable::put(string key, string ip, string fecha) {
    float loadFactor = (float) this->size / this->sizeA;
    if (loadFactor > 0.75)
        this->rehashing();
    int pos = this->getPos(key);
    this->tabla[pos].insert(key, ip, fecha);
    this->size++;
}

// Rehashing
// Entradas: NA
// Salidas: NA
// Complejidad: O(n*v) n -> elementos en la lista de nodos y v -> elementos en la lista
void MyHashTable::rehashing() {
    int sizeAnt = this->sizeA;
    this->sizeA = this->sizeA * 2 + 1;
    MyLinkedList *tmp = new MyLinkedList[this->sizeA];

    for (int i = 0; i < sizeAnt; i++) {
        while (!this->tabla[i].isEmpty()) {
            MyNodoLL *nodo = this->tabla[i].getAt(0);
            int pos = this->getPos(nodo->key);
            tmp[pos].insertFirst(nodo->key, nodo->ip, nodo->accesos, nodo->fechas);
            this->tabla[i].removeFirst();
        }
    }
    this->tabla = tmp;
}

// Get
// Entradas: string Key
// Salidas: int valor
// Complejidad: O(n) n -> elementos en la lista de nodos
void MyHashTable::get(string key) {
    int pos = this->getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    lista->getAt(key);
}

// Remove
// Entradas: string Key
// Salidas: NA
// Complejidad: O(n) n -> elementos en la lista de nodos
void MyHashTable::remove(string key) {
    int pos = this->getPos(key);
    MyLinkedList *lista = &this->tabla[pos];
    lista->removeAt(key);
}