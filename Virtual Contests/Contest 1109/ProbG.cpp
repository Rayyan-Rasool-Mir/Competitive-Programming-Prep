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

const int MAXN = 200005;
long long tree[4 * MAXN];

void update(int node, int start, int end, int idx, long long val)
{
    if (start == end)
    {
        tree[node] = max(tree[node], val);
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid){
        update(2 * node, start, mid, idx, val);

    }
    else{
        update(2 * node + 1, mid + 1, end, idx, val);

    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

long long query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l){
        return 0;
    }
    if (l <= start && end <= r){
        return tree[node];
    }
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        vector<vector<int>> ready(n + 2);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for (int i = 0; i <= 4 * n; i++){
            tree[i] = 0;
        }

        vector<long long> dp(n + 1, 0);
        vector<long long> ending(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j : ready[i])
            {
                update(1, 1, n, j, ending[j]);
            }

            long long prev = 0;
            int limit = i - a[i] - 1;
            if (limit >= 1)
            {
                prev = query(1, 1, n, 1, min(limit, n));
            }
            ending[i] = a[i] + prev;

            dp[i] = max(dp[i - 1], ending[i]);

            long long time = i + a[i] + 1;
            if (time <= n)
            {
                ready[time].push_back(i);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}