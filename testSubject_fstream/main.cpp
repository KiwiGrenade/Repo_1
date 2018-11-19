#include <iostream>
#include <fstream>

using namespace std;

struct wpis
{
    string nazwa;
    short odmiana;
    short ocena;
    int koszt;
};

void ocena()
{
    ofstream lista;
    lista.open("listaOcen.txt");
    if (lista.good()==true)
    {
        wpis towar;
        cout << "Nazwa: ";
        cin >> towar.nazwa;
        lista << "Nazwa: " << towar.nazwa << endl;
        cout << "Odmiana:" << endl;
        cout << "1.Sativa" << endl;
        cout << "2.Indica" << endl;
        cout << "3.Mix" << endl;
        while (towar.odmiana!=1&&towar.odmiana!=2&&towar.odmiana!=3)
        cin >> towar.odmiana;
        switch (towar.odmiana)
        {
            case 1:     lista << "Sativa" << endl;break;
            case 2:     lista << "Indica" << endl;break;
            case 3:     lista << "Mix" <<endl;break;
        }
        cout << "Ocena (od 0 do 10): ";
        cin >> towar.ocena;
        lista << "Ocena (od 0 do 10): " << towar.ocena << endl;
        cout << "Koszt: ";
        cin >> towar.koszt;
        lista << "Koszt: " << towar.koszt << endl;
    }

    else
    {
        cout << "Oj, cos poszlo nie tak!" << endl;
        cout << "Plik nie zostal poprawnie otwarty!";
    }

    lista.close();
}
void przeglad()
{
    ifstream lista;
    lista.open ("listaOcen.txt");
    string wiersz;
    while (getline (lista,wiersz).good() == true)
    {
        cout << wiersz << endl;
    }
    lista.close();
}

int main()
{
    cout << "Witaj w oceniaczu towaru!" << " Czym moge sluzyc?" << endl;
    cout << "1.Ocen towar" << endl;
    cout << "2.Przegladaj oceny" << endl;
    cout << "3.Usun ocene" << endl;
    cout << "0.Wyjdz" << endl;
    int wybor;
    cin >> wybor;
    switch (wybor)
    {
        case 1:
            {
                ocena();break;
            }
        case 2:
            {
                przeglad();break;
            }
        case 3:
        case 0:;
    }
    return 0;
}
