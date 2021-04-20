#ifndef EVENTOS_H
#define EVENTOS_H

#include <string>

using namespace std;

class Eventos
{
    private:
        string mes;
        int dia;
        string hora;
        long id;
        string ip;
        string error;

    public:
        Eventos(string mes, int dia, string hora, string ip, string error, long id);
        string getMes() { return this->mes; }
        string getHora() { return this->hora; }
        int getDia() { return this->dia; }
        int getId() { return this->id; }
        string getIp() { return this->ip; }
        string getError() { return this->error; }
};

Eventos::Eventos(string mes, int dia, string hora, string ip, string error, long id)
{
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ip = ip;
    this->error = error;
    this->id = id;
};

#endif