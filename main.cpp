#include <iostream>

#include "Ksiazka_Adresowa.h"

using namespace std;

int main()
{

KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

int idZalogowanegoUzytkownika = 0;
int idOstatniegoAdresata = 0;
char wybor;

while (true)
{
if (idZalogowanegoUzytkownika == 0)
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
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                idOstatniegoAdresata = ksiazkaAdresowa.podajIdOstatniegoAdresata();
                ksiazkaAdresowa.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
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
if (idZalogowanegoUzytkownika != 0)
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
                ksiazkaAdresowa.dodawanieAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlAdresatow();
                break;

            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;

            case '8':
                idZalogowanegoUzytkownika = 0;
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
}

}

//ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    return 0;
}
