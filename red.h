#ifndef RED_H
#define RED_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "router.h"
#include <fstream>

using namespace std;

class Red
{
public:
    Red(); //constructor por defecto

    void setRed(map <char,Router> red);
    map <char,Router> getRed();
    void agregarTopologia(char routerA, char routerB, int costo);

    void encontrarMejorRuta(char origen, char destino, char anterior);
private:
    map <char,Router> red;


};

#endif // RED_H
