#include "menu.h"

Menu::Menu()
{
}

void Menu::opcionesRed()
{
   Red *redRouters = new Red();
   bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
   while(!flag1)
   {
       try
       {
           char option;
           cout << "*****************************************************************************" << endl;
           cout << "Ingrese el número de la opción:" << endl;
           cout << "Opción 1: Agregar enlaces a la topología de un router." << endl;
           cout << "Opción 2: Eliminar enlaces de la topología de un router." << endl;
           cout << "Opción 3: Configurar costo de enlaces de la topología de un router." << endl;
           cout << "*****************************************************************************" << endl;
           cin >> option;
           if(sizeof(option) != 1)
               throw option;
           else if(option == '1')
           {
               while(!flag2)
               {
                   try
                   {
                       char nodoA, nodoB; int costo;
                       cout << "*****************************************************************************" << endl;
                       cout << "Ingrese el router al cual quiere agregar enlace" << endl;
                       cin >> nodoA;
                       cout << "Ingrese el router de enlace" << endl;
                       cin >> nodoB;
                       cout << "Ingrese el costo de enlace" << endl;
                       cin >> costo;
                       cout << "*****************************************************************************" << endl;
                       if((sizeof(nodoA) != 1) || (sizeof(nodoB) != 1) || (sizeof(costo) != 4))
                       {    throw nodoA; throw nodoB; throw costo; }
                       else
                       {
                           flag1 = true;
                           flag2 = true;
                           redRouters->agregarTopologia(nodoA, nodoB, costo);
                           //Imprime la topologia de la red
                           for (auto posicion : redRouters->red) //topologia de cada router
                           {
                               //posicion.first: nodo o router
                               cout << posicion.first << endl;
                               //posicion.second: map <char,int> topologia (objeto de clase Router)
                               for (auto posicion2 : posicion.second.getTopologia()){
                                   cout << posicion2.first << ":" << posicion2.second<<endl;
                               }
                           }
                       }

                   }
                   catch(...)
                   {
                       cerr << "Ocurrió un error inesperado" << endl;
                   }
               }
           }
           else if(option == '2')
           {
               while(!flag3)
               {
                   try
                   {
                       char nodoA, nodoB;
                       cout << "*****************************************************************************" << endl;
                       cout << "Ingrese el router del cual quiere eliminar un enlace" << endl;
                       cin >> nodoA;
                       cout << "Ingrese el router a eliminar" << endl;
                       cin >> nodoB;
                       cout << "*****************************************************************************" << endl;
                       if((sizeof(nodoA) != 1) || (sizeof(nodoB) != 1))
                       {   throw nodoA; throw nodoB; }
                       else
                       {
                           flag1 = true;
                           flag3 = true;
                           redRouters->eliminarTopologia(nodoA, nodoB);
                           //Imprime la topologia de la red
                           for (auto posicion : redRouters->red) //topologia de cada router
                           {
                               //posicion.first: nodo o router
                               cout << posicion.first << endl;
                               //posicion.second: map <char,int> topologia (objeto de clase Router)
                               for (auto posicion2 : posicion.second.getTopologia()){
                                   cout << posicion2.first << ":" << posicion2.second<<endl;
                               }
                           }

                       }
                   }
                   catch(...)
                   {
                       cerr << "Ocurrió un error inesperado" << endl;
                   }
               }
           }
           else if(option == '3')
           {
               while(!flag4)
               {
                   try
                   {
                       char nodoA, nodoB; int costo;
                       cout << "*****************************************************************************" << endl;
                       cout << "Ingrese el router al cual quiere cambiar costo de un enlace" << endl;
                       cin >> nodoA;
                       cout << "Ingrese el router cuyo costo de enlace con el anterior se cambiará" << endl;
                       cin >> nodoB;
                       cout << "Ingrese el nuevo costo de enlace" << endl;
                       cin >> costo;
                       cout << "*****************************************************************************" << endl;
                       if((sizeof(nodoA) != 1) || (sizeof(nodoB) != 1) || (sizeof(costo) != 4))
                       {    throw nodoA; throw nodoB; throw costo;}
                       else
                       {
                           flag1 = true;
                           flag4 = true;
                           redRouters->configurarTopologia(nodoA, nodoB, costo);
                           //Imprime la topologia de la red
                           for (auto posicion : redRouters->red) //topologia de cada router
                           {
                               //posicion.first: nodo o router
                               cout << posicion.first << endl;
                               //posicion.second: map <char,int> topologia (objeto de clase Router)
                               for (auto posicion2 : posicion.second.getTopologia()){
                                   cout << posicion2.first << ":" << posicion2.second<<endl;
                               }
                           }
                       }

                   }
                   catch(...)
                   {
                       cerr << "Ocurrió un error inesperado" << endl;
                   }
               }
           }
       }
       catch(...)
       {
           cerr << "Ocurrió un error inesperado" << endl;
       }

   }
   delete redRouters;

}


