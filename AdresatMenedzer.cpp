#include "AdresatMenedzer.h"

int AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    adresat.id = ++idOstatniegoAdresata;
    adresat.idUzytkownika = idZalogowanegoUzytkownika;
    metodyPomocnicze.wczytajLinie();

    cout << "Podaj imie: ";
    adresat.imie = metodyPomocnicze.wczytajLinie();
    adresat.imie = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    adresat.nazwisko = metodyPomocnicze.wczytajLinie();
    adresat.nazwisko = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.nrTelefonu = metodyPomocnicze.wczytajLinie();

    cout << "Podaj email: ";
    adresat.email = metodyPomocnicze.wczytajLinie();

    cout << "Podaj adres: ";
    adresat.adres = metodyPomocnicze.wczytajLinie();

    return adresat;
}

void AdresatMenedzer::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

int AdresatMenedzer::pobierzZPlikuIdOstatniegoAdresata()
{
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(plikZAdresatami.nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.id << endl;
    cout << "Imie:               " << adresat.imie << endl;
    cout << "Nazwisko:           " << adresat.nazwisko << endl;
    cout << "Numer telefonu:     " << adresat.nrTelefonu << endl;
    cout << "Email:              " << adresat.email << endl;
    cout << "Adres:              " << adresat.adres << endl;
}
