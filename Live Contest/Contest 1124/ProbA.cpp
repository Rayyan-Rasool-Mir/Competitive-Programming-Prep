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
        int n, k;
        cin>>n>>k;

        long long gap = n-k+1;

        long long money = 1;
        for (int i = 0; i < gap; i++)
        {
            money *= 2;
        }

        long long rest = 2ll * (k-1);

        long long answer = money+rest;

        cout<< answer <<endl;
    }
    
    return 0;
}