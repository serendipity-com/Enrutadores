#include "router.h"

Router::Router()
{

}

void Router::setTopologia(map <string,int> topologia)
{
    this ->topologia = topologia;
}

void Router::setID(string ID)
{
    this -> ID = ID;
}

string Router::getID()
{
    return ID;
}

map<string, int> Router::getTopologia()
{
    return topologia;
}

void Router::agregarRouter(string clave, int valor)
{
    //comprueba si el router existe
    auto valorBuscar = topologia.find(clave);

    if (valorBuscar == topologia.end())
    {
        topologia.insert({clave,valor});
    }
    else
    {
        cout << "El router con el ID " << clave <<" ya existe en esta red" << endl;
    }
}

void Router::eliminarRouter(string clave)
{
    //comprueba si el router a elimar existe
    auto valorBuscar = topologia.find(clave);

    if (valorBuscar != topologia.end())
    {
        topologia.erase(clave);
    }
    else
    {
        cout << "El router con el ID " << clave <<" no existe en esta red " << endl;
    }
}

void Router::configurarTopologia(string clave, int valor)
{
    topologia[clave] = valor;
    topologia[ID] = valor;
}
