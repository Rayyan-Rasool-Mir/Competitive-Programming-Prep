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
        long long int ans = 0;
        long long int best = 0;
        vector<long long> freq(n + 2);
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<int> suffix(n + 2);

        suffix[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
        {
            suffix[i] = min(a[i], suffix[i + 1]);
        }

        for (int i = 1; i <= n; i++)
        {
            ans += (a[i] - suffix[i]);
            freq[suffix[i]]++;
        }


        for (int i = 0; i < freq.size(); i++)
        {
            best = max(best, freq[i]);
        }
        ans += max(0LL, best - 1);

        cout << ans << "\n";
    }

    return 0;
}