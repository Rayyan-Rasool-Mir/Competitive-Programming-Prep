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

string bob_best(string str) {
    string bestbob = "";
    bool first = true;
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '1') {
            string candidate = str;
            candidate.erase(i, 1);
            if (first || candidate < bestbob) {
                bestbob = candidate;
                first = false;
            }
        }
    }
    return bestbob;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
    cin >> s;
    int n = s.length();
    
    string bestalice = "";
    bool first_alice = true;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            string afteralice = s;
            afteralice.erase(i, 1);
            
            string strfinal = bob_best(afteralice);
            
            if (first_alice || strfinal > bestalice) {
                bestalice = strfinal;
                first_alice = false;
            }
        }
    }
    
    cout << bestalice << endl;
    }
    return 0;
}