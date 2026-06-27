#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &b = a;

    cout << a << " " << b << endl;

    b = 20;

    cout << a << " " << b << endl;

    return 0;
}