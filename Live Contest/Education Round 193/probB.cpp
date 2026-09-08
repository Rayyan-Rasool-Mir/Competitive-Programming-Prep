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
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> block_sizes;
        vector<int> block_colors;
        
        if (n > 0) {
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i - 1]) {
                    count++;
                } else {
                    block_sizes.push_back(count);
                    block_colors.push_back(a[i-1]);
                    count = 1;
                }
            }
            block_sizes.push_back(count);
            block_colors.push_back(a[n-1]);
        }

        int k = block_sizes.size();

        if (k <= 1) {
            cout << k << endl;
            continue; 
        }

        bool twoadjacentblocks = false;
        bool can_gain_one = false;

        for (int i = 0; i < k; i++) {
            if (block_sizes[i] >= 2) {
                if (i + 1 < k && block_sizes[i + 1] >= 2) {
                    twoadjacentblocks = true;
                }

                if (i > 0) {
                    if (i - 2 < 0 || block_colors[i] != block_colors[i - 2]) {
                        can_gain_one = true;
                    }
                }
                if (i < k - 1) {
                    if (i + 2 >= k || block_colors[i] != block_colors[i + 2]) {
                        can_gain_one = true;
                    }
                }
            }
        }

        if (twoadjacentblocks) {
            cout << k + 2 << endl;
        } else if (can_gain_one) {
            cout << k + 1 << endl;
        } else {
            cout << k << endl;
        }
    }
    return 0;
}