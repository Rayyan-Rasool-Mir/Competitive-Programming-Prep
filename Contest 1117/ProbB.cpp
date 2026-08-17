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
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        for (int i = 0; i < m; i++)
        {
            cin>>b[i];
        }
        
        long long bea = a[0] + n - 1;
        long long ver = b[0] + m - 1;

        if (bea >= ver)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}