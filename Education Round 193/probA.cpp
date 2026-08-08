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
        int x =n+1;
        int s = sqrt(x);
        bool isPrime =true;

        if(x<=1){
            isPrime = false;
        }

        for (int i = 2; i <= s; i++)
        {
            if(x%i == 0){
                isPrime =false;
                break;
            }
        }
        if (isPrime)
        {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    
    return 0;
}