#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream> // iostreamit ja namespacet pitää muistaa includettaa täälläkin.

using namespace std;

class Pankkitili
{
public:

    Pankkitili(string omistaja);
    double getBalance();        //getteri saldolle
    virtual bool deposit(double); //virtuaalimetodeja.
    virtual bool withdraw(double);


protected:

    string omistaja;
    double saldo = 0;

};

#endif // PANKKITILI_H
