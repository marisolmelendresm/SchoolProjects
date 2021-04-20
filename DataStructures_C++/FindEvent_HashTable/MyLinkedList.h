#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
#include <vector>

using namespace std;

struct MyNodoLL {
    string key;
    string ip;
    int accesos;
    vector<string> fechas;
    MyNodoLL *next;

    MyNodoLL(string key, string ip, string fechas, MyNodoLL* next) {
        this->key = key;
        this->ip = ip;
        this->fechas.push_back(fechas);
        this->accesos = 1;
        this->next = next;
    }
    MyNodoLL(string key, string ip, string fechas): MyNodoLL(key, ip, fechas, nullptr){}
};

class MyLinkedList {
    private:
        MyNodoLL *head;
        MyNodoLL *tail; 
        int size;
        
    public:
        MyLinkedList();
        ~MyLinkedList();
        int length();
        bool isEmpty();
        MyNodoLL* getAt(int pos);
        void getAt(string key);

        void insertFirst(string key, string ip, string fecha);
        void insertFirst(string key, string ip, int accesos, vector<string> fechas);
        void insert(string key, string ip, string fecha);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        void removeAt(string key);

        friend ostream &operator<<(ostream &os, const MyLinkedList &ll) {
            if (ll.size > 0) {
                MyNodoLL *current = ll.head;
                os << "[";
                for (int i = 0; i < ll.size - 1; i++) {
                    os << "Ip: " << current->ip << " | Accesos: " << current->accesos << " | Fechas: ";
                    for (int j=0; j < current->fechas.size(); j++)
                        os << current->fechas[j] << ", ";
                    current = current->next;
                }
                os << "]" << endl;
                return os;
            }
            os << "[]\n";
            return os;
        }
};

#endif