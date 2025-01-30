#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include <iostream>
#include "pankkitili.h"
using namespace std;




class Luottotili: public Pankkitili
{
public:

    Luottotili(string, double);
    bool deposit(double) override; //overridellä muutetaan perityt metodit.
    bool withdraw(double) override;

protected:

    double luottoRaja = 0;

};

#endif // LUOTTOTILI_H
