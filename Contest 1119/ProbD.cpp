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
        
        map<long long, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            pos[x].push_back(i);
        }


        if (pos[0].empty()) {
            cout << "YES\n";
            cout << string(n, 'A') << "\n";
        }

        else if (pos[0].size() == 1) {
            cout << "NO\n";
        }
        else {
            string res(n, 'A');
            int k = 0;

            while (pos.count(k) && pos[k].size() >= 2) {

                res[pos[k][1]] = 'B';
                k++;
            }

            if (pos.count(k)) {
                res[pos[k][0]] = 'C';
            }

            cout << "YES\n";
            cout << res << "\n";
        }
    }

    return 0;
}