#ifndef RED_H
#define RED_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "router.h"
#include <string.h> //para usar strtok
#include <fstream>

class Red
{
public:
    Red(string fileName);
    void setRed(map <string , map <string, string>> red);
    map <string, map <string, string>> getRed();
    void agregarTopologia(string clave, map <string, string> valor);
private:
    map <string , map <string, string>> red;


};

#endif // RED_H
