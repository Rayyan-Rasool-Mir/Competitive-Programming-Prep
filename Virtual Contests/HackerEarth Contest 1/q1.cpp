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

char upper (char c){
    return (c - 'a') + 'A';
}

int main()
{
    while(true){
        string input;
        cin>>input;

        if (input.size() == 0)
        {
            break;
        }

        for (int i = 0; i < input.size(); i++)
        {
            input[i] = upper(input[i]);
        }
        
        cout << input<<endl;

    }
    return 0;
}