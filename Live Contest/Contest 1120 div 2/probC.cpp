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
        int n;
        cin >> n;

        vector<long long> a(n + 1);

        for (int k = 1; k <= n; k++)
        {
            cin >> a[k];
        }

        vector<int> diff(n + 1, 0);

        for (int k = 1; k <= n; k++)
        {
            long long L = 1LL * k * a[k];
            long long R = 1LL * k * (a[k] + 1) - 1;

            if (L < n)
            {
                R = min(R, 1LL * n - 1);

                diff[L]++;
                diff[R + 1]--;
            }
        }

        vector<int> B;

        int covered = 0;

        for (int x = 0; x < n; x++)
        {
            covered += diff[x];

            if (covered == 0)
            {
                B.push_back(x);
            }
        }

        cout << B.size() << '\n';

        for (int x : B)
        {
            cout << x << " ";
        }

        cout << '\n';
    }
}