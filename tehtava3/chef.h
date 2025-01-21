#ifndef CHEF_H
#define CHEF_H

#include <iostream> // iostreamit ja namespacet pitää muistaa includettaa täälläkin.

using namespace std;

class chef
{
public:

    chef(string);       //chef jäsenmuuttujat.
    ~chef();
    //string getName(); mikä tän tarkoitus on?
    int makeSalad(int);
    int makeSoup(int);

protected:

    string chefName;
};

#endif // CHEF_H
