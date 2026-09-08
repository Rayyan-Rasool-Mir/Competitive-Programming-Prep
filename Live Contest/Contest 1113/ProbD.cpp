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

    int t_cases;
    cin >> t_cases;

    while (t_cases--)
    {
        int n, q;
        cin >> n >> q;

        string s, t;
        cin >> s >> t;

        vector<int> prefA(n + 1, 0);
        vector<int> prefB(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            prefA[i + 1] = prefA[i];
            prefB[i + 1] = prefB[i];
            if (s[i] == '1' && t[i] == '0')
            {
                prefA[i + 1]++;
            }
            else if (s[i] == '0' && t[i] == '1')
            {
                prefB[i + 1]++;
            }
        }

        for (int i = 0; i < q; ++i)
        {
            int l, r;
            cin >> l >> r;
            int countA = prefA[r] - prefA[l - 1];
            int countB = prefB[r] - prefB[l - 1];
            int len = r - l + 1;

            if (2 * countA <= len && 2 * countB <= len)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}