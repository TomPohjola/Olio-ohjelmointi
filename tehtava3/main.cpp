#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{

    chef kokki("Gordon Ramsay");
    kokki.makeSalad(15);
    kokki.makeSoup(15);

    italianChef kokki2("Super Mario");
    kokki2.makeSalad(20);
    kokki2.askSecret("",15,15); //tässä kohdassa jätän salasanan tyhjäksi, ku haluan käyttäjän itse antaa se.







    return 0;
}
