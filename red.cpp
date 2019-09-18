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

//        for (auto posicion : red) //topologia de cada router
//        {
//            //posicion.first: nodo o router
//            cout << posicion.first << endl;
//            //posicion.second: map <char,int> topologia (objeto de clase Router)
//            for (auto posicion2 : posicion.second.getTopologia()){
//                cout << posicion2.first << ":" << posicion2.second<<endl;
//            }
//        }
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

void Red::agregarTopologia(char routerA,char routerB, int valor)
{
    //comprueba si el router existe
    //valorBuscar: iterador que apunta al elemento donde se halle la clave routerA
    auto valorBuscar = red.find(routerA);
    //routerA: nodo cuya topología se agrega al map de topología

    if (valorBuscar == red.end()) //si no está
    {
        Router topologia; //es un map <char,int>
        //nodo de enlace(routerB) y costo de este enlace(valor)
        topologia.agregarRouter(routerB,valor);
        red.insert({routerA,topologia});//router (routerA) y su topología completa
    }
    else //si sí está
    {
        //se para en el valor (map <char,int>) asociado a la clave routerA
        red[routerA].agregarRouter(routerB,valor);
    }
    auto valorBuscar2 = red.find(routerB);

    if (valorBuscar2 == red.end())
    {
        Router topologia;
        topologia.agregarRouter(routerA,valor);
        red.insert({routerB,topologia});
    }
    else
    {
        red[routerB].agregarRouter(routerA,valor);
    }
}

