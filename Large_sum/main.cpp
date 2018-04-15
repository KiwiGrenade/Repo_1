#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //string sum=0;
    int n=0,sum=0;
    fstream plik;
    plik.open("number.txt",ios::in);
    if (plik.good()==true){
        plik >> sum;
        cout << sum;
        }
    else{
        cout << "Error. Something is wrong with file.";
    }
    return 0;
}
