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
        int n, m;
        cin >> n >> m;

        vector<int> count(m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a <= m)
            {
                count[a]++;
            }
        }

        vector<long long> sum(m + 2, 0);
        for (int i = m; i >= 1; i--)
        {
            sum[i] = sum[i + 1] + count[i];
        }

        long long max_carrots = 0;
        for (int i = 1; i <= m; i++)
        {
            long long current_count = sum[i];
            if (2 * i <= m)
            {
                current_count += count[2 * i];
            }
            max_carrots = max(max_carrots, current_count);
        }
        
        cout<<max_carrots<<endl;
    }

    return 0;
}