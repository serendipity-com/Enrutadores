#include "red.h"

Red::Red()
{
    char link[45] = {'\0'};
    ifstream topologiaRouter("red.txt");
    if(topologiaRouter.is_open())
    {
        int cont = 0;
        while(!topologiaRouter.eof())
        {
           link[cont] = topologiaRouter.get();
           cont++;
        }
        topologiaRouter.close();
        char delimitador[] = "-=";
        string links = "";
        //solo en la primer llamada a strtok pasamos cadena en primer argumento
        char *subStr = strtok(link, delimitador);
        if(subStr != NULL)
        { //NULL es para saber hasta donde va a segmentar
            while(subStr != NULL)
            {
                // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
                links += subStr;
                //En las demás llamadas a strtok le pasamos como primer arg a NULL
                subStr = strtok(NULL, delimitador);
            }
        }
        cout << links << endl;

    }
    else cout << "Fichero no existe o faltan permisos para abrirlo" << endl;
}
