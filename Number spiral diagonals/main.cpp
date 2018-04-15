#include <iostream>
#include <windows.h>
using namespace std;
bool test_1(int i)
{
    if(i%2!=0)
        {return true;}
    else
        {return false;}
}
int main()
{
    int i=0,licznik_przeskoku=0,licznik_zapisu=0,licznik_przeskoku_max=1,licznik_zapisu_max=4;
    for (i;i<25;i++){
        licznik_przeskoku++;
        if (test_1(i)==true){
            licznik_zapisu++;
            cout << i << "    #1" << endl;
            if(licznik_przeskoku=licznik_przeskoku_max){
                    licznik_przeskoku=0;
                    cout << i << "    #2" << endl;
                    }}
        if (licznik_zapisu=licznik_zapisu_max){
            licznik_zapisu=0;
            licznik_przeskoku_max+2;
            }}
return 0;
}
