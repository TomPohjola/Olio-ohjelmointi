#ifndef SEURAAJA_H
#define SEURAAJA_H

using namespace std;
#include <iostream>

class Seuraaja
{    
public:

    Seuraaja(string);  //public jäsenfuntiot.
    string getNimi();
    void paivitus(string);

    Seuraaja* next;

private:

    string nimi;



};

#endif // SEURAAJA_H
