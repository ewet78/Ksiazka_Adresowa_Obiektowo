#ifndef KSIAZKA_ADRESOWA_H
#define KSIAZKA_ADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    PlikZAdresatami plikZAdresatami;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), plikZAdresatami(nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami)
    {
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void dodawanieAdresata();
    int podajIdOstatniegoAdresata();
    void wyswietlAdresatow();
    bool czyUzytkownikJestZalogowany();
    void wyszukiwaniePoImieniu();
    void wyszukiwaniePoNazwisku();
    void usunAdresata();
    void edytujAdresata();


};


#endif
