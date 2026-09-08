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

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    long long t;
    cin>>t;

    while (t--)
    {
        long long size;
        cin>>size;

        long long arr[size];

        for(long long i = 0; i < size; i++)
        {
            cin>>arr[i];
        }

        if (size==1)
        {
            cout<<arr[0]<<endl;
        }else{
            cout<<gcd(arr[0], arr[size-1])<<endl;
        }
        
        
    }

    return 0;
}