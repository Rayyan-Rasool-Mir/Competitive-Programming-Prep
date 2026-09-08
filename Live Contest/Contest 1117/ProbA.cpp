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
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<bool> available(26, false);
        vector<bool> used(m, false);
        vector<string> words(n);
        vector<string> a(m);
        for (int i = 0; i < n; i++){
            cin >> words[i];
        }

        for (int i = 0; i < m; i++){
            cin >> a[i];
        }

        for (string word : words){
            available[word[0] - 'a'] = true;
        }

        int done = 0;

        while (true){
            bool changed = false;

            for (int i = 0; i < m; i++){

                if (used[i])
                    continue;

                bool possible = true;

                for (char c : a[i])
                {
                    if (!available[c - 'A'])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    used[i] = true;
                    done++;

                    available[a[i][0] - 'A'] = true;

                    changed = true;
                }
            }

            if (!changed)
                break;
        }

        cout << (done == m ? "YES" : "NO") << endl;
    }

    return 0;
}