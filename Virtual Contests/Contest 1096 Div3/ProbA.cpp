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
        int x, y;
        cin>>x>>y;

        if (x%2 != 0 && y%2 != 0)
        {
            cout<<"NO"<<'\n';
        }else{
            cout<<"Yes"<<'\n';
        }
        
    }
    
    return 0;
}