#include "asiakas.h"
#include "luottotili.h"
#include "pankkitili.h"




Asiakas::Asiakas(string nimi, double luottoRaja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja)
//alustusluettelossa pitää tarvitut jäsenmuuttujat.
{
    this->nimi = nimi;    //muistetaan tässäki sijoittaa toi annettu nimi parametri nimi jäsenmuuttujalle.

    cout << "asiakkuus luotu kayttajalle" << " " << nimi << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "luottotilisi saldo on" << " " << luottotili.getBalance() << endl;
    cout << "kayttotilisi saldo on" << " " << kayttotili.getBalance() << endl;

}

bool Asiakas::talletus(double talletus)
{
    kayttotili.deposit(talletus);
    return true;
}

bool Asiakas::nosto(double nosto)
{
    kayttotili.withdraw(nosto);
    return true;
}

bool Asiakas::luotonMaksu(double takaisinmaksu)
{
    luottotili.deposit(takaisinmaksu);
    return true;
}

bool Asiakas::luotonNosto(double velanotto)
{
    luottotili.withdraw(velanotto);
    return true;
}

bool Asiakas::tiliSiirto(double siirto, Asiakas &kohdeasiakas)
{
    {
        if (nosto(siirto))

        {

            // kutsutaan nosto metodia, katsotaan palauttaako se true arvon.

            cout << "Nostettiin " << siirto << " euroa asiakkaan " << nimi << " tililta." << endl;
            if (kohdeasiakas.talletus(siirto)) {
            cout << "Talletettiin " << siirto << " euroa asiakkaan " << kohdeasiakas.getNimi() << " tilille." << endl;
            return true;

            } else {

            // Jos se palauttaa falsen niin sit palautetaan rahat takaisin tilille.

            cout << "Talletus asiakkaan " << kohdeasiakas.getNimi() << " tilille epaonnistui. Palautetaan rahat." << endl;
            talletus(siirto);
            }
        } else {
            cout << "Nosto asiakkaan " << nimi << " tililta epäonnistui." << endl;
        }
        return false;
    }
}
