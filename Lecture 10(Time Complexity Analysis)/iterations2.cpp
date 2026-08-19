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
    int x;      //iteration 1
    int sum = 0;//iteration2
    sum = x+x;  //iteration 3

    int n; //iteration 4
    cin >> n; //iteration 5
    for (int  i = 0; i < n; i++)
    {
        int y;
        y=5;
        y++;

        //there are 3 iterations inside the loop
    }
    

    //in this code there are 5 lines of code that are executed, hence there are there are 5 iterations
    //no. of iterations = 5
    return 0;
}

//TC = O(5) + O(3*n) [there are 3 iterations that are repeated n times in a loop]
//overall TC = O(n)