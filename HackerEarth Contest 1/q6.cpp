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
    cin >> t;
    while (t--)
    {
        long long int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int val = 1;
            for (int j = 0; j <= i; j++)
            {
                cout<< val << " ";
                val = val * (i - j) / (j + 1);
            }
            cout<<endl;   
        }
    }
    
    return 0;
}