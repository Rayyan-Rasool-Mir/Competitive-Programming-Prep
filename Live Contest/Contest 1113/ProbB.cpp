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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        if (n < 2 * m) {
            cout << "NO" << endl;
            continue;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (a[i] > b[i]) {
                ok = false;
                break;
            }

            if (a[n - m + i] < b[i]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}