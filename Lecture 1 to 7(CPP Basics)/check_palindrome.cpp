#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    string rev_string;
    for (int i = str.size() -1; i >=0 ; --i)
    {
        rev_string.push_back(str[i]);
    }
    
    if(str==rev_string){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a Plaindrome"<<endl;
    }
    return 0;
}