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

        int size = 2 * n;

        vector<int> arr(size + 1);
        vector<int> first(n + 1, -1);
        vector<int> partner(size + 1);
        vector<long long> dp(size + 2, 0);

        for (int i = 1; i <= size; i++)
        {
            cin >> arr[i];

            if (first[arr[i]] == -1)
            {
                first[arr[i]] = i;
            }
            else
            {
                partner[i] = first[arr[i]];
                partner[first[arr[i]]] = i;
            }
        }

        for (int i = size; i >= 1; i--)
        {
            dp[i] = dp[i + 1] + 1;

            if (partner[i] > i)
            {
                int length = partner[i] - i + 1;
                dp[i] = max(dp[i], 1LL * length * length + dp[partner[i] + 1]);
            }
        }

        cout << dp[1] << endl;
    }

    return 0;
}