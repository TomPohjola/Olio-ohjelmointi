#ifndef GAME_H
#define GAME_H

#include <iostream> // iostreamit ja namespacet pitää muistaa includettaa täälläkin.

using namespace std;

class game
{
public:
    game(int maxNumber);    //konstruktori, täällä alustetaan pari muuttujaa ja maksimiarvo.
    ~game(); //destruktori
    void play(); //pelin toiminnallisuus täällä.

private:

    int maxNumber; //tässä on gamen jäsenmuuttujat.
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();

};

#endif // GAME_H
