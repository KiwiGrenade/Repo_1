#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

string wordSelection()
{
    string word;
    srand(time(NULL));
    int randomNumber=(rand()%100)+1;
    ifstream wordsList;
    wordsList.open("wordsList.txt");
    if(wordsList.good()==true)
    {
        int i=0;
        for (i;i<randomNumber;i++)
        {
            getline(wordsList,word);
        }
    }
    wordsList.close();
    return word;
}

string unreviling (string coveredLetters, string word, char letter)
{
    size_t found=word.find_first_of(letter);//zmienna "found" rowna sie pozycji znaku ze zmiennej char "letter" w zmiennej string "word", jesli znaku nie znaleziono
                                            //zmienna "found" przyjmuje wartosc maksymalnej wartosci "size_t", czyli "npos"
    while  (found!=string::npos)      //rub \/ jesli zmienna "found" nie jest rowna npos (czyli jesli funkcja "find_first_of" znalazla
                                      //znak ze zmiennej "letter" w string "word"
    {
        coveredLetters[found]=word[found]; //zastap znak ze string "coveredLetters" z pozycji "found" znakiem z tej samej pozycji ze string "word"
        found=word.find_first_of(letter,found+1);//przeszukaj zmienna "word" w poszukiwaniu znaku "letter" _PO_ pozycji ostatniego znaku znalezionego
                                                //np. "kukulka"- program wyszuka najpierw pierwsze k, potem zmieni definicje zmiennej "found"
                                                //na kolejna wspolrzedna zmiennej "letter", jesli takowa wystepuje
    }
    return coveredLetters;
}

int main()
{
    int health = 7, points = 0;                         //
    string coveredLetters, word = wordSelection();              //inicjalizacja zmiennych (pozostalo stworzenie algorytmu randomizujocego, i bazy danych ze slowami
                                                    //oraz odczytu slow do zmiennej "word"
    char letter;                                    //
    coveredLetters.assign (word.size(), '-');//wypelnianie zmiennej "coveredLetters" znakiem '-' tyle razy, ile znakow ma zmienna "anwer"
    while (health > 0 && word != coveredLetters)
    {
        cout << "Health:" << health << "        Points:" << points << endl;
        cout << "Your word: " << coveredLetters << endl;
        cout << "Insert letter here: " << endl;
        cin >> letter;
        coveredLetters = unreviling(coveredLetters, word, letter);//przypisanie zmiennej string "coveredLetters" wartosci zwracanej przez funckcje
                                                              //"unreviling", aby zmienna string zapamietala zmiany
        if (word.find_first_of(letter) != string::npos)//to samo co "found!="
            points++;
        else
            health--;
    }
    if (word==coveredLetters && health!=0)
        cout << "Congratulations! You won!" <<endl;
    else
        cout << "You lost!" << endl;
    return 0;
}
