#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    fstream plik;
    plik.open("long_number.txt",ios::in);
    if (plik.good()==false){
        cout << "Error, nie odnaleziono pliku." << endl;
        exit (0);
    }
    else {

    }
    return 0;
}
