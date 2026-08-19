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
    cin>>n;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            count++;
        }
        
    }

    cout<<count<<endl;
    
    return 0;
}

//even here, the time complexity of O(n^2)