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
    int n;
    cin >> n;

    vector<int> bt(n);

    for (int i = 0; i < n; i++)
        cin >> bt[i];

    sort(bt.begin(), bt.end());

    int waiting = 0;
    int totalWaiting = 0;

    for (int i = 0; i < n; i++)
    {
        totalWaiting += waiting;
        waiting += bt[i];
    }

    double awt = (double)totalWaiting / n;

    cout << "Average Waiting Time: " << awt << endl;

    return 0;
}

//At every step, SJF makes the locally optimal choice: Choose the available process with the shortest burst time.