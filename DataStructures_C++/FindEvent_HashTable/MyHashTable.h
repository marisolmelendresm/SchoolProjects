#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyLinkedList.h"

class MyHashTable {
    private:
        int size;  // N° elementos almacenados
        int sizeA; // Tamaño del arreglo 
        MyLinkedList* tabla;
        void rehashing();
        int getPos(string key);
    
    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key, string ip, string fecha);
        void get(string key);
        void remove(string key);

};

#endif