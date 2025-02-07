#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"



using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja *a = new Seuraaja("matti");    //luodaan oliot dynaamisesti
    Seuraaja *b = new Seuraaja("pekka");
    Seuraaja *c = new Seuraaja("seppo");

    n.lisaa(a);
    n.lisaa(b);
    n.lisaa(c);
    n.tulosta();

    n.postita("tassapa olisi somettelua.");

    n.poista(a);//poistetaan seuraaja a viittaamalla siihen & merkillä


    delete a;   //aina ku luodaan olio dynaamisesti new funktiolla, pitää muistaa poistaa ne deletellä.
    delete b;
    delete c;







}
