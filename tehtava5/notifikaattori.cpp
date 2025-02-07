#include "notifikaattori.h"
#include "seuraaja.h"




Notifikaattori::Notifikaattori() : seuraajat(nullptr) //alustetaan seuraajat osoitin nulliksi.
{
    cout << "luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *uusiseuraaja)
{
    uusiseuraaja->next = seuraajat;     //lisätään uusi seuraaja listan alkuun ja sitten päivitetään seuraajat osoitin osoittaan uuteen seuraajaan.
    seuraajat = uusiseuraaja;

    cout << "luodaan seuraaja" << " " << seuraajat->getNimi() << endl;


}

void Notifikaattori::poista(Seuraaja *pois)
{
    Seuraaja* nykyinen = seuraajat;
    Seuraaja* edellinen = nullptr;

    cout << "poistetaan seuraaja" << " " << pois->getNimi() << endl;

    while (nykyinen != nullptr) {
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }

    if (nykyinen == pois) {
        if (edellinen == nullptr) {
            seuraajat = nykyinen->next;
        } else {
            edellinen->next = nykyinen->next;
        }
        delete nykyinen;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja* nykyinen = seuraajat;
    cout << nykyinen << endl;
    while (nykyinen != nullptr) {
        cout << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(string post)
{
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr) {

        cout << "seuraaja" << " " << nykyinen->getNimi() << " " << "sai viestin" << " ";

        nykyinen = nykyinen->next;

        nykyinen->paivitus(post);        //paivitus otta parametriksi muuttujan pos.

    }
}
