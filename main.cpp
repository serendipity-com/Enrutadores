#include <iostream>
#include <iterator>
#include "router.h"

using namespace std;

int main()
{
    Router router;
    router.setID("A");
    router.agregarRouter("A",0);
    router.agregarRouter("B",1);
    router.agregarRouter("C",2);

    router.configurarTopologia("B",3);
    for (auto posicion : router.getTopologia())
    {
        cout << posicion.first << ':'  << posicion.second  << endl ;
    }

    cout << "" << endl;
    return 0;
}
