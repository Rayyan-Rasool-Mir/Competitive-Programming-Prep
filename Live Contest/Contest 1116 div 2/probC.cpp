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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int m = 2 * n;

        string next = s;

        for (int i = 0; i < m; i++)
        {
            int j = (i + 1) % m;

            if (s[i] == '1' && s[j] == '0')
            {
                next[i] = '0';
                next[j] = '1';
            }
        }

        int redScore = 0;
        int totalPotatoes = 0;

        for (int i = 0; i < m; i++)
        {
            if (next[i] == '1')
            {
                totalPotatoes++;

                if (i % 2 == 1)
                    redScore++;
            }
        }

        int blueScore = totalPotatoes - redScore;

        cout << redScore << " " << blueScore << '\n';
    }

    return 0;
}