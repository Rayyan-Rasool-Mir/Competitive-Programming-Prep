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

bool canFinish(long long K, int n, const vector<int>& a) {
    priority_queue<long long> pq;
    for (int x : a) {
        pq.push((long long)x);
    }

    for (long long j = K - 1; j >= 0; j--) {
        if (pq.empty()){
            break;
        } 
        
        long long currentMax = pq.top();
        pq.pop();

        if (j >= 31) {
        } else {
            currentMax -= (1LL << j);
            if (currentMax > 0) {
                pq.push(currentMax);
            }
        }
    }
    return pq.empty();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long low = n;
        long long high = n + 32;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canFinish(mid, n, a)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}