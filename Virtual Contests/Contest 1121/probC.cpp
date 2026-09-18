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

const long long MOD = 998244353;

long long modpow(long long a, long long b)
{
    long long ans = 1;

    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> fact(n + 1);
        vector<long long> inv(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        for (int i = 1; i <= n; i++)
        {
            inv[i] = modpow(i, MOD - 2);
        }

        vector<long long> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = (suffix[i + 1] + a[i]) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            long long h = n - i - 1;

            long long contributionSum =
                suffix[i + 1]
                - h * (a[i] % MOD);

            contributionSum %= MOD;

            if (contributionSum < 0)
                contributionSum += MOD;

            long long ways = fact[n - 1] * inv[h] % MOD;

            ans += ways * contributionSum % MOD;
            ans %= MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}