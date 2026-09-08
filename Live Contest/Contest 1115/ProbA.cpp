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

        int arr[n];
        int freq[1001] = {0};

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        int sum = 0;
        int maxfreq = 0;
        int maxval = 0;

        for (int i = 0; i < 1001; i++)
        {
            if (freq[i] > 0)
            {
                sum += i * freq[i];

                if (freq[i] > maxfreq)
                {
                    maxfreq = freq[i];
                    maxval = i;
                }
            }
        }
        int others = n - maxfreq;

        if (maxfreq <= others + 1)
        {
            cout << sum << endl;
        }
        else
        {
            int usable = others + 2;
            int lost = maxfreq - usable;
            cout << sum - lost * maxval << endl;
        }
    }

    return 0;
}