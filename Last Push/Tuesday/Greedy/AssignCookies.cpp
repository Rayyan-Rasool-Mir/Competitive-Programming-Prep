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
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int l = 0;
    int r = 0;

    while (l < g.size() && r < s.size())
    {
        if (g[l] <= s[r])
        {
            r++;
            l++;
        }
        else
        {
            r++;
        }
    }
    return l;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int ans = findContentChildren(g, s);

    cout << "Maximum satisfied children: " << ans << endl;

    return 0;
}

/*
This uses Greedy + Two Pointers:
    1. Sort children by greed factor.
    2. Sort cookies by size.
    3. l points to the current child and r to the current cookie.
    4. If cookie >= greed, assign it → move both pointers.
    5. If cookie < greed, the cookie is useless for this and every later child → move only the cookie pointer.
    6. l is the number of satisfied children.
*/