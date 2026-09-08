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
        int n, k;
        cin>> n>>k;
        string str;
        cin>>str;
        int count = 0;
        
        for (int i = 0; i < n; i+=k)
        {
            bool pay = true;
            for (int j = i; j < i+k; j++)
            {
                if (str[j] == '0')
                {
                    pay = false;
                }    
            }
            if (pay)
            {
                count++;
            }
            
            
        }
        cout<<count<<'\n';
        
    }
    
    return 0;
}