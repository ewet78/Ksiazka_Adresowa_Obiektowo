
#include "Ksiazka_Adresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wczytajAdresatowZPliku(int idZalogowanegoUzytownika)
{
    adresatMenedzer.wczytajAdresatowZPliku(idZalogowanegoUzytownika);
}

void KsiazkaAdresowa::dodawanieAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}
int KsiazkaAdresowa::podajIdOstatniegoAdresata()
{
    adresatMenedzer.pobierzZPlikuIdOstatniegoAdresata();
}

void KsiazkaAdresowa::wyswietlAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}
