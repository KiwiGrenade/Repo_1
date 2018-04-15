/*Program jest praktycznie w pełni gotowy. Jedyne co może być zmienione, to rola liter w kluczu i jego skomplikowanie, tak jak złożoność procesu szyfrowania.
Maszyna szyfrująca, jak i deszyfrująca oparta jest o szyfr Cezara. Po podaniu klucza program dodaje jego wartość do każdej litery wiadomośći zmieniając ją na szyfr.
Deszyfrowanie oparte jest na odwróceniu tego procesu. Do szyfrowania i deszyfrowania służy jeden klucz.*/


#include <iostream>
#include <windows.h>
#include <string>


using namespace std;


string szyfrowanie(string tresc_wprowadzana,int klucz){
string tresc_wychodzaca;
    for (unsigned i=0;i < tresc_wprowadzana.length();i++){
            tresc_wychodzaca+=tresc_wprowadzana[i]+klucz;
    }
return tresc_wychodzaca;
}


string deszyfrowanie(string tresc_wprowadzana,int klucz){
string tresc_wychodzaca;
    for (unsigned i=0;i < tresc_wprowadzana.length();i++){
            tresc_wychodzaca+=tresc_wprowadzana[i]-klucz;
    }
return tresc_wychodzaca;
}


int wzor_szyfrowania(){
    system("cls");
        cout << "Podaj klucz: ";
        string tresc;
        int klucz;
        cin >> klucz;
        if (0>klucz)
        {
            cout << "Niepoprawny format klucza. ";system("pause");return(wzor_szyfrowania());
        }
        cin.ignore();
        system("cls");
        cout << "Klucz: " << klucz <<endl;
        cout << "Podaj tresc wiadomosci: ";
        getline(cin,tresc);
        system("cls");
        cout << "Klucz: " << klucz << endl;
        cout << "Tresc wiadomosci: " << szyfrowanie(tresc,klucz) << endl;
        system("pause");
        system("cls");
        }

int wzor_deszyfrowania(){
    system("cls");
        cout << "Podaj klucz: ";
        string tresc;
        int klucz;
        cin >> klucz;
        if (0>klucz)
        {
            cout << "Niepoprawny format klucza. ";system("pause");return(wzor_szyfrowania());
        }
        cin.ignore();
        system("cls");
        cout << "Klucz: " << klucz <<endl;
        cout << "Podaj tresc wiadomosci: ";
        getline(cin,tresc);
        system("cls");
        cout << "Klucz: " << klucz << endl;
        cout << "Tresc wiadomosci: " << deszyfrowanie(tresc,klucz) << endl;
        system("pause");
        system("cls");
        }


int main()
{
    int choice;
    while (choice!=0){
    cout << "0-Wyjscie z programu" << endl;
    cout << "1-Szyfrowanie" << endl;
    cout << "2-Deszyfrowanie" << endl;
    cin >> choice;
    switch(choice){
        case 0:{
        system("cls");
        cout << "See ya!"; break;
        }
        case 1:{
            wzor_szyfrowania();
            break;
        }
        case 2:{
            wzor_deszyfrowania();
            break;
        }
        default:{
        cout << "Nie zrozumialem komendy." << endl; break;
        }
    }
}
    return 0;
}
