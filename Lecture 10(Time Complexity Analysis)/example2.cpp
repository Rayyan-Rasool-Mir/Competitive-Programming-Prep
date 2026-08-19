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
    int count = 0;
    while(n>0){
        n /=2;
        count++;
    }
    cout<<count<<endl;
    return 0;
}

//O(1) + O(1) + O(log(n)) = O(log(n));