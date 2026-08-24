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
//here we are assuming a 1 index based array
int main()
{
    const int N = 1e5 +10;
    int arr[N];
    int pf[N];

    int n;
    cin>>n;

    for (int  i = 1; i <= n; i++)
    {
        cin>>arr[i];
        pf[i] = pf[i-1] + arr[i];
    }

    int t;
    cin>>t;
    while (t--)
    {
        int l, r;
        cin>>l>>r;

        // long long sum = 0;
        // for (int i = l; i <= r; i++)
        // {
        //     sum += arr[i];
        // }
        //this code isn't needed for prefix

        cout<<pf[r] - pf[l-1]<<endl;
        
    }
    //TC = O(N)
    
    
    return 0;
}