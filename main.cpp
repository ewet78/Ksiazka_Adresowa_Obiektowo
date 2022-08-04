#include <iostream>

#include "Ksiazka_Adresowa.h"

using namespace std;

int main()
{

KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
UzytkownikMenedzer menu("Uzytkownicy");

ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

char wybor;

while (true)
{
if (menu.pobierzIdZalogowanegoUzytkownika() == 0)
        {
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
if (menu.pobierzIdZalogowanegoUzytkownika() > 0)
    {
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;

    switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodawanieAdresata();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlAdresatow();
                break;

            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;

            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
}

}


    return 0;
}
