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
        int odd = 0, rem2 = 0, rem0 = 0;
        int len;
        cin>>len;

        int arr[len];
        for (int i = 0; i < len; i++)
        {
            cin>>arr[i];
        }

        for (int i = 0; i < len; i++)
        {
            if (arr[i]%2 == 1)
            {
                odd++;
            }else if (arr[i]%4 == 2)
            {
                rem2++;
            }else if (arr[i]%4 == 0)
            {
                rem0++;
            }
            
        }
        cout<< max({odd, rem2, rem0})<< "\n";

    }
    
    return 0;
}