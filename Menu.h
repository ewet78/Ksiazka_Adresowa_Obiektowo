#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "AdresatMenedzer.h"
#include "Ksiazka_Adresowa.h"


using namespace std;

class Menu
{
public:
    char wybor;
    void menuGlowne();
    void menuUzytkownika();
    AdresatMenedzer adresatMenedzer;
    KsiazkaAdresowa ksiazkaAdresowa;

    Menu();
};



#endif
