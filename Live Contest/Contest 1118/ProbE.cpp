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

const int MAX = 200500;
int min_prime[MAX];
vector<int> prime_powers;

void sieve() {
    for (int i = 2; i < MAX; i++) {
        if (min_prime[i] == 0) {
            for (int j = i; j < MAX; j += i)
                if (min_prime[j] == 0) min_prime[j] = i;
            long long cur = i;
            while (cur < MAX) {
                prime_powers.push_back((int)cur);
                cur *= i;
            }
        }
    }
    sort(prime_powers.begin(), prime_powers.end());
}

int bit[MAX], n_val;

void update(int idx, int val) {
    for (; idx <= n_val; idx += idx & -idx)
        bit[idx] = max(bit[idx], val);
}

int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res = max(res, bit[idx]);
    return res;
}

vector<int> pos[MAX];

void solve() {
    int n;
    if (!(cin >> n)) return;
    n_val = n;
    for (int i = 1; i <= n; i++) bit[i] = 0;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a < MAX) pos[a].push_back(i);
    }

    vector<int> ans;
    for (int x : prime_powers) {
        vector<int> m_pos;
        m_pos.push_back(0);
        if (x <= n) {
            for (int v = x; v <= n; v += x)
                for (int p : pos[v]) m_pos.push_back(p);
            sort(m_pos.begin(), m_pos.end());
        }
        m_pos.push_back(n + 1);

        vector<pair<int, int>> current_intervals;
        bool ok = false;
        for (int i = 0; i < (int)m_pos.size() - 1; i++) {
            int l = m_pos[i] + 1, r = m_pos[i+1] - 1;
            if (l <= r) {
                current_intervals.push_back({l, r});
                if (query(l) < r) ok = true;
            }
        }

        if (ok) ans.push_back(x);
        for (auto& p : current_intervals) update(p.first, p.second);
        
        if (query(1) == n) break;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
    cout << "\n";

    for (int i = 1; i <= n; i++){
        pos[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}