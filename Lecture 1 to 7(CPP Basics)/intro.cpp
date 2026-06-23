/*
Find the area of rectangle using lb
constraints:
1<=l<=10^9
1<=b<=10^9

*/
#include <iostream>
using namespace std;

// int main()
// {
//     long long int l, b; //due to constraints we can't just take int in the final output, we need higher storage datatypes like long long int;
//     cin >>l >> b;

//     cout<< l*b<<endl;

// }


int main()
{
    long long int l, b;
    cin >>l >> b;

    cout<< l* 1LL* b<<endl; //approach 2 where we use 1LL in order to do the calculations in long long int form to store the answer

}