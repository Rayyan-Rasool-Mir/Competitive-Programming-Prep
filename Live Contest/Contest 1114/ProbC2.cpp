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

        string a, b;
        cin >> a >> b;

        vector<int> oddA, evenA, oddB, evenB;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                if (i % 2 == 0)
                    oddA.push_back(i);
                else
                    evenA.push_back(i);
            }

            if (b[i] == '1')
            {
                if (i % 2 == 0)
                    oddB.push_back(i);
                else
                    evenB.push_back(i);
            }
        }

        if (oddA.size() != oddB.size() || evenA.size() != evenB.size())
        {
            cout << -1 << endl;
            continue;
        }

        long long ans = 0;

        for (int i = 0; i < (int)oddA.size(); i++)
            ans += abs(oddA[i] - oddB[i]) / 2;

        for (int i = 0; i < (int)evenA.size(); i++)
            ans += abs(evenA[i] - evenB[i]) / 2;

        cout << ans << endl;
    }

    return 0;
}