#include <iostream>
#include "opz.h"

using namespace std;
int main()
{
    char* str = new char[500];

    cout <<"Введите строку: ";
    cin.getline(str, 500);

    if (GetCheck(str))
        cout << GetResult(str);
    else
        cout << "Строка введена неверно";

    return 0;
}