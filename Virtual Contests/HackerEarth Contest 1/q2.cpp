#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        int num = 1;

        int size;
        cin>>size;

        for (int i = 0; i < size; i++)
        {
            int input;
            cin >> input;

            num = (num*input)%10;
        }
        

        if (num == 2 || num == 3 || num == 5)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}