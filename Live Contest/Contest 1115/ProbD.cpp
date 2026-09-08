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
    ;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n < 2)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i];

                if (i == n - 1)
                {
                    cout << "";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
            continue;
        }

        vector<long long> x(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            x[i] = a[i + 1] - a[i];
        }

        for (int i = 0; i < n - 1;)
        {
            int j = i;
            while (j < n - 1 && abs(x[j]) % 2 == abs(x[i]) % 2)
            {
                j++;
            }

            sort(x.begin() + i, x.begin() + j);

            i = j;
        }

        vector<long long> res(n);
        res[0] = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            res[i + 1] = res[i] + x[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << res[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}