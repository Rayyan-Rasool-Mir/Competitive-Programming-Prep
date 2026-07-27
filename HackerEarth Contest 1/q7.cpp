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
    string input;
    cin >> input;

    int upval = 0;
    int lowval = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = toupper(input[i]);
            upval += input[i];
        }
        else
        {
            input[i] = tolower(input[i]);
            lowval += input[i];
        }
    }

    int x = abs(upval - lowval);
    int ans;
    if (x < 2)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}