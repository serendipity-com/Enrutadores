#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <string.h> //para usar strtok
#include <fstream>

using namespace std;

class Router
{
public:
    Router(map<string, string> topologia);
    void setTopologia(map <string,string> topologia);
    void setID(string ID);

    string getID();
    map <string, string> getTopologia();

    void agregarRouter(string clave, string valor);
    void eliminarRouter(string clave);
    void configurarTopologia(string clave, string valor);


private:
    string ID;
    map <string, string> topologia;
};

#endif // ROUTER_H
