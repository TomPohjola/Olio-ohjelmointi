#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

#include <iostream> // iostreamit ja namespacet pitää muistaa includettaa täälläkin.

using namespace std;

class italianChef: public chef
{
public:

    italianChef(string);
    ~italianChef();
    bool askSecret(string, int, int);

private:

    int makepizza(int, int);

    string password;
    int flour;
    int water;


};

#endif // ITALIANCHEF_H

