#include "seuraaja.h"
#include "notifikaattori.h"







Seuraaja::Seuraaja(string nimi)
{
    this->nimi = nimi;                      //this pointteri osoittaa ''itseään'' eli kun on 2 saman nimistä muuttujaa niin sillä kääntäjälle kerrotaan kumpi on kumpi. ''this->'' viittaa siis jäsenmuuttujaan eikä parametriin.
    next = nullptr;                         //määritellään next null pointeriksi.
}

string Seuraaja::getNimi()
{
    return nimi;                            //täs palautetaan vain nimi.
}

void Seuraaja::paivitus(string up)
{
    cout << up << endl;                     //tulostetaan konsolille päivitys
}
