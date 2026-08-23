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

const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long fact[N];
//1<=T<= 10^5
//1<=N<=10^5
int main()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i-1] * i;
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;

        cout<<fact[n]<<endl;
    }
    
    return 0;
}

//original factorial code has a time comlexity of O(n^2), which would fail at 10^10
//but this code ony has O(n) due to pre computation (TC = 10^5 + 10^5)