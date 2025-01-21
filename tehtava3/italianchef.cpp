#include "chef.h"
#include "italianchef.h"



italianChef::italianChef(string chefName) : chef(chefName)
// tässä pitää muistaa laittaa tuo string chefname ja tärkeänä tuo ": chef(chefName), se pitää kutsua eksplisiittisesti, koska ei oo defaulttikonstruktoria."
{
    cout << "ITALIANCHEF KONSTRUKTORI: alustettu" << endl;
    password = "pizza";
}

italianChef::~italianChef()
{
    cout << "ITALIANCHEF DESTRUKTORI: data poistettu" << endl;
}

bool italianChef::askSecret(string ask, int flour, int water)
{

    cout << "anna salasana, jos haluat pizzaa" << endl; //oma kokeilu, jossa kysyn salasanan
    cin >> ask;

    if ((ask.compare(password)) == 0) {
        cout << "salasana oikein!" << endl;

    makepizza(flour, water);
    }
    else {
    cout << "salasana vaarin, nyt jaa pizzat saamatta :(" << endl;
    return false;

    }
    return true;

}

int italianChef::makepizza(int flour, int water)
{
    int pizzasFromFlour = flour / 5;
    int pizzasFromWater = water / 5;
    int totalPizzas = std::min(pizzasFromFlour, pizzasFromWater); //tässä toi min funktio valitsee pienemmän luvun, mikä on pizzanteossa rajoittava tekijä.

    cout << flour << " " << "jauhosta" << " " << "ja" << " " << water << " " << "vedesta" << " " << "saat yhteensa" << " " << totalPizzas << " " << "pitsaa." << endl;
    return 0;
}

