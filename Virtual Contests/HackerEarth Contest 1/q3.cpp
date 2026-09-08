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

        string bi;
        cin >> bi;
        long long int ans = 0;

        for (char bit : bi)
        {
            ans = ans * 2 + (bit - '0');
        }
        cout << ans << endl;
    }

    return 0;
}