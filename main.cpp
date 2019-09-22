#include <iostream>
#include <iterator>
#include "router.h"
#include "red.h"



using namespace std;

int main()
{
    Red *redRouters = new Red();
    redRouters->encontrarMejorRuta('A','C','A');
    delete  redRouters;
    return 0;
}
