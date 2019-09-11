#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Router
{
public:
    Router();

    void setTopologia(map <string,int> topologia);
    void setID(string ID);

    string getID();
    map <string, int> getTopologia();

    void agregarRouter(string clave, int valor);
    void eliminarRouter(string clave);
    void configurarTopologia(string clave, int valor);


private:
    string ID;
    map <string, int> topologia;
};

#endif // ROUTER_H
