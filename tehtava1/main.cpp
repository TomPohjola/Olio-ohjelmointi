#include <iostream>
#include <ctime>
using namespace std;

int game(int maxNum);   //peli aliohjelman prototyyppi, ottaa vastaan integerin maxNum.
int arvausMaara;


int game(int maxNum){       // toi ''int maxNum'' pitää olla prototyypissä ja aliohjelmassa. pääohjelmassa kutsuttaessa laitetaan vaan se luku, joka halutaan sen maxNum olevan.

    srand(time(NULL)); //seedi randominumerogeneraattorille

    int randNum = rand() % maxNum;  //randomi numero on suurimmillaan maxNumin arvo.
    int arvattuLuku = 0;

    while(arvattuLuku != randNum){      //pelin silmukkarakenne.

        cout << "arvaa luku." << endl;
        cin >> arvattuLuku;

        if(arvattuLuku > randNum){
            cout << "yrita uudelleen, lukusi on suurempi." << endl;
            arvausMaara++;  //inkrementoidaan arvausten määrää.
        }
        else if(arvattuLuku < randNum){
            cout << "yrita uudelleen, lukusi on pienempi." << endl;
            arvausMaara++;  //inkrementoidaan arvausten määrää.
        }
        else if(arvattuLuku == randNum){
            cout << "hienoa! voitit pelin!" << endl;
            arvausMaara++;  //inkrementoidaan arvausten määrää.
            return arvausMaara; //palautetaan arvausten määrä.
        }

    }

}

int main()
{

    game(20); //kutsutaan peliohjelma, peli ottaa vastaan integerein maxNum, joka on tässä tapauksessa 20.
    cout << "arvausten lukumaara" << " " << arvausMaara << endl;    //tulostetaan arvausten määr lopuksi.
    return 0;
}
