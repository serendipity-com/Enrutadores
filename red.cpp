#include "red.h"
#include "router.h"

Red::Red(string fileName)
{
    char *linksA = new char[7];
    ifstream topologiaRouter(fileName);
    if(topologiaRouter.is_open())
    {
        int cont  = 0;
        string node = "", nodeF = "";
        map <string, string> topologiaNodo;
        map <string, map <string, string>> red;
        setRed(red);
        while(!topologiaRouter.eof())
        {
           linksA[cont] = topologiaRouter.get();
           if(linksA[cont] == '\n')
           {
               node += linksA[0];
               char delimitador[] = "-=\n";
               string linksS = "";
               //solo en la primer llamada a strtok pasamos cadena en primer argumento
               char *subStr = strtok(linksA, delimitador);
               if(subStr != NULL)
               { //NULL es para saber hasta donde va a segmentar
                   while(subStr != NULL)
                   {
                       // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
                       linksS += subStr;
                       //En las demás llamadas a strtok le pasamos como primer arg a NULL
                       subStr = strtok(NULL, delimitador);
                   }
               }
               Router topologia(topologiaNodo);
               topologia.agregarRouter(linksS[1], linksS[2]);
               delete [] linksA;
               char *linksA = new char[7];
               cont = 0;
               linksA[cont] = topologiaRouter.get();
               nodeF += linksA[cont];
               if(node != nodeF)
               {
                   agregarTopologia(node, topologia.getTopologia());
               }
           }
           else
           {
               cont++;
           }
        }
        topologiaRouter.close();
        delete [] linksA;
    }
    else cout << "Fichero no existe o faltan permisos para abrirlo" << endl;
}

void Red::setRed(map <string , map <string, string>> red)
{
    this ->red = red;
}

map<string, map<string, string>> Red::getRed()
{
    return red;
}

void Red::agregarTopologia(string clave, map <string, string> valor)
{
    auto valorBuscar = red.find(clave);

    if (valorBuscar == red.end())
    {
        red.insert({clave, valor});
    }
    else
    {
        cout << endl << "********************************************************" << endl;
        cout << "La topologia para el router de ID <" << clave <<"> ya existe en esta red" << endl;
        cout << "********************************************************" << endl<< endl;
    }
}

