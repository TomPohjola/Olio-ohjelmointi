#include "pankkitili.h"

Pankkitili::Pankkitili(string omistaja)
{
    cout << "Pankkitili luotu kayttajalle" << " " << omistaja << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}


bool Pankkitili::deposit(double tal)
{
    if (tal > 0)
    {
        cout << "PANKKITILI: talletus" << " " << tal << " " << "tehty." << endl;

        saldo = saldo + tal;
        return true;
    }
    else
    {
        cout << "hylatty, et voi antaa negatiivista lukua." << endl;
        return false;
    }

}

bool Pankkitili::withdraw(double nos)
{
    if (nos > 0 && nos <= saldo)
    {
        cout << "PANKKITILI: nosto" << " " << nos << " " << "tehty." << endl;

        saldo = saldo - nos;

         cout << "saldo:" << " " << saldo << endl;

        return true;
    }

    else if(nos > saldo)
    {
        cout << "hylatty, saldo ei riita." << endl;
        return false;
    }

    else
    {
        cout << "hylatty, et voi antaa negatiivista lukua." << endl;
        return false;
    }

}
