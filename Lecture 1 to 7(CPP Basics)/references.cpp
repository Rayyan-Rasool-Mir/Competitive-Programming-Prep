#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &b = a;

    cout << a << " " << b << endl;

    b = 20;

    cout << a << " " << b << endl;
    // when we change the value of b it also changes the value of a.
    return 0;
}