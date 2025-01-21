#include "chef.h"

chef::chef(string chefName) //kokin nimi tänne
{
    cout << "CHEF KONSTRUKTORI: chef alustettu." << endl;
    this->chefName =chefName;       //taas käytän tuota this juttua ku saman nimiset muuttujat
    cout << "kokin nimi:" << "" << chefName << endl;
}

chef::~chef()
{
    cout << "CHEF DESTRUKTORI: data poistettu." << endl; //poistetaan turha data
}

int chef::makeSalad(int salad)  //otetaan vastaan aineksien määrä.
{
    int annos;
    annos = salad / 5;

    cout << "annoit" << " " << salad <<  " " << "ainesta," <<  " " << "joista saat"  " "
         <<  annos <<  " " << "annosta" << endl;
    return salad/5;         //jakamalla 5 saahaan annosten määrä.

}

int chef::makeSoup(int soup)
{
    int annos;
    annos = soup / 3;

    cout << "annoit" << " " << soup <<  " " << "ainesta," <<  " " << "joista saat"  " "
         <<  annos <<  " " << "annosta" << endl;
    return soup/3;
}
