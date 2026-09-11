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
        long long x, y;
        cin >> x >> y;
        vector<long long> val;

        long long maxval = x+y;
        long long opno = 0;

        for (int bit = 30; bit >= 0; bit--) {
            if (maxval & (1LL << bit)) {
                long long candidate = opno | (1LL << bit);

                if (candidate <= x) {
                    opno = candidate;
                }
            }
        }

        cout << maxval << " " << x - opno << '\n';
        
    }

    return 0;
}