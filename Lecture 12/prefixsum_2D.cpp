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
const int N = 1e3 +10;
int arr[N][N];
long long pf[N][N];

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] ;
        }
        
    }

    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        // long long sum = 0;

        // for (int i = a; i <= c; i++)
        // {
        //     for (int j = b; j <= d; j++)
        //     {
        //         sum += arr[i][j];
        //     }
        // }
        cout<<pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1]  <<endl;
    }

    return 0;
}