/*You are given an array A of intergers of size N. You will be given Q queries where each query is represented by two integers L, R
You have to find the greatest common divisor of the array after excluding the part of the range from L to R inclusive(1 based indexing).
It is guaranteed that after execluding the part from the range, the remaining array is non empty.
*/
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

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 10];

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;

            for (int i = 1; i <= l - 1; i++)
            {
                ans = gcd(ans, arr[i]);
            }

            for (int i = r + 1; i <= n; i++)
            {
                ans = gcd(ans, arr[i]);
            }
            cout << ans << endl;
        }
    }

    return 0;
}