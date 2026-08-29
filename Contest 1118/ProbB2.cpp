#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> count(m + 1, 0);
    long long max_count = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a <= m) count[a]++;
    }


    vector<long long> s_sum(m + 2, 0);
    for (int i = m; i >= 1; i--) {
        s_sum[i] = s_sum[i + 1] + count[i];
        max_count = max(max_count, (long long)count[i]);
    }

    vector<long long> ans(m + 1, 0);
    ans[0] = max_count; 

    int k_limit = min(m, 19);
    for (int k = 1; k <= k_limit; k++) {
        long long current_best = 0;
        long long power_of_2 = (1LL << k);

        for (int L = 1; L <= m; L++) {
            long long current_L_total = 0;

            for (int p = 1; p < power_of_2; p++) {
                if (1LL * p * L > m) break;
                current_L_total += s_sum[p * L];
            }

            if (1LL * power_of_2 * L <= m) {
                current_L_total += count[power_of_2 * L];
            }
            current_best = max(current_best, current_L_total);
        }
        ans[k] = current_best;
    }


    for (int k = 1; k <= m; k++) {
        if (k > k_limit) ans[k] = ans[k_limit];
        ans[k] = max(ans[k], ans[k - 1]);
    }

    for (int k = 1; k <= m; k++) {
        cout << ans[k] << (k == m ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int t; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}