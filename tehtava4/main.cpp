#include <iostream>

#include "luottotili.h"
#include "pankkitili.h"
#include "asiakas.h"

using namespace std;

int main()
{
    //Pankkitili asiakas1("matti"); //nää on testailuja.
    //asiakas1.deposit(500);
    //asiakas1.getBalance();
    //asiakas1.withdraw(50);
    //asiakas1.deposit(-123);
    //asiakas1.withdraw(5000);

    //Luottotili asiakas2("matti", 300); //nää on myös testailuja.
    //asiakas2.withdraw(150);
    //asiakas2.withdraw(150);
    //asiakas2.withdraw(150);
    //asiakas2.deposit(299);
    //asiakas2.deposit(2);
    //asiakas2.deposit(1);
    //asiakas2.deposit(1);
    //asiakas2.deposit(-1);

    Asiakas asiakas1("Seppo", 400); //Asiakas on koosteolio, joka omistaa pankkitili ja luottotili oliot.
    Asiakas asiakas2("matti", 400);
    asiakas1.showSaldo();
    asiakas1.luotonNosto(300);


    asiakas1.luotonNosto(410);

    asiakas1.talletus(500);
    asiakas1.tiliSiirto(300, asiakas2);
    asiakas2.showSaldo();


    return 0;
}
