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
        vector<int> a(n + 1);
        vector<long long> freq(n + 2);
        long long sum = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += (long long)i * a[i];
            freq[a[i]]++;
        }

        vector<long long> b(n + 2);
        for (int i = n; i >= 1; i--)
        {
            b[i] = b[i + 1] + freq[i];
        }

        long long final_sum = 0;
        for (int h = 1; h <= n; h++)
        {
            if (b[h] == 0){
                continue;
            }
            long long idx = (long long)n * b[h] - (b[h] * (b[h] - 1) / 2);
            final_sum += idx;
        }

        long long dist = final_sum - sum;
        long long change = 0;

        for (int k = 1; k <= n; k++)
        {
            long long current_change = (long long)k - (n - b[a[k]] + 1);
            change = max(change, current_change);
        }

        cout << dist + change << "\n";
    }

    return 0;
}