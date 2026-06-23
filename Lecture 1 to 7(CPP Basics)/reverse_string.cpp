#include <iostream>
using namespace std;
/*
string reverse_string(string str){
    int s = 0;
    int e = str.size() - 1;

    while(s < e){
        swap(str[s], str[e]);
        s++;
        e--;
    }

    return str;
}
*/
string reverse_string(string str){
    int size =str.size();
    string temp(size, ' ');

    for (int i = 0; i < size; i++)
    {
        temp[i] = str[size - 1-i];
    }
    
    return temp;
}
int main()
{
    string str;
    getline(cin, str);

    string rev_string;
    for (int i = str.size() -1; i >=0 ; --i)
    {
        rev_string.push_back(str[i]);
    }
    
    cout << rev_string;

    // cout<< reverse_string(str);
    return 0;
}