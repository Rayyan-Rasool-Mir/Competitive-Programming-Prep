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

bool check(int X, int n, int m, const vector<long long> &v, const vector<vector<long long>> &a)
{
    if (X <= 0){
        return false;
    }

    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    long long current_sum = 0;

    for (int k = n - 1; k >= 0; --k)
    {
        for (int j = 0; j < m; ++j)
        {
            if (min_heap.size() < X)
            {

                min_heap.push(a[k][j]);
                current_sum += a[k][j];
            }
            else if (a[k][j] > min_heap.top())
            {

                current_sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(a[k][j]);
                current_sum += a[k][j];
            }
        }
        if (current_sum >= v[k])
            return true;
    }
    return false;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin>>n >> m;
        vector<long long> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        vector<vector<long long>> a(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        int low = 1, high = m - 1;
        int ans = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, n, m, v, a))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}