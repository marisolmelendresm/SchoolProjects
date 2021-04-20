/*
Equipo 2:
Marisol Melendres Muñoz         A01632636
Eduardo Venegas Hernandez       A01638188
Carlos Moises Chavez Jimenez    A01637322

Grupo 13
13/09/2020
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

#include "eventos.h"

using namespace std;

// Funcion que hace el intercambio de valores en el vector
// Entradas: a y b - objetos a intercambiar
// Salida: NA
template <class T>
void swaping(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

//Funcion auxiliar que parte el vector para regresarselo a la funcion principal del ordenamiento.
// Entradas: Vector - objetos del texto, lit - valor minimo, max = valor maximo
// Salida: Valor macimo
int particion ( vector<Eventos> &arr, int lit, int max)
{
    int pivot = arr[max].getId(); // pivote
    int i = (lit - 1); // indice del elemento m�s peque�o

    for (int j = lit; j <= max - 1; j++)
    {
        // Si el elemento actual es m�s peque�o que el pivote
        if (arr[j].getId() < pivot)
        {
            i++; // Incrementar el index del elemento m�s peque�o.
            swaping(arr[i],arr[j]);
        }
    }
    swaping(arr[i+1],arr[max]);
    return (i + 1);
}

//Funci�n principal de QuickSort que valida que el valor final de la sublista sea mayor al primero de esa sublista, si es asi
// divide el arreglo con una particion que se hace con la funcion auxiliar, y sigue comparando y dividiendo.
// Entradas: Vector - objetos del texto, lit - valor minimo, max = valor maximo
// Salida: NA
void ordenQuick(vector<Eventos> &arr, int lit, int max){
	if (lit < max)
    {
        int res = particion( arr, lit, max);
        ordenQuick( arr, lit, res - 1 );
        ordenQuick( arr, res + 1, max );
    }
}
//Complejidad O(n*log n)

int main()
{
    // Crea vector donde se guardarán cada uno de los objetos
    vector<Eventos> evento;

    // Lee el archivo
    ifstream file("bitacora.txt");
    // Archivo a escribir
    ofstream filex("bitacoraOrdenada.txt");
    string str = "";
    int dia = 0;
    string mes = "";
    int diaf = 0;
    string mesf = "";
    int choise = 0;
    bool flag = false;

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



    // Lee linea por linea
    while (getline(file, str))
    {
        string hora, ip, error;
        long id;

        // vector que será utilizado para guardar la linea
        vector<string> result;
        // Separacion de las palabras
        istringstream iss(str);
        for (string s; iss >> str;)
            result.push_back(str);

        // Guarda los datos temporalmente
        mes = result[0];
        dia = stoi(result[1]);
        hora = result[2];
        ip = result[3];

        // Concatena el error
        for (int i = 4; i < result.size()-1; i++)
            error = "" +error + result[i];

        // Guarda el valor numerico del mes
        string id_ = meses[mes];

        // Concatena el día
        if (dia < 10)
            id_ = id_ + "0" + to_string(dia);
        else
            id_ = id_ + to_string(dia);

        for (int i = 0; i < hora.size(); i++)
        {
            if (hora[i] != ':')
                id_ = id_ + hora[i];
        }

        id = stol(id_);

        // Crea el objeto con los datos y lo añade al vector
        Eventos eventoTemp(mes, dia, hora, ip, error, id);
        evento.push_back(eventoTemp);
    }

    ordenQuick(evento, 0, evento.size()-1); //Se manda el vector al ordenamiento QuickSort

    int mesesMax[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < evento.size(); i++){ //Recorre todo el arreglo para imprimirlo en un archivo de texto llamado: "bitacoraOrdenada.txt".
        filex << evento[i].getMes() << " " << evento[i].getDia() << " " << evento[i].getHora() << " " << evento[i].getIp() << " " << evento[i].getError() << endl;
    }

    do{ //Ciclo que hace busquedas por fecha inicial y final, termina cuando el usuario
        system("cls"); //Instruccion que limpia la pantal
        cout << "Ingrese la fecha inicial de busqueda:" << endl << endl;
        bool valMes = false;
        bool valDia = false;
        bool valMesF = false;
        bool valDiaF = false;

        // Valida el mes
        while (!valMes){
            cout << "Mes (Primeras tres letras): ";
            cin >> mes;
            for (int i = 1; i <= 12; i++){
                if (stoi(meses[mes]) == i){
                    valMes = true;
                    i = 13;
                }
                if (i == 12){
                    cout << "Mes inexistente, vuelva a intentar" << endl;
                }
            }
        }

        // Valida el día
        while (!valDia){
            cout << "Dia: ";
            cin >> dia;
            int indiceMes = stoi(meses[mes]) - 1;
            int maxDias = mesesMax[indiceMes];
            if (dia >= 1 && dia <= maxDias){
                valDia = true;
            }
            else{
                cout << mes << " no tiene dia " << dia << endl << "Vuelva a intentar" << endl;
            }
        }
        cout << endl << "Ingrese la fecha final de busqueda:" << endl << endl;

        // Valida el mes
        while (!valMesF){
            cout << "Mes (Primeras tres letras): ";
            cin >> mesf;
            for (int i = 1; i <= 12; i++){
                if (stoi(meses[mes]) == i)
                {
                    valMesF = true;
                    i = 13;
                }
                if (i == 12){
                    cout << "Mes inexistente, vuelva a intentar" << endl;
                }
            }
        }

        // Valida el día
        while (!valDiaF){
            cout << "Dia: ";
            cin >> diaf;
            int indiceMes = stoi(meses[mes]) - 1;
            int maxDias = mesesMax[indiceMes];
            if (diaf >= 1 && diaf <= maxDias){
                valDiaF = true;
            }
            else{
                cout << mesf << " no tiene dia " << diaf << endl << "Vuelva a intentar" << endl;
            }
        }

        cout << endl;

        for (int i = 0; i < evento.size(); i++) //Ciclo que recorre el arreglo para comparar la fecha inicial y final, e imprimir los valores indicados.
        {
            if(evento[i].getDia()==dia && evento[i].getMes()==mes){
                flag = true;
            }
            if(evento[i].getDia()==diaf && evento[i].getMes()==mesf){
                flag = false;
                i=evento.size(); //Termina el ciclo
            }
            if(flag){
                cout << evento[i].getMes() << " " << evento[i].getDia() << " " << evento[i].getHora() << " " << evento[i].getIp() << " " << evento[i].getError() << endl;
            }
        }

        cout << endl <<"Desea realizar otra busqueda? " << endl << "Presione 0 para terminar el programa, o presione cualquier otro numero para volver a buscar: ";
        cin >> choise;
    } while( choise != 0);
    return 0;
}
