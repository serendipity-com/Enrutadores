#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

class Router
{
public:
    Router();//constructor por defecto (sin parámetros), sirve como un tipo de dato
    void setTopologia(map <char,int> topologia);
    void setID(char ID);

    char getID();
    map <char, int> getTopologia();

    void agregarRouter(char clave, int valor);
    void eliminarRouter(char clave);
    void configurarTopologia(char clave, int valor);


private:
    char ID;
    map <char,int> topologia;
};

#endif // ROUTER_H
