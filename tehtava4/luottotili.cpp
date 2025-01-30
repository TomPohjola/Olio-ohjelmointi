#include "luottotili.h"
#include "pankkitili.h"



Luottotili::Luottotili(string omistaja, double luottoRaja) : Pankkitili(omistaja)
{
    this->luottoRaja = luottoRaja;
    cout << "Luottotili luotu kayttajalle" << " " << omistaja << endl;
}

bool Luottotili::deposit(double lTal)
{
    if (lTal > 0 && lTal+saldo <= 0)
    {
        cout << "LUOTTOTILI: talletus" << " " << lTal << " " << "tehty." << endl;
        saldo += lTal;

        cout << "LUOTTOTILI: saldo" << saldo << endl;
        return true;
    }
    else if (saldo+lTal > 0)
    {
        cout << "hylatty, saldo ei voi olla yli 0." << " " << endl;
        return false;

    }
    else
    {
        cout << "hylatty, et voi antaa negatiivista lukua." << endl;
        return false;
    }
}

bool Luottotili::withdraw(double lNos)
{
    //cout << luottoRaja;

    if (lNos > 0 && saldo-lNos >= -luottoRaja)
    {
        cout << "LUOTTOTILI: nosto" << " " << lNos << " " << "tehty." << endl;

        saldo -= lNos;

        cout << "LUOTTOTILI: saldo" << saldo << endl;
        return true;
    }
    else if (lNos > luottoRaja )
    {
        cout << "hylatty, luottoraja ei riita." << " " << endl;
        return false;
    }

    else
    {
        cout << "hylatty, et voi antaa negatiivista lukua." << endl;
        return false;
    }


}
