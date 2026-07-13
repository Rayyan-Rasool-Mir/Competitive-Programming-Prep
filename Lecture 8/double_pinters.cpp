#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    int* p = &a;

    int** pp = &p;

    cout << a << endl;
    cout << *p << endl;
    cout << **pp << endl;
}