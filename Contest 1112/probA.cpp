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
        int n;
        cin >> n;

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            cin >> ans[i];
        }

        if (n == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (n % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }


        int miniodd = INT_MAX;
        int maxeven = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0){
                miniodd = min(miniodd, ans[i]);
            }
            else{
                maxeven = max(maxeven, ans[i]);
            }
        }

        if (maxeven +1 < miniodd)
        {
            cout << "YES" << endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}