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
        cin >>n;

        string a,b;
        cin >>a>>b;

        int odda= 0; 
        int oddb=0;
        int evena=0;
        int evenb=0;

        for (int i = 0; i < n; i++)
        {
            if(a[i] == '1'){
                if(i%2 == 0){
                    odda++;
                }else{
                    evena++;
                }
            }

            if(b[i] == '1'){
                if(i%2 == 0){
                    oddb++;
                }else{
                    evenb++;
                }
            }
        }

        if(odda == oddb && evena ==evenb){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}