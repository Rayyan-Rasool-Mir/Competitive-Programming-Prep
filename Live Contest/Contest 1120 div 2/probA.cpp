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

        int ones = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x == 1)
                ones++;
        }

        if (ones >= (n + 1) / 2)
            cout << "Bessie\n";
        else
            cout << "Elsie\n";
    }
    return 0;
}