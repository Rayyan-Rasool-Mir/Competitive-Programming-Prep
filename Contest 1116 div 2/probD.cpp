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

int main() {

    int t;
    cin >> t;

    const long long MOD = 998244353;
    const int MAX_N = 1000005;

    vector<long long> fact(MAX_N);
    vector<long long> invFact(MAX_N);

    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long p = MOD - 2;
    long long base = fact[MAX_N - 1];
    long long res = 1;
    while (p > 0) {
        if (p % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        p /= 2;
    }
    invFact[MAX_N - 1] = res;

    for (int i = MAX_N - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int n0 = 0, n1 = 0; 
        int k0 = 0, k1 = 0; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                n0++;
                if (i == 0 || s[i - 1] != '0') k0++;
            } else {
                n1++;
                if (i == 0 || s[i - 1] != '1') k1++;
            }
        }

        long long ways0 = 1;
        if (k0 > 0) {
            int N = n0 - 1;
            int R = k0 - 1;
            ways0 = fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        }

        long long ways1 = 1;
        if (k1 > 0) {
            int N = n1 - 1;
            int R = k1 - 1;
            ways1 = fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        }

        cout << (ways0 * ways1) % MOD << "\n";
    }

    return 0;
}