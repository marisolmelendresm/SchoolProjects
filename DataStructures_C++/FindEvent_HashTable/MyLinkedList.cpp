#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "MyLinkedList.h"

using namespace std;

// Constructor
// Entrada: NA
// Salida: NA
// Complejidad: O(1)
MyLinkedList::MyLinkedList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

// Destructor
// Entrada: NA
// Salida: NA
// Complejidad: O(n)
MyLinkedList::~MyLinkedList() {
    while (!this->isEmpty())
        this->removeLast();
}

// Getter tamaño de la lista
// Entrada: NA
// Salida: int size
// Complejidad: O(1)
int MyLinkedList::length() {
    return this->size;
}

// Getter lista vacia
// Entrada: NA
// Salida: bool vacía
// Complejidad: O(1)
bool MyLinkedList::isEmpty() {
    return this->length() == 0;
}

// Getter valor en cierta posición
// Entrada: string key
// Salida: int valor
// Complejidad: O(n)
void MyLinkedList::getAt(string key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            cout << "Ip: " << current->ip << " | Accesos: " << current->accesos << " | Fechas: " << endl;
            for (int j = 0; j < current->fechas.size(); j++) {
                string date = current->fechas[j].substr(2);
                cout << date << endl;
            }
            cout << endl;
            return;
        }
        current = current->next;
    }
    throw invalid_argument("No se puede obtener la clave " + key + ".");
}

// Remover valor en cierta posición
// Entrada: string key
// Salida: NA
// Complejidad: O(n)
void MyLinkedList::removeAt(string key) {
    MyNodoLL *current = this->head;
    MyNodoLL *prev = nullptr;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            prev == nullptr ?
                this->head = current->next :
                prev->next = current->next;
            delete current;
            this->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    throw invalid_argument("No se puede remover la clave " + key + ".");
}

// Getter valor en cierta posición
// Entrada: int posición
// Salida: MyNodoLL* current
// Complejidad: O(n)
MyNodoLL* MyLinkedList::getAt(int pos) {
    if (pos >= 0 && pos < this->size) {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos; i++)
            current = current->next;
        return current;
    }
    throw invalid_argument("No se puede insertar la posicion " + to_string(pos) + " en una lista de tamano " + to_string(this->size) + ".");
}

// Insertar valor en 1ra posición
// Entrada: int valor
// Salida: NA
// Complejidad: O(1)
void MyLinkedList::insertFirst(string key, string ip, string fecha) {
    
    this->head = new MyNodoLL(key, ip, fecha, this -> head);
    if (this->tail == nullptr)
        this->tail = this->head;
    this->size++; 
}

// Insertar valor en 1ra posición
// Entrada: key, ip, accesos, fechas
// Salida: NA
// Complejidad: O(1)
void MyLinkedList::insertFirst(string key, string ip, int accesos, vector<string> fechas) {
    this->head = new MyNodoLL(key, ip, fechas[0], this->head);
    this->head->fechas = fechas;
    this->head->accesos = accesos;
    if (this->tail == nullptr)
        this->tail = this->head;
    this->size++; 
}

// Insrerta el valor dentro de la lista
// Entrada: key, ip, fecha
// Salida: NA
// Complejidad: O(n)
void MyLinkedList::insert(string key, string ip, string fecha) {
    if (this->head == nullptr) {
        insertFirst(key, ip, fecha);
        return;
    }
    MyNodoLL *current = this->head;
    while (current->next != nullptr) {
        if (current -> key == key){
            current -> fechas.push_back(fecha);
            current -> accesos++;
            sort(current->fechas.begin(), current->fechas.end());
            return;
        }
        current = current -> next;
    }
    insertFirst(key, ip, fecha);
}

// Remover valor en 1ra posición
// Entrada: NA
// Salida: NA
// Complejidad: O(1)
void MyLinkedList::removeFirst() {
    if (this->head != nullptr) {
        if(this->size > 0) {
            MyNodoLL *tmp = this->head;
            this->head = this->head->next;
            this->size--;
            if (this->size == 0)
                this->tail == nullptr;
            delete tmp;
        } else
            throw invalid_argument("No se puede borrar el inicio de una lista vacia.");
    }
}

// Remover valor en ultima posición
// Entrada: NA
// Salida: NA
// Complejidad: O(n)
void MyLinkedList::removeLast() {
    if (this->head>0) {
        MyNodoLL *current = this->head;
        for (int i = 0; i < this->size-2; i++)
            current = current->next;
        this->tail = current;
        current = this->tail->next;
        this->tail->next = nullptr;
        this->size--;
        if (this->size == 0)
            this->tail == nullptr;
        delete current;
    }
}

// Remover valor en cierta posición
// Entrada: int posicion
// Salida: NA
// Complejidad: O(n)
void MyLinkedList::removeAt(int pos) {
    if (pos >= 0 && pos < this->size) {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++)
            current = current->next;
        MyNodoLL *tmp = current->next;
        current->next = current->next->next;
        delete tmp;
        this->size--;
    } else
        throw invalid_argument("No se puede remver la posicion " + to_string(pos) + " en una lista de tamano " + to_string(this->size) + ".");
}
