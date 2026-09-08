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
        string s;
        cin >> n >> s;


        long long MOD = 998244353;

        long long ways[2] = {1, 1};

        for (int parity = 0; parity < 2; ++parity)
        {
            int implied_start_val = -1;
            bool possible = true;

            for (int i = parity; i < n; i += 2)
            {
                if (s[i] != '?')
                {
                    int current_val = s[i] - '0';
                    int step_from_start = (i - parity) / 2;

                    int start_val_needed = (current_val + step_from_start) % 2;

                    if (implied_start_val == -1)
                    {
                        implied_start_val = start_val_needed;
                    }
                    else if (implied_start_val != start_val_needed)
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible)
            {
                ways[parity] = 0;
            }
            else if (implied_start_val == -1)
            {

                ways[parity] = 2;
            }
            else
            {
                ways[parity] = 1;
            }
        }

        cout << (ways[0] * ways[1]) % MOD << "\n";
    }

    return 0;
}