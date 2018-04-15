#include <iostream>
#include <string>

using namespace std;

int main()
{
    __int64 i=1,wynik=1,suma=0,liczba=10;
    for (i;i<=100-1;i++){
        wynik+=wynik*i;
            cout << wynik << endl;
    }
    i=0; //poni¿sza pêtla for jest przyk³adem pêtli oddzielaj¹cej cyfry od liczby dodawaj¹c je do sumy cyfr
    for (i;i<wynik*10;i++){ //wynik mno¿ony jest razy 10 bo z ka¿d¹ pêtl¹ zmniejsza siê o 10, oznacza to, ¿e nie ma miejsca w pêtli dla finalnej cyfry
        suma+= wynik%10; //oddzielanie cyfry od liczby i dodawanie jej do sumy cyfr
        wynik/=10;//usuwanie cyfry ju¿ dodanej z liczby
    }
    cout << suma;
    return 0;
}
