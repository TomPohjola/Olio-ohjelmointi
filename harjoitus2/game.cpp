#include "game.h"
#include <ctime>


game::game(int maxNumber)
{
    cout << "KONSTRUKTORI: alustetaan pelin maksimiarvon nyt." << endl;

    playerGuess = 0; //konstruktorissa alustetaan muuttujia
    numOfGuesses = 0;
    this->maxNumber = maxNumber; // vähän hämäävä, mut tässä toi this-> sijoittaa ton luvun 20 muuttujaan int maxNumber.
}

game::~game()
{
    cout << "DEKONSTRUKTORI: deletoidaan turha data" << endl;
}

void game::play()
{

    srand(time(NULL)); //seedin luonti kellonajasta.
    //cout << "3maksiminumero on" << " " << maxNumber << endl;
    randomNumber = rand() % maxNumber +1; //+1 varmistaa, että lukualue on 1-20

    //cout << "4maksiminumero on" << " " << maxNumber << endl;

    while(playerGuess != randomNumber){      //pelin silmukkarakenne.

        cout << "arvaa luku." << endl;
        cin >> playerGuess;

        if(playerGuess > randomNumber){
            cout << "yrita uudelleen, lukusi on suurempi." << endl;
            numOfGuesses++;  //inkrementoidaan arvausten määrää.
        }
        else if(playerGuess < randomNumber){
            cout << "yrita uudelleen, lukusi on pienempi." << endl;
            numOfGuesses++;  //inkrementoidaan arvausten määrää.
        }
        else if(playerGuess == randomNumber){
            cout << "hienoa! voitit pelin!" << endl;
            numOfGuesses++;  //inkrementoidaan arvausten määrää.
            printGameResult(); //kutsutaan toista funktiota tämän sisällä.
            break;
        }

    }

}

void game::printGameResult()
{
    cout << "arvausten lukumaara on:" << " " << numOfGuesses << endl;
}

