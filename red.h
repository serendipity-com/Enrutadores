#ifndef RED_H
#define RED_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "router.h"
#include <fstream>

using namespace std;

struct Red
{
    Red(); //constructor por defecto
    void setRed(map <char,Router> red);
    map <char,Router> getRed();
    void agregarTopologia(char routerA, char routerB, int costo);
    void eliminarTopologia(char routerA, char routerB);
    void configurarTopologia(char routerA, char routerB, int costo);
    void encontrarMejorRuta(char origen, char destino, char anterior);
    map <char,Router> red;
};

#endif // RED_H
