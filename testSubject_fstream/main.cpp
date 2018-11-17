#include <iostream>
#include <fstream>
using namespace std;

void ocena()
{   ofstream lista;
    lista.open("listaOcen.txt");
    cout << "Nazwa: ";
    string nazwa;
    cin >> nazwa;
    lista << "Nazwa: " << nazwa << endl;
    cout << "Odmiana:" << endl;
    cout << "1.Sativa" << endl;
    cout << "2.Indica" << endl;
    cout << "3.Mix" << endl;
    int odmiana=0;
    do
        {
            cin >> odmiana;
            switch (odmiana)
            {
                case 1:    lista << "Odmiana: Sativa" << endl;break;
                case 2:    lista << "Odmiana: Indica" << endl;break;
                case 3:    lista << "Odmiana: Mix" << endl;break;
                default: cout << "Blad wprowadzania danych!";break;
            }
        }
        while (odmiana==1||2||3);//popraw to <<
    cout << "Ocena: ";
    int ocena;
    cin >> ocena;
    lista << "Ocena: " << ocena << endl;
    cout << "Koszt: ";
    int koszt;
    cin >> koszt;
    lista << "Koszt: " << koszt << endl;
    lista.close();
}
void przeglad()
{
    ifstream lista;
    lista.open("listaOcen.txt");
    string wiersz;
    while (getline(lista,wiersz).good()==true)
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
                ocena();
            }
        case 2:
            {
                przeglad();
            }
        case 3:
        case 0:;
    }
    return 0;
}
