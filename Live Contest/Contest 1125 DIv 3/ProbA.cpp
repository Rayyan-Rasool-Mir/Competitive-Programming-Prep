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
    cin >> t;
    while (t--)
    {
        int x0, y0, r;
        cin >> x0 >> y0 >> r;
        // int x, y;
        // bool found = false;

        // for (int i = x0 -r ; i <= x0 + r; i++)
        // {
        //     for (int j = y0 - r; j <= y0 + r; j++)
        //     {
        //         if (((x0 - i) * (x0 - i) + (y0 - j) * (y0 - j) == r * r))
        //         {
        //             x = i;
        //             y = j;
        //             found = true;
        //             break;
        //         }
        //     }
        //     if(found){
        //         break;
        //     }
        // }
        cout << x0 + r << " " << y0 << '\n';
    }

    return 0;
}