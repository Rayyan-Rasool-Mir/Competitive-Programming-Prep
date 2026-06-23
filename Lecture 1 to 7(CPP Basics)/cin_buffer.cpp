#include <iostream>
using namespace std;

int main()
{
    int t;//number of test cases
    cin>>t;
    cin.ignore(); //ignore the buffer created by the cin above to allow getline take the correct number of inputs

    while (t--)
    {
        string s;
        getline(cin, s);
        cout<<s<<endl;
    }
    
    return 0;
}