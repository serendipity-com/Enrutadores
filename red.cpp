#include "red.h"

Red::Red()
{
    ifstream topologiaRouter("red.txt");
    string linea;
    if(topologiaRouter.is_open())
    {
        while(!topologiaRouter.eof())
        {
           getline(topologiaRouter, linea);
           if(linea != "")
            agregarTopologia(linea[0], linea[1], linea[2] - '0');
        }
        topologiaRouter.close();

        //Imprime la topologia de la red
        for (auto posicion : red) //topologia de cada router
        {
            //posicion.first: nodo o router
            cout << posicion.first << endl;
            //posicion.second: map <char,int> topologia (objeto de clase Router)
            for (auto posicion2 : posicion.second.getTopologia()){
                cout << posicion2.first << ":" << posicion2.second<<endl;
            }
        }
    }
    else cout << "Fichero no existe o faltan permisos para abrirlo" << endl;


}

void Red::setRed(map<char, Router> red)
{
    this ->red = red;
}

map<char, Router> Red::getRed()
{
    return red;
}

void Red::agregarTopologia(char routerA,char routerB, int valor) //Agregar enlace
{
    //comprueba si el router existe
    //valorBuscar: iterador que apunta al elemento donde se halle la clave routerA
    auto valorBuscar = red.find(routerA);
    //routerA: nodo cuya topología se agrega al map de topología

    if (valorBuscar == red.end()) //si no está
    {
        Router topologia; //es un map de los enlaces de routerA
        topologia.agregarRouter(routerB,valor); //agrega enlace con routerB
        red.insert({routerA,topologia});//routerA(que no estaba) y su enlace con routerB
    }
    else //si sí está
    {
        //se para en el map de enlaces de routerA y agrega enlace con routerB
        red[routerA].agregarRouter(routerB,valor);
    }
    auto valorBuscar2 = red.find(routerB);

    if (valorBuscar2 == red.end())
    {
        Router topologia; //map de los enlaces de routerB
        topologia.agregarRouter(routerA,valor); //agrega enlace con routerA
        red.insert({routerB,topologia});//routerB(que no estaba) y su enlace con routerA
    }
    else
    {   //se para en el map de enlaces de routerB y agrega enlace con routerA
        red[routerB].agregarRouter(routerA,valor);
    }
}

void Red::eliminarTopologia(char routerA, char routerB) //Eliminar enlace
{
    //comprueba si el router existe
    //valorBuscar: iterador que apunta al elemento donde se halle la clave routerA
    auto valorBuscar = red.find(routerA);
    //routerA: nodo cuya topología se agrega al map de topología

    if (valorBuscar != red.end()) //si está
    {
        auto valorBuscar2 = red[routerA].topologia.find(routerB);
        if (valorBuscar2 != red[routerA].topologia.end())
        {
            red[routerA].topologia.erase(routerB); //Elimina enlace si existe
        }
        else
        {
            cout << endl << "********************************************************" << endl;
            cout << "El router con el ID <" << routerB <<"> no existe en esta red " << endl;
            cout << "********************************************************" << endl << endl;
        }
    }
    else //si no está
    {
        cout << endl << "********************************************************" << endl;
        cout << "El router con el ID <" << routerA <<"> no existe en esta red " << endl;
        cout << "********************************************************" << endl << endl;
    }
    auto valorBuscar3 = red.find(routerB);

    if (valorBuscar3 != red.end())
    {
        auto valorBuscar4 = red[routerB].topologia.find(routerA);
        if (valorBuscar4 != red[routerB].topologia.end())
        {
            red[routerB].topologia.erase(routerA); //Elimina enlace si existe
        }
        else
        {
            cout << endl << "********************************************************" << endl;
            cout << "El router con el ID <" << routerA <<"> no existe en esta red " << endl;
            cout << "********************************************************" << endl << endl;
        }
    }
    else
    {
        cout << endl << "********************************************************" << endl;
        cout << "El router con el ID <" << routerB <<"> no existe en esta red " << endl;
        cout << "********************************************************" << endl << endl;
    }
}

void Red::configurarTopologia(char routerA, char routerB, int costo) //Cambiar costo de enlace
{
    //comprueba si el router existe
    //valorBuscar: iterador que apunta al elemento donde se halle la clave routerA
    auto valorBuscar = red.find(routerA);
    //routerA: nodo cuya topología se agrega al map de topología
    if (valorBuscar != red.end()) //si está
    {
        auto valorBuscar = red[routerA].topologia.find(routerB);
        if (valorBuscar != red[routerA].topologia.end())
        {
            red[routerA].topologia[routerB] = costo;
        }
        else
        {
            cout << endl << "********************************************************" << endl;
            cout << "El router con el ID <" << routerB <<"> no existe en esta red " << endl;
            cout << "********************************************************" << endl << endl;
        }
    }
    else //si no está
    {
        cout << endl << "********************************************************" << endl;
        cout << "El router con el ID <" << routerA <<"> no existe en esta red " << endl;
        cout << "********************************************************" << endl << endl;
    }
    auto valorBuscar2 = red.find(routerB);

    if (valorBuscar2 != red.end())
    {
        auto valorBuscar = red[routerB].topologia.find(routerA);
        if (valorBuscar != red[routerB].topologia.end())
        {
            red[routerB].topologia[routerA] = costo;
        }
        else
        {
            cout << endl << "********************************************************" << endl;
            cout << "El router con el ID <" << routerA <<"> no existe en esta red " << endl;
            cout << "********************************************************" << endl << endl;
        }
    }
    else
    {
        cout << endl << "********************************************************" << endl;
        cout << "El router con el ID <" << routerB <<"> no existe en esta red " << endl;
        cout << "********************************************************" << endl << endl;
    }
}


void Red::encontrarMejorRuta(char origen, char destino, char anterior)
{
    map <char, int> topologia = red[origen].getTopologia();

    char nombre;
    int valor = 10;

    if (origen == destino)
    {
        return;
    }
    else
    {
        cout << origen;
        for (auto posicion : topologia)
        {
            if(posicion.second < valor && anterior != posicion.first)
            {
                nombre = posicion.first;
                valor = posicion.second;
            }
        }
        cout << nombre<< endl;
        encontrarMejorRuta(nombre, destino, origen);
    }
}

