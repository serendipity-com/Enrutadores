#include <iostream>
#include <iterator>
#include <menu.h>

using namespace std;

int main()
{
    Menu *menu = new Menu();
    menu->opcionesRed();
    delete menu;
    return 0;

}
