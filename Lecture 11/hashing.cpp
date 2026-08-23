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
const int N = 1e7 + 10;
int hasharr[N];

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        hasharr[a[i]]++;
    }

    int t;
    cin>>t;

    while (t--)
    {
        int x;
        cin>>x;

        cout<< hasharr[x]<<endl;
    }
    
    
    return 0;
}