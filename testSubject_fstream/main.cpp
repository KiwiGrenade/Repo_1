#include <iostream>
#include <fstream>

using namespace std;

struct wpis //utworzenie struktury typu "wpis"
{

    string nazwa;
    short odmiana;
    short ocena;
    int koszt;
};

void ocenianie()
{
    ofstream lista;
    lista.open("listaOcen.txt",std::fstream::app);
    if (lista.good()==true)
    {
        wpis towar;                                             //utworzenie struktury typu "wpis" o nazwie "towar"
        cout << "Nazwa: ";
        cin >> towar.nazwa;                                     //zapisanie strumienia danych do struktury o nazwie "towar" do komorki "nazwa"
        lista << "Nazwa: " << towar.nazwa << endl;              //wtloczenie danych z "towar.nazwa" do listy
        cout << "Odmiana:" << endl <<"1.Sativa" << endl << "2.Indica" << endl << "3.Mix" << endl;
        while (towar.odmiana!=1 && towar.odmiana!=2 && towar.odmiana!=3)            //dopoki "towar.odmiana" nie jest rowna 1, 2 lub 3;podaj odmiane
        cin >> towar.odmiana;
        switch (towar.odmiana)
        {
            case 1:     lista << "Odmiana: Sativa" << endl; break;
            case 2:     lista << "Odmiana: Indica" << endl; break;
            case 3:     lista << "Odmiana: Mix" <<endl; break;
        }
        cout << "Ocena (od 0 do 10): ";
        cin >> towar.ocena;
        lista << "Ocena (od 0 do 10): " << towar.ocena << endl;
        cout << "Koszt: ";
        cin >> towar.koszt;
        lista << "Koszt: " << towar.koszt << endl;                  //popracuj nad tym
    }

    else
    {
        cout << "Oj, cos poszlo nie tak!" << endl;
        cout << "Plik nie zostal poprawnie otwarty!";
    }

    lista.close();
}

void przegladanie()
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

void usuwanie()
{
  ofstream lista;
  lista.open("listaOcen.txt",std::fstream::trunc);
  lista.close();
}

int main()
{
  int wybor=11;
  do {
    cout << "Witaj w oceniaczu towaru!" << " Czym moge sluzyc?" << endl;
    cout << "1.Ocen towar" << endl;
    cout << "2.Przegladaj oceny" << endl;
    cout << "9.Usun wszystkie oceny" << endl;
    cout << "0.Wyjdz" << endl;
    cin >> wybor;
    system("cls");
    switch (wybor)
    {
        case 1:
            {
                ocenianie();
                system("cls");
                break;
            }
        case 2:
            {
                przegladanie();
                system("pause");
                system("cls");
                break;
            }
        case 9:
            {
                const string haslo = "OCZYWISCIE";
                string klucz;
                cout << "Jestes pewien, ze chcesz to zrobic?" << '\n';
                cout << "Wpisz OCZYWISCIE (uwzgledniajac wielkie litery)" << '\n';
                cout << "aby usunac wszystkie wpisy." << '\n';
                cin >> klucz;
                if (klucz==haslo)
                {
                  usuwanie();
                  system("cls");
                  cout << "Wszystkie wpisy zostaly zniszczone." << '\n';
                  system("pause");
                  system("cls");
                  break;
                }
                else system("cls");break;

            }
        case 0:
        {
          system("exit");break;
        }
        default:
            {
              cout << "Error: ";
              system("pause");
              break;
            }
    }
  } while(wybor!=0);

    return 0;
}
