#include "router.h"

Router::Router()
{

}

void Router::setTopologia(map<char,int> topologia)
{
    this ->topologia = topologia;
}

void Router::setID(char ID)
{
    this -> ID = ID;
}

char Router::getID()
{
    return ID;
}

map<char, int> Router::getTopologia()
{
    return topologia;
}

void Router::agregarRouter(char clave, int valor)
{
    //comprueba si el router existe
    auto valorBuscar = topologia.find(clave); //map de enlaces de routerA

    if (valorBuscar == topologia.end()) //si no está en el map
    {
        topologia.insert({clave,valor});
    }
    else //si sí está
    {
        cout << endl << "********************************************************" << endl;
        cout << "El router con el ID <" << clave <<"> ya existe en esta red" << endl;
        cout << "********************************************************" << endl<< endl;
    }
}

