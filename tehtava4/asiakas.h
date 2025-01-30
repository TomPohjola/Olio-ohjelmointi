#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"

using namespace std;

class Asiakas
{
public:

    Asiakas(string nimi, double luottoRaja);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto (double siirto, Asiakas &kohdeasiakas);

private:

    string nimi;
    Pankkitili kayttotili;  //tässä noiden muuttujien tyypit on pankkitili ja luottotili -luokat.
    Luottotili luottotili;

};

#endif // ASIAKAS_H
