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

using ll = long long;


class Fenwick
{
    int n;
    vector<ll> bit;

public:
    Fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, ll val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll sum(int idx)
    {
        ll ans = 0;

        while (idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }

        return ans;
    }

    ll rangeSum(int l, int r)
    {
        if (l > r)
            return 0;

        return sum(r) - sum(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;


        vector<ll> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }

        Fenwick fw(n);

        set<int> active;

        set<int> starts;

        vector<int> answer(n + 1);


        int pos = p[n];

        active.insert(pos);
        starts.insert(pos);

        fw.add(pos, a[pos]);

        answer[n] = 0;



        for (int i = n - 1; i >= 1; i--)
        {
            pos = p[i];

            auto it = active.lower_bound(pos);

            bool hasLeft = false;
            int leftPos = -1;

            if (it != active.begin())
            {
                --it;
                hasLeft = true;
                leftPos = *it;
            }

            int currentGroup;


            if (!hasLeft)
            {
                currentGroup = pos;
                starts.insert(pos);
            }
            else
            {
                auto itStart = starts.upper_bound(leftPos);
                --itStart;

                int leftStart = *itStart;

                ll leftSum = fw.rangeSum(leftStart, leftPos);

                if (a[pos] > leftSum)
                {
                    currentGroup = pos;
                    starts.insert(pos);
                }
                else
                {
                    currentGroup = leftStart;
                }
            }


            active.insert(pos);
            fw.add(pos, a[pos]);

            while (true)
            {
                auto itNext = starts.upper_bound(currentGroup);

                if (itNext == starts.end())
                    break;

                int nextGroup = *itNext;

                ll currentSum =
                    fw.rangeSum(currentGroup, nextGroup - 1);

                if (a[nextGroup] <= currentSum)
                {
                    starts.erase(nextGroup);
                }
                else
                {
                    break;
                }
            }

            answer[i] = (int)starts.size() - 1;
        }


        for (int i = 1; i <= n; i++)
        {
            cout << answer[i] << " ";
        }

        cout << '\n';
    }

    return 0;
}