#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int blocks = n - k;

        int zeros = n / 2;
        int ones = n - zeros;

        int maxBlocks = 2 * min(zeros, ones) + (zeros != ones);
        int minBlocks = (zeros > 0) + (ones > 0);

        if (blocks > maxBlocks || blocks < minBlocks)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<string> parts(blocks, "");

        char ch;
        if (zeros > ones)
        {
            ch = '0';
        }
        else if (ones > zeros)
        {
            ch = '1';
        }
        else
        {
            ch = '0';
        }

        for (int i = 0; i < blocks; i++)
        {
            parts[i] += ch;
            if (ch == '0')
                zeros--;
            else
                ones--;

            if (ch == '0')
            {
                ch = '1';
            }
            else
            {
                ch = '0';
            }
        }

        for (int i = 0; i < blocks; i++)
        {
            if (parts[i] == "0")
            {
                while (zeros > 0)
                {
                    parts[i] += '0';
                    zeros--;
                }
            }
            else
            {
                while (ones > 0)
                {
                    parts[i] += '1';
                    ones--;
                }
            }
        }

        string ans = "";
        for (int i =0; i<parts.size(); i++)
        {
            ans += parts[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
