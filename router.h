#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

struct Router
{
    Router();//constructor por defecto (sin parámetros), sirve como un tipo de dato
    void setTopologia(map <char,int> topologia);
    void setID(char ID);
    char getID();
    map <char, int> getTopologia();
    void agregarRouter(char clave, int valor);
    char ID;
    map <char,int> topologia;
};

#endif // ROUTER_H
