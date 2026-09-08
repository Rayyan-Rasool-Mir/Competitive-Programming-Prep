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
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int count = 0;
        int maxcount = 0;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '#')
            {
                count++;
            }else{
                maxcount = max(maxcount, count);
                count = 0;
            }
        }
        maxcount = max(maxcount, count);

        int ans = (maxcount+1)/2;
        cout<<ans<<endl;
    }

    return 0;
}