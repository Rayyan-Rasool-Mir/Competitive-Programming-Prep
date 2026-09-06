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
        vector<int> a(n);
        int bestL = -1, bestR = -1, maxK = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (maxK == 0 && (a[i] == 1 || a[i] == -1))
            {
                maxK = 1;
                bestL = i;
                bestR = i;
            }
        }

        for (int i = 0; i < n;)
        {
            if (a[i] == 1)
            {
                i++;
                continue;
            }
            int j = i;
            int firstNeg = -1, lastNeg = -1;
            while (j < n && a[j] != 1)
            {
                if (a[j] == -1)
                {
                    if (firstNeg == -1)
                        firstNeg = j;
                    lastNeg = j;
                }
                j++;
            }

            int curL = -1, curR = -1;

            if (i > 0 && a[i - 1] == 1)
                curL = i - 1;
            else if (firstNeg != -1)
                curL = firstNeg;

            if (j < n && a[j] == 1)
                curR = j;
            else if (lastNeg != -1)
                curR = lastNeg;

            if (curL != -1 && curR != -1 && curL < curR)
            {
                if (curR - curL + 1 > maxK)
                {
                    maxK = curR - curL + 1;
                    bestL = curL;
                    bestR = curR;
                }
            }
            i = j;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
                a[i] = 0;
        }
        if (bestL != -1)
        {
            a[bestL] = 1;
            a[bestR] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i != n - 1)
            {
                cout << " ";
            }
        }

        cout << "\n";
    }
}
