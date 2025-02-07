#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"

using namespace std;
#include <iostream>

class Notifikaattori
{
public:

    Notifikaattori();
    void lisaa(Seuraaja*); //tämän avulla voidaan käyttää ja muokata Seuraaja-olion/luokan dataa ilman et pitää kopioida kaikkea.
    void poista(Seuraaja*);        // seuraajat ja pos on osoittimia ko. luokkaan/olioon.
    void tulosta();
    void postita(string);

private:

    Seuraaja* seuraajat;

};

#endif // NOTIFIKAATTORI_H
