#include <iostream>
#include <string>
using namespace std;

int main()
{
    string imie;
    cout << "Podaj swoje imie: ";
    cin >> imie;
    if (imie[imie.length()-1]=='a'){
        cout << "Jestes kobieta!" << endl;
    }
    else {
        cout << "Jestes mezczyzna!" << endl;
    }
    return 0;
}
