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
        int a,b,c;

        cin>>a>>b>>c;

        long long arr[3] = {a,b,c};
        sort(arr, arr+3);

        cout<<min(arr[2]-arr[0] ,arr[1])<<endl;

    }
    
    return 0;
}