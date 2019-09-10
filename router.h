#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <map>

using namespace std;

class Router
{
public:
    Router();


private:
    string ID;
    map <string, int> topologia;
};

#endif // ROUTER_H
