/*
    Eduardo Venegas Hernández    A01638188
    Marisol Melendres Muñoz      A01632636
    Carlos Moisés Chávez Jimenez A01637322
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
#include "MyHashTable.h"

using namespace std;

int main() {

    // Diccionario para convertr el mes en un dato numerico
    map<string, string> meses;

    meses[string("Jan")] = "01";
    meses[string("Feb")] = "02";
    meses[string("Mar")] = "03";
    meses[string("Apr")] = "04";
    meses[string("May")] = "05";
    meses[string("Jun")] = "06";
    meses[string("Jul")] = "07";
    meses[string("Aug")] = "08";
    meses[string("Sep")] = "09";
    meses[string("Oct")] = "10";
    meses[string("Nov")] = "11";
    meses[string("Dec")] = "12";

    // Crea Hashtable
    MyHashTable ht;

    // Lee el archivo
    ifstream file("bitacora2.txt");
    string str = "";

    // Variables del nodo
    string ipAnterior = "";

    // Lee linea por linea
    while (getline(file, str)) {
        // vector que será utilizado para guardar la linea
        vector<string> result;

        // Separacion de las palabras
        istringstream iss(str);
        for (string s; iss >> str;)
            result.push_back(str);

        // Guarda los datos temporalmente
        string ip = result[3];
        stringstream ipStr(ip);

        string fecha = meses[result[0]] + result[0] + " " + result[1] + " " + result[2];

        // Vector para separar ip y puerto
        vector<string> ipVector;
        while (getline(ipStr, str, ':'))
            ipVector.push_back(str);

        ip = ipVector[0];

        // Inserta el IP en la linked list
        ht.put(ip, ip, fecha);
    }

    
    int salir = 1;

    do{ // Ciclo de menu
        string ipUser; 
        cout << "Ingresa la Ip inicial a buscar (aaa.bbb.ccc.ddd): ";
        cin >> ipUser;
        //Manda al metodo para mostrar datos e imprimirlos en un archivo.
        ht.get(ipUser);
        cout << endl << "Si desea salir del programa ingrese 0, si desea realizar otra busqueda de IP ingrese cualquier otro numero: ";
        cin >> salir;
    }while(salir!=0);

    return 0;
}