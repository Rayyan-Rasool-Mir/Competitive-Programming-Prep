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

        int ans=0;
        while (true)
        {
            if(a==b || b==c || a==c){
                cout<<ans<<endl;
                break;
            }else if(a>b && a>c){
                if(b<c){
                    a--;
                    b++;
                    ans++;
                }else{
                    a--;
                    c++;
                    ans++;
                }

            }
            else if(b>a && b>c){
                if(a<c){
                    b--;
                    a++;
                    ans++;
                }else{
                    b--;
                    c++;
                    ans++;
                }
            }
            else{
                if(a<b){
                    c--;
                    a++;
                    ans++;
                }else{
                    c--;
                    b++;
                    ans++;
                }
            }
        }
        

    }
    
    return 0;
}