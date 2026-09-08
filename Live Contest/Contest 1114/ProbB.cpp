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

        string s;
        cin >> s;
        int runs = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
                runs++;
        }

        int maxremoval =0;

        for (int i = 1; i < n-1; i++)
        {
            if (s[i] != s[i - 1] && s[i] != s[i + 1])
            {
                if (s[i - 1] == s[i + 1])
                {
                    maxremoval = max(maxremoval, 2);
                }else{
                    maxremoval = max(maxremoval, 1);
                }
                
            }
            
        }
        cout<<runs-maxremoval<<endl;
       
    }
    
    return 0;
}
